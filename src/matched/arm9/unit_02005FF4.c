/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005FF4
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005FF4, sub_02006118, sub_02006138
 *
 * symbols:
 *   sub_02005FF4_State  0x020AA260  data
 *   sub_02006118_Table  0x020AA294  data
 *   sub_020058D0        0x020058D0  thumb
 *   sub_0200590C        0x0200590C  thumb
 *   sub_0200597C        0x0200597C  thumb
 *   sub_020059A0        0x020059A0  thumb
 *   sub_02005D14        0x02005D14  thumb
 *   sub_02005F90        0x02005F90  thumb
 *   sub_02006300        0x02006300  thumb
 *   sub_02006394        0x02006394  thumb
 *   _s32_div_f          0x0209C0A4  arm
 *   func_020746B0       0x020746B0  arm
 *   func_020755A8       0x020755A8  arm
 *   func_02072E9C       0x02072E9C  arm
 *   func_02072F34       0x02072F34  arm
 *   func_02085A38       0x02085A38  arm
 *
 * The three state connection pump, plus the initialiser and the address-of
 * accessor for the five entry table at 0x020AA294.
 *
 * sub_02005FF4 is where the signal strength bar comes from: `unk24` counts
 * up towards `unk2C` while the current access point matches the one being
 * connected to and back down towards zero when it does not, and the value
 * handed to func_02072F34 is `unk24 * 0x7F / unk2C` or `unk24 * 0x7F /
 * unk30`.  Both divisions are signed, so they call the compiler's own
 * `_s32_div_f` helper rather than `_u32_div_f`: `unk24` is a `u16` that
 * promotes to `int` and the two limits are `int`.  Getting that wrong is not
 * a codegen difference but a relocation with a different symbol name, and
 * the name is what the harness resolves against.
 *
 * sub_02006138 carries no label: it is `lsls`, `adds`, `adds`, `bx lr`, the
 * address of one table entry's second word, and it saves nothing, so
 * disasm.py's prologue sweep cannot see it.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02005FF4State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u32 unk28;
    int unk2C;
    int unk30;
};

struct Sub02006118Entry {
    u32 unk00;
    u32 unk04;
};

extern struct Sub02005FF4State sub_02005FF4_State;
extern struct Sub02006118Entry sub_02006118_Table[];

extern u16  sub_020058D0(void);
extern u32 *sub_0200590C(void);
extern void sub_0200597C(void);
extern int  sub_020059A0(u32 a);
extern void sub_02005D14(void);
extern void sub_02005F90(void);
extern void sub_02006300(u32 a, int mode);
extern int  sub_02006394(void);
extern void func_020746B0(int p0);
extern u32  func_020755A8(u32 req, int a, int b, int c, u32 arg);
extern void func_02072E9C(void **r0);
extern void func_02072F34(u32 *req, int level);
extern void func_02085A38(u32 msec);

void sub_02005FF4(void)
{
    u32 *req = sub_0200590C();
    u16 id = sub_020058D0();

    if (sub_02005FF4_State.unk1C == 0) {
        return;
    }
    switch (sub_02005FF4_State.unk20) {
    case 0:
        if (id != 0) {
            if (id != sub_02005FF4_State.unk28) {
                if (sub_02005FF4_State.unk24 != 0) {
                    sub_02005FF4_State.unk24--;
                    func_02072F34(req, sub_02005FF4_State.unk24 * 0x7F /
                                       sub_02005FF4_State.unk30);
                    return;
                }
                func_02072F34(req, 0);
            } else {
                if (sub_02005FF4_State.unk24 < sub_02005FF4_State.unk2C) {
                    sub_02005FF4_State.unk24++;
                    func_02072F34(req, sub_02005FF4_State.unk24 * 0x7F /
                                       sub_02005FF4_State.unk2C);
                    return;
                }
                sub_02005F90();
                return;
            }
        }
        sub_02005D14();
        if (sub_02005FF4_State.unk28 == 0) {
            sub_02005F90();
            return;
        }
        func_020746B0(0x1300);
        sub_02006300(sub_02005FF4_State.unk28, 0);
        sub_02005FF4_State.unk24 = 0;
        sub_02005FF4_State.unk20 = 1;
        return;
    case 1:
        if (sub_02006394() == 1) {
            sub_0200597C();
            sub_02006300(sub_02005FF4_State.unk28, 1);
            sub_02005FF4_State.unk20 = 2;
            return;
        }
        func_02085A38(1);
        return;
    case 2:
        if (sub_02006394() == 1) {
            func_020746B0(0);
            sub_020059A0(sub_02005FF4_State.unk28);
            func_020755A8((u32)sub_0200590C(), 0, -1, -1,
                          sub_02005FF4_State.unk28);
            func_02072F34(req, 0);
            sub_02005FF4_State.unk20 = 0;
            return;
        }
        func_02085A38(1);
        return;
    }
}

void sub_02006118(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        sub_02006118_Table[i].unk00 = 0;
        func_02072E9C((void **)(&sub_02006118_Table[i].unk04));
    }
}

u32 *sub_02006138(int i)
{
    return &sub_02006118_Table[i].unk04;
}
