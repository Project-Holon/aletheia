/*
 * file:     scenesetselectway.c
 * unit:     yes
 * function: DWCi_SceneSetSelectWay, initGraphics, procInit, procInit1, procInit2, DWCi_SceneSetSelectWay_procScene, input, DWCi_SceneSetSelectWay_draw, button, endScene, endScene1, endScene2, moveFocus, DWCi_SceneSetSelectWayDispPush
 * address:  0x021CC998
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      DWCi_SceneSetSelectWay (libdwcutil.TWL.HYB.a scenesetselectwa)
 * Call input, DWCi_SceneSetSelectWay_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetSelectWay_procScene.c \
 *       --func DWCi_SceneSetSelectWay_procScene --addr 0x021CCC70 --region ov016 --cc dsi/1.1p1 --arm
 * sdk:      input (libdwcutil.TWL.HYB.a scenesetselectwa)
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneSetSelectWay_draw.c \
 *       --func DWCi_SceneSetSelectWay_draw --addr 0x021CCE00 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_SETTIGNlGet                 0x021CF404  arm
 *   DWCi_Language                    0x021C0EC8  arm
 *   initGraphics                     0x021CCAC0  arm   ov016
 *   DWCi_HLlLoadSet                  0x021BD6D4  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_Flag                        0x021C0EF0  arm
 *   DWCi_FOCUSlDisp4                 0x021BD4C8  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   gSceneSetSelectWayFocus                       0x021DE614  data
 *   gSceneSetSelectWayCommentIds                       0x021DA7D8  data
 *   gSceneSetSelectWayFocusRects                       0x021DA858  data
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   DWCi_Char   0x021BD170  arm  ov016
 *   DWCi_ARClReadEx   0x021D4B68  arm  ov016
 *   gSceneSetSelectWayScreenName   0x021DA800  data
 *   gSceneSetSelectWayPathChar   0x021DB778  data
 *   GX_LoadBG2Char   0x0207F0B8  data
 *   gSceneSetSelectWayPathPltt   0x021DB790  data
 *   GX_LoadBGPltt   0x0207E3D0  data
 *   gSceneSetSelectWayPathScr   0x021DB7A8  data
 *   GX_LoadBG2Scr   0x0207EB78  data
 *   dat_021DE614   0x021DE614  data
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
 *   dispPushButton                   0x021C1EDC  arm
 *   moveFocus                        0x021CD018  arm   ov016
 *   scenemenu_bss                    0x021DE59C  data
 *   scenemenu_init_20658             0x021DA474  data
 *   scenemenu_rodata                 0x021DA478  data
 *   gSceneSetSelectWayButtonRects                       0x021DA818  data
 *   DWCi_BTNlEnd  0x021BCAE4  arm  ov016
 *   endScene2  0x021CCEE4  arm  ov016
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_ARClRelease                 0x021D4C68  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_SetParam2_                  0x021C0E8C  arm
 *   DWCi_SetListReturn               0x021CA5C0  arm
 *   DWCi_SceneSetSelectAp            0x021CBC90  arm
 *   DWCi_SceneSetSearch              0x021CB780  arm
 *   DWCi_SceneSetAossButton          0x021C4904  arm
 *   DWCi_SceneSetRakuReady           0x021CB2E8  arm
 *   DWCi_SceneSetList                0x021C82FC  arm
 *   gSceneSetSelectWayFocusMoveTable     0x021DA7DF  data
 *   g_021DA85A     0x021DA85A  data
 *   g_021DA85C     0x021DA85C  data
 *   g_021DA85E     0x021DA85E  data
 *   gSceneSetSelectWayPushPalette     0x021DA7D4  data
 */
#include "../../matched/include/G_FocusState.h"
#include "../sdk_ioreg.h"
#include "../arm9/gx_load2d.h"
#include "../../matched/include/G_SCENEMENU_BSS.h"

typedef _Bool bool;

#include "../types.h"

typedef struct Rect {
    unsigned short left, top, right, bottom;
} Rect;

struct tagSETTINGINFO {
    u8 pad[0xf4];
    u8 page;
};

typedef struct {
    char name[0x14];
    u8 pad14;
    u8 pad15;
} T22;

