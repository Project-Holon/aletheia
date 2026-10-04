/*
 * function: func_021CAB68
 * address:  0x021CAB68
 * packet:   pkt_ov016_021CAB68
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      checkRaku (libdwcutil.TWL.HYB.a(scenesetrakubutt))
 * symbols:
 *   func_021C1518  0x021C1518  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021D0014  0x021D0014  arm
 *   func_021CFFAC  0x021CFFAC  arm
 *   func_021D1208  0x021D1208  arm
 *   func_021BCB9C  0x021BCB9C  arm
 *   func_021CAA08  0x021CAA08  arm
 *   func_021CABF8  0x021CABF8  arm
 *   g_021DE5F8  0x021DE5F8  data  a1
 */
extern int func_021C1518(void);
extern void func_021C0E40(unsigned int v);
extern void func_021D0014(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021BCB9C(void);
extern void func_021CAA08(void);
extern void func_021CABF8(void);
extern unsigned char g_021DE5F8;

void func_021CAB68(void)
{
    switch (func_021C1518()) {
    case 2:
        g_021DE5F8 = 1;
        func_021C0E40((unsigned int)func_021CAA08);
        break;
    case 4:
        g_021DE5F8 = 0;
        func_021D0014();
        func_021CFFAC(9);
        func_021D1208(13, 1, 1, -1, 0);
        func_021BCB9C();
        func_021C0E40((unsigned int)func_021CABF8);
        break;
    }
}
