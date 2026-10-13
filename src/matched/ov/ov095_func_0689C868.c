/*
 * function: BTL_ID_IsBatonPassSick
 * address: 0x0689C868
 * packet: pkt_ov095_0689C868
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBatonPassSickKinds 0x0689E200 data a2
 */

extern unsigned short gBatonPassSickKinds[];
int BTL_ID_IsBatonPassSick(unsigned a)
{
    unsigned i;
    for (i = 0; i < 14; i++) {
        if (a == gBatonPassSickKinds[i]) return 1;
    }
    return 0;
}
