/*
 * function: B_BAG_MAIN_CreateFingerCursor
 * address:  0x0220C6D0
 * packet:   pkt_0220C6D0
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_FINGER_CURSOR_Create 0x02209A7C thumb
 */
#include "../include/Obj00315.h"

extern int BTLV_FINGER_CURSOR_Create(int, int, int);

void B_BAG_MAIN_CreateFingerCursor(char *a)
{
    ((struct Obj00315 *)a)->f14C = BTLV_FINGER_CURSOR_Create(*(int *)&((struct Obj00315 *)a)->f8, 9,
                                         *(unsigned short *)(*(int *)&((struct Obj00315 *)a)->f0 + 0xc));
}