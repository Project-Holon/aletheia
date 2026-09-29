/*
 * function: func_021C3D8C
 * address:  0x021C3D8C
 * packet:   pkt_ov016_021C3D8C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneOptMovFailure (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   func_021C3DC8  0x021C3DC8  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021BD060  0x021BD060  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C0     0x021DE5C0  data
 *   func_021C3E48  0x021C3E48  arm  ov016
 */

extern void func_021C3DC8();
extern void func_021BD29C();
extern int func_021BD060();
extern void func_021C0E40();
extern void func_021C3E48();
extern unsigned char g_021DE5C0;

void func_021C3D8C(void)
{
    func_021C3DC8();
    func_021BD29C(0x20);
    g_021DE5C0 = func_021BD060(0x3C, -1, 0);
    func_021C0E40(func_021C3E48);
}
