/*
 * function: func_02173FB4
 * address:  0x02173FB4
 * packet:   pkt_ov009_02173FB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleGT2Error (dwc_match.o)
 *
 * symbols:
 *   DWCi_StopMatch  0x0216EB68  arm  ov009
 */

extern void DWCi_StopMatch(int error, int code);

int func_02173FB4(int result)
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
    case 5:
        dwcError = 0;
        errorCode = 0;
        result = 0;
        break;
    case 3:
        dwcError = 6;
        errorCode = -10;
        break;
    case 4:
        dwcError = 6;
        errorCode = -30;
        break;
    case 6:
        dwcError = 6;
        errorCode = -70;
        break;
    case 7:
        dwcError = 6;
        errorCode = -80;
        break;
    }
    if (dwcError != 0)
        DWCi_StopMatch(dwcError, errorCode + -87000);
    return result;
}
