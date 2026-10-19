/*
 * function: FIELD_SUBSCREEN_HandleCGearInput
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
 *   C_GEAR_HandleCommand 0x021F29D8 thumb ov029
 */

int C_GEAR_HandleCommand();

typedef struct HidObj_021A1138 {
    int f0[8];
    char * f20;
} HidObj_021A1138;

int FIELD_SUBSCREEN_HandleCGearInput(HidObj_021A1138 *w, int b)
{
    return C_GEAR_HandleCommand(w->f20, b, w);
}
