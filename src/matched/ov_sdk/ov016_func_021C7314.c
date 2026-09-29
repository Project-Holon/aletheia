/*
 * function: func_021C7314
 * address:  0x021C7314
 * packet:   pkt_ov016_021C7314
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit1 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BF390  0x021BF390  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021BF6F4  0x021BF6F4  arm  ov016
 *   func_021C7690  0x021C7690  arm  ov016
 *   func_021BF708  0x021BF708  arm  ov016
 *   func_021BF71C  0x021BF71C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5E4     0x021DE5E4  data
 *   func_021C73A0  0x021C73A0  arm  ov016
 */

typedef struct MemSsea {
    unsigned char pad0[0x14];
    unsigned char pos;
} MemSsea;

extern int func_021D5580();
extern void func_021BF390();
extern void func_021CFFAC();
extern void func_021BF6F4();
extern int func_021C7690();
extern void func_021BF708();
extern void func_021BF71C();
extern void func_021C0E40();
extern void func_021C73A0();
extern MemSsea *g_021DE5E4;

void func_021C7314(void)
{
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    func_021BF390();
    func_021CFFAC(0x14);
    if (g_021DE5E4->pos == 0) {
        func_021BF6F4(0);
        func_021BF71C(0);
    } else {
        if (func_021C7690(0x1A))
            func_021BF708(0);
        func_021BF71C(0);
    }
    func_021C0E40(func_021C73A0);
}
