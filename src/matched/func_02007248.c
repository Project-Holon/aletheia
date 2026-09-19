/*
 * function: func_02007248
 * address:  0x02007248
 * packet:   pkt_02007248
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 * status:   EXACT*
 * blocker:  020334E8 (arm) reached only by the `blx` inside this function; also EXACT* -> the follower at 0x0200725A has no label
 *
 * symbols:
 *   func_020334E8  0x020334E8  arm
 *
 * A five-argument forwarder: the fifth parameter is copied out of the
 * caller's frame into this function's own outgoing slot, so the small
 * `push {r3, lr}` + `sub sp, #4` pair is the callee's stack argument home
 * area, not saved state (see
 * docs/idioms/a-defaulting-wrapper-spends-one-zero-on-r3-and-the-stack-word.md
 * for the sibling shape).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02007248.c \
 *       --func func_02007248 --addr 0x02007248 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Sub02007248 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
};

extern void func_020334E8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

void func_02007248(struct Sub02007248 *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    func_020334E8(p->unk10, a1, a2, a3, a4);
}
