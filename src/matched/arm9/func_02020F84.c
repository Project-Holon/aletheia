/*
 * unit:     no
 * address:  0x02020F84
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02020F84
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *
 * One of a pair of near-identical entry points (func_02020F84 uses table 0x36,
 * func_02020FB4 table 0x35) that open a message archive, read one entry into
 * the caller's buffer and close it again.  An out-of-range entry index falls
 * back to 0; the bound 0x272 is one more than the last id func_02021288
 * accepts, which is why it is a pool word rather than a folded immediate.
 *
 * The heap argument stays in r3 across the guard because it is the fourth
 * argument of the archive open, not a leftover: the ARM callee clobbers r0-r3,
 * so a value still in r3 at the second call could not have survived the first
 * (docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-
 * arity.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020F84.c  *       --func func_02020F84 --addr 0x02020F84 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02045C04(struct Rec *rec);

void func_02020F84(void *dst, u32 entry, u32 heap)
{
    void *arc;

    if (entry > 0x272) {
        entry = 0;
    }
    arc = func_02045B38(0, 2, 0x36, heap);
    func_02045CAC(arc, entry, dst);
    func_02045C04(arc);
}
