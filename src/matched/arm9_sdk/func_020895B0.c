/*
 * function: func_020895B0
 * address:  0x020895B0
 * packet:   pkt_020895B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetTrackMuteEx (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_020895B0(int playerNo, u32 trackBitMask, int mute)
{
    PushCommand_impl(8, (u32)playerNo, trackBitMask, (u32)mute, 0);
}
