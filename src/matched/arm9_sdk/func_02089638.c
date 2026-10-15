/*
 * function: SND_SetChannelVolume
 * address:  0x02089638
 * packet:   pkt_02089638
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetChannelVolume (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void SND_SetChannelVolume(u32 chBitMask, int volume, int shift)
{
    PushCommand_impl(0x14, chBitMask, (u32)volume, (u32)shift, 0);
}
