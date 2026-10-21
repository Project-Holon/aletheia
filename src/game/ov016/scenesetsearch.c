/*
 * file:     scenesetsearch.c
 * unit:     yes
 * function: DWCi_SceneSetSearch, initGraphics, procInit, procInit1, procInit2, procScene, isEnd, input, DWCi_SceneSetSearch_draw, button, endScene, endScene1, endScene2, procError, procError1
 * address:  0x021CB780
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetsearch.o), symbol DWCi_SceneSetSearch (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SceneSetSearch.c \
 *       --func DWCi_SceneSetSearch --addr 0x021CB780 --region ov016 --cc 1.1p1 --arm --lang c99
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *   python tools/match.py one --src src/matched/DWCi_SceneSetSearch_draw.c \
 *       --func DWCi_SceneSetSearch_draw --addr 0x021CBAC4 --region ov016 --cc dsi/1.1p1 --arm
 * sdk:      button (sceneoptmovwait.o), TwlDWC libdwcutil.TWL.HYB.a
 * sdk:      endScene (scenesetrakubutt.o), TwlDWC libdwcutil.TWL.HYB.a
 * sdk:      endScene1 (sceneoptinfo.o), TwlDWC libdwcutil.TWL.HYB.a
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneopterase.o), symbol procError1 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneopterase.o; its bytes equal sceneopterase.o's own
 * function and only the pool words differ (the copy's own next scene step and, for endScene1,
 * its own one-byte flag, declared here under the sceneopterase_bss name at the copy's address).
 * The object that owns this copy is not identified; the C is the same either way.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CBC70.c \
 *       --func procError1 --addr 0x021CBC70 --region ov016 --cc 1.1p1 --arm --lang c99
 *
 * symbols:
 *   initGraphics                     0x021cb7ec arm
 *   DWCi_COMMENTlDispEx              0x021bd060 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_CMNlStep                    0x021bd214 arm
 *   DWCi_CMNlMsgDraw                 0x021bd29c arm
 *   DWCi_ANIMElInitEx                0x021bc820 arm
 *   DWCi_SEARCHlInit                 0x021cef20 arm
 *   DWCi_SEARCHlBegin                0x021cef84 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   scenesetsearch_bss               0x021de608 data
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   sSceneSetSearchPathJbBgStep3Char    0x021DB6C4  data
 *   sSceneSetSearchPathYbBgStep3Pltt    0x021DB6DC  data
 *   sSceneSetSearchPathXb4MultiScr    0x021DB6F4  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021bcb14 arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   procScene                        0x021cb960 arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_SEARCHlGetApInfo            0x021CF114  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   gSceneSetSearchWork                       0x021DE608  data
 *   DWCi_IPTlCheckTrigger            0x021d6824 arm
 *   DWCi_BTNlSet                     0x021bcb28 arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_BTNlIsEnd                   0x021bcb58 arm
 *   DWCi_SEARCHlStop                 0x021cf080 arm
 *   DWCi_ANIMElEnd                   0x021bc8ec arm
 *   DWCi_FNTlDeleteBgLcd             0x021d5ca8 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_SEARCHlEnd                  0x021cef50 arm
 *   DWCi_SETTIGNlGet                 0x021cf404 arm
 *   DWCi_SETTINGlSetSetting          0x021cf80c arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_SetParam2_                  0x021c0e8c arm
 *   sScenesetsearchChoose                           0x021de608 data
 *   DWCi_SceneSetSelectWay           0x021cc998 arm
 *   DWCi_SceneSetApList              0x021c50d4 arm
 *   DWCi_WINlGet                     0x021d1568 arm
 *   DWCi_WINlEnd                     0x021d1524 arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   procConfirm                      0x021C22AC  arm
 *   sceneopterase_bss                0x021DE5A4  data
 */
struct SearchBss {
    unsigned char Choose;
    unsigned char pad;
    unsigned short Count;
};
#include "../sdk_ioreg.h"
#include "../arm9/gx_load2d.h"

typedef _Bool bool;

/* scenesetsearch.o .bss at 0x021DE608 */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
} SCENESETSEARCH_BSS;

#include "../types.h"

#include "dwcutil_types.h"

typedef struct tagSETTINGINFO {
    unsigned char pad[0xF4];
    unsigned char setting;            /* 0xF4 */
} SETTINGINFO;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

