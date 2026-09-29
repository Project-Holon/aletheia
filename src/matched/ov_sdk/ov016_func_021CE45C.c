/*
 * function: func_021CE45C
 * address:  0x021CE45C
 * packet:   pkt_ov016_021CE45C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cbUsb (libdwcutil.TWL.HYB.a scenesetusbready)
 *
 * symbols:
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D0DC8  0x021D0DC8  arm  ov016
 *   func_021CE564  0x021CE564  arm  ov016
 *   func_021CE2D4  0x021CE2D4  arm  ov016
 *   func_021CE5B0  0x021CE5B0  arm  ov016
 *   g_021DE62C  0x021DE62C  data
 */

extern void func_021D0014(void);
extern void func_021CFFAC(int no);
extern void func_021D1208(int a, int b, int c, int d, int e);
extern void func_021BCB9C(void);
extern void func_021C0E40(void (*proc)(void));
extern void func_021D0DC8(void *cb);
extern void func_021CE564(void);
extern void func_021CE2D4(void);
extern void func_021CE5B0(void);
extern unsigned char g_021DE62C;

void func_021CE45C(int state)
{
    if (g_021DE62C != 0)
        return;
    switch (state) {
    case 0:
        g_021DE62C = 3;
        func_021D0014();
        func_021CFFAC(0x12);
        func_021D1208(0x10, 1, 1, -1, 0);
        func_021BCB9C();
        func_021C0E40(func_021CE564);
        break;
    case 1:
        g_021DE62C = 1;
        func_021D0014();
        func_021C0E40(func_021CE2D4);
        break;
    case 2:
        func_021D0014();
        func_021D0DC8(0);
        func_021D1208(0x11, 0, 1, -1, 0);
        func_021BCB9C();
        func_021C0E40(func_021CE5B0);
        break;
    case 3:
        g_021DE62C = 2;
        func_021D0014();
        func_021CFFAC(9);
        func_021C0E40(func_021CE2D4);
        break;
    }
}
