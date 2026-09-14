/*
 * function: sub_0200FB24
 * address:  0x0200FB24
 * packet:   pkt_0200F83C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A getter on the module-wide object at 0x0214617C (the same object
 * unit_0200F7C0.c names sub_0200F7C0_Obj): returns field +0x5c when field
 * +0x2c is set, 0 otherwise.
 *
 * EXACT* because the 20 compiled bytes fall 52 short of the disasm.py
 * extent: an unlabelled follower, sub_0200FB38, hides in the run of
 * literal-pool .word data right after this function (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * sub_0200FB38 itself (a conditional store: bump the object's +0x2c field
 * from 1 to 2) is a documented near miss: every write attempt reproduces
 * all twenty bytes but with r0 and r1 swapped throughout, a pure
 * register-numbering difference no source restructuring here changed, in
 * the same class as the codegen near misses in docs/MATCHING.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FB24.c \
 *       --func sub_0200FB24 --addr 0x0200FB24 --cc 1.1p1
 */

typedef unsigned int u32;

u32 sub_0200FB24(void)
{
    u32 *obj = (u32 *)0x0214617C;

    if (obj[0x2c / 4] != 0) {
        return obj[0x5c / 4];
    }
    return 0;
}