#include "headline.h"
#include "comment.h"
#include "common.h"
#include "anime.h"
#include "search.h"
#include "sound.h"
#include "dwcutil_main.h"
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "graphics.h"
extern bool DWCi_EFFlCheck(int lcd);
#include "button.h"
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
#include "input.h"
extern bool DWCi_EFFlWait(int frame);
typedef int bool_0;
#include "font.h"
#include "setting.h"
#include "window.h"
void DWCi_SceneSetSearch(void);
void DWCi_SceneSetSearch_draw(void);
extern SCENESETSEARCH_BSS scenesetsearch_bss;
extern unsigned short sSceneSetSearchPathJbBgStep3Char[];
extern unsigned short sSceneSetSearchPathYbBgStep3Pltt[];
extern unsigned short sSceneSetSearchPathXb4MultiScr[];
extern struct SearchBss gSceneSetSearchWork;
extern unsigned char sScenesetsearchChoose;
extern int DWCi_SceneSetSelectWay;
extern int DWCi_SceneSetApList;
extern SCENEOPTERASE_BSS sceneopterase_bss;

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void procScene(void);
static void isEnd(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void procError(void);
static void procError1(void);

void DWCi_SceneSetSearch(void)
{
    scenesetsearch_bss.Count = 0;
    scenesetsearch_bss.Choose = 0;
    initGraphics();
    DWCi_COMMENTlDispEx(0x33, -1, 0);
    DWCi_HLlLoadSet();
    DWCi_CMNlStep(2);
    DWCi_CMNlMsgDraw(0x33);
    DWCi_ANIMElInitEx(0);
    DWCi_SEARCHlInit();
    DWCi_SEARCHlBegin();
    DWCi_SNDlPlay(0xa);
    DWCi_ChangeScene((uptr)procInit);
}

/*
 * Load three tilemaps through DWCi_CMNlLoadResource, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */
static void initGraphics(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetSearchPathJbBgStep3Char), GX_LoadBG2Char);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetSearchPathYbBgStep3Pltt), GX_LoadBGPltt);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetSearchPathXb4MultiScr), GX_LoadBG2Scr);

    p = (u16 *)REG_DB_BG0CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)REG_BG0CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)REG_BG1CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}

static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene((uptr)procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(1);
    DWCi_ChangeScene((uptr)procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene((uptr)procScene);
}

/*
 * Call input, DWCi_SceneSetSearch_draw, button, isEnd.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/procScene.c \
 *       --func procScene --addr 0x021CB960 --region ov016 --cc dsi/1.1p1 --arm
 */
static void procScene(void)
{
    input();
    DWCi_SceneSetSearch_draw();
    button();
    isEnd();
}

static void isEnd(void)
{
    APINFO *info;
    int num;
    int i;

    gSceneSetSearchWork.Count++;
    if (gSceneSetSearchWork.Count < 300)
        return;
    DWCi_SNDlStop();
    num = DWCi_SEARCHlGetApInfo(&info);
    if (num == 0) {
        gSceneSetSearchWork.Choose = 2;
        DWCi_WINlInitEx(15, 1, 1, -1, 0);
        DWCi_SNDlPlay(18);
        DWCi_BTNlDisable();
        DWCi_ChangeScene((uptr)procError);
        return;
    }
    for (i = 0; i < num; i++) {
        if (((APINFO *)((u8 *)info + i * 42))->wep != 2)
            break;
    }
    if (i == num) {
        gSceneSetSearchWork.Choose = 3;
        DWCi_WINlInitEx(14, 1, 1, -1, 0);
        DWCi_SNDlPlay(18);
        DWCi_BTNlDisable();
        DWCi_ChangeScene((uptr)procError);
        return;
    }
    gSceneSetSearchWork.Choose = 1;
    DWCi_SNDlPlay(15);
    DWCi_ChangeScene((uptr)endScene);
}

static void input(void)
{
    if (!DWCi_IPTlCheckTrigger(2)) {
        return;
    }
    DWCi_SNDlStop();
    DWCi_BTNlSet(0);
}

void DWCi_SceneSetSearch_draw(void)
{
}

static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
    DWCi_ChangeScene((uptr)endScene);
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
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((uptr)endScene2);
}

static void endScene2(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    if (!DWCi_BTNlIsEnd()) {
        return;
    }
    while (!DWCi_SEARCHlStop()) {
    }
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    if (sScenesetsearchChoose != 1) {
        DWCi_SEARCHlEnd();
        DWCi_SETTINGlSetSetting(((SETTINGINFO *)DWCi_SETTIGNlGet())->setting);
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((uptr)((void (*)())&DWCi_SceneSetSelectWay));
    } else {
        DWCi_SetParam_(0, 1);
        DWCi_SetParam2_(0, 0);
        DWCi_ChangeScene((uptr)((void (*)())&DWCi_SceneSetApList));
    }
}

static void procError(void)
{
    if (DWCi_WINlGet() != 0) {
        return;
    }
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene((uptr)procError1);
}

static void procConfirm(void);

static void procError1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_ChangeScene((uptr)endScene);
}
