/*
 * function: NHTTPi_encodeUrlChar
 * address:  0x021BA2D0
 * packet:   pkt_ov114_021BA2D0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * URL-encode one byte into dst.  Space becomes '+'; an unreserved
 * character is copied as-is; anything else becomes "%XX".  Returns the
 * number of bytes written (1 or 3).  No relocations.
 *
 * The two nibbles are computed before the '%' store on purpose; see
 * docs/idioms/compute-a-stores-operands-before-the-store.md.
 */

int NHTTPi_encodeUrlChar(char *dst, int c)
{
    int hi, lo;

    if (c == 0x20) {
        *dst = '+';
        return 1;
    }
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
        *dst = c;
        return 1;
    }
    hi = (c >> 4) & 0xf;
    lo = c & 0xf;
    *dst = '%';
    dst[1] = hi < 10 ? hi + '0' : hi + '7';
    dst[2] = lo < 10 ? lo + '0' : lo + '7';
    return 3;
}
