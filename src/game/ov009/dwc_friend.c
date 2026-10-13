/*
 * file:     dwc_friend.c
 * unit:     yes
 * function: func_0216870C, func_02168724, func_02168848, func_02168864, func_021688FC, func_02168994, func_021689BC, func_02168AD4, func_02168D7C, func_02168DA4, func_02168E50, func_02168ECC, func_02168F18, func_02168F4C, func_02168FF0, func_02169038, func_0216909C, func_021690D0, func_02169174, func_021691FC, func_02169210, func_02169294, func_021692C4, func_02169568, func_0216959C, func_021695F0, func_021696B0, func_021697D8, func_0216980C, func_021698C0, DWCi_GPProfileSearchCallback, DWCi_GPGetInfoCallback_RecvBuddyRequest, func_02169E18, func_02169FE4, func_02169FF8, func_0216A00C, func_0216A020
 * address:  0x0216870C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0216980C  0x0216980C  arm  ov009
 *   func_021684CC  0x021684CC  arm  ov009
 *   strtoul        0x02095EAC  arm
 *   strcpy         0x02094798  arm
 *   func_02176984  0x02176984  arm  ov009
 *   g_021A2004     0x021A2004  data
 *   g_021A2008     0x021A2008  data
 *   func_0209477C  0x0209477C  arm
 *   func_02059CBC  0x02059CBC  arm
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   func_02059B40  0x02059B40  arm
 *   func_021690D0  0x021690D0  arm  ov009
 *   func_020592A0  0x020592A0  arm
 *   DWCi_IsError                    0x02059F38 arm
 *   IsStatsConnected                0x02193D64 arm ov009
 *   PersistThink                    0x02193D80 arm ov009
 *   CloseStatsConnection            0x02193D00 arm ov009
 *   DWC_GetFriendDataType           0x020591CC arm
 *   DWC_Alloc                       0x0205A16C arm
 *   DWCi_GetUserData                0x0216A39C arm ov009
 *   DWC_GetGsProfileId              0x020598EC arm
 *   gpGetReversBuddiesList          0x02186564 arm ov009
 *   s_bNeedCloseStatsConnection     0x021AA860 data
 *   func_02059F54  0x02059F54  arm
 *   func_02168D7C  0x02168D7C  arm
 *   func_02169294  0x02169294  arm
 *   func_02185BD8  0x02185BD8  arm
 *   func_02169E18  0x02169E18  arm
 *   func_021861A8  0x021861A8  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   func_0218627C  0x0218627C  arm  ov009
 *   func_0216870C  0x0216870C  arm  ov009
 *   func_02185948  0x02185948  arm  ov009
 *   gpGetNumBuddies                  0x02185fa4 arm
 *   gpGetBuddyStatus                 0x02185fd4 arm
 *   DWCi_IsBuddyFriendData           0x0205915c arm
 *   DWC_SetGsProfileId               0x02059a10 arm
 *   DWCi_SetBuddyFriendData          0x02059214 arm
 *   DWC_IsBuddyFriendData            0x0205912c arm
 *   DWCi_SetExpIsBuddyFriendFlag     0x02059270 arm
 *   gpDeleteBuddy                    0x02186220 arm
 *   DWCi_IsBuddyMsgAlreadySent       0x020591b0 arm
 *   gpGetBuddyIndex                  0x02186108 arm
 *   DWCi_SetSentBuddyReqFlag         0x020592a0 arm
 *   DWC_LoginIdToUserName            0x02059a44 arm
 *   gpProfileSearchA                 0x02185b10 arm
 *   DWCi_GPProfileSearchCallback     0x02169934 arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02168FF0  0x02168FF0  arm  ov009
 *   func_0216959C  0x0216959C  arm  ov009
 *   g_021A200C   0x021A200C  data
 *   func_02185D04  0x02185D04  arm
 *   func_02168E50  0x02168E50  arm
 *   DWCi_SetReverseBuddyFlag         0x02059240 arm
 *   strcmp                           0x020948E0 arm
 *   gpAuthBuddyRequest               0x02185E94 arm ov009
 *   OS_SNPrintf                      0x02084F80 arm
 *   memcmp                           0x020923F0 arm
 *   gpDenyBuddyRequest               0x02185EE4 arm ov009
 *   g_021A2010                       0x021A2010 data
 *   func_021696B0  0x021696B0  arm  ov009
 *   func_02169174  0x02169174  arm  ov009
 *   DWC_Free       0x0205A1B0  arm
 *   func_02169568  0x02169568  arm  ov009
 *   func_02059194  0x02059194  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef unsigned long long u64;

typedef struct {
    int profile;
    int status;
    char statusString[256];
    char locationString[256];
    unsigned int ip;
    int port;
    int quietModeFlags;
} GPBuddyStatus;

typedef struct DWCstAccFriendData {
    char data[0xc];
} DWCstAccFriendData;

typedef struct DWCstAccUserData {
    char pad[0x24];
    unsigned int gamecode;
} DWCstAccUserData;

/* the GP connection object behind a `void **` handle */
typedef struct GPConnObj {
    char pad0[0x23c];
    int status;
    char pad240[0x3b8 - 0x240];
    char statusString[256];
    char locationString[256];
} GPConnObj;

typedef void (*GPCallback)(void **connection, void *arg, void *param);

