/*
 * function: func_021CB1C4
 * address:  0x021CB1C4
 * packet:   pkt_021CB1C4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CB1C4   0x021CB1C4  arm
 *
 * Call func_021CB294, func_021CB1D4.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CB1C4.c \
 *       --func func_021CB1C4 --addr 0x021CB1C4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CB294(void);
extern void func_021CB1D4(void);

void func_021CB1C4(void)
{
    func_021CB294();
    func_021CB1D4();
}
