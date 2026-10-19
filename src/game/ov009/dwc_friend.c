/*
 * file:     dwc_friend.c
 * unit:     yes
 * function: DWC_GetFriendStatus, DWC_GetFriendStatusSC, DWC_GetFriendStatusData, DWC_GetFriendStatusDataSC, DWC_SetOwnStatusData, DWC_SetBuddyFriendCallback, DWCi_FriendInit, DWCi_FriendProcess, DWCi_IsServerUpdating, DWCi_UpdateServersAsync, DWCi_StopFriendProcess, DWCi_GPRecvBuddyRequestCallback, DWCi_GPRecvBuddyAuthCallback, DWCi_GPRecvBuddyStatusCallback, DWCi_GetProfileIDFromList, DWCi_GetFriendListIndex, DWCi_InitGPProcessCount, DWCi_SetGPStatus, DWCi_CallBuddyFriendCallback, DWCi_ShutdownFriend, DWCi_GPProcess, DWCi_CloseFriendProcess, DWCi_UpdateFriendReq, DWCi_EndUpdateServers, DWCi_DeleteFriendFromList, DWCi_RefreshFriendListForth, DWCi_RefreshFriendListAll, DWCi_GPSendBuddyRequest, DWCi_GetFriendBuddyStatus, DWCi_HandleGPError, DWCi_GPProfileSearchCallback, DWCi_GPGetInfoCallback_RecvBuddyRequest, DWCi_GPGetInfoCallback_RecvAuthMessage, DWCi_GetPersCallbackLevel, DWCi_BeginCloseStatsConnection, DWCi_EndCloseStatsConnection, DWCi_GetReverseBuddiesCallback
 * address:  0x0216870C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_GetFriendBuddyStatus  0x0216980C  arm  ov009
 *   DWC_GetCommonValueString  0x021684CC  arm  ov009
 *   strtoul        0x02095EAC  arm
 *   strcpy         0x02094798  arm
 *   DWCi_IsLockedBuddyStatus  0x02176984  arm  ov009
 *   gDwcFriendMaxEntryKey     0x021A2004  data
 *   gDwcFriendNumEntryKey     0x021A2008  data
 *   strlen  0x0209477C  arm
 *   DWC_Base64Decode  0x02059CBC  arm
 *   DWCi_CheckLogin  0x0216AA70  arm  ov009
 *   DWC_Base64Encode  0x02059B40  arm
 *   DWCi_SetGPStatus  0x021690D0  arm  ov009
 *   DWCi_SetSentBuddyReqFlag  0x020592A0  arm
 *   DWCi_IsError                    0x02059F38 arm
 *   IsStatsConnected                0x02193D64 arm ov009
 *   PersistThink                    0x02193D80 arm ov009
 *   CloseStatsConnection            0x02193D00 arm ov009
 *   DWCi_Acc_GetFlagDataTypeThunk           0x020591CC arm
 *   DWC_Alloc                       0x0205A16C arm
 *   DWCi_GetUserData                0x0216A39C arm ov009
 *   DWC_GetGsProfileId              0x020598EC arm
 *   gpGetReversBuddiesList          0x02186564 arm ov009
 *   s_bNeedCloseStatsConnection     0x021AA860 data
 *   DWCi_SetError  0x02059F54  arm
 *   DWCi_IsServerUpdating  0x02168D7C  arm
 *   DWCi_CloseFriendProcess  0x02169294  arm
 *   gpGetInfo  0x02185BD8  arm
 *   DWCi_GPGetInfoCallback_RecvAuthMessage  0x02169E18  arm
 *   gpIsBuddy  0x021861A8  arm  ov009
 *   OS_GetTick  0x020870D0  arm
 *   gpSetStatusA  0x0218627C  arm  ov009
 *   DWC_GetFriendStatus  0x0216870C  arm  ov009
 *   gpProcess  0x02185948  arm  ov009
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
 *   DWC_LoginIdToUserName            0x02059a44 arm
 *   gpProfileSearchA                 0x02185b10 arm
 *   DWCi_GPProfileSearchCallback     0x02169934 arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWCi_GetProfileIDFromList  0x02168FF0  arm  ov009
 *   DWCi_DeleteFriendFromList  0x0216959C  arm  ov009
 *   gDwcFriendGetInfoFlags   0x021A200C  data
 *   gpSendBuddyRequestA  0x02185D04  arm
 *   DWCi_StopFriendProcess  0x02168E50  arm
 *   DWCi_SetReverseBuddyFlag         0x02059240 arm
 *   strcmp                           0x020948E0 arm
 *   gpAuthBuddyRequest               0x02185E94 arm ov009
 *   OS_SNPrintf                      0x02084F80 arm
 *   memcmp                           0x020923F0 arm
 *   gpDenyBuddyRequest               0x02185EE4 arm ov009
 *   gDwcFriendKeyFormat                       0x021A2010 data
 *   DWCi_RefreshFriendListAll  0x021696B0  arm  ov009
 *   DWCi_CallBuddyFriendCallback  0x02169174  arm  ov009
 *   DWC_Free       0x0205A1B0  arm
 *   DWCi_EndUpdateServers  0x02169568  arm  ov009
 *   DWCi_IsReverseBuddyFriendData  0x02059194  arm
 *   _ll_udiv                     0x0209C00C  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"
extern int strcmp(const char *s1, const char *s2);
extern int memcmp(unsigned char *s1, unsigned char *s2, unsigned int n);

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
    int persCallbackLevel;                                              /* 0x20 */
    int reserved24;                                              /* 0x24 */
    int reserved28;                                              /* 0x28 */
    void (*finishCb)(int, u8, int);                         /* 0x2c */
    int finishParam;                                        /* 0x30 */
    void (*statusCb)(int, u8, char *, void *);              /* 0x34 */
    void *statusParam;                                      /* 0x38 */
    void (*deleteCb)(int, int, int);                        /* 0x3c */
    int deleteParam;                                        /* 0x40 */
    void (*buddyCb)(int, void *);                           /* 0x44 */
    void *buddyParam;                                       /* 0x48 */
    int reserved4c;                                              /* 0x4c */
    int reserved50;                                              /* 0x50 */
    int reserved54;                                              /* 0x54 */
    int reserved58;                                              /* 0x58 */
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

