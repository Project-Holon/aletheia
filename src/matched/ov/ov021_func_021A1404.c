/*
 * function: func_021A1404
 * address: 0x021A1404
 * packet: pkt_ov021_021A1404
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
 *   func_0217D1C0 0x0217D1C0 thumb ov018
 */

typedef unsigned char  u8;
void func_0217D1C0(u8 *w, int b);

typedef struct HidObj_021A1404 {
    int f0[8];
    u8 *f20;
} HidObj_021A1404;

void func_021A1404(HidObj_021A1404 *w, int b)
{
    func_0217D1C0(w->f20, b);
}
