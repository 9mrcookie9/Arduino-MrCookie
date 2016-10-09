// System.h
#ifndef _System_h_
#define _System_h_

#include <math.h>

class SystemMain{
public:
  void Init(void);
  void Setup(void);
  void Update(void);
private:
  static byte Mac[];
};
#endif

