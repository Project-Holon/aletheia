/*
 * function: SND_SetPlayerTempoRatio
 * address:  0x020893B8
 * packet:   pkt_020893B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020897B4 0x020897B4 arm
 */

typedef unsigned int   u32;
extern void func_020897B4(int playerNo, u32 offset, u32 data, int size);

void SND_SetPlayerTempoRatio(int playerNo, int ratio)
{
    func_020897B4(playerNo, 0x1a, (u32)ratio, 2);
}
