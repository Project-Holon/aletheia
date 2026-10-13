/*
 * function: SND_SetTrackModDepth
 * address:  0x02089454
 * packet:   pkt_02089454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020897DC 0x020897DC arm
 */

typedef unsigned int u32;
extern void func_020897DC(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size);

void SND_SetTrackModDepth(int playerNo, u32 trackBitMask, u32 depth)
{
    func_020897DC(playerNo, trackBitMask, 0x1a, (u32)depth, 1);
}
