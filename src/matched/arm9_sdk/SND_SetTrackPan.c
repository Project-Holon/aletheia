/*
 * function: SND_SetTrackPan
 * address:  0x02089438
 * packet:   pkt_02089438
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

void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan)
{
    SNDi_SetTrackParam(playerNo, trackBitMask, 0x9, (u32)pan, 1);
}
