/*
 * function: func_02009020
 * address:  0x02009020
 * packet:   pkt_02009020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009074  0x02009074  thumb
 *
 * Tail call to func_02009074 with the count 0x14: the twenty-element table
 * of 0x38-byte objects described in src/matched/unit_02008FFC.c.  That file
 * left it out as a near miss because the pool word was the only reference to
 * 0x02009074; func_02009074 is now matched (src/matched/unit_02009050.c), so
 * the relocation attests through the `matched` class.  Seeded from ov119
 * 0x021E062E (tree_ov170_3).
 *
 * Addresses are Black-image addresses.
 */

struct Sub02008F80Obj;
extern int func_02009074(struct Sub02008F80Obj *arr, int n);

void func_02009020(void *table)
{
    func_02009074(table, 0x14);
}
