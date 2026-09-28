/*
 * function: func_0202F630
 * address:  0x0202F630
 * packet:   pkt_0202F498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted out of src/pending: the callee func_0202F640 became a manifest
 * entry this pass, so the second call site resolves on `matched`.
 */

typedef unsigned int u32;

extern u32  func_020185F0(u32 a);
extern void func_0202F640(u32 a, u32 b);

void func_0202F630(u32 a, u32 b)
{
    func_0202F640(func_020185F0(a), b);
}
