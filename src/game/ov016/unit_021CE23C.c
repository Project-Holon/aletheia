/*
 * file:     unit_021CE23C.c
 * function: func_021CE23C
 * address:  0x021CE23C
 * packet:   pkt_021CE23C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CE23C   0x021CE23C  arm
 *
 * Call func_021CE250, func_021CE288, func_021CE28C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE23C.c \
 *       --func func_021CE23C --addr 0x021CE23C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CE250(void);
extern void func_021CE288(void);
extern void func_021CE28C(void);

void func_021CE23C(void)
{
    func_021CE250();
    func_021CE288();
    func_021CE28C();
}
