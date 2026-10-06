/*
 * unit: yes
 * function: func_021DE980, func_021DE9AC
 * address: 0x021DE980
 * packet: pkt_ov093_021DE980
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DE9AC.
 * symbols:
 *   d_021F1904 0x021F1904 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 */
extern int func_021D775C(int);
extern int d_021F1904;
extern void func_021D7704(int,int);
extern int func_0201C1E8(int a);
void func_021DE980(int a,int b,int c) { if(c==func_021D775C(3)) { if(func_0201C1E8((unsigned short)func_021D775C(18))==2) func_021D7704(53,6144); } }
int *func_021DE9AC(int *p) { *p=3; return &d_021F1904; }
