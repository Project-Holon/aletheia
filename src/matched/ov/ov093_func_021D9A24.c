/*
 * function: HAND_TOKUSEI_SereneGrace_DoubleEffectChance
 * address: 0x021D9A24
 * packet: pkt_ov093_021D9A24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);
void HAND_TOKUSEI_SereneGrace_DoubleEffectChance(int a,int b,int c) { unsigned short v; if(c==BTL_EVENT_GetVar(3)) { v=BTL_EVENT_GetVar(0x26)*2; BTL_EVENT_OverwriteVar(0x26,v); } }
