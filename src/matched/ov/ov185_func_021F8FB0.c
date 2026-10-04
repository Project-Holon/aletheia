/*
 * function: func_021F8FB0
 * address:  0x021F8FB0
 * packet:   pkt_ov185_021F8FB0
 * region:   ov185
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD15C  0x021FD15C  thumb  ov186
 */
#include "../include/Obj10773.h"
#include "../include/Obj24760.h"

extern void func_021FD15C(void *p, int a1);

void func_021F8FB0(char *p, char *a1)
{
    if (((struct Obj10773 *)p)->f4 != 0) {
        func_021FD15C((void *)(((struct Obj10773 *)p)->f4), ((struct Obj24760 *)a1)->fC);
        ((struct Obj10773 *)p)->f4 = 0;
    }
}
