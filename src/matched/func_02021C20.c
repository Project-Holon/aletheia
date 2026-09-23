/*
 * function: func_02021C20
 * address:  0x02021C20
 * packet:   pkt_02021C20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * palanm.c: the per-pixel RGB555 blend loop.  Each channel of src[i] moves
 * weight/16 of the way toward the matching channel of the anim sub-object's
 * 15-bit target colour; the result is written to dst[i].
 *
 * Closed in wave 13 by the shape func_0202EA40 (blink_palanm.c) proved the
 * same day: the source pixel and the target are u16 LOCALS (an `int` pixel
 * is 20 bytes out), the channel extractions are written inline in each
 * blend rather than bound to sb/sg/sr locals, and the pack is
 * `r | ((b << 10) | (g << 5))` -- the channel ORed last is the one the
 * compiler evaluates first, which is the image's red, blue, green order.
 * The earlier 69-byte reading (int px, t/w/sb/sg/sr locals) is in
 * docs/notes/func_02021C20.c.txt.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;

struct C02021C20 {
    u16 f0;
    u16 lo6 : 6;
    u16 weight : 5;
    u16 hi : 5;
    u16 target : 15;
    u16 sign : 1;
};

void func_02021C20(u16 *src, u16 *dst, struct C02021C20 *c, u32 count)
{
    u32 i;
    u16 a;
    u16 t;
    s32 r;
    s32 g;
    s32 b;

    for (i = 0; i < count; i++) {
        a = src[i];
        t = c->target;
        r = (u8)((a & 0x1f) + ((((t & 0x1f) - (a & 0x1f)) * c->weight) >> 4));
        b = (u8)(((a >> 10) & 0x1f) + (((((t >> 10) & 0x1f) - ((a >> 10) & 0x1f)) * c->weight) >> 4));
        g = (u8)(((a >> 5) & 0x1f) + (((((t >> 5) & 0x1f) - ((a >> 5) & 0x1f)) * c->weight) >> 4));
        dst[i] = (u16)(r | ((b << 10) | (g << 5)));
    }
}
