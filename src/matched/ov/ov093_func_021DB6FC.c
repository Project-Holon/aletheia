/*
 * function: BTL_TOKUSEI_Klutz_NoticeHeldItem
 * address: 0x021DB6FC
 * packet: pkt_ov093_021DB6FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
typedef unsigned short u16;
struct QI;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *,void *);
void BTL_TOKUSEI_Klutz_NoticeHeldItem(int a,void *b,int c) { unsigned char *p; if(c==BTL_EVENT_GetVar(2) && BTL_POKEPARAM_GetItem(func_021C7CF4(b,c))) { p=func_021C88A4(b,0x21,c); p[4]=c; func_021C88C8(b,p); } }
