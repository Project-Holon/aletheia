/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005CA4
 * packet:   pkt_02005924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005CA4, sub_02005CBC, sub_02005CE0, sub_02005D08,
 *           sub_02005D14, sub_02005D28
 *
 * symbols:
 *   sub_02005CE0_State  0x020AA260  data
 *   sub_0200590C        0x0200590C  thumb
 *   sub_020059C8        0x020059C8  thumb
 *   sub_02005C64        0x02005C64  thumb
 *   sub_02005F90        0x02005F90  thumb
 *   func_02072D98       0x02072D98  arm
 *   func_02072E7C       0x02072E7C  arm
 *
 * A bit-per-channel broadcast and the callback hook that goes with it.
 *
 * sub_02005CA4 forwards its second argument without ever mentioning it: the
 * original never touches r1 between entry and either call, which is what a
 * parameter that is only ever passed on looks like.  The one thing to get
 * right is that both arms call the same function with a different first
 * argument rather than computing the argument and calling once; written as
 * `sub_02005CBC(a == 1 ? 0x7F : 0, b)` the compiler folds the two calls into
 * one and the function is four bytes shorter.
 */

typedef unsigned int u32;

struct Sub02005CE0State {
    u32   unk00;
    int (*unk04)(void *arg);
};

extern struct Sub02005CE0State sub_02005CE0_State;

extern u32 *sub_0200590C(void);
extern void sub_020059C8(void);
extern int  sub_02005C64(void);
extern void sub_02005F90(void);
extern void func_02072D98(u32 idx, u32 val);
extern void func_02072E7C(void **r0, int fadeFrame);

void sub_02005CBC(u32 value, u32 mask);
void sub_02005D14(void);

void sub_02005CA4(int a, u32 mask)
{
    if (a == 1) {
        sub_02005CBC(0x7F, mask);
    } else {
        sub_02005CBC(0, mask);
    }
}

void sub_02005CBC(u32 value, u32 mask)
{
    int i;

    for (i = 0; i < 5; i++) {
        if ((1 << i) & mask) {
            func_02072D98(i, value);
        }
    }
}

int sub_02005CE0(void *arg)
{
    if (sub_02005C64() == 0) {
        return 1;
    }
    if (sub_02005CE0_State.unk04 == 0) {
        return 0;
    }
    return sub_02005CE0_State.unk04(arg);
}

void sub_02005D08(int (*hook)(void *arg))
{
    sub_02005CE0_State.unk04 = hook;
}

void sub_02005D14(void)
{
    func_02072E7C((void **)sub_0200590C(), 0);
    sub_020059C8();
}

void sub_02005D28(void)
{
    sub_02005F90();
    sub_02005D14();
}
