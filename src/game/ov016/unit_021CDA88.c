/*
 * file:     unit_021CDA88.c
 * unit:     yes
 * function: func_021CDA88, func_021CDAC8, func_021CDB48
 * address:  0x021CDA88
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
 *   g_021DE624     0x021DE624  data
 *   func_021BD674  0x021BD674  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021BD1D4  0x021BD1D4  arm
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021D603C  0x021D603C  arm  ov016
 *   func_021CDB84  0x021CDB84  arm  ov016
 */
typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

extern void func_021BD674(int idx);
extern void func_021BD29C(int msgId);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021D603C(int lcd, int plane);
extern void func_021CDB84(void);
void func_021CDA88(void);
void func_021CDAC8(void);
void func_021CDB48(void);
extern unsigned char g_021DE624;


/*
 * sdk:      DWCi_SceneSetUsbComplete (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA88.c \n *       --func func_021CDA88 --addr 0x021CDA88 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CDA88(void)
{
    g_021DE624 = 0;
    func_021CDAC8();
    func_021BD674(8);
    func_021BD29C(41);
    func_021CFFAC(16);
    func_021C0E40((unsigned int)func_021CDB48);
}


void func_021CDAC8(void)
{
    func_021BD1D4((void *)0x021DB828, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}


/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDB48.c \n *       --func func_021CDB48 --addr 0x021CDB48 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CDB48(void)
{
    func_021D55A4(2, 0, 21, 8);
    func_021D603C(0, 21);
    func_021C0E40((unsigned int)func_021CDB84);
}
