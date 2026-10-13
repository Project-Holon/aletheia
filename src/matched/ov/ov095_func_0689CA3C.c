/*
 * function: BTL_ID_IsAssistExcludedMove
 * address: 0x0689CA3C
 * packet: pkt_ov095_0689CA3C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ID_IsCallMoveExcluded 0x0689CA0C thumb ov095
 *   BTL_ID_IsInList 0x0689C888 thumb ov095
 *   gAssistExtraExcludedMoves 0x0689E3D4 data a2
 */
extern int BTL_ID_IsCallMoveExcluded(unsigned a);
extern int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
extern unsigned short gAssistExtraExcludedMoves[];
int BTL_ID_IsAssistExcludedMove(unsigned a)
{
    if (BTL_ID_IsCallMoveExcluded(a))
        return 1;
    return BTL_ID_IsInList(a, gAssistExtraExcludedMoves, 20);
}
