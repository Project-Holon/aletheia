/*
 * function: func_021C3714
 * address:  0x021C3714
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C3714   0x021C3714  arm
 *
 * Call func_021C3728, func_021C3748, func_021C374C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C3714.c \
 *       --func func_021C3714 --addr 0x021C3714 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C3728(void);
extern void func_021C3748(void);
extern void func_021C374C(void);

void func_021C3714(void)
{
    func_021C3728();
    func_021C3748();
    func_021C374C();
}
