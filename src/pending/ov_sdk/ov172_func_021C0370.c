/*
 * function: func_021C0370
 * address:  0x021C0370
 * packet:   pkt_ov172_021C0370
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      GetWord (exifdec.o)
 *
 * symbols:
 *   (none)
 */

unsigned short func_021C0370(unsigned char *src, unsigned long cur, short Endian)
{
    unsigned short word;

    if (Endian == 0) {
        word = (src[cur + 1] << 8) & 0xff00;
        word |= (unsigned short)src[cur];
        return word;
    }
    word = (src[cur] << 8) & 0xff00;
    word |= src[cur + 1];
    return word;
}
