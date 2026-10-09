/*
 * file:     unit_021C2D60.c
 * function: func_021C2D60
 * address:  0x021C2D60
 * packet:   pkt_021C20AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C2D60   0x021C2D60  arm
 *
 * Call func_021C2D74, func_021C2E68, func_021C2E6C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C2D60.c \
 *       --func func_021C2D60 --addr 0x021C2D60 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C2D74(void);
extern void func_021C2E68(void);
extern void func_021C2E6C(void);

void func_021C2D60(void)
{
    func_021C2D74();
    func_021C2E68();
    func_021C2E6C();
}
