/*
 * function: NNS_G2dSetCellAnimationSpeed
 * address:  0x020643C4
 * packet:   pkt_02064364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * Stores the multi-cell animation's user callback/context word at +0x14.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetCellAnimationSpeed.c  *       --func NNS_G2dSetCellAnimationSpeed --addr 0x020643C4 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct MultiCellAnim {
    u8 pad00[0x14];
    u32 unk14;
};

void NNS_G2dSetCellAnimationSpeed(struct MultiCellAnim *mca, u32 value)
{
    mca->unk14 = value;
}
