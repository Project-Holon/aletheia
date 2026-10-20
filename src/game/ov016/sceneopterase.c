/*
 * file:     sceneopterase.c
 * unit:     yes
 * function: DWCi_SceneOptErase, initGraphics, procInit, procInit1, procInit2, DWCi_SceneOptErase_procScene, input, DWCi_SceneOptErase_draw, button, endScene, endScene1, endScene2, procConfirm, procConfirm1
 * address:  0x021C1F1C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call input, DWCi_SceneOptErase_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptErase_procScene.c \
 *       --func DWCi_SceneOptErase_procScene --addr 0x021C20AC --region ov016 --cc dsi/1.1p1 --arm
 * Two guarded DWCi_BTNlSet calls keyed off DWCi_IPTlCheckTrigger.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021C20C0 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptErase_draw.c \
 *       --func DWCi_SceneOptErase_draw --addr 0x021C20FC --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_SceneOptMovConfirm1EndScene2 0x021C3AD0  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   endScene2                        0x021C21F0  arm
 *   initGraphics                     0x021C1F64  arm
 *   sceneopterase_bss                0x021DE5A4  data
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_BTNlIsEnd  0x021BCB58  arm
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm
 *   DWCi_COMMENTlDelete  0x021BD138  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   gSceneOptEraseWork     0x021DE5A4  data
 *   DWCi_SceneOptMenu  0x021C2A3C  arm
 *   DWCi_SceneOptErase1  0x021C231C  arm
 *   DWCi_SceneOptErase  0x021C1F1C  arm
 *   DWCi_SceneOptErase_procScene  0x021C20AC  arm
 *   input  0x021C20C0  arm
 *   DWCi_SceneOptErase_draw  0x021C20FC  arm
 *   button  0x021C2100  arm
 */
#include "../../matched/include/G_SCENEOPTERASE_BSS.h"

typedef _Bool bool;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

#include "../types.h"

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(u32 v);
extern void DWCi_CMNlButton(int kind);
extern void DWCi_CMNlMsgDraw(int msgId);
extern s32 DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_HLlLoad(int idx);
extern s8 DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlEnd(void);
extern void DWCi_SNDlPlay(u32 v);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern s8 DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern s32 DWCi_WINlIsInit(void);
void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void DWCi_BTNlSet(signed char v);
extern int  DWCi_BTNlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int x);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int a, int b);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SceneOptErase1(void);
void DWCi_SceneOptErase(void);
void DWCi_SceneOptErase_procScene(void);
void DWCi_SceneOptErase_draw(void);
extern SCENEOPTERASE_BSS sceneopterase_bss;
extern struct SCENEOPTERASE_BSS gSceneOptEraseWork;


static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void procConfirm(void);
static void procConfirm1(void);

void DWCi_SceneOptErase(void)
{
    sceneopterase_bss.Choose = 0;
    initGraphics();
    DWCi_HLlLoad(0x12);
    DWCi_COMMENTlDispEx(0x3b, -1, 0);
    DWCi_CMNlMsgDraw(0x17);
    DWCi_ChangeScene((u32)procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB2B4, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}

static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene((u32)procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(3);
    DWCi_ChangeScene((u32)procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene((u32)DWCi_SceneOptErase_procScene);
}

void DWCi_SceneOptErase_procScene(void)
{
    input();
    DWCi_SceneOptErase_draw();
    button();
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(1);
    if (DWCi_IPTlCheckTrigger(2))
        DWCi_BTNlSet(0);
}

void DWCi_SceneOptErase_draw(void)
{
}

static void button(void)
{
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        DWCi_ChangeScene((u32)endScene);
        break;
    case 1:
        DWCi_SNDlPlay(6);
        DWCi_WINlInitEx(0x18, 0, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene((u32)procConfirm);
        break;
    }
}

static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((u32)endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    if (sceneopterase_bss.Choose == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((u32)endScene2);
}

/*
 * Same shape as DWCi_Sceneoptmovconfirm1EndScene2 with a different flag byte and last stage.
 */
static void endScene2(void)
{
    if (DWCi_EFFlCheck(0) != 0)
        return;
    if (((u8 *)&gSceneOptEraseWork)[0] == 0) {
        if (DWCi_EFFlCheck(1) != 0)
            return;
    }
    if (DWCi_BTNlIsEnd() == 0)
        return;
    DWCi_FNTlDeleteBgLcd(0);
    if (((u8 *)&gSceneOptEraseWork)[0] == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (((u8 *)&gSceneOptEraseWork)[0] == 0) {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((u32)DWCi_SceneOptMenu);
    } else {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((u32)DWCi_SceneOptErase1);
    }
}

static void procConfirm(void)
{
    switch (DWCi_WINlGet()) {
    case 1:
        DWCi_SNDlPlay(0xe);
        sceneopterase_bss.Choose = 1;
        break;
    case 0:
        DWCi_SNDlPlay(7);
        break;
    default:
        return;
    }
    DWCi_WINlEnd();
    DWCi_ChangeScene((u32)procConfirm1);
}

static void procConfirm1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_ChangeScene((u32)endScene);
}