/* scenemenu.o .bss at 0x021DE59C, members at their vendor offsets */
typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    void          *Palette;           /* 0x04 */
} SCENEMENU_BSS;

/* scenemenu.o .rodata at 0x021DA478, members at their vendor offsets */
typedef struct {
    Rect           R_TOUCH[2];        /* 0x00 */
    Rect           R_FOCUS[2];        /* 0x10 */
} SCENEMENU_RODATA;

/* PALETTE's initialiser is the compiler's @20658 in its own .rodata section */
typedef struct { unsigned char v[2]; } PALETTE_INIT;

typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;

typedef struct { unsigned char b[4]; } Palette4;

#include "setting.h"
#include "dwcutil_main.h"
#include "headline.h"
#include "comment.h"
#include "common.h"
#include "focus.h"
#include "archive.h"
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
#include "graphics.h"
#include "button.h"
#include "sound.h"
#include "input.h"
#include "screen.h"
#include "sceneend.h"
#include "scenesetlist.h"
#include "scenesetselectap.h"
#include "scenesetsearch.h"
#include "scenesetaossbutton.h"
#include "scenesetrakuready.h"
void DWCi_SceneSetSelectWay(void);
void DWCi_SceneSetSelectWay_procScene(void);
void DWCi_SceneSetSelectWay_draw(void);
extern struct FocusState gSceneSetSelectWayFocus;
extern s8 gSceneSetSelectWayCommentIds[7];
extern Rect gSceneSetSelectWayFocusRects[4][4];
extern T22 gSceneSetSelectWayScreenName;
extern unsigned char gSceneSetSelectWayPathChar[];
extern unsigned char gSceneSetSelectWayPathPltt[];
extern unsigned char gSceneSetSelectWayPathScr[];
extern struct SCENEMENU_BSS scenemenu_bss;
extern const SCENEMENU_RODATA scenemenu_rodata;
extern const PALETTE_INIT scenemenu_init_20658;
extern Rect gSceneSetSelectWayButtonRects[4][4];
extern signed char gSceneSetSelectWayFocusMoveTable[2][4][4];
extern Palette4 gSceneSetSelectWayPushPalette;

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
static void DWCi_SceneSetSelectWayDispPush(void);

void DWCi_SceneSetSelectWay(void)
{
    struct tagSETTINGINFO *info;

    info = (struct tagSETTINGINFO *)DWCi_SETTIGNlGet();
    gSceneSetSelectWayFocus.flag = 0;
    if (gSceneSetSelectWayFocus.last == 0)
        gSceneSetSelectWayFocus.last = 1;
    if (DWCi_Language() != 0) {
        if (gSceneSetSelectWayFocus.cur == 2)
            gSceneSetSelectWayFocus.cur = 0;
        if (gSceneSetSelectWayFocus.last == 2)
            gSceneSetSelectWayFocus.last = 1;
    }
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x32, gSceneSetSelectWayCommentIds[DWCi_Language()], info->page + 1);
    DWCi_CMNlStep(1);
    DWCi_FOCUSlDisp4(gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].left,
                     gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].right,
                     gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].top,
                     gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].bottom);
    DWCi_ChangeScene((uptr)procInit);
}

/*
 * Copy a 0x16-byte NCL resource path from the static table into a stack
 * buffer, load three tilemaps through DWCi_CMNlLoadResource, publish the buffer
 * through DWCi_Char/DWCi_ARClReadEx into the 0x021DE614 record, then set
 * the low two bits of the 0x04001008 and 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/initGraphics.c \
 *       --func initGraphics --addr 0x021CCAC0 --region ov016 --cc dsi/1.1p1 --arm
 */
static void initGraphics(void)
{
    T22 buf;
    u16 *p;

    buf = gSceneSetSelectWayScreenName;
    DWCi_CMNlLoadResource((char *)((sptr)gSceneSetSelectWayPathChar), GX_LoadBG2Char);
    DWCi_CMNlLoadResource((char *)((sptr)gSceneSetSelectWayPathPltt), GX_LoadBGPltt);
    DWCi_CMNlLoadResource((char *)((sptr)gSceneSetSelectWayPathScr), GX_LoadBG2Scr);
    gSceneSetSelectWayFocus.screen = DWCi_ARClReadEx((char *)((sptr)DWCi_Char((unsigned char *)(&buf))), 0, 4);

    p = (u16 *)REG_DB_BG0CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)REG_BG1CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}


