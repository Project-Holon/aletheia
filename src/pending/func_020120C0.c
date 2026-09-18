/*
 * function: func_020120C0
 * address:  0x020120C0
 * packet:   pkt_020120B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
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
 * blocker:  literal, two sites.  Both pool words are single-witness data
 *           addresses: 0x00000015 appears in one literal pool in the whole
 *           image (this one) and 0x021D359C in one, and neither is attested
 *           by a string or a label.  0x021D359C is overlay-space, so a
 *           later wave that labels it in its overlay would close the second
 *           site; the first needs a second pool word somewhere.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020120C0.c \
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
