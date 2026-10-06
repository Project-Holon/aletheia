/*
 * file:     unit_0208D708.c
 * unit:     yes
 * function: func_0208D708, func_0208D734, func_0208D788
 * address:  0x0208D708
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct dst_string_tag {
    unsigned long len;
    char *cur;
    char *base;
};



void string_put_char(struct dst_string_tag *p, char c)
{
    if (p->len > 0) {
        *p->cur = c;
        --p->len;
    }
    ++p->cur;
}


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
