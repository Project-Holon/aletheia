/*
 * unit: yes
 * function: func_021DC13C, func_021DC164
 * address: 0x021DC13C
 * packet: pkt_ov093_021DC13C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gFriendGuardHandlers 0x021F0780 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int gFriendGuardHandlers;
extern int BTL_EVENT_GetVar(int);
extern int func_021B9A24(unsigned int,unsigned int);
extern void BTL_EVENT_MultiplyVar(int,int);
void func_021DC13C(int a,int b,unsigned int c) { unsigned char k; k=BTL_EVENT_GetVar(4); if(k!=c && func_021B9A24(c,k)) BTL_EVENT_MultiplyVar(0x35,3<<10); }
int *func_021DC164(int *p) { *p=1; return &gFriendGuardHandlers; }
