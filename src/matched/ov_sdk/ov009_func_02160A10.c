/*
 * function: func_02160A10
 * address:  0x02160A10
 * packet:   pkt_ov009_02160A10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      compare_fqdn (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_021609E8  0x021609E8  arm  ov009
 */

extern int func_021609E8(const char *p);

static int func_02160A10(char *name, char *pat)
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
        pat_cnt = func_021609E8(name);
        pat_len = func_021609E8(pat);
        if (pat_len > pat_cnt)
            return 1;
        name += pat_cnt - pat_len;
    }
}
