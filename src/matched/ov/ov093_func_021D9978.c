/*
 * function: HAND_TOKUSEI_StatLossGuard_BlockForeignDrop
 * address: 0x021D9978
 * packet: pkt_ov093_021D9978
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
void HAND_TOKUSEI_StatLossGuard_BlockForeignDrop(int a,int b,int c) { if(c==BTL_EVENT_GetVar(4) && c!=BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(0x1d)!=8) BTL_EVENT_OverwriteVar(0x41,1); }
