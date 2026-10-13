/*
 * function: C_GEAR_POWER_ONOFF_Delete
 * address: 0x021EFF2C
 * packet: pkt_ov035_021EFF2C
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   C_GEAR_POWER_ONOFF_ExitScreen 0x021EFFD4 thumb ov035
 *   func_020307B0 0x020307B0 arm
 */
extern void C_GEAR_POWER_ONOFF_ExitScreen(char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void C_GEAR_POWER_ONOFF_Delete(char *p) { C_GEAR_POWER_ONOFF_ExitScreen(p); func_020307B0(p); }
