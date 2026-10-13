/*
 * function: sub_02040588
 * address:  0x02040588
 * packet:   pkt_0203FC6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *
 * Eight-way dispatch turning a small selector into a one-hot plane mask for
 * one of the two 2D engines: selectors 0..3 go to the engine-A visible-plane
 * toggle at BG_SYS_SetMainPlaneVisible with masks 1/2/4/8 and selectors 4..7 to the
 * engine-B toggle at BG_SYS_SetSubPlaneVisible with the same four.  The on/off flag is
 * the second parameter and is forwarded untouched in r1, which is why no
 * argument setup other than the mask appears in any arm.  The ARM form
 * of the dense switch is `cmp #7` plus `addls pc, pc, r0, lsl #2` over a
 * run of eight branches, with the out-of-range case falling straight into
 * the epilogue.
 */

typedef unsigned int u32;

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void sub_02040588(unsigned char which, unsigned char enable)
{
    switch (which) {
    case 0:
        BG_SYS_SetMainPlaneVisible(1, enable);
        break;
    case 1:
        BG_SYS_SetMainPlaneVisible(2, enable);
        break;
    case 2:
        BG_SYS_SetMainPlaneVisible(4, enable);
        break;
    case 3:
        BG_SYS_SetMainPlaneVisible(8, enable);
        break;
    case 4:
        BG_SYS_SetSubPlaneVisible(1, enable);
        break;
    case 5:
        BG_SYS_SetSubPlaneVisible(2, enable);
        break;
    case 6:
        BG_SYS_SetSubPlaneVisible(4, enable);
        break;
    case 7:
        BG_SYS_SetSubPlaneVisible(8, enable);
        break;
    }
}
