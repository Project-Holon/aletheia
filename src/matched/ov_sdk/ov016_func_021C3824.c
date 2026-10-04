/*
 * function: func_021C3824
 * address:  0x021C3824
 * packet:   pkt_ov016_021C3824
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneOptMovConfirm1 (libdwcutil.TWL.HYB.a sceneoptmovconfirm1.o)
 *
 * symbols:
 *   func_021C386C  0x021C386C  arm  ov016
 *   func_021BD674  0x021BD674  arm  ov016
 *   func_021BD060  0x021BD060  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5B8     0x021DE5B8  data
 *   func_021C38EC  0x021C38EC  arm  ov016
 */

extern void func_021C386C();
extern void func_021BD674();
extern int func_021BD060();
extern void func_021BD29C();
extern void func_021C0E40(unsigned int v);
extern void func_021C38EC();
extern unsigned char g_021DE5B8;

void func_021C3824(void)
{
    g_021DE5B8 = 0;
    func_021C386C();
    func_021BD674(0x13);
    func_021BD060(0x3C, -1, 0);
    func_021BD29C(0x1B);
    func_021C0E40((unsigned int)func_021C38EC);
}
