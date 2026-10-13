/*
 * function: FIELD_SUBSCREEN_ExitIntrude
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
 *   INTRUDE_SUBDISP_Exit 0x0217D160 thumb ov018
 */

void INTRUDE_SUBDISP_Exit(int a0);

typedef struct HidObj_021A13F8 {
    int f0[8];
    int f20;
} HidObj_021A13F8;

void FIELD_SUBSCREEN_ExitIntrude(HidObj_021A13F8 *w)
{
    INTRUDE_SUBDISP_Exit(w->f20);
}
