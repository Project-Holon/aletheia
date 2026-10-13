/*
 * function: BILLBOARD_SetImageFormat
 * address:  0x0204EEC8
 * packet:   pkt_0204EE0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f   0x0209C0A4  arm
 *   gTexSizeTbl  0x020A14C0  data
 *   gTexParamS   0x020A14D4  data
 *   gTexParamT   0x020A14D8  data
 *
 * Seats a billboard cell's texture parameters: the S and T sizes come from
 * the two 3-bit fields of fmt (bits 4..6 and 0..2) as 1 << (n + 3), the
 * three table words go to 0x14/0x18/0x1C, and the two byte ratios at
 * 0x0A/0x0B are the sizes divided by b and c.
 *
 * Source order of the stores decides the prologue's colouring. The three
 * table stores come before the two size stores: with f04 written first the
 * sb field, sb + 3 and the constant 1 rotate through lr/r5/ip (14 bytes
 * out); with f04 after the table loads they land in ip/lr/r5 as the image.
 * The T field is not a named local: as a local it gets its own web and the
 * st half of the same rotation moves; written as `fmt & 7` at both uses it
 * is a CSE temporary and colours as the image.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Cell {
    u8  pad_00[4];
    u16 f04;
    u16 f06;
    u8  f08;
    u8  f09;
    u8  f0a;
    u8  f0b;
    u8  pad_0c[8];
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Pair8 { u32 w; u32 pad; };

extern s32 _s32_div_f(s32 a, s32 b);
extern const u32 gTexSizeTbl[];
extern const struct Pair8 gTexParamS[];
extern const struct Pair8 gTexParamT[];

void BILLBOARD_SetImageFormat(struct Cell *dst, u32 idx, s32 fmt, u32 b, u8 c)
{
    s32 sb = (fmt & 0x70) >> 4;

    dst->f14 = gTexSizeTbl[idx];
    dst->f18 = gTexParamS[sb].w;
    dst->f1c = gTexParamT[fmt & 7].w;
    dst->f04 = 1 << (sb + 3);
    dst->f06 = 1 << ((fmt & 7) + 3);
    dst->f09 = c;
    dst->f08 = b;
    dst->f0a = _s32_div_f(dst->f04, dst->f08);
    dst->f0b = _s32_div_f(dst->f06, dst->f09);
}