typedef struct GpBuddyRequestArg {
    int result;
    int profile;
    char pad8[0x8e - 8];
    char userName[9];
    char gamecode[4];
} GpBuddyRequestArg;

typedef struct GpGetInfoResponseArg {
    int result;
    int profile;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char firstname[31];
    char lastname[31];
} GpGetInfoResponseArg;

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

extern int DWC_GetCommonValueString(char *key, char *value, char *string, char separator);
extern unsigned long strtoul(unsigned int s, unsigned int *endptr, unsigned int base);
extern unsigned char DWCi_IsLockedBuddyStatus(char *buddyStatus);
extern int DWC_Base64Decode(const char *src, u32 srclen, char *dst, u32 dstlen);
extern int DWCi_CheckLogin(void);
extern int DWC_Base64Encode(const char *src, u32 srclen, char *dst, u32 dstlen);
extern char gDwcFriendMaxEntryKey[];
extern char gDwcFriendNumEntryKey[];
extern char gDwcFriendGetInfoFlags[];
extern char gDwcFriendKeyFormat[];
extern void DWCi_SetSentBuddyReqFlag(void *frienddata, int setflag);
extern int DWCi_IsError(void);
extern int IsStatsConnected(void);
extern int PersistThink(void);
extern void CloseStatsConnection(void);
extern unsigned int DWCi_Acc_GetFlagDataTypeThunk(void *userdata);
extern void *DWC_Alloc(int name, unsigned long size);
extern DWCstAccUserData *DWCi_GetUserData(void);
extern int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata);
extern int gpGetReversBuddiesList(void **connection, int *targets, int numOfTargets, int blocking, void (*callback)(void **, void *, void *), void *param);
extern void DWCi_SetError(int error, int errorCode);
extern void DWC_Free(int name, void *ptr, unsigned long size);
extern int gpGetInfo(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int gpIsBuddy(void **connection, int profile);
extern int gpDeleteBuddy(void **connection, int profile);
extern int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status);
extern u64 OS_GetTick(void);
extern int gpSetStatusA(void **connection, int status, const char *statusString, const char *locationString);
extern int gpProcess(void **connection);
extern int gpGetNumBuddies(void **connection, int *numBuddies);
extern int DWCi_IsBuddyFriendData(void *frienddata);
extern void DWC_SetGsProfileId(void *frienddata, int gs_profile_id);
extern void DWCi_SetBuddyFriendData(DWCstAccFriendData *frienddata);
extern int DWC_IsBuddyFriendData(void *frienddata);
extern void DWCi_SetExpIsBuddyFriendFlag(void *frienddata, int setflag);
extern int DWCi_IsBuddyMsgAlreadySent(void *frienddata);
extern int gpGetBuddyIndex(void **connection, int profile, int *index);
extern void DWC_LoginIdToUserName(struct DWCstAccUserData *userdata, void *frienddata, char *username);
extern int gpProfileSearchA(void **connection, char *nick, char *uniquenick, char *email,
                            char *firstname, char *lastname, int icquin, int blocking,
                            void (*callback)(void **, void *, void *), void *param);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int gpSendBuddyRequestA(void **connection, int profile, char *reason);
