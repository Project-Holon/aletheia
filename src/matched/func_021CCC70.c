/*
 * function: func_021CCC70
 * address:  0x021CCC70
 * packet:   pkt_021CCC70
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CCC70   0x021CCC70  arm
 *
 * Call func_021CCC84, func_021CCE00, func_021CCE04.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CCC70.c \
 *       --func func_021CCC70 --addr 0x021CCC70 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CCC84(void);
extern void func_021CCE00(void);
extern void func_021CCE04(void);

void func_021CCC70(void)
{
    func_021CCC84();
    func_021CCE00();
    func_021CCE04();
}
