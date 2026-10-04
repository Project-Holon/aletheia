/*
 * function: func_021F1D58
 * address:  0x021F1D58
 * packet:   pkt_ov194_021F1D58
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04): lane17 wave D2: 204 bytes vs 208, first draft. Logic: phase += step with wrap at 0x10000 (signed int compare), t = (s16)((tbl_020A1B38[(phase >> 4) * 2 + 1] + 0x1000) / 2), per-channel RGB555 lerp (a + ((b - a) * t >> 12)), write u16, call func_02061CA4(0xF, row * 32 + idx * 2, out, 2), return *out == b. Residue: original copies the phase pointer to r0 first (adds r0,r1,#0; ldrh r1,[r0]) and reads the stack colour args a (r5) and b (r3) before the table lookup; ours loads a/b after t. Try computing the channels of a before t and keeping phase in a local pointer.
 *
 * symbols:
 *   tbl_020A1B38  0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
extern s16 tbl_020A1B38[];
extern int func_02061CA4(u32 ch, u32 off, u16 *src, u32 size);

int func_021F1D58(u16 *out, u16 *phase, u32 step, u32 row, u8 idx, u16 a, u16 b)
{
    int ph = *phase + step;
    int t;
    u32 r0, g0, b0, r1, g1, b1;
    if (ph >= 0x10000) *phase = ph - 0x10000;
    else *phase = ph;
    t = (s16)((tbl_020A1B38[(*phase >> 4) * 2 + 1] + 0x1000) / 2);
    r0 = (u8)(a & 0x1F);
    g0 = (u8)((a & 0x3E0) >> 5);
    b0 = (u8)((a & 0x7C00) >> 10);
    r1 = (u8)(b & 0x1F);
    g1 = (u8)((b & 0x3E0) >> 5);
    b1 = (u8)((b & 0x7C00) >> 10);
    r0 = (u8)(r0 + (((int)(r1 - r0) * t) >> 12));
    g0 = (u8)(g0 + (((int)(g1 - g0) * t) >> 12));
    b0 = (u8)(b0 + (((int)(b1 - b0) * t) >> 12));
    *out = (u16)(r0 | (g0 << 5) | (b0 << 10));
    func_02061CA4(0xF, row * 32 + idx * 2, out, 2);
    return *out == b;
}