extern void DWCi_SetReverseBuddyFlag(void *frienddata, int setflag);
extern int gpAuthBuddyRequest(void **connection, int profile);
extern int gpDenyBuddyRequest(void **connection, int profile);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern int DWCi_IsReverseBuddyFriendData(void *frienddata);

/* dwc_friend.o local data: one .bss block at 0x021AA860 */
static FriendCnt *stpFriendCnt = 0;
static int s_bInCloseStatsConnection = 0;
static int s_bInPersistThink = 0;
static int s_bNeedCloseStatsConnection = 0;
static int s_bReverseBuddiesBusy = 0;

u8 DWC_GetFriendStatus(int a, int b);
u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);
unsigned char DWC_GetFriendStatusData(void *p, int a, u8 *b);
unsigned char DWC_GetFriendStatusDataSC(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
int DWC_SetOwnStatusData(char *statusData, unsigned long size);
int DWC_SetBuddyFriendCallback(void (*callback)(int, void *), void *param);
void DWCi_FriendInit(FriendCnt *p, int pGpObj, int userData, int friendList, int n);
void DWCi_FriendProcess(void);
int DWCi_IsServerUpdating(void);
void DWCi_UpdateServersAsync(int authToken, int partnerChallenge, void (*a2)(int, u8, int), int finishParam, void (*a4)(int, u8, char *, void *), void *statusParam, void (*a6)(int, int, int), int deleteParam);
void DWCi_StopFriendProcess(int error, int errorCode);
void DWCi_GPRecvBuddyRequestCallback(void **connection, int *arg);
int DWCi_GPRecvBuddyAuthCallback(void **connection, int *arg);
void DWCi_GPRecvBuddyStatusCallback(void **connection, RecvArg *arg);
int DWCi_GetProfileIDFromList(int index);
int DWCi_GetFriendListIndex(int pid);
void DWCi_InitGPProcessCount(void);
int DWCi_SetGPStatus(int status, const char *statusString, const char *locString);
void DWCi_CallBuddyFriendCallback(int index);
void DWCi_ShutdownFriend(void);
int DWCi_GPProcess(void);
void DWCi_CloseFriendProcess(void);
void DWCi_UpdateFriendReq(DWCstAccFriendData *friendList, int friendListLen);
void DWCi_EndUpdateServers(void);
void DWCi_DeleteFriendFromList(void *friendData, int deleteIndex, int otherIndex);
int DWCi_RefreshFriendListForth(DWCstAccFriendData *friendList, int index, int profileID);
int DWCi_RefreshFriendListAll(DWCstAccFriendData *friendList, int friendListLen, int profileID);
int DWCi_GPSendBuddyRequest(int profileID);
int DWCi_GetFriendBuddyStatus(void *friendData, GPBuddyStatus *status);
static int DWCi_HandleGPError(int result);
void DWCi_GPProfileSearchCallback(void **connection, void *argv, void *param);
static void DWCi_GPGetInfoCallback_RecvBuddyRequest(void **connection, void *argv, void *param);
void DWCi_GPGetInfoCallback_RecvAuthMessage(void **connection, void *argv, void *param);
int DWCi_GetPersCallbackLevel(void);
void DWCi_BeginCloseStatsConnection(void);
void DWCi_EndCloseStatsConnection(void);
void DWCi_GetReverseBuddiesCallback(void **connection, void *argv, void *param);


/*
 * Tail call with the last argument moved to the fourth slot.
 */
u8 DWC_GetFriendStatus(int a, int b)
{
    return DWC_GetFriendStatusSC((void *)a, 0, 0, (char *)b);
}


/*
 * sdk:      DWC_GetFriendStatusSC (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString)
{
    u8 state;
    GPBuddyStatus status;
    int len;
    char valueStr[4];

    if (DWCi_GetFriendBuddyStatus(friendData, &status)) {
        if (status.status == 6) {
            if (maxEntry) {
                len = DWC_GetCommonValueString(gDwcFriendMaxEntryKey, valueStr, status.statusString, '/');
                if (len > 0)
                    *maxEntry = strtoul((unsigned int)valueStr, 0, 10);
                else
                    *maxEntry = 0;
            }
            if (numEntry) {
                len = DWC_GetCommonValueString(gDwcFriendNumEntryKey, valueStr, status.statusString, '/');
                if (len > 0)
                    *numEntry = strtoul((unsigned int)valueStr, 0, 10);
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
        if (DWCi_IsLockedBuddyStatus((char *)(&status)))
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
 * Calls DWC_GetFriendStatusDataSC with two zeroed arguments between the tail arguments.
 */
unsigned char DWC_GetFriendStatusData(void *p, int a, u8 *b)
{
    unsigned char DWC_GetFriendStatusDataSC(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
    return DWC_GetFriendStatusDataSC(p, 0, 0, (char *)a, (int *)b);
}


/*
 * sdk:      DWC_GetFriendStatusDataSC (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
unsigned char DWC_GetFriendStatusDataSC(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size)
{
	char statusString[256];
	unsigned char ret;
	ret = DWC_GetFriendStatusSC(friendData, maxEntry, numEntry, statusString);
	if (ret == 0) {
		*size = -1;
		return ret;
	}
	*size = DWC_Base64Decode(statusString, strlen((const char *)statusString), 0, 0);
	if (statusData == 0 || *size == -1)
		return ret;
	DWC_Base64Decode(statusString, strlen((const char *)statusString), statusData, *size);
	return ret;
}


/*
 * sdk:      DWC_SetOwnStatusData (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int DWC_SetOwnStatusData(char *statusData, unsigned long size)
{
	char statusString[256];
	int len;
	int ret;

	if (stpFriendCnt == 0 || !DWCi_CheckLogin())
		return 0;
	len = DWC_Base64Encode(statusData, size, statusString, 255);
	if (len == -1)
		return 0;
	statusString[len] = 0;
	ret = DWCi_SetGPStatus(-1, 0, statusString);
	if (ret == 0)
		return 1;
	return 0;
}


/*
 * sdk:      DWC_SetBuddyFriendCallback (dwc_friend.o)
 */
int DWC_SetBuddyFriendCallback(void (*callback)(int, void *), void *param)
{
    if (stpFriendCnt == 0)
        return 0;
    stpFriendCnt->buddyCb = callback;
    stpFriendCnt->buddyParam = param;
    return 1;
}


void DWCi_FriendInit(FriendCnt *friendCnt, int pGpObj, int userData, int friendList, int friendListLen)
{
    int i;
    FriendCnt *q;

    stpFriendCnt = friendCnt;
    friendCnt->state = 0;
    stpFriendCnt->connection = (void **)pGpObj;
    stpFriendCnt->pollCount = 0;
    q = stpFriendCnt;
    q->lastTick = 0;
    q->friendListLen = friendListLen;
    stpFriendCnt->friendList = (DWCstAccFriendData *)friendList;
    stpFriendCnt->sendIdx = 0;
    stpFriendCnt->changed = 0;
    stpFriendCnt->phase = 0;
    stpFriendCnt->stage = 0;
    stpFriendCnt->persCallbackLevel = 0;
    stpFriendCnt->reserved24 = 0;
    stpFriendCnt->reserved28 = userData;
    stpFriendCnt->finishCb = 0;
    stpFriendCnt->finishParam = 0;
    stpFriendCnt->statusCb = 0;
    stpFriendCnt->statusParam = 0;
    stpFriendCnt->deleteCb = 0;
    stpFriendCnt->deleteParam = 0;
    stpFriendCnt->buddyCb = 0;
    stpFriendCnt->buddyParam = 0;
    stpFriendCnt->reserved4c = 0;
    stpFriendCnt->reserved50 = 0;
    stpFriendCnt->reserved54 = 0;
    stpFriendCnt->reserved58 = 0;
    stpFriendCnt->reversePids = 0;

    for (i = 0; i < friendListLen; i++)
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
void DWCi_FriendProcess(void)
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
        DWCi_GPProcess();
        return;
    }

    if (DWCi_GetPersCallbackLevel() != 0 || IsStatsConnected()) {
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
        if (DWCi_GPProcess() != 0)
            return;
        if (stpFriendCnt->state == 0)
            return;
        if (stpFriendCnt->friendList != 0 && stpFriendCnt->phase != 3 && stpFriendCnt->pollCount > 7) {
            if (stpFriendCnt->phase <= 1)
                DWCi_UpdateFriendReq(stpFriendCnt->friendList, stpFriendCnt->friendListLen);
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
        if (DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[i]) == 3)
            pidcnt++;
    if (pidcnt == 0) {
        stpFriendCnt->stage = 0;
        DWCi_EndUpdateServers();
        return;
    }
    stpFriendCnt->reversePids = DWC_Alloc(4, pidcnt * 4);
    if (stpFriendCnt->reversePids == 0) {
        DWCi_StopFriendProcess(9, (int)0xfffeee8fU);
        return;
    }
    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
        if (DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[i]) == 3) {
            stpFriendCnt->reversePids[j] = DWC_GetGsProfileId(DWCi_GetUserData(), &stpFriendCnt->friendList[i]);
            j++;
        }
    }
    gpResult = gpGetReversBuddiesList(stpFriendCnt->connection, stpFriendCnt->reversePids, pidcnt, 0, DWCi_GetReverseBuddiesCallback, 0);
    if (DWCi_HandleGPError(gpResult) != 0)
        return;
end:
    stpFriendCnt->stage = 0;
}


