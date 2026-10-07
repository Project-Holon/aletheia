/*
 * function: func_02172604
 * address:  0x02172604
 * packet:   pkt_ov009_02172604
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_PostProcessSVConnectionHybrid (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_02176674                0x02176674 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   qr2_send_statechanged        0x0219B490 arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_02173064                0x02173064 arm   ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

struct DWCstMatchControl {
    u8 pad0[0xd];
    u8 f0d;
    u8 pad1[0x10 - 0xe];
    void *qr2Obj;
    u8 f14;
    u8 pad2[0x18 - 0x15];
    u8 f18;
    u8 pad3[0x554 - 0x19];
    int f554;
    u8 pad4[0x56a - 0x558];
    u8 aid;
    u8 pad5[0x5a4 - 0x56b];
    int f5a4;
    int f5a8;
    u8 pad6[0x5dc - 0x5ac];
    int f5dc;
    u8 pad7[0x650 - 0x5e0];
    int f650;
    u8 pad8[0x680 - 0x654];
    int f680;
    u8 pad9[0x7a0 - 0x684];
    u64 f7a0;
};

struct DWCstNodeInfo {
    u8 pad0[0x16];
    u8 aid;
};

extern int func_02175F3C(void);
extern void func_02175F4C(int state);
extern int func_02176674(void);
extern int func_0217603C(void);
extern u64 func_020870D0(void);
extern void qr2_send_statechanged(void *qrec);
extern struct DWCstNodeInfo *func_0217637C(int index);
extern void func_02173064(u8 aid, u16 type);

int func_02172604(void)
{
    int sbClear = 0;
    int i;
    u64 tick;

    if (((struct DWCstMatchControl *)func_02175F3C())->f5a4 != 0 || ((struct DWCstMatchControl *)func_02175F3C())->f5a8 == 0xf) {
        ((struct DWCstMatchControl *)func_02175F3C())->f18 = 0;
        ((struct DWCstMatchControl *)func_02175F3C())->f5dc = 0;
        func_02175F4C(1);
        func_02176674();
        return sbClear;
    }
    ((struct DWCstMatchControl *)func_02175F3C())->f18 = 0;
    ((struct DWCstMatchControl *)func_02175F3C())->f5dc = 0;
    if (((struct DWCstMatchControl *)func_02175F3C())->f0d == 0 && func_0217603C() == 1) {
        tick = func_020870D0();
        ((struct DWCstMatchControl *)func_02175F3C())->f7a0 = tick;
    }
    qr2_send_statechanged(((struct DWCstMatchControl *)func_02175F3C())->qr2Obj);
    if (((struct DWCstMatchControl *)func_02175F3C())->f14 == 2)
        ((struct DWCstMatchControl *)func_02175F3C())->f680 = ((struct DWCstMatchControl *)func_02175F3C())->f554;
    func_02175F4C(0x13);
    ((struct DWCstMatchControl *)func_02175F3C())->f650 = 0;
    for (i = 1; i < func_0217603C(); i++)
        func_02173064(func_0217637C(i)->aid, 2);
    func_02173064(((struct DWCstMatchControl *)func_02175F3C())->aid, 2);
    if (((struct DWCstMatchControl *)func_02175F3C())->f14 != 2)
        sbClear = 1;
    return sbClear;
}
