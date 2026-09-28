/*
 * function: func_0208948C
 * address:  0x0208948C
 * packet:   pkt_0208948C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetTrackAllocatableChannel (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_0208948C(int playerNo, u32 trackBitMask, u32 chBitMask)
{
    PushCommand_impl(9, (u32)playerNo, trackBitMask, chBitMask, 0);
}
