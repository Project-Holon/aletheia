/*
 * function: SND_SetupChannelPcm
 * address:  0x02089660
 * packet:   pkt_02089660
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetupChannelPcm (snd_interface.o)
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void SND_SetupChannelPcm(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan)
{
    PushCommand_impl(0xe, (u32)(chNo | (timer << 16)), (u32)dataaddr, (u32)((volume << 24) | (shift << 22) | loopLen), (u32)((loop << 26) | (format << 24) | (pan << 16) | loopStart));
}
