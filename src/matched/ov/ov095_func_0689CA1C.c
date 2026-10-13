/*
 * function: BTL_ID_IsSleepTalkExcludedMove
 * address: 0x0689CA1C
 * packet: pkt_ov095_0689CA1C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ID_IsCallMoveExcluded 0x0689CA0C thumb ov095
 *   BTL_ID_IsInList 0x0689C888 thumb ov095
 *   gSleepTalkExtraExcludedMoves 0x0689E346 data a2
 */

extern int BTL_ID_IsCallMoveExcluded(unsigned a);
extern int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
extern unsigned short gSleepTalkExtraExcludedMoves[];
int BTL_ID_IsSleepTalkExcludedMove(unsigned a)
{
    if (BTL_ID_IsCallMoveExcluded(a)) return 1;
    return BTL_ID_IsInList(a, gSleepTalkExtraExcludedMoves, 11);
}
