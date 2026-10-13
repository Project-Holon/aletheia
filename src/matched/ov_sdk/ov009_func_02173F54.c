/*
 * function: DWCi_HandleNNResult
 * address:  0x02173F54
 * packet:   pkt_ov009_02173F54
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleNNResult (dwc_match.o)
 *
 * symbols:
 *   DWCi_StopMatch  0x0216EB68  arm  ov009
 */

extern void DWCi_StopMatch(int error, int code);

enum E { E_OK, E_A, E_B, E_C, E_D, E_E, E_NET };

int DWCi_HandleNNResult(int result)
{
    enum E dwcError;

    if (result == 0)
        return 0;
    switch (result) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        dwcError = E_NET;
        break;
    }
    if (dwcError != E_OK)
        DWCi_StopMatch(dwcError, -86009);
    return result;
}
