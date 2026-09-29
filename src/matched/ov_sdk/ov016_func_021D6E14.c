/*
 * function: func_021D6E14
 * address:  0x021D6E14
 * packet:   pkt_ov016_021D6E14
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OBJlInit (libdwcutil.TWL.HYB.a(obj.o))
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_02082AC0  0x02082AC0  arm
 *   func_021D5410  0x021D5410  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DE6A8  0x021DE6A8  data
 *   func_021D6EA4  0x021D6EA4  arm  ov016
 */

extern void *func_021D6414(unsigned long size, int align);
extern void func_02082AC0(unsigned long data, void *dst, unsigned long size);
extern void *func_021D5410(long size, void *data, long dsize);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021D6EA4(void);
extern char *g_021DE6A8;

void func_021D6E14(void)
{
	int i;

	g_021DE6A8 = func_021D6414(0x80c, 4);
	func_02082AC0(0x200, g_021DE6A8, 0x800);
	for (i = 0; i < 2; i++)
		*(void **)(g_021DE6A8 + i * 4 + 0x800) = func_021D5410(0x40, g_021DE6A8 + i * 0x400, 8);
	*(void **)(g_021DE6A8 + 0x808) = func_021D7680(1, (void (*)(void *, void *))func_021D6EA4, 0, 0xc8);
}