/*
 * True when the object at +0xc of the current root exists and its first word
 * is 1.
 */
int DWCi_IsServerUpdating(void)
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
void DWCi_UpdateServersAsync(int authToken, int partnerChallenge, void (*finishCallback)(int, u8, int), int finishParam, void (*statusCallback)(int, u8, char *, void *), void *statusParam, void (*deleteCallback)(int, int, int), int deleteParam)
{
    stpFriendCnt->finishCb = finishCallback;
    stpFriendCnt->finishParam = finishParam;
    stpFriendCnt->statusCb = statusCallback;
    stpFriendCnt->statusParam = statusParam;
    stpFriendCnt->deleteCb = deleteCallback;
    stpFriendCnt->deleteParam = deleteParam;
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
 * sdk:      DWCi_StopFriendProcess (dwc_friend.o)
 */
void DWCi_StopFriendProcess(int error, int errorCode)
{
    if (stpFriendCnt == 0 || error == 0) return;
    DWCi_SetError(error, errorCode);
    if (DWCi_IsServerUpdating() != 0) {
        if (stpFriendCnt->reversePids != 0) {
            DWC_Free(4, stpFriendCnt->reversePids, 0);
            stpFriendCnt->reversePids = 0;
        }
        stpFriendCnt->finishCb(error, stpFriendCnt->changed, stpFriendCnt->finishParam);
    }
    DWCi_CloseFriendProcess();
}


/*
 * sdk:      DWCi_GPRecvBuddyRequestCallback (dwc_friend.o)
 */
void DWCi_GPRecvBuddyRequestCallback(void **connection, int *arg)
{
    if (stpFriendCnt->friendList == 0) return;
    gpGetInfo(connection, *arg, 0, 0, DWCi_GPGetInfoCallback_RecvBuddyRequest, 0);
}


/*
 * sdk:      DWCi_GPRecvBuddyAuthCallback (dwc_friend.o)
 */
int DWCi_GPRecvBuddyAuthCallback(void **connection, int *arg)
{
    gpGetInfo(connection, *arg, 0, 0, DWCi_GPGetInfoCallback_RecvAuthMessage, 0);
    return 1;
}


/*
 * sdk:      DWCi_GPRecvBuddyStatusCallback (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
void DWCi_GPRecvBuddyStatusCallback(void **connection, RecvArg *arg)
{
	GPBuddyStatus status;
	int friendIdx;

	friendIdx = DWCi_GetFriendListIndex(arg->profile);
	if (friendIdx == -1) {
		if (gpIsBuddy(connection, arg->profile))
			gpDeleteBuddy(connection, arg->profile);
		return;
	}
	if (stpFriendCnt->statusCb == 0)
		return;
	gpGetBuddyStatus(connection, arg->index, (&status));
	stpFriendCnt->statusCb(friendIdx, status.status, status.locationString, stpFriendCnt->statusParam);
}


/*
 * DWCi_GetProfileIDFromList: the profile id of a friend list entry, zero when unset or invalid.
 */
int DWCi_GetProfileIDFromList(int index)
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
int DWCi_GetFriendListIndex(int pid)
{
    int i;

    if (stpFriendCnt == 0 || pid == 0) {
        return -1;
    }
    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
        if (pid == DWCi_GetProfileIDFromList(i)) {
            return i;
        }
    }
    return -1;
}


