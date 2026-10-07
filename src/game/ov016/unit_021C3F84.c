/*
 * file:     unit_021C3F84.c
 * unit:     yes
 * function: func_021C3F84, func_021C3FD4, func_021C3FF4, func_021C405C
 * address:  0x021C3F84
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BCB14  0x021BCB14  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C0     0x021DE5C0  data
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   func_021D5790  0x021D5790  arm  ov016
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCAE4  0x021BCAE4  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C2A3C  0x021C2A3C  arm  ov016
 *   func_021C450C  0x021C450C  arm  ov016
 */
extern signed char func_021BCB14(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021BCB9C();
extern void func_021D5790();
extern int func_021D5580();
extern void func_021BCAE4();
extern void func_021D55A4();
extern int func_021BCB58();
extern void func_021D5CA8(int a);
extern void func_021BD138();
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C2A3C();
extern void func_021C450C();
void func_021C3F84(void);
void func_021C3FD4(void);
void func_021C3FF4(void);
void func_021C405C(void);
extern unsigned char g_021DE5C0[];


/*
 * sdk:      button (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
void func_021C3F84(void)
{
    int r = func_021BCB14();
    if (r != 0) {
        if (r != 1)
            return;
        g_021DE5C0[1] = 1;
        func_021CFFAC(6);
    } else {
        g_021DE5C0[1] = 0;
        func_021CFFAC(7);
    }
    func_021C0E40((unsigned int)func_021C3FD4);
}


/*
 * sdk:      endScene (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
void func_021C3FD4(void)
{
    func_021BCB9C();
    func_021D5790(8);
    func_021C0E40((unsigned int)func_021C3FF4);
}


/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
void func_021C3FF4(void)
{
    if (func_021D5580(1))
        return;
    func_021BCAE4();
    if (!g_021DE5C0[1])
        func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 0x15, 8);
    func_021C0E40((unsigned int)func_021C405C);
}


/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
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
        func_021C0E40((unsigned int)func_021C2A3C);
    } else {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C450C);
    }
}
