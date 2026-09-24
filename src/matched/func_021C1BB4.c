/*
 * function: func_021C1BB4
 * address:  0x021C1BB4
 * packet:   pkt_021C1BB4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C1BB4   0x021C1BB4  arm
 *
 * Call func_021C1BC8, func_021C1CF8, func_021C1CFC.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C1BB4.c \
 *       --func func_021C1BB4 --addr 0x021C1BB4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C1BC8(void);
extern void func_021C1CF8(void);
extern void func_021C1CFC(void);

void func_021C1BB4(void)
{
    func_021C1BC8();
    func_021C1CF8();
    func_021C1CFC();
}
