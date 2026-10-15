/*
 * function: BR_POKESEARCH_DestroyMsgbox
 * address:  0x021F8FB0
 * packet:   pkt_ov185_021F8FB0
 * region:   ov185
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BR_UTIL_DeleteTextWin  0x021FD15C  thumb  ov186
 */
#include "../include/Obj10773.h"
#include "../include/Obj24760.h"

extern void BR_UTIL_DeleteTextWin(void *p, int a1);

void BR_POKESEARCH_DestroyMsgbox(char *p, char *a1)
{
    if (((struct Obj10773 *)p)->f4 != 0) {
        BR_UTIL_DeleteTextWin((void *)(((struct Obj10773 *)p)->f4), ((struct Obj24760 *)a1)->fC);
        ((struct Obj10773 *)p)->f4 = 0;
    }
}
