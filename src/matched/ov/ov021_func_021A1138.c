/*
 * function: func_021A1138
 * address: 0x021A1138
 * packet: pkt_ov021_021A1138
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_fog.c and filed here.
 *
 * symbols:
 *   func_021F29D8 0x021F29D8 thumb ov029
 */

int func_021F29D8();

typedef struct HidObj_021A1138 {
    int f0[8];
    char * f20;
} HidObj_021A1138;

int func_021A1138(HidObj_021A1138 *w, int b)
{
    return func_021F29D8(w->f20, b, w);
}
