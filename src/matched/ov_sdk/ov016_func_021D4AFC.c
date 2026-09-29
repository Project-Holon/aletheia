/*
 * function: func_021D4AFC
 * address:  0x021D4AFC
 * packet:   pkt_ov016_021D4AFC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      cbRead (libdwcutil.TWL.HYB.a(archive.o))
 *
 * symbols:
 *   func_0207A78C  0x0207A78C  arm
 *   func_020771B4  0x020771B4  arm
 *   func_021D4B50  0x021D4B50  arm  ov016
 */

extern unsigned long func_0207A78C(void *arc);
extern int func_020771B4(int dma, unsigned long src, void *dst, unsigned long len, void (*cb)(void), void *arg, int async);
extern void func_021D4B50(void);

int func_021D4AFC(void *arc, void *dst, unsigned long pos, unsigned long size)
{
	unsigned long base = func_0207A78C(arc);
	func_020771B4(-1, pos + base, dst, size, func_021D4B50, arc, 1);
	return 0x100;
}
