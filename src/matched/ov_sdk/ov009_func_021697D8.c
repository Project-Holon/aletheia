/*
 * function: DWCi_GPSendBuddyRequest
 * address:  0x021697D8
 * packet:   pkt_ov009_021697D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPSendBuddyRequest (dwc_friend.o)
 *
 * symbols:
 *   g_021AA860   0x021AA860  data
 *   gDwcFriendGetInfoFlags   0x021A200C  data
 *   func_02185D04  0x02185D04  arm
 *   DWCi_HandleGPError  0x021698C0  arm
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;
extern char gDwcFriendGetInfoFlags[];
extern int func_02185D04(void **connection, int profile, char *reason);
extern int DWCi_HandleGPError(int result);

int DWCi_GPSendBuddyRequest(int profileID)
{
    int gpResult;

    gpResult = func_02185D04(*(void ***)(*(char **)(((char *)&g_021AA860) + 0xc) + 4), profileID, gDwcFriendGetInfoFlags);
    DWCi_HandleGPError(gpResult);
    return gpResult;
}
