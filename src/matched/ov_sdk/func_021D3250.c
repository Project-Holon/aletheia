/*
 * function: func_021D3250
 * address:  0x021D3250
 * packet:   pkt_021D3228
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D3250   0x021D3250  arm
 *
 * Word at +0x40 of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D3250.c \
 *       --func func_021D3250 --addr 0x021D3250 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned int func_021D3250(void)
{
    char **p = (char **)0x021DE660;
    unsigned int *q = (unsigned int *)(p[1] + 0x40);
    return *q;
}