/*
 * sdk:      DWCi_InitGPProcessCount (dwc_friend.o)
 */
void DWCi_InitGPProcessCount(void)
{
    FriendCnt *p = stpFriendCnt;

    if (p == 0) return;
    p->pollCount = 0;
    stpFriendCnt->lastTick = OS_GetTick();
}


int DWCi_SetGPStatus(int status, const char *statusString, const char *locString)
{
    if (stpFriendCnt == 0 || DWCi_CheckLogin() == 0) {
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
    return gpSetStatusA(stpFriendCnt->connection, status, statusString, locString);
}


/*
 * sdk:      DWCi_CallBuddyFriendCallback (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
void DWCi_CallBuddyFriendCallback(int index)
{
	struct { char pad[0x108]; char s[0x10c]; } status;
	unsigned char st;
	if (stpFriendCnt->buddyCb != 0 && stpFriendCnt->state != 1)
		stpFriendCnt->buddyCb(index, stpFriendCnt->buddyParam);
	if (stpFriendCnt->statusCb == 0)
		return;
	st = DWC_GetFriendStatus((int)(&stpFriendCnt->friendList[index]), (int)status.s);
	stpFriendCnt->statusCb(index, st, status.s, stpFriendCnt->statusParam);
}


/*
 * Clears the word at +0xc of the module state block.
 */
void DWCi_ShutdownFriend(void)
{
    stpFriendCnt = 0;
}


/*
 * sdk:      DWCi_GPProcess (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int DWCi_GPProcess(void)
{
	int result;
	FriendCnt *w;
	u64 tick;
	result = 0;
	tick = OS_GetTick();
	w = stpFriendCnt;
	if ((tick - w->lastTick) * 64 / 33514 >= 300) {
		w->pollCount++;
		result = gpProcess(stpFriendCnt->connection);
		stpFriendCnt->lastTick = OS_GetTick();
	}
	return result;
}


/*
 * Clears the word and the two bytes at +0x1e and +0x1f of the object at
 * +0xc of the current root.
 */
void DWCi_CloseFriendProcess(void)
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


void DWCi_UpdateFriendReq(DWCstAccFriendData *friendList, int friendListLen)
{
    GPBuddyStatus status;
    char userName[21];
    int numBuddy;
    int i;
    int j;
    int profileID;

    if (stpFriendCnt->phase == 0) {
        DWCi_HandleGPError(gpGetNumBuddies(stpFriendCnt->connection, &numBuddy));
        i = 0;
        for (; i < numBuddy; ) {
            DWCi_HandleGPError(gpGetBuddyStatus(stpFriendCnt->connection, i, &status));
            for (j = 0; j < friendListLen; j++) {
                if (DWCi_GetProfileIDFromList(j) == status.profile) {
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
                DWCi_HandleGPError(gpDeleteBuddy(stpFriendCnt->connection, status.profile));
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
        profileID = DWCi_GetProfileIDFromList(stpFriendCnt->sendIdx);
        if (profileID == 0)
            goto blockB;
        if (DWCi_RefreshFriendListForth(friendList, stpFriendCnt->sendIdx, profileID) != 0)
            goto next;
        DWCi_HandleGPError(gpGetBuddyIndex(stpFriendCnt->connection, profileID, &i));
        if (i != -1)
            goto next;
        DWCi_GPSendBuddyRequest(profileID);
        DWCi_SetSentBuddyReqFlag(&friendList[stpFriendCnt->sendIdx], 1);
        goto next;
    blockB:
        if (DWC_GetGsProfileId(DWCi_GetUserData(), &friendList[stpFriendCnt->sendIdx]) != -1)
            goto next;
        DWC_LoginIdToUserName(DWCi_GetUserData(), &friendList[stpFriendCnt->sendIdx], (char *)userName);
        gpProfileSearchA(stpFriendCnt->connection, 0, 0, 0, 0, userName, 0, 0,
                         DWCi_GPProfileSearchCallback, (void *)stpFriendCnt->sendIdx);
        stpFriendCnt->phase = 2;
        return;
    next:
        stpFriendCnt->sendIdx++;
    }
}


void DWCi_EndUpdateServers(void)
{
    stpFriendCnt->finishCb(0, stpFriendCnt->changed, stpFriendCnt->finishParam);
    stpFriendCnt->state = 2;
}


void DWCi_DeleteFriendFromList(void *friendData, int deleteIndex, int otherIndex)
{
    if (stpFriendCnt == 0) return;
    MI_CpuFill8((char *)friendData + deleteIndex * 0xc, 0, 0xc);
    if (stpFriendCnt->deleteCb == 0) return;
    stpFriendCnt->deleteCb(deleteIndex, otherIndex, stpFriendCnt->deleteParam);
}


/*
 * sdk:      DWCi_RefreshFriendListForth (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int DWCi_RefreshFriendListForth(DWCstAccFriendData *friendList, int index, int profileID)
{
	int i;
	int pid_i;

	if (DWCi_Acc_GetFlagDataTypeThunk(&friendList[index]) == 1)
		return 0;
	for (i = 0; i < index; i++) {
		pid_i = DWCi_GetProfileIDFromList(i);
		if (pid_i != 0 && pid_i == profileID) {
			if (DWCi_IsBuddyFriendData(&friendList[index]) && !DWCi_IsBuddyFriendData(&friendList[i]))
				DWCi_DeleteFriendFromList(friendList, i, index);
			else
				DWCi_DeleteFriendFromList(friendList, index, i);
			stpFriendCnt->changed = 1;
			return 1;
		}
	}
	return 0;
}


/*
 * sdk:      DWCi_RefreshFriendListAll (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int DWCi_RefreshFriendListAll(DWCstAccFriendData *friendList, int friendListLen, int profileID)
{
    int index = -1;
    int pid_i;
    int i;
    int j;

    for (i = 0; i < friendListLen; i++) {
        pid_i = DWCi_GetProfileIDFromList(i);
        if (pid_i == 0)
            continue;
        if (pid_i == profileID)
            index = i;
        for (j = i + 1; j < friendListLen; j++) {
            if (pid_i != DWCi_GetProfileIDFromList(j))
                continue;
            if (DWCi_Acc_GetFlagDataTypeThunk(&friendList[i]) == 2 && DWCi_Acc_GetFlagDataTypeThunk(&friendList[j]) == 3)
                DWC_SetGsProfileId(&friendList[i], pid_i);
            if (DWCi_IsBuddyFriendData(&friendList[j])) {
                DWCi_SetBuddyFriendData(&friendList[i]);
                if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                    DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[i], 1);
            }
            DWCi_DeleteFriendFromList(friendList, j, i);
            stpFriendCnt->changed = 1;
        }
    }
    return index;
}


/*
 * sdk:      DWCi_GPSendBuddyRequest (dwc_friend.o)
 */
int DWCi_GPSendBuddyRequest(int profileID)
{
    int gpResult;

    gpResult = gpSendBuddyRequestA(stpFriendCnt->connection, profileID, gDwcFriendGetInfoFlags);
    DWCi_HandleGPError(gpResult);
    return gpResult;
}


/*
 * closed (2026-10-01, ov SDK wave 2): the dwc_friend.o statics (s_bNeedCloseStatsConnection +0,
 *   stpFriendCnt +0xc) are TU `static ... = 0;` as in DWCi_FriendProcess, not one extern
 *   struct; the anchor web now schedules the prologue like the image.
 *
 * sdk:      DWCi_GetFriendBuddyStatus (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int DWCi_GetFriendBuddyStatus(void *friendData, GPBuddyStatus *status)
{
	unsigned char ret = 0;
	int buddyIdx = 0;
	int profileid;
	if (stpFriendCnt == 0 || !DWCi_CheckLogin())
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
 * sdk:      DWCi_HandleGPError (dwc_friend.o)
 */
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


void DWCi_GPProfileSearchCallback(void **connection, void *argv, void *param)
{
    GPProfileSearchResponseArg *arg = argv;
    int i;
    int idx;
    int match_index = (int)param;

    if (arg->result != 0 || arg->numMatches == 0)
        goto err;
    if (DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[match_index]) == 0)
        goto err;
    if (stpFriendCnt->state != 1)
        return;

    for (i = 0; i < arg->numMatches; i++) {
        if (DWCi_RefreshFriendListForth(stpFriendCnt->friendList, match_index, arg->matches[i].profileID) != 0) {
            stpFriendCnt->sendIdx++;
            stpFriendCnt->phase = 1;
            arg->more = 0x601;
            return;
        }
    }

    for (i = 0; i < arg->numMatches; i++) {
        DWCi_HandleGPError(gpGetBuddyIndex(connection, arg->matches[i].profileID, &idx));
        if (idx == -1) {
            DWCi_GPSendBuddyRequest(arg->matches[i].profileID);
            DWCi_SetSentBuddyReqFlag(&stpFriendCnt->friendList[match_index], 1);
        } else {
            DWC_SetGsProfileId(&stpFriendCnt->friendList[match_index], arg->matches[0].profileID);
            DWCi_SetBuddyFriendData(&stpFriendCnt->friendList[match_index]);
            DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[match_index], 1);
            if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[match_index]) != 0)
                DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[match_index], 1);
            DWCi_CallBuddyFriendCallback(match_index);
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
        DWCi_HandleGPError(arg->result);
        return;
    }
    if (stpFriendCnt->state != 1 && DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[match_index]) != 0)
        return;
    stpFriendCnt->sendIdx++;
    stpFriendCnt->phase = 1;
}


