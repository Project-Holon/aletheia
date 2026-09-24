/*
 * function: func_021D0684
 * address:  0x021D0684
 * packet:   pkt_021D0684
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D0684   0x021D0684  arm
 *
 * True when field +0x14 of the object behind the pointer is non-zero.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D0684.c \
 *       --func func_021D0684 --addr 0x021D0684 --region ov016 --cc dsi/1.1p1 --arm
 */

int func_021D0684(void)
{
    char **p = (char **)0x021DE64C;
    unsigned int *q = (unsigned int *)(p[1] + 0x14);
    return *q != 0;
}
