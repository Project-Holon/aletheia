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
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern u32 func_0208A674(u32, u32);
extern void func_0208A640(u32, u32, u32);
extern void func_020896EC(const void *start, const void *end);
void NNSi_SndArcDisposeWave(u32 a, u32 n, u32 x, u32 y) {
    if (func_0208A674(x, y) == a) func_0208A640(x, y, 0);
    func_020896EC((const void *)a, (const void *)(a + n));
}
