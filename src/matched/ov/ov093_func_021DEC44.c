/*
 * unit: yes
 * function: HAND_ITEM_LifeOrb_BoostDamage, HAND_ITEM_GetMetronomeHandlers
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
 *   gMetronomeHandlers 0x021F13BC data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   HAND_ITEM_GetBoostRatio 0x021DD008 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int gMetronomeHandlers;
extern void BTL_EVENT_MultiplyVar(int,int);
extern int HAND_ITEM_GetBoostRatio(int);
void HAND_ITEM_LifeOrb_BoostDamage(int a,int b,int c) { if(c==BTL_EVENT_GetVar(3)) BTL_EVENT_MultiplyVar(53,HAND_ITEM_GetBoostRatio(a)); }
int *HAND_ITEM_GetMetronomeHandlers(int *p) { *p=1; return &gMetronomeHandlers; }
