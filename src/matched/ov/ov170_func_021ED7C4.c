/*
 * function: BOX2_SEQ_MoveCursorToSlot
 * address:  0x021ED7C4
 * packet:   pkt_ov170_021ED7C4
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

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern const signed char d_021EFCD0[];
extern const signed char d_021EFCC8[];

void BOX2_SEQ_MoveCursorToSlot(char *p, int i)
{
    short xy[2];
    int j;
    if (i == 0xFF)
        return;
    j = 0;
    BOX2_SEQ_GetActorSurfacePos(p, *(unsigned char *)(p + i + 0x3DD2), &xy[1], &xy[0], j);
    for (; j < 8u; j++)
        BOX2_SEQ_AddActorSurfacePos(p, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
}
