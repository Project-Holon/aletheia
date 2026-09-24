/*
 * function: func_021C2528
 * address:  0x021C2528
 * packet:   pkt_021C2528
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C2528   0x021C2528  arm
 *
 * Bail out on two func_021D5580 probes, then arm timer 0x800000 and kick func_0208BEA4.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C2528.c \
 *       --func func_021C2528 --addr 0x021C2528 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D5580(int);
extern void func_02087A04(int);
extern void func_0208BEA4(void);

void func_021C2528(void)
{
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    func_02087A04(0x800000);
    func_0208BEA4();
}
