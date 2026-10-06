/*
 * function: func_0219A780
 * address:  0x0219A780
 * packet:   pkt_0219A780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17955.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216D438(char *a0, int a1);
extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);

int func_0219A780(char *a, u32 b, u32 c, u32 d)
{
func_0216D438(a, (((u32)func_02197E7C((u32)(((u32)func_0216D5F8((void *)a) << 16) >> 16), (u32)0) << 16) >> 16));
((struct Obj17955 *)((u8 *)(b)))->f2 = 1;
return 1;
}

