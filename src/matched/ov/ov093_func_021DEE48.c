/*
 * function: HAND_ITEM_PowerHerb_CheckSkipCharge
 * address: 0x021DEE48
 * packet: pkt_ov093_021DEE48
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void HAND_ITEM_PowerHerb_CheckSkipCharge(int a,int b,int c,int *p) { if(c==BTL_EVENT_GetVar(3)) { if(BTL_EVENT_GetVar(18)!=507) { if(BTL_EVENT_OverwriteVar(81,1)) *p=1; } } }
