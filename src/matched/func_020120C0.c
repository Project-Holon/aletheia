/*
 * function: func_020120C0
 * address:  0x020120C0
 * packet:   pkt_020120B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           ov021_id (21) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * symbols:
 *   func_020120B4     0x020120B4  thumb
 *   ov021_id          0x00000015  data
 *   s0x021D359C       0x021D359C  data
 *
 * Four arguments, and the first is the same object twice: the pool words are
 * a small constant 0x15 (an absolute linker symbol, not a literal - see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md, 21 is
 * an overlay id) and the overlay-space address 0x021D359C.  func_020120B4
 * itself only reads r0, which is why its ten-byte body says nothing about
 * this call's arity.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020120C0.c \
 *       --func func_020120C0 --addr 0x020120C0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x08];
    u32 f8;
};

extern u8 ov021_id[];
extern u8 s0x021D359C;
extern void func_020120B4(struct IcaAnime *p, u32 id, void *ov, void *p2);

void func_020120C0(struct IcaAnime *p)
{
    func_020120B4(p, (u32)ov021_id, &s0x021D359C, p);
}
