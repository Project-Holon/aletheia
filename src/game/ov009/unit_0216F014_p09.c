/*
 * file:     unit_0216F014_p09.c
 * unit:     yes
 * function: func_02171FD4, func_021720D8, func_02172124
 * address:  0x02171FD4
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
 *   func_02176554                0x02176554 arm   ov009
 *   func_0217653C                0x0217653C arm   ov009
 *   func_02175F3C                0x02175F3C arm   ov009
 *   NNCancel                     0x02199FB4 arm   ov009
 *   func_02175FB8                0x02175FB8 arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_02172E18                0x02172E18 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_02173614                0x02173614 arm   ov009
 *   func_02172BB8                0x02172BB8 arm   ov009
 *   func_02176674                0x02176674 arm   ov009
 *   DWCi_GetMatchCnt                                  0x02175F3C arm
 *   DWCi_CancelPreConnectedServerProcessWithResetLevel 0x02171FD4 arm
 *   func_02172E7C                0x02172E7C arm   ov009
 *   func_0216EB68                0x0216EB68 arm   ov009
 *   func_0217695C                0x0217695C arm   ov009
 *   func_0216BBDC                0x0216BBDC arm   ov009
 *   DWCi_RestartFromTimeout      0x02172DB4 arm   ov009
 *   func_02171E34                0x02171E34 arm   ov009
 */
typedef unsigned char u8;

typedef unsigned short u16;

struct DWCstMatchControl_02171FD4 {
    u8 pad0[0x18];
    u8 f18;
    u8 pad1[0x5dc - 0x19];
    int f5dc;
    u8 pad2[0x618 - 0x5e0];
    int f618;
    u8 pad3[0x632 - 0x61c];
    u16 f632;
    u8 pad4[0x654 - 0x634];
    int f654;
    u8 pad5[0x67c - 0x658];
    int f67c;
    u8 pad6[0x6d8 - 0x680];
    u8 f6d8;
};

struct DWCstNodeInfo { int profileID; };

struct DWCstMatchControl_021720D8
{
    u8 pad0[0xd];
    u8 connectedOnceBefore;  /* +0xd */
    u8 pad1[0x15 - 0xe];
    u8 qr2MatchTypeExt;      /* +0x15 */
};

struct DWCstMatchControl {
    u8 pad0[0x15];
    u8 qr2MatchTypeExt;
    u8 pad1[0x554 - 0x16];
    int f554;
    u8 pad2[0x57c - 0x558];
    int f57c;
    u8 pad3[0x618 - 0x580];
    int f618;
    u8 pad4[0x62f - 0x61c];
    u8 f62f;
    u8 pad5[0x798 - 0x630];
    int f798;
};

extern int func_02176554(void);
extern void func_0217653C(void);
extern int func_02175F3C(void);
extern void NNCancel(int cookie);
extern unsigned char func_02175FB8(void);
extern void func_02175F4C(int state);
extern int func_02172E18(int profileID);
extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern int func_02173614(int profileID, unsigned char command);
extern void func_02172BB8(int level);
extern int func_02176674(void);
extern struct DWCstMatchControl_021720D8 * DWCi_GetMatchCnt(void);
extern int DWCi_CancelPreConnectedServerProcessWithResetLevel(int clientPid, int resetLevel);
extern void func_02172E7C(void);
extern void func_0216EB68(int error, int errorCode);
extern int func_0217695C(void);
extern int *func_0216BBDC(int pid, int flag);
extern void DWCi_RestartFromTimeout(void);
extern int func_02171E34(int resendPid);
/* * sdk: DWCi_CancelPreConnectedServerProcessWithResetLevel (libdwcmatch.TWL.HYB.a dwc_match.o) */ int func_02171FD4(int clientPid, int resetLevel);
int DWCi_CancelPreConnectedServerProcess(int clientPid);
int func_02172124(void);



/*
 * sdk:      DWCi_CancelPreConnectedServerProcessWithResetLevel (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02171FD4(int clientPid, int resetLevel)
{
    struct DWCstNodeInfo *pNodeInfo;
    int i;

    if (func_02176554())
        func_0217653C();
    ((struct DWCstMatchControl_02171FD4 *)func_02175F3C())->f6d8 = 0xff;
    if (((struct DWCstMatchControl_02171FD4 *)func_02175F3C())->f618 != 0) {
        NNCancel(((struct DWCstMatchControl_02171FD4 *)func_02175F3C())->f618);
        ((struct DWCstMatchControl_02171FD4 *)func_02175F3C())->f618 = 0;
    }
    ((struct DWCstMatchControl_02171FD4 *)func_02175F3C())->f67c = 0;
    if (func_02175FB8() == 2) {
        ((struct DWCstMatchControl_02171FD4 *)func_02175F3C())->f18 = 0;
        ((struct DWCstMatchControl_02171FD4 *)func_02175F3C())->f5dc = 0;
        func_02175F4C(0x11);
        ((struct DWCstMatchControl_02171FD4 *)func_02175F3C())->f654 = 0;
        ((struct DWCstMatchControl_02171FD4 *)func_02175F3C())->f632 = 0;
        func_02172E18(clientPid);
        for (i = 1; i < func_0217603C(); i++) {
            pNodeInfo = (struct DWCstNodeInfo *)func_0217637C(i);
            if (!func_02173614(pNodeInfo->profileID, 0xd))
                return 0;
        }
        if (func_0217603C() == 1)
            func_02172BB8(resetLevel);
    } else {
        func_02176674();
    }
    return 1;
}



int DWCi_CancelPreConnectedServerProcess(int clientPid)
{
    int resetLevel = 2;

    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0 ||
        DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
        if (DWCi_GetMatchCnt()->connectedOnceBefore == 0)
            resetLevel = 1;
    }
    return DWCi_CancelPreConnectedServerProcessWithResetLevel(clientPid, resetLevel);
}


/*
 * sdk:      DWCi_CancelPreConnectedClientProcess (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02172124(void)
{
    int result = 1;

    if (((struct DWCstMatchControl *)func_02175F3C())->f798 != 0)
        goto stop;
    if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 3) {
    stop:
        if (func_0217603C() > 1)
            func_02172E7C();
        if (((struct DWCstMatchControl *)func_02175F3C())->f798 != 0)
            func_0216EB68(0x16, -80432);
        else
            func_0216EB68(0x16, -80430);
        return 0;
    }
    if (func_02176674() == 1)
        return result;
    if (((struct DWCstMatchControl *)func_02175F3C())->f57c != 0)
        ((struct DWCstMatchControl *)func_02175F3C())->f57c = 0;
    if (((struct DWCstMatchControl *)func_02175F3C())->f618 != 0) {
        NNCancel(((struct DWCstMatchControl *)func_02175F3C())->f618);
        ((struct DWCstMatchControl *)func_02175F3C())->f618 = 0;
    }
    if (func_0217695C()) {
        if (((struct DWCstMatchControl *)func_02175F3C())->f62f != 0)
            goto restart;
    }
    if (func_02176554()) {
        if (func_0216BBDC(((struct DWCstMatchControl *)func_02175F3C())->f554, 1) != 0)
            goto restart;
    }
    if (func_0217603C() > 1) {
    restart:
        DWCi_RestartFromTimeout();
    } else {
        func_02175F4C(3);
        result = func_02171E34(0);
    }
    return result;
}
