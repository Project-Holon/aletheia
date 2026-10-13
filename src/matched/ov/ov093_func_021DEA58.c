/*
 * function: BTL_HANDLER_ITEM_FocusSash_CheckSurvive
 * address: 0x021DEA58
 * packet: pkt_ov093_021DEA58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: func_021C7CF4 returns its live r0 here (the matched
 * tail forwarder is declared void); r1 is visibly loaded with c before
 * the call and is retained as an argument, per canonical exceptions.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
extern void *func_021C7CF4(int *,int);
typedef unsigned char u8;
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void BTL_HANDLER_ITEM_FocusSash_CheckSurvive(int a,int *b,int c,int *p) { if(c==BTL_EVENT_GetVar(4)) { if(BTL_POKEPARAM_IsHpFull(func_021C7CF4(b,c))) *p=BTL_EVENT_OverwriteVar(58,3); else *p=0; } }
