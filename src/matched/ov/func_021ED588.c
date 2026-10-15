/*
 * function: BOX2_SEQ_RefreshCursorSlot
 * address:  0x021ED588
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_MoveCursorActor  0x021ED594  thumb  ov170
 *
 * Forward with the byte field at +0x16.
 */
#include "../include/Obj00000.h"

extern void BOX2_SEQ_MoveCursorActor(char *p, unsigned i);

void BOX2_SEQ_RefreshCursorSlot(char *p)
{
    BOX2_SEQ_MoveCursorActor(p, ((struct Obj00000 *)p)->f16);
}

