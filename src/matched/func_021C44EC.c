/*
 * function: func_021C44EC
 * address:  0x021C44EC
 * packet:   pkt_021C44EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C44EC   0x021C44EC  arm
 *
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C44EC.c \
 *       --func func_021C44EC --addr 0x021C44EC --region ov016 --cc dsi/1.1p1 --arm
 */

int func_021C44EC(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}
