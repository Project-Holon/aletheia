/*
 * function: func_021DE24C
 * address: 0x021DE24C
 * packet: pkt_ov093_021DE24C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 021DE26E.
 * interface: original restores r3 from r7 before calling 021DE228.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DE228 0x021DE228 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void func_021DE228(int, void *, int, int);
void func_021DE24C(int a, void *b, int c, int d) { if (func_021D775C(12) != 6) func_021DE228(a,b,c,d); }
