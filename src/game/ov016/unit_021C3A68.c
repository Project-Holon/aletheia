/*
 * file:     unit_021C3A68.c
 * unit:     yes
 * function: func_021C3A68, func_021C3AD0
 * address:  0x021C3A68
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
 *   endScene                         0x021C2168  arm
 *   endScene2                        0x021C3AD0  arm
 *   initGraphics                     0x021C1F64  arm
 *   procConfirm                      0x021C22AC  arm
 *   procConfirm1                     0x021C22FC  arm
 *   procInit                         0x021C1FE4  arm
 *   procInit1                        0x021C204C  arm
 *   procInit2                        0x021C2088  arm
 *   procScene                        0x021C20AC  arm
 *   sceneopterase_bss                0x021DE5B8  data
 *   func_021D5580  0x021D5580  arm
 *   func_021BCB58  0x021BCB58  arm
 *   func_021D5CA8  0x021D5CA8  arm
 *   func_021BD138  0x021BD138  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C0E50  0x021C0E50  arm
 *   func_021C0E40  0x021C0E40  arm
 *   g_021DE5B8     0x021DE5B8  data
 *   func_021C2A3C  0x021C2A3C  arm
 *   func_021C35F0  0x021C35F0  arm
 */
#include "../../matched/include/G_021DE5B8.h"

typedef _Bool bool;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

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
extern int  func_021D5580(int x);
extern int  func_021BCB58(void);
extern void func_021D5CA8(int x);
extern void func_021BD138(void);
extern void func_021D6090(int a, int b);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021C2A3C(void);
extern void func_021C35F0(void);
void func_021C3AD0(void);
extern SCENEOPTERASE_BSS sceneopterase_bss;
extern struct G_021DE5B8 g_021DE5B8;


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
 * The final func_021C0E50(0, 1) is written in both arms: the original emits
 * it once per arm, not merged before the branch.
 */
void func_021C3AD0(void)
{
    if (func_021D5580(0) != 0)
        return;
    if (((u8 *)&g_021DE5B8)[0] == 0) {
        if (func_021D5580(1) != 0)
            return;
    }
    if (func_021BCB58() == 0)
        return;
    func_021D5CA8(0);
    if (((u8 *)&g_021DE5B8)[0] == 0) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021D6090(0, 0x15);
    if (((u8 *)&g_021DE5B8)[0] == 0) {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C2A3C);
    } else {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C35F0);
    }
}
