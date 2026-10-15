/*
 * function: BR_POKESEARCH_DestroyText
 * address:  0x021F8EE8
 * packet:   pkt_021F8EE8
 * region:   ov185
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_UTIL_DeleteProfileScreen  0x021FD640  thumb  ov186
 */
#include "../include/Obj10772.h"

extern void BR_UTIL_DeleteProfileScreen(int *p);

void BR_POKESEARCH_DestroyText(char *p, int *a1)
{
    if (((struct Obj10772 *)p)->f10 != 0) {
        BR_UTIL_DeleteProfileScreen((int *)(((struct Obj10772 *)p)->f10));
        ((struct Obj10772 *)p)->f10 = 0;
    }
}
