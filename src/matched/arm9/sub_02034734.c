/*
 * function: SAVEDATA_PanicFailPrintf
 * address:  0x02034734
 * packet:   pkt_02034734
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_Sink  0x0214699C  data
 *
 * The printf-shaped sibling of SAVEDATA_PanicFail (src/matched/unit_02034714.c):
 * byte for byte the same body, dispatching the hook at g_Sink+0xC through
 * `blx` so a Thumb handler works, wrapped in a variadic frame.
 *
 * The whole difference between the two functions is the trailing `...`.
 * A variadic function homes all four argument registers so the callee's
 * va_list has somewhere contiguous to walk, which is the leading
 * `push {r0, r1, r2, r3}` here (the same shape
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md
 * describes for &param), and it is also what turns the epilogue from
 * `pop {r3, pc}` into `pop {r3, lr}` / `add sp, sp, #0x10` / `bx lr`:
 * the homed block has to be discarded before the return.  No `va_start`
 * appears because this function never reads the variadic tail itself; the
 * registered handler does.
 *
 * As in SAVEDATA_PanicFail, the hook is called with no C-visible arguments.  The
 * named parameters survive into it only because nothing here clobbers
 * r0-r3 before the `blx`, so writing the call as `h(expr, line, file)`
 * would add `mov`s the original does not have.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVEDATA_PanicFailPrintf.c \
 *       --func SAVEDATA_PanicFailPrintf --addr 0x02034734 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef void (*AssertHandler)(void);

struct Sink {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    AssertHandler handler;
};

extern struct Sink g_Sink;

void SAVEDATA_PanicFailPrintf(const char *expr, u32 line, const char *file, ...)
{
    AssertHandler h = g_Sink.handler;

    if (h) {
        h();
    }
}
