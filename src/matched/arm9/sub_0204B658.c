/*
 * unit:     no
 * function: sub_0204B658
 * address:  0x0204B658
 * packet:   pkt_0204B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The test side of sub_0204B604 in src/matched/unit_0204B5F4.c: is bit
 * `which` of the two-bit field at bits 20..21 of the flag word at +0x60 set.
 *
 * The mask is not built into a register here the way the setter builds it.
 * Each arm carries its own constant `tst`, and the `movne r1, #1` that both
 * arms reach is the shared exit
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md), so the
 * result has to be a named local initialised to zero before the branch and
 * assigned in both arms, not a returned expression.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B658.c \
 *       --func sub_0204B658 --addr 0x0204B658 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Actor {
    u8  pad_00[0x60];
    u32 f_00 : 8;
    u32 f_08 : 4;
    u32 f_0c : 6;
    u32 f_12 : 2;
    u32 f_14 : 2;
    u32 f_16 : 2;
    u32 f_18 : 8;
};

u32 sub_0204B658(const struct Actor *actor, u32 which)
{
    u32 result = 0;

    if (which == 0) {
        if ((actor->f_14 & 1) != 0) {
            result = 1;
        }
    } else {
        if ((actor->f_14 & 2) != 0) {
            result = 1;
        }
    }

    return result;
}
