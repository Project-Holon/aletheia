/*
 * function: string_fill_char
 * address:  0x0208D734
 * packet:   pkt_0208D734
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

struct dst_string_tag {
    unsigned long len;
    char *cur;
    char *base;
};

void string_fill_char(struct dst_string_tag *p, char c, int n)
{
    if (n > 0) {
        unsigned long i, k;
        k = p->len;
        if (k > n)
            k = n;
        for (i = 0; i < k; ++i)
            p->cur[i] = c;
        p->len -= k;
        p->cur += n;
    }
}
