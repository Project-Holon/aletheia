/*
 * function: func_021D6F38
 * address:  0x021D6F38
 * packet:   pkt_ov016_021D6F38
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OBJlDelete (libdwcutil.TWL.HYB.a(obj.o))
 *
 * symbols:
 *   g_021DE6A8  0x021DE6A8  data
 *   func_021D546C  0x021D546C  arm  ov016
 */

extern void func_021D546C(void *que, void *elem);
extern char *g_021DE6A8;

void func_021D6F38(unsigned int *obj)
{
	int lcd;

	*obj = (*obj & 0xc1fffcff) | 0x200;
	lcd = 0;
	if ((char *)obj >= g_021DE6A8 + 0x400)
		lcd = 1;
	func_021D546C(*(void **)(g_021DE6A8 + 0x800 + lcd * 4), obj);
}
