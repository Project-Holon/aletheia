/*
 * function: func_021A141C
 * address: 0x021A141C
 * packet: pkt_ov021_021A141C
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
 *   func_0217D4DC 0x0217D4DC thumb ov018
 */

void *func_0217D4DC(void *w, int b, int c);

typedef struct HidObj_021A141C {
    int f0[8];
    void *f20;
} HidObj_021A141C;

void *func_021A141C(HidObj_021A141C *w, int b)
{
    return func_0217D4DC(w->f20, b, (int)w);
}
