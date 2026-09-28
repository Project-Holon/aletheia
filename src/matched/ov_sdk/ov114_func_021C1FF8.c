/*
 * function: func_021C1FF8
 * address:  0x021C1FF8
 * packet:   pkt_ov114_021C1FF8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghttpStartup (libdwcgsghttp.TWL.HYB.a(ghttpmain.o))
 *
 * symbols:
 *   func_021C0370  0x021C0370  arm  ov114
 *   func_021C0368  0x021C0368  arm  ov114
 *   func_021C0374  0x021C0374  arm  ov114
 *   g_021D3B64  0x021D3B64  data
 *   g_021CE5AC  0x021CE5AC  data
 *   g_021CE5B0  0x021CE5B0  data
 */

extern void func_021C0370(void);
extern void func_021C0368(void);
extern void func_021C0374(void);
extern int g_021D3B64;
extern int g_021CE5AC;
extern int g_021CE5B0;

void func_021C1FF8(void)
{
	func_021C0370();
	if (++g_021D3B64 == 1) {
		func_021C0368();
		g_021CE5B0 = 125;
		g_021CE5AC = 250;
	} else {
		func_021C0374();
	}
}
