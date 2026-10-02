/*
 * unit: yes
 * function: func_021DE948, func_021DE974
 * address: 0x021DE948
 * packet: pkt_ov093_021DE948
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DE974.
 * symbols:
 *   d_021F18EC 0x021F18EC data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 */
extern int func_021D775C(int);
extern int d_021F18EC;
extern void func_021D7704(int,int);
extern int func_0201C1E8(unsigned short);
void func_021DE948(int a,int b,int c) { if(c==func_021D775C(3)) { if(func_0201C1E8(func_021D775C(18))==1) func_021D7704(53,6144); } }
int *func_021DE974(int *p) { *p=3; return &d_021F18EC; }
