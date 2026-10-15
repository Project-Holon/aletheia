/*
 * function: DWCi_HandleGPError
 * address:  0x0216BD04
 * packet:   pkt_ov009_0216BD04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleGPError (dwc_main.o)
 *
 * Extra open callee of DWCi_GPErrorCallback (0x0216C08C).
 *
 * symbols:
 *   DWCi_StopLogin  0x0216A3B8  arm  ov009
 *   DWCi_StopMatch  0x0216EB68  arm  ov009
 *   DWCi_StopFriendProcess  0x02168E50  arm  ov009
 *   gDwcGlobalState     0x021AA878  data
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal gDwcGlobalState;
extern void DWCi_StopLogin(int error, int errorCode);
extern void DWCi_StopMatch(int error, int errorCode);
extern void DWCi_StopFriendProcess(int error, int errorCode);

static int DWCi_HandleGPError(int result)
{
    int errorCode;
    int dwcError;

    if (result == 0) return 0;
    switch (result) {
    case 1: dwcError = 9; errorCode = -1; break;
    case 2: dwcError = 9; errorCode = -2; break;
    case 3: dwcError = 6; errorCode = -10; break;
    case 4: dwcError = 6; errorCode = -20; break;
    }
    switch (*(int *)(*(char **)(((char *)&gDwcGlobalState) + 4) + 0x24)) {
    case 1:
        errorCode += (int)0xffff11b8;
        DWCi_StopLogin(dwcError, errorCode);
        break;
    case 2:
        errorCode += (int)0xffff11b8;
        if (*(int *)(*(char **)(((char *)&gDwcGlobalState) + 4) + 0x94) < 1)
            DWCi_StopLogin(dwcError, errorCode);
        break;
    case 4:
        errorCode += (int)0xfffec398;
        DWCi_StopMatch(dwcError, errorCode);
        break;
    default:
        errorCode += (int)0xfffe9c88;
        break;
    }
    DWCi_StopFriendProcess(dwcError, errorCode);
    return result;
}
