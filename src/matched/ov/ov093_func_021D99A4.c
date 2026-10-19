/*
 * function: HAND_TOKUSEI_ShieldDust_BlockForeignChange
 * address: 0x021D99A4
 * packet: pkt_ov093_021D99A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);
void HAND_TOKUSEI_ShieldDust_BlockForeignChange(int a,int b,int c) { if(c==BTL_EVENT_GetVar(4) && c!=BTL_EVENT_GetVar(3)) BTL_EVENT_OverwriteVar(0x41,1); }
