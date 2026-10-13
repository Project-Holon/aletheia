/*
 * function: EVENT_FIELD_PROCLINK_HasReturnDefaultSlot
 * address:  0x0216208C
 * packet:   pkt_ov010_0216208C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain.
 */
#include "../include/Obj18951.h"

typedef unsigned short u16;

int EVENT_FIELD_PROCLINK_HasReturnDefaultSlot(char *p, int unused)
{
    if (((struct Obj18951 *)p)->f2 & 8)
        return 1;
    return 0;
}