static void dispPushButton(void);

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
    DWCi_ChangeScene((uptr)DWCi_SceneSetSelectWay_procScene);
}

void DWCi_SceneSetSelectWay_procScene(void)
{
    input();
    DWCi_SceneSetSelectWay_draw();
    button();
}

static void input(void)
{
    unsigned int i;

    for (i = 0; i < 4; i++) {
        if (DWCi_TPlCheckTrigger((unsigned short *)(&gSceneSetSelectWayButtonRects[DWCi_Flag(1)][i]))) {
            DWCi_BTNlSet(1);
            gSceneSetSelectWayFocus.cur = i;
            DWCi_FOCUSlDisp4(gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].left,
                             gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].right,
                             gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].top,
                             gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].bottom);
            return;
        }
    }
    if (DWCi_IPTlCheckTrigger(1)) {
        DWCi_BTNlSet(1);
        return;
    }
    if (DWCi_IPTlCheckTrigger(2)) {
        DWCi_BTNlSet(0);
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x40)) {
        moveFocus(1);
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x80)) {
        moveFocus(3);
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x20)) {
        moveFocus(0);
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x10))
        moveFocus(2);
}

void DWCi_SceneSetSelectWay_draw(void)
{
}

/*
 * sdk:      button (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE04.c \n *       --func button --addr 0x021CCE04 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void button(void)
{
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        break;
    case 1:
        DWCi_SNDlPlay(6);
        DWCi_SceneSetSelectWayDispPush();
        gSceneSetSelectWayFocus.flag = 1;
        break;
    default:
        return;
    }
    DWCi_ChangeScene((uptr)endScene);
}

/*
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE58.c \n *       --func endScene --addr 0x021CCE58 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((uptr)endScene1);
}

/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE78.c \n *       --func endScene1 --addr 0x021CCE78 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (gSceneSetSelectWayFocus.flag)
        DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 20, 8);
    DWCi_ChangeScene((uptr)endScene2);
}

static void endScene2(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_ARClRelease(gSceneSetSelectWayFocus.screen);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    if (gSceneSetSelectWayFocus.flag == 0) {
        DWCi_SetParam_(2, 0);
        DWCi_ChangeScene((uptr)DWCi_SceneSetSelectAp);
        return;
    }
    switch (gSceneSetSelectWayFocus.cur) {
    case 0:
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneSetSearch);
        break;
    case 1:
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneSetAossButton);
        break;
    case 2:
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneSetRakuReady);
        break;
    case 3:
        DWCi_SetParam_(2, 0);
        DWCi_SetParam2_(0, 0);
        DWCi_SetListReturn(1);
        DWCi_ChangeScene((uptr)DWCi_SceneSetList);
        break;
    }
}

/*
 * sdk:      moveFocus (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_moveFocus.c \n *       --func moveFocus --addr 0x021CD018 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void moveFocus(int dir)
{
    signed char prev = gSceneSetSelectWayFocus.cur;
    signed char next = gSceneSetSelectWayFocusMoveTable[DWCi_Flag(1)][prev][dir];
    if (next == -1)
        return;
    if (next == 0)
        gSceneSetSelectWayFocus.last = prev;
    if (next == -2)
        gSceneSetSelectWayFocus.cur = gSceneSetSelectWayFocus.last;
    else
        gSceneSetSelectWayFocus.cur = next;
    DWCi_SNDlPlay(8);
    DWCi_FOCUSlDisp4(gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].left,
                  gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].right,
                  gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].top,
                  gSceneSetSelectWayFocusRects[DWCi_Flag(1)][gSceneSetSelectWayFocus.cur].bottom);
}

/*
 * sdk:      DWCi_SceneSetSelectWayDispPush (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD108.c \n *       --func DWCi_SceneSetSelectWayDispPush --addr 0x021CD108 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void DWCi_SceneSetSelectWayDispPush(void)
{
    Palette4 palette = gSceneSetSelectWayPushPalette;
    DWCi_SCREENlCopyPalette(gSceneSetSelectWayFocus.screen, palette.b[gSceneSetSelectWayFocus.cur], palette.b[gSceneSetSelectWayFocus.cur]);
}
