/*
 * function: NNSi_SndArcDisposeWave
 * address:  0x020752F4
 * packet:   pkt_020752F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SND_InvalidateWaveData  0x020896EC  arm
 *   SND_SetWaveDataAddress  0x0208A640  arm
 *   SND_GetWaveDataAddress  0x0208A674  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern u32 SND_GetWaveDataAddress(u32, u32);
extern void SND_SetWaveDataAddress(u32, u32, u32);
extern void SND_InvalidateWaveData(const void *start, const void *end);
void NNSi_SndArcDisposeWave(u32 a, u32 n, u32 x, u32 y) {
    if (SND_GetWaveDataAddress(x, y) == a) SND_SetWaveDataAddress(x, y, 0);
    SND_InvalidateWaveData((const void *)a, (const void *)(a + n));
}
