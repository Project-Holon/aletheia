/*
 * function: FSi_CopySafeString
 * address:  0x02078018
 * packet:   pkt_02078018
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_CopySafeString (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 */

typedef int BOOL;

int FSi_CopySafeString(char *dst, int dstlen, const char *src, int srclen, BOOL *stickyFailure)
{
    int i;
    int n = (dstlen - 1 < srclen) ? (dstlen - 1) : srclen;

    for (i = 0; (i < n) && src[i]; ++i)
    {
        dst[i] = src[i];
    }
    if ((i < srclen) && src[i])
    {
        *stickyFailure = 1;
    }
    dst[i] = '\0';
    return i;
}