/* the friend control block that stpFriendCnt points to (0x60 bytes) */
typedef struct FriendCnt {
    int state;                                              /* 0x00 */
    void **connection;                                      /* 0x04 */
    unsigned int pollCount;                                 /* 0x08 */
    u64 lastTick;                                           /* 0x0c */
    int friendListLen;                                      /* 0x14 */
    DWCstAccFriendData *friendList;                         /* 0x18 */
    u8 sendIdx;                                             /* 0x1c */
    u8 changed;                                             /* 0x1d */
    u8 phase;                                               /* 0x1e */
    u8 stage;                                               /* 0x1f */
    int fld20;                                              /* 0x20 */
    int fld24;                                              /* 0x24 */
    int fld28;                                              /* 0x28 */
    void (*finishCb)(int, u8, int);                         /* 0x2c */
    int finishParam;                                        /* 0x30 */
    void (*statusCb)(int, u8, char *, void *);              /* 0x34 */
    void *statusParam;                                      /* 0x38 */
    void (*deleteCb)(int, int, int);                        /* 0x3c */
    int deleteParam;                                        /* 0x40 */
    void (*buddyCb)(int, void *);                           /* 0x44 */
    void *buddyParam;                                       /* 0x48 */
    int fld4c;                                              /* 0x4c */
    int fld50;                                              /* 0x50 */
    int fld54;                                              /* 0x54 */
    int fld58;                                              /* 0x58 */
    int *reversePids;                                       /* 0x5c */
} FriendCnt;

typedef struct GPProfileSearchMatch {
    int profileID;
    char pad[0xb0 - 4];
} GPProfileSearchMatch;

typedef struct GPProfileSearchResponseArg {
    int result;
    int numMatches;
    int more;
    GPProfileSearchMatch *matches;
} GPProfileSearchResponseArg;

typedef struct GPGetInfoResponseArg_02169BB0 {
    int field0;
    int field4;
    char pad8[0x8e - 8];
    char userName[9];
    char gamecode[4];
} GPGetInfoResponseArg_02169BB0;

typedef struct {
    int result;
    int profile;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char firstname[31];
    char lastname[31];
} GPGetInfoResponseArg_0216870C;

typedef struct GPUniqueMatch {
    int profile;
    u8 rest[0x18];
} GPUniqueMatch;

typedef struct GPGetReverseBuddiesListResponseArg {
    int result;
    int numOfUniqueMatchs;
    GPUniqueMatch *matches;
} GPGetReverseBuddiesListResponseArg;

typedef struct RecvArg {
    int profile;
    unsigned char pad[4];
    int index;
} RecvArg;

extern int func_021684CC(char *key, char *value, char *string, char separator);
extern unsigned long strtoul(const char *s, char **end, int base);
extern int func_02176984(GPBuddyStatus *status);
extern int func_0209477C(const u8 *s);
extern int func_02059CBC(const char *src, u32 srclen, char *dst, u32 dstlen);
extern int func_0216AA70(void);
extern int func_02059B40(const char *src, u32 srclen, char *dst, u32 dstlen);
extern char g_021A2004[];
extern char g_021A2008[];
extern char g_021A200C[];
extern char g_021A2010[];
extern void func_020592A0(void *frienddata, int setflag);
extern int DWCi_IsError(void);
extern int IsStatsConnected(void);
extern int PersistThink(void);
extern void CloseStatsConnection(void);
extern int DWC_GetFriendDataType(DWCstAccFriendData *frienddata);
extern void *DWC_Alloc(int name, unsigned long size);
extern DWCstAccUserData *DWCi_GetUserData(void);
extern int DWC_GetGsProfileId(DWCstAccUserData *userdata, DWCstAccFriendData *frienddata);
extern int gpGetReversBuddiesList(void **connection, int *targets, int numOfTargets, int blocking, void (*callback)(void **, void *, void *), void *param);
extern void func_02059F54(int error, int errorCode);
extern void DWC_Free(int name, void *ptr, unsigned long size);
extern int func_02185BD8(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int func_021861A8(void **connection, int profile);
extern int gpDeleteBuddy(void **connection, int profile);
extern int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status);
extern u64 func_020870D0(void);
extern int func_0218627C(void **connection, int status, const char *statusString, const char *locationString);
extern int func_02185948(void *conn);
extern int gpGetNumBuddies(void **connection, int *numBuddies);
extern int DWCi_IsBuddyFriendData(DWCstAccFriendData *frienddata);
extern void DWC_SetGsProfileId(DWCstAccFriendData *frienddata, int gs_profile_id);
extern void DWCi_SetBuddyFriendData(DWCstAccFriendData *frienddata);
extern int DWC_IsBuddyFriendData(DWCstAccFriendData *frienddata);
extern void DWCi_SetExpIsBuddyFriendFlag(DWCstAccFriendData *frienddata, int setflag);
extern int DWCi_IsBuddyMsgAlreadySent(DWCstAccFriendData *frienddata);
extern int gpGetBuddyIndex(void **connection, int profile, int *index);
extern void DWCi_SetSentBuddyReqFlag(DWCstAccFriendData *frienddata, int setflag);
extern void DWC_LoginIdToUserName(DWCstAccUserData *userdata, DWCstAccFriendData *frienddata, char *username);
extern int gpProfileSearchA(void **connection, char *nick, char *uniquenick, char *email,
                            char *firstname, char *lastname, int icquin, int blocking,
                            void (*callback)(void **, void *, void *), void *param);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int func_02185D04(void **connection, int profile, char *reason);