static void DWCi_GPGetInfoCallback_RecvBuddyRequest(void **connection, void *argv, void *param)
{
    GpBuddyRequestArg *arg = argv;
    int i;
    int confirm = 0;
    int alreadyBuddy = 0;
    int index;
    unsigned int gamecode;
    char userName[21];
    char gamecode_str[5];

    if (arg->result != 0)
        return;

    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
        if (DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[i]) == 1) {
            DWC_LoginIdToUserName(DWCi_GetUserData(), &stpFriendCnt->friendList[i], (char *)userName);
            if (strcmp(userName, arg->userName) != 0)
                continue;
            if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                alreadyBuddy = 1;
            gpAuthBuddyRequest(connection, arg->profile);
            DWC_SetGsProfileId(&stpFriendCnt->friendList[i], arg->profile);
            confirm = 1;
        } else if (DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[i]) == 3 || DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[i]) == 2) {
            gamecode = DWCi_GetUserData()->gamecode;
            OS_SNPrintf(gamecode_str, 5, gDwcFriendKeyFormat, (gamecode >> 24) & 0xff, (gamecode >> 16) & 0xff, (gamecode >> 8) & 0xff, gamecode & 0xff);
            if (DWC_GetGsProfileId(DWCi_GetUserData(), &stpFriendCnt->friendList[i]) != arg->profile)
                continue;
            if (memcmp((unsigned char *)gamecode_str, (unsigned char *)arg->gamecode, 4) != 0)
                continue;
            if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                alreadyBuddy = 1;
            gpAuthBuddyRequest(connection, arg->profile);
            confirm = 1;
        }
    }

    if (confirm != 0) {
        DWCi_GPSendBuddyRequest(arg->profile);
        index = DWCi_RefreshFriendListAll(stpFriendCnt->friendList, stpFriendCnt->friendListLen, arg->profile);
        DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[index], 1);
        if (!DWC_IsBuddyFriendData(&stpFriendCnt->friendList[index]))
            return;
        DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[index], 1);
        if (alreadyBuddy)
            return;
        DWCi_CallBuddyFriendCallback(index);
        stpFriendCnt->changed = 1;
    } else {
        gpDenyBuddyRequest(connection, arg->profile);
    }
}


