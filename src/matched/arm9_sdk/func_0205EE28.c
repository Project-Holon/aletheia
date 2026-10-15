/*
 * function: codetovalue
 * address:  0x0205EE28
 * packet:   pkt_0205EE28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      codetovalue (libdwcac.TWL.HYB.a(shop_usb.o))
 *
 * symbols:
 *   (none)
 */

long codetovalue(unsigned char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    if (c >= 'a' && c <= 'z') {
        return (long)(c - 'a') + 26;
    }
    if (c >= '0' && c <= '9') {
        return (long)(c - '0') + 52;
    }
    if (c == '+') {
        return 62;
    }
    if (c == '/') {
        return 63;
    }
    return -(c != '=');
}
