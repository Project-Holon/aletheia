/*
 * function: NHTTPi_strToInt
 * address:  0x021BA448
 * packet:   pkt_ov114_021BA448
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int NHTTPi_strToInt(signed char *s, int len)
{
    int i;
    int acc;
    int started;
    int old;
    signed char c;

    if (len > 10) return -1;
    acc = 0;
    started = 0;
    for (i = 0; i < len; i++) {
        c = s[i];
        if (started && (c == ' ' || c == 0)) break;
        if (!started && c == ' ') continue;
        if (c < '0' || c > '9') return -1;
        started = 1;
        old = acc;
        acc = acc * 10 + c - '0';
        if (old > acc) return -1;
    }
    return acc;
}