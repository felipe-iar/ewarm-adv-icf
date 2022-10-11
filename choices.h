#ifndef __CHOICES_H__
#define __CHOICES_H__

#define USE_X
//#define USE_Y
#define USE_Z

#ifdef USE_X
#pragma location=".usingX"
__root const int USING_X;
#warning Using X now...
extern int funX();
#endif

#ifdef USE_Y
#pragma location=".usingY"
__root const int USING_Y;
#warning Using Y now...
extern int funY();
#endif

#ifdef USE_Z
#pragma location=".usingZ"
__root const int USING_Z;
#warning Using Z now...
extern int funZ();
#endif

#endif /* __CHOICES_H__ */