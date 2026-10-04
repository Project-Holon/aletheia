/*
 * function: func_021BC294
 * address:  0x021BC294
 * packet:   pkt_021BC294
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC2B8  0x021BC2B8  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25581.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020056A0(void (*)(void), u8 *, u32);
extern void func_021BC2B8(void *unused, unsigned char *p);

void func_021BC294(u8 *p)
{
    ((struct Obj25581 *)p)->f4 = func_020056A0((void (*)(void))func_021BC2B8, p, 0);
}
