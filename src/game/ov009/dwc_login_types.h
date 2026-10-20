#ifndef ALETHEIA_OV009_DWC_LOGIN_TYPES_H
#define ALETHEIA_OV009_DWC_LOGIN_TYPES_H
/*
 * DWC login module (ov009, dwc_login.o): the login control block that the
 * global at 0x021AA874 points to, plus the prototypes dwc_login shares.
 * Field offsets checked against every view the parts used.
 */

#include "../types.h"
#include "../ov009/gpi_types.h"
#include "../arm9/dwc_account.h"

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
extern int gpProcess(void **connection);
extern u64 OS_GetTick(void);
extern void DWCi_SetError(int error, int errorCode);
extern int DWCi_Auth_IsFinished(void);
extern void DWCi_Auth_AbortAuthentication(void);
extern void DWCi_Auth_ShutdownAuthentication(void);
extern void *DWCi_Np_GetConsoleIdPrefix(void);
extern long long DWCi_Np_GetConsoleId(void);
extern int OS_SNPrintf(char *dst, u32 len, const char *fmt, ...);
extern int gpSetInfosA(void **connection, int info, char *value);
extern u64 DWCi_Auth_GetConsoleUserId(void);
extern char *DWCi_Np_GetAppGameName(void);
extern int DWCi_GPSetServerStatus(int matchType);
extern int DWCi_GT2Startup(void);
extern void DWCi_SetMatchmakeProfileId(int profileID);
extern void DWCi_RegisterMatchmakeKeys(void);
extern int gpGetInfo(void **connection, int profile, int checkCache, int blocking, GPCallback callback, void *param);
extern int gpConnectPreAuthenticatedA(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, GPCallback callback, void *param);
extern u64 OS_GetTick(void);
extern void DWCi_Auth_ProcessAuthentication(void);
extern int DWCi_Auth_IsSucceeded(void);
extern void DWCi_Auth_GetGameSpyToken(char *authtoken, char *partnerchallenge);
extern int DWCi_Auth_GetErrorCode(void);
extern void gpDisconnect(void **connection);
extern int strcmp(const char *a, const char *b);
extern int gpGetLoginTicket(void **connection, char *loginTicket);

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
