/*
 * unit:     no
 * address:  0x020222CC
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020222CC
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *
 * Selects one of two hardware register addresses (0x0400006C, 0x0400106C:
 * the master brightness registers of the two DS display engines) from its
 * first argument and passes it to func_0207D534 together with the second
 * argument, the brightness level, which stays in r1 untouched (an argument
 * passed through a register must be named in the C).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020222CC.c \
 *       --func func_020222CC --addr 0x020222CC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void func_0207D534(u32 reg, int brightness);

void func_020222CC(u32 which, int brightness)
{
    if (which == 0) {
        func_0207D534(0x0400006C, brightness);
    } else {
        func_0207D534(0x0400106C, brightness);
    }
}
