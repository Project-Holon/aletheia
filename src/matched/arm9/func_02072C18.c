/*
 * function: NNS_SndWaveOutSetVolume
 * address:  0x02072C18
 * packet:   pkt_02072A44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SND_SetChannelVolume  0x02089638  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct S { u32 f0; u32 f4; u32 f8; };
extern void SND_SetChannelVolume(u32 chBitMask, int volume, int shift);

void NNS_SndWaveOutSetVolume(struct S *s, u32 v)
{
    if (s->f8 == 0) return;
    SND_SetChannelVolume(1 << s->f0, v, 0);
}
