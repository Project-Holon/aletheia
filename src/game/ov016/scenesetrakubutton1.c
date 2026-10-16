/*
 * file:     scenesetrakubutton1.c
 * unit:     yes
 * function: DWCi_SceneSetRakuButton1, initGraphics, DWCi_SceneSetRakuButton1ProcInit, DWCi_SceneSetRakuButton1ProcInit1, DWCi_SceneSetRakuButton1ProcInit2, procScene, input, DWCi_SceneSetRakuButton_draw, button, endScene, endScene1, endScene2, checkRaku, DWCi_SceneSetRakuButton1ProcError, procError1
 * address:  0x021CAC64
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
 *       --func input --addr 0x021CADCC --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneSetRakuButton_draw.c \
 *       --func DWCi_SceneSetRakuButton_draw --addr 0x021CAE04 --region ov016 --cc dsi/1.1p1 --arm
 * sdk:      button (sceneoptmovwait.o), TwlDWC libdwcutil.TWL.HYB.a
 * sdk:      endScene (scenesetrakubutt.o), TwlDWC libdwcutil.TWL.HYB.a
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneopterase.o), symbol endScene1 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneopterase.o; its bytes equal sceneopterase.o's own
 * function and only the pool words differ (the copy's own next scene step and, for endScene1,
 * its own one-byte flag, declared here under the sceneopterase_bss name at the copy's address).
 * The object that owns this copy is not identified; the C is the same either way.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CAE54.c \
 *       --func endScene1 --addr 0x021CAE54 --region ov016 --cc 1.1p1 --arm --lang c99
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneopterase.o), symbol procError1 (name and prototype from the
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB088.c \
 *       --func procError1 --addr 0x021CB088 --region ov016 --cc 1.1p1 --arm --lang c99
 *
 * symbols:
 *   OS_Sleep                       0x02085A38  arm  arm9
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IsFold                    0x021CAC44  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   initGraphics      0x021CACA0 arm
 *   DWCi_HLlLoadSet   0x021BD6D4 arm
 *   DWCi_CMNlMsgDraw  0x021BD29C arm
 *   DWCi_ANIMElInitEx 0x021BC820 arm
 *   DWCi_ChangeScene  0x021C0E40 arm
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   procScene                        0x021CADAC  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   endScene2                        0x021CAEBC  arm
 *   procConfirm                      0x021C22AC  arm
 *   procConfirm1                     0x021C22FC  arm
 *   sceneopterase_bss                0x021DE5FC  data
 *   DWCi_BTNlIsEnd  0x021BCB58  arm
 *   DWCi_ANIMElEnd  0x021BC8EC  arm
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm
 *   DWCi_COMMENTlDelete  0x021BD138  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_RAKUlEnd  0x021C14F4  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   DWCi_SceneSetSelectWay  0x021CC998  arm
 *   DWCi_SceneSetRakuComplete  0x021CB0A8  arm
 *   gSceneSetRakuButton1Work  0x021DE5FC  data  a1
 *   DWCi_RAKUlGetState               0x021c1518 arm
 *   DWCi_RAKUlSetResult              0x021c15d0 arm
 *   Choose                           0x021de5fc data
 */

typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

typedef unsigned int   u32;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

void DWCi_HLlLoadSet(void);
void DWCi_CMNlMsgDraw(int msgId);
void DWCi_ANIMElInitEx(int color);
extern void DWCi_ChangeScene(void (*scene)(void));
void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void OS_Sleep(u32 msec);
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern int DWCi_IsFold(void);
extern void DWCi_BTNlSet(signed char v);
extern void DWCi_SNDlStop(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_BTNlDisable(void);
extern bool DWCi_EFFlWait(int frame);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_HLlLoad(int idx);
extern void DWCi_BTNlEnd(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_ANIMElEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int x);
extern void DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int a, int b);
extern void DWCi_RAKUlEnd(void);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneSetSelectWay(void);
extern void DWCi_SceneSetRakuComplete(void);
extern int DWCi_RAKUlGetState(void);
extern void DWCi_RAKUlSetResult(void);
void DWCi_SceneSetRakuButton1(void);
void DWCi_SceneSetRakuButton_draw(void);
extern SCENEOPTERASE_BSS sceneopterase_bss;
extern unsigned char Choose;

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
static void checkRaku(void);
static void procError(void);
static void procError1(void);


void DWCi_SceneSetRakuButton1(void)
{
    *(unsigned char *)0x021DE5FC = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x2a);
    DWCi_ANIMElInitEx(2);
    DWCi_ChangeScene(procInit);
}


static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB658, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}


static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}


static void procInit1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(1);
    DWCi_ChangeScene(procInit2);
}


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


static void procScene(void)
{
    OS_Sleep(0xa);
    checkRaku();
    input();
    DWCi_SceneSetRakuButton_draw();
    button();
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

void DWCi_SceneSetRakuButton_draw(void)
{
}


static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
    DWCi_ChangeScene(endScene);
}


static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
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
    DWCi_ChangeScene(endScene2);
}


/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(scenesetrakubutt))
 */
static void endScene2(void)
{
    if (DWCi_EFFlCheck(0) != 0)
        return;
    if (Choose == 0) {
        if (DWCi_EFFlCheck(1) != 0)
            return;
    }
    if (DWCi_BTNlIsEnd() == 0)
        return;
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if (Choose == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_RAKUlEnd();
    if (Choose == 0) {
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene(DWCi_SceneSetSelectWay);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetRakuComplete);
    }
}


static void checkRaku(void)
{
    switch (DWCi_RAKUlGetState()) {
    case 3:
        Choose = 1;
        DWCi_SNDlStop();
        DWCi_RAKUlSetResult();
        DWCi_ChangeScene(endScene);
        break;
    case 4:
        Choose = 0;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(9);
        DWCi_WINlInitEx(0xd, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procError);
        break;
    case 5:
        Choose = 0;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(0x12);
        DWCi_WINlInitEx(0xe, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procError);
        break;
    }
}


static void procError(void)
{
    if (DWCi_WINlGet() == 0) {
        DWCi_SNDlPlay(6);
        DWCi_WINlEnd();
        DWCi_ChangeScene(procError1);
    }
}


static void procError1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_ChangeScene(endScene);
}
