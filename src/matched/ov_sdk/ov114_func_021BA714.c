/*
 * function: NHTTPi_Base64Encode
 * address:  0x021BA714
 * packet:   pkt_ov114_021BA714
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_Base64Encode (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 *
 * symbols:
 *   NHTTPi_strlen  0x021BA118  arm
 *   sNHTTPBase64Chars     0x021CE3BC  data
 */

extern char sNHTTPBase64Chars[];
extern int NHTTPi_strlen(char *str_p);

int NHTTPi_Base64Encode(char *dst_p, const char *src_p)
{
    char *tbl;
    char *wp;
    int i;
    int len;

    wp = dst_p;
    tbl = sNHTTPBase64Chars;
    len = NHTTPi_strlen((char *)src_p);

    for (i = 0; i < len; i += 3, src_p += 3, wp += 4) {
        wp[0] = tbl[src_p[0] >> 2];
        wp[1] = tbl[((src_p[0] & 3) << 4) + (src_p[1] >> 4)];
        wp[2] = tbl[((src_p[1] & 15) << 2) + (src_p[2] >> 6)];
        wp[3] = tbl[src_p[2] & 63];
    }
    if (i == len + 1) {
        wp[-1] = '=';
    } else if (i == len + 2) {
        wp[-2] = '=';
        wp[-1] = '=';
    }
    *wp = 0;
    return NHTTPi_strlen(dst_p);
}