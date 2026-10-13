/*
 * function: HAND_TOKUSEI_LightMetalHalveWeight
 * address: 0x021DCC10
 * packet: pkt_ov093_021DCC10
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment at 021DCC2A.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
void HAND_TOKUSEI_LightMetalHalveWeight(int a, int b, int c) { if (c == BTL_EVENT_GetVar(2)) BTL_EVENT_MultiplyVar(0x35, 2048); }
