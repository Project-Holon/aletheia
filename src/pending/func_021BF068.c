/*
 * function: func_021BF068
 * address:  0x021BF068
 * packet:   pkt_021BF068
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   sub_0203C3EC  0x0203C3EC  arm
 *
 * Channel-id predicate: true when sub_0203C3EC() answers 3, 4 or 5.
 * `push {r3, lr}; blx; cmp r0, #3; beq; cmp r0, #4; beq; cmp r0, #5; bne;
 * movs r0, #1; pop; movs r0, #0; pop`.
 *
 * NOT EXACT.  MATCH: same size, same instruction multiset, and the single
 * relocation is right, but the target address 0x0203C3EC has no witness.
 *
 * Blocking class: missing witness, the same one as func_021BF03C.  0x0203C3EC
 * is neither matched, nor an SDK symbol, nor a labelled function start in
 * arm9's listing, so the BL/BLX field stays wildcarded.  Both entries go
 * EXACT together when the arm9 function at 0x0203C3EC is matched.
 */

typedef int BOOL;

extern int sub_0203C3EC(void);

BOOL func_021BF068(void)
{
    int v = sub_0203C3EC();

    if (v == 3 || v == 4 || v == 5) {
        return 1;
    }

    return 0;
}
