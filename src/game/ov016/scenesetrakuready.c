/*
 * file:     scenesetrakuready.c
 * unit:     yes
 * function: DWCi_SceneSetRakuReady, func_021CB344, func_021CB3EC, func_021CB454, func_021CB498, func_021CB4BC, func_021CB4DC, DWCi_SceneSetRakuReady_draw, button, endScene, endScene1, endScene2, func_021CB6A4, func_021CB734, procError1
 * address:  0x021CB2E8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakuread), symbol DWCi_SceneSetRakuReady (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB2E8.c \
 *       --func DWCi_SceneSetRakuReady --addr 0x021CB2E8 --region ov016 --cc 1.1p1 --arm --lang c99
 * Set r0 to 0xa, call func_02085A38, then run the four ov016 steps.
 * Addresses are Black-image addresses.
 *   python tools/match.py one --src src/matched/func_021CB4BC.c \
 *       --func func_021CB4BC --addr 0x021CB4BC --region ov016 --cc dsi/1.1p1 --arm
 * Two-stage guard around func_021BCB28.
 *   python tools/match.py one --src src/matched/func_021CB4DC.c \
 *       --func func_021CB4DC --addr 0x021CB4DC --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneSetRakuReady_draw.c \
 *       --func DWCi_SceneSetRakuReady_draw --addr 0x021CB514 --region ov016 --cc dsi/1.1p1 --arm
 * sdk:      button (sceneoptmovwait.o), TwlDWC libdwcutil.TWL.HYB.a
 * sdk:      endScene (scenesetrakubutt.o), TwlDWC libdwcutil.TWL.HYB.a
 * sdk:      endScene1 (scenesetrakuread.o), TwlDWC libdwcutil.TWL.HYB.a
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakubutt), symbol endScene2 (name and prototype from the vendor object DWARF).
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB5D8.c \
 *       --func endScene2 --addr 0x021CB5D8 --region ov016 --cc 1.1p1 --arm --lang c99
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneopterase.o), symbol procError1 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneopterase.o; its bytes equal sceneopterase.o's own
 * function and only the pool words differ (the copy's own next scene step and, for endScene1,
 * its own one-byte flag, declared here under the sceneopterase_bss name at the copy's address).
 * The object that owns this copy is not identified; the C is the same either way.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB760.c \
 *       --func procError1 --addr 0x021CB760 --region ov016 --cc 1.1p1 --arm --lang c99
 *
 * symbols:
 *   initGraphics                     0x021cb344 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_COMMENTlDispEx              0x021bd060 arm
 *   DWCi_CMNlStep                    0x021bd214 arm
 *   DWCi_CMNlMsgDraw                 0x021bd29c arm
 *   DWCi_ANIMElInitEx                0x021bc820 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   Choose                           0x021de604 data
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB680    0x021DB680  data
 *   dat_021DB698    0x021DB698  data
 *   dat_021DB6B0    0x021DB6B0  data
 *   dat_0207F0B8    0x0207F0B8  data
 *   dat_0207E3D0    0x0207E3D0  data
 *   dat_0207EB78    0x0207EB78  data
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_RAKUlInit                   0x021c1488 arm
 *   DWCi_CMNlButton                  0x021bd264 arm
 *   DWCi_BTNlGet                     0x021bcb14 arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   procScene                        0x021cb4bc arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_BTNlIsEnd                   0x021bcb58 arm
 *   DWCi_ANIMElEnd                   0x021bc8ec arm
 *   DWCi_FNTlDeleteBgLcd             0x021d5ca8 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_RAKUlEnd                    0x021c14f4 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_SceneSetSelectWay           0x021cc998 arm
 *   DWCi_SceneSetRakuButton          0x021ca838 arm
 *   DWCi_RAKUlGetState               0x021c1518 arm
 *   DWCi_WINlInitEx                  0x021d1208 arm
 *   DWCi_WINlGet                     0x021d1568 arm
 *   DWCi_WINlEnd                     0x021d1524 arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   procConfirm                      0x021C22AC  arm
 *   sceneopterase_bss                0x021DE5A4  data
 */
