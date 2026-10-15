/*
 * function: DIGITALCARDCHECK_DeleteRecord
 * address:  0x0217D174
 * packet:   pkt_0217D174
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DeleteDateWindow  0x021E62A0  thumb  ov177
 */
#include "../include/Obj10701.h"

extern void WIFIBATTLEMATCH_VIEW_DeleteDateWindow(void *p);

void DIGITALCARDCHECK_DeleteRecord(int *p)
{
    if (((struct Obj10701 *)p)->f10) {
        WIFIBATTLEMATCH_VIEW_DeleteDateWindow((void *)(((struct Obj10701 *)p)->f10));
        ((struct Obj10701 *)p)->f10 = 0;
    }
}
