/*
 * function: func_021C3280
 * address:  0x021C3280
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C3280   0x021C3280  arm
 *
 * Call func_021C3290, func_021C3294.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C3280.c \
 *       --func func_021C3280 --addr 0x021C3280 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C3290(void);
extern void func_021C3294(void);

void func_021C3280(void)
{
    func_021C3290();
    func_021C3294();
}
