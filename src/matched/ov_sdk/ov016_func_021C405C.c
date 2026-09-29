/*
 * function: func_021C405C
 * address:  0x021C405C
 * packet:   pkt_ov016_021C405C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C0     0x021DE5C0  data
 *   func_021C2A3C  0x021C2A3C  arm  ov016
 *   func_021C450C  0x021C450C  arm  ov016
 */

extern int func_021D5580();
extern int func_021BCB58();
extern void func_021D5CA8();
extern void func_021BD138();
extern void func_021D6090();
extern void func_021C0E50();
extern void func_021C0E40();
extern void func_021C2A3C();
extern void func_021C450C();
extern unsigned char g_021DE5C0[];

void func_021C405C(void)
{
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    if (!func_021BCB58())
        return;
    func_021D5CA8(0);
    if (!g_021DE5C0[1]) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021D6090(0, 0x15);
    if (!g_021DE5C0[1]) {
        func_021C0E50(0, 1);
        func_021C0E40(func_021C2A3C);
    } else {
        func_021C0E50(0, 1);
        func_021C0E40(func_021C450C);
    }
}
