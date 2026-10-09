/*
 * file:     unit_021CBFD8.c
 * function: func_021CBFD8
 * address:  0x021CBFD8
 * packet:   pkt_021CB1C4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CBFD8   0x021CBFD8  arm
 *
 * Call func_021CBFEC, func_021CC0E4, func_021CC0E8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CBFD8.c \
 *       --func func_021CBFD8 --addr 0x021CBFD8 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CBFEC(void);
extern void func_021CC0E4(void);
extern void func_021CC0E8(void);

void func_021CBFD8(void)
{
    func_021CBFEC();
    func_021CC0E4();
    func_021CC0E8();
}
