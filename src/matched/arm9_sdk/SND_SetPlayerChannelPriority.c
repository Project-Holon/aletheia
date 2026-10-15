/*
 * function: SND_SetPlayerChannelPriority
 * address:  0x020893E8
 * packet:   pkt_020893E8
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

void SND_SetPlayerChannelPriority(int playerNo, int prio)
{
    SNDi_SetPlayerParam(playerNo, 0x4, (u32)prio, 1);
}
