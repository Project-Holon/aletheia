/*
 * function: GetLong
 * address:  0x021C03C0
 * packet:   pkt_ov172_021C03C0
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GetLong (exifdec.o)
 *
 * symbols:
 *   (none)
 */

unsigned long GetLong(unsigned char *src, unsigned long cur, short Endian)
{
    unsigned long word;

    if (Endian == 0) {
        word = src[cur];
        word |= (src[cur + 1] << 8) & 0xff00;
        word |= (src[cur + 2] << 16) & 0xff0000;
        word |= (src[cur + 3] << 24) & 0xff000000;
    } else {
        word = (src[cur] << 24) & 0xff000000;
        word |= (src[cur + 1] << 16) & 0xff0000;
        word |= (src[cur + 2] << 8) & 0xff00;
        word |= src[cur + 3];
    }
    return word;
}
