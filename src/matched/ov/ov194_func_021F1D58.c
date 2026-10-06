/*
 * function: func_021F1D58
 * address:  0x021F1D58
 * packet:   pkt_ov194_021F1D58
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wD9r lane18): closed by the NitroSDK FX_CosIdx inline for the table read
 *   (earlier drafts wrote the raw tbl[(*phase >> 4) * 2 + 1] expression) and the ov105 021B8734
 *   lerp body (u8 r, g, blue; int dr, dg, db) with g before the cosine and an s16 t.
 *
 * symbols:
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 */
typedef unsigned char u8;
typedef short s16;
typedef s16 fx16;
typedef unsigned short u16;
typedef unsigned int u32;
extern fx16 FX_SinCosTable_[];
static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1) + 1]; }
typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
int func_021F1D58(u16 *out, u16 *phase, u32 step, u32 row, u8 idx, u16 a, u16 b)
{
    u8 r, g, blue; int dr, dg, db; s16 t;
    int ph = *phase + step;
    if (ph >= 0x10000) *phase = ph - 0x10000;
    else *phase = ph;
    g = (a & 0x3E0) >> 5;
    t = (FX_CosIdx(*phase) + 0x1000) / 2;
    r = a & 31;
    blue = (a & 0x7C00) >> 10;
    db = ((u8)((b & 0x7C00) >> 10) - blue) * t >> 12;
    dr = ((u8)(b & 31) - r) * t >> 12;
    dg = ((u8)((b & 0x3E0) >> 5) - g) * t >> 12;
    *out = (u8)(r + dr) | ((u8)(g + dg) << 5) | ((u8)(blue + db) << 10);
    func_02061CA4((void *)0xF, row * 32 + idx * 2, (u32)out, 2);
    return *out == b;
}
