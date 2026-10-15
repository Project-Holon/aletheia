/*
 * function: SND_SetMasterPan
 * address:  0x02089754
 * packet:   pkt_02089754
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetMasterPan (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void SND_SetMasterPan(int pan)
{
    PushCommand_impl(0x18, (u32)pan, 0, 0, 0);
}
