/*
 * function: func_021CAEBC
 * address:  0x021CAEBC
 * packet:   pkt_ov016_021CAEBC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_021D5580  0x021D5580  arm
 *   func_021BCB58  0x021BCB58  arm
 *   func_021BC8EC  0x021BC8EC  arm
 *   func_021D5CA8  0x021D5CA8  arm
 *   func_021BD138  0x021BD138  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C14F4  0x021C14F4  arm
 *   func_021C0E50  0x021C0E50  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021CC998  0x021CC998  arm
 *   func_021CB0A8  0x021CB0A8  arm
 *   g_021DE5FC  0x021DE5FC  data  a1
 */
extern int func_021D5580(int x);
extern int func_021BCB58(void);
extern void func_021BC8EC(void);
extern void func_021D5CA8(int x);
extern void func_021BD138(void);
extern void func_021D6090(int a, int b);
extern void func_021C14F4(void);
extern void func_021C0E50(int a, int b);
extern void func_021C0E40(void *p);
extern void func_021CC998(void);
extern void func_021CB0A8(void);
extern unsigned char g_021DE5FC;

void func_021CAEBC(void)
{
    if (func_021D5580(0) != 0)
        return;
    if (g_021DE5FC == 0) {
        if (func_021D5580(1) != 0)
            return;
    }
    if (func_021BCB58() == 0)
        return;
    func_021BC8EC();
    func_021D5CA8(0);
    if (g_021DE5FC == 0) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021C14F4();
    if (g_021DE5FC == 0) {
        func_021C0E50(2, 1);
        func_021C0E40(func_021CC998);
    } else {
        func_021C0E50(0, 0);
        func_021C0E40(func_021CB0A8);
    }
}
