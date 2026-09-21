/*
 * function: func_020224DC
 * address:  0x020224DC
 * packet:   pkt_020224DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021468A4     0x021468A4  data
 *   func_020225F0  0x020225F0  thumb
 *   func_02030EAC  0x02030EAC  arm
 *
 * Drops one entry of the two-slot callback block func_02022458 arms (the
 * 0x18-byte object at +0x74 of the dual-screen cluster): three parallel
 * two-element arrays, ctx[] at +0x00, fn[] at +0x08 and arg[] at +0x10.
 * func_020221B8 calls it once per slot during shutdown.
 *
 * It clears this slot's user word FIRST, and only then checks whether both
 * user words have gone to zero; when they have and the vblank/task handle at
 * g_021468A4 +0x54 is still live, it releases that handle through
 * func_02030EAC and nulls it.  The slot's handler is then re-armed with the
 * do-nothing func_020225F0 rather than a null, the same convention
 * func_02022458 uses, and the context pointer cleared last.
 *
 * Shape notes.  The zero written to arg[idx] and the zero written back to
 * +0x54 are one value kept in r6 across the call, which is what makes them
 * one named local rather than two literal zeroes; the final ctx[idx] = 0
 * uses a fresh `movs r0, #0` after the call instead, so it must be written
 * as a plain constant.  The two `adds r0, r5, r4` recomputations of
 * &slot[idx] on either side of the guard are the compiler's own
 * rematerialisation of the scaled index, not two separate cursors; keeping
 * the address in a named local costs a callee-saved register, see
 * docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020224DC.c \
 *       --func func_020224DC --addr 0x020224DC --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned int   u32;

typedef void (*Handler)(void);

struct Slots {
    void   *ctx[2];
    Handler fn[2];
    u32     arg[2];
};

struct G021468A4 {
    u8    pad00[0x54];
    void *f54;
};

extern struct G021468A4 g_021468A4;

extern void func_020225F0(void);
extern void func_02030EAC(void *a);

void func_020224DC(struct Slots *p, u32 idx)
{
    u32 zero = 0;

    p->arg[idx] = zero;
    if (p->arg[0] == 0 && p->arg[1] == 0 && g_021468A4.f54 != 0) {
        func_02030EAC(g_021468A4.f54);
        g_021468A4.f54 = (void *)zero;
    }
    p->fn[idx] = func_020225F0;
    p->ctx[idx] = 0;
}
