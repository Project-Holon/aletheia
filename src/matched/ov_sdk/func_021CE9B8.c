/*
 * function: DWCi_SBlEnable
 * address:  0x021CE9B8
 * packet:   pkt_021CE6F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SBlEnable   0x021CE9B8  arm
 *
 * Clear the byte at +0x1e of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SBlEnable.c \
 *       --func DWCi_SBlEnable --addr 0x021CE9B8 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_SBlEnable(void)
{
    *(unsigned char *)(*(char **)0x021DE63C + 0x1e) = 0;
}
