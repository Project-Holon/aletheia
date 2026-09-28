/*
 * function: func_02089330
 * address:  0x02089330
 * packet:   pkt_02089330
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_StopSeq (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_02089330(int playerNo)
{
    PushCommand_impl(1, (u32)playerNo, 0, 0, 0);
}
