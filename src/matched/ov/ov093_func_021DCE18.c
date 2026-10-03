/*
 * function: func_021DCE18
 * address: 0x021DCE18
 * packet: pkt_ov093_021DCE18
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021DCE48 0x021DCE48 thumb ov093
 */
typedef unsigned short u16;
extern int func_021D775C(int);
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
extern void func_021DCE48(int,unsigned char *,int);
void func_021DCE18(int a,unsigned char *b,int c) { int k; k=func_021D775C(16); if(k!=func_021D70A8((void *)a) && c==func_021D775C(2)) func_021DCE48(a,b,c); }
