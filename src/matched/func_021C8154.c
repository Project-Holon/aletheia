/*
 * function: func_021C8154
 * address:  0x021C8154
 * packet:   pkt_021C8154
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C8154   0x021C8154  arm
 *
 * Call func_021C8168, func_021C8188, func_021C818C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C8154.c \
 *       --func func_021C8154 --addr 0x021C8154 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C8168(void);
extern void func_021C8188(void);
extern void func_021C818C(void);

void func_021C8154(void)
{
    func_021C8168();
    func_021C8188();
    func_021C818C();
}
