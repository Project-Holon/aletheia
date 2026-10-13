/*
 * function: DWCi_SBlDisable
 * address:  0x021CE9D0
 * packet:   pkt_021CE6F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SBlDisable   0x021CE9D0  arm
 *
 * Set the byte at +0x1e of the object behind the global pointer to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SBlDisable.c \
 *       --func DWCi_SBlDisable --addr 0x021CE9D0 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_SBlDisable(void)
{
    *(unsigned char *)(*(char **)0x021DE63C + 0x1e) = 1;
}
