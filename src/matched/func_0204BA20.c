/*
 * function: func_0204BA20
 * address:  0x0204BA20
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Store the logical negation of the argument into bit 0 of the cell actor's
 * +0x64 flag word.  A leaf: no lr saved, no relocation.
 *
 * The bit has to be written as an `if`/`else` with a literal in each arm.
 * The assignment form `a->hidden = (v == 0)` materialises the boolean first
 * (`moveq r1, #1` / `movne r1, #0` / `and r1, r1, #1`) and then inserts it,
 * twelve bytes longer; only the two-arm form lets the compiler clear the bit
 * once with `bic` and predicate the set back onto the entry compare.  See
 * docs/idioms/a-one-bit-bitfield-wants-two-arms-not-a-boolean.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BA20.c \
 *       --func func_0204BA20 --addr 0x0204BA20 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Actor {
    u8  pad_00[0x64];
    u32 hidden : 1;    /* 0x64, bit 0 */
    u32 pad_64 : 31;
};

void func_0204BA20(struct Actor *a, u32 v)
{
    if (v == 0) {
        a->hidden = 1;
    } else {
        a->hidden = 0;
    }
}
