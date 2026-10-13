/*
 * function: FIELD_SUBSCREEN_CheckIntrudeRequest
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
 *   INTRUDE_SUBDISP_EventCheck 0x0217D4DC thumb ov018
 */

void *INTRUDE_SUBDISP_EventCheck(void *w, int b, int c);

typedef struct HidObj_021A141C {
    int f0[8];
    void *f20;
} HidObj_021A141C;

void *FIELD_SUBSCREEN_CheckIntrudeRequest(HidObj_021A141C *w, int b)
{
    return INTRUDE_SUBDISP_EventCheck(w->f20, b, (int)w);
}
