/*
 * function: BTL_ID_IsEncoreFailMove
 * address: 0x0689C8AC
 * packet: pkt_ov095_0689C8AC
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
 *   gEncoreFailMoves 0x0689E2DA data a2
 *   BTL_ID_IsInList 0x0689C888 thumb
 */

int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
int BTL_ID_IsEncoreFailMove(unsigned a);
extern unsigned short gEncoreFailMoves[];

int BTL_ID_IsEncoreFailMove(unsigned a)
{
    return BTL_ID_IsInList(a, gEncoreFailMoves, 6);
}
