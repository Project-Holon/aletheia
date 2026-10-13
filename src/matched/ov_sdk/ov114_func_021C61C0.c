/*
 * function: DWCi_Ndi_decodeBASE64
 * address:  0x021C61C0
 * packet:   pkt_ov114_021C61C0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_decodeBASE64 (libdwcnd.TWL.HYB.a dwci_nd.o)
 *
 * symbols:
 *   getNchar  0x021C6004  arm  ov114
 *   decodeChar  0x021C6048  arm  ov114
 */

extern int getNchar(unsigned char *c, char *str, int n);
extern int decodeChar(unsigned char c);

int DWCi_Ndi_decodeBASE64(char *decbin, char *str, int length)
{
    unsigned char c[4];
    char dec[3];
    int d;
    int i;
    int n;
    int len;

    len = 0;
    n = getNchar(c, str, 4);
    d = 0;
    while (n > 0 && d >= 0) {
        dec[0] = 0;
        dec[1] = 0;
        dec[2] = 0;
        d = decodeChar(c[0]);
        if (d >= 0) {
            dec[0] = d << 2;
            d = decodeChar(c[1]);
            if (d >= 0) {
                dec[0] |= d >> 4;
                dec[1] = d << 4;
                d = decodeChar(c[2]);
                if (d >= 0) {
                    dec[1] |= d >> 2;
                    dec[2] = d << 6;
                    d = decodeChar(c[3]);
                    if (d >= 0)
                        dec[2] |= d;
                }
            }
        }
        for (i = 0; i < n - 1; i++)
            *decbin++ = dec[i];
        str += n;
        len += n - 1;
        length -= 4;
        if (length <= 0)
            break;
        n = getNchar(c, str, 4);
    }
    *decbin = 0;
    return len;
}
