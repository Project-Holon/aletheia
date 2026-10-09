/*
 * file:     unit_021C28E8.c
 * function: func_021C28E8
 * address:  0x021C28E8
 * packet:   pkt_021C20AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C28E8   0x021C28E8  arm
 *
 * Call func_021C28FC, func_021C291C, func_021C2920.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C28E8.c \
 *       --func func_021C28E8 --addr 0x021C28E8 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C28FC(void);
extern void func_021C291C(void);
extern void func_021C2920(void);

void func_021C28E8(void)
{
    func_021C28FC();
    func_021C291C();
    func_021C2920();
}
