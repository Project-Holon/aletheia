/*
 * file:     unit_021C46B0.c
 * unit:     yes
 * function: func_021C46B0, func_021C46DC, func_021C4714, func_021C4794, func_021C4890, func_021C48E4
 * address:  0x021C46B0
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
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   endScene                         0x021C46DC  arm
 *   func_021D5580  0x021D5580  arm
 *   func_021C11B8  0x021C11B8  arm
 *   func_021BCAE4  0x021BCAE4  arm
 *   func_021D55A4  0x021D55A4  arm
 *   func_021C0E40  0x021C0E40  arm
 *   g_021DE5C8     0x021DE5C8  data
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021BC8EC  0x021BC8EC  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C2A3C  0x021C2A3C  arm  ov016
 *   func_021C3D8C  0x021C3D8C  arm  ov016
 *   func_021C4110  0x021C4110  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C11D4  0x021C11D4  arm  ov016
 */
typedef unsigned char u8;

extern int DWCi_BTNlGet(void);
extern void DWCi_SNDlStop(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021C115C(void);
extern void func_021BCB9C(void);
extern void func_021D5790(int);
extern void func_021C0E40(unsigned int v);
extern int  func_021D5580(int x);
extern int  func_021C11B8(void);
extern void func_021BCAE4(void);
extern void func_021D55A4(int a, int b, int c, int d);
extern int func_021BCB58();
extern void func_021BC8EC();
extern void func_021D5CA8(int a);
extern void func_021BD138();
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C2A3C();
extern void func_021C3D8C();
extern void func_021C4110();
extern void func_021D0014();
extern void func_021CFFAC(unsigned int v);
extern void func_021C11D4(unsigned int v);
void func_021C46DC(void);
void func_021C4714(void);
void func_021C4794(void);
void func_021C4890(int state);
int func_021C48E4(void);
extern u8   g_021DE5C8;



static void endScene(void);



static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
    DWCi_ChangeScene(endScene);
}



/*
 * Wake the sub-state, flag it and post the event at 0x021C4714.
 * Addresses are Black-image addresses.
 */
void func_021C46DC(void)
{
    if (*(unsigned char *)0x021DE5C8 == 0)
        func_021C115C();
    func_021BCB9C();
    func_021D5790(8);
    func_021C0E40((unsigned int)((void *)0x021C4714));
}



void func_021C4714(void)
{
    if (func_021D5580(1) != 0)
        return;
    if (g_021DE5C8 == 0) {
        if (func_021C11B8() == 0)
            return;
    }
    func_021BCAE4();
    if (g_021DE5C8 == 0)
        func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 0x15, 8);
    func_021C0E40((unsigned int)func_021C4794);
}



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
