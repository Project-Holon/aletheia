/*
 * function: BTL_TOKUSEI_StickyHold_BlockItemRemoval
 * address: 0x021DB854
 * packet: pkt_ov093_021DB854
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
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void BTL_TOKUSEI_StickyHold_BlockItemRemoval(int a,int b,int c,int *d) { if(c==BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(0x2d)==0) *d=BTL_EVENT_OverwriteVar(0x41,1); }
