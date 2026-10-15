/*
 * function: B_BAG_MAIN_DeleteFingerCursor
 * address:  0x0220C6E8
 * packet:   pkt_0220C6E8
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_FINGER_CURSOR_Delete 0x02209B30 thumb
 */
#include "../include/Obj25045.h"

extern void BTLV_FINGER_CURSOR_Delete(int);

void B_BAG_MAIN_DeleteFingerCursor(char *a)
{
    BTLV_FINGER_CURSOR_Delete(((struct Obj25045 *)a)->f14C);
}
