/*
 * function: func_021DF65C
 * address:  0x021DF65C
 * packet:   pkt_ov175_021DF65C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_HandleWSLoginError (libdwcsc.TWL.HYB.a(dwc_sc.o))
 *
 * symbols:
 *   func_02059F54  0x02059F54  arm
 *
 * near miss (w4_s4): 16 B short. Original splits cases 0x69 and 0x6a..0x6c into a compare
 * tree (0x69 alone, then range test 0x6a..0x6c linear); mine emits a second jump table
 * for 0x69..0x6c. Everything above the 0x68 split is identical.
 *
 * blocker:  the 0x69..0x6c dispatch.  The image builds a compare tree (0x69 a
 *           lone node, 0x6a..0x6c a linear chain) where 1.1p1 builds a second
 *           pc-relative table for the four dense values; the function is 200 B
 *           against 216 and 75 concrete bytes differ, all downstream of the
 *           dispatch.  w7: re-measured; moving case 105 into its own block,
 *           after 108, around case 104, splitting 105 from 106-108 and
 *           reversing the label order all still table 0x69..0x6c, so the
 *           run-length heuristic cannot be moved from the source.
 */

extern void func_02059F54(int error, int errorCode);

int func_021DF65C(int result)
{
	int dwcError = 20;
	int errorCode = -43000;
	if (result == 0)
		return 0;
	switch (result) {
	case 2: case 3: case 4: case 5: case 6: case 7:
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
