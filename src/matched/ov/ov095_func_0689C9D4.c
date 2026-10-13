/*
 * function: BTL_ID_IsSimpleEffectId
 * address: 0x0689C9D4
 * packet: pkt_ov095_0689C9D4
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
 *   gSimpleEffectIds 0x0689E35C data a2
 *   BTL_ID_IsInList 0x0689C888 thumb
 */

int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
int BTL_ID_IsSimpleEffectId(unsigned a);
extern unsigned short gSimpleEffectIds[];

int BTL_ID_IsSimpleEffectId(unsigned a)
{
    return BTL_ID_IsInList(a, gSimpleEffectIds, 12);
}
