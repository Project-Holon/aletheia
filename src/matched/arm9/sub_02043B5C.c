/*
 * function: sub_02043B5C
 * address:  0x02043B5C
 * packet:   pkt_020437D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Clears a tiled character buffer to a constant pixel value.  The tile
 * count is (width/8) * (height/8) and the byte count is that times the
 * per-tile size at +8, 0x20 for 4bpp and 0x40 for 8bpp.  In the 4bpp case
 * the fill value is a nibble, so it is replicated into both halves of the
 * byte before the fill.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct CharBuf {
    u8  *pixels;
    u16 width;
    u16 height;
    u16 tileSize;
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

void sub_02043B5C(struct CharBuf *buf, u8 value)
{
    u32 size = ((u32)buf->width >> 3) * ((u32)buf->height >> 3) * buf->tileSize;

    if (buf->tileSize == 0x20) {
        value = (value & 0xf) | ((value & 0xf) << 4);
    }

    MI_CpuFill8(buf->pixels, value, size);
}
