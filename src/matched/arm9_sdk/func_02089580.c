/*
 * function: func_02089580
 * address:  0x02089580
 * packet:   pkt_02089580
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetTrackMute (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_02089580(int playerNo, u32 trackBitMask, int flag)
{
    PushCommand_impl(8, (u32)playerNo, trackBitMask, flag ? 3 : 0, 0);
}
