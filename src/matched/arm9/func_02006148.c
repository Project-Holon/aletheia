/*
 * function: func_02006148
 * address:  0x02006148
 * packet:   pkt_02006148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207430C  0x0207430C  arm
 *
 * Two `return 1`s cross-jump into one block, and the block lands between the
 * second test and the body - which is what makes the second branch `blo`
 * (branch on the *acceptance* test to the body) rather than the `bhs` a
 * conjunction emits.  So the source has the two guards in this order, each
 * with its own return, and the last `return 1` is the one that ends up as
 * the shared block.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006148.c \
 *       --func func_02006148 --addr 0x02006148 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *func_0207430C(int index);

int func_02006148(u32 a0)
{
    if (a0 < 0x546) {
        goto fail;
    }
    if (a0 < 0x81B) {
        goto ok;
    }
fail:
    return 1;
ok:
    return func_0207430C(a0)[5] - 1;
}
