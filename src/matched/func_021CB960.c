/*
 * function: func_021CB960
 * address:  0x021CB960
 * packet:   pkt_021CB1C4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CB960   0x021CB960  arm
 *
 * Call func_021CBAA0, func_021CBAC4, func_021CBAC8, func_021CB978.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CB960.c \
 *       --func func_021CB960 --addr 0x021CB960 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CBAA0(void);
extern void func_021CBAC4(void);
extern void func_021CBAC8(void);
extern void func_021CB978(void);

void func_021CB960(void)
{
    func_021CBAA0();
    func_021CBAC4();
    func_021CBAC8();
    func_021CB978();
}