/*
 * sdk:      DWCi_GPGetInfoCallback_RecvAuthMessage (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * The object reads arg from r1 (GP callback: connection, arg, param); the DWARF
 * prototype lists only arg.
 */
void DWCi_GPGetInfoCallback_RecvAuthMessage(void **connection, void *argv, void *param)
{
    GpGetInfoResponseArg *arg = argv;
    char userName[21];
    int index;
    int i;
    int listChanged = 0;
    int alreadyBuddy = 0;

    if (arg->result != 0)
        return;
    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
        if (DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[i]) == 1) {
            DWC_LoginIdToUserName((void *)DWCi_GetUserData(), &stpFriendCnt->friendList[i], (char *)userName);
            if (strcmp(userName, arg->lastname) == 0) {
                DWC_SetGsProfileId(&stpFriendCnt->friendList[i], arg->profile);
                DWCi_SetBuddyFriendData(&stpFriendCnt->friendList[i]);
                listChanged = 1;
            }
        } else if (DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[i]) == 3
                   || DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[i]) == 2) {
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
    index = DWCi_RefreshFriendListAll(stpFriendCnt->friendList, stpFriendCnt->friendListLen, arg->profile);
    if (!alreadyBuddy) {
        DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[index], 1);
        if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[index]))
            DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[index], 1);
        DWCi_CallBuddyFriendCallback(index);
    }
    stpFriendCnt->changed = 1;
}


