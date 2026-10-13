/*
 * function: FIELD_SUBSCREEN_UpdateNoGear
 * address: 0x021A119C
 * packet: pkt_ov021_021A119C
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
 *   NO_GEAR_Update 0x021F00F8 thumb ov030
 */

typedef unsigned int   u32;
extern void NO_GEAR_Update(char *p);
void FIELD_SUBSCREEN_UpdateNoGear(u32 *p);

void FIELD_SUBSCREEN_UpdateNoGear(u32 *p) { NO_GEAR_Update((char *)p[8]); }
