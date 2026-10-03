/*
 * function: func_0202C218
 * address:  0x0202C218
 * packet:   pkt_0202C218
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the record through func_0202C204 when the object is live and the
 * lookup fails.  Unlabelled in the listing (no lr save of its own beyond the
 * callee-saved set) and absent from the worklist; filed from the bytes.  It is
 * the tail-call target of the thunk at 0x0202C0C8, which is what
 * src/pending/func_0202B7E0.c is blocked on.
 *
 * symbols:
 *   sub_0202C2D8  0x0202C2D8  thumb
 *   func_0202C250  0x0202C250  thumb
 *   func_0202C2DC  0x0202C2DC  thumb
 *   func_0202C204  0x0202C204  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C218.c \
 *       --func func_0202C218 --addr 0x0202C218 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32  sub_0202C2D8(u32 *p);
extern u32  func_0202C250(u32 *p, u32 v);
extern void func_0202C2DC(void *p);
extern void func_0202C204(u32 *p);

void func_0202C218(u32 *p, u32 v)
{
    if (sub_0202C2D8(p) == 0) {
        return;
    }
    if (func_0202C250(p, v) != 0) {
        return;
    }
    func_0202C2DC(p);
    func_0202C204(p);
}
