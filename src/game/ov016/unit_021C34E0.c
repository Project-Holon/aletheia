/*
 * file:     unit_021C34E0.c
 * function: func_021C34E0
 * address:  0x021C34E0
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C34E0   0x021C34E0  arm
 *
 * Call func_021C34F4, func_021C3514, func_021C3518.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C34E0.c \
 *       --func func_021C34E0 --addr 0x021C34E0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C34F4(void);
extern void func_021C3514(void);
extern void func_021C3518(void);

void func_021C34E0(void)
{
    func_021C34F4();
    func_021C3514();
    func_021C3518();
}
