/*
 * function: func_020897DC
 * address:  0x020897DC
 * packet:   pkt_020897DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SNDi_SetTrackParam (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_020897DC(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size)
{
    PushCommand_impl(7, (u32)(playerNo | (size << 24)), trackBitMask, offset, data);
}
