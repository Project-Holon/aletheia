/*
 * function: func_021C08D4
 * address:  0x021C08D4
 * packet:   pkt_021C08D4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   func_021BF6BC  0x021BF6BC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25974.h"

extern int func_020056A0(void (*)(void), void *, int);
typedef unsigned int   u32;
extern u32 func_021BF6BC(u32 a0, u32 a1);

void func_021C08D4(char *p)
{
    ((struct Obj25974 *)p)->f3C0 = func_020056A0((void (*)(void))func_021BF6BC, p, 0);
}
