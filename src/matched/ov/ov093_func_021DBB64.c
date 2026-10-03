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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 */
extern int func_021D775C(int);
typedef unsigned short u16;
struct QI;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
void func_021DBB64(int a,void *b,int c,int *d) { if(c==func_021D775C(2) && func_021D775C(0x2d)==0 && func_021D5B40(func_021C7CF4(b,c))) *d=1; }
