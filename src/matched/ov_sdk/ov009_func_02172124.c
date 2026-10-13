/*
 * function: func_02172124
 * address:  0x02172124
 * packet:   pkt_ov009_02172124
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CancelPreConnectedClientProcess (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_02172E7C                0x02172E7C arm   ov009
 *   func_0216EB68                0x0216EB68 arm   ov009
 *   func_02176674                0x02176674 arm   ov009
 *   NNCancel                     0x02199FB4 arm   ov009
 *   func_0217695C                0x0217695C arm   ov009
 *   func_02176554                0x02176554 arm   ov009
 *   DWCi_GetGT2ConnectionByProfileID                0x0216BBDC arm   ov009
 *   DWCi_RestartFromTimeout      0x02172DB4 arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_02171E34                0x02171E34 arm   ov009
 */

typedef unsigned char u8;

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

extern int func_02175F3C(void);
extern int func_0217603C(void);
extern void func_02172E7C(void);
extern void func_0216EB68(int error, int errorCode);
extern int func_02176674(void);
extern void NNCancel(int cookie);
extern int func_0217695C(void);
extern int func_02176554(void);
extern int *DWCi_GetGT2ConnectionByProfileID(int pid, int flag);
extern void DWCi_RestartFromTimeout(void);
extern void func_02175F4C(int state);
extern int func_02171E34(int resendPid);

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
        if (DWCi_GetGT2ConnectionByProfileID(((struct DWCstMatchControl *)func_02175F3C())->f554, 1) != 0)
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
