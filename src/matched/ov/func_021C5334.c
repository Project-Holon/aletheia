/*
 * function: func_021C5334
 * address:  0x021C5334
 * packet:   pkt_021C5334
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
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_021C56F8  0x021C56F8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18304.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern int func_021C56F8(int *a);

int func_021C5334(u32 a)
{
func_0201C4E4((struct PrintSys *)(((struct Obj18304 *)((u8 *)(a)))->f6C));
return func_021C56F8((int *)a);
}

