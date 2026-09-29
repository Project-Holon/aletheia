/*
 * function: func_021C2050
 * address:  0x021C2050
 * packet:   pkt_ov172_021C2050
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * w9_nm: still 35 B. Tried: explicit cbbuf pointer (base + y, then + y), DWARF declaration order, size split (y = w*h; y >>= 1), while form, three result locals computed then stored, post-increment split. The object keeps yuyv in r1 (the width register), the Cb base in r4, and computes the third pair's masked half before the first store.
 *
 * sdk:      SSP_YUV422ToYUV888 (jpegenc.o)
 *
 * symbols:
 *   (none)
 */

void func_021C2050(void *src, unsigned long width, unsigned long height, void *dst)
{
    unsigned long yuyv;
    unsigned long x;
    unsigned long y;
    unsigned long *pYuyv;
    unsigned short *ybuf;
    unsigned short *crbuf;

    pYuyv = (unsigned long *)src;
    ybuf = (unsigned short *)dst;
    y = (width * height) >> 1;
    crbuf = ybuf + y + y;
    for (x = 0; x < y; x++) {
        yuyv = *pYuyv++;
        ybuf[x] = (yuyv & 0xff) | ((yuyv & 0xff0000) >> 8);
        ybuf[y + x] = ((yuyv & 0xff00) >> 8) | (yuyv & 0xff00);
        crbuf[x] = ((yuyv & 0xff000000) >> 16) | (yuyv >> 24);
    }
}
