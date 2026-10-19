/*
 * function: DWCi_Language
 * address:  0x021C0EC8
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_Language   0x021C0EC8  arm
 *
 * Read the first byte of the global object at 0x021DE56C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_Language.c \
 *       --func DWCi_Language --addr 0x021C0EC8 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned char DWCi_Language(void)
{
    return *(unsigned char *)0x021DE56C;
}
