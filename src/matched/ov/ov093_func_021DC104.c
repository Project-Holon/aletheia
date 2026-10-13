/*
 * unit: yes
 * function: func_021DC104, func_021DC130
 * address: 0x021DC104
 * packet: pkt_ov093_021DC104
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMultiscaleHandlers 0x021F0690 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int gMultiscaleHandlers;
extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
typedef unsigned char u8;
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern void BTL_EVENT_MultiplyVar(int,int);
void func_021DC104(int a,void *b,int c) { int k=4; if(c==BTL_EVENT_GetVar(k) && BTL_POKEPARAM_IsHpFull(func_021C7CF4(b,c))) BTL_EVENT_MultiplyVar(0x35,k<<9); }
int *func_021DC130(int *p) { *p=1; return &gMultiscaleHandlers; }
