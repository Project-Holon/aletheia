/*
 * function: func_020345DC
 * address:  0x020345DC
 * packet:   pkt_02034520
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closes the clact.c fan-in-1 blocker documented in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt: func_0204D8AC (cell-actor
 * resource teardown) calls this twice, once for the palette buffer and once
 * for the tile buffer, and both call sites were the address's only image
 * wide branch references, so `label` had no witness. func_020307B0 already
 * has a `matched` witness from src/matched/unit_02033C9C.c's veneer, so both
 * calls here resolve cleanly.
 *
 * Frees the buffer a resource handle points to, then frees the handle
 * itself: *p is the inner allocation, p is the outer one.
 *
 * The first call goes through the tail-call veneer at 0x02033C9C
 * (src/matched/unit_02033C9C.c), the second calls func_020307B0 directly;
 * both land at the same function, but the call site that reaches it through
 * the veneer must spell the veneer's own symbol
 * (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md).
 *
 * symbols:
 *   sub_02033C9C   0x02033C9C  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020345DC.c \
 *       --func func_020345DC --addr 0x020345DC --cc 1.1p1 --arm
 */

extern void sub_02033C9C(void *p);
extern void func_020307B0(void *p);

void func_020345DC(void **p)
{
    sub_02033C9C(*p);
    func_020307B0(p);
}
