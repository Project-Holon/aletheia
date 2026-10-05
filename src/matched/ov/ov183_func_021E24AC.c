/*
 * function: func_021E24AC
 * address:  0x021E24AC
 * packet:   pkt_021E24AC
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FD15C  0x021FD15C  thumb  ov186
 */
#include "../include/Obj10761.h"
#include "../include/Obj24667.h"

extern void func_021FD15C(void *p, int a1);

void func_021E24AC(char *p, char *a1)
{
    if (((struct Obj10761 *)p)->f4 != 0) {
        func_021FD15C((void *)(((struct Obj10761 *)p)->f4), ((struct Obj24667 *)a1)->fC);
        ((struct Obj10761 *)p)->f4 = 0;
    }
}
