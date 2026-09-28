/*
 * function: func_021CDBA8
 * address:  0x021CDBA8
 * packet:   pkt_021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CDBA8   0x021CDBA8  arm
 *
 * Call func_021CDC78, func_021CDBB8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CDBA8.c \
 *       --func func_021CDBA8 --addr 0x021CDBA8 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CDC78(void);
extern void func_021CDBB8(void);

void func_021CDBA8(void)
{
    func_021CDC78();
    func_021CDBB8();
}
