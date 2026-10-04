/*
 * function: func_021FC9D0
 * address:  0x021FC9D0
 * packet:   pkt_ov094_021FC9D0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wait callback: decrements the countdown at 0x1e4, done when it reaches zero.
 */
#include "../include/Obj21685.h"
int func_021FC9D0(void *a, char *s)
{
    return --((struct Obj21685 *)s)->f1E4 <= 0;
}
