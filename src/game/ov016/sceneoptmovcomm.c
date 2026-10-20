/*
 * file:     sceneoptmovcomm.c
 * unit:     yes
 * function: DWCi_SceneOptMovComm, initGraphics, procInit, procInit1, DWCi_SceneOptMovComm_procScene, DWCi_SceneOptMovComm_input, DWCi_SceneOptMovComm_draw, endScene, endScene1, DWCi_SceneOptMovCommCbMov
 * address:  0x021C315C
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
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_ANIMElInitEx  0x021BC820  arm  ov016
 *   DWCi_ICONlInit  0x021BD744  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_GXlVisible  0x021D603C  arm  ov016
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_MOVlChangeCallback  0x021C11D4  arm  ov016
 *   DWCi_MOVlIsEnd  0x021C11B8  arm
 *   DWCi_ICONlEnd  0x021BD7F4  arm
 *   DWCi_ANIMElEnd  0x021BC8EC  arm
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   gSceneOptMovCommWork     0x021DE5B4  data
 *   DWCi_SceneOptMovFailure  0x021C3D8C  arm
 *   DWCi_SceneOptMovDisconnect  0x021C3B8C  arm
 *   DWCi_SceneOptMovComplete  0x021C33CC  arm
 *   DWCi_SETTINGlEraseAll  0x021CFC20  arm  ov016
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   DWCi_MOVlEnd  0x021C115C  arm  ov016
 */
#include "../types.h"
#include "../sdk_ioreg.h"
typedef _Bool bool;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

#include "common.h"
#include "anime.h"
#include "icon.h"
#include "sound.h"
#include "dwcutil_main.h"
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "graphics.h"
extern bool DWCi_EFFlCheck(int lcd);
#include "move.h"
typedef int bool_0;
#include "font.h"
#include "sceneoptmovfailure.h"
#include "sceneoptmovdisconnect.h"
#include "sceneoptmovcomplete.h"
#include "setting.h"
void DWCi_SceneOptMovComm(void);
void DWCi_SceneOptMovComm_procScene(void);
void DWCi_SceneOptMovComm_input(void);
void DWCi_SceneOptMovComm_draw(void);
extern u8   gSceneOptMovCommWork;

/*
 * sdk:      DWCi_SceneOptMovComm (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 */

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void endScene(void);
static void endScene1(void);
static void DWCi_SceneOptMovCommCbMov(int state);
void DWCi_SceneOptMovComm(void)
{
	initGraphics();
	DWCi_CMNlMsgDraw(0x1e);
	DWCi_ANIMElInitEx(0);
	DWCi_ICONlInit(1);
	DWCi_SNDlPlay(0xb);
	DWCi_ChangeScene((uptr)procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB368, (void *)0x0207EB78);
    ((BgCnt *)REG_DB_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_DB_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG2CNT_ADDR)->priority = 3;
}

/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 */
static void procInit(void)
{
	DWCi_EFFlFade(2, 0, 0x15, 8);
	DWCi_GXlVisible(0, 0x15);
	DWCi_ChangeScene((uptr)procInit1);
}

static void procInit1(void)
{
	if (DWCi_EFFlCheck(0))
		return;
	DWCi_MOVlChangeCallback((uptr)DWCi_SceneOptMovCommCbMov);
	DWCi_ChangeScene((uptr)DWCi_SceneOptMovComm_procScene);
}

void DWCi_SceneOptMovComm_procScene(void)
{
    DWCi_SceneOptMovComm_input();
    DWCi_SceneOptMovComm_draw();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovComm_input.c \
 *       --func DWCi_SceneOptMovComm_input --addr 0x021C3290 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovComm_input(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovComm_draw.c \
 *       --func DWCi_SceneOptMovComm_draw --addr 0x021C3294 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovComm_draw(void)
{
}

/*
 * sdk:      endScene (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 */
static void endScene(void)
{
	DWCi_EFFlFade(3, 0, 0x15, 8);
	DWCi_ChangeScene((uptr)endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(0) != 0)
        return;
    if (DWCi_MOVlIsEnd() == 0)
        return;
    DWCi_ICONlEnd();
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 1);
    if (gSceneOptMovCommWork == 0) {
        DWCi_ChangeScene((uptr)DWCi_SceneOptMovFailure);
        return;
    }
    if (gSceneOptMovCommWork == 2) {
        DWCi_ChangeScene((uptr)DWCi_SceneOptMovDisconnect);
        return;
    }
    DWCi_ChangeScene((uptr)DWCi_SceneOptMovComplete);
}

/*
 * sdk:      DWCi_SceneOptMovCommCbMov (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 */
static void DWCi_SceneOptMovCommCbMov(int state)
{
	if (state == 2) {
		DWCi_SETTINGlEraseAll();
		gSceneOptMovCommWork = 1;
		DWCi_SNDlStop();
		DWCi_SNDlPlay(0x10);
	} else if (state == 3) {
		gSceneOptMovCommWork = 2;
		DWCi_SNDlStop();
		DWCi_SNDlPlay(0x12);
	} else {
		gSceneOptMovCommWork = 0;
		DWCi_SNDlStop();
		DWCi_SNDlPlay(0x12);
	}
	DWCi_MOVlChangeCallback(0);
	DWCi_MOVlEnd();
	DWCi_ChangeScene((uptr)endScene);
}