extern void DWCi_SetReverseBuddyFlag(DWCstAccFriendData *frienddata, int setflag);
extern int gpAuthBuddyRequest(void **connection, int profile);
extern int gpDenyBuddyRequest(void **connection, int profile);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern int memcmp(void *p1, void *p2, unsigned long size);
extern int func_02059194(DWCstAccFriendData *frienddata);

/* dwc_friend.o local data: one .bss block at 0x021AA860 */
static FriendCnt *stpFriendCnt = 0;
static int s_bInCloseStatsConnection = 0;
static int s_bInPersistThink = 0;
static int s_bNeedCloseStatsConnection = 0;
static int s_bReverseBuddiesBusy = 0;

u8 func_0216870C(int a, int b);
u8 func_02168724(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);
unsigned char func_02168848(void *p, int a, int b);
unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
int func_021688FC(char *statusData, unsigned long size);
int func_02168994(void (*callback)(int, void *), void *param);
void func_021689BC(FriendCnt *p, int a1, int a2, int a3, int n);
void func_02168AD4(void);
int func_02168D7C(void);
void func_02168DA4(int a0, int a1, void (*a2)(int, u8, int), int a3, void (*a4)(int, u8, char *, void *), void *a5, void (*a6)(int, int, int), int a7);
void func_02168E50(int error, int errorCode);
void func_02168ECC(void **connection, int *arg);
int func_02168F18(void **connection, int *arg);
void func_02168F4C(void **connection, RecvArg *arg);
int func_02168FF0(int index);
int func_02169038(int pid);
void func_0216909C(void);
int func_021690D0(int status, const char *statusString, const char *locString);
void func_02169174(int index);
void func_021691FC(void);
int func_02169210(void);
void func_02169294(void);
void func_021692C4(DWCstAccFriendData *friendList, int friendListLen);
void func_02169568(void);
void func_0216959C(void *friendData, int deleteIndex, int otherIndex);
int func_021695F0(DWCstAccFriendData *friendList, int index, int profileID);
int func_021696B0(DWCstAccFriendData *friendList, int friendListLen, int profileID);
int func_021697D8(int profileID);
int func_0216980C(void *friendData, GPBuddyStatus *status);
int func_021698C0(int result);
void DWCi_GPProfileSearchCallback(void **connection, void *argv, void *param);
static void DWCi_GPGetInfoCallback_RecvBuddyRequest(void **connection, void *argv, void *param);
void func_02169E18(void **connection, void *argv, void *param);
int func_02169FE4(void);
void func_02169FF8(void);
void func_0216A00C(void);
void func_0216A020(void **connection, void *argv, void *param);


/*
 * Tail call with the last argument moved to the fourth slot.
 */
u8 func_0216870C(int a, int b)
{
    return func_02168724((void *)a, 0, 0, (char *)b);
}


/*
 * sdk:      DWC_GetFriendStatusSC (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
u8 func_02168724(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString)
{
    u8 state;
    GPBuddyStatus status;
    int len;
    char valueStr[4];

    if (func_0216980C(friendData, &status)) {
        if (status.status == 6) {
            if (maxEntry) {
                len = func_021684CC(g_021A2004, valueStr, status.statusString, '/');
                if (len > 0)
                    *maxEntry = strtoul(valueStr, 0, 10);
                else
                    *maxEntry = 0;
            }
            if (numEntry) {
                len = func_021684CC(g_021A2008, valueStr, status.statusString, '/');
                if (len > 0)
                    *numEntry = strtoul(valueStr, 0, 10);
                else
                    *numEntry = 0;
            }
        } else {
            if (maxEntry)
                *maxEntry = 0;
            if (numEntry)
                *numEntry = 0;
        }
        if (statusString)
            strcpy(statusString, status.locationString);
        state = status.status;
        if (func_02176984(&status))
            state = 2;
        return state;
    }
    if (maxEntry)
        *maxEntry = 0;
    if (numEntry)
        *numEntry = 0;
    return 0;
}


/*
 * Calls func_02168864 with two zeroed arguments between the tail arguments.
 */
unsigned char func_02168848(void *p, int a, int b)
{
    unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
    return func_02168864(p, 0, 0, (char *)a, (int *)b);
}


/*
 * sdk:      DWC_GetFriendStatusDataSC (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size)
{
	char statusString[256];
	unsigned char ret;
	ret = func_02168724(friendData, maxEntry, numEntry, statusString);
	if (ret == 0) {
		*size = -1;
		return ret;
	}
	*size = func_02059CBC(statusString, func_0209477C((const u8 *)statusString), 0, 0);
	if (statusData == 0 || *size == -1)
		return ret;
	func_02059CBC(statusString, func_0209477C((const u8 *)statusString), statusData, *size);
	return ret;
}


/*
 * sdk:      DWC_SetOwnStatusData (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int func_021688FC(char *statusData, unsigned long size)
{
	char statusString[256];
	int len;
	int ret;

	if (stpFriendCnt == 0 || !func_0216AA70())
		return 0;
	len = func_02059B40(statusData, size, statusString, 255);
	if (len == -1)
		return 0;
	statusString[len] = 0;
	ret = func_021690D0(-1, 0, statusString);
	if (ret == 0)
		return 1;
	return 0;
}


/*
 * sdk:      DWC_SetBuddyFriendCallback (dwc_friend.o)
 */
