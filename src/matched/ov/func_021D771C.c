/*
 * function: func_021D771C
 * address:  0x021D771C
 * packet:   pkt_021D7474
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D771C   0x021D771C  arm
 *
 * Store a word at +0x08 of the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D771C.c \
 *       --func func_021D771C --addr 0x021D771C --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021D771C(char *p, unsigned int v)
{
    *(unsigned int *)(p + 8) = v;
}
