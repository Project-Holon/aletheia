/*
 * function: NNSi_SndArcDisposeWaveArcTable
 * address:  0x020752D4
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * See src/matched/NNSi_SndArcDisposeWaveArc.c: the pair is deliberately not one unit.
 *
 * symbols:
 *   NNSi_SndArcForgetFileAddress  0x020751F4  arm
 *   SND_DestroyWaveArc  0x0208A424  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void NNSi_SndArcForgetFileAddress(u32 a, u32 b, u32 c);
struct SNDWaveArc;
extern void SND_DestroyWaveArc(struct SNDWaveArc *waveArc);

void NNSi_SndArcDisposeWaveArcTable(int a, int b, int c, int d)
{
    NNSi_SndArcForgetFileAddress(a, c, d);
    SND_DestroyWaveArc((struct SNDWaveArc *)a);
}
