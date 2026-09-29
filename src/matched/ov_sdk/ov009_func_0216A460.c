/*
 * function: func_0216A460
 * address:  0x0216A460
 * packet:   pkt_ov009_0216A460
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleGPError (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 */

extern void func_0216A3B8(int error, int errorCode);

int func_0216A460(int result)
{
	int dwcError;
	int errorCode;

	if (result == 0)
		return 0;
	switch (result) {
	case 1:
		dwcError = 9;
		errorCode = -1;
		break;
	case 2:
		dwcError = 9;
		errorCode = -2;
		break;
	case 3:
		dwcError = 6;
		errorCode = -10;
		break;
	case 4:
		dwcError = 6;
		errorCode = -20;
		break;
	}
	func_0216A3B8(dwcError, errorCode - 61000);
	return result;
}
