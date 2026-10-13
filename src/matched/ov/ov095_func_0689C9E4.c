/*
 * function: BTL_ID_GetItemCuredSick
 * address: 0x0689C9E4
 * packet: pkt_ov095_0689C9E4
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
 *   gItemCuredSickKinds 0x0689E374 data a4
 */

unsigned int BTL_ID_GetItemCuredSick(unsigned a);
extern const unsigned int gItemCuredSickKinds[];

unsigned int BTL_ID_GetItemCuredSick(unsigned a)
{
    if (a < 6) return gItemCuredSickKinds[a];
    return 0;
}
