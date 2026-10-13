/*
 * function: DWCi_KB10lSetErase
 * address:  0x021BF6F4
 * packet:   pkt_021BF6E0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_KB10lSetErase   0x021BF6F4  arm
 *
 * Store a byte at +0x66 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_KB10lSetErase.c \
 *       --func DWCi_KB10lSetErase --addr 0x021BF6F4 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_KB10lSetErase(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE560 + 0x66) = v;
}
