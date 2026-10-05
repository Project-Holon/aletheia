/*
 * function: func_021E5A30
 * address: 0x021E5A30
 * packet: pkt_ov177_021E5A30
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note: 2026-10-02 lane07: DIFF, 172 bytes. Channel unpack/blend scheduling differs (orig reads c0 via add r1,sp,#0x18 before table load, builds 0x1f<<10 mask by reusing the 0x1f register, blend order B,R,G). Tried u8 locals, decl orders, shifted-mask forms.
 * note 2026-10-05: orig packs `(g << 5) | r | (b << 10)` (orrs g5,r then b10); tried that order:
 * the compiler then rebuilds 0x1f from a shifted register and the function shrinks to 156 B (orig 172).
 * The original keeps c0 in r6 and c1 in r1 and builds each mask with its own movs/lsls; no source form
 * found that reproduces this. Still DIFF.
 *
 * symbols:
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_02061CA4    0x02061CA4  arm
 */
extern const short FX_SinCosTable_[];
extern int func_02061CA4(int, int, void *, int);
void func_021E5A30(int slot, unsigned short *out, const unsigned short *phase, int unused, unsigned char a, unsigned char b, unsigned short c0, unsigned short c1)
{
    int t = (short)((FX_SinCosTable_[(*phase >> 4) * 2 + 1] + 0x1000) / 2);
    unsigned char g0 = (c0 & 0x3e0) >> 5, r0 = c0 & 0x1f, b0 = (c0 & 0x7c00) >> 10;
    unsigned char bl = b0 + ((((c1 & 0x7c00) >> 10) - b0) * t >> 12);
    unsigned char r = r0 + (((c1 & 0x1f) - r0) * t >> 12);
    unsigned char g = g0 + ((((c1 & 0x3e0) >> 5) - g0) * t >> 12);
    *out = (bl << 10) | (g << 5) | r;
    func_02061CA4(slot, a * 32 + b * 2, out, 2);
}
