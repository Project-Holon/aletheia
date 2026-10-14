/*
 * function: DRAW_SYSTEM_PutPixel
 * address:  0x021B6E5C
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Bounds-checks the two indices and stores the pixel into the +0xa8 plane.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void DRAW_SYSTEM_PutPixel(unsigned short *p, char *base, unsigned x, unsigned y,
                          unsigned short v);

void DRAW_SYSTEM_PutPixel(unsigned short *p, char *base, unsigned x, unsigned y,
                  unsigned short v)
{
    if (x >= p[4] && x < p[5] && y >= p[6] && y < p[7]) {
        *(u16 *)(base + x * 2 + y * 512) = v;
    }
}
