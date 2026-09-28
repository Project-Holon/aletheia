/*
 * function: func_021C204C
 * address:  0x021C204C
 * packet:   pkt_ov114_021C204C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghttpCleanup (libdwcgsghttp.TWL.HYB.a(ghttpmain.o))
 *
 * symbols:
 *   func_021C0370  0x021C0370  arm  ov114
 *   func_021C0FB0  0x021C0FB0  arm  ov114
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021C0374  0x021C0374  arm  ov114
 *   func_021C036C  0x021C036C  arm  ov114
 *   g_021D3B64  0x021D3B64  data
 *   g_021D3B2C  0x021D3B2C  data
 */

extern void func_021C0370(void);
extern void func_021C0FB0(void);
extern void func_0217EAE0(void *ptr);
extern void func_021C0374(void);
extern void func_021C036C(void);
extern int g_021D3B64;
extern void *g_021D3B2C;

void func_021C204C(void)
{
	func_021C0370();
	if (--g_021D3B64 == 0) {
		func_021C0FB0();
		if (g_021D3B2C != 0) {
			func_0217EAE0(g_021D3B2C);
			g_021D3B2C = 0;
		}
		func_021C0374();
		func_021C036C();
	} else {
		func_021C0374();
	}
}
