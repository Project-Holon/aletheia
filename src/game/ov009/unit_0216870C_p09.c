/*
 * file:     unit_0216870C_p09.c
 * unit:     yes
 * function: func_02169E18, func_02169FE4
 * address:  0x02169E18
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020591CC  0x020591CC  arm
 *   func_0216A39C  0x0216A39C  arm  ov009
 *   func_02059A44  0x02059A44  arm
 *   func_020948E0  0x020948E0  arm
 *   func_020598EC  0x020598EC  arm
 *   func_0205915C  0x0205915C  arm
 *   func_02059A10  0x02059A10  arm
 *   func_02059214  0x02059214  arm
 *   func_021696B0  0x021696B0  arm  ov009
 *   func_02059240  0x02059240  arm
 *   func_0205912C  0x0205912C  arm
 *   func_02059270  0x02059270  arm
 *   func_02169174  0x02169174  arm  ov009
 *   g_021AA860  0x021AA860  data
 */
#include "../../matched/include/G_FriendGlobal.h"

struct DWCstAccUserData;
typedef struct {
    unsigned char data[12];
} DWCFriendData;

typedef struct {
    char pad0[0x14];
    int friendListLen;
    DWCFriendData *friendList;
    unsigned char pad1c;
    unsigned char buddyUpdated;
} DWCFriendControl;

typedef struct {
    int result;
    int profile;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char firstname[31];
    char lastname[31];
} GPGetInfoResponseArg;

typedef unsigned char  u8;

extern int func_020591CC(DWCFriendData *frienddata);
extern int func_0216A39C(void);
extern void func_02059A44(void *userdata, DWCFriendData *frienddata, char *username);
extern int func_020948E0(const char *a, const char *b);
extern int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata);
extern int func_0205915C(DWCFriendData *frienddata);
extern void func_02059A10(void *frienddata, int gs_profile_id);
extern void func_02059214(DWCFriendData *frienddata);
extern int func_021696B0(u8 *friendList, int friendListLen, int profileID);
extern void func_02059240(void *frienddata, int setflag);
extern int func_0205912C(DWCFriendData *frienddata);
extern void func_02059270(void *frienddata, int setflag);
extern void func_02169174(int index);
void func_02169E18(void *connection, GPGetInfoResponseArg *arg);
int func_02169FE4(void);
extern struct FriendGlobal g_021AA860;


/*
 * sdk:      DWCi_GPGetInfoCallback_RecvAuthMessage (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * The object reads arg from r1 (GP callback: connection, arg, param); the DWARF
 * prototype lists only arg.
 */
void func_02169E18(void *connection, GPGetInfoResponseArg *arg)
{
    char userName[21];
    int index;
    int i;
    int listChanged = 0;
    int alreadyBuddy = 0;

    if (arg->result != 0)
        return;
    for (i = 0; i < ((DWCFriendControl *)g_021AA860.ctl)->friendListLen; i++) {
        if (func_020591CC(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 1) {
            func_02059A44((void *)func_0216A39C(), &((DWCFriendControl *)g_021AA860.ctl)->friendList[i], userName);
            if (func_020948E0(userName, arg->lastname) == 0) {
                func_02059A10(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i], arg->profile);
                func_02059214(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]);
                listChanged = 1;
            }
        } else if (func_020591CC(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 3
                   || func_020591CC(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 2) {
            if (func_020598EC((struct DWCstAccUserData *)func_0216A39C(), &((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == arg->profile) {
                if (func_0205915C(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 1)
                    alreadyBuddy = 1;
                else {
                    func_02059A10(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i], arg->profile);
                    func_02059214(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]);
                    listChanged = 1;
                }
            }
        }
    }
    if (!listChanged)
        return;
    index = func_021696B0((u8 *)((DWCFriendControl *)g_021AA860.ctl)->friendList, ((DWCFriendControl *)g_021AA860.ctl)->friendListLen, arg->profile);
    if (!alreadyBuddy) {
        func_02059240(&((DWCFriendControl *)g_021AA860.ctl)->friendList[index], 1);
        if (func_0205912C(&((DWCFriendControl *)g_021AA860.ctl)->friendList[index]))
            func_02059270(&((DWCFriendControl *)g_021AA860.ctl)->friendList[index], 1);
        func_02169174(index);
    }
    ((DWCFriendControl *)g_021AA860.ctl)->buddyUpdated = 1;
}


/*
 * The word at +0x20 of the block held at +0xc of the module state block.
 */
int func_02169FE4(void)
{
    int blk = *(int *)(((char *)&g_021AA860) + 0xc);

    return *(int *)(blk + 0x20);
}
