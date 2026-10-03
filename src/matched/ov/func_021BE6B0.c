/*
 * function: func_021BE6B0
 * address:  0x021BE6B0
 * packet:   pkt_021BE6B0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0204047C  0x0204047C  arm
 *
 * Four arm9 register writes -- (0,3), (1,1), (3,1), (2,0) -- then a store of 6
 * at +0x1CC; returns the second argument.
 *
 * NOT EXACT.  MATCH: the 34 bytes, the store offset and all four call sites are
 * right, but the target address 0x0204047C has no witness, so match.py leaves
 * every BL/BLX field wildcarded and will not claim the entry.
 *
 * Blocking class: missing witness.  0x0204047C is not a matched entry, not a
 * symbol of layout/symbols_sdk.json, and not a `func_` label of arm9's listing,
 * so neither `matched` nor `sole-ref/code` attests it.  It turns EXACT on its
 * own the moment the arm9 function at 0x0204047C is matched.
 */

typedef unsigned long u32;

extern void sub_0204047C(int idx, unsigned short val);

typedef struct {
    char pad[0x1CC];
    u32 f1CC;
} S;

int func_021BE6B0(S *s, int b)
{
    sub_0204047C(0, 3);
    sub_0204047C(1, 1);
    sub_0204047C(3, 1);
    sub_0204047C(2, 0);
    s->f1CC = 6;

    return b;
}
