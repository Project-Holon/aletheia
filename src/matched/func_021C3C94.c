/*
 * function: func_021C3C94
 * address:  0x021C3C94
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C3C94   0x021C3C94  arm
 *
 * Call func_021C3D58, func_021C3CA4.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C3C94.c \
 *       --func func_021C3C94 --addr 0x021C3C94 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C3D58(void);
extern void func_021C3CA4(void);

void func_021C3C94(void)
{
    func_021C3D58();
    func_021C3CA4();
}
