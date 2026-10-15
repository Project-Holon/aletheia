/*
 * function: NNSi_SndArcDisposeWaveArc
 * address:  0x020752A4
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Kept as its own file rather than folded with NNSi_SndArcDisposeWaveArcTable, its immediate
 *  * neighbour: the two are the only callers of 0x0208A424 anywhere in the image,
 *  * so any range holding both has no witness left for that site and caps at
 *  * MATCH. Split, each file is the other's witness.
 *
 * symbols:
 *   NNSi_SndArcForgetFileAddress  0x020751F4  arm
 *   SND_InvalidateWaveData  0x020896EC  arm
 *   SND_DestroyWaveArc  0x0208A424  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void NNSi_SndArcForgetFileAddress(u32 a, u32 b, u32 c);
struct SNDWaveArc;
extern void SND_InvalidateWaveData(const void *start, const void *end);
extern void SND_DestroyWaveArc(struct SNDWaveArc *waveArc);

void NNSi_SndArcDisposeWaveArc(int a, int b, int c, int d)
{
    NNSi_SndArcForgetFileAddress(a, c, d);
    SND_InvalidateWaveData((const void *)a, (const void *)(a + b));
    SND_DestroyWaveArc((struct SNDWaveArc *)a);
}
