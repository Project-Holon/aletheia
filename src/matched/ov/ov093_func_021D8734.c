/*
 * function: BTL_CALC_HugePowerDoubleAttack
 * address: 0x021D8734
 * packet: pkt_ov093_021D8734
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
extern int WAZA_TOOL_GetDamageType(int);
void BTL_CALC_HugePowerDoubleAttack(int a,int b,int c) { if (c==BTL_EVENT_GetVar(3)) { if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(18))==1) BTL_EVENT_MultiplyVar(53,8192); } }
