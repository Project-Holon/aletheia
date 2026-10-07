/*
 * file:     unit_021C46B0_p02.c
 * unit:     yes
 * function: func_021C4794, func_021C4890, func_021C48E4
 * address:  0x021C4794
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
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021C11B8  0x021C11B8  arm  ov016
 *   func_021BC8EC  0x021BC8EC  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C8     0x021DE5C8  data
 *   func_021C2A3C  0x021C2A3C  arm  ov016
 *   func_021C3D8C  0x021C3D8C  arm  ov016
 *   func_021C4110  0x021C4110  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C11D4  0x021C11D4  arm  ov016
 *   func_021C46DC  0x021C46DC  arm  ov016
 */
extern int func_021D5580();
extern int func_021BCB58();
extern int func_021C11B8();
extern void func_021BC8EC();
extern void func_021D5CA8(int a);
extern void func_021BD138();
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021C2A3C();
extern void func_021C3D8C();
extern void func_021C4110();
extern void func_021D0014();
extern void func_021CFFAC(unsigned int v);
extern void func_021C11D4(unsigned int v);
extern void func_021C46DC();
void func_021C4794(void);
void func_021C4890(int state);
int func_021C48E4(void);
extern unsigned char g_021DE5C8;


/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneoptmovwait.o)
 */
void func_021C4794(void)
{
    if (func_021D5580(0))
        return;
    if (g_021DE5C8 == 0) {
        if (func_021D5580(1))
            return;
    }
    if (!func_021BCB58())
        return;
    if (g_021DE5C8 == 0) {
        if (!func_021C11B8())
            return;
    }
    func_021BC8EC();
    func_021D5CA8(0);
    if (g_021DE5C8 == 0) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021D6090(0, 0x15);
    if (g_021DE5C8 == 0) {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C2A3C);
    } else if (g_021DE5C8 == 2) {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C3D8C);
    } else {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C4110);
    }
}


/*
 * sdk:      cbMov (libdwcutil.TWL.HYB.a sceneoptmovwait.o)
 */
void func_021C4890(int state)
{
    func_021D0014();
    if (state == 0) {
        g_021DE5C8 = 1;
        func_021CFFAC(0x10);
    } else {
        g_021DE5C8 = 2;
        func_021CFFAC(0x12);
    }
    func_021C11D4(0);
    func_021C0E40((unsigned int)func_021C46DC);
}

/*
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C48E4.c \
 *       --func func_021C48E4 --addr 0x021C48E4 --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021C48E4(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}
