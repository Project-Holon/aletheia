/*
 * file:     unit_021C686C.c
 * function: func_021C686C
 * address:  0x021C686C
 * packet:   pkt_021C686C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C686C   0x021C686C  arm
 *
 * Call func_021C687C, func_021C6A0C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C686C.c \
 *       --func func_021C686C --addr 0x021C686C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C687C(void);
extern void func_021C6A0C(void);

void func_021C686C(void)
{
    func_021C687C();
    func_021C6A0C();
}
