/*
 * function: func_02005D34
 * address:  0x02005D34
 * packet:   pkt_02005D34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  func_020755A8 (label) and func_02005CE0/func_02005924 (matched-class
 *           candidates); the four early exits are all concrete.
 *
 * symbols:
 *   func_02005CE0  0x02005CE0  thumb
 *   func_02005D14  0x02005D14  thumb
 *   func_02005924  0x02005924  thumb
 *   sub_0200590C   0x0200590C  thumb
 *   func_020055A8  0x020755A8  arm
 *   func_02005EB4  0x02005EB4  thumb
 *
 * Open one connection slot of `size` bytes and register it: three guards,
 * each with its own `return 0` epilogue (so they are separate `if`s and not
 * a shared exit), then the slot-descriptor creation call whose first argument
 * is the slot pointer sub_0200590C returns, and a trailing `!= 0xFFFF` test
 * that re-runs the registration for the parent key.
 *
 * The third failure return reads r6 (the zero the two `-1` arguments were
 * derived from) rather than rematerialising `movs r0, #0`, which is why it is
 * spelled as a return of the same local the earlier statements used.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02005D34.c \
 *       --func func_02005D34 --addr 0x02005D34 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern int   func_02005CE0(void *arg);
extern void  func_02005D14(void);
extern int   func_02005924(u32 a);
extern u32 *sub_0200590C(void);
extern void *func_020755A8(void *slot, u32 a, int b, int c, u32 d);
extern void  func_02005EB4(u32 key);

void *func_02005D34(u32 a0, u32 a1)
{
    void *r;
    int   zero;

    zero = 0;
    if (func_02005CE0((void *)a0) == 0) {
        return 0;
    }
    func_02005D14();
    if (func_02005924(a0) == 0) {
        return 0;
    }
    r = func_020755A8(sub_0200590C(), 0, -1, -1, a0);
    if (r == 0) {
        return (void *)zero;
    }
    if (a1 != 0xFFFF) {
        func_02005EB4(a1);
    }
    return r;
}
