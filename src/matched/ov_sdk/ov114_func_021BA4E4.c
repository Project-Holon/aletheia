/*
 * function: NHTTPi_intToStr
 * address:  0x021BA4E4
 * packet:   pkt_ov114_021BA4E4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_intToStr (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 *
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   @12945 0x021CDFA4 data
 */


int NHTTPi_intToStr(char *p_p, unsigned long n)
{
    unsigned int rdx[9] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10};
    int len = 0;
    int b = 0;
    int i;
    unsigned int x;

    for (i = 0; i < 9; i++) {
        if (n >= rdx[i]) {
            x = n / rdx[i];
            p_p[len] = x + '0';
            b = 1;
            n -= x * rdx[i];
            len++;
        } else if (b) {
            p_p[len++] = '0';
        }
    }
    p_p[len] = n + '0';
    return len + 1;
}
