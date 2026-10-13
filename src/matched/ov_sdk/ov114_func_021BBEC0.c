/*
 * function: NHTTPi_CheckHeaderEnd
 * address:  0x021BBEC0
 * packet:   pkt_ov114_021BBEC0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_CheckHeaderEnd (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 */

int NHTTPi_CheckHeaderEnd(char *buf_p, int bufwp)
{
    char c = buf_p[(bufwp - 2) & 3];

    if (c == '\r' && buf_p[(bufwp - 1) & 3] == '\r') {
        return 1;
    }
    if (c == '\n' && buf_p[(bufwp - 1) & 3] == '\n') {
        return 1;
    }
    if (buf_p[(bufwp - 4) & 3] == '\r' && buf_p[(bufwp - 3) & 3] == '\n' && c == '\r' && buf_p[(bufwp - 1) & 3] == '\n') {
        return 1;
    }
    return 0;
}
