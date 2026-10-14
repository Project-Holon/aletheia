/*
 * function: ZUKAN_DETAIL_FORM_ApplyPendingDisplay
 * address:  0x021C47B4
 * packet:   pkt_ov208_021C47B4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: loads the object at +0x6ac of the second argument and
 * passes it to ZUKAN_DETAIL_COMMON_TransferPalettes.  Pool word 0x021C47B5 in func_021C3B6C.
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_TransferPalettes  0x021BC6BC  thumb
 */
#include "../include/Obj25510.h"

extern void ZUKAN_DETAIL_COMMON_TransferPalettes(char *p);

void ZUKAN_DETAIL_FORM_ApplyPendingDisplay(int unused, char *p)
{
    ZUKAN_DETAIL_COMMON_TransferPalettes(*(char * *)&((struct Obj25510 *)p)->f6AC);
}
