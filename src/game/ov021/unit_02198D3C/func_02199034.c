/*
 * function: func_02199034
 * address:  0x02199034
 * packet:   pkt_02199034
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
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj17953.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D674(u32, u32);
extern void *func_0216D6BC(int a0, int a1, int a2);

int func_02199034(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj17953 *)((u8 *)(func_0216D6BC(a, 4, c))))->f2 = c;
return func_0216D674(a, b);
}

