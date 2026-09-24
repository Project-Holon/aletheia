/*
 * function: func_021D38C8
 * address:  0x021D38C8
 * packet:   pkt_021D3228
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D38C8   0x021D38C8  arm
 *
 * Store a word at +0x4c of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D38C8.c \
 *       --func func_021D38C8 --addr 0x021D38C8 --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021D38C8(unsigned int v)
{
    char **p = (char **)0x021DE660;
    unsigned int *q = (unsigned int *)(p[1] + 0x4c);
    *q = v;
}
