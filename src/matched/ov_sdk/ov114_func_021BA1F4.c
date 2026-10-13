/*
 * function: NHTTPi_getUrlEncodedSize
 * address:  0x021BA1F4
 * packet:   pkt_021BA1F4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int NHTTPi_getUrlEncodedSize(char *s)
{
    int w = 0;
    char c;

    while ((c = *s++) != 0)
    {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') || c == ' ')
            w += 1;
        else
            w += 3;
    }
    return w;
}
