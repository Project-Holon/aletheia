/*
 * file:     scenesetaossbutton.c
 * unit:     yes
 * function: DWCi_IsFold, DWCi_SceneSetAossButton, initGraphics, procInit, procInit1, procInit2, procScene, input, DWCi_SceneSetAossButton_draw, button, endScene, endScene1, endScene2, taskVBlank, procError, procError1, procWait, procCancel
 * address:  0x021C48E4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Two-stage guard around DWCi_BTNlSet.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021C4BDC --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneSetAossButton_draw.c \
 *       --func DWCi_SceneSetAossButton_draw --addr 0x021C4C14 --region ov016 --cc dsi/1.1p1 --arm
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneopterase.o), symbol endScene1 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneopterase.o; its bytes equal sceneopterase.o's own
 * function and only the pool words differ (the copy's own next scene step and, for endScene1,
 * its own one-byte flag, declared here under the sceneopterase_bss name at the copy's address).
 * The object that owns this copy is not identified; the C is the same either way.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C4C9C.c \
 *       --func endScene1 --addr 0x021C4C9C --region ov016 --cc 1.1p1 --arm --lang c99
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   DWCi_TSKlAct                   0x021D75D0  arm  ov016
 *   sScenesetaossbuttonChoose                           0x021DE5CC  data
 *   initGraphics                     0x021C4964  arm
 *   DWCi_HLlLoadSet                  0x021BD6D4  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ANIMElInitEx                0x021BC820  arm
 *   DWCi_AOSSlInit                   0x021C07A8  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   sSceneSetAossButtonPathJbBgStep3Char    0x021DB3E0  data
 *   sSceneSetAossButtonPathYbBgStep3Pltt    0x021DB3F8  data
 *   sSceneSetAossButtonPathXb4MultiScr    0x021DB410  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   taskVBlank                       0x021C4DE4  arm
 *   procScene                        0x021C4AF8  arm
 *   button  0x021C4C18  arm  ov016
 *   DWCi_AOSSlStart  0x021C0900  arm  ov016
 *   DWCi_TSKlDeleteEx  0x021D7744  arm  ov016
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   DWCi_WINlInitEx  0x021D1208  arm  ov016
 *   DWCi_BTNlDisable  0x021BCB9C  arm  ov016
 *   gSceneSetAossButtonWork     0x021DE5CC  data
 *   procWait  0x021C4E4C  arm  ov016
 *   procError  0x021C4E00  arm  ov016
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   procCancel                       0x021C4E98  arm
 *   DWCi_TSKlDeleteEx                0x021D7744  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   endScene2                        0x021C4D04  arm
 *   procConfirm                      0x021C22AC  arm
 *   procConfirm1                     0x021C22FC  arm
 *   sceneopterase_bss                0x021DE5CC  data
 *   DWCi_BTNlIsEnd  0x021BCB58  arm  ov016
 *   DWCi_AOSSlEnd  0x021C08B0  arm  ov016
 *   DWCi_ANIMElEnd  0x021BC8EC  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_SceneSetSelectWay  0x021CC998  arm  ov016
 *   DWCi_SceneSetAossComplete  0x021C4EC8  arm  ov016
 *   input                            0x021C4BDC  arm
 *   DWCi_IPTlUpdate  0x021D656C  arm
 */
struct SCENESETAOSSBUTT_BSS {
    unsigned char Choose;
    unsigned char pad_1[0x1];
    unsigned short Count;
    void *Task;
};
#include "../sdk_ioreg.h"
#include "../arm9/gx_load2d.h"

typedef _Bool bool;

/* scenesetaossbutt.o .bss at 0x021DE5CC, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
    void          *Task;              /* 0x04 */
} SCENESETAOSSBUTT_BSS;

#include "../types.h"

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

