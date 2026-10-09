/*
 * file:     unit_021C4660.c
 * function: func_021C4660
 * address:  0x021C4660
 * packet:   pkt_021C4660
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C4660   0x021C4660  arm
 *
 * Call func_021C4674, func_021C46AC, func_021C46B0.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C4660.c \
 *       --func func_021C4660 --addr 0x021C4660 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C4674(void);
extern void func_021C46AC(void);
extern void func_021C46B0(void);

void func_021C4660(void)
{
    func_021C4674();
    func_021C46AC();
    func_021C46B0();
}
