/*
 * function: DWCi_KBlSetErase
 * address:  0x021BDC68
 * packet:   pkt_021BDC54
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_KBlSetErase   0x021BDC68  arm
 *
 * Store a byte at +0x123 of a global object pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_KBlSetErase.c \
 *       --func DWCi_KBlSetErase --addr 0x021BDC68 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_KBlSetErase(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE55C + 0x123) = v;
}
