/*
 * function: DWCi_SETTINGlGetSetType
 * address:  0x021CF7F4
 * packet:   pkt_021CF3F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SETTINGlGetSetType   0x021CF7F4  arm
 *
 * Byte at +0xe7 of the i-th 0x100-byte record behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTINGlGetSetType.c \
 *       --func DWCi_SETTINGlGetSetType --addr 0x021CF7F4 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned char DWCi_SETTINGlGetSetType(unsigned int i)
{
    return *(unsigned char *)(*(char **)0x021DE644 + (i << 8) + 0xe7);
}
