/*
 * function: func_021BA620
 * address:  0x021BA620
 * packet:   pkt_ov114_021BA620
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_strtonum (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 *
 * symbols:
 */


int func_021BA620(char *p_p, int size)
{
    int numFound = 0;
    int n = 0;

    while (size-- != 0) {
        if (*p_p != ' ' && *p_p >= '0' && *p_p <= '9') {
            n = n * 10 + *p_p - '0';
            numFound++;
            if (numFound > 9) {
                return -1;
            }
        }
        p_p++;
    }
    if (numFound == 0) {
        n = -1;
    }
    return n;
}
