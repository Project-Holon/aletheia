/*
 * function: FIELD_SUBSCREEN_DrawIntrude
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
 *   INTRUDE_SUBDISP_Draw 0x0217D3AC thumb ov018
 */

void INTRUDE_SUBDISP_Draw(int id);

typedef struct HidObj_021A1410 {
    int f0[8];
    int f20;
} HidObj_021A1410;

void FIELD_SUBSCREEN_DrawIntrude(HidObj_021A1410 *w)
{
    INTRUDE_SUBDISP_Draw(w->f20);
}
