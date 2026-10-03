/*
 * function: func_021DEA58
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern void *func_021C7CF4(int *,int);
typedef unsigned char u8;
extern int func_021D5B48(u8 *p);
extern int func_021D76BC(int,unsigned int);
void func_021DEA58(int a,int *b,int c,int *p) { if(c==func_021D775C(4)) { if(func_021D5B48(func_021C7CF4(b,c))) *p=func_021D76BC(58,3); else *p=0; } }
