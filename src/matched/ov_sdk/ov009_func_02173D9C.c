/*
 * function: func_02173D9C
 * address:  0x02173D9C
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_HandleSBError: maps a server browsing error to a DWC error and stops the match.
 *
 * symbols:
 *   func_0216EB68  0x0216EB68  arm  ov009
 */

extern void func_0216EB68(int error, int errorCode);

int func_02173D9C(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 6;
        errorCode = -50;
        break;
    case 2:
        dwcError = 6;
        errorCode = -30;
        break;
    case 3:
        dwcError = 6;
        errorCode = -20;
        break;
    case 4:
        dwcError = 6;
        errorCode = -40;
        break;
    case 5:
        dwcError = 9;
        errorCode = -1;
        break;
    case 6:
        dwcError = 9;
        errorCode = -2;
        break;
    }
    func_0216EB68(dwcError, errorCode + -85000);
    return error;
}
