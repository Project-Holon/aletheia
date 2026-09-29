/*
 * function: DWC_ConnectToGameServerAsync
 * address:  0x0216B408
 * packet:   pkt_ov009_0216B408
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ConnectToGameServerAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
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
 */

typedef unsigned char u8;

struct DWCstGlobal;

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

extern struct DWCstGlobal stLastSocketError;

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
extern char g_021A2028[];
extern char g_021A202C[];
extern void DWCi_MatchedCallback(int error, int cancel, int self, int isServer,
                                 int index, void *param);

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