typedef _Bool bool;

typedef unsigned short u16;

typedef unsigned int   u32;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

extern void DWCi_HLlLoadSet(void);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_RAKUlInit(void);
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void func_02085A38(u32 msec);
extern void func_021CB6A4(void);
extern void func_021CB518(void);
extern int func_021D6824(unsigned int f);
extern int func_021CB2C8(void);
extern void func_021BCB28(signed char v);
extern void DWCi_SNDlStop(void);
extern void DWCi_BTNlDisable(void);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_ANIMElEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_RAKUlEnd(void);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_SceneSetSelectWay(void);
extern void DWCi_SceneSetRakuButton(void);
extern int DWCi_RAKUlGetState(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern void DWCi_HLlLoad(int idx);
extern bool DWCi_WINlIsInit(void);
void DWCi_SceneSetRakuReady(void);
void func_021CB344(void);
void func_021CB4BC(void);
void func_021CB4DC(void);
void DWCi_SceneSetRakuReady_draw(void);
extern unsigned char Choose;
extern unsigned short dat_021DB680[];
extern unsigned short dat_021DB698[];
extern unsigned short dat_021DB6B0[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_0207EB78[];
extern SCENEOPTERASE_BSS sceneopterase_bss;


static void initGraphics(void);

static void procInit(void);


void DWCi_SceneSetRakuReady(void)
{
    Choose = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x37, -1, 0);
    DWCi_CMNlStep(2);
    DWCi_CMNlMsgDraw(0x24);
    DWCi_ANIMElInitEx(0);
    DWCi_SNDlPlay(0xb);
    DWCi_ChangeScene(procInit);
}



/*
 * Load three tilemaps through func_021BD1D4, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */
void func_021CB344(void)
{
    u16 *p;

    func_021BD1D4((char *)((int)dat_021DB680), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB698), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB6B0), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));

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
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_RAKUlInit();
    DWCi_CMNlButton(1);
    DWCi_ChangeScene(procInit2);
}



static void procScene(void);



static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


void func_021CB4BC(void)
{
    func_02085A38(0xa);
    func_021CB6A4();
    func_021CB4DC();
    DWCi_SceneSetRakuReady_draw();
    func_021CB518();
}


void func_021CB4DC(void)
{
    if (func_021D6824(2))
    {
        func_021BCB28(0);
        return;
    }
    if (func_021CB2C8())
        func_021BCB28(0);
}

void DWCi_SceneSetRakuReady_draw(void)
{
}


static void endScene(void);


static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
    DWCi_ChangeScene(endScene);
}


static void endScene1(void);


static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}


static void endScene2(void);


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (Choose == 0)
        DWCi_BTNlEnd();
    if (Choose == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x14, 8);
    DWCi_ChangeScene(endScene2);
}


static void endScene2(void)
{
    if (DWCi_EFFlCheck(0)) {
        return;
    }
    if (Choose == 0) {
        if (DWCi_EFFlCheck(1)) {
            return;
        }
    }
    if (!DWCi_BTNlIsEnd()) {
        return;
    }
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if (Choose == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (Choose == 0) {
        DWCi_RAKUlEnd();
        DWCi_SetParam_((void *)2, (void *)1);
        DWCi_ChangeScene(DWCi_SceneSetSelectWay);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetRakuButton);
    }
}


static void procError(void);



static void checkRaku(void)
{
    switch (DWCi_RAKUlGetState()) {
    case 1:
        Choose = 1;
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
    }
}



static void procError1(void);



static void procError(void)
{
    if (DWCi_WINlGet() != 0) {
        return;
    }
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procError1);
}

static void procConfirm(void);


static void procError1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_ChangeScene(endScene);
}
