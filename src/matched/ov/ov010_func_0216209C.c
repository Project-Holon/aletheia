/*
 * function: EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType
 * address:  0x0216209C
 * packet:   pkt_ov010_0216209C
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
#include "../include/Obj18952.h"

typedef unsigned short u16;

u16 EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType(char *p)
{
    return ((struct Obj18952 *)p)->f26;
}
