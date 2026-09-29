/*
 * function: func_021C1518
 * address:  0x021C1518
 * packet:   pkt_ov016_021C1518
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RAKUlGetState (libdwcutil.TWL.HYB.a(rakuraku.o))
 *
 * symbols:
 *   func_021BC7F0  0x021BC7F0  thumb  ov016
 *   OS_Terminate  0x02088234  arm
 *   g_021DE594  0x021DE594  data
 */

extern int func_021BC7F0(void *param);
extern void OS_Terminate(void);
extern int *g_021DE594;

int func_021C1518(void)
{
	int prm[0x3a];

	switch (*g_021DE594) {
	case 0:
	case 1:
	case 3:
	case 5:
		return 0;
	case 2:
		return 1;
	case 4:
		return 2;
	case 6:
		if (func_021BC7F0(prm) != 1)
			OS_Terminate();
		if (prm[8] >= 0 && prm[8] <= 3 && prm[9] == 1)
			return 3;
		return 5;
	case 7:
		return 4;
	}
}
