/*
 * function: func_021C4D04
 * address:  0x021C4D04
 * packet:   pkt_ov016_021C4D04
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a scenesetaossbutton.o)
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021C08B0  0x021C08B0  arm  ov016
 *   func_021BC8EC  0x021BC8EC  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5CC     0x021DE5CC  data
 *   func_021CC998  0x021CC998  arm  ov016
 *   func_021C4EC8  0x021C4EC8  arm  ov016
 */

extern int func_021D5580();
extern int func_021BCB58();
extern void func_021C08B0(int a);
extern void func_021BC8EC();
extern void func_021D5CA8(int a);
extern void func_021BD138();
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021CC998();
extern void func_021C4EC8();
extern unsigned char g_021DE5CC;

void func_021C4D04(void)
{
    if (func_021D5580(0))
        return;
    if (g_021DE5CC == 0) {
        if (func_021D5580(1))
            return;
    }
    if (!func_021BCB58())
        return;
    func_021C08B0(g_021DE5CC != 0);
    func_021BC8EC();
    func_021D5CA8(0);
    if (g_021DE5CC == 0) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021D6090(0, 0x15);
    if (g_021DE5CC == 0) {
        func_021C0E50(2, 1);
        func_021C0E40((unsigned int)func_021CC998);
    } else {
        func_021C0E50(0, 0);
        func_021C0E40((unsigned int)func_021C4EC8);
    }
}
