/*
 * file:     unit_021C0370_p01.c
 * unit:     yes
 * function: func_021C0370, func_021C03C0
 * address:  0x021C0370
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
unsigned short func_021C0370(unsigned char *src, unsigned long cur, short Endian);
unsigned long func_021C03C0(unsigned char *src, unsigned long cur, short Endian);

unsigned short func_021C0370(unsigned char *src, unsigned long cur, short Endian)
{
    unsigned short word;

    if (Endian == 0) {
        word = src[cur] & 0x00ff;
        word |= (src[cur + 1] << 8) & 0xff00;
    } else {
        word = (src[cur] << 8) & 0xff00;
        word |= src[cur + 1];
    }
    return word;
}

/*
 * sdk:      GetLong (exifdec.o)
 */
unsigned long func_021C03C0(unsigned char *src, unsigned long cur, short Endian)
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
