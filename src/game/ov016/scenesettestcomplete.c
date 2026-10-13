/*
 * file:     scenesettestcomplete.c
 * unit:     yes
 * function: func_021CD580, initGraphics, procInit, func_021CD658, DWCi_SceneSetTestCompletet_procScene, DWCi_SceneSetTestCompletet_draw, func_021CD690, func_021CD6F0, func_021CD79C
 * address:  0x021CD580
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      DWCi_SceneSetTestCompletet (libdwcutil.TWL.HYB.a scenesettestcomp)
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD580.c \n *       --func func_021CD580 --addr 0x021CD580 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettest.o)
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD658.c \n *       --func func_021CD658 --addr 0x021CD658 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   g_021DE620     0x021DE620  data
 *   func_021CD5B0  0x021CD5B0  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CD61C  0x021CD61C  arm  ov016
 *   Count                            0x021DE5BC  data
 *   DWCi_CMNlLoadResource            0x021BD1D4  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_MOVlIsEnd                   0x021C11B8  arm
 *   DWCi_SceneOptMenu                0x021C2A3C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   GX_LoadBG2Scr                    0x0207EB78  arm
 *   endScene                         0x021C3CA8  arm
 *   endScene1                        0x021C3CEC  arm
 *   procScene                        0x021C3C94  arm
 *   sceneoptmovdisco_str_20611       0x021DB800  data
 *   wait                             0x021C3D58  arm
 *   procInit1                        0x021CD658  arm
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021D0580  0x021D0580  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021D0A84  0x021D0A84  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E8C  0x021C0E8C  arm  ov016
 *   func_021C82FC  0x021C82FC  arm  ov016
 *   func_021C1984  0x021C1984  arm  ov016
 *   func_021C0ED8  0x021C0ED8  arm  ov016
 *   func_021C1630  0x021C1630  arm  ov016
 */
#define reg_G2S_DB_BG0CNT (*(volatile unsigned short *)0x04001008)
#define reg_G2S_DB_BG1CNT (*(volatile unsigned short *)0x0400100A)
#define reg_G2_BG1CNT     (*(volatile unsigned short *)0x0400000A)
#define reg_G2_BG2CNT     (*(volatile unsigned short *)0x0400000C)
typedef _Bool bool;

extern void func_021CD5B0(void);
extern void func_021BD29C(int msgId);
extern void func_021C0E40(unsigned int v);
extern void func_021CD61C(void);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void GX_LoadBG2Scr(void *src, unsigned long offset, unsigned long size);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_MOVlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_SceneOptMenu(void);
extern int func_021D5580(int lcd);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021D0580(void);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
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
void func_021CD580(void);
void func_021CD658(void);
void DWCi_SceneSetTestCompletet_procScene(void);
void DWCi_SceneSetTestCompletet_draw(void);
void func_021CD690(void);
void func_021CD6F0(void);
void func_021CD79C(void);
extern unsigned char g_021DE620;
/* sceneoptmovdisco .bss */
extern unsigned char Count;
/* the resource file name, the compiler's @20611 in .rodata */
extern char sceneoptmovdisco_str_20611[];


void func_021CD580(void)
{
    g_021DE620 = 0;
    func_021CD5B0();
    func_021BD29C(45);
    func_021C0E40((unsigned int)func_021CD61C);
}



static void initGraphics(void);


static void procInit(void);


static void procInit1(void);


static void procScene(void);


static void endScene(void);


static void endScene1(void);


static void wait(void);



static void initGraphics(void)
{
    DWCi_CMNlLoadResource(sceneoptmovdisco_str_20611, GX_LoadBG2Scr);
    reg_G2S_DB_BG0CNT = (unsigned short)((reg_G2S_DB_BG0CNT & ~3) | 3);
    reg_G2S_DB_BG1CNT = (unsigned short)((reg_G2S_DB_BG1CNT & ~3) | 3);
    reg_G2_BG1CNT = (unsigned short)((reg_G2_BG1CNT & ~3) | 3);
    reg_G2_BG2CNT = (unsigned short)((reg_G2_BG2CNT & ~3) | 3);
}



static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}


void func_021CD658(void)
{
    if (func_021D5580(0))
        return;
    func_021C0E40((unsigned int)DWCi_SceneSetTestCompletet_procScene);
}



/*
 * Call func_021CD79C, DWCi_SceneSetTestCompletet_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTestCompletet_procScene.c \
 *       --func DWCi_SceneSetTestCompletet_procScene --addr 0x021CD67C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTestCompletet_procScene(void)
{
    func_021CD79C();
    DWCi_SceneSetTestCompletet_draw();
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTestCompletet_draw.c \
 *       --func DWCi_SceneSetTestCompletet_draw --addr 0x021CD68C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTestCompletet_draw(void)
{
}



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
