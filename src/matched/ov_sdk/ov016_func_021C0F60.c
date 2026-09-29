/*
 * function: func_021C0F60
 * address:  0x021C0F60
 * packet:   pkt_ov016_021C0F60
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MSGlInit (libdwcutil.TWL.HYB.a(message.o))
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5410  0x021D5410  arm  ov016
 *   g_021DE58C  0x021DE58C  data
 */

extern void *func_021D6414(unsigned long size, int align);
extern void *func_021D5410(long size, void *data, long dsize);
extern char *g_021DE58C;

void func_021C0F60(void)
{
	void *m = func_021D6414(0x64, 4);
	g_021DE58C = m;
	*(void **)(g_021DE58C + 0x60) = func_021D5410(8, m, 0xc);
}
