/*
 * function: NHTTPi_strToHex
 * address:  0x021BA35C
 * packet:   pkt_ov114_021BA35C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_strToHex (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 *
 * symbols:
 */

#define NHTTPi_TOLOWER(c) ((((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c))

int NHTTPi_strToHex(char *p_p, int len)
{
    int i;
    int n;
    int e;
    char c;

    if (len > 8) {
        return -1;
    }
    if (len == 8 && *p_p > '7') {
        return -1;
    }
    n = 0;
    e = 0;
    for (i = 0; i < len; i++) {
        c = NHTTPi_TOLOWER(p_p[i]);
        if (c >= '0' && c <= '9') {
            n = c + n * 16 - '0';
            e = 1;
        } else if (c >= 'a' && c <= 'f') {
            n = c + n * 16 - 'W';
            e = 1;
        } else {
            if (e != 0 && (c == ' ' || c == 0)) {
                break;
            }
            if (e != 0 || c != ' ') {
                return -1;
            }
        }
    }
    return n;
}
