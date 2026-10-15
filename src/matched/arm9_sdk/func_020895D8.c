/*
 * function: SND_LockChannel
 * address:  0x020895D8
 * packet:   pkt_020895D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_LockChannel (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void SND_LockChannel(u32 chBitMask, u32 flags)
{
    PushCommand_impl(0x1a, chBitMask, flags, 0, 0);
}
