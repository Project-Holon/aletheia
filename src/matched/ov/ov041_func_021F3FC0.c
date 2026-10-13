/*
 * function: GIMMICK41_GetCannonDirection
 * address: 0x021F3FC0
 * packet: pkt_ov041_021F3FC0
 * region: ov041
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GIMMICK41_FacingToRingIndex 0x021F3F44 thumb ov041
 *   GIMMICK41_TurnRingDirection 0x021F3F70 thumb ov041
 *   gGimmick41CannonQuarterTurns 0x021F4660 data a1
 */

extern int GIMMICK41_FacingToRingIndex(int x);
extern int GIMMICK41_TurnRingDirection(int, int);
extern const unsigned char gGimmick41CannonQuarterTurns[];
int GIMMICK41_GetCannonDirection(unsigned int a, int i)
{
    return GIMMICK41_TurnRingDirection(GIMMICK41_FacingToRingIndex(a), gGimmick41CannonQuarterTurns[i]);
}
