/*
 * function: func_021BA25C
 * address:  0x021BA25C
 * packet:   pkt_ov114_021BA25C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH (near miss: 58 B, guard shape: image has an extra cmpgt r1,#0 after the preloaded ldrsb and i in r2 first)
 *
 * sdk:      NHTTPi_getUrlEncodedSize2 (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 *
 * symbols:
 *   (none)
 */

int func_021BA25C(char *p_p, int len)
{
    int i;
    int n;
    int c;

    i = 0;
    n = 0;
    c = *p_p++;
    for (; len > 0 && i < len; i++) {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') || c == ' ')
            n += 1;
        else
            n += 3;
        c = *p_p++;
    }
    return n;
}
