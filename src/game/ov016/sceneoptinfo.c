/*
 * file:     sceneoptinfo.c
 * unit:     yes
 * function: DWCi_SceneOptInfo, initGraphics, drawInfo, procInit, procInit1, procInit2, DWCi_SceneOptInfo_procScene, input, DWCi_SceneOptInfo_draw, button, endScene, endScene1, endScene2
 * address:  0x021C255C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call input, DWCi_SceneOptInfo_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptInfo_procScene.c \
 *       --func DWCi_SceneOptInfo_procScene --addr 0x021C28E8 --region ov016 --cc dsi/1.1p1 --arm
 * Guard: if (DWCi_IPTlCheckTrigger(2)) call DWCi_IPTlCheckTrigger.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021C28FC --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptInfo_draw.c \
 *       --func DWCi_SceneOptInfo_draw --addr 0x021C291C --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   initGraphics        0x021C2590  arm
 *   DWCi_HLlLoad        0x021BD674  arm
 *   DWCi_COMMENTlDispEx 0x021BD060  arm
 *   DWCi_ChangeScene    0x021C0E40  arm
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_FNTlFormBgEx                    0x021D5A58  arm
 *   OS_GetMacAddress                     0x02087C6C  arm
 *   OS_SNPrintf                          0x02084F80  arm
 *   DWCi_STRlConvertStringAsciiToUnicode 0x021D722C  arm
 *   DWCi_FNTlDrawRect                    0x021D5E5C  arm
 *   DWCi_BM_GetWiFiInfo                  0x02058518  arm
 *   _ll_udiv                             0x0209C00C  arm
 *   _ull_mod                             0x0209C018  arm
 *   DWCi_FNTlRenewBg                     0x021D5FC4  arm
 *   sSceneOptInfoTable1                           0x021DB2F0  data  a1
 *   sSceneOptInfoTable2                           0x021DB310  data  a1
 *   sSceneOptInfoTable3                           0x021DB324  data  a1
 *   DWCi_EFFlFade     0x021D55A4  arm
 *   DWCi_GXlVisible   0x021D603C  arm
 *   DWCi_EFFlCheck    0x021D5580  arm
 *   DWCi_CMNlButton   0x021BD264  arm
 *   DWCi_BTNlGet     0x021BCB14  arm
 *   DWCi_BTNlEnable  0x021BCB84  arm
 *   DWCi_SNDlPlay    0x021CFFAC  arm
 *   DWCi_BTNlDisable 0x021BCB9C  arm
 *   DWCi_EFFlWait    0x021D5790  arm
 *   DWCi_BTNlEnd     0x021BCAE4  arm
 *   DWCi_BTNlIsEnd      0x021BCB58  arm
 *   DWCi_FNTlDeleteBgLcd 0x021D5CA8  arm
 *   DWCi_COMMENTlDelete 0x021BD138  arm
 *   DWCi_GXlInvisible   0x021D6090  arm
 *   DWCi_SetParam_      0x021C0E50  arm
 *   DWCi_SceneOptMenu   0x021C2A3C  arm
 */
#include "../types.h"
#include "../sdk_ioreg.h"
typedef _Bool bool;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

#include "../sdk_dwc.h"

#include "headline.h"
#include "comment.h"
#include "dwcutil_main.h"
#include "common.h"
#include "font.h"
#include "../arm9/os_ownerinfo.h"
#include "../arm9/os_printf.h"
#include "str.h"
#include "../arm9/dwc_backup.h"
bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "graphics.h"
bool DWCi_EFFlCheck(int lcd);
#include "button.h"
void DWCi_SceneOptInfo_procScene(void);
#include "input.h"
#include "sound.h"
bool DWCi_EFFlWait(int frame);
#include "sceneoptmenu.h"
void DWCi_SceneOptInfo(void);
static void drawInfo(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
void DWCi_SceneOptInfo_procScene(void);
void DWCi_SceneOptInfo_draw(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
extern char sSceneOptInfoTable1[];
extern char sSceneOptInfoTable2[];
extern char sSceneOptInfoTable3[];

static void initGraphics(void);
static void input(void);

void DWCi_SceneOptInfo(void)
{
    initGraphics();
    DWCi_HLlLoad(0x11);
    DWCi_COMMENTlDispEx(0x3a, -1, 0);
    drawInfo();
    DWCi_ChangeScene((uptr)procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB2DC, (void *)0x0207EB78);
    ((BgCnt *)REG_DB_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_DB_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG2CNT_ADDR)->priority = 3;
}

static void drawInfo(void)
{
    DWCWiFiInfo info;
    unsigned long long id;
    int tmp[4];
    int i;
    unsigned short buf[20];
    char tmpbuf[20];
    unsigned char mac[6];
    void *canvas;

    canvas = DWCi_FNTlFormBgEx(0, 0);
    OS_GetMacAddress(mac);
    OS_SNPrintf(tmpbuf, 20, sSceneOptInfoTable1, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    DWCi_STRlConvertStringAsciiToUnicode(buf, (unsigned char *)tmpbuf, 20);
    DWCi_FNTlDrawRect(canvas, 8, 0x40, 0xf0, 0x1c, 2, 0x480, buf);
    DWCi_BM_GetWiFiInfo(&info);
    id = info.attestedUserId;
    if (id != 0) {
        tmp[3] = (int)((id % 10) * 1000);
        id /= 10;
        for (i = 0; i < 3; i++) {
            tmp[2 - i] = (int)(id % 10000);
            id /= 10000;
        }
        OS_SNPrintf(tmpbuf, 20, sSceneOptInfoTable2, tmp[0], tmp[1], tmp[2], tmp[3]);
        DWCi_STRlConvertStringAsciiToUnicode(buf, (unsigned char *)tmpbuf, 20);
    } else {
        OS_SNPrintf(tmpbuf, 20, sSceneOptInfoTable3);
        DWCi_STRlConvertStringAsciiToUnicode(buf, (unsigned char *)tmpbuf, 20);
    }
    DWCi_FNTlDrawRect(canvas, 8, 0x78, 0xf0, 0x1c, 2, 0x480, buf);
    DWCi_FNTlRenewBg((sptr)canvas);
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
    if (DWCi_EFFlCheck(1)) return;
    if (DWCi_EFFlCheck(0)) return;
    DWCi_CMNlButton(2);
    DWCi_ChangeScene((uptr)procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2) return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene((uptr)DWCi_SceneOptInfo_procScene);
}

void DWCi_SceneOptInfo_procScene(void)
{
    input();
    DWCi_SceneOptInfo_draw();
    button();
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(2))
        DWCi_BTNlSet(0);
}

void DWCi_SceneOptInfo_draw(void)
{
}

static void button(void)
{
    if (DWCi_BTNlGet() != 0) return;
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
    if (DWCi_EFFlCheck(1)) return;
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((uptr)endScene2);
}

static void endScene2(void)
{
    if (DWCi_EFFlCheck(1)) return;
    if (DWCi_EFFlCheck(0)) return;
    if (!DWCi_BTNlIsEnd()) return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 1);
    DWCi_ChangeScene((uptr)DWCi_SceneOptMenu);
}
