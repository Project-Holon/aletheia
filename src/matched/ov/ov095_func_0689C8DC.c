/*
 * function: BTL_ID_IsPressureNoExtraPpMove
 * address: 0x0689C8DC
 * packet: pkt_ov095_0689C8DC
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
 *   gPressureNoExtraPpMoves 0x0689E2C4 data a2
 *   BTL_ID_IsInList 0x0689C888 thumb
 */

int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
int BTL_ID_IsPressureNoExtraPpMove(unsigned a);
extern unsigned short gPressureNoExtraPpMoves[];

int BTL_ID_IsPressureNoExtraPpMove(unsigned a)
{
    return BTL_ID_IsInList(a, gPressureNoExtraPpMoves, 5);
}
