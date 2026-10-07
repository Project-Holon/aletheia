/*
 * function: func_021696B0
 * address:  0x021696B0
 * packet:   pkt_ov009_021696B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RefreshFriendListAll (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   func_02168FF0  0x02168FF0  arm  ov009
 *   func_020591CC  0x020591CC  arm
 *   func_02059A10  0x02059A10  arm
 *   func_0205915C  0x0205915C  arm
 *   func_02059214  0x02059214  arm
 *   func_0205912C  0x0205912C  arm
 *   func_02059270  0x02059270  arm
 *   func_0216959C  0x0216959C  arm  ov009
 *   g_021AA860     0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

typedef unsigned char u8;

struct Work {
    char pad0[0x18];
    u8 *friendList;
    char pad1c;
    u8 flag;
};
extern struct FriendGlobal g_021AA860;

extern int func_02168FF0(int index);
extern int func_020591CC(void *friendData);
extern void func_02059A10(void *friendData, int pid);
extern int func_0205915C(void *friendData);
extern void func_02059214(void *friendData);
extern int func_0205912C(void *friendData);
extern void func_02059270(void *friendData, int flag);
extern void func_0216959C(void *friendList, int deleteIndex, int otherIndex);

int func_021696B0(u8 *friendList, int friendListLen, int profileID)
{
    int index = -1;
    int pid_i;
    int i;
    int j;

    for (i = 0; i < friendListLen; i++) {
        pid_i = func_02168FF0(i);
        if (pid_i == 0)
            continue;
        if (pid_i == profileID)
            index = i;
        for (j = i + 1; j < friendListLen; j++) {
            if (pid_i != func_02168FF0(j))
                continue;
            if (func_020591CC(friendList + i * 12) == 2 && func_020591CC(friendList + j * 12) == 3)
                func_02059A10(friendList + i * 12, pid_i);
            if (func_0205915C(friendList + j * 12)) {
                func_02059214(friendList + i * 12);
                if (func_0205912C(g_021AA860.ctl->friendList + i * 12))
                    func_02059270(g_021AA860.ctl->friendList + i * 12, 1);
            }
            func_0216959C(friendList, j, i);
            g_021AA860.ctl->flag = 1;
        }
    }
    return index;
}
