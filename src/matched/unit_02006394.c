/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02006394
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02006394
 *
 * symbols:
 *   sub_02006394_State   0x020AA260  data
 *   sub_02006394_Thread  0x020AA354  data
 *   func_0208574C        0x0208574C  arm
 *
 * "Has the worker thread finished."  A thread that was never started counts
 * as finished, which is the early `return 1`.
 *
 * Near miss, recorded here because this file is what survived of the range.
 * sub_020063B4, 0x020063B4..0x02006448, is the caller-driven version of the
 * three state pump that sub_02005FF4 runs off its own state word, with the
 * state behind a pointer the caller owns.  Every call, constant and field
 * access in it is reproduced and its first 0x20 bytes are byte identical,
 * but the best shape found is 64 bytes out and all 64 are block placement:
 * the original cross-jumps three tails that no spelling tried here makes
 * this compiler merge the same way.  Specifically, states 0 and 1 share one
 * copy of the `sub_02006300` call with the two arguments set up beforehand;
 * the `stop` path and the two normal paths share one copy of the store back
 * through the state pointer; the two `func_02085A38(2)` error exits share
 * one block placed between the last case and the common `return 0`; and
 * case 1 reaches that block through a two byte `b` bridge rather than
 * branching to it directly.  Twelve source shapes were tried, crossing a
 * merged tail against a duplicated one, a `mode` temporary against inlined
 * calls, `goto` against `break`, and a fallthrough `err:` label against a
 * second `return 0`.  The count moves between 64 and 153 and never reaches
 * zero, and what is left is all in the compiler's block ordering rather
 * than in the source, which is where enumerating shapes stops being the
 * cheap method.
 */

typedef unsigned int u32;

struct Sub02006394State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
};

extern struct Sub02006394State sub_02006394_State;
extern u32 sub_02006394_Thread[];

extern int func_0208574C(u32 *thread);

int sub_02006394(void)
{
    if (sub_02006394_State.unk14 == 0) {
        return 1;
    }
    return func_0208574C(sub_02006394_Thread);
}
