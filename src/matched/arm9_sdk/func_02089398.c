/*
 * function: SND_PauseSeq
 * address:  0x02089398
 * packet:   pkt_02089398
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_PauseSeq (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void SND_PauseSeq(int playerNo, int flag)
{
    PushCommand_impl(4, (u32)playerNo, (u32)flag, 0, 0);
}
