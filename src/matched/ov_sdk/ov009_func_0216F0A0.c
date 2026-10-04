/*
 * function: func_0216F0A0
 * address:  0x0216F0A0
 * packet:   pkt_ov009_0216F0A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ProcessMatchClosing (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_0216B994                0x0216B994 arm   ov009
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_0216EB68                0x0216EB68 arm   ov009
 *   NNCancel                     0x02199FB4 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_02195DE4                0x02195DE4 arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   func_02172BB8                0x02172BB8 arm   ov009
 */

typedef unsigned char u8;
typedef unsigned long long u64;

struct GT2Socket { void *pad; };

struct DWCstMatchControl {
    u8 pad0[4];
    struct GT2Socket **gt2Socket;
    u8 pad1[0x14 - 0x8];
    u8 f14;
    u8 f15;
    u8 pad2[0x618 - 0x16];
    int f618;
    int f61c;
    u8 pad3[0x629 - 0x620];
    u8 f629;
    u8 f62a;
    u8 pad4[0x668 - 0x62b];
    u64 f668;
};

extern int func_0216B994(void);
extern int func_02175F3C(void);
extern void func_0216EB68(int error, int errorCode);
extern void NNCancel(int cookie);
extern int func_0217603C(void);
extern void func_02195DE4(struct GT2Socket *socket);
extern void func_02175F4C(int state);
extern u64 func_020870D0(void);
extern void func_02172BB8(int level);

int func_0216F0A0(int error, int errorCode)
{
    u64 tick;

    if (func_0216B994() != 4)
        return 0;
    if (((struct DWCstMatchControl *)func_02175F3C())->f14 == 2)
        return 1;
    if (error != 0) {
        func_0216EB68(error, errorCode - 80000);
        return 1;
    }
    if (((struct DWCstMatchControl *)func_02175F3C())->f62a == 1 || ((struct DWCstMatchControl *)func_02175F3C())->f629 == 1)
        return 1;
    if (((struct DWCstMatchControl *)func_02175F3C())->f618 != 0) {
        NNCancel(((struct DWCstMatchControl *)func_02175F3C())->f618);
        ((struct DWCstMatchControl *)func_02175F3C())->f618 = 0;
    }
    if (func_0217603C() > 1) {
        if (((struct DWCstMatchControl *)func_02175F3C())->f629 == 0) {
            ((struct DWCstMatchControl *)func_02175F3C())->f629 = 2;
            func_02195DE4(*((struct DWCstMatchControl *)func_02175F3C())->gt2Socket);
        }
    } else if (((struct DWCstMatchControl *)func_02175F3C())->f15 == 3) {
        func_0216EB68(0x16, -80430);
    } else if (((struct DWCstMatchControl *)func_02175F3C())->f61c == 1) {
        func_02175F4C(0x15);
        tick = func_020870D0();
        ((struct DWCstMatchControl *)func_02175F3C())->f668 = tick;
    } else {
        func_02172BB8(1);
    }
    return 1;
}
