/*
 * function: BMP_CopyPixels
 * address:  0x02043814
 * packet:   pkt_0204361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TU: bmp.c.  Copy one bitmap's pixels over another's, clipped to whichever
 * of the two buffers is smaller.  Both sizes come from BMP_GetByteSize rather
 * than from the descriptors directly, and the comparison is unsigned
 * (`movlo`), so the sizes are u32.
 *
 * symbols:
 *   BMP_GetByteSize  0x020437EC  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_CopyPixels.c \
 *       --func BMP_CopyPixels --addr 0x02043814 --cc 1.1p1 --arm
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

extern u32  BMP_GetByteSize(const struct Bmp *bmp);
extern void MIi_CpuCopy32(void *dst, const void *src, u32 size);

void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src)
{
    u32 size;
    u32 other;

    size = BMP_GetByteSize(dst);
    other = BMP_GetByteSize(src);

    if (other < size)
        size = other;

    MIi_CpuCopy32(dst->pixels, src->pixels, size);
}
