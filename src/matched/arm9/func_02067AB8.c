/*
 * function: func_02067AB8
 * address:  0x02067AB8
 * packet:   pkt_02067AAC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled two-instruction leaf of the NNS G2D cell-to-OAM composer
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): the setter
 * for the mode word at +0x04 of the composer state whose flip lane is
 * src/matched/unit_02067B40.c.
 *
 * Decompiled so that it becomes a `matched` witness for the call at
 * 0x0204CBB0+0x1c (src/matched/func_0204CBB0.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067AB8.c \
 *       --func func_02067AB8 --addr 0x02067AB8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct G2dOamState {
    u8  pad_00[4];
    u32 mode;   /* 0x04 */
};

void func_02067AB8(struct G2dOamState *p, u32 mode)
{
    p->mode = mode;
}