int func_02168994(void (*callback)(int, void *), void *param)
{
    if (stpFriendCnt == 0)
        return 0;
    stpFriendCnt->buddyCb = callback;
    stpFriendCnt->buddyParam = param;
    return 1;
}


void func_021689BC(FriendCnt *p, int a1, int a2, int a3, int n)
{
    int i;
    FriendCnt *q;

    stpFriendCnt = p;
    p->state = 0;
    stpFriendCnt->connection = (void **)a1;
    stpFriendCnt->pollCount = 0;
    q = stpFriendCnt;
    q->lastTick = 0;
    q->friendListLen = n;
    stpFriendCnt->friendList = (DWCstAccFriendData *)a3;
    stpFriendCnt->sendIdx = 0;
    stpFriendCnt->changed = 0;
    stpFriendCnt->phase = 0;
    stpFriendCnt->stage = 0;
    stpFriendCnt->fld20 = 0;
    stpFriendCnt->fld24 = 0;
    stpFriendCnt->fld28 = a2;
    stpFriendCnt->finishCb = 0;
    stpFriendCnt->finishParam = 0;
    stpFriendCnt->statusCb = 0;
    stpFriendCnt->statusParam = 0;
    stpFriendCnt->deleteCb = 0;
    stpFriendCnt->deleteParam = 0;
    stpFriendCnt->buddyCb = 0;
    stpFriendCnt->buddyParam = 0;
    stpFriendCnt->fld4c = 0;
    stpFriendCnt->fld50 = 0;
    stpFriendCnt->fld54 = 0;
    stpFriendCnt->fld58 = 0;
    stpFriendCnt->reversePids = 0;

    for (i = 0; i < n; i++)
        DWCi_SetSentBuddyReqFlag(&stpFriendCnt->friendList[i], 0);
}


/*
 * sdk:      DWCi_FriendProcess (libdwcmatch.TWL.HYB.a dwc_friend.o)
 *
 * closed (lane 09, 2026-10-01): the object's statics (s_bNeedCloseStatsConnection +0,
 *   s_bInPersistThink +4, stpFriendCnt +0xc, all local data in dwc_friend.o) are defined
 *   here as TU `static ... = 0;` so mwcc pools them on one .bss anchor; that anchor web
 *   colours first (base r4, zero r5, then i/j/pidcnt r6/r7/r8) and the stpFriendCnt
 *   reload after loop 2 comes back (680 B). An extern struct at the anchor colours i
 *   first and CSEs the reload. Declaration order sets the .bss layout (third declared
 *   lands at +0, fourth at +0xc). Locals are the DWARF set (gpResult, i, j, pidcnt);
 *   field8 is unsigned (bls).
 */
void func_02168AD4(void)
{
    int gpResult;
    int i;
    int j;
    int pidcnt;

    if (stpFriendCnt == 0)
        return;
    if (DWCi_IsError())
        return;

    if (stpFriendCnt->friendList == 0) {
        if (stpFriendCnt->connection == 0 || *stpFriendCnt->connection == 0)
            return;
        func_02169210();
        return;
    }

    if (func_02169FE4() != 0 || IsStatsConnected()) {
        s_bInPersistThink = 1;
        s_bNeedCloseStatsConnection = 0;
        PersistThink();
        s_bInPersistThink = 0;
        if (s_bNeedCloseStatsConnection == 1) {
            s_bNeedCloseStatsConnection = 0;
            CloseStatsConnection();
        }
    }

    if (stpFriendCnt->connection != 0 && *stpFriendCnt->connection != 0) {
        if (func_02169210() != 0)
            return;
        if (stpFriendCnt->state == 0)
            return;
        if (stpFriendCnt->friendList != 0 && stpFriendCnt->phase != 3 && stpFriendCnt->pollCount > 7) {
            if (stpFriendCnt->phase <= 1)
                func_021692C4(stpFriendCnt->friendList, stpFriendCnt->friendListLen);
            if (stpFriendCnt->sendIdx >= stpFriendCnt->friendListLen) {
                stpFriendCnt->phase = 3;
                stpFriendCnt->stage++;
            }
        }
    }

    if (stpFriendCnt->stage < 2)
        return;
    if (stpFriendCnt->connection == 0 || *stpFriendCnt->connection == 0)
        goto end;

    j = 0;
    pidcnt = 0;
    for (i = 0; i < stpFriendCnt->friendListLen; i++)
        if (DWC_GetFriendDataType(&stpFriendCnt->friendList[i]) == 3)
            pidcnt++;
    if (pidcnt == 0) {
        stpFriendCnt->stage = 0;
        func_02169568();
        return;
    }
    stpFriendCnt->reversePids = DWC_Alloc(4, pidcnt * 4);
    if (stpFriendCnt->reversePids == 0) {
        func_02168E50(9, (int)0xfffeee8fU);
        return;
    }
    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
        if (DWC_GetFriendDataType(&stpFriendCnt->friendList[i]) == 3) {
            stpFriendCnt->reversePids[j] = DWC_GetGsProfileId(DWCi_GetUserData(), &stpFriendCnt->friendList[i]);
            j++;
        }
    }
    gpResult = gpGetReversBuddiesList(stpFriendCnt->connection, stpFriendCnt->reversePids, pidcnt, 0, func_0216A020, 0);
    if (func_021698C0(gpResult) != 0)
        return;
