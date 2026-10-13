/*
 * function: DWCi_KB10lIsInit
 * address:  0x021BF730
 * packet:   pkt_021BF6E0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_KB10lIsInit   0x021BF730  arm
 *
 * True when the global pointer at 0x021DE560 is non-null.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_KB10lIsInit.c \
 *       --func DWCi_KB10lIsInit --addr 0x021BF730 --region ov016 --cc dsi/1.1p1 --arm
 */

int DWCi_KB10lIsInit(void)
{
    return *(void **)0x021DE560 != 0;
}
