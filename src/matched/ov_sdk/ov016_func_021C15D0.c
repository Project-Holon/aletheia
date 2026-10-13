/*
 * function: DWCi_RAKUlSetResult
 * address:  0x021C15D0
 * packet:   pkt_ov016_021C15D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RAKUlSetResult (libdwcutil.TWL.HYB.a(rakuraku.o))
 *
 * symbols:
 *   func_021BC7F0  0x021BC7F0  thumb  ov016
 *   OS_Terminate  0x02088234  arm
 *   DWCi_SETTINGlSetRaku  0x021CF9BC  arm  ov016
 */

extern int func_021BC7F0(int a);
extern void OS_Terminate(void);
extern void DWCi_SETTINGlSetRaku(void *param);

void DWCi_RAKUlSetResult(void)
{
	char prm[0xe8];

	if (func_021BC7F0((int)prm) != 1)
		OS_Terminate();
	DWCi_SETTINGlSetRaku(prm);
}
