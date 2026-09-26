/*
 * function: func_021C1F04
 * address:  0x021C1F04
 * packet:   pkt_ov172_021C1F04
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * Blocker: codegen scheduling only.  This is the RGB555 -> planar YCbCr
 *          converter (three padded planes, `(w+7)&~7` stride).  The unsigned
 *          `i % stride` correctly selects _u32_div_f at 0x0209C2B0 and the
 *          channel extraction masks line up, but compiled size is 328 vs 332
 *          and mwccarm runs out of registers: it spills i*2 to the stack and
 *          keeps `w` in a stack slot, where the original keeps i*2 in r7 and
 *          w in r5.  The 2b3/54d/6b3/14d fixed-point coefficient expressions
 *          also reassociate slightly.  See docs/notes/pkt_ov172_021C1F04.c.txt.
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 _u32_div_f(u32, u32);

void func_021C1F04(u16 *src, u32 w, u32 h, u8 *dst)
{
    u32 stride = (w + 7) & ~7;
    u32 hpad = (h + 7) & ~7;
    u32 area = stride * hpad;
    u8 *d0 = dst;
    u8 *d1 = dst + area;
    u8 *d2 = d1 + area;
    u32 i;

    for (i = 0; i < area; i++) {
        u32 v = 0;
        u32 r, g, b;

        if (i % stride < w)
            v = *src++;

        g = (v & 0x3e0) >> 2;
        r = (v & 0x1f) << 3;
        b = (v & 0x7c00) >> 7;

        d0[i] = (u8)((g * 0x964 + r * 0x4c9 + b * 0x1d3 + 0x800) >> 12);
        {
            u32 u = (0x80800 - r * 0x2b3 - g * 0x54d + (b << 11)) >> 12;
            if (u > 0xff)
                u = 0xff;
            d1[i] = (u8)u;
        }
        {
            u32 u = ((r << 11) + 0x80800 - g * 0x6b3 - b * 0x14d) >> 12;
            if (u > 0xff)
                u = 0xff;
            d2[i] = (u8)u;
        }
    }
}
