/*
 * function: func_021C55B4
 * address:  0x021C55B4
 * packet:   pkt_021C55B4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C55B4   0x021C55B4  arm
 *
 * Call func_021C55C8, func_021C57E4, func_021C5A10.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C55B4.c \
 *       --func func_021C55B4 --addr 0x021C55B4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C55C8(void);
extern void func_021C57E4(void);
extern void func_021C5A10(void);

void func_021C55B4(void)
{
    func_021C55C8();
    func_021C57E4();
    func_021C5A10();
}
