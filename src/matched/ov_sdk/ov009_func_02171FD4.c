/*
 * function: func_02171FD4
 * address:  0x02171FD4
 * packet:   pkt_ov009_02171FD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CancelPreConnectedServerProcessWithResetLevel (libdwcmatch.TWL.HYB.a dwc_match.o)
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
struct DWCstMatchControl {
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
extern int func_02176554(void);
extern void func_0217653C(void);
extern struct DWCstMatchControl *func_02175F3C(void);
extern void NNCancel(int cookie);
extern unsigned char func_02175FB8(void);
extern void func_02175F4C(int state);
extern int func_02172E18(int profileID);
extern int func_0217603C(void);
extern struct DWCstNodeInfo *func_0217637C(int index);
extern int func_02173614(int profileID, unsigned char command);
extern void func_02172BB8(int level);
extern int func_02176674(void);

int func_02171FD4(int clientPid, int resetLevel)
{
    struct DWCstNodeInfo *pNodeInfo;
    int i;

    if (func_02176554())
        func_0217653C();
    func_02175F3C()->f6d8 = 0xff;
    if (func_02175F3C()->f618 != 0) {
        NNCancel(func_02175F3C()->f618);
        func_02175F3C()->f618 = 0;
    }
    func_02175F3C()->f67c = 0;
    if (func_02175FB8() == 2) {
        func_02175F3C()->f18 = 0;
        func_02175F3C()->f5dc = 0;
        func_02175F4C(0x11);
        func_02175F3C()->f654 = 0;
        func_02175F3C()->f632 = 0;
        func_02172E18(clientPid);
        for (i = 1; i < func_0217603C(); i++) {
            pNodeInfo = func_0217637C(i);
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
