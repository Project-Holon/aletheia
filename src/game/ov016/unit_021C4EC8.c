/*
 * file:     unit_021C4EC8.c
 * function: func_021C4EC8
 * address:  0x021C4EC8
 * packet:   pkt_ov016_021C4EC8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetAossComplete (libdwcutil.TWL.HYB.a scenesetaosscomplete.o)
 *
 * symbols:
 *   func_021C4F04  0x021C4F04  arm  ov016
 *   func_021BD6D4  0x021BD6D4  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5D4     0x021DE5D4  data
 *   func_021C4F70  0x021C4F70  arm  ov016
 */

extern void func_021C4F04();
extern void func_021BD6D4();
extern void func_021BD29C();
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021C4F70();
extern unsigned char g_021DE5D4;

void func_021C4EC8(void)
{
    g_021DE5D4 = 0;
    func_021C4F04();
    func_021BD6D4();
    func_021BD29C(0x23);
    func_021CFFAC(0x10);
    func_021C0E40((unsigned int)func_021C4F70);
}
