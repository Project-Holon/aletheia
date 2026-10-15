/*
 * function: BOX2_SEQ_SetCursorFrame
 * address:  0x021ED544
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorAnimSeq  0x021EBFA8  thumb  ov170
 *
 * Offset by four when the low nibble of 0x1c is set.
 */
#include "../include/Obj00000.h"



struct Slot { unsigned char a[0x1c]; unsigned char f : 4; };
extern void BOX2_SEQ_SetActorAnimSeq(char *, int, int);
void BOX2_SEQ_SetCursorFrame(char *p, int b)
{
    if (((struct Slot *)p)->f)
        b += 4;
    BOX2_SEQ_SetActorAnimSeq(*(char * *)&((struct Obj00000 *)p)->f2C, 4, b);
}
