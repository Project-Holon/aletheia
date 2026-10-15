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
 * function: WIPE_SetBrightness
 *
 * symbols:
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *
 * Selects one of two hardware register addresses (0x0400006C, 0x0400106C:
 * the master brightness registers of the two DS display engines) from its
 * first argument and passes it to GXx_SetMasterBrightness_ together with the second
 * argument, the brightness level, which stays in r1 untouched (an argument
 * passed through a register must be named in the C).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SetBrightness.c \
 *       --func WIPE_SetBrightness --addr 0x020222CC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);

void WIPE_SetBrightness(u32 which, int brightness)
{
    if (which == 0) {
        GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, brightness);
    } else {
        GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, brightness);
    }
}
