/*
 * function: DWCi_HandleGPError
 * address:  0x021698C0
 * packet:   pkt_ov009_021698C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleGPError (dwc_friend.o)
 *
 * symbols:
 *   DWCi_StopFriendProcess  0x02168E50  arm
 */

extern void DWCi_StopFriendProcess(int error, int errorCode);

static int DWCi_HandleGPError(int result)
{
    int dwcError;
    int errorCode;

    if (result == 0) return 0;
    switch (result) {
    case 1: dwcError = 9; errorCode = -1; break;
    case 2: dwcError = 9; errorCode = -2; break;
    case 3: dwcError = 6; errorCode = -10; break;
    case 4: dwcError = 6; errorCode = -20; break;
    }
    DWCi_StopFriendProcess(dwcError, errorCode + (int)0xfffeeaa8);
    return result;
}