end:
    stpFriendCnt->stage = 0;
}


/*
 * True when the object at +0xc of the current root exists and its first word
 * is 1.
 */
int func_02168D7C(void)
{
    int r = 0;
    FriendCnt *p = stpFriendCnt;

    if (p != 0 && p->state == 1) r = 1;
    return r;
}


/*
 * Fill the descriptor hanging off the global at 0x021AA860 (+0x0c): six
 * arguments land at +0x2c..+0x40, four status bytes are cleared, the state
 * word is set to 1, and the +0x1f counter is bumped twice -- once only when
 * the +0x18 word is zero.
 */
void func_02168DA4(int a0, int a1, void (*a2)(int, u8, int), int a3, void (*a4)(int, u8, char *, void *), void *a5, void (*a6)(int, int, int), int a7)
{
    stpFriendCnt->finishCb = a2;
    stpFriendCnt->finishParam = a3;
    stpFriendCnt->statusCb = a4;
    stpFriendCnt->statusParam = a5;
    stpFriendCnt->deleteCb = a6;
    stpFriendCnt->deleteParam = a7;
    stpFriendCnt->changed = 0;
    stpFriendCnt->phase = 0;
    stpFriendCnt->stage = 0;
    stpFriendCnt->sendIdx = 0;
    stpFriendCnt->state = 1;

    if (stpFriendCnt->friendList == 0)
        stpFriendCnt->stage += 1;

    stpFriendCnt->stage += 1;
}


/*
 * sdk:      func_02168E50 (dwc_friend.o)
 */
void func_02168E50(int error, int errorCode)
{
    if (stpFriendCnt == 0 || error == 0) return;
    func_02059F54(error, errorCode);
    if (func_02168D7C() != 0) {
        if (stpFriendCnt->reversePids != 0) {
            DWC_Free(4, stpFriendCnt->reversePids, 0);
            stpFriendCnt->reversePids = 0;
        }
        stpFriendCnt->finishCb(error, stpFriendCnt->changed, stpFriendCnt->finishParam);
    }
    func_02169294();
}


/*
 * sdk:      DWCi_GPRecvBuddyRequestCallback (dwc_friend.o)
 */
void func_02168ECC(void **connection, int *arg)
{
    if (stpFriendCnt->friendList == 0) return;
    func_02185BD8(connection, *arg, 0, 0, DWCi_GPGetInfoCallback_RecvBuddyRequest, 0);
}


/*
 * sdk:      DWCi_GPRecvBuddyAuthCallback (dwc_friend.o)
 */
int func_02168F18(void **connection, int *arg)
{
    func_02185BD8(connection, *arg, 0, 0, func_02169E18, 0);
    return 1;
}


/*
 * sdk:      DWCi_GPRecvBuddyStatusCallback (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
void func_02168F4C(void **connection, RecvArg *arg)
{
	GPBuddyStatus status;
	int friendIdx;

	friendIdx = func_02169038(arg->profile);
	if (friendIdx == -1) {
		if (func_021861A8(connection, arg->profile))
			gpDeleteBuddy(connection, arg->profile);
		return;
	}
	if (stpFriendCnt->statusCb == 0)
		return;
	gpGetBuddyStatus(connection, arg->index, (&status));
	stpFriendCnt->statusCb(friendIdx, status.status, status.locationString, stpFriendCnt->statusParam);
}


/*
 * func_02168FF0: the profile id of a friend list entry, zero when unset or invalid.
 */
int func_02168FF0(int index)
{
    DWCstAccFriendData *list = stpFriendCnt->friendList;
    int pid;

    if (list == 0) {
        return 0;
    }
    pid = DWC_GetGsProfileId(DWCi_GetUserData(), &list[index]);
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

    if (stpFriendCnt == 0 || pid == 0) {
        return -1;
    }
    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
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
    FriendCnt *p = stpFriendCnt;

    if (p == 0) return;
    p->pollCount = 0;
    stpFriendCnt->lastTick = func_020870D0();
}


int func_021690D0(int status, const char *statusString, const char *locString)
{
    if (stpFriendCnt == 0 || func_0216AA70() == 0) {
        return 0;
    }
    if (status == -1) {
        status = ((GPConnObj *)*stpFriendCnt->connection)->status;
    }
    if (statusString == 0) {
        statusString = ((GPConnObj *)*stpFriendCnt->connection)->statusString;
    }
    if (locString == 0) {
        locString = ((GPConnObj *)*stpFriendCnt->connection)->locationString;
    }
    return func_0218627C(stpFriendCnt->connection, status, statusString, locString);
}


