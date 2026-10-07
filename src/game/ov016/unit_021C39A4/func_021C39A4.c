/*
 * function: func_021C39A4
 * address:  0x021C39A4
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C39A4   0x021C39A4  arm
 *
 * Call func_021C39B8, func_021C39F4, func_021C39F8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C39A4.c \
 *       --func func_021C39A4 --addr 0x021C39A4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C39B8(void);
extern void func_021C39F4(void);
extern void func_021C39F8(void);

void func_021C39A4(void)
{
    func_021C39B8();
    func_021C39F4();
    func_021C39F8();
}