#include "headline.h"
#include "comment.h"
#include "common.h"
#include "anime.h"
#include "libaoss.h"
#include "sound.h"
#include "dwcutil_main.h"
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "graphics.h"
extern bool DWCi_EFFlCheck(int lcd);
#include "button.h"
struct TCB;
#include "task.h"
#include "input.h"
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
#include "window.h"
#include "font.h"
#include "scenesetselectway.h"
#include "scenesetaosscomplete.h"
void DWCi_SceneSetAossButton(void);
void DWCi_SceneSetAossButton_draw(void);
extern SCENESETAOSSBUTT_BSS sScenesetaossbuttonChoose;
extern unsigned short sSceneSetAossButtonPathJbBgStep3Char[];
extern unsigned short sSceneSetAossButtonPathYbBgStep3Pltt[];
extern unsigned short sSceneSetAossButtonPathXb4MultiScr[];
extern SCENEOPTERASE_BSS sceneopterase_bss;
extern struct SCENESETAOSSBUTT_BSS gSceneSetAossButtonWork;

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void procScene(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void taskVBlank(void);
static void procError(void);
static void procError1(void);
static void procWait(void);
static void procCancel(void);

/*
 * Bit 15 of the halfword at 0x02FFFFA8 (lid closed), as 0/1: this scene's own
 * copy of the libdwcutil helper.
 */
static int DWCi_IsFold(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}

void DWCi_SceneSetAossButton(void)
{
    sScenesetaossbuttonChoose.Count = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x36, -1, 0);
    DWCi_CMNlStep(2);
    DWCi_CMNlMsgDraw(0x22);
    DWCi_ANIMElInitEx(0);
    DWCi_AOSSlInit();
    DWCi_SNDlPlay(0xb);
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

    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetAossButtonPathJbBgStep3Char), GX_LoadBG2Char);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetAossButtonPathYbBgStep3Pltt), GX_LoadBGPltt);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetAossButtonPathXb4MultiScr), GX_LoadBG2Scr);

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
    if (DWCi_BTNlGet() == -2)
        return;
    sScenesetaossbuttonChoose.Task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskVBlank, 0, 0x78);
    DWCi_ChangeScene((uptr)procScene);
}

static void procScene(void)
{
    input();
    DWCi_SceneSetAossButton_draw();
    button();
    switch (DWCi_AOSSlStart()) {
    case 0:
        return;
    case 1:
        if (sScenesetaossbuttonChoose.Task == 0)
            return;
        sScenesetaossbuttonChoose.Choose = 1;
        DWCi_TSKlDeleteEx(1, sScenesetaossbuttonChoose.Task);
        sScenesetaossbuttonChoose.Task = 0;
        DWCi_ChangeScene((uptr)procWait);
        return;
    case 2:
        if (sScenesetaossbuttonChoose.Task == 0)
            return;
        DWCi_SNDlStop();
        DWCi_WINlInitEx(0xC, 1, 1, -1, 0);
        DWCi_SNDlPlay(9);
        DWCi_BTNlDisable();
        DWCi_TSKlDeleteEx(1, sScenesetaossbuttonChoose.Task);
        sScenesetaossbuttonChoose.Task = 0;
        DWCi_ChangeScene((uptr)procError);
        return;
    }
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(2))
    {
        DWCi_BTNlSet(0);
        return;
    }
    if (DWCi_IsFold())
        DWCi_BTNlSet(0);
}

void DWCi_SceneSetAossButton_draw(void)
{
}

static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    if (sScenesetaossbuttonChoose.Task == 0)
        return;
    DWCi_TSKlDelete(1, sScenesetaossbuttonChoose.Task);
    sScenesetaossbuttonChoose.Task = 0;
    DWCi_BTNlDisable();
    DWCi_ChangeScene((uptr)procCancel);
}

static void endScene(void)
{
    DWCi_BTNlDisable();
    if (sScenesetaossbuttonChoose.Task != 0)
        DWCi_TSKlDeleteEx(1, sScenesetaossbuttonChoose.Task);
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((uptr)endScene1);
}

static void procConfirm(void);

static void procConfirm1(void);

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    if (sceneopterase_bss.Choose == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((uptr)endScene2);
}

/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a scenesetaossbutton.o)
 */
static void endScene2(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if ((*(unsigned char *)&gSceneSetAossButtonWork) == 0) {
        if (DWCi_EFFlCheck(1))
            return;
    }
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_AOSSlEnd((*(unsigned char *)&gSceneSetAossButtonWork) != 0);
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if ((*(unsigned char *)&gSceneSetAossButtonWork) == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if ((*(unsigned char *)&gSceneSetAossButtonWork) == 0) {
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneSetSelectWay);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene((uptr)DWCi_SceneSetAossComplete);
    }
}

static void taskVBlank(void)
{
    DWCi_IPTlUpdate();
    DWCi_TSKlAct(0);
    input();
    button();
}

static void procError(void)
{
    if (DWCi_WINlGet())
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene((uptr)procError1);
}

static void procError1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_ChangeScene((uptr)endScene);
}


static void procWait(void)
{
    input();
    DWCi_SceneSetAossButton_draw();
    button();
    sScenesetaossbuttonChoose.Count = sScenesetaossbuttonChoose.Count + 1;
    if (sScenesetaossbuttonChoose.Count < 1080)
        return;
    DWCi_SNDlStop();
    DWCi_ChangeScene((uptr)endScene);
}

/*
 * Tear down the sequence and post the event at 0x021C4C60.
 * Addresses are Black-image addresses.
 */
static void procCancel(void)
{
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
    *(unsigned char *)0x021DE5CC = 0;
    DWCi_ChangeScene((uptr)endScene);
}
