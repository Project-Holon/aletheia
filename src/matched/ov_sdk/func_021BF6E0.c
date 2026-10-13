/*
 * function: DWCi_KB10lGet
 * address:  0x021BF6E0
 * packet:   pkt_021BF6E0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_KB10lGet   0x021BF6E0  arm
 *
 * Read the byte at +0x60 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_KB10lGet.c \
 *       --func DWCi_KB10lGet --addr 0x021BF6E0 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned char DWCi_KB10lGet(void)
{
    return *(unsigned char *)(*(char **)0x021DE560 + 0x60);
}
