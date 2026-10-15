/*
 * function: SND_SetChannelTimer
 * address:  0x02089618
 * packet:   pkt_02089618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetChannelTimer (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void SND_SetChannelTimer(u32 chBitMask, int timer)
{
    PushCommand_impl(0x13, chBitMask, (u32)timer, 0, 0);
}
