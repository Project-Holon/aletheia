/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_LifeOrb_BoostDamage, BTL_HANDLER_ITEM_GetMetronomeHandlers
 * address: 0x021DEC44
 * packet: pkt_ov093_021DEC44
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DEC64.
 * symbols:
 *   d_021F13BC 0x021F13BC data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio 0x021DD008 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int d_021F13BC;
extern void BTL_EVENT_MultiplyVar(int,int);
extern int BTL_HANDLER_ITEM_GetBoostRatio(int);
void BTL_HANDLER_ITEM_LifeOrb_BoostDamage(int a,int b,int c) { if(c==BTL_EVENT_GetVar(3)) BTL_EVENT_MultiplyVar(53,BTL_HANDLER_ITEM_GetBoostRatio(a)); }
int *BTL_HANDLER_ITEM_GetMetronomeHandlers(int *p) { *p=1; return &d_021F13BC; }
