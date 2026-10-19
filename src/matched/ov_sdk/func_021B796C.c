/*
 * function: GetSecurityType
 * address:  0x021B796C
 * packet:   pkt_021B796C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GetSecurityType   0x021B796C  thumb
 *
 * Return 1 when bit 4 of the argument is set, else 0.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GetSecurityType.c \
 *       --func GetSecurityType --addr 0x021B796C --region ov016 --cc dsi/1.1p1 --thumb
 */

int GetSecurityType(unsigned int v)
{
    int r = 0;
    if (v & 0x10)
        r = 1;
    return r;
}
