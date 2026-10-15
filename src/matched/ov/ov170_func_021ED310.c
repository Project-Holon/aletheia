/*
 * function: BOX2_SEQ_LayoutHandSlots
 * address:  0x021ED310
 * packet:   pkt_ov170_021ED310
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   d_021EFCD0 0x021EFCD0 data a1
 *   d_021EFCC8 0x021EFCC8 data a1
 */
#include "../include/Obj24020.h"


extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern const signed char d_021EFCD0[];
extern const signed char d_021EFCC8[];

void BOX2_SEQ_LayoutHandSlots(char *w)
{
    short xy[2];
    unsigned i;
    if (((struct Obj24020 *)w)->f9FD4 != 0) {
        i = 0;
        BOX2_SEQ_GetActorSurfacePos(w, 0xA, &xy[1], &xy[0], 0);
        for (; i < 8; i++)
            BOX2_SEQ_AddActorSurfacePos(w, i + 0x58, (short)(xy[1] + d_021EFCD0[i]), (short)(xy[0] + d_021EFCC8[i]), (short)0);
    }
}
