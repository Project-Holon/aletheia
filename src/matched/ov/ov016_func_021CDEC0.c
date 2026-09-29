/*
 * function: func_021CDEC0
 * address:  0x021CDEC0
 * packet:   pkt_ov016_021CDEC0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_021BCB14  0x021BCB14  arm
 *   func_021CFFAC  0x021CFFAC  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021CDF10  0x021CDF10  arm
 *   g_021DE628  0x021DE628  data  a1
 */
extern signed char func_021BCB14(void);
extern void func_021CFFAC(int x);
extern void func_021C0E40(void *p);
extern void func_021CDF10(void);
extern unsigned char g_021DE628;

void func_021CDEC0(void)
{
    switch (func_021BCB14()) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(6);
        g_021DE628 = 1;
        break;
    default:
        return;
    }
    func_021C0E40(func_021CDF10);
}
