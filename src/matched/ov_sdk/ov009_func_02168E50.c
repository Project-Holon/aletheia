/*
 * function: DWCi_StopFriendProcess
 * address:  0x02168E50
 * packet:   pkt_ov009_02168E50
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_StopFriendProcess (dwc_friend.o)
 *
 * symbols:
 *   g_021AA860    0x021AA860  data
 *   func_02059F54  0x02059F54  arm
 *   DWCi_IsServerUpdating  0x02168D7C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   DWCi_CloseFriendProcess  0x02169294  arm
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;
extern void func_02059F54(int error, int errorCode);
extern int DWCi_IsServerUpdating(void);
extern void func_0205A1B0(int name, void *ptr, int flag);
extern void DWCi_CloseFriendProcess(void);

void DWCi_StopFriendProcess(int error, int errorCode)
{
    if (*(char **)(((char *)&g_021AA860) + 0xc) == 0 || error == 0) return;
    func_02059F54(error, errorCode);
    if (DWCi_IsServerUpdating() != 0) {
        if (*(void **)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x5c) != 0) {
            func_0205A1B0(4, *(void **)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x5c), 0);
            *(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x5c) = 0;
        }
        (*(void (*)(int, unsigned char, int))(*(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x2c)))(
            error,
            *(unsigned char *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x1d),
            *(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x30));
    }
    DWCi_CloseFriendProcess();
}
