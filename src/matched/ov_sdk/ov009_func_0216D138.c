/*
 * function: DWCi_SetupGameServer
 * address:  0x0216D138
 * packet:   pkt_0216D138
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_SetupGameServer (dwc_match.o): configure the match block (getter
 * func_02175F3C), start the game server, and when no server block exists yet
 * build one through ServerBrowserNewA with the +0x684/+0x684/+0x688 fields of
 * four getter results.
 *
 * symbols:
 *   DWCi_SetMatchCommonParam  0x0216F5FC  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_SetConnectionAttemptParam  0x02175560  arm  ov009
 *   DWCi_SetMatchStatus  0x02175F4C  arm  ov009
 *   DWCi_GPSetServerStatus  0x0216F20C  arm  ov009
 *   func_02173D28  0x02173D28  arm  ov009
 *   func_02175F84  0x02175F84  arm  ov009
 *   DWCi_QR2Startup  0x0216CD8C  arm  ov009
 *   func_02175530  0x02175530  arm  ov009
 *   ServerBrowserNewA  0x0219EC74  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 *   func_0216F770  0x0216F770  arm  ov009
 *   DWCi_HandleSBError  0x02173D9C  arm  ov009
 */

extern void DWCi_SetMatchCommonParam(int a0);
extern int func_02175F3C(void);
extern void DWCi_SetConnectionAttemptParam(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern void DWCi_SetMatchStatus(int a0);
extern int DWCi_GPSetServerStatus(int status);
extern int  func_02173D28(void);
extern void func_02175F84(int a0);
extern int  DWCi_QR2Startup(int a0);
extern int  func_02175530(void);
extern int  ServerBrowserNewA(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
extern void func_0219B490(int a0);
extern int func_0216F770(int profileID);
extern void DWCi_HandleSBError(void);

void DWCi_SetupGameServer(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
{
    char *a, *b, *c, *d;

    DWCi_SetMatchCommonParam(2);
    *(int *)(func_02175F3C() + 0x778) = p4;
    *(int *)(func_02175F3C() + 0x77c) = p5;
    *(int *)(func_02175F3C() + 0x7b0) = p0;
    DWCi_SetConnectionAttemptParam((void *)p6, (unsigned char *)p7, (void *)p8);
    DWCi_SetMatchStatus(0x16);
    DWCi_GPSetServerStatus(6);
    if (func_02173D28() != 0)
        return;
    func_02175F84(2);
    *(int *)(func_02175F3C() + 0x7c4) = 1;
    if (*(int *)(func_02175F3C() + 0x10) == 0) {
        if (DWCi_QR2Startup(*(int *)(func_02175F3C() + 0x678)) != 0)
            return;
    }
    a = (char *)func_02175F3C();
    *(int *)(a + 0x790) = func_02175530();
    if (*(int *)(func_02175F3C() + 0x5e0) == 0) {
        a = (char *)func_02175F3C();
        b = (char *)func_02175F3C();
        c = (char *)func_02175F3C();
        d = (char *)func_02175F3C();
        *(int *)(a + 0x5e0) = ServerBrowserNewA(*(int *)(b + 0x684),
                                             *(int *)(c + 0x684),
                                             *(int *)(d + 0x688), 0, 0x14, 1, 0,
                                             (int)0x02174058, 0);
    }
    func_0219B490(*(int *)(func_02175F3C() + 0x10));
    func_0216F770(*(int *)(func_02175F3C() + 0x678));
    DWCi_HandleSBError();
}
