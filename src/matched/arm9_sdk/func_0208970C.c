/*
 * function: func_0208970C
 * address:  0x0208970C
 * packet:   pkt_0208970C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetMasterVolume (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_0208970C(int volume)
{
    PushCommand_impl(0x17, (u32)volume, 0, 0, 0);
}
