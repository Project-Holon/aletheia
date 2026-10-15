/*
 * function: MSL_C_LIB_MbrToWc
 * address:  0x02092264
 * packet:   pkt_02092264
 * region:   arm9
 * compiler: 1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     2026-10-12 lane HF0: hidden function filed.
 * symbols:
 */
int MSL_C_LIB_MbrToWc(unsigned short *pwc, const unsigned char *s, unsigned int n)
{
    if (s == 0) {
        return 0;
    }
    if (n == 0) {
        return -1;
    }
    if (pwc != 0) {
        *pwc = *s;
    }
    if (*s == 0) {
        return 0;
    }
    return 1;
}
