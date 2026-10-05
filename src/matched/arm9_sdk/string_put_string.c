/*
 * function: string_put_string
 * address:  0x0208D788
 * packet:   pkt_0208D788
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

void string_put_string(struct dst_string_tag *p, const char *s, int n)
{
    if (n > 0) {
        unsigned long i, k;
        k = p->len;
        if (k > n)
            k = n;
        for (i = 0; i < k; ++i)
            p->cur[i] = s[i];
        p->len -= k;
        p->cur += n;
    }
}
