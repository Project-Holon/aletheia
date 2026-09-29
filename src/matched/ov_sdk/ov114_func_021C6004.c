/*
 * function: func_021C6004
 * address:  0x021C6004
 * packet:   pkt_ov114_021C6004
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      getNchar (libdwcnd.TWL.HYB.a dwci_nd.o)
 *
 * symbols:
 *   (none)
 */

int func_021C6004(unsigned char *dst, char *p, int n)
{
    int i;
    int len;

    len = 0;
    for (i = 0; i < n; i++) {
        if (*p != 0) {
            *dst++ = *p;
            len++;
            p++;
        } else {
            *dst++ = 0;
        }
    }
    return len;
}
