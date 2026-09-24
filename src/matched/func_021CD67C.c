/*
 * function: func_021CD67C
 * address:  0x021CD67C
 * packet:   pkt_021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CD67C   0x021CD67C  arm
 *
 * Call func_021CD79C, func_021CD68C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CD67C.c \
 *       --func func_021CD67C --addr 0x021CD67C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CD79C(void);
extern void func_021CD68C(void);

void func_021CD67C(void)
{
    func_021CD79C();
    func_021CD68C();
}
