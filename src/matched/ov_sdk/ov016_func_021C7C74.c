/*
 * function: func_021C7C74
 * address:  0x021C7C74
 * packet:   pkt_ov016_021C7C74
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procError (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   func_021D1568  0x021D1568  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D1524  0x021D1524  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C7CA0  0x021C7CA0  arm  ov016
 */

extern signed char func_021D1568(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1524();
extern void func_021C0E40();
extern void func_021C7CA0();

void func_021C7C74(void)
{
    if (func_021D1568())
        return;
    func_021CFFAC(6);
    func_021D1524();
    func_021C0E40(func_021C7CA0);
}
