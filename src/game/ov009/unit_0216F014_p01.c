/*
 * file:     unit_0216F014_p01.c
 * unit:     yes
 * function: func_0216F014, func_0216F058, func_0216F0A0, func_0216F1E8
 * address:  0x0216F014
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
 *   func_0216B908  0x0216B908  arm  ov009
 *   func_0216BEA4  0x0216BEA4  arm  ov009
 *   func_0216BA08  0x0216BA08  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02176358  0x02176358  arm  ov009
 *   func_0216B994                0x0216B994 arm   ov009
 *   func_0216EB68                0x0216EB68 arm   ov009
 *   NNCancel                     0x02199FB4 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_02195DE4                0x02195DE4 arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   func_02172BB8                0x02172BB8 arm   ov009
 *   DWCi_GetMatchCnt                  0x02175F3C arm
 *   DWCi_CancelPreConnectedServerProcess 0x021720D8 arm
 */
typedef struct {
    int pid;
    unsigned int bitmap;
    int id;
} Poll;

typedef unsigned char u8;

typedef unsigned long long u64;

struct GT2Socket { void *pad; };

struct DWCstMatchControl_0216F0A0 {
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

struct DWCstMatchControl_0216F1E8
{
    u8 pad0[0x629];
    u8 closeState;
};

extern int func_0216B908(void);
extern int func_0216BEA4(unsigned char aid);
extern int func_0216BA08(void);
extern int func_02175F3C(void);
extern void *func_02176358(void);
extern int func_0216B994(void);
extern void func_0216EB68(int error, int errorCode);
extern void NNCancel(int cookie);
extern int func_0217603C(void);
extern void func_02195DE4(int *p);
extern void func_02175F4C(int state);
extern u64 func_020870D0(void);
extern void func_02172BB8(int level);
extern struct DWCstMatchControl_0216F1E8 * DWCi_GetMatchCnt(void);
extern int DWCi_CancelPreConnectedServerProcess(int clientPid);
void func_0216F014(unsigned int bitmap);
void func_0216F058(const Poll *p);
int func_0216F0A0(int error, int errorCode);
void DWCi_ProcessMatchSCClosing(int clientPid);


/*
 * Hard-closes every aid present now but absent from the given bitmap.
 */
void func_0216F014(unsigned int bitmap)
{
    unsigned int cur = func_0216B908();
    unsigned int diff = cur & (cur ^ bitmap);
    unsigned char i;

    if (diff == 0) {
        return;
    }
    for (i = 0; i < 0x20; i++) {
        if (diff & (1 << i)) {
            func_0216BEA4(i);
        }
    }
}


/*
 * DWCi_ProcessMatchPollingPacket: on a client, closes the aids a server poll no longer lists.
 */
void func_0216F058(const Poll *p)
{
    int pid = p->pid;
    unsigned int bitmap = p->bitmap;
    int id = p->id;
    int *node;

    if (func_0216BA08() != 0) {
        return;
    }
    if (id != *(int *)(func_02175F3C() + 0x7c8)) {
        return;
    }
    node = func_02176358();
    if (node == 0) {
        return;
    }
    if (*node != pid) {
        return;
    }
    func_0216F014(bitmap);
}


/*
 * sdk:      DWCi_ProcessMatchClosing (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_0216F0A0(int error, int errorCode)
{
    u64 tick;

    if (func_0216B994() != 4)
        return 0;
    if (((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f14 == 2)
        return 1;
    if (error != 0) {
        func_0216EB68(error, errorCode - 80000);
        return 1;
    }
    if (((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f62a == 1 || ((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f629 == 1)
        return 1;
    if (((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f618 != 0) {
        NNCancel(((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f618);
        ((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f618 = 0;
    }
    if (func_0217603C() > 1) {
        if (((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f629 == 0) {
            ((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f629 = 2;
            func_02195DE4((int *)(*((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->gt2Socket));
        }
    } else if (((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f15 == 3) {
        func_0216EB68(0x16, -80430);
    } else if (((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f61c == 1) {
        func_02175F4C(0x15);
        tick = func_020870D0();
        ((struct DWCstMatchControl_0216F0A0 *)func_02175F3C())->f668 = tick;
    } else {
        func_02172BB8(1);
    }
    return 1;
}


void DWCi_ProcessMatchSCClosing(int clientPid)
{
    if (DWCi_GetMatchCnt()->closeState == 1)
        return;
    DWCi_CancelPreConnectedServerProcess(clientPid);
}
