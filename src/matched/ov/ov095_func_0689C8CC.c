/*
 * function: BTL_ID_IsMetronomeItemIgnoredMove
 * address: 0x0689C8CC
 * packet: pkt_ov095_0689C8CC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov095/unit_0689C888.c and filed here.
 *
 * symbols:
 *   gMetronomeItemIgnoredMoves 0x0689E2B6 data a2
 *   BTL_ID_IsInList 0x0689C888 thumb
 */

int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
int BTL_ID_IsMetronomeItemIgnoredMove(unsigned a);
extern unsigned short gMetronomeItemIgnoredMoves[];

int BTL_ID_IsMetronomeItemIgnoredMove(unsigned a)
{
    return BTL_ID_IsInList(a, gMetronomeItemIgnoredMoves, 3);
}
