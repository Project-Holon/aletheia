/*
 * function: func_021A1410
 * address: 0x021A1410
 * packet: pkt_ov021_021A1410
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
 *   func_0217D3AC 0x0217D3AC thumb ov018
 */

void func_0217D3AC(int id);

typedef struct HidObj_021A1410 {
    int f0[8];
    int f20;
} HidObj_021A1410;

void func_021A1410(HidObj_021A1410 *w)
{
    func_0217D3AC(w->f20);
}
