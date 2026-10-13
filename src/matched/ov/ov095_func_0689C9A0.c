/*
 * function: BTL_ID_IsBallWithCatchBonus
 * address: 0x0689C9A0
 * packet: pkt_ov095_0689C9A0
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
 *   gCatchBonusBalls 0x0689E308 data a2
 *   BTL_ID_IsInList 0x0689C888 thumb
 */

int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
int BTL_ID_IsBallWithCatchBonus(unsigned a);
extern unsigned short gCatchBonusBalls[];

int BTL_ID_IsBallWithCatchBonus(unsigned a)
{
    return BTL_ID_IsInList(a, gCatchBonusBalls, 10);
}
