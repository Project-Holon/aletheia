/*
 * function: STD_CompareString
 * address:  0x0208CD94
 * packet:   pkt_0208CD94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      STD_CompareString (std_string.o)
 */

int STD_CompareString(const char *str1, const char *str2)
{
    unsigned long dstalign;
    unsigned char chr1;
    unsigned char chr2;
    unsigned long lng1;
    unsigned long y;
    int i;

    i = 0;
    dstalign = (unsigned long)str1 & 3;

    if ((dstalign ^ ((unsigned long)str2 & 3)) == 0) {
        if (dstalign != 0) {
            for (; i + dstalign < 4; i++) {
                chr1 = (unsigned char)str1[i];
                chr2 = (unsigned char)str2[i];
                if (chr1 != chr2 || chr1 == 0) {
                    return chr1 - chr2;
                }
            }
        }
        for (;;) {
            lng1 = *(const unsigned long *)(str1 + i);
            if (lng1 != *(const unsigned long *)(str2 + i)) {
                break;
            }
            y = ~(((lng1 & 0x7f7f7f7f) + 0x7f7f7f7f) | lng1 | 0x7f7f7f7f);
            if (y != 0) {
                break;
            }
            i += 4;
        }
    }

    for (;;) {
        chr1 = (unsigned char)str1[i];
        chr2 = (unsigned char)str2[i];
        if (chr1 != chr2 || chr1 == 0) {
            return chr1 - chr2;
        }
        i++;
    }
}
