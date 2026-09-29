/*
 * function: func_021D4C68
 * address:  0x021D4C68
 * packet:   pkt_ov016_021D4C68
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ARClRelease (libdwcutil.TWL.HYB.a(archive.o))
 *
 * symbols:
 *   func_021D6438  0x021D6438  arm  ov016
 *   func_021D546C  0x021D546C  arm  ov016
 *   g_021DE66C  0x021DE66C  data
 */

extern void func_021D6438(void *p);
extern void func_021D546C(void *que, void *elem);
extern char *g_021DE66C;

void func_021D4C68(void *file)
{
	func_021D6438(&file);
	func_021D546C(*(void **)(g_021DE66C + 0x84), file);
}
