/*
 * function: func_021C79B4
 * address:  0x021C79B4
 * packet:   pkt_ov016_021C79B4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procWin (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   func_021D1568  0x021D1568  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D1524  0x021D1524  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5E4     0x021DE5E4  data
 *   func_021C7A0C  0x021C7A0C  arm  ov016
 */

typedef struct MemSsea {
    unsigned char pad0[0x15];
    unsigned char result;
} MemSsea;

extern int func_021D1568();
extern void func_021CFFAC();
extern void func_021D1524();
extern void func_021C0E40();
extern void func_021C7A0C();
extern MemSsea *g_021DE5E4;

void func_021C79B4(void)
{
    g_021DE5E4->result = func_021D1568();
    switch (g_021DE5E4->result) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(0xE);
        break;
    default:
        return;
    }
    func_021D1524();
    func_021C0E40(func_021C7A0C);
}
