#ifndef ALETHEIA_OV009_DWC_LOGIN_TYPES_H
#define ALETHEIA_OV009_DWC_LOGIN_TYPES_H
/*
 * DWC login module (ov009, dwc_login.o): the login control block that the
 * global at 0x021AA874 points to, plus the prototypes unit_0216A1F4 shares.
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

extern DWCstLoginControl *g_021AA874;

/* callees */
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern int func_02178F30(void);
extern int func_02059F38(void);
extern int func_02185948(void **connection);
extern u64 func_020870D0(void);
extern void func_02059F54(int error, int errorCode);
extern int func_02178E70(void);
extern void DWCi_Auth_AbortAuthentication(void);
extern void DWCi_Auth_ShutdownAuthentication(void);
extern void *DWCi_Np_GetConsoleIdPrefix(void);
extern long long func_02167E88(void);
extern int func_02084F80(char *dst, u32 len, const char *fmt, ...);
extern int func_02185CB4(void **connection, int info, char *value);
extern u64 func_02178F00(void);
extern void func_02059408(u64 num, int bitnum, char *result);
extern char *func_02167EA0(void);
extern int func_0216F20C(int matchType);
extern int DWCi_GT2Startup(void);
extern void func_02176AA8(int profileID);
extern void func_02176ABC(void);
extern int func_02185BD8(void **connection, int profile, int checkCache, int blocking, GPCallback callback, void *param);
extern int func_021859C0(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, GPCallback callback, void *param);
extern int func_020596C8(DWCstAccUserData *userdata);
extern void func_02059474(DWCstAccLoginId *loginid, u32 gamecode, char *username);
extern u64 func_02059084(DWCstAccLoginId *loginid);
extern int func_020596B0(DWCstAccLoginId *loginid);
extern int func_02059644(DWCstAccLoginId *loginid);
extern void func_02059588(DWCstAccLoginId *loginid);
extern u64 OS_GetTick(void);
extern void DWCi_Acc_SetPlayerId(DWCstAccLoginId *loginid, u32 v);
extern int func_02178D14(u16 *ingamesn, char *gsbrcd, u64 userid, void *(*allocator)(u32, long), void (*deallocator)(u32, void *, long));
extern void *func_0205A16C(u32 size, long align);
extern void func_0205A1B0(u32 name, void *ptr, long align);
extern void func_02178DB4(void);
extern int func_02178E80(void);
extern void func_02178EA0(char *authtoken, char *partnerchallenge);
extern void func_020590C8(DWCstAccLoginId *loginid, u64 userid);
extern int func_02178E90(void);
extern void func_02185ACC(void **connection);
extern int strcmp(const char *a, const char *b);
extern void func_020597F0(DWCstAccUserData *userdata, DWCstAccLoginId *loginid, int gs_profile_id);
extern int func_02186618(void **connection, char *loginTicket);

/* this unit */
extern void func_0216A1F4(DWCstLoginControl *logcnt, DWCstAccUserData *userdata, void **pGpObj, int productID, u32 gamecode, u16 *playerName, void (*callback)(int, int, void *), void *param);
extern int func_0216A278(void);
extern void func_0216A2B0(void);
extern DWCstAccUserData *func_0216A39C(void);
extern void func_0216A3B8(int error, int errorCode);
extern void func_0216A404(void);
extern void func_0216A42C(void);
extern int func_0216A460(int result);
extern void func_0216A4D4(void **pconnection, void *arg, void *param);
extern void func_0216A68C(GPCallback callback, int next_state);
extern int func_0216A6F4(void);
extern void func_0216A838(void);
extern void func_0216A8F4(void **pconnection, void *arg, void *param);
extern int func_0216AA70(void);
extern int func_0216AA9C(char **authToken, char **partnerChallenge);
extern int func_0216AAE0(char *loginTicket);

#endif
