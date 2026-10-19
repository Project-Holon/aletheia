/*
 * function: procFade
 * address:  0x021C18C4
 * packet:   pkt_ov016_021C18C4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procFade (libdwcutil.TWL.HYB.a(sceneinit.o))
 *
 * symbols:
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021C1908  0x021C1908  arm  ov016
 */

extern int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C1908(void);

void procFade(void)
{
	DWCi_EFFlFade(2, 1, 2, 0x14);
	DWCi_EFFlFade(2, 0, 2, 0x14);
	DWCi_ChangeScene((unsigned int)func_021C1908);
}
