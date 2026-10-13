/*
 * function: FIELD_SUBSCREEN_UpdatePowerOnoff
 * address: 0x021A1584
 * packet: pkt_ov021_021A1584
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_3dbg.c and filed here.
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_Update 0x021EFF3C thumb ov035
 */

typedef struct { unsigned char pad[0x20]; void *f20; } Obj_021A1584;
extern int C_GEAR_POWER_ONOFF_Update(void *p);
int FIELD_SUBSCREEN_UpdatePowerOnoff(Obj_021A1584 *p);

int FIELD_SUBSCREEN_UpdatePowerOnoff(Obj_021A1584 *p) { return C_GEAR_POWER_ONOFF_Update(p->f20); }
