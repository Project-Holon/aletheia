/*
 * function: func_021C20AC
 * address:  0x021C20AC
 * packet:   pkt_021C20AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C20AC   0x021C20AC  arm
 *
 * Call func_021C20C0, func_021C20FC, func_021C2100.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C20AC.c \
 *       --func func_021C20AC --addr 0x021C20AC --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C20C0(void);
extern void func_021C20FC(void);
extern void func_021C2100(void);

void func_021C20AC(void)
{
    func_021C20C0();
    func_021C20FC();
    func_021C2100();
}
