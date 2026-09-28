/*
 * function: func_020894B4
 * address:  0x020894B4
 * packet:   pkt_020894B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_StartTimer (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_020894B4(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags)
{
    PushCommand_impl(0xc, chBitMask, capBitMask, alarmBitMask, flags);
}
