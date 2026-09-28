/*
 * function: func_020896AC
 * address:  0x020896AC
 * packet:   pkt_020896AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_InvalidateSeqData (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_020896AC(const void *start, const void *end)
{
    PushCommand_impl(0x1e, (u32)start, (u32)end, 0, 0);
}
