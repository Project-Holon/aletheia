/*
 * function: func_021CA818
 * address:  0x021CA818
 * packet:   pkt_021CA390
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA818   0x021CA818  arm
 *
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CA818.c \
 *       --func func_021CA818 --addr 0x021CA818 --region ov016 --cc dsi/1.1p1 --arm
 */

int func_021CA818(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}
