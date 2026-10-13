/*
 * file:     scenesetaossbutton.c
 * unit:     yes
 * function: func_021C4904, func_021C4964, func_021C4A0C, procInit1, procInit2, func_021C4AF8, func_021C4BDC, DWCi_SceneSetAossButton_draw, func_021C4C18, func_021C4C60, endScene1, func_021C4D04, func_021C4DE4, func_021C4E00, func_021C4E2C, func_021C4E4C, func_021C4E98
 * address:  0x021C4904
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Two-stage guard around func_021BCB28.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C4BDC.c \
 *       --func func_021C4BDC --addr 0x021C4BDC --region ov016 --cc dsi/1.1p1 --arm
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
 *   Choose                           0x021DE5CC  data
 *   initGraphics                     0x021C4964  arm
 *   DWCi_HLlLoadSet                  0x021BD6D4  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ANIMElInitEx                0x021BC820  arm
 *   DWCi_AOSSlInit                   0x021C07A8  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB3E0    0x021DB3E0  data
 *   dat_021DB3F8    0x021DB3F8  data
 *   dat_021DB410    0x021DB410  data
 *   dat_0207F0B8    0x0207F0B8  data
 *   dat_0207E3D0    0x0207E3D0  data
 *   dat_0207EB78    0x0207EB78  data
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   taskVBlank                       0x021C4DE4  arm
 *   procScene                        0x021C4AF8  arm
 *   func_021C4C18  0x021C4C18  arm  ov016
 *   func_021C0900  0x021C0900  arm  ov016
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   g_021DE5CC     0x021DE5CC  data
 *   func_021C4E4C  0x021C4E4C  arm  ov016
 *   func_021C4E00  0x021C4E00  arm  ov016
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   procCancel                       0x021C4E98  arm
 *   DWCi_TSKlDeleteEx                0x021D7744  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   endScene2                        0x021C4D04  arm
 *   procConfirm                      0x021C22AC  arm
 *   procConfirm1                     0x021C22FC  arm
 *   sceneopterase_bss                0x021DE5CC  data
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021C08B0  0x021C08B0  arm  ov016
 *   func_021BC8EC  0x021BC8EC  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021CC998  0x021CC998  arm  ov016
 *   func_021C4EC8  0x021C4EC8  arm  ov016
 *   input                            0x021C4BDC  arm
 *   draw                             0x021C4C14  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_IPTlUpdate  0x021D656C  arm
 */
#include "../../matched/include/G_SCENESETAOSSBUTT_BSS.h"

typedef _Bool bool;

/* scenesetaossbutt.o .bss at 0x021DE5CC, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
    void          *Task;              /* 0x04 */
} SCENESETAOSSBUTT_BSS;

typedef unsigned short u16;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

extern void DWCi_HLlLoadSet(void);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_AOSSlInit(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlButton(int kind);
extern int   DWCi_BTNlGet(void);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021C4C18();
extern int func_021C0900();
extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void func_021C0E40(unsigned int v);
extern void func_021D0014();
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021CFFAC(unsigned int v);
extern void func_021BCB9C();
extern void func_021C4E4C();
extern void func_021C4E00();
extern int func_021D6824(unsigned int f);
extern int func_021C48E4(void);
extern void func_021BCB28(signed char v);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_BTNlDisable(void);
extern void DWCi_TSKlDeleteEx(int kind, void *task);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_HLlLoad(int idx);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlEnd(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
extern int func_021D5580();
extern int func_021BCB58();
extern void func_021C08B0(int a);
extern void func_021BC8EC();
extern void func_021D5CA8(int a);
extern void func_021BD138();
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021CC998();
extern void func_021C4EC8();
extern void DWCi_IPTlUpdate(void);
extern void func_021D75D0(int);
extern void DWCi_SNDlStop(void);
void DWCi_SceneSetAossButton(void);
void func_021C4964(void);
void func_021C4AF8(void);
void func_021C4BDC(void);
void DWCi_SceneSetAossButton_draw(void);
void func_021C4D04(void);
void func_021C4DE4(void);
void func_021C4E98(void);
extern SCENESETAOSSBUTT_BSS Choose;
extern unsigned short dat_021DB3E0[];
extern unsigned short dat_021DB3F8[];
extern unsigned short dat_021DB410[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_0207EB78[];
extern SCENEOPTERASE_BSS sceneopterase_bss;
extern struct SCENESETAOSSBUTT_BSS g_021DE5CC;






static void initGraphics(void);





static void procInit(void);






void DWCi_SceneSetAossButton(void)
{
    Choose.Count = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x36, -1, 0);
    DWCi_CMNlStep(2);
    DWCi_CMNlMsgDraw(0x22);
    DWCi_ANIMElInitEx(0);
    DWCi_AOSSlInit();
    DWCi_SNDlPlay(0xb);
    DWCi_ChangeScene(procInit);
}






/*
 * Load three tilemaps through func_021BD1D4, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */
void func_021C4964(void)
{
    u16 *p;

    func_021BD1D4((char *)((int)dat_021DB3E0), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB3F8), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB410), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}






static void procInit1(void);






static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}





static void procInit2(void);





static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(1);
    DWCi_ChangeScene(procInit2);
}




static void taskVBlank(void);



static void procScene(void);




static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    Choose.Task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskVBlank, 0, 0x78);
    DWCi_ChangeScene(procScene);
}



void func_021C4AF8(void)
{
    func_021C4BDC();
    DWCi_SceneSetAossButton_draw();
    func_021C4C18();
    switch (func_021C0900()) {
    case 0:
        return;
    case 1:
        if (Choose.Task == 0)
            return;
        Choose.Choose = 1;
        DWCi_TSKlDeleteByIndex(1, Choose.Task);
        Choose.Task = 0;
        func_021C0E40((unsigned int)func_021C4E4C);
        return;
    case 2:
        if (Choose.Task == 0)
            return;
        func_021D0014();
        func_021D1208(0xC, 1, 1, -1, 0);
        func_021CFFAC(9);
        func_021BCB9C();
        DWCi_TSKlDeleteByIndex(1, Choose.Task);
        Choose.Task = 0;
        func_021C0E40((unsigned int)func_021C4E00);
        return;
    }
}


void func_021C4BDC(void)
{
    if (func_021D6824(2))
    {
        func_021BCB28(0);
        return;
    }
    if (func_021C48E4())
        func_021BCB28(0);
}

void DWCi_SceneSetAossButton_draw(void)
{
}



static void procCancel(void);



static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    if (Choose.Task == 0)
        return;
    DWCi_TSKlDelete(1, Choose.Task);
    Choose.Task = 0;
    DWCi_BTNlDisable();
    DWCi_ChangeScene(procCancel);
}



static void endScene1(void);



static void endScene(void)
{
    DWCi_BTNlDisable();
    if (Choose.Task != 0)
        DWCi_TSKlDeleteEx(1, Choose.Task);
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}

static void procConfirm(void);

static void procConfirm1(void);

static void endScene(void);

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
