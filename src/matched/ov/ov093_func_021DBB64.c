/*
 * function: func_021DBB64
 * address: 0x021DBB64
 * packet: pkt_ov093_021DBB64
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
 */
extern int BTL_EVENT_GetVar(int);
typedef unsigned short u16;
struct QI;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
void func_021DBB64(int a,void *b,int c,int *d) { if(c==BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(0x2d)==0 && BTL_POKEPARAM_GetItem(func_021C7CF4(b,c))) *d=1; }
