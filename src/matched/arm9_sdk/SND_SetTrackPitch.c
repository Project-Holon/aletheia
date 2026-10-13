/*
 * function: SND_SetTrackPitch
 * address:  0x0208941C
 * packet:   pkt_0208941C
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

void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch)
{
    func_020897DC(playerNo, trackBitMask, 0xc, (u32)pitch, 2);
}