/*
 * sdk:      func_02169174 (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
void func_02169174(int index)
{
	struct { char pad[0x108]; char s[0x10c]; } status;
	unsigned char st;
	if (stpFriendCnt->buddyCb != 0 && stpFriendCnt->state != 1)
		stpFriendCnt->buddyCb(index, stpFriendCnt->buddyParam);
	if (stpFriendCnt->statusCb == 0)
		return;
	st = func_0216870C((int)(&stpFriendCnt->friendList[index]), (int)status.s);
	stpFriendCnt->statusCb(index, st, status.s, stpFriendCnt->statusParam);
}


/*
 * Clears the word at +0xc of the module state block.
 */
void func_021691FC(void)
{
    stpFriendCnt = 0;
}


/*
 * sdk:      func_02169210 (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int func_02169210(void)
{
	int result;
	FriendCnt *w;
	u64 tick;
	result = 0;
	tick = func_020870D0();
	w = stpFriendCnt;
	if ((tick - w->lastTick) * 64 / 33514 >= 300) {
		w->pollCount++;
		result = func_02185948(stpFriendCnt->connection);
		stpFriendCnt->lastTick = func_020870D0();
	}
	return result;
}


/*
 * Clears the word and the two bytes at +0x1e and +0x1f of the object at
 * +0xc of the current root.
 */
void func_02169294(void)
{
    FriendCnt *p = stpFriendCnt;
    FriendCnt *q;

    if (p == 0) return;
    p->state = 0;
    q = stpFriendCnt;
    q->phase = 0;
    q = stpFriendCnt;
    q->stage = 0;
}


void func_021692C4(DWCstAccFriendData *friendList, int friendListLen)
{
    GPBuddyStatus status;
    char userName[21];
    int numBuddy;
    int i;
    int j;
    int profileID;

    if (stpFriendCnt->phase == 0) {
        func_021698C0(gpGetNumBuddies(stpFriendCnt->connection, &numBuddy));
        i = 0;
        for (; i < numBuddy; ) {
            func_021698C0(gpGetBuddyStatus(stpFriendCnt->connection, i, &status));
            for (j = 0; j < friendListLen; j++) {
                if (func_02168FF0(j) == status.profile) {
                    if (DWCi_IsBuddyFriendData(&friendList[j]) != 0)
                        goto after;
                    DWC_SetGsProfileId(&friendList[j], status.profile);
                    DWCi_SetBuddyFriendData(&friendList[j]);
                    if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[j]) != 0)
                        DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[j], 1);
                    stpFriendCnt->changed = 1;
                    goto after;
                }
            }
        after:
            if (j == friendListLen) {
                func_021698C0(gpDeleteBuddy(stpFriendCnt->connection, status.profile));
                numBuddy--;
                i--;
            }
            i++;
        }
        stpFriendCnt->phase = 1;
    }

    while (stpFriendCnt->sendIdx < friendListLen) {
        if (DWCi_IsBuddyMsgAlreadySent(&friendList[stpFriendCnt->sendIdx]) != 0)
            goto next;
        profileID = func_02168FF0(stpFriendCnt->sendIdx);
        if (profileID == 0)
            goto blockB;
        if (func_021695F0(friendList, stpFriendCnt->sendIdx, profileID) != 0)
            goto next;
        func_021698C0(gpGetBuddyIndex(stpFriendCnt->connection, profileID, &i));
        if (i != -1)
            goto next;
        func_021697D8(profileID);
        DWCi_SetSentBuddyReqFlag(&friendList[stpFriendCnt->sendIdx], 1);
        goto next;
    blockB:
        if (DWC_GetGsProfileId(DWCi_GetUserData(), &friendList[stpFriendCnt->sendIdx]) != -1)
            goto next;
        DWC_LoginIdToUserName(DWCi_GetUserData(), &friendList[stpFriendCnt->sendIdx], userName);
        gpProfileSearchA(stpFriendCnt->connection, 0, 0, 0, 0, userName, 0, 0,
                         DWCi_GPProfileSearchCallback, (void *)stpFriendCnt->sendIdx);
        stpFriendCnt->phase = 2;
        return;
    next:
        stpFriendCnt->sendIdx++;
    }
}


void func_02169568(void)
{
    stpFriendCnt->finishCb(0, stpFriendCnt->changed, stpFriendCnt->finishParam);
    stpFriendCnt->state = 2;
}


void func_0216959C(void *friendData, int deleteIndex, int otherIndex)
{
    if (stpFriendCnt == 0) return;
    MI_CpuFill8((char *)friendData + deleteIndex * 0xc, 0, 0xc);
    if (stpFriendCnt->deleteCb == 0) return;
    stpFriendCnt->deleteCb(deleteIndex, otherIndex, stpFriendCnt->deleteParam);
}


/*
 * sdk:      func_021695F0 (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int func_021695F0(DWCstAccFriendData *friendList, int index, int profileID)
{
	int i;
	int pid_i;

	if (DWC_GetFriendDataType(&friendList[index]) == 1)
		return 0;
	for (i = 0; i < index; i++) {
		pid_i = func_02168FF0(i);
		if (pid_i != 0 && pid_i == profileID) {
			if (DWCi_IsBuddyFriendData(&friendList[index]) && !DWCi_IsBuddyFriendData(&friendList[i]))
				func_0216959C(friendList, i, index);
			else
				func_0216959C(friendList, index, i);
			stpFriendCnt->changed = 1;
			return 1;
		}
	}
	return 0;
}


/*
 * sdk:      func_021696B0 (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int func_021696B0(DWCstAccFriendData *friendList, int friendListLen, int profileID)
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
            if (DWC_GetFriendDataType(&friendList[i]) == 2 && DWC_GetFriendDataType(&friendList[j]) == 3)
                DWC_SetGsProfileId(&friendList[i], pid_i);
            if (DWCi_IsBuddyFriendData(&friendList[j])) {
                DWCi_SetBuddyFriendData(&friendList[i]);
                if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                    DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[i], 1);
            }
            func_0216959C(friendList, j, i);
            stpFriendCnt->changed = 1;
        }
    }
    return index;
}


/*
 * sdk:      func_021697D8 (dwc_friend.o)
 */
