/*
 * file:     unit_021CD690.c
 * unit:     yes
 * function: func_021CD690, func_021CD6F0, func_021CD79C
 * address:  0x021CD690
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
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021D0580  0x021D0580  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021D0A84  0x021D0A84  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E8C  0x021C0E8C  arm  ov016
 *   func_021C82FC  0x021C82FC  arm  ov016
 *   func_021C1984  0x021C1984  arm  ov016
 *   g_021DE620     0x021DE620  data
 *   func_021C0ED8  0x021C0ED8  arm  ov016
 *   func_021C1630  0x021C1630  arm  ov016
 */
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021D0580(void);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(unsigned int v);
extern int func_021D5580(int lcd);
extern int func_021D0A84(void);
extern void func_021D5CA8(int lcd);
extern int func_021BD138(void);
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E8C(unsigned int a, unsigned int b);
extern void func_021C82FC(void);
extern void func_021C1984(void);
extern unsigned int func_021C0ED8(void);
extern void func_021C1630(void);
void func_021CD690(void);
void func_021CD6F0(void);
void func_021CD79C(void);
extern unsigned char g_021DE620;


/*
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD690.c \n *       --func func_021CD690 --addr 0x021CD690 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CD690(void)
{
    int scene;
    func_021C0EA0(0, (unsigned int *)((void **)&scene));
    if (scene != 0)
        func_021D0580();
    func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 21, 8);
    func_021C0E40((unsigned int)func_021CD6F0);
}


void func_021CD6F0(void)
{
    int scene;
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    if (!func_021D0A84())
        return;
    func_021D5CA8(0);
    func_021BD138();
    func_021D6090(1, 1);
    func_021D6090(0, 21);
    func_021C0E50((unsigned int)((void *)2), (unsigned int)((void *)1));
    func_021C0EA0(0, (unsigned int *)((void **)&scene));
    if (scene == 0) {
        func_021C0E8C(0, 0);
        func_021C0E40((unsigned int)func_021C82FC);
        return;
    }
    func_021C0E40((unsigned int)func_021C1984);
}


/*
 * sdk:      wait (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD79C.c \n *       --func func_021CD79C --addr 0x021CD79C --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CD79C(void)
{
    int scene;
    int r;
    if (++g_021DE620 < 180)
        return;
    func_021C0EA0(0, (unsigned int *)((void **)&scene));
    r = func_021C0ED8();
    if (r != 0 && r == 1 && scene != 0) {
        func_021C0E40((unsigned int)func_021C1630);
        return;
    }
    func_021C0E40((unsigned int)func_021CD690);
}
