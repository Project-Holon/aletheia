#ifndef ALETHEIA_OV009_DWC_LOGIN_TYPES_H
#define ALETHEIA_OV009_DWC_LOGIN_TYPES_H
/*
 * DWC login module (ov009, dwc_login.o): the login control block that the
 * global at 0x021AA874 points to, plus the prototypes dwc_login shares.
 * Field offsets checked against every view the parts used.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct DWCstAccLoginId {
    u32 w0;
    u32 w1;
    u32 w2;
} DWCstAccLoginId;

typedef struct DWCstAccUserData {
    u32 size;                       /* +0x00 */
    DWCstAccLoginId pseudo;         /* +0x04 */
    DWCstAccLoginId authentic;      /* +0x10 */
    int gs_profile_id;              /* +0x1c */
    u32 pad20;                      /* +0x20 */
    u32 gamecode;                   /* +0x24 */
} DWCstAccUserData;

/* GameSpy GP callback: (connection, response argument, user param). */
typedef void (*GPCallback)(void **pconnection, void *arg, void *param);

typedef struct GPConnectResponseArg {
    int result;                     /* +0x00 */
    int profile;                    /* +0x04 */
    char uniquenick[21];            /* +0x08 */
} GPConnectResponseArg;

typedef struct GPGetInfoResponseArg {
    int result;                     /* +0x00 */
    int profile;                    /* +0x04 */
    char pad8[0x86];
    char nick[21];                  /* +0x8e */
} GPGetInfoResponseArg;

#pragma pack(4)
typedef struct DWCstLoginControl {
    void **connection;              /* +0x00 */
    int state;                      /* +0x04 */
    int productID;                  /* +0x08 */
    u32 gamecode;                   /* +0x0c */
    u16 *playerName;                /* +0x10 */
    void (*callback)(int error, int profileID, void *param); /* +0x14 */
    void *param;                    /* +0x18 */
    DWCstAccUserData *userdata;     /* +0x1c */
    u8 pad20[0x10];                 /* +0x20 */
    int connectFlag;                /* +0x30 */
    u64 tick;                       /* +0x34 */
    DWCstAccLoginId loginId;        /* +0x3c */
    char authToken[0x100];          /* +0x48 */
    char partnerChallenge[0x100];   /* +0x148 */
    char username[9];               /* +0x248 */
    char gsbrcd[9];                 /* +0x251 */
    u8 pad25a[6];                   /* +0x25a */
} DWCstLoginControl;
#pragma pack()

extern DWCstLoginControl *gDwcLoginControl;

/* callees */
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern int DWCi_Auth_IsConsoleUserIdAuthentic(void);
extern int DWCi_IsError(void);
extern int func_02185948(void **connection);
extern u64 OS_GetTick(void);
extern void DWCi_SetError(int error, int errorCode);
extern int DWCi_Auth_IsFinished(void);
extern void DWCi_Auth_AbortAuthentication(void);
extern void DWCi_Auth_ShutdownAuthentication(void);
extern void *DWCi_Np_GetConsoleIdPrefix(void);
extern long long DWCi_Np_GetConsoleId(void);
extern int OS_SNPrintf(char *dst, u32 len, const char *fmt, ...);
extern int func_02185CB4(void **connection, int info, char *value);
extern u64 DWCi_Auth_GetConsoleUserId(void);
extern void DWCi_Acc_U64ToString32(u64 num, int bitnum, char *result);
extern char *DWCi_Np_GetAppGameName(void);
extern int DWCi_GPSetServerStatus(int matchType);
extern int DWCi_GT2Startup(void);
extern void DWCi_SetMatchmakeProfileId(int profileID);
extern void DWCi_RegisterMatchmakeKeys(void);
extern int gpGetInfo(void **connection, int profile, int checkCache, int blocking, GPCallback callback, void *param);
extern int gpConnectPreAuthenticatedA(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, GPCallback callback, void *param);
extern int func_020596C8(DWCstAccUserData *userdata);
extern void DWCi_Acc_LoginIdToUserName(DWCstAccLoginId *loginid, u32 gamecode, char *username);
extern u64 func_02059084(DWCstAccLoginId *loginid);
extern int DWCi_Acc_IsValidLoginId(DWCstAccLoginId *loginid);
extern int DWCi_Acc_CheckConsoleUserId(DWCstAccLoginId *loginid);
extern void DWCi_Acc_CreateTempLoginId(DWCstAccLoginId *loginid);
extern u64 OS_GetTick(void);
extern void DWCi_Acc_SetPlayerId(DWCstAccLoginId *loginid, u32 v);
extern int DWCi_Auth_StartAuthentication(u16 *ingamesn, char *gsbrcd, u64 userid, void *(*allocator)(int, u32), void (*deallocator)(int, void *, u32));
extern void *DWC_Alloc(int name, u32 size);
extern void DWC_Free(int name, void *ptr, u32 size);
extern void DWCi_Auth_ProcessAuthentication(void);
extern int DWCi_Auth_IsSucceeded(void);
extern void DWCi_Auth_GetGameSpyToken(char *authtoken, char *partnerchallenge);
extern void func_020590C8(DWCstAccLoginId *loginid, u64 userid);
extern int DWCi_Auth_GetErrorCode(void);
extern void func_02185ACC(void **connection);
extern int strcmp(const char *a, const char *b);
extern void DWCi_Acc_SetLoginIdToUserData(DWCstAccUserData *userdata, DWCstAccLoginId *loginid, int gs_profile_id);
extern int func_02186618(void **connection, char *loginTicket);

/* this unit */
extern void DWCi_LoginInit(DWCstLoginControl *logcnt, DWCstAccUserData *userdata, void **pGpObj, int productID, u32 gamecode, u16 *playerName, void (*callback)(int, int, void *), void *param);
extern int DWCi_LoginAsync(void);
extern void DWCi_LoginProcess(void);
extern DWCstAccUserData *DWCi_GetUserData(void);
extern void DWCi_StopLogin(int error, int errorCode);
extern void DWCi_ShutdownLogin(void);
extern void DWCi_CloseLogin(void);
extern void DWCi_GPConnectCallback(void **pconnection, void *arg, void *param);
extern void DWCi_GPConnect(GPCallback callback, int next_state);
extern int DWCi_RemoteLogin(void);
extern void DWCi_RemoteLoginProcess(void);
extern void DWCi_GPGetInfoCallback(void **pconnection, void *arg, void *param);
extern int DWCi_CheckLogin(void);
extern int DWCi_GetAuthInfo(char **authToken, char **partnerChallenge);
extern int DWCi_GetLoginTicket(char *loginTicket);

#endif
