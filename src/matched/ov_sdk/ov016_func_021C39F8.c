/*
 * function: func_021C39F8
 * address:  0x021C39F8
 * packet:   pkt_ov016_021C39F8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a(sceneoptmovconfi))
 * symbols:
 *   func_021BCB14  0x021BCB14  arm
 *   func_021CFFAC  0x021CFFAC  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021C3A48  0x021C3A48  arm
 *   g_021DE5B8  0x021DE5B8  data  a1
 */

#include "../include/G_021DE5B8.h"

extern signed char func_021BCB14(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021C3A48(void);
extern struct G_021DE5B8 g_021DE5B8;

void func_021C39F8(void)
{
    switch (func_021BCB14()) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(6);
        (*(unsigned char *)&g_021DE5B8) = 1;
        break;
    default:
        return;
    }
    func_021C0E40((unsigned int)func_021C3A48);
}
