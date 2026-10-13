/*
 * function: DWCi_HandleNNError
 * address:  0x02173EF8
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_HandleNNError: maps a NAT negotiation error to a DWC error and stops the match.
 *
 * symbols:
 *   DWCi_StopMatch  0x0216EB68  arm  ov009
 */

extern void DWCi_StopMatch(int error, int errorCode);

int DWCi_HandleNNError(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 9;
        errorCode = -1;
        break;
    case 2:
        dwcError = 6;
        errorCode = -50;
        break;
    case 3:
        dwcError = 6;
        errorCode = -30;
        break;
    }
    DWCi_StopMatch(dwcError, errorCode + -86000);
    return error;
}
