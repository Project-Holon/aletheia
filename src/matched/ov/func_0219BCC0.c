/*
 * function: func_0219BCC0
 * address:  0x0219BCC0
 * packet:   pkt_0219BCC0
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
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03525.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D83C(u32, u32, u32, u32);
extern int func_0216D86C(void *p);

int func_0219BCC0(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj03525 *)((u8 *)(b)))->f1 = 1;
((struct Obj03525 *)((u8 *)(b)))->f2 = func_0216D83C(c, b, c, d);
((struct Obj03525 *)((u8 *)(b)))->f4 = func_0216D86C((void *)c);
((struct Obj03525 *)((u8 *)(b)))->f6 = 255;
((struct Obj03525 *)((u8 *)(b)))->f8 = c;
return 255;
}

