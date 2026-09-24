/*
 * function: func_021C4FD0
 * address:  0x021C4FD0
 * packet:   pkt_021C4660
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C4FD0   0x021C4FD0  arm
 *
 * Call func_021C50A0, func_021C4FE0.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C4FD0.c \
 *       --func func_021C4FD0 --addr 0x021C4FD0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C50A0(void);
extern void func_021C4FE0(void);

void func_021C4FD0(void)
{
    func_021C50A0();
    func_021C4FE0();
}
