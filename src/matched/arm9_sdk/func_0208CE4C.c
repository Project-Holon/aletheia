/*
 * function: func_0208CE4C
 * address:  0x0208CE4C
 * packet:   pkt_0208CE4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      STD_CompareNString (std_string.o)
 */

int func_0208CE4C(const char *str1, const char *str2, int len)
{
    unsigned long dstalign;
    unsigned char chr1;
    unsigned char chr2;
    unsigned long lng1;
    unsigned long y;
    int i;

    if (len != 0) {
        i = 0;
        dstalign = (unsigned long)str1 & 3;

        if ((dstalign ^ ((unsigned long)str2 & 3)) == 0) {
            if (dstalign != 0) {
                for (; i + dstalign < 4 && i < len; i++) {
                    chr1 = (unsigned char)str1[i];
                    chr2 = (unsigned char)str2[i];
                    if (chr1 != chr2 || chr1 == 0) {
                        return chr1 - chr2;
                    }
                }
            }
            for (; i <= len - 4; i += 4) {
                lng1 = *(const unsigned long *)(str1 + i);
                if (lng1 != *(const unsigned long *)(str2 + i)) {
                    break;
                }
                y = ~(((lng1 & 0x7f7f7f7f) + 0x7f7f7f7f) | lng1 | 0x7f7f7f7f);
                if (y != 0) {
                    break;
                }
            }
        }

        for (; i < len; i++) {
            chr1 = (unsigned char)str1[i];
            chr2 = (unsigned char)str2[i];
            if (chr1 != chr2 || chr1 == 0) {
                return chr1 - chr2;
            }
        }
    }
    return 0;
}
