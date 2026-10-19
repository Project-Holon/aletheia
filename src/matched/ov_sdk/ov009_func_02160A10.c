/*
 * function: compare_fqdn
 * address:  0x02160A10
 * packet:   pkt_ov009_02160A10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      compare_fqdn (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   chars_till_end  0x021609E8  arm  ov009
 */

extern int chars_till_end(const char *p);

static int compare_fqdn(char *name, char *pat)
{
    int pat_len;
    int pat_cnt;
    char c2;
    char c1;

    for (;;) {
        while (c2 = *pat++, c1 = *name++, c1 == c2) {
            if (c1 == 0)
                return 0;
        }
        if (c2 != '*')
            return 1;
        name--;
        pat_cnt = chars_till_end(name);
        pat_len = chars_till_end(pat);
        if (pat_len > pat_cnt)
            return 1;
        name += pat_cnt - pat_len;
    }
}
