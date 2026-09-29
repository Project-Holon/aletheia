/*
 * function: func_021C15D0
 * address:  0x021C15D0
 * packet:   pkt_ov016_021C15D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      DWCi_RAKUlSetResult (libdwcutil.TWL.HYB.a(rakuraku.o))
 *
 * symbols:
 *   func_021BC7F0  0x021BC7F0  thumb  ov016
 *   OS_Terminate  0x02088234  arm
 *   func_021CF9BC  0x021CF9BC  arm  ov016
 */

extern int func_021BC7F0(void *param);
extern void OS_Terminate(void);
extern void func_021CF9BC(void *param);

void func_021C15D0(void)
{
	char prm[0xe8];

	if (func_021BC7F0(prm) != 1)
		OS_Terminate();
	func_021CF9BC(prm);
}
