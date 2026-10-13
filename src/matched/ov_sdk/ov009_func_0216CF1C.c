/*
 * function: DWCi_ConnectToAnybodyAsync
 * address:  0x0216CF1C
 * packet:   pkt_ov009_0216CF1C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ConnectToAnybodyAsync (dwc_match.o)
 *
 * symbols:
 *   DWC_Free                0x0205A1B0  arm
 *   DWCi_GetDefaultMatchFilter           0x0216FAD4  arm  ov009
 *   func_0209477C           0x0209477C  arm
 *   DWC_Alloc               0x0205A16C  arm
 *   DWCi_StopMatch           0x0216EB68  arm  ov009
 *   MI_CpuCopy8             0x02082D44  arm
 *   DWCi_SetMatchCommonParam           0x0216F5FC  arm  ov009
 *   func_02175F3C           0x02175F3C  arm  ov009
 *   DWCi_SetConnectionAttemptParam           0x02175560  arm  ov009
 *   DWCi_SetMatchStatus           0x02175F4C  arm  ov009
 *   func_0219EC74           0x0219EC74  arm  ov009
 *   DWCi_HandleSBError           0x02173D9C  arm  ov009
 *   DWCi_GPSetServerStatus           0x0216F20C  arm  ov009
 *   DWCi_QR2Startup           0x0216CD8C  arm  ov009
 *   func_0219B490           0x0219B490  arm  ov009
 *   func_0216F770           0x0216F770  arm  ov009
 *   DWCi_SBCallback           0x02174058  arm  ov009
 *   g_021AAA20              0x021AAA20  data
 *   g_021A2044              0x021A2044  data
 */

#include "../include/G_NNThinkGlobal.h"

extern void DWC_Free(int name, void *ptr, unsigned long size);
extern int DWCi_GetDefaultMatchFilter(char *filter, int profileID, unsigned char numEntry, unsigned char matchType, unsigned char hostState);
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern void *DWC_Alloc(int name, unsigned long size);
extern void DWCi_StopMatch(int error, int errorCode);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void DWCi_SetMatchCommonParam(unsigned char matchType, unsigned char numEntry, void *callback, void *param);
extern int func_02175F3C(void);
extern void DWCi_SetConnectionAttemptParam(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern void DWCi_SetMatchStatus(int state);
extern void *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, void *callback, void *instance);
extern int DWCi_HandleSBError(int error);
extern int DWCi_GPSetServerStatus(int status);
extern int DWCi_QR2Startup(int profileID);
extern void func_0219B490(void *qrec);
extern int func_0216F770(int profileID);
extern void DWCi_SBCallback(void *sb, int reason, void *server);

extern struct NNThinkGlobal g_021AAA20;
extern char g_021A2044[];

void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam)
{
    int sbError;
    unsigned long addFilterLenMax;
    char filter[511];

    if (g_021AAA20.addFilter != 0) {
        DWC_Free(4, g_021AAA20.addFilter, 0);
        g_021AAA20.addFilter = 0;
    }
    if (addFilter != 0) {
        addFilterLenMax = 0x1ff - DWCi_GetDefaultMatchFilter(filter, -1, 32, 3, 3) - func_0209477C((const u8 *)g_021A2044);
        g_021AAA20.addFilter = DWC_Alloc(4, addFilterLenMax);
        if (g_021AAA20.addFilter == 0) {
            DWCi_StopMatch(9, -80001);
            return;
        }
        MI_CpuCopy8(addFilter, g_021AAA20.addFilter, addFilterLenMax);
        (g_021AAA20.addFilter + addFilterLenMax)[-1] = 0;
    }
    DWCi_SetMatchCommonParam(0, numEntry, matchedCallback, matchedParam);
    *(void **)(func_02175F3C() + 0x778) = newClientCallback;
    *(void **)(func_02175F3C() + 0x77c) = newClientParam;
    *(void **)(func_02175F3C() + 0x780) = evalCallback;
    *(void **)(func_02175F3C() + 0x784) = evalParam;
    *(int *)(func_02175F3C() + 0x7b0) = topology;
    DWCi_SetConnectionAttemptParam(attemptCallback, connectionUserData, attemptParam);
    DWCi_SetMatchStatus(0x16);
    if (*(void **)(func_02175F3C() + 0x5e0) == 0) {
        *(void **)(func_02175F3C() + 0x5e0) = func_0219EC74(*(char **)(func_02175F3C() + 0x684), *(char **)(func_02175F3C() + 0x684), *(char **)(func_02175F3C() + 0x688), 0, 20, 1, 0, DWCi_SBCallback, 0);
    }
    if (*(void **)(func_02175F3C() + 0x5e0) == 0) {
        if (DWCi_HandleSBError(5))
            return;
    }
    DWCi_GPSetServerStatus(3);
    if (*(void **)(func_02175F3C() + 0x10) == 0) {
        if (DWCi_QR2Startup(*(int *)(func_02175F3C() + 0x678)))
            return;
    } else {
        func_0219B490(*(void **)(func_02175F3C() + 0x10));
    }
    sbError = func_0216F770(*(int *)(func_02175F3C() + 0x678));
    DWCi_HandleSBError(sbError);
}
