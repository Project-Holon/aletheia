/*
 * function: DWCi_GetReverseBuddiesCallback
 * address:  0x0216A020
 * packet:   pkt_ov009_0216A020
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GetReverseBuddiesCallback (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   DWCi_IsServerUpdating  0x02168D7C  arm  ov009
 *   DWC_Free       0x0205A1B0  arm
 *   DWCi_EndUpdateServers  0x02169568  arm  ov009
 *   DWCi_Acc_GetFlagDataTypeThunk  0x020591CC  arm
 *   DWCi_GetUserData  0x0216A39C  arm  ov009
 *   DWC_GetGsProfileId  0x020598EC  arm
 *   func_02059194  0x02059194  arm
 *   DWCi_SetReverseBuddyFlag  0x02059240  arm
 *   DWC_IsBuddyFriendData  0x0205912C  arm
 *   DWCi_SetExpIsBuddyFriendFlag  0x02059270  arm
 *   g_021AA860     0x021AA860  data
 *
 * The DWARF has the response argument alone; the object receives it in r1, so the
 * callback takes the connection first.
 */

#include "../include/G_FriendGlobal.h"

typedef unsigned char u8;

typedef struct GPUniqueMatch {
    int profile;
    u8 rest[0x18];
} GPUniqueMatch;

typedef struct GPGetReverseBuddiesListResponseArg {
    int result;
    int numOfUniqueMatchs;
    GPUniqueMatch *matches;
} GPGetReverseBuddiesListResponseArg;

typedef struct FriendData {
    u8 raw[12];
} FriendData;

typedef struct MatchCnt {
    u8 pad0[0x14];
    int friendListLen;              /* +0x14 */
    FriendData *friendList;         /* +0x18 */
    u8 pad1[1];
    u8 reverseChanged;              /* +0x1D */
} MatchCnt;

extern struct FriendGlobal g_021AA860;

extern int DWCi_IsServerUpdating(void);
extern void DWC_Free(int name, void *ptr, unsigned long size);
extern void DWCi_EndUpdateServers(void);
extern int DWCi_Acc_GetFlagDataTypeThunk();
extern int DWCi_GetUserData(void);
struct DWCstAccUserData;
extern int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata);
extern int func_02059194(FriendData *frienddata);
extern void DWCi_SetReverseBuddyFlag(void *frienddata, int setflag);
extern int DWC_IsBuddyFriendData(FriendData *frienddata);
extern void DWCi_SetExpIsBuddyFriendFlag(void *frienddata, int setflag);

#define CNT (*(MatchCnt **)(((unsigned char *)&g_021AA860) + 0xC))
#define PTR5C (*(void **)((u8 *)CNT + 0x5C))

void DWCi_GetReverseBuddiesCallback(void *connection, GPGetReverseBuddiesListResponseArg *arg)
{
    int i;
    int j;

    if (!DWCi_IsServerUpdating())
        return;
    if (PTR5C != 0) {
        DWC_Free(4, PTR5C, 0);
        PTR5C = 0;
    }
    if (arg->result != 0) {
        DWCi_EndUpdateServers();
        return;
    }
    for (i = 0; i < CNT->friendListLen; i++) {
        if (DWCi_Acc_GetFlagDataTypeThunk(&CNT->friendList[i]) == 3) {
            for (j = 0; j < arg->numOfUniqueMatchs; j++) {
                if (arg->matches[j].profile == DWC_GetGsProfileId((struct DWCstAccUserData *)DWCi_GetUserData(), &CNT->friendList[i])) {
                    if (!func_02059194(&CNT->friendList[i])) {
                        CNT->reverseChanged = 1;
                        DWCi_SetReverseBuddyFlag(&CNT->friendList[i], 1);
                        if (DWC_IsBuddyFriendData(&CNT->friendList[i]))
                            DWCi_SetExpIsBuddyFriendFlag(&CNT->friendList[i], 1);
                    }
                    break;
                }
            }
            if (j == arg->numOfUniqueMatchs && func_02059194(&CNT->friendList[i]) == 1) {
                CNT->reverseChanged = 1;
                DWCi_SetReverseBuddyFlag(&CNT->friendList[i], 0);
            }
            if (DWC_IsBuddyFriendData(&CNT->friendList[i]))
                DWCi_SetExpIsBuddyFriendFlag(&CNT->friendList[i], 1);
        }
    }
    DWCi_EndUpdateServers();
}
