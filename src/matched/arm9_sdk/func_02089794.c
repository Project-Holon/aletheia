/*
 * function: func_02089794
 * address:  0x02089794
 * packet:   pkt_02089794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_ReadDriverInfo (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

struct SNDDriverInfo;

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_02089794(struct SNDDriverInfo *info)
{
    PushCommand_impl(0x21, (u32)info, 0, 0, 0);
}
