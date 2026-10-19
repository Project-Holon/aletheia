/*
 * function: TEXT_TEXTURE_ClearBitmap
 * address:  0x0216FC50
 * packet:   pkt_ov010_0216FC50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears the pixel buffer of a bitmap: gets the buffer (BMP_GetPixels) and
 * its byte size (BMP_GetByteSize), then stores 0 in every byte. The loop label
 * sits on the strb, so the `adds r1, r2, #0` before it is the zero copied
 * from the counter, not a store of i (docs/idioms/a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero.md).
 *
 * symbols:
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);

void TEXT_TEXTURE_ClearBitmap(void *bmp)
{
    u8 *buf;
    u32 n;
    u32 i;

    buf = (u8 *)BMP_GetPixels(bmp);
    n = BMP_GetByteSize(bmp);
    for (i = 0; i < n; i++) {
        buf[i] = 0;
    }
}
