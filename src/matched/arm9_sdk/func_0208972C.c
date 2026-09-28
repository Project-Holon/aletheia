/*
 * function: func_0208972C
 * address:  0x0208972C
 * packet:   pkt_0208972C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetOutputSelector (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_0208972C(int left, int right, int channel1, int channel3)
{
    PushCommand_impl(0x19, (u32)left, (u32)right, (u32)channel1, (u32)channel3);
}
