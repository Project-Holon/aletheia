/*
 * function: func_021C117C
 * address:  0x021C117C
 * packet:   pkt_ov016_021C117C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd (libdwcutil.TWL.HYB.a(move.o))
 *
 * symbols:
 *   func_021D3BF8  0x021D3BF8  arm  ov016
 *   func_021D7724  0x021D7724  arm  ov016
 *   g_021DE590  0x021DE590  data
 */

extern int func_021D3BF8(void);
extern void func_021D7724(int kind, void *task);
extern char *g_021DE590;

void func_021C117C(void *task)
{
	if (func_021D3BF8() == 0)
		return;
	g_021DE590[0x1e2a1] = 1;
	func_021D7724(0, task);
}
