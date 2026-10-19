/*
 * function: cert_item_len
 * address:  0x0216017C
 * packet:   pkt_ov009_0216017C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cert_item_len (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   (none)
 */

static int cert_item_len(unsigned char **ps)
{
    unsigned char *s;
    int len;
    int lenlen;

    s = *ps;
    len = *s++;
    if (len & 0x80) {
        lenlen = len & 0x7f;
        len = 0;
        while (lenlen--) {
            if (len & 0xff000000)
                return -1;
            len = (len << 8) + *s++;
        }
    }
    *ps = s;
    return len;
}
