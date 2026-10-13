/*
 * function: FIELD_3DBG_ExitCGear
 * address: 0x021A10D4
 * packet: pkt_ov021_021A10D4
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
 *   C_GEAR_Nop 0x021F2980 thumb ov029
 */

typedef unsigned int   u32;
u32 C_GEAR_Nop(u32 a);
u32 FIELD_3DBG_ExitCGear(u32 *p);

u32 FIELD_3DBG_ExitCGear(u32 *p) { return C_GEAR_Nop(p[8]); }
