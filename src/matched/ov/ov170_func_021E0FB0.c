/*
 * function: BOX2_MAIN_MoveCursorTo
 * address:  0x021E0FB0
 * packet:   pkt_ov170_021E0FB0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_MoveActor 0x021ED14C thumb
 *   BOX2_SEQ_LayoutHandSlots 0x021ED310 thumb
 */
#include "../include/Obj14264.h"

extern void BOX2_SEQ_MoveActor(int a, int b, int c);
extern void BOX2_SEQ_LayoutHandSlots(char *w);

void BOX2_MAIN_MoveCursorTo(char *w, int x, int y)
{
    BOX2_SEQ_MoveActor((int)w, (short)x, (short)y);
    BOX2_SEQ_LayoutHandSlots(w);
    ((struct Obj14264 *)w)->fA180 = x;
    ((struct Obj14264 *)w)->fA184 = y;
}
