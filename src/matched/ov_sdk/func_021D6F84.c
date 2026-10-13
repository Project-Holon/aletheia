/*
 * function: DWCi_OBJlGetOam
 * address:  0x021D6F84
 * packet:   pkt_021D6DF4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_OBJlGetOam   0x021D6F84  arm
 *
 * Index a (a,b) record of the global table.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_OBJlGetOam.c \
 *       --func DWCi_OBJlGetOam --addr 0x021D6F84 --region ov016 --cc dsi/1.1p1 --arm
 */

char *DWCi_OBJlGetOam(unsigned int a, unsigned int b)
{
    return *(char **)0x021DE6A8 + (a << 10) + (b << 3);
}