/*
 * The word at +0x20 of the block held at +0xc of the module state block.
 */
int DWCi_GetPersCallbackLevel(void)
{
    return stpFriendCnt->persCallbackLevel;
}


/*
 * Sets the word at +0x10 of the module state block to 1.
 */
void DWCi_BeginCloseStatsConnection(void)
{
    s_bReverseBuddiesBusy = 1;
}


/*
 * Clears the word at +0x10 of the module state block.
 */
void DWCi_EndCloseStatsConnection(void)
{
    s_bReverseBuddiesBusy = 0;
}


/*
 * sdk:      DWCi_GetReverseBuddiesCallback (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * The DWARF has the response argument alone; the object receives it in r1, so the
 * callback takes the connection first.
 */
void DWCi_GetReverseBuddiesCallback(void **connection, void *argv, void *param)
{
    GPGetReverseBuddiesListResponseArg *arg = argv;
    int i;
    int j;

    if (!DWCi_IsServerUpdating())
        return;
    if (stpFriendCnt->reversePids != 0) {
        DWC_Free(4, stpFriendCnt->reversePids, 0);
        stpFriendCnt->reversePids = 0;
    }
    if (arg->result != 0) {
        DWCi_EndUpdateServers();
        return;
    }
    for (i = 0; i < stpFriendCnt->friendListLen; i++) {
        if (DWCi_Acc_GetFlagDataTypeThunk(&stpFriendCnt->friendList[i]) == 3) {
            for (j = 0; j < arg->numOfUniqueMatchs; j++) {
                if (arg->matches[j].profile == DWC_GetGsProfileId(DWCi_GetUserData(), &stpFriendCnt->friendList[i])) {
                    if (!DWCi_IsReverseBuddyFriendData(&stpFriendCnt->friendList[i])) {
                        stpFriendCnt->changed = 1;
                        DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[i], 1);
                        if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                            DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[i], 1);
                    }
                    break;
                }
            }
            if (j == arg->numOfUniqueMatchs && DWCi_IsReverseBuddyFriendData(&stpFriendCnt->friendList[i]) == 1) {
                stpFriendCnt->changed = 1;
                DWCi_SetReverseBuddyFlag(&stpFriendCnt->friendList[i], 0);
            }
            if (DWC_IsBuddyFriendData(&stpFriendCnt->friendList[i]))
                DWCi_SetExpIsBuddyFriendFlag(&stpFriendCnt->friendList[i], 1);
        }
    }
    DWCi_EndUpdateServers();
}
