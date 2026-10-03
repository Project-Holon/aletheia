/*
 * function: func_02175AA4
 * address:  0x02175AA4
 * packet:   pkt_ov009_02175AA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_StartMatch (libdwcmatch.TWL.HYB.a dwc_match.o)
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

extern struct DWCstMatchControl *func_02175F3C(void);
extern void func_0219F00C(char *p);
extern void func_02175F4C(int state);
extern int func_02171C08(int delay, int init, int resendPid);
extern int func_021719A4(int error);
extern int gpIsBuddy(void **connection, int profile);
extern int func_021719D0(int profileID, int delay);
extern int func_0216F770(int profileID);
extern int func_02173D9C(int error);

int func_02175AA4(void)
{
    int result;
    int sbError;

    if (func_02175F3C()->sbObj != 0)
        func_0219F00C(func_02175F3C()->sbObj);
    if (func_02175F3C()->f798 != 0) {
        func_02175F4C(0xc);
    } else if (func_02175F3C()->qr2MatchTypeExt == 0) {
        func_02175F4C(2);
    } else if (func_02175F3C()->qr2MatchTypeExt == 1) {
        func_02175F4C(3);
        result = 1;
        if (func_021719A4(func_02171C08(0, 1, 0)))
            result = 0;
        return result;
    } else if (func_02175F3C()->qr2MatchTypeExt == 2) {
        func_02175F4C(0xd);
        func_02175F3C()->f0d = 1;
        return 1;
    } else if (func_02175F3C()->qr2MatchTypeExt == 3) {
        if (gpIsBuddy(func_02175F3C()->connection, func_02175F3C()->f554)) {
            func_02175F4C(3);
            result = func_021719A4(func_021719D0(func_02175F3C()->f554, 0));
            if (result)
                return 0;
        }
        return 1;
    }
    func_02175F3C()->f67c = 0;
    sbError = func_02173D9C(func_0216F770(func_02175F3C()->f67c));
    result = 0;
    if (sbError == 0)
        result = 1;
    return result;
}
