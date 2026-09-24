/*
 * function: func_0218022C
 * address:  0x0218022C
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Count the characters of a null-terminated string, consuming at most `n`
 * bytes: a lead byte 110xxxxx with a valid continuation costs 2 bytes, a lead
 * 1110xxxx with two valid continuations costs 3, anything else 1.  A null
 * string counts as zero characters.
 */

int func_0218022C(const char *s, int n)
{
    int count = 0;

    if (s == 0)
        return 0;

    while (*s != 0 && n > 0) {
        unsigned char c = *s;

        if ((c & 0xe0) == 0xc0 && n >= 2 && (((unsigned char *)s)[1] & 0xc0) == 0x80) {
            s += 2;
            n -= 2;
        } else if ((c & 0xf0) == 0xe0 && n >= 3 && (((unsigned char *)s)[1] & 0xc0) == 0x80
                   && (((unsigned char *)s)[2] & 0xc0) == 0x80) {
            s += 3;
            n -= 3;
        } else {
            s += 1;
            n -= 1;
        }
        count++;
    }
    return count;
}
