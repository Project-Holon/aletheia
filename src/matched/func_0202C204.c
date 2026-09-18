/*
 * function: func_0202C204
 * address:  0x0202C204
 * packet:   pkt_0202C148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the object's first word when it is non-zero.  Unlabelled in the
 * listing (no lr save) and absent from the worklist; filed from the bytes.
 * It is the tail-call target of the thunk at 0x0202C0C0, which is what
 * src/pending/func_0202B704.c is blocked on.
 *
 * symbols:
 *   sub_0202C2D8  0x0202C2D8  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C204.c \
 *       --func func_0202C204 --addr 0x0202C204 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32 sub_0202C2D8(u32 *p);

void func_0202C204(u32 *p)
{
    if (sub_0202C2D8(p) != 0) {
        *p = 0;
    }
}
