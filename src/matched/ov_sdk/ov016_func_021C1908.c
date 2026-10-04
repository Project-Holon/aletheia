/*
 * function: func_021C1908
 * address:  0x021C1908
 * packet:   pkt_ov016_021C1908
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procWait (libdwcutil.TWL.HYB.a(sceneinit.o))
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021C0ED8  0x021C0ED8  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C1984  0x021C1984  arm  ov016
 *   func_021CBC90  0x021CBC90  arm  ov016
 */

extern int func_021D5580(int lcd);
extern unsigned int func_021C0ED8(void);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021C1984(void);
extern void func_021CBC90(void);

void func_021C1908(void)
{
	if (func_021D5580(1))
		return;
	if (func_021D5580(0))
		return;
	switch (func_021C0ED8()) {
	case 0:
		func_021C0E50(0, (unsigned int)((void *)1));
		func_021C0E40((unsigned int)func_021C1984);
		break;
	case 1:
		func_021C0E50((unsigned int)((void *)1), (unsigned int)((void *)1));
		func_021C0E40((unsigned int)func_021CBC90);
		break;
	}
}
