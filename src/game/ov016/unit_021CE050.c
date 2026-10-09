/*
 * file:     unit_021CE050.c
 * function: func_021CE050
 * address:  0x021CE050
 * packet:   pkt_021CE050
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CE050   0x021CE050  arm
 *
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE050.c \
 *       --func func_021CE050 --addr 0x021CE050 --region ov016 --cc dsi/1.1p1 --arm
 */

int func_021CE050(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}
