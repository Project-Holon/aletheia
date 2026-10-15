/*
 * function: DWCi_HandleQR2Error
 * address:  0x02173E30
 * packet:   pkt_ov009_02173E30
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleQR2Error (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWC_GetState  0x0216B994  arm  ov009
 *   DWCi_StopLogin  0x0216A3B8  arm  ov009
 *   DWCi_StopMatch  0x0216EB68  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
 */

extern int DWC_GetState(void);
extern void DWCi_StopLogin(int dwcError, int errorCode);
extern void DWCi_StopMatch(int dwcError, int errorCode);
extern void DWCi_SetError(int dwcError, int errorCode);

int DWCi_HandleQR2Error(int error)
{
    int errorCode;
    int dwcError;

    if (error == 0)
        return 0;
    switch (error) {
    case 1:
        dwcError = 6;
        errorCode = -50;
        break;
    case 2:
        dwcError = 6;
        errorCode = -60;
        break;
    case 3:
        dwcError = 6;
        errorCode = -30;
        break;
    case 4:
        dwcError = 6;
        errorCode = -80;
        break;
    case 5:
        dwcError = 6;
        errorCode = -20;
        break;
    }
    switch (DWC_GetState()) {
    case 2:
        DWCi_StopLogin(dwcError, errorCode - 64000);
        break;
    case 4:
        DWCi_StopMatch(dwcError, errorCode - 84000);
        break;
    default:
        DWCi_SetError(dwcError, errorCode - 94000);
        break;
    }
    return error;
}
