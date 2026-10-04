/*
 * function: func_0203FA08
 * address:  0x0203FA08
 * packet:   pkt_0203FA08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44    0x02146A44  data
 *   func_020416B8 0x020416B8  arm
 *   func_02033CC0 0x02033CC0  arm
 *   func_02033F64 0x02033F64  arm
 *   _u32_div_f    0x0209C2B0  arm
 *
 * Allocate a run of tiles for a layer in its arena, bottom-up (top == 0,
 * func_02033CC0) or top-down (func_02033F64), and return the tile index of
 * the run relative to the layer's tile base, or -1.  Closed in wave 11:
 * the arena base is selected into a local BEFORE the direction test, the
 * round-up flag is `f = (size % t != 0)` (remainder taken first, then the
 * quotient), and the tile stride `t` is an int local (tools/permuter.py,
 * type:l(t:u32->int)); every divide stays unsigned because each dividend
 * is u32.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *g_02146A44;
extern u8 func_020416B8(int channel);
typedef signed int     s32;
struct AreaMan;
extern s32 func_02033CC0(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern u32 func_02033F64(u32 arena, u32 a, u32 b, u32 c);

u32 func_0203FA08(u32 layer, u32 size, u32 top)
{
    int t = func_020416B8(layer & 0xff);
    u8 *g = g_02146A44;
    u32 d1 = *(u32 *)(g + 0x170 + layer * 4) / t;
    u32 d2 = *(u32 *)(g + 0x1b0 + layer * 4) / t;
    u32 f;
    u32 n, r, base;

    f = (size % t != 0);
    n = size / t;
    base = (layer < 4) ? *(u32 *)(g + 0x168) : *(u32 *)(g + 0x16c);
    if (top == 0)
        r = func_02033CC0((struct AreaMan *)base, d1, d2, n + f);
    else
        r = func_02033F64(base, d1 + d2 - 1, d2, n + f);
    if (r == 0xFFFFFFFF)
        return 0xFFFFFFFF;
    return (r * t - *(u32 *)(g_02146A44 + 0x170 + layer * 4)) / t;
}
