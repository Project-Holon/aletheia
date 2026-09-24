/*
 * function: func_021D7794
 * address:  0x021D7794
 * packet:   pkt_021D7474
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D7794   0x021D7794  arm
 *
 * Store a byte at +0x38 of the i-th 0x40-byte record behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D7794.c \
 *       --func func_021D7794 --addr 0x021D7794 --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021D7794(unsigned int i, unsigned char v)
{
    char *p = *(char **)0x021DE6E4;
    *(unsigned char *)(p + (i << 6) + 0x38) = v;
}
