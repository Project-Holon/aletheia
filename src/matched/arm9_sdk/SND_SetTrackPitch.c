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
 *   SNDi_SetTrackParam 0x020897DC arm
 */

typedef unsigned int u32;
extern void SNDi_SetTrackParam(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size);

void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch)
{
    SNDi_SetTrackParam(playerNo, trackBitMask, 0xc, (u32)pitch, 2);
}
