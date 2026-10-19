/*
 * file:     scenesetaosscomplete.c
 * unit:     yes
 * function: DWCi_SceneSetAossComplete, initGraphics, procInit, procInit1, DWCi_SceneSetAossComplete_procScene, DWCi_SceneSetAossComplete_draw, endScene, endScene1, wait
 * address:  0x021C4EC8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      DWCi_SceneSetAossComplete (libdwcutil.TWL.HYB.a scenesetaosscomplete.o)
 * sdk:      procInit1 (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovdisco), symbol endScene (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneoptmovdisco; its bytes equal the object's own
 * function and only the pool words differ (the copy's own data and next scene step).
 * The object that owns this copy is not identified; the C is the same either way.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C4FE4.c \
 *       --func endScene --addr 0x021C4FE4 --region ov016 --cc 1.1p1 --arm --lang c99
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a(scenesetaosscomp))
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovdisco), symbol wait (name and prototype from the
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C50A0.c \
 *       --func wait --addr 0x021C50A0 --region ov016 --cc 1.1p1 --arm --lang c99
 *
 * symbols:
 *   initGraphics  0x021C4F04  arm  ov016
 *   DWCi_HLlLoadSet  0x021BD6D4  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneSetAossCompleteWork     0x021DE5D4  data
 *   procInit  0x021C4F70  arm  ov016
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
 *   procScene                        0x021C3C94  arm
 *   sceneoptmovdisco_str_20611       0x021DB424  data
 *   DWCi_SetParam2_  0x021C0E8C  arm
 *   DWCi_SceneSetTestConfirm  0x021CD80C  arm
 */
#define reg_G2S_DB_BG0CNT (*(volatile unsigned short *)0x04001008)
#define reg_G2S_DB_BG1CNT (*(volatile unsigned short *)0x0400100A)
#define reg_G2_BG1CNT     (*(volatile unsigned short *)0x0400000A)
#define reg_G2_BG2CNT     (*(volatile unsigned short *)0x0400000C)
typedef _Bool bool;

extern void DWCi_HLlLoadSet();
extern void DWCi_CMNlMsgDraw();
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void GX_LoadBG2Scr(void *src, unsigned long offset, unsigned long size);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)(void));
extern int DWCi_MOVlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_SceneSetTestConfirm(void);
void DWCi_SceneSetAossComplete(void);
void DWCi_SceneSetAossComplete_procScene(void);
void DWCi_SceneSetAossComplete_draw(void);
extern unsigned char gSceneSetAossCompleteWork;
/* sceneoptmovdisco .bss */
/* the resource file name, the compiler's @20611 in .rodata */
extern char sceneoptmovdisco_str_20611[];

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void endScene(void);
static void endScene1(void);
static void wait(void);


void DWCi_SceneSetAossComplete(void)
{
    gSceneSetAossCompleteWork = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x23);
    DWCi_SNDlPlay(0x10);
    DWCi_ChangeScene(procInit);
}


static void procScene(void);


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


static void procInit1(void)
{
    if (!DWCi_EFFlCheck(0))
        DWCi_ChangeScene(DWCi_SceneSetAossComplete_procScene);
}


/*
 * Call wait, DWCi_SceneSetAossComplete_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetAossComplete_procScene.c \
 *       --func DWCi_SceneSetAossComplete_procScene --addr 0x021C4FD0 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetAossComplete_procScene(void)
{
    wait();
    DWCi_SceneSetAossComplete_draw();
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetAossComplete_draw.c \
 *       --func DWCi_SceneSetAossComplete_draw --addr 0x021C4FE0 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetAossComplete_draw(void)
{
}


static void endScene(void)
{
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene1);
}


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1) != 0)
        return;
    if (DWCi_EFFlCheck(0) != 0)
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 0);
    DWCi_SetParam2_(0, 1);
    DWCi_ChangeScene(DWCi_SceneSetTestConfirm);
}


static void wait(void)
{
    if (++gSceneSetAossCompleteWork >= 120)
        DWCi_ChangeScene(endScene);
}
