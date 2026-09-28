/*
 * function: func_02089350
 * address:  0x02089350
 * packet:   pkt_02089350
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_PrepareSeq (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

struct SNDBankData;

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_02089350(int playerNo, const void *base, u32 offset, struct SNDBankData *bank)
{
    PushCommand_impl(2, (u32)playerNo, (u32)base, offset, (u32)bank);
}
