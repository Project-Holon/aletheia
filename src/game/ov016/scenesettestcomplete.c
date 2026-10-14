/*
 * file:     scenesettestcomplete.c
 * unit:     yes
 * function: DWCi_SceneSetTestCompletet, initGraphics, procInit, DWCi_SceneSetTestCompletet_procInit1, DWCi_SceneSetTestCompletet_procScene, DWCi_SceneSetTestCompletet_draw, endScene, DWCi_SceneSetTestCompletet_endScene1, wait
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD580.c \n *       --func DWCi_SceneSetTestCompletet --addr 0x021CD580 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettest.o)
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD658.c \n *       --func DWCi_SceneSetTestCompletet_procInit1 --addr 0x021CD658 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   gSceneSetTestCompleteWaitCount     0x021DE620  data
 *   initGraphics  0x021CD5B0  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   procInit  0x021CD61C  arm  ov016
 *   Count                            0x021DE5BC  data
 *   DWCi_CMNlLoadResource            0x021BD1D4  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_MOVlIsEnd                   0x021C11B8  arm
 *   DWCi_SceneOptMenu                0x021C2A3C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   GX_LoadBG2Scr                    0x0207EB78  arm
 *   endScene1                        0x021C3CEC  arm
 *   procScene                        0x021C3C94  arm
 *   sceneoptmovdisco_str_20611       0x021DB800  data
 *   procInit1                        0x021CD658  arm
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   DWCi_STEPlEnd  0x021D0580  arm  ov016
 *   DWCi_STEPlIsEnd  0x021D0A84  arm  ov016
 *   DWCi_SetParam2_  0x021C0E8C  arm  ov016
 *   DWCi_SceneSetList  0x021C82FC  arm  ov016
 *   DWCi_SceneMenu  0x021C1984  arm  ov016
 *   DWCi_Entry  0x021C0ED8  arm  ov016
 *   DWCi_SceneEnd  0x021C1630  arm  ov016
 */
#define reg_G2S_DB_BG0CNT (*(volatile unsigned short *)0x04001008)
#define reg_G2S_DB_BG1CNT (*(volatile unsigned short *)0x0400100A)
#define reg_G2_BG1CNT     (*(volatile unsigned short *)0x0400000A)
#define reg_G2_BG2CNT     (*(volatile unsigned short *)0x0400000C)
typedef _Bool bool;

extern void DWCi_CMNlMsgDraw(int msgId);
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
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneOptMenu(void);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern void DWCi_STEPlEnd(void);
extern int DWCi_STEPlIsEnd(void);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_SceneSetList(void);
extern void DWCi_SceneMenu(void);
extern unsigned int DWCi_Entry(void);
extern void DWCi_SceneEnd(void);
void DWCi_SceneSetTestCompletet(void);
void DWCi_SceneSetTestCompletet_procInit1(void);
void DWCi_SceneSetTestCompletet_procScene(void);
void DWCi_SceneSetTestCompletet_draw(void);
void DWCi_SceneSetTestCompletet_endScene1(void);
extern unsigned char gSceneSetTestCompleteWaitCount;
/* sceneoptmovdisco .bss */
extern unsigned char Count;
/* the resource file name, the compiler's @20611 in .rodata */
extern char sceneoptmovdisco_str_20611[];

static void initGraphics(void);
static void procInit(void);
static void endScene(void);
static void wait(void);


void DWCi_SceneSetTestCompletet(void)
{
    gSceneSetTestCompleteWaitCount = 0;
    initGraphics();
    DWCi_CMNlMsgDraw(45);
    DWCi_ChangeScene(procInit);
}


static void procInit1(void);


static void procScene(void);


static void endScene1(void);


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


void DWCi_SceneSetTestCompletet_procInit1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_ChangeScene(DWCi_SceneSetTestCompletet_procScene);
}


/*
 * Call wait, DWCi_SceneSetTestCompletet_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTestCompletet_procScene.c \
 *       --func DWCi_SceneSetTestCompletet_procScene --addr 0x021CD67C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTestCompletet_procScene(void)
{
    wait();
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD690.c \n *       --func endScene --addr 0x021CD690 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void endScene(void)
{
    int scene;
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    if (scene != 0)
        DWCi_STEPlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 21, 8);
    DWCi_ChangeScene(DWCi_SceneSetTestCompletet_endScene1);
}


void DWCi_SceneSetTestCompletet_endScene1(void)
{
    int scene;
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_STEPlIsEnd())
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 21);
    DWCi_SetParam_((unsigned int)(2), (unsigned int)(1));
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    if (scene == 0) {
        DWCi_SetParam2_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetList);
        return;
    }
    DWCi_ChangeScene(DWCi_SceneMenu);
}


/*
 * sdk:      wait (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD79C.c \n *       --func wait --addr 0x021CD79C --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void wait(void)
{
    int scene;
    int r;
    if (++gSceneSetTestCompleteWaitCount < 180)
        return;
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    r = DWCi_Entry();
    if (r != 0 && r == 1 && scene != 0) {
        DWCi_ChangeScene(DWCi_SceneEnd);
        return;
    }
    DWCi_ChangeScene(endScene);
}
