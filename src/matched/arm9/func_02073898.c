/*
 * function: NNS_SndStrmFreeChannel
 * address:  0x02073898
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Releases the registered slot when one is held: the mask to drop is the value
 *  * in +0x4c itself, and the same zero then clears +0x4c and +0x50 out of one
 *  * `mov r0, #0`.
 *
 * symbols:
 *   SND_CHANNEL_UnlockChannels  0x02072974  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct X { u8 pad00[0x4c]; u32 f4c; u32 f50; };
extern void SND_CHANNEL_UnlockChannels(u32);

void NNS_SndStrmFreeChannel(struct X *x)
{
    if (x->f4c == 0) return;
    SND_CHANNEL_UnlockChannels(x->f4c);
    x->f4c = 0;
    x->f50 = 0;
}
