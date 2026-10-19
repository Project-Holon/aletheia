/*
 * unit:     no
 * function: PMS_DRAW_ClearWork
 * address:  0x0202E43C
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * A pool-word-and-bx tail call that supplies two constant arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md); r3 holds the target,
 * so a fourth argument would not fit and the call has exactly three
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * It is its own file rather than the head of a unit with 0x0202E448
 * because that neighbour's table address has no witness; see
 * src/pending/sub_0202E448.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMS_DRAW_ClearWork.c \
 *       --func PMS_DRAW_ClearWork --addr 0x0202E43C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void MI_CpuFill8(void *p, u32 a, u32 b);

void PMS_DRAW_ClearWork(void *p)
{
    MI_CpuFill8(p, 0, 4);
}
