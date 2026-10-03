/*
 * function: func_021D6EEC
 * address:  0x021D6EEC
 * packet:   pkt_ov016_021D6EEC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OBJlEnd (libdwcutil.TWL.HYB.a(obj.o))
 *
 * symbols:
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE6A8  0x021DE6A8  data
 */

extern void func_021D7744(unsigned int idx, void *r4);
extern void func_021D6438(void **mem);
extern char *g_021DE6A8;

void func_021D6EEC(void)
{
	func_021D7744(1, *(void **)(g_021DE6A8 + 0x808));
	func_021D6438((void *)0x021DE6A8);
}
