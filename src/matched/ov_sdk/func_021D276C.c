/*
 * function: func_021D276C
 * address:  0x021D276C
 * packet:   pkt_021D276C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D276C   0x021D276C  arm
 *
 * Store a halfword at the head of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D276C.c \
 *       --func func_021D276C --addr 0x021D276C --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021D276C(unsigned short v)
{
    *(unsigned short *)(*(char **)0x021DE65C) = v;
}
