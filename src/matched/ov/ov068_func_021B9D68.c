/*
 * function: func_021B9D68
 * address:  0x021B9D68
 * packet:   pkt_ov068_021B9D68
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BGR555 cross-fade of one palette entry: advance the u16 phase at *ang by
 * inc (wrapping at 0x10000), take f = (table[phase >> 4 pair, second entry]
 * + 0x1000) / 2 as an s16 from the table at 0x020A1B38, blend each channel
 * of c0 toward c1 by f >> 12, store to *out and hand it to func_02061CA4.
 * Twin: arm9 func_0202EA40 (blink_palanm.c).  What closed it: all six
 * channels as u8 locals extracted in mask-then-shift form, the blended
 * channels as s32 with a u8 cast, and the pack `(b << 10) | (r | (g << 5))`
 * (the channel ORed last is evaluated first: blue, red, green).  Shift-then-
 * mask extraction, or the unnested pack, compiles 184 bytes.
 *
 * symbols:
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02061CA4  0x02061CA4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern s16  d_020A1B38[];
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

void func_021B9D68(u16 *out, u16 *ang, int inc, u32 idx, u8 slot, u16 c0, u16 c1)
{
    int t;
    s16 f;
    u8 r0, g0, b0, r1, g1, b1;
    s32 r, g, b;

    t = *ang + inc;
    if (t >= 0x10000) {
        *ang = t - 0x10000;
    } else {
        *ang = t;
    }
    f = (d_020A1B38[((*ang >> 4) << 1) + 1] + 0x1000) / 2;
    r0 = c0 & 0x1f;
    g0 = (c0 & 0x3e0) >> 5;
    b0 = (c0 & 0x7c00) >> 10;
    r1 = c1 & 0x1f;
    g1 = (c1 & 0x3e0) >> 5;
    b1 = (c1 & 0x7c00) >> 10;
    b = (u8)(b0 + (((b1 - b0) * f) >> 12));
    r = (u8)(r0 + (((r1 - r0) * f) >> 12));
    g = (u8)(g0 + (((g1 - g0) * f) >> 12));
    *out = (u16)((b << 10) | (r | (g << 5)));
    func_02061CA4((void *)15, idx * 32 + slot * 2, (u32)out, 2);
}
