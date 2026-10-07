/*
 * function: func_021C73C0
 * address:  0x021C73C0
 * packet:   pkt_021C73C0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C73C0   0x021C73C0  arm
 *
 * Call func_021C73D0, func_021C7718.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C73C0.c \
 *       --func func_021C73C0 --addr 0x021C73C0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C73D0(void);
extern void func_021C7718(void);

void func_021C73C0(void)
{
    func_021C73D0();
    func_021C7718();
}
