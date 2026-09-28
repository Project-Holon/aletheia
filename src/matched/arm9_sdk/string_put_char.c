/*
 * function: string_put_char
 * address:  0x0208D708
 * packet:   pkt_0208D708
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

void string_put_char(struct dst_string_tag *p, char c)
{
    if (p->len > 0) {
        *p->cur = c;
        --p->len;
    }
    ++p->cur;
}
