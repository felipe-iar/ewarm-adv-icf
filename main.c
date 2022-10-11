#include "choices.h"

void main()
{
  int res = 0;
#if defined(USE_X)
  res += funX();
#endif
#if defined(USE_Y)
  res += funY();
#endif
#if defined(USE_Z)
  res += funZ();
#endif  
  while (1) { };
}
