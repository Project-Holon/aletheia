/*
 * function: SND_SetPlayerVolume
 * address:  0x020893D0
 * packet:   pkt_020893D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SNDi_SetPlayerParam 0x020897B4 arm
 */

typedef unsigned int   u32;
extern void SNDi_SetPlayerParam(int playerNo, u32 offset, u32 data, int size);

void SND_SetPlayerVolume(int playerNo, int volume)
{
    SNDi_SetPlayerParam(playerNo, 0x6, (u32)volume, 2);
}
