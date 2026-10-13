/*
 * file:     unit_021C4D04.c
 * unit:     yes
 * function: func_021C4D04, func_021C4DE4, func_021C4E00, func_021C4E2C, func_021C4E4C, func_021C4E98
 * address:  0x021C4D04
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
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021C08B0  0x021C08B0  arm  ov016
 *   func_021BC8EC  0x021BC8EC  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5CC     0x021DE5CC  data
 *   func_021CC998  0x021CC998  arm  ov016
 *   func_021C4EC8  0x021C4EC8  arm  ov016
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   endScene                         0x021C4C60  arm
 *   endScene1                        0x021C2188  arm
 *   endScene2                        0x021C21F0  arm
 *   initGraphics                     0x021C1F64  arm
 *   procConfirm                      0x021C22AC  arm
 *   procInit                         0x021C1FE4  arm
 *   procInit1                        0x021C204C  arm
 *   procInit2                        0x021C2088  arm
 *   procScene                        0x021C20AC  arm
 *   sceneopterase_bss                0x021DE5A4  data
 *   input                            0x021C4BDC  arm
 *   draw                             0x021C4C14  arm
 *   button                           0x021C4C18  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   Choose                           0x021DE5CC  data
 *   DWCi_IPTlUpdate  0x021D656C  arm
 */
#include "../../matched/include/G_SCENESETAOSSBUTT_BSS.h"

typedef _Bool bool;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
    void          *Task;              /* 0x04 */
} SCENESETAOSSBUTT_BSS;

extern int func_021D5580();
extern int func_021BCB58();
extern void func_021C08B0(int a);
extern void func_021BC8EC();
extern void func_021D5CA8(int a);
extern void func_021BD138();
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021CC998();
extern void func_021C4EC8();
extern void DWCi_IPTlUpdate(void);
extern void func_021D75D0(int);
extern void func_021C4BDC(void);
extern void func_021C4C18(void);
extern int  DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_WINlEnd(void);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_CMNlButton(int kind);
extern void DWCi_CMNlMsgDraw(int msgId);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_HLlLoad(int idx);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlEnd(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern bool DWCi_WINlIsInit(void);
extern void DWCi_SNDlStop(void);
extern void func_021D0014(void);
extern void func_021CFFAC(unsigned int v);
void func_021C4D04(void);
void func_021C4DE4(void);
void func_021C4E98(void);
extern struct SCENESETAOSSBUTT_BSS g_021DE5CC;
extern SCENEOPTERASE_BSS sceneopterase_bss;
extern SCENESETAOSSBUTT_BSS Choose;


/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a scenesetaossbutton.o)
 */
void func_021C4D04(void)
{
    if (func_021D5580(0))
        return;
    if ((*(unsigned char *)&g_021DE5CC) == 0) {
        if (func_021D5580(1))
            return;
    }
    if (!func_021BCB58())
        return;
    func_021C08B0((*(unsigned char *)&g_021DE5CC) != 0);
    func_021BC8EC();
    func_021D5CA8(0);
    if ((*(unsigned char *)&g_021DE5CC) == 0) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021D6090(0, 0x15);
    if ((*(unsigned char *)&g_021DE5CC) == 0) {
        func_021C0E50(2, 1);
        func_021C0E40((unsigned int)func_021CC998);
    } else {
        func_021C0E50(0, 0);
        func_021C0E40((unsigned int)func_021C4EC8);
    }
}


void func_021C4DE4(void)
{
    DWCi_IPTlUpdate();
    func_021D75D0(0);
    func_021C4BDC();
    func_021C4C18();
}


static void procError1(void);


static void procError(void)
{
    if (DWCi_WINlGet())
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procError1);
}


static void initGraphics(void);

static void procInit(void);

static void procInit1(void);

static void procInit2(void);

static void procScene(void);

static void procConfirm(void);


static void endScene(void);

static void endScene1(void);

static void endScene2(void);


static void procError1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_ChangeScene(endScene);
}


static void input(void);

static void draw(void);

static void button(void);


static void procWait(void)
{
    input();
    draw();
    button();
    Choose.Count = Choose.Count + 1;
    if (Choose.Count < 1080)
        return;
    DWCi_SNDlStop();
    DWCi_ChangeScene(endScene);
}


/*
 * Tear down the sequence and post the event at 0x021C4C60.
 * Addresses are Black-image addresses.
 */
void func_021C4E98(void)
{
    func_021D0014();
    func_021CFFAC(7);
    *(unsigned char *)0x021DE5CC = 0;
    func_021C0E40((unsigned int)((void *)0x021C4C60));
}
