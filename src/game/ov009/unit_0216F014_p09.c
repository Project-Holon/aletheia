/*
 * file:     unit_0216F014_p09.c
 * unit:     yes
 * function: func_02171E34, func_02171F68
 * address:  0x02171E34
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
 *   func_020870D0                0x020870D0 arm
 *   func_0217653C                0x0217653C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_0216F770                0x0216F770 arm   ov009
 *   func_02173D9C                0x02173D9C arm   ov009
 *   func_02171C08                0x02171C08 arm   ov009
 *   func_021719A4                0x021719A4 arm   ov009
 *   func_0216EB68                0x0216EB68 arm   ov009
 *   func_02176554  0x02176554  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 */
typedef unsigned char u8;

typedef unsigned long long u64;

struct DWCstMatchControl {
    u8 pad0[0x15];
    u8 qr2MatchTypeExt;
    u8 pad1[0x5e4 - 0x16];
    int f5e4;
    u64 f5e8;
    u8 pad2[0x628 - 0x5f0];
    u8 f628;
    u8 pad3[0x648 - 0x629];
    u64 f648;
    u8 pad4[0x67c - 0x650];
    int f67c;
    u8 pad5[0x798 - 0x680];
    int f798;
};

extern int func_02175F3C(void);
extern u64 func_020870D0(void);
extern void func_0217653C(void);
extern void func_02175F4C(int state);
extern int func_0216F770(int profileID);
extern int func_02173D9C(int error);
extern int func_02171C08(int delay, int init, int resendPid);
extern int func_021719A4(int error);
extern void func_0216EB68(int error, int errorCode);
extern int func_02176554(void);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
int func_02171E34(int resendPid);
int func_02171F68(int arg);


/*
 * sdk:      DWCi_RetryReserving (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02171E34(int resendPid)
{
    int result;
    int sbError;
    u64 tick;

    ((struct DWCstMatchControl *)func_02175F3C())->f67c = 0;
    ((struct DWCstMatchControl *)func_02175F3C())->f628 = 0;
    tick = func_020870D0();
    ((struct DWCstMatchControl *)func_02175F3C())->f648 = tick;
    func_0217653C();
    if (((struct DWCstMatchControl *)func_02175F3C())->f798 != 0) {
        func_02175F4C(0xc);
        sbError = func_02173D9C(func_0216F770(0));
        if (sbError != 0)
            return 0;
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 0) {
        func_02175F4C(2);
        if (resendPid != 0) {
            ((struct DWCstMatchControl *)func_02175F3C())->f5e4 = 1;
            tick = func_020870D0();
            ((struct DWCstMatchControl *)func_02175F3C())->f5e8 = tick;
        } else {
            sbError = func_02173D9C(func_0216F770(0));
            if (sbError != 0)
                return 0;
        }
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 1) {
        result = func_021719A4(func_02171C08(1, 0, resendPid));
        if (result != 0)
            return 0;
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 3) {
        func_0216EB68(6, -80410);
        return 0;
    }
    return 1;
}


/*
 * Sends command 5 to the new node recorded in the temporary node info.
 */
int func_02171F68(int arg)
{
    int result;

    if (func_02176554() == 0) {
        return 0;
    }
    result = func_0216FF2C(5, *(int *)(func_02175F3C() + 0x554), *(unsigned int *)(func_02175F3C() + 0x558),
                           *(unsigned short *)(func_02175F3C() + 0x560), 0, 0);
    *(int *)(func_02175F3C() + 0x67c) = 0;
    return result;
}
