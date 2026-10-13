/*
 * file:     sceneopterase.c
 * unit:     yes
 * function: func_021C1F1C, func_021C1F64, func_021C1FE4, func_021C204C, func_021C2088, DWCi_SceneOptErase_procScene, func_021C20C0, DWCi_SceneOptErase_draw, func_021C2100, func_021C2168, func_021C2188, func_021C21F0, func_021C22AC, func_021C22FC
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
 * Call func_021C20C0, DWCi_SceneOptErase_draw, func_021C2100.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptErase_procScene.c \
 *       --func DWCi_SceneOptErase_procScene --addr 0x021C20AC --region ov016 --cc dsi/1.1p1 --arm
 * Two guarded func_021BCB28 calls keyed off func_021D6824.
 *   python tools/match.py one --src src/matched/func_021C20C0.c \
 *       --func func_021C20C0 --addr 0x021C20C0 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptErase_draw.c \
 *       --func DWCi_SceneOptErase_draw --addr 0x021C20FC --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
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
 *   procScene                        0x021C20AC  arm
 *   sceneopterase_bss                0x021DE5A4  data
 *   func_021BD1D4  0x021BD1D4  arm
 *   func_021D5580  0x021D5580  arm
 *   func_021BCB58  0x021BCB58  arm
 *   func_021D5CA8  0x021D5CA8  arm
 *   func_021BD138  0x021BD138  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C0E50  0x021C0E50  arm
 *   func_021C0E40  0x021C0E40  arm
 *   g_021DE5A4     0x021DE5A4  data
 *   func_021C2A3C  0x021C2A3C  arm
 *   func_021C231C  0x021C231C  arm
 */
#include "../../matched/include/G_SCENEOPTERASE_BSS.h"

typedef _Bool bool;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef unsigned char u8;

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_CMNlButton(int kind);
extern void DWCi_CMNlMsgDraw(int msgId);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_HLlLoad(int idx);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlEnd(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void func_021C2100(void);
extern int func_021D6824(unsigned int f);
extern void func_021BCB28(signed char v);
extern int  func_021D5580(int x);
extern int  func_021BCB58(void);
extern void func_021D5CA8(int x);
extern void func_021BD138(void);
extern void func_021D6090(int a, int b);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021C2A3C(void);
extern void func_021C231C(void);
void DWCi_SceneOptErase(void);
void func_021C1F64(void);
void DWCi_SceneOptErase_procScene(void);
void func_021C20C0(void);
void DWCi_SceneOptErase_draw(void);
void func_021C21F0(void);
extern SCENEOPTERASE_BSS sceneopterase_bss;
extern struct SCENEOPTERASE_BSS g_021DE5A4;



static void initGraphics(void);


static void procInit(void);


static void procInit1(void);


static void procInit2(void);


static void procScene(void);


static void procConfirm(void);


static void procConfirm1(void);


static void endScene(void);


static void endScene1(void);


static void endScene2(void);



void DWCi_SceneOptErase(void)
{
    sceneopterase_bss.Choose = 0;
    initGraphics();
    DWCi_HLlLoad(0x12);
    DWCi_COMMENTlDispEx(0x3b, -1, 0);
    DWCi_CMNlMsgDraw(0x17);
    DWCi_ChangeScene(procInit);
}



void func_021C1F64(void)
{
    func_021BD1D4((void *)0x021DB2B4, (void *)0x0207EB78);
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
    DWCi_ChangeScene(procInit1);
}



static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(3);
    DWCi_ChangeScene(procInit2);
}



static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


void DWCi_SceneOptErase_procScene(void)
{
    func_021C20C0();
    DWCi_SceneOptErase_draw();
    func_021C2100();
}


void func_021C20C0(void)
{
    if (func_021D6824(1))
        func_021BCB28(1);
    if (func_021D6824(2))
        func_021BCB28(0);
}

void DWCi_SceneOptErase_draw(void)
{
}



static void button(void)
{
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        DWCi_ChangeScene(endScene);
        break;
    case 1:
        DWCi_SNDlPlay(6);
        DWCi_WINlInitEx(0x18, 0, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procConfirm);
        break;
    }
}



static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}



static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    if (sceneopterase_bss.Choose == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}



/*
 * Same shape as func_021C3AD0 with a different flag byte and last stage.
 */
void func_021C21F0(void)
{
    if (func_021D5580(0) != 0)
        return;
    if (((u8 *)&g_021DE5A4)[0] == 0) {
        if (func_021D5580(1) != 0)
            return;
    }
    if (func_021BCB58() == 0)
        return;
    func_021D5CA8(0);
    if (((u8 *)&g_021DE5A4)[0] == 0) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021D6090(0, 0x15);
    if (((u8 *)&g_021DE5A4)[0] == 0) {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C2A3C);
    } else {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C231C);
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
    DWCi_ChangeScene(procConfirm1);
}



static void procConfirm1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_ChangeScene(endScene);
}
