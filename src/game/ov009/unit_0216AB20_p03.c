/*
 * file:     unit_0216AB20_p03.c
 * unit:     yes
 * function: func_0216B284, func_0216B354, func_0216B408, func_0216B634, func_0216B65C, func_0216B7E0
 * address:  0x0216B284
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
 *   func_02059F38  0x02059F38  arm
 *   func_0216BB98  0x0216BB98  arm  ov009
 *   func_0216BC84  0x0216BC84  arm  ov009
 *   func_0216C7E0  0x0216C7E0  arm  ov009
 *   func_0216CF1C  0x0216CF1C  arm  ov009
 *   func_0216BFB8  0x0216BFB8  arm  ov009
 *   g_021AA878  0x021AA878  data
 *   func_0216D138  0x0216D138  arm  ov009
 *   DWCi_IsError                     0x02059f38 arm
 *   DWCi_ClearGT2ConnectionList      0x0216bb98 arm
 *   DWCi_SetState                    0x0216bc84 arm
 *   DWCi_GetProfileIDFromList        0x02168ff0 arm
 *   gpIsBuddy                        0x021861a8 arm
 *   gpGetBuddyIndex                  0x02186108 arm
 *   gpGetBuddyStatus                 0x02185fd4 arm
 *   DWCi_IsLockedBuddyStatus         0x02176984 arm
 *   DWC_GetCommonValueString         0x021684cc arm
 *   strtoul                          0x02095eac arm
 *   DWCi_CustomCommonInit            0x0216c7e0 arm
 *   DWCi_ConnectToGameServerAsync    0x0216d27c arm
 *   DWCi_SetError                    0x02059f54 arm
 *   DWCi_GPSetServerStatus           0x0216f20c arm
 *   stLastSocketError                0x021aa878 data
 *   g_021A2028                       0x021a2028 data
 *   g_021A202C                       0x021a202c data
 *   DWCi_MatchedCallback             0x0216bfb8 arm
 *   DWC_CancelMatch              0x0216C858 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_0216F20C                0x0216F20C arm   ov009
 *   DWCi_NNFreeNegotiateList     0x02176B34 arm   ov009
 *   DWCi_ClearQR2Key             0x0216EC18 arm   ov009
 *   func_0217601C                0x0217601C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_0216F6C0                0x0216F6C0 arm   ov009
 *   func_02195DE4                0x02195DE4 arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_0216C230                0x0216C230 arm   ov009
 *   func_0216B994                0x0216B994 arm   ov009
 *   g_021AA8A0                   0x021AA8A0 data
 *   func_0216BA08  0x0216BA08  arm  ov009
 *   func_0216BEA4  0x0216BEA4  arm  ov009
 */
#include "../../matched/include/G_DwcGlobal.h"

struct DWCstGlobal;
struct GTI2Connection;
typedef struct DwcState {
	void *gt2Socket;
	unsigned char pad0a[0x10];
	int outSize;
	int inSize;
	unsigned char pad0[0x8];
	int state;
	unsigned char pad1[0x3c];
	int profileID;
	unsigned char pad2[0x8];
	void (*loginCallback)(int, int, void *);
	void *loginParam;
	void *updateCallback;
	void *updateParam;
	void *matchedCallback;
	void *matchedParam;
	unsigned char pad3[0x50];
	unsigned char updateBuf0[0x100];
	unsigned char updateBuf1[0x100];
} DwcState;

typedef struct DwcGlobal DwcGlobal;

typedef unsigned char u8;

struct DWCstDwcCnt
{
    u8 pad0[0x1c];
    void *gp;                                       /* +0x1c */
    u8 pad20[0x24 - 0x20];
    int state;                                      /* +0x24 */
    u8 pad28[0x80 - 0x28];
    void (*field80)(int, int, int, int, int, void *); /* +0x80 */
    void *field84;                                  /* +0x84 */
};

struct DWCstGlobal
{
    int lastSocketError;                            /* +0x00 */
    struct DWCstDwcCnt *pDwc;                       /* +0x04 */
};

typedef struct GPBuddyStatus_
{
    int profile;                                    /* +0x00 */
    int status;                                     /* +0x04 */
    char statusString[256];                         /* +0x08 */
    char locationString[256];                       /* +0x108 */
    unsigned int ip;                                /* +0x208 */
    int port;                                       /* +0x20c */
    int quietModeFlags;                             /* +0x210 */
} GPBuddyStatus;

struct GT2Socket { int pad; };

struct DWCControl {
    struct GT2Socket *socket;
    u8 pad0[0x24 - 0x4];
    int state;
    u8 pad1[0x2d - 0x28];
    u8 f2d;
    u8 pad2[0x64 - 0x2e];
    int myProfileID;
    u8 pad3[0xb05 - 0x68];
    u8 fb05;
};

