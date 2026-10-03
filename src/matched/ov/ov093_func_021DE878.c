/*
 * function: func_021DE878
 * address: 0x021DE878
 * packet: pkt_ov093_021DE878
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
 *   func_021D5444 0x021D5444 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern void *func_021C7CF4(int *,int);
typedef unsigned short u16;
struct QF;
extern u16 func_021D5444(struct QF *p);
void func_021DE878(int a,int *b,int c) { if(c==func_021D775C(3)) { if((unsigned int)func_021D5444(func_021C7CF4(b,c))-380<=1) { if(func_021D775C(26)==2) func_021D7704(53,6144); } } }
