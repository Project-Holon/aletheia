/*
 * function: func_021DE3D4, func_021DE3F0
 * address: 0x021DE3D4
 * packet: pkt_ov093_021DE3D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F163C 0x021F163C data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void func_021D7704(int,int);
void func_021DE3D4(int a, int b, int c) { int k=2; if(c == func_021D775C(k)) func_021D7704(0x35,k<<10); }
extern u8 d_021F163C[];
void *func_021DE3F0(int *p) { *p=2; return d_021F163C; }
