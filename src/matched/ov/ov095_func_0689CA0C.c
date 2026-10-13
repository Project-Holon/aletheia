/*
 * function: BTL_ID_IsCallMoveExcluded
 * address:  0x0689CA0C
 * packet:   pkt_ov095_0689CA0C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ID_IsInList  0x0689C888  thumb
 *   gCallMoveExcludedMoves     0x0689E330  data  ov095  a2
 */

extern unsigned short gCallMoveExcludedMoves[];

int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);

int BTL_ID_IsCallMoveExcluded(unsigned a)
{
    return BTL_ID_IsInList(a, gCallMoveExcludedMoves, 0xb);
}
