/*
 * function: FIELD_SUBSCREEN_NoGearHook
 * address: 0x021A1190
 * packet: pkt_ov021_021A1190
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
 *   NO_GEAR_Hook 0x021F0114 thumb ov030
 */

typedef unsigned int   u32;
extern void NO_GEAR_Hook(void *a);
void FIELD_SUBSCREEN_NoGearHook(u32 *p);

void FIELD_SUBSCREEN_NoGearHook(u32 *p) { NO_GEAR_Hook((void *)p[8]); }
