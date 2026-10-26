/*
 * file:     scenesetlistsave.c
 * unit:     yes
 * function: DWCi_SceneSetListSave, initGraphics, procInit, procInit1, procScene, DWCi_SceneSetListSave_input, DWCi_SceneSetListSave_draw, endScene, endScene1
 * address:  0x021CA5D0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenemenu.o), symbol procInit (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under scenemenu.o; its bytes equal scenemenu.o's own
 * function and only the pool word differs (the next scene step of the copy's own range).
 * The object that owns this copy is not identified; the C is the same either way.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CA684.c \
 *       --func procInit --addr 0x021CA684 --region ov016 --cc 1.1p1 --arm --lang c99
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   initGraphics                     0x021ca5f0 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_SETTINGlSet                 0x021cf8d8 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   sSceneSetListSavePathJbBgStep3Char    0x021DB600  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   sSceneSetListSavePathYbBgStep3Pltt    0x021DB618  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   sSceneSetListSavePathXb4NoneScr    0x021DB630  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_FOCUSlDisp4                 0x021BD4C8  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
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
 *   DWCi_WINlInitEx                  0x021d1208 arm
 *   DWCi_WINlIsInit                  0x021d157c arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_SceneSetSelectAp            0x021cbc90 arm
 */
#include "scenemenu_types.h"
#include "../sdk_ioreg.h"
#include "../arm9/gx_load2d.h"

#include "../types.h"

typedef _Bool bool;

#include "dwcutil_types.h"

/* scenemenu.o .rodata at 0x021DA478, members at their vendor offsets */
typedef struct {
    RECT           R_TOUCH[2];        /* 0x00 */
    RECT           R_FOCUS[2];        /* 0x10 */
} SCENEMENU_RODATA;

/* PALETTE's initialiser is the compiler's @20658 in its own .rodata section */
typedef struct { unsigned char v[2]; } PALETTE_INIT;

#include "headline.h"
#include "setting.h"
#include "dwcutil_main.h"
#include "common.h"
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
#include "graphics.h"
#include "button.h"
#include "sound.h"
#include "focus.h"
#include "input.h"
#include "screen.h"
#include "sceneend.h"
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
#include "window.h"
#include "comment.h"
void DWCi_SceneSetListSave(void);
void DWCi_SceneSetListSave_input(void);
void DWCi_SceneSetListSave_draw(void);
extern unsigned short sSceneSetListSavePathJbBgStep3Char[];
extern unsigned short sSceneSetListSavePathYbBgStep3Pltt[];
extern unsigned short sSceneSetListSavePathXb4NoneScr[];
extern struct SCENEMENU_BSS scenemenu_bss;
extern const SCENEMENU_RODATA scenemenu_rodata;
extern const PALETTE_INIT scenemenu_init_20658;
extern void DWCi_SceneSetSelectAp(void);

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procScene(void);
static void endScene(void);
static void endScene1(void);

void DWCi_SceneSetListSave(void)
{
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_SETTINGlSet();
    DWCi_ChangeScene(procInit);
}

/*
 * Load three tilemaps through DWCi_CMNlLoadResource, then set the low two bits of
 * 0x04001008, 0x0400100A, 0x0400000A and 0x0400000C.
 * Addresses are Black-image addresses.
 */
static void initGraphics(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)(sSceneSetListSavePathJbBgStep3Char), GX_LoadBG2Char);
    DWCi_CMNlLoadResource((char *)(sSceneSetListSavePathYbBgStep3Pltt), GX_LoadBGPltt);
    DWCi_CMNlLoadResource((char *)(sSceneSetListSavePathXb4NoneScr), GX_LoadBG2Scr);

    p = (u16 *)REG_DB_BG0CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)REG_BG1CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
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
    DWCi_ChangeScene(procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_WINlInitEx(0x44, 5, 1, -1, 0);
    DWCi_ChangeScene(procScene);
}



static void procScene(void)
{
    DWCi_SceneSetListSave_input();
    DWCi_SceneSetListSave_draw();
    if (DWCi_WINlIsInit()) {
        return;
    }
    DWCi_ChangeScene(endScene);
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetListSave_input.c \
 *       --func DWCi_SceneSetListSave_input --addr 0x021CA768 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetListSave_input(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetListSave_draw.c \
 *       --func DWCi_SceneSetListSave_draw --addr 0x021CA76C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetListSave_draw(void)
{
}

static void endScene(void)
{
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x14, 8);
    DWCi_ChangeScene(endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    DWCi_SetParam_(2, 1);
    DWCi_ChangeScene(DWCi_SceneSetSelectAp);
}
