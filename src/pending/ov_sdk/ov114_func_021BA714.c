/*
 * function: func_021BA714
 * address:  0x021BA714
 * packet:   pkt_ov114_021BA714
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH (near miss: 33 B, register colouring only: i in r2, image r1)
 *
 * sdk:      NHTTPi_Base64Encode (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 *
 * symbols:
 *   func_021BA118  0x021BA118  arm
 *   g_021CE3BC     0x021CE3BC  data
 */

extern char g_021CE3BC[];
extern int func_021BA118(char *str_p);

int func_021BA714(char *dst_p, char *src_p)
{
    char *tbl;
    char *wp;
    int i;
    int len;

    wp = dst_p;
    tbl = g_021CE3BC;
    len = func_021BA118(src_p);

    for (i = 0; i < len; i += 3, src_p += 3, wp += 4) {
        int c0 = src_p[0];
        int c1 = src_p[1];
        int c2 = src_p[2];
        wp[0] = tbl[c0 >> 2];
        wp[1] = tbl[((c0 & 3) << 4) + (c1 >> 4)];
        wp[2] = tbl[((c1 & 15) << 2) + (c2 >> 6)];
        wp[3] = tbl[c2 & 63];
    }
    if (i == len + 1) {
        wp[-1] = '=';
    } else if (i == len + 2) {
        wp[-2] = '=';
        wp[-1] = '=';
    }
    *wp = 0;
    return func_021BA118(dst_p);
}
