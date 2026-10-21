/*
 * file:     scenesettestconfirm.c
 * unit:     yes
 * function: DWCi_SceneSetTestConfirm, initGraphics, procInit, procInit1, procScene, DWCi_SceneSetTestConfNopA, DWCi_SceneSetTestConfNopB, endScene, endScene1
 * address:  0x021CD80C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      DWCi_SceneSetTestConfirm (libdwcutil.TWL.HYB.a scenesettestconf)
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SceneSetTestConfirm.c \n *       --func DWCi_SceneSetTestConfirm --addr 0x021CD80C --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovdisco), symbol initGraphics (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneoptmovdisco; its bytes equal the object's own
 * function and only the pool words differ (the copy's own data and next scene step).
 * The object that owns this copy is not identified; the C is the same either way.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD870.c \
 *       --func initGraphics --addr 0x021CD870 --region ov016 --cc 1.1p1 --arm --lang c99
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenemenu.o), symbol procInit (name and prototype from the
 * layout/symbols_sdk.txt files this copy under scenemenu.o; its bytes equal scenemenu.o's own
 * function and only the pool word differs (the next scene step of the copy's own range).
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD8DC.c \
 *       --func procInit --addr 0x021CD8DC --region ov016 --cc 1.1p1 --arm --lang c99
 *
 * symbols:
 *   DWCi_SEARCHlEnd  0x021CEF50  arm  ov016
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   initGraphics  0x021CD870  arm  ov016
 *   DWCi_COMMENTlDispEx  0x021BD060  arm  ov016
 *   DWCi_HLlLoadSet  0x021BD6D4  arm  ov016
 *   DWCi_SETTINGlSet  0x021CF8D8  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   procInit  0x021CD8DC  arm  ov016
 *   sScenesettestconfirmCount                            0x021DE5BC  data
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
 *   sceneoptmovdisco_str_20611       0x021DB814  data
 *   wait                             0x021C3D58  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_FOCUSlDisp4                 0x021BD4C8  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_SCREENlCopyPalette          0x021CE7B0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   dispPushButton                   0x021C1EDC  arm
 *   endScene2                        0x021C1DC4  arm
 *   moveFocus                        0x021C1E70  arm
 *   procInit2                        0x021C1B90  arm
 *   scenemenu_bss                    0x021DE59C  data
 *   scenemenu_init_20658             0x021DA474  data
 *   scenemenu_rodata                 0x021DA478  data
 *   gSceneSetTestConfirmMessageIds     0x021DA8AC  data
 *   DWCi_WINlInitEx  0x021D1208  arm  ov016
 *   DWCi_WINlGet  0x021D1568  arm  ov016
 *   DWCi_WINlEnd  0x021D1524  arm  ov016
 *   DWCi_WINlIsInit  0x021D157C  arm  ov016
 *   DWCi_SceneSetTest  0x021CD160  arm  ov016
 */
#include "scenemenu_types.h"
#include "../sdk_ioreg.h"
#include "common.h"
#include "../arm9/gx_load2d.h"

#define reg_G2S_DB_BG0CNT (*(volatile unsigned short *)REG_DB_BG0CNT_ADDR)
#define reg_G2S_DB_BG1CNT (*(volatile unsigned short *)REG_DB_BG1CNT_ADDR)
#define reg_G2_BG1CNT     (*(volatile unsigned short *)REG_BG1CNT_ADDR)
#define reg_G2_BG2CNT     (*(volatile unsigned short *)REG_BG2CNT_ADDR)
typedef _Bool bool;

#include "dwcutil_types.h"

/* scenemenu.o .rodata at 0x021DA478, members at their vendor offsets */
typedef struct {
    RECT           R_TOUCH[2];        /* 0x00 */
    RECT           R_FOCUS[2];        /* 0x10 */
} SCENEMENU_RODATA;

/* PALETTE's initialiser is the compiler's @20658 in its own .rodata section */
typedef struct { unsigned char v[2]; } PALETTE_INIT;

typedef struct { int m[3]; } MsgTable;