int func_021697D8(int profileID)
{
    int gpResult;

    gpResult = func_02185D04(stpFriendCnt->connection, profileID, g_021A200C);
    func_021698C0(gpResult);
    return gpResult;
}


/*
 * closed (2026-10-01, ov SDK wave 2): the dwc_friend.o statics (s_bNeedCloseStatsConnection +0,
 *   stpFriendCnt +0xc) are TU `static ... = 0;` as in DWCi_FriendProcess, not one extern
 *   struct; the anchor web now schedules the prologue like the image.
 *
 * sdk:      DWCi_GetFriendBuddyStatus (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int func_0216980C(void *friendData, GPBuddyStatus *status)
{
	unsigned char ret = 0;
	int buddyIdx = 0;
	int profileid;
	if (stpFriendCnt == 0 || !func_0216AA70())
		return 0;
	profileid = DWC_GetGsProfileId(DWCi_GetUserData(), friendData);
	if (profileid > 0) {
		if (gpGetBuddyIndex(stpFriendCnt->connection, profileid, &buddyIdx) != 0)
			goto end;
	}
	if (!(profileid > 0 && buddyIdx != -1)) {
		ret = 0;
	} else {
		int res = gpGetBuddyStatus(stpFriendCnt->connection, buddyIdx, status);
		ret = 0;
		if (res == 0)
			ret = 1;
	}
end:
	return ret;
}


/*
 * sdk:      func_021698C0 (dwc_friend.o)
 */
int func_021698C0(int result)
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
    func_02168E50(dwcError, errorCode + (int)0xfffeeaa8);
    return result;
}


void DWCi_GPProfileSearchCallback(void **connection, void *argv, void *param)
{
    GPProfileSearchResponseArg *arg = argv;
    int i;
    int idx;
    int match_index = (int)param;

    if (arg->result != 0 || arg->numMatches == 0)
        goto err;
    if (DWC_GetFriendDataType(&stpFriendCnt->friendList[match_index]) == 0)
        goto err;
    if (stpFriendCnt->state != 1)
        return;

    for (i = 0; i < arg->numMatches; i++) {
        if (func_021695F0(stpFriendCnt->friendList, match_index, arg->matches[i].profileID) != 0) {
            stpFriendCnt->sendIdx++;
            stpFriendCnt->phase = 1;
            arg->more = 0x601;
            return;
        }
    }

    for (i = 0; i < arg->numMatches; i++) {
        func_021698C0(gpGetBuddyIndex(connection, arg->matches[i].profileID, &idx));
        if (idx == -1) {
            func_021697D8(arg->matches[i].profileID);
            DWCi_SetSentBuddyReqFlag(&stpFriendCnt->friendList[match_index], 1);
        } else {
            DWC_SetGsProfileId(&stpFriendCnt->friendList[match_index], arg->matches[0].profileID);
            DWCi_SetBuddyFriendData(&stpFriendCnt->friendList[match_index]);
            DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[match_index], 1);
            if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[match_index]) != 0)
                DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[match_index], 1);
            func_02169174(match_index);
            stpFriendCnt->sendIdx++;
            stpFriendCnt->phase = 1;
            arg->more = 0x601;
            stpFriendCnt->changed = 1;
            return;
        }
    }

    if (arg->more == 0x600)
        return;
    stpFriendCnt->sendIdx++;
    stpFriendCnt->phase = 1;
    return;

err:
    if (arg->result != 0) {
        func_021698C0(arg->result);
        return;
    }
    if (stpFriendCnt->state != 1 && DWC_GetFriendDataType(&stpFriendCnt->friendList[match_index]) != 0)
        return;
    stpFriendCnt->sendIdx++;
    stpFriendCnt->phase = 1;
}


