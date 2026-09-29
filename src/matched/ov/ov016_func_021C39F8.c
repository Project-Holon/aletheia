/*
 * function: func_021C39F8
 * address:  0x021C39F8
 * packet:   pkt_ov016_021C39F8
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
 *   func_021C3A48  0x021C3A48  arm
 *   g_021DE5B8  0x021DE5B8  data  a1
 */
extern signed char func_021BCB14(void);
extern void func_021CFFAC(int x);
extern void func_021C0E40(void *p);
extern void func_021C3A48(void);
extern unsigned char g_021DE5B8;

void func_021C39F8(void)
{
    switch (func_021BCB14()) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(6);
        g_021DE5B8 = 1;
        break;
    default:
        return;
    }
    func_021C0E40(func_021C3A48);
}
