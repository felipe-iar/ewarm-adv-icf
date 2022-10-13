#define USE_X
#define USE_Y
#define USE_Z

#include <stdio.h>
#include "choices.h"

#define BLOCK_START_ADDRESS(addr) ((unsigned int)(addr))
#define BLOCK_FINAL_ADDRESS(addr) (((unsigned int)(addr) & 0xFFFFFC00U) + 0x3FFU)
#define CONCAT(a, b) a##b
#define BLOCK_SIZE(B) (BLOCK_FINAL_ADDRESS(CONCAT(slot,B##_end))+1-BLOCK_START_ADDRESS(CONCAT(slot,B##_start)))

void main()
{
  int res = 0;
#if defined(USE_X)
  printf("X block start address: 0x%08x\n", BLOCK_START_ADDRESS(slotX_start));
  printf("X block final address: 0x%08x\n", BLOCK_FINAL_ADDRESS(slotX_end));
  printf("X slot has %d kbytes.\n\n", (unsigned int)(BLOCK_SIZE(X) / 1024U));
  res += funX();
#endif
#if defined(USE_Y)
  printf("y block start address: 0x%08x\n", BLOCK_START_ADDRESS(slotY_start));
  printf("Y block final address: 0x%08x\n", BLOCK_FINAL_ADDRESS(slotY_end));
  printf("Y slot has %d kbytes.\n\n", BLOCK_SIZE(Y) / 1024);
  res += funY();
#endif
#if defined(USE_Z)
  printf("Z block start address: 0x%08x\n", BLOCK_START_ADDRESS(slotZ_start));
  printf("Z block final address: 0x%08x\n", BLOCK_FINAL_ADDRESS(slotZ_end));
  printf("Z slot has %d kbytes.\n\n", BLOCK_SIZE(Z) / 1024);
  res += funZ();
#endif 

  while (1) { };
}