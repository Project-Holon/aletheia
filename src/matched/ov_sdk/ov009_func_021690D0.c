/*
 * function: DWCi_SetGPStatus
 * address:  0x021690D0
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_SetGPStatus: sets the GP status, defaulting each unset argument to the current one.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 *   DWCi_CheckLogin  0x0216AA70  arm  ov009
 *   func_0218627C  0x0218627C  arm  ov009
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;
extern int DWCi_CheckLogin(void);
extern int func_0218627C(void **connection, int status, const char *statusString, const char *locationString);

int DWCi_SetGPStatus(int status, const char *statusString, const char *locString)
{
    if (*(char **)(((char *)&g_021AA860) + 0xc) == 0 || DWCi_CheckLogin() == 0) {
        return 0;
    }
    if (status == -1) {
        status = *(int *)(**(char ***)(*(char **)(((char *)&g_021AA860) + 0xc) + 4) + 0x23c);
    }
    if (statusString == 0) {
        statusString = **(char ***)(*(char **)(((char *)&g_021AA860) + 0xc) + 4) + 0x3b8;
    }
    if (locString == 0) {
        locString = **(char ***)(*(char **)(((char *)&g_021AA860) + 0xc) + 4) + 0x4b8;
    }
    return func_0218627C(*(void **)(*(char **)(((char *)&g_021AA860) + 0xc) + 4), status, statusString, locString);
}
