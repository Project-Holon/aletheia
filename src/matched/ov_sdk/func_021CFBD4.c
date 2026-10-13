/*
 * function: DWCi_SETTINGlGetMemMap
 * address:  0x021CFBD4
 * packet:   pkt_021CF3F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SETTINGlGetMemMap   0x021CFBD4  arm
 *
 * The global pointer at 0x021DE644.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTINGlGetMemMap.c \
 *       --func DWCi_SETTINGlGetMemMap --addr 0x021CFBD4 --region ov016 --cc dsi/1.1p1 --arm
 */

char *DWCi_SETTINGlGetMemMap(void)
{
    return *(char **)0x021DE644;
}
