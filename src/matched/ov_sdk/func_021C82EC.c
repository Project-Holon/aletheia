/*
 * function: DWCi_SetErrorCode
 * address:  0x021C82EC
 * packet:   pkt_021C82EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SetErrorCode   0x021C82EC  arm
 *
 * Store a word into the global at 0x021DE5E8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SetErrorCode.c \
 *       --func DWCi_SetErrorCode --addr 0x021C82EC --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_SetErrorCode(unsigned int v)
{
    *(unsigned int *)0x021DE5E8 = v;
}
