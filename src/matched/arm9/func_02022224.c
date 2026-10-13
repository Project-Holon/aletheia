/*
 * function: WIPE_ResetWndMask
 * address:  0x02022224
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A two-instruction forwarder (fan-in 22) that pins the first argument of
 * WIPE_SUB_SetWindowVisible to zero and passes the caller's window pointer through as the
 * second.  Tail calls in this compiler are always a pool word and a `bx`,
 * never a displacement branch, because every function gets its own section;
 * see docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * EXACT* is the extent walk running into the second forwarder at 0x02022230,
 * which is an unlabelled leaf with its own callers and keeps its own file.
 *
 * symbols:
 *   WIPE_SUB_SetWindowVisible  0x02023B48  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_ResetWndMask.c \
 *       --func WIPE_ResetWndMask --addr 0x02022224 --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

extern u32 WIPE_SUB_SetWindowVisible(u32 kind, void *win);

u32 WIPE_ResetWndMask(void *win)
{
    return WIPE_SUB_SetWindowVisible(0, win);
}
