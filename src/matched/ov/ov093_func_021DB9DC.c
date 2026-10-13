/*
 * unit: yes
 * function: HAND_TOKUSEI_Stench_SetFlinchChance, HAND_TOKUSEI_GetShadowTagHandlers
 * address: 0x021DB9DC
 * packet: pkt_ov093_021DB9DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gShadowTagHandlers 0x021F06E8 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int gShadowTagHandlers;
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void HAND_TOKUSEI_Stench_SetFlinchChance(int a,int b,int c) { if(c==BTL_EVENT_GetVar(3) && (unsigned char)BTL_EVENT_GetVar(0x25)==0) BTL_EVENT_OverwriteVar(0x26,10); }
int *HAND_TOKUSEI_GetShadowTagHandlers(int *p) { *p=1; return &gShadowTagHandlers; }
