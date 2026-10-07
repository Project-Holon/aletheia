/*
 * file:     unit_0217576C_p01.c
 * unit:     yes
 * function: func_02175AA4, func_02175BFC, func_02175C64
 * address:  0x02175AA4
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
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_0219F00C                0x0219F00C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_02171C08                0x02171C08 arm   ov009
 *   func_021719A4                0x021719A4 arm   ov009
 *   gpIsBuddy                    0x021861A8 arm   ov009
 *   func_021719D0                0x021719D0 arm   ov009
 *   func_0216F770                0x0216F770 arm   ov009
 *   func_02173D9C                0x02173D9C arm   ov009
 *   func_020870D0  0x020870D0  arm
 *   func_0216CB90  0x0216CB90  arm  ov009
 *   func_021768EC  0x021768EC  arm  ov009
 *   func_02175D10  0x02175D10  arm  ov009
 */
typedef unsigned char u8;

struct DWCstMatchControl {
    void **connection;
    u8 pad0[0xd - 0x4];
    u8 f0d;
    u8 pad1[0x15 - 0xe];
    u8 qr2MatchTypeExt;
    u8 pad2[0x554 - 0x16];
    int f554;
    u8 pad3[0x5e0 - 0x558];
    void *sbObj;
    u8 pad4[0x67c - 0x5e4];
    int f67c;
    u8 pad5[0x798 - 0x680];
    int f798;
};

extern int func_02175F3C(void);
extern void func_0219F00C(char *p);
extern void func_02175F4C(int state);
extern int func_02171C08(int delay, int init, int resendPid);
extern int func_021719A4(int error);
extern int gpIsBuddy(void **connection, int profile);
extern int func_021719D0(int profileID, int delay);
extern int func_0216F770(int profileID);
extern int func_02173D9C(int error);
extern unsigned long long func_020870D0(void);
extern int func_0216CB90(void);
extern void func_021768EC(int result);
extern int func_02175D10(int suspend);
int func_02175AA4(void);
void func_02175BFC(int suspend, void *callback, void *suspendResultParam);
int func_02175C64(void);


/*
 * sdk:      DWCi_StartMatch (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02175AA4(void)
{
    int result;
    int sbError;

    if (((struct DWCstMatchControl *)func_02175F3C())->sbObj != 0)
        func_0219F00C(((struct DWCstMatchControl *)func_02175F3C())->sbObj);
    if (((struct DWCstMatchControl *)func_02175F3C())->f798 != 0) {
        func_02175F4C(0xc);
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 0) {
        func_02175F4C(2);
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 1) {
        func_02175F4C(3);
        result = 1;
        if (func_021719A4(func_02171C08(0, 1, 0)))
            result = 0;
        return result;
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 2) {
        func_02175F4C(0xd);
        ((struct DWCstMatchControl *)func_02175F3C())->f0d = 1;
        return 1;
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 3) {
        if (gpIsBuddy(((struct DWCstMatchControl *)func_02175F3C())->connection, ((struct DWCstMatchControl *)func_02175F3C())->f554)) {
            func_02175F4C(3);
            result = func_021719A4(func_021719D0(((struct DWCstMatchControl *)func_02175F3C())->f554, 0));
            if (result)
                return 0;
        }
        return 1;
    }
    ((struct DWCstMatchControl *)func_02175F3C())->f67c = 0;
    sbError = func_02173D9C(func_0216F770(((struct DWCstMatchControl *)func_02175F3C())->f67c));
    result = 0;
    if (sbError == 0)
        result = 1;
    return result;
}


/*
 * sdk:      DWCi_RequestSuspendMatchInit (dwc_match.o)
 */
void func_02175BFC(int suspend, void *callback, void *suspendResultParam)
{
    *(char *)(func_02175F3C() + 0x30) = 0;
    *(int *)(func_02175F3C() + 0x2c) = suspend;
    *(void **)(func_02175F3C() + 0x34) = callback;
    *(void **)(func_02175F3C() + 0x38) = suspendResultParam;
    *(unsigned long long *)(func_02175F3C() + 0x20) = 0;
    {
        unsigned long long tick = func_020870D0();
        *(unsigned long long *)(func_02175F3C() + 0x3c) = tick;
    }
    *(int *)(func_02175F3C() + 0x48) = 1;
}


/*
 * sdk:      DWCi_RequestSuspendMatchProcess (dwc_match.o)
 */
int func_02175C64(void)
{
    int ret;
    int suspend;

    if (*(int *)(func_02175F3C() + 0x48) == 0)
        return 0;
    if (*(int *)(func_02175F3C() + 0x44) != 0) {
        func_02175BFC(*(int *)(func_02175F3C() + 0x2c), *(void **)(func_02175F3C() + 0x34), *(void **)(func_02175F3C() + 0x38));
        *(int *)(func_02175F3C() + 0x44) = 0;
    }
    suspend = *(int *)(func_02175F3C() + 0x2c);
    if (suspend == 0xff)
        return 0;
    ret = func_0216CB90();
    if ((suspend != 0 && ret != 0) || (suspend == 0 && ret == 0)) {
        func_021768EC(0);
        return 1;
    }
    func_02175D10(suspend);
    return 1;
}