struct DWCstNodeInfo {
    int profileID;
    u8 pad0[0x16 - 0x4];
    u8 aid;
};

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_02059F38(void);
extern void func_0216BB98(void);
extern void func_0216BC84(int state);
extern void func_0216C7E0(unsigned char matchType);
extern void func_0216CF1C(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
extern void func_0216BFB8(int error, int cancel, int self, int isServer, int index);
extern void func_0216D138(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
extern int DWCi_IsError(void);
extern void DWCi_ClearGT2ConnectionList(void);
extern void DWCi_SetState(int state);
extern int DWCi_GetProfileIDFromList(int index);
extern int gpIsBuddy(void **connection, int profile);
extern int gpGetBuddyIndex(void **connection, int profile, int *index);
extern int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status);
extern int DWCi_IsLockedBuddyStatus(GPBuddyStatus *status);
extern int DWC_GetCommonValueString(char *key, char *value, char *string,
                                    char separator);
extern unsigned long strtoul(const char *nptr, char **endptr, int base);
extern void DWCi_CustomCommonInit(u8 matchType);
extern void DWCi_ConnectToGameServerAsync(
    int topology, int serverPid,
    void (*matchedCallback)(int, int, int, int, int, void *),
    void *matchedParam, void (*newClientCallback)(int, void *),
    void *newClientParam, int (*attemptCallback)(unsigned char *, void *),
    unsigned char *connectionUserData, void *attemptParam);
extern void DWCi_SetError(int error, int errorCode);
extern int DWCi_GPSetServerStatus(int matchType);
extern void DWCi_MatchedCallback(int error, int cancel, int self, int isServer,
                                 int index, void *param);
extern int DWC_CancelMatch(void);
extern int func_0217603C(void);
extern int func_0216F20C(int status);
extern void DWCi_NNFreeNegotiateList(void);
extern void DWCi_ClearQR2Key(void);
extern void func_0217601C(void);
extern void func_02175F4C(int state);
extern void func_0216F6C0(void);
extern void func_02195DE4(int *p);
extern char *func_0217637C(int index);
extern void func_0216C230(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
extern int func_0216B994(void);
int func_0216B284(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int func_0216B354(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int DWC_ConnectToGameServerAsync( int topology, int serverIndex, void (*matchedCallback)(int, int, int, int, int, void *), void *matchedParam, void (*newClientCallback)(int, void *), void *newClientParam, int (*attemptCallback)(unsigned char *, void *), unsigned char *connectionUserData, void *attemptParam);
int func_0216B634(int a, int b);
int func_0216B65C(void);
int func_0216B7E0(void *p);
extern struct DwcGlobal g_021AA878;
extern struct DWCstGlobal stLastSocketError;
extern char g_021A2028[];
extern char g_021A202C[];
extern void *g_021AA8A0[32];


/*
 * sdk:      DWC_ConnectToAnybodyAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B284(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (func_02059F38() || ((DwcState *)g_021AA878.st)->state != 3)
		return 0;
	func_0216BB98();
	((DwcState *)g_021AA878.st)->matchedCallback = matchedCallback;
	((DwcState *)g_021AA878.st)->matchedParam = matchedParam;
	func_0216BC84(4);
	func_0216C7E0(0);
	func_0216CF1C(topology, maxEntry - 1, addFilter, func_0216BFB8, 0, newClientCallback, newClientParam, evalCallback, evalParam, attemptCallback, connectionUserData, attemptParam);
	return 1;
}


/*
 * sdk:      DWC_SetupGameServer (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B354(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (func_02059F38() || ((DwcState *)g_021AA878.st)->state != 3)
		return 0;
	func_0216BB98();
	((DwcState *)g_021AA878.st)->matchedCallback = matchedCallback;
	((DwcState *)g_021AA878.st)->matchedParam = matchedParam;
	func_0216BC84(4);
	func_0216C7E0(2);
	func_0216D138(topology, (unsigned char)(maxEntry - 1), (int)func_0216BFB8, 0, (int)newClientCallback, (int)newClientParam, (int)attemptCallback, (int)connectionUserData, (int)attemptParam);
	return 1;
}


int DWC_ConnectToGameServerAsync(
    int topology, int serverIndex,
    void (*matchedCallback)(int, int, int, int, int, void *),
    void *matchedParam, void (*newClientCallback)(int, void *),
    void *newClientParam, int (*attemptCallback)(unsigned char *, void *),
    unsigned char *connectionUserData, void *attemptParam)
{
    unsigned char numEntry;
    unsigned char maxEntry;
    GPBuddyStatus status;
    int buddyIdx;
    char valueStr[4];
    int dwcError;

    buddyIdx = -1;

    if (DWCi_IsError() || stLastSocketError.pDwc->state != 3)
        return 0;

    DWCi_ClearGT2ConnectionList();
    stLastSocketError.pDwc->field80 = matchedCallback;
    stLastSocketError.pDwc->field84 = matchedParam;
    DWCi_SetState(4);

    dwcError = DWCi_GetProfileIDFromList(serverIndex);
    if (dwcError == 0 || !gpIsBuddy(&stLastSocketError.pDwc->gp, dwcError))
    {
        dwcError = 0xb;
        goto error;
    }

    gpGetBuddyIndex(&stLastSocketError.pDwc->gp, dwcError, &buddyIdx);
    gpGetBuddyStatus(&stLastSocketError.pDwc->gp, buddyIdx, &status);
    if (status.status != 6)
    {
        dwcError = 0xb;
        goto error;
    }

    valueStr[0] = 0x30;
    if (DWCi_IsLockedBuddyStatus(&status))
    {
        dwcError = 0x15;
        goto error;
    }

    DWC_GetCommonValueString(g_021A2028, valueStr, status.statusString, 0x2f);
    maxEntry = (unsigned char)strtoul(valueStr, 0, 10);
    DWC_GetCommonValueString(g_021A202C, valueStr, status.statusString, 0x2f);
    numEntry = (unsigned char)strtoul(valueStr, 0, 10);
    if (numEntry == maxEntry)
    {
        dwcError = 0xc;
        goto error;
    }

    DWCi_CustomCommonInit(3);
    DWCi_ConnectToGameServerAsync(topology, dwcError, DWCi_MatchedCallback, 0,
                                  newClientCallback, newClientParam,
                                  attemptCallback, connectionUserData,
                                  attemptParam);
    return 1;

error:
    DWCi_SetError(dwcError, 0);
    stLastSocketError.pDwc->field80(dwcError, 0, 1, 0, 0,
                                    stLastSocketError.pDwc->field84);
    if (stLastSocketError.pDwc != 0 && stLastSocketError.pDwc->state == 4)
    {
        DWCi_SetState(3);
        DWCi_GPSetServerStatus(1);
    }
    return 1;
}


/*
 * Stores a at +0x88 and b at +0x8c of the current object; 0 when the block
 * is absent, 1 when it was written.
 */
int func_0216B634(int a, int b)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    if (p == 0) return 0;
    *(int *)(p + 0x88) = a;
    p = *(char **)(((char *)&g_021AA878) + 4);
    *(int *)(p + 0x8c) = b;
    return 1;
}


/*
 * sdk:      DWC_CloseAllConnectionsHard (libdwcmatch.TWL.HYB.a dwc_main.o)
 */
int func_0216B65C(void)
{
    struct DWCstNodeInfo *pNodeInfo;
    int i;
    int anyGT2ConnectionExist = 0;

    ((struct DWCControl *)g_021AA878.st)->fb05 = 1;
    if (DWC_CancelMatch())
        return 1;
    if (g_021AA878.st == 0 || func_02059F38() ||
        (((struct DWCControl *)g_021AA878.st)->state != 4 && ((struct DWCControl *)g_021AA878.st)->state != 5))
        return -1;
    for (i = 0; i < 32; i++) {
        if (g_021AA8A0[i] != 0) {
            anyGT2ConnectionExist = 1;
            break;
        }
    }
    if (anyGT2ConnectionExist == 0) {
        func_0217603C();
        func_0216F20C(1);
        DWCi_NNFreeNegotiateList();
        func_0216BC84(3);
        DWCi_ClearQR2Key();
        func_0217601C();
        func_02175F4C(0);
        func_0216F6C0();
        return 1;
    }
    ((struct DWCControl *)g_021AA878.st)->f2d = 1;
    func_02195DE4((int *)((struct DWCControl *)g_021AA878.st)->socket);
    while (func_0217603C() > 1) {
        for (i = 0; i < func_0217603C(); i++) {
            pNodeInfo = (struct DWCstNodeInfo *)func_0217637C(i);
            if (pNodeInfo->profileID != ((struct DWCControl *)g_021AA878.st)->myProfileID)
                func_0216C230(0, 0, 1, pNodeInfo->aid);
        }
    }
    ((struct DWCControl *)g_021AA878.st)->f2d = 0;
    func_0217601C();
    func_02175F4C(0);
    func_0216F6C0();
    if (func_0216B994() != 3) {
        DWCi_NNFreeNegotiateList();
        func_0216BC84(3);
        DWCi_ClearQR2Key();
    }
    return 0;
}


/*
 * Returns -3 when func_0216BA08 rejects the pointer, else the func_0216BEA4 result.
 */
int func_0216B7E0(void *p)
{
    int func_0216BA08(void);
    int func_0216BEA4(void *);
    if (func_0216BA08() == 0) return -3;
    return func_0216BEA4(p);
}
