/*
 * file:     unit_0216870C_p04.c
 * unit:     yes
 * function: func_02168DA4, func_02168E50, func_02168ECC, func_02168F18, func_02168F4C, func_02168FF0, func_02169038, func_0216909C, func_021690D0
 * address:  0x02168DA4
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
 *   g_021AA860  0x021AA860  data
 *   func_02059F54  0x02059F54  arm
 *   func_02168D7C  0x02168D7C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_02169294  0x02169294  arm
 *   func_02185BD8  0x02185BD8  arm
 *   func_02169BB0  0x02169BB0  arm
 *   func_02169E18  0x02169E18  arm
 *   func_021861A8  0x021861A8  arm  ov009
 *   func_02186220  0x02186220  arm  ov009
 *   func_02185FD4  0x02185FD4  arm  ov009
 *   func_0216A39C  0x0216A39C  arm  ov009
 *   DWC_GetGsProfileId  0x020598EC  arm
 *   func_020870D0  0x020870D0  arm
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   func_0218627C  0x0218627C  arm  ov009
 */
#include "../../matched/include/G_FriendGlobal.h"

struct GPBuddyStatus;
typedef struct FriendCtl {
	unsigned char pad0[0x34];
	void (*statusCallback)(int, unsigned char, char *, void *);
	void *statusParam;
} FriendCtl;

typedef struct FriendGlobal FriendGlobal;

typedef struct BuddyStatus {
	int profile;
	int status;
	char statusString[256];
	char locationString[256];
	unsigned char pad[0xc];
} BuddyStatus;

typedef struct RecvArg {
	int profile;
	unsigned char pad[4];
	int index;
} RecvArg;

extern void func_02059F54(int error, int errorCode);
extern int func_02168D7C(void);
extern void func_0205A1B0(int name, void *ptr, int flag);
extern void func_02169294(void);
extern int func_02185BD8(void **connection, int profile, int checkCache, int blocking,
                         void (*callback)(void **, void *, void *), void *param);
extern void func_02169BB0(void **connection, void *arg);
extern void func_02169E18(void *arg);
extern int func_021861A8(void **connection, int profile);
extern int func_02186220(void **connection, int profile);
extern int func_02185FD4(void **connection, int index, struct GPBuddyStatus *status);
extern int func_0216A39C(void);
extern int DWC_GetGsProfileId(void *user, void *data);
extern unsigned long long func_020870D0(void);
extern int func_0216AA70(void);
extern int func_0218627C(void **connection, int status, const char *statusString, const char *locationString);
void func_02168DA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void func_02168E50(int error, int errorCode);
void func_02168ECC(void **connection, int *arg);
int func_02168F18(void **connection, int *arg);
void func_02168F4C(void **connection, RecvArg *arg);
int func_02168FF0(int index);
int func_02169038(int pid);
void func_0216909C(void);
int func_021690D0(int status, const char *statusString, const char *locString);
extern struct FriendGlobal g_021AA860;


/*
 * Fill the descriptor hanging off the global at 0x021AA860 (+0x0c): six
 * arguments land at +0x2c..+0x40, four status bytes are cleared, the state
 * word is set to 1, and the +0x1f counter is bumped twice -- once only when
 * the +0x18 word is zero.
 */
void func_02168DA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x2c) = a2;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x30) = a3;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x34) = a4;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x38) = a5;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x3c) = a6;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x40) = a7;
    *(char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1d) = 0;
    *(char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1e) = 0;
    *(char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1f) = 0;
    *(char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1c) = 0;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x00) = 1;

    if (*(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x18) == 0)
        *(unsigned char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1f) += 1;

    *(unsigned char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1f) += 1;
}


/*
 * sdk:      DWCi_StopFriendProcess (dwc_friend.o)
 */
void func_02168E50(int error, int errorCode)
{
    if (*(char **)(((char *)&g_021AA860) + 0xc) == 0 || error == 0) return;
    func_02059F54(error, errorCode);
    if (func_02168D7C() != 0) {
        if (*(void **)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x5c) != 0) {
            func_0205A1B0(4, *(void **)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x5c), 0);
            *(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x5c) = 0;
        }
        (*(void (*)(int, unsigned char, int))(*(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x2c)))(
            error,
            *(unsigned char *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x1d),
            *(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x30));
    }
    func_02169294();
}


/*
 * sdk:      DWCi_GPRecvBuddyRequestCallback (dwc_friend.o)
 */
void func_02168ECC(void **connection, int *arg)
{
    if (*(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x18) == 0) return;
    func_02185BD8(connection, *arg, 0, 0, (void (*)(void **, void *, void *))func_02169BB0, 0);
}


/*
 * sdk:      DWCi_GPRecvBuddyAuthCallback (dwc_friend.o)
 */
int func_02168F18(void **connection, int *arg)
{
    func_02185BD8(connection, *arg, 0, 0, (void (*)(void **, void *, void *))func_02169E18, 0);
    return 1;
}


/*
 * sdk:      DWCi_GPRecvBuddyStatusCallback (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
void func_02168F4C(void **connection, RecvArg *arg)
{
	BuddyStatus status;
	int friendIdx;

	friendIdx = func_02169038(arg->profile);
	if (friendIdx == -1) {
		if (func_021861A8(connection, arg->profile))
			func_02186220(connection, arg->profile);
		return;
	}
	if (((FriendCtl *)g_021AA860.ctl)->statusCallback == 0)
		return;
	func_02185FD4(connection, arg->index, (struct GPBuddyStatus *)(&status));
	((FriendCtl *)g_021AA860.ctl)->statusCallback(friendIdx, status.status, status.locationString, ((FriendCtl *)g_021AA860.ctl)->statusParam);
}


/*
 * DWCi_GetProfileIDFromList: the profile id of a friend list entry, zero when unset or invalid.
 */
int func_02168FF0(int index)
{
    char *list = *(char **)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x18);
    int pid;

    if (list == 0) {
        return 0;
    }
    pid = DWC_GetGsProfileId((void *)func_0216A39C(), list + index * 0xc);
    if (pid != 0 && pid != -1) {
        return pid;
    }
    return 0;
}


/*
 * DWCi_GetFriendListIndex: the friend list index holding a profile id, or -1.
 */
int func_02169038(int pid)
{
    int i;

    if (*(char **)(((char *)&g_021AA860) + 0xc) == 0 || pid == 0) {
        return -1;
    }
    for (i = 0; i < *(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x14); i++) {
        if (pid == func_02168FF0(i)) {
            return i;
        }
    }
    return -1;
}


/*
 * sdk:      DWCi_InitGPProcessCount (dwc_friend.o)
 */
void func_0216909C(void)
{
    char *p = *(char **)(((char *)&g_021AA860) + 0xc);

    if (p == 0) return;
    *(int *)(p + 8) = 0;
    *(unsigned long long *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0xc) = func_020870D0();
}


int func_021690D0(int status, const char *statusString, const char *locString)
{
    if (*(char **)(((char *)&g_021AA860) + 0xc) == 0 || func_0216AA70() == 0) {
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
