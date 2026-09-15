/*
 * unit:     no
 * function: sub_0204D500
 * address:  0x0204D500
 * packet:   pkt_0204D3C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   sub_02064B68  0x02064B68  arm
 *
 * The third handler of the row that src/matched/unit_0204D4C4.c dispatches
 * through: step the pointer past the object's 0xc-byte header and tail-call
 * into the G2D layer, forwarding the second argument untouched.
 *
 * Byte-correct, capped at MATCH.  The tail call is a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), so the site is an ABS32
 * naming 0x02064B68, and that address is named by no other pool word and by
 * no branch anywhere in the image: `label`, `literal` and `veneer` all have
 * nothing outside this range.  The one route left is an EXACT entry for
 * 0x02064B68 itself acting as a `matched` witness; that function is a
 * 168-byte two-armed cell/node walk which is four transposed instructions
 * away from matching, recorded in docs/notes/sub_02064B68.c.txt.
 *
 * Kept out of unit_0204D4C4.c for exactly this reason: folding it back in
 * would cap that whole range at MATCH for one unattestable word.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D500.c \
 *       --func sub_0204D500 --addr 0x0204D500 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u32 type;
    u8  pad_04[8];
    u8  unk_0c;
};

extern void sub_02064B68(void *p, u32 arg);

void sub_0204D500(struct Obj *o, u32 arg)
{
    sub_02064B68(&o->unk_0c, arg);
}
