/*
 * function: func_021DF65C
 * address:  0x021DF65C
 * packet:   pkt_ov175_021DF65C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleWSLoginError (libdwcsc.TWL.HYB.a(dwc_sc.o))
 *
 * symbols:
 *   func_02059F54  0x02059F54  arm
 *
 * The prior "case 105..108 is a second jump table" residue was a wrong value
 * set: the switch also has case 1 (the 0..7 table maps 0 to default, 1..7 to
 * the -8 arm). Adding case 1 shifted the switch tree so 105 became a lone node
 * and 106..108 a linear range chain, exactly as the image.
 */

extern void func_02059F54(int error, int errorCode);

int func_021DF65C(int result)
{
	int dwcError = 20;
	int errorCode = -43000;
	if (result == 0)
		return 0;
	switch (result) {
	case 1: case 2: case 3: case 4: case 5: case 6: case 7:
	case 100: case 101: case 102: case 103:
	case 105: case 106: case 107: case 108:
		errorCode -= 8;
		break;
	case 104:
		dwcError = 9;
		errorCode -= 6;
		break;
	default:
		errorCode -= 15;
		break;
	}
	func_02059F54(dwcError, errorCode);
	return result;
}
