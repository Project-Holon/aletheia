/*
 * function: func_020127B8
 * address:  0x020127B8
 * packet:   pkt_020127B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020127AC  0x020127AC  thumb
 *
 * Promoted from src/pending/func_020127B8.c (was MATCH, blocker 0x020127AC,
 * declared by the naming convention, which defaults to ARM).  The pool word
 * is 0x020127AD, so the target is Thumb; declared `thumb` the `matched`
 * class fires on the EXACT unit entry for 0x020127AC
 * (src/matched/unit_020127A4.c, which names it as a member function) and
 * the site resolves with no change to the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020127B8.c \
 *       --func func_020127B8 --addr 0x020127B8 --cc 1.1p1 --thumb
 */

typedef unsigned int   u32;
struct SaveBlock;
extern void *func_020127AC(struct SaveBlock *p, u32 idx);

void func_020127B8(void *p)
{
    func_020127AC(p, 3);
}
