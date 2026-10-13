/*
 * unit: yes
 * function: HAND_TOKUSEI_SuperLuckOnCriticalCheck, HAND_TOKUSEI_AddSuperLuck
 * address: 0x021D9BC8
 * packet: pkt_ov093_021D9BC8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0860 0x021F0860 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);
void HAND_TOKUSEI_SuperLuckOnCriticalCheck(int a,int b,int c) { unsigned char v; if(c==BTL_EVENT_GetVar(3)) { v=BTL_EVENT_GetVar(0x2c)+1; BTL_EVENT_OverwriteVar(0x2c,v); } }
extern unsigned int d_021F0860;
void *HAND_TOKUSEI_AddSuperLuck(int *p) { *p=1; return &d_021F0860; }