#include "search.h"
#include "dwcutil_main.h"
#include "comment.h"
#include "headline.h"
#include "setting.h"
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "graphics.h"
#include "move.h"
#include "font.h"
#include "sceneoptmenu.h"
extern bool DWCi_EFFlWait(int frame);
#include "button.h"
#include "sound.h"
#include "focus.h"
#include "input.h"
#include "screen.h"
#include "sceneend.h"
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
#include "window.h"
#include "scenesettest.h"
void DWCi_SceneSetTestConfirm(void);
void DWCi_SceneSetTestConfNopA(void);
void DWCi_SceneSetTestConfNopB(void);
/* sceneoptmovdisco .bss */
extern unsigned char sScenesettestconfirmCount;
/* the resource file name, the compiler's @20611 in .rodata */
extern char sceneoptmovdisco_str_20611[];
extern struct SCENEMENU_BSS scenemenu_bss;
extern const SCENEMENU_RODATA scenemenu_rodata;
extern const PALETTE_INIT scenemenu_init_20658;
extern MsgTable gSceneSetTestConfirmMessageIds;

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procScene(void);
static void endScene(void);
static void endScene1(void);


void DWCi_SceneSetTestConfirm(void)
{
    int prm;
    DWCi_SEARCHlEnd();
    DWCi_GetParam2_(0, (unsigned int *)((void **)&prm));
    initGraphics();
    DWCi_COMMENTlDispEx(49, -1, 0);
    if (prm != 2)
        DWCi_HLlLoadSet();
    if (prm == 1)
        DWCi_SETTINGlSet();
    DWCi_ChangeScene((uptr)procInit);
}


static void wait(void);


static void initGraphics(void)
{
    DWCi_CMNlLoadResource(sceneoptmovdisco_str_20611, GX_LoadBG2Scr);
    reg_G2S_DB_BG0CNT = (unsigned short)((reg_G2S_DB_BG0CNT & ~3) | 3);
    reg_G2S_DB_BG1CNT = (unsigned short)((reg_G2S_DB_BG1CNT & ~3) | 3);
    reg_G2_BG1CNT = (unsigned short)((reg_G2_BG1CNT & ~3) | 3);
    reg_G2_BG2CNT = (unsigned short)((reg_G2_BG2CNT & ~3) | 3);
}

static void procInit2(void);

static void endScene2(void);

static void moveFocus(int dir);

static void dispPushButton(void);


static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x14, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x14);
    DWCi_ChangeScene((uptr)procInit1);
}


/*
 * sdk:      procInit1 (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD944.c \n *       --func procInit1 --addr 0x021CD944 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void procInit1(void)
{
    int prm;
    MsgTable msg = gSceneSetTestConfirmMessageIds;
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_GetParam2_(0, (unsigned int *)((void **)&prm));
    DWCi_WINlInitEx(msg.m[prm], 1, 1, -1, 0);
    DWCi_ChangeScene((uptr)procScene);
}


/*
 * sdk:      procScene (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD9CC.c \n *       --func procScene --addr 0x021CD9CC --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void procScene(void)
{
    DWCi_SceneSetTestConfNopA();
    DWCi_SceneSetTestConfNopB();
    if (DWCi_WINlGet())
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_SNDlPlay(6);
    DWCi_ChangeScene((uptr)endScene);
}


void DWCi_SceneSetTestConfNopA(void)
{
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTestConfNopB.c \
 *       --func DWCi_SceneSetTestConfNopB --addr 0x021CDA10 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTestConfNopB(void)
{
}


/*
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA14.c \n *       --func endScene --addr 0x021CDA14 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void endScene(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_EFFlFade(3, 0, 20, 8);
    DWCi_ChangeScene((uptr)endScene1);
}


/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA48.c \n *       --func endScene1 --addr 0x021CDA48 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void endScene1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_GXlInvisible(0, 20);
    DWCi_SetParam_(0, (unsigned int)(1));
    DWCi_ChangeScene((uptr)DWCi_SceneSetTest);
}
