/*
 * function: func_021A13F8
 * address: 0x021A13F8
 * packet: pkt_ov021_021A13F8
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/unit_021A1144.c and filed here.
 *
 * symbols:
 *   func_0217D160 0x0217D160 thumb ov018
 */

void func_0217D160(int a0);

typedef struct HidObj_021A13F8 {
    int f0[8];
    int f20;
} HidObj_021A13F8;

void func_021A13F8(HidObj_021A13F8 *w)
{
    func_0217D160(w->f20);
}
