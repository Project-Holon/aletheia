/*
 * function: func_021DC8B8
 * address:  0x021DC8B8
 * packet:   pkt_021DC8B8
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   func_021DC8E4  0x021DC8E4  thumb  ov171
 */
#include "../include/Obj24047.h"

extern int func_020056A0(void (*)(void), int *, int);
typedef unsigned char  u8;
extern void func_021DC8E4(void *unused, const u8 *p);

void func_021DC8B8(int *p)
{
    ((struct Obj24047 *)p)->fB28 = func_020056A0((void (*)(void))func_021DC8E4, p, 0);
}
