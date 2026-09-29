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
 *   func_0216FAD4           0x0216FAD4  arm  ov009
 *   func_0209477C           0x0209477C  arm
 *   DWC_Alloc               0x0205A16C  arm
 *   func_0216EB68           0x0216EB68  arm  ov009
 *   MI_CpuCopy8             0x02082D44  arm
 *   func_0216F5FC           0x0216F5FC  arm  ov009
 *   func_02175F3C           0x02175F3C  arm  ov009
 *   func_02175560           0x02175560  arm  ov009
 *   func_02175F4C           0x02175F4C  arm  ov009
 *   func_0219EC74           0x0219EC74  arm  ov009
 *   func_02173D9C           0x02173D9C  arm  ov009
 *   func_0216F20C           0x0216F20C  arm  ov009
 *   func_0216CD8C           0x0216CD8C  arm  ov009
 *   func_0219B490           0x0219B490  arm  ov009
 *   func_0216F770           0x0216F770  arm  ov009
 *   func_02174058           0x02174058  arm  ov009
 *   g_021AAA20              0x021AAA20  data
 *   g_021A2044              0x021A2044  data
 */

extern void DWC_Free(int name, void *ptr, unsigned long size);
extern int func_0216FAD4(char *filter, int profileID, unsigned char numEntry, unsigned char matchType, unsigned char hostState);
extern int func_0209477C(const char *s);
extern void *DWC_Alloc(int name, unsigned long size);
extern void func_0216EB68(int error, int errorCode);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void func_0216F5FC(unsigned char matchType, unsigned char numEntry, void *callback, void *param);
extern char *func_02175F3C(void);
extern void func_02175560(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern void func_02175F4C(int state);
extern void *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, void *callback, void *instance);
extern int func_02173D9C(int error);
extern int func_0216F20C(int matchType);
extern int func_0216CD8C(int profileID);
extern void func_0219B490(void *qrec);
extern int func_0216F770(int profileID);
extern void func_02174058(void *sb, int reason, void *server);

typedef struct {
    int pad0[3];
    char *filter;
} MatchGlobal;

extern MatchGlobal g_021AAA20;
extern char g_021A2044[];

void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam)
{
    int sbError;
    unsigned long addFilterLenMax;
    char filter[511];

    if (g_021AAA20.filter != 0) {
        DWC_Free(4, g_021AAA20.filter, 0);
        g_021AAA20.filter = 0;
    }
    if (addFilter != 0) {
        addFilterLenMax = 0x1ff - func_0216FAD4(filter, -1, 32, 3, 3) - func_0209477C(g_021A2044);
        g_021AAA20.filter = DWC_Alloc(4, addFilterLenMax);
        if (g_021AAA20.filter == 0) {
            func_0216EB68(9, -80001);
            return;
        }
        MI_CpuCopy8(addFilter, g_021AAA20.filter, addFilterLenMax);
        (g_021AAA20.filter + addFilterLenMax)[-1] = 0;
    }
    func_0216F5FC(0, numEntry, matchedCallback, matchedParam);
    *(void **)(func_02175F3C() + 0x778) = newClientCallback;
    *(void **)(func_02175F3C() + 0x77c) = newClientParam;
    *(void **)(func_02175F3C() + 0x780) = evalCallback;
    *(void **)(func_02175F3C() + 0x784) = evalParam;
    *(int *)(func_02175F3C() + 0x7b0) = topology;
    func_02175560(attemptCallback, connectionUserData, attemptParam);
    func_02175F4C(0x16);
    if (*(void **)(func_02175F3C() + 0x5e0) == 0) {
        *(void **)(func_02175F3C() + 0x5e0) = func_0219EC74(*(char **)(func_02175F3C() + 0x684), *(char **)(func_02175F3C() + 0x684), *(char **)(func_02175F3C() + 0x688), 0, 20, 1, 0, func_02174058, 0);
    }
    if (*(void **)(func_02175F3C() + 0x5e0) == 0) {
        if (func_02173D9C(5))
            return;
    }
    func_0216F20C(3);
    if (*(void **)(func_02175F3C() + 0x10) == 0) {
        if (func_0216CD8C(*(int *)(func_02175F3C() + 0x678)))
            return;
    } else {
        func_0219B490(*(void **)(func_02175F3C() + 0x10));
    }
    sbError = func_0216F770(*(int *)(func_02175F3C() + 0x678));
    func_02173D9C(sbError);
}