static void DWCi_GPGetInfoCallback_RecvBuddyRequest(void **connection, void *argv, void *param)
{
    GPGetInfoResponseArg_02169BB0 *arg = argv;
    int i;
    int confirm = 0;
    int alreadyBuddy = 0;
    int index;
    unsigned int gamecode;
    char userName[21];
    char gamecode_str[5];

    if (arg->field0 != 0)
        return;

    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
        if (DWC_GetFriendDataType(&stpFriendCnt->friendList[i]) == 1) {
            DWC_LoginIdToUserName(DWCi_GetUserData(), &stpFriendCnt->friendList[i], userName);
            if (strcmp(userName, arg->userName) != 0)
                continue;
            if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                alreadyBuddy = 1;
            gpAuthBuddyRequest(connection, arg->field4);
            DWC_SetGsProfileId(&stpFriendCnt->friendList[i], arg->field4);
            confirm = 1;
        } else if (DWC_GetFriendDataType(&stpFriendCnt->friendList[i]) == 3 || DWC_GetFriendDataType(&stpFriendCnt->friendList[i]) == 2) {
            gamecode = DWCi_GetUserData()->gamecode;
            OS_SNPrintf(gamecode_str, 5, g_021A2010, (gamecode >> 24) & 0xff, (gamecode >> 16) & 0xff, (gamecode >> 8) & 0xff, gamecode & 0xff);
            if (DWC_GetGsProfileId(DWCi_GetUserData(), &stpFriendCnt->friendList[i]) != arg->field4)
                continue;
            if (memcmp(gamecode_str, arg->gamecode, 4) != 0)
                continue;
            if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                alreadyBuddy = 1;
            gpAuthBuddyRequest(connection, arg->field4);
            confirm = 1;
        }
    }

    if (confirm != 0) {
        func_021697D8(arg->field4);
        index = func_021696B0(stpFriendCnt->friendList, stpFriendCnt->friendListLen, arg->field4);
        DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[index], 1);
        if (!DWC_IsBuddyFriendData(&stpFriendCnt->friendList[index]))
            return;
        DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[index], 1);
        if (alreadyBuddy)
            return;
        func_02169174(index);
        stpFriendCnt->changed = 1;
    } else {
        gpDenyBuddyRequest(connection, arg->field4);
    }
}


/*
 * sdk:      DWCi_GPGetInfoCallback_RecvAuthMessage (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * The object reads arg from r1 (GP callback: connection, arg, param); the DWARF
 * prototype lists only arg.
 */
void func_02169E18(void **connection, void *argv, void *param)
{
    GPGetInfoResponseArg_0216870C *arg = argv;
    char userName[21];
    int index;
    int i;
    int listChanged = 0;
    int alreadyBuddy = 0;

    if (arg->result != 0)
        return;
    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
        if (DWC_GetFriendDataType(&stpFriendCnt->friendList[i]) == 1) {
            DWC_LoginIdToUserName((void *)DWCi_GetUserData(), &stpFriendCnt->friendList[i], userName);
            if (strcmp(userName, arg->lastname) == 0) {
                DWC_SetGsProfileId(&stpFriendCnt->friendList[i], arg->profile);
                DWCi_SetBuddyFriendData(&stpFriendCnt->friendList[i]);
                listChanged = 1;
            }
        } else if (DWC_GetFriendDataType(&stpFriendCnt->friendList[i]) == 3
                   || DWC_GetFriendDataType(&stpFriendCnt->friendList[i]) == 2) {
            if (DWC_GetGsProfileId(DWCi_GetUserData(), &stpFriendCnt->friendList[i]) == arg->profile) {
                if (DWCi_IsBuddyFriendData(&stpFriendCnt->friendList[i]) == 1)
                    alreadyBuddy = 1;
                else {
                    DWC_SetGsProfileId(&stpFriendCnt->friendList[i], arg->profile);
                    DWCi_SetBuddyFriendData(&stpFriendCnt->friendList[i]);
                    listChanged = 1;
                }
            }
        }
    }
    if (!listChanged)
        return;
    index = func_021696B0(stpFriendCnt->friendList, stpFriendCnt->friendListLen, arg->profile);
    if (!alreadyBuddy) {
        DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[index], 1);
        if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[index]))
            DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[index], 1);
        func_02169174(index);
    }
    stpFriendCnt->changed = 1;
}


/*
 * The word at +0x20 of the block held at +0xc of the module state block.
 */
int func_02169FE4(void)
{
    return stpFriendCnt->fld20;
}


/*
 * Sets the word at +0x10 of the module state block to 1.
 */
void func_02169FF8(void)
{
    s_bReverseBuddiesBusy = 1;
}


/*
 * Clears the word at +0x10 of the module state block.
 */
void func_0216A00C(void)
{
    s_bReverseBuddiesBusy = 0;
}


/*
 * sdk:      func_0216A020 (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * The DWARF has the response argument alone; the object receives it in r1, so the
 * callback takes the connection first.
 */
void func_0216A020(void **connection, void *argv, void *param)
{
    GPGetReverseBuddiesListResponseArg *arg = argv;
    int i;
    int j;

    if (!func_02168D7C())
        return;
    if (stpFriendCnt->reversePids != 0) {
        DWC_Free(4, stpFriendCnt->reversePids, 0);
        stpFriendCnt->reversePids = 0;
    }
    if (arg->result != 0) {
        func_02169568();
        return;
    }
    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
        if (DWC_GetFriendDataType(&stpFriendCnt->friendList[i]) == 3) {
            for (j = 0; j < arg->numOfUniqueMatchs; j++) {
                if (arg->matches[j].profile == DWC_GetGsProfileId(DWCi_GetUserData(), &stpFriendCnt->friendList[i])) {
                    if (!func_02059194(&stpFriendCnt->friendList[i])) {
                        stpFriendCnt->changed = 1;
                        DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[i], 1);
                        if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                            DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[i], 1);
                    }
                    break;
                }
            }
            if (j == arg->numOfUniqueMatchs && func_02059194(&stpFriendCnt->friendList[i]) == 1) {
                stpFriendCnt->changed = 1;
                DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[i], 0);
            }
            if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[i], 1);
        }
    }
    func_02169568();
}
