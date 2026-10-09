/*
 * file:     unit_021D656C.c
 * function: func_021D656C
 * address:  0x021D656C
 * packet:   pkt_021D656C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D656C   0x021D656C  arm
 *
 * Call func_021D657C, func_021D668C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D656C.c \
 *       --func func_021D656C --addr 0x021D656C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021D657C(void);
extern void func_021D668C(void);

void func_021D656C(void)
{
    func_021D657C();
    func_021D668C();
}
