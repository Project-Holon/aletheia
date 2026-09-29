/*
 * function: func_021D6EA4
 * address:  0x021D6EA4
 * packet:   pkt_ov016_021D6EA4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskTransfer (libdwcutil.TWL.HYB.a(obj.o))
 *
 * symbols:
 *   func_020862F0  0x020862F0  arm
 *   func_0207E684  0x0207E684  arm
 *   func_0207E708  0x0207E708  arm
 *   g_021DE6A8  0x021DE6A8  data
 */

extern void func_020862F0(void *start, unsigned long n);
extern void func_0207E684(void *src, unsigned long off, unsigned long sz);
extern void func_0207E708(void *src, unsigned long off, unsigned long sz);
extern char *g_021DE6A8;

void func_021D6EA4(void)
{
	func_020862F0(g_021DE6A8, 0x800);
	func_0207E684(g_021DE6A8, 0, 0x400);
	func_0207E708(g_021DE6A8 + 0x400, 0, 0x400);
}
