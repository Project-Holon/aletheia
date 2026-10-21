/*
 * file:     scenemenu.c
 * unit:     yes
 * function: DWCi_SceneMenu, initGraphics, procInit, procInit1, procInit2, DWCi_SceneMenu_procScene, input, DWCi_SceneMenu_draw, button, endScene, endScene1, endScene2, moveFocus, dispPushButton
 * address:  0x021C1984
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call input, DWCi_SceneMenu_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneMenu_procScene.c \
 *       --func DWCi_SceneMenu_procScene --addr 0x021C1BB4 --region ov016 --cc dsi/1.1p1 --arm
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenemenu.o), symbol input (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C1BC8.c \
 *       --func input --addr 0x021C1BC8 --region ov016 --cc 1.1p1 --arm --lang c99
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneMenu_draw.c \
 *       --func DWCi_SceneMenu_draw --addr 0x021C1CF8 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_HLlLoad  0x021BD674  arm
 *   DWCi_COMMENTlDispEx  0x021BD060  arm
 *   DWCi_STEPlChangeScr  0x021D0AB0  arm
 *   DWCi_FOCUSlDisp4  0x021BD4C8  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   gSceneMenuWork   0x021DE59C  data
 *   sSceneMenuFocusX0     0x021DA488  data
 *   sSceneMenuFocusY0     0x021DA48A  data
 *   sSceneMenuFocusX1     0x021DA48C  data
 *   sSceneMenuFocusY1     0x021DA48E  data
 *   procInit  0x021C1AE8  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   DWCi_Char   0x021BD170  arm  ov016
 *   DWCi_ARClReadEx   0x021D4B68  arm  ov016
 *   sSceneMenuPathYbBgStep11Pltt    0x021DA498  data
 *   sSceneMenuPathJbBgStep1Char    0x021DB270  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   sSceneMenuPathJbBgStep1Pltt    0x021DB288  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   sSceneMenuPathJb2MenuScr    0x021DB2A0  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_SCREENlCopyPalette          0x021CE7B0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   endScene2                        0x021C1DC4  arm
 *   scenemenu_bss                    0x021DE59C  data
 *   scenemenu_init_20658             0x021DA474  data
 *   scenemenu_rodata                 0x021DA478  data
 *   DWCi_FOCUSlDelete  0x021BD5A8  arm
 *   DWCi_COMMENTlDelete  0x021BD138  arm
 *   DWCi_ARClRelease  0x021D4C68  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   DWCi_SceneSetSelectAp  0x021CBC90  arm
 *   DWCi_SceneOptMenu  0x021C2A3C  arm
 *   DWCi_SceneMenu  0x021C1984  arm
 *   initGraphics  0x021C1A04  arm
 *   DWCi_SceneMenu_procScene  0x021C1BB4  arm
 *   input  0x021C1BC8  arm
 *   DWCi_SceneMenu_draw  0x021C1CF8  arm
 *   button  0x021C1CFC  arm
 */
#include "scenemenu_types.h"
#include "../sdk_ioreg.h"
#include "../arm9/gx_load2d.h"

#include "../types.h"

typedef struct {
    char name[0x14];
    u8 pad14;
    u8 pad15;
} T;

typedef _Bool bool;

#include "dwcutil_types.h"

/* scenemenu.o .rodata at 0x021DA478, members at their vendor offsets */
typedef struct {
    RECT           R_TOUCH[2];        /* 0x00 */
    RECT           R_FOCUS[2];        /* 0x10 */
} SCENEMENU_RODATA;

/* PALETTE's initialiser is the compiler's @20658 in its own .rodata section */
typedef struct { unsigned char v[2]; } PALETTE_INIT;

struct SceneMenuState {
    u8  focusPos;
    u8  pad01[3];
    int palette;
};

#include "headline.h"
#include "comment.h"
#include "step.h"
#include "common.h"
#include "archive.h"
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
#include "graphics.h"
#include "dwcutil_main.h"
#include "button.h"
#include "sound.h"
#include "focus.h"
#include "input.h"
#include "screen.h"
#include "sceneend.h"
#include "scenesetselectap.h"
#include "sceneoptmenu.h"
void DWCi_SceneMenu(void);
void DWCi_SceneMenu_procScene(void);
void DWCi_SceneMenu_draw(void);
extern struct SceneMenuState gSceneMenuWork;
extern u16  sSceneMenuFocusX0[][4];
extern u16  sSceneMenuFocusY0[][4];
extern u16  sSceneMenuFocusX1[][4];
extern u16  sSceneMenuFocusY1[][4];
extern T sSceneMenuPathYbBgStep11Pltt;
extern unsigned char sSceneMenuPathJbBgStep1Char[];
extern unsigned char sSceneMenuPathJbBgStep1Pltt[];
extern unsigned char sSceneMenuPathJb2MenuScr[];
extern struct SCENEMENU_BSS scenemenu_bss;
extern const SCENEMENU_RODATA scenemenu_rodata;
extern const PALETTE_INIT scenemenu_init_20658;

