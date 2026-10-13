/*
 * function: BTL_ID_GetTurnCheckSick
 * address: 0x0689C9F8
 * packet: pkt_ov095_0689C9F8
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
 *   gTurnCheckSickKinds 0x0689E4C0 data a4
 */

unsigned int BTL_ID_GetTurnCheckSick(unsigned a);
extern const unsigned int gTurnCheckSickKinds[];

unsigned int BTL_ID_GetTurnCheckSick(unsigned a)
{
    if (a < 0x23) return gTurnCheckSickKinds[a];
    return 0;
}
