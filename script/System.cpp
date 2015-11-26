#include "System.h"

void SystemMain::Init(void){
  lcdController.lcdClass.SetLcd();
  dhtController.dht.setDHT(3);
}

void SystemMain::Setup(void){
 // lcdControllerClass.lcdClass.HelloWorld_Debug(0,1);
}

void SystemMain::Update(void){
  lcdController.ScreenRefresh(200);
  dhtController.checkData();
  buttonFirst.Use(2,lcdController);

  if(buttonFirst.State)
    lcdController.lcdClass.PrintS("true",10);
  else
    lcdController.lcdClass.PrintS("false",10);

  if(dhtController.lastDataChanged == true || lcdController.clearScreen){
    lcdController.lcdClass.PrintS(String("T:"+dhtController.Temperature));
    lcdController.lcdClass.PrintS(String("W:"+dhtController.Humidity),0,1);
    dhtController.lastDataChanged = false;
  }

  if(lcdController.clearScreen == true){
    lcdController.clearScreen = false;
  }
}

void LcdMain::SetLcd(uint8_t id,int width,int height){
  lcd = new LiquidCrystal_I2C(id,width,height);
  lcd->init();
  lcd->clear();
}

void LcdMain::HelloWorld_Debug(int x,int y){
  lcd->setCursor(x,y);
  lcd->print("Hello World!");
}

void LcdMain::Print(uint8_t text,int x,int y,bool clearLcd){
  if(clearLcd)
    lcd->clear();
  lcd->setCursor(x,y);
  lcd->print(text);
} 
void LcdMain::PrintS(String text,int x,int y,bool clearLcd){
  if(clearLcd)
    lcd->clear();
  lcd->setCursor(x,y);
  lcd->print(text);
}
void LcdController::ScreenRefresh(int refreshTime){
  timer++;
  if(timer > refreshTime){
    timer = 0;
    lcdClass.lcd->clear();
    clearScreen = true;
  }
}

void ButtonMain::Use(int id,LcdController lcdController){
  if (timer == 0)
    buttonState = digitalRead(id);
  else
    timer++;

  if (timer > 10)
    timer = 0;

  if (buttonState != lastState && timer == 0) {
    if (buttonState == 1) {
      lcdController.ScreenRefresh(0);
      State = !State;
      if (timer == 0)
        timer = 1;
    }
  }
  lastState = buttonState;
}

void DHTMain::setDHT(uint8_t pin, uint8_t type){
  dht = new DHT(pin,type);
  dht->begin();
}

void DhtController::checkData(){
  if(dht.dht->readTemperature() != lastTemperature || dht.dht->readHumidity() != lastHumidity && !lastDataChanged){
    lastDataChanged = true;
    lastHumidity = dht.dht->readHumidity();
    lastTemperature = dht.dht->readTemperature();
    
    Temperature = String(round(dht.dht->readTemperature()));
    Temperature = String(Temperature+"C");
    Humidity = String(round(dht.dht->readHumidity()));
    Humidity = String(Humidity+"%");
  }
}

