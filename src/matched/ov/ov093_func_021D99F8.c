/*
 * unit: yes
 * function: HAND_TOKUSEI_StatLossGuard_BlockIfFlagged, HAND_TOKUSEI_GetStatLossGuardHandlers
 * address: 0x021D99F8
 * packet: pkt_ov093_021D99F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gStatLossGuardHandlers 0x021F0CEC data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   func_021E85F8 0x021E85F8 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);
extern int func_021E85F8(int);
void HAND_TOKUSEI_StatLossGuard_BlockIfFlagged(int a,int b,int c) { if(func_021E85F8(c)!=0 && BTL_EVENT_GetVar(5)==1) BTL_EVENT_OverwriteVar(0x47,1); }
extern unsigned int gStatLossGuardHandlers;
void *HAND_TOKUSEI_GetStatLossGuardHandlers(int *p) { *p=5; return &gStatLossGuardHandlers; }
