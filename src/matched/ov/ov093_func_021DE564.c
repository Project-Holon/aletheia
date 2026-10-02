/*
 * function: func_021DE564, func_021DE58C
 * address: 0x021DE564
 * packet: pkt_ov093_021DE564
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: u8 local holds getter result before increment; narrow callee argument.
 * unit: yes
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   d_021F146C 0x021F146C data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern int func_021D76BC(int,u8);
void func_021DE564(int a, int b, int c) { u8 j; if(c == func_021D775C(3)) { j=func_021D775C(0x2c); func_021D76BC(0x2c,j+1); } }
extern u8 d_021F146C[];
void *func_021DE58C(int *p) { *p=1; return d_021F146C; }
