/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_ExpertBelt_BoostSuperEffective, BTL_HANDLER_ITEM_GetLifeOrbHandlers
 * address: 0x021DEBB4
 * packet: pkt_ov093_021DEBB4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DEBE0.
 * symbols:
 *   d_021F16DC 0x021F16DC data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio 0x021DD008 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int d_021F16DC;
extern void BTL_EVENT_MultiplyVar(int,int);
extern int BTL_HANDLER_ITEM_GetBoostRatio(int);
void BTL_HANDLER_ITEM_ExpertBelt_BoostSuperEffective(int a,int b,int c) { if(c==BTL_EVENT_GetVar(3)) { if(BTL_EVENT_GetVar(56)>3) BTL_EVENT_MultiplyVar(53,BTL_HANDLER_ITEM_GetBoostRatio(a)); } }
int *BTL_HANDLER_ITEM_GetLifeOrbHandlers(int *p) { *p=2; return &d_021F16DC; }
