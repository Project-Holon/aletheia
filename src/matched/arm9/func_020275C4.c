/*
 * function: BEACON_STATUS_GetMessage
 * address:  0x020275C4
 * packet:   pkt_020275C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled arm9 leaf reading the word at +0xB08. Filed as the relocation
 * witness for ov021 EVENT_NAMEIN_StoreResult (wave A1).
 */
#include "../include/Obj15765.h"

int BEACON_STATUS_GetMessage(void *p)
{
    return ((struct Obj15765 *)p)->fB08;
}
