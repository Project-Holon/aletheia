/*
 * function: BMP_GetByteSize
 * address:  0x020437EC
 * packet:   pkt_0204361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TU: bmp.c.  Byte size of a bitmap's pixel buffer: depth * ((width / 8) * height / 8). The first division is an `lsr` because the width comes out of a u16 field and is known non-negative; the second is a signed `asr` triple because it divides an int product.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetByteSize.c  *       --func BMP_GetByteSize --addr 0x020437EC --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp {
    void *pixels; /* 0x00 */
    u16   width;  /* 0x04 */
    u16   height; /* 0x06 */
    u16   depth;  /* 0x08 */
    u16   kind;   /* 0x0a */
};

u32 BMP_GetByteSize(const struct Bmp *bmp)
{
    return bmp->depth * ((bmp->width / 8) * bmp->height / 8);
}