/*
 * Settles the panel and dispatches the record indexed by gSceneMenuWork[0].
 */

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void moveFocus(int dir);
static void dispPushButton(void);
void DWCi_SceneMenu(void)
{
    u8 i;

    initGraphics();
    DWCi_HLlLoad(0);
    DWCi_COMMENTlDispEx(0x2e, -1, 0);
    DWCi_STEPlChangeScr(4);
    i = gSceneMenuWork.focusPos;
    DWCi_FOCUSlDisp4(sSceneMenuFocusX0[i][0], sSceneMenuFocusX1[i][0],
                  sSceneMenuFocusY0[i][0], sSceneMenuFocusY1[i][0]);
    DWCi_ChangeScene((uptr)procInit);
}

/*
 * Copy a 0x16-byte NCL descriptor (name + two flags) from the static table to
 * a stack buffer, load three tilemaps through DWCi_CMNlLoadResource, publish the
 * buffer through DWCi_Char/DWCi_ARClReadEx into the 0x021DE59C record, then
 * set the low two bits of the 0x04001008 and 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/initGraphics.c \
 *       --func initGraphics --addr 0x021C1A04 --region ov016 --cc dsi/1.1p1 --arm
 */
static void initGraphics(void)
{
    T buf;
    u16 *p;

    buf = sSceneMenuPathYbBgStep11Pltt;
    DWCi_CMNlLoadResource((char *)((sptr)sSceneMenuPathJbBgStep1Char), GX_LoadBG2Char);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneMenuPathJbBgStep1Pltt), GX_LoadBGPltt);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneMenuPathJb2MenuScr), GX_LoadBG2Scr);
    gSceneMenuWork.palette = (sptr)DWCi_ARClReadEx((char *)((sptr)DWCi_Char((unsigned char *)(&buf))), 0, 4);

    p = (u16 *)REG_DB_BG0CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)REG_BG1CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}


static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x14, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x14);
    DWCi_ChangeScene((uptr)procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(0);
    DWCi_ChangeScene((uptr)procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene((uptr)DWCi_SceneMenu_procScene);
}

void DWCi_SceneMenu_procScene(void)
{
    input();
    DWCi_SceneMenu_draw();
    button();
}

static void input(void)
{
    int i;

    for (i = 0; i < sizeof(scenemenu_rodata.R_TOUCH) / sizeof(RECT); i++) {
        if (DWCi_TPlCheckTrigger((unsigned short *)&scenemenu_rodata.R_TOUCH[i])) {
            DWCi_BTNlSet(1);
            scenemenu_bss.FocusPos = (unsigned char)i;
            DWCi_FOCUSlDisp4(scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].l, scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].r,
                             scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].t, scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].b);
            return;
        }
    }
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(1);
    else if (DWCi_IPTlCheckTrigger(2))
        DWCi_BTNlSet(0);
    else if (DWCi_IPTlCheckRepeat(0x40))
        moveFocus(1);
    else if (DWCi_IPTlCheckRepeat(0x80))
        moveFocus(3);
    else if (DWCi_IPTlCheckRepeat(0x20))
        moveFocus(0);
    else if (DWCi_IPTlCheckRepeat(0x10))
        moveFocus(2);
}

void DWCi_SceneMenu_draw(void)
{
}

static void button(void)
{
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        DWCi_ChangeScene((uptr)DWCi_SceneEnd);
        break;
    case 1:
        DWCi_SNDlPlay(6);
        dispPushButton();
        DWCi_ChangeScene((uptr)endScene);
        break;
    }
}

static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((uptr)endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x16, 8);
    DWCi_ChangeScene((uptr)endScene2);
}

static void endScene2(void)
{
    if (DWCi_EFFlCheck(1) != 0)
        return;
    if (DWCi_EFFlCheck(0) != 0)
        return;
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_ARClRelease((void *)gSceneMenuWork.palette);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    switch (gSceneMenuWork.focusPos) {
    case 0:
        DWCi_SetParam_(1, 0);
        DWCi_ChangeScene((uptr)DWCi_SceneSetSelectAp);
        return;
    case 1:
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene((uptr)DWCi_SceneOptMenu);
        return;
    }
}

static void moveFocus(int dir)
{
    if (dir != 1 && dir != 3) {
        scenemenu_bss.FocusPos ^= 1;
        DWCi_SNDlPlay(8);
        DWCi_FOCUSlDisp4(scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].l, scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].r,
                         scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].t, scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].b);
    }
}

static void dispPushButton(void)
{
    PALETTE_INIT PALETTE = scenemenu_init_20658;

    DWCi_SCREENlCopyPalette(scenemenu_bss.Palette, PALETTE.v[scenemenu_bss.FocusPos], PALETTE.v[scenemenu_bss.FocusPos]);
}
