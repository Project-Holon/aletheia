/*
 * file:     sceneoptmovwait.c
 * unit:     yes
 * function: func_021C44EC, func_021C450C, func_021C4558, func_021C45D8, func_021C4614, procInit2, DWCi_SceneOptMovWait_procScene, func_021C4674, DWCi_SceneOptMovWait_draw, func_021C46B0, func_021C46DC, func_021C4714, func_021C4794, func_021C4890, func_021C48E4
 * address:  0x021C44EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      procInit2 (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 * Call func_021C4674, DWCi_SceneOptMovWait_draw, func_021C46B0.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovWait_procScene.c \
 *       --func DWCi_SceneOptMovWait_procScene --addr 0x021C4660 --region ov016 --cc dsi/1.1p1 --arm
 * Two-stage guard around func_021BCB28.
 *   python tools/match.py one --src src/matched/func_021C4674.c \
 *       --func func_021C4674 --addr 0x021C4674 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovWait_draw.c \
 *       --func DWCi_SceneOptMovWait_draw --addr 0x021C46AC --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_MOVlInit                    0x021C1074  arm
 *   initGraphics                     0x021C4558  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ANIMElInitEx                0x021BC820  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   cbMov                            0x021C4890  arm
 *   Choose                           0x021DE5C8  data
 *   func_021BD1D4  0x021BD1D4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   procScene                        0x021C4660  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   endScene                         0x021C46DC  arm
 *   func_021D5580  0x021D5580  arm
 *   func_021C11B8  0x021C11B8  arm
 *   func_021BCAE4  0x021BCAE4  arm
 *   func_021D55A4  0x021D55A4  arm
 *   func_021C0E40  0x021C0E40  arm
 *   g_021DE5C8     0x021DE5C8  data
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021BC8EC  0x021BC8EC  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C2A3C  0x021C2A3C  arm  ov016
 *   func_021C3D8C  0x021C3D8C  arm  ov016
 *   func_021C4110  0x021C4110  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C11D4  0x021C11D4  arm  ov016
 */
typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

typedef unsigned char u8;

extern void DWCi_MOVlInit(void (*callback)(int));
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void func_021C46B0(void);
extern int func_021D6824(unsigned int f);
extern void func_021BCB28(signed char v);
extern void DWCi_SNDlStop(void);
extern void func_021C115C(void);
extern void func_021BCB9C(void);
extern void func_021D5790(int);
extern void func_021C0E40(unsigned int v);
extern int  func_021D5580(int x);
extern int  func_021C11B8(void);
extern void func_021BCAE4(void);
extern void func_021D55A4(int a, int b, int c, int d);
extern int func_021BCB58();
extern void func_021BC8EC();
extern void func_021D5CA8(int a);
extern void func_021BD138();
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C2A3C();
extern void func_021C3D8C();
extern void func_021C4110();
extern void func_021D0014();
extern void func_021CFFAC(unsigned int v);
extern void func_021C11D4(unsigned int v);
int func_021C44EC(void);
void DWCi_SceneOptMovWait(void);
void func_021C4558(void);
void DWCi_SceneOptMovWait_procScene(void);
void func_021C4674(void);
void DWCi_SceneOptMovWait_draw(void);
void func_021C46DC(void);
void func_021C4714(void);
void func_021C4794(void);
void func_021C4890(int state);
int func_021C48E4(void);
extern unsigned char Choose;
extern u8   g_021DE5C8;


/*
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C44EC.c \
 *       --func func_021C44EC --addr 0x021C44EC --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021C44EC(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}



static void cbMov(int state);


static void initGraphics(void);


static void procInit(void);



void DWCi_SceneOptMovWait(void)
{
    DWCi_MOVlInit(cbMov);
    Choose = 0;
    initGraphics();
    DWCi_CMNlMsgDraw(0x1c);
    DWCi_ANIMElInitEx(0);
    DWCi_SNDlPlay(0xb);
    DWCi_ChangeScene(procInit);
}



void func_021C4558(void)
{
    func_021BD1D4((void *)0x021DB3CC, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}



static void procInit1(void);



static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}



static void procInit2(void);



static void procInit1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(1);
    DWCi_ChangeScene(procInit2);
}


static void procScene(void);


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_ChangeScene(procScene);
}


void DWCi_SceneOptMovWait_procScene(void)
{
    func_021C4674();
    DWCi_SceneOptMovWait_draw();
    func_021C46B0();
}


void func_021C4674(void)
{
    if (func_021D6824(2))
    {
        func_021BCB28(0);
        return;
    }
    if (func_021C44EC())
        func_021BCB28(0);
}

void DWCi_SceneOptMovWait_draw(void)
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




/*
 * Wake the sub-state, flag it and post the event at 0x021C4714.
 * Addresses are Black-image addresses.
 */
void func_021C46DC(void)
{
    if (*(unsigned char *)0x021DE5C8 == 0)
        func_021C115C();
    func_021BCB9C();
    func_021D5790(8);
    func_021C0E40((unsigned int)((void *)0x021C4714));
}




void func_021C4714(void)
{
    if (func_021D5580(1) != 0)
        return;
    if (g_021DE5C8 == 0) {
        if (func_021C11B8() == 0)
            return;
    }
    func_021BCAE4();
    if (g_021DE5C8 == 0)
        func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 0x15, 8);
    func_021C0E40((unsigned int)func_021C4794);
}




/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneoptmovwait.o)
 */
void func_021C4794(void)
{
    if (func_021D5580(0))
        return;
    if (g_021DE5C8 == 0) {
        if (func_021D5580(1))
            return;
    }
    if (!func_021BCB58())
        return;
    if (g_021DE5C8 == 0) {
        if (!func_021C11B8())
            return;
    }
    func_021BC8EC();
    func_021D5CA8(0);
    if (g_021DE5C8 == 0) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021D6090(0, 0x15);
    if (g_021DE5C8 == 0) {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C2A3C);
    } else if (g_021DE5C8 == 2) {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C3D8C);
    } else {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C4110);
    }
}




/*
 * sdk:      cbMov (libdwcutil.TWL.HYB.a sceneoptmovwait.o)
 */
void func_021C4890(int state)
{
    func_021D0014();
    if (state == 0) {
        g_021DE5C8 = 1;
        func_021CFFAC(0x10);
    } else {
        g_021DE5C8 = 2;
        func_021CFFAC(0x12);
    }
    func_021C11D4(0);
    func_021C0E40((unsigned int)func_021C46DC);
}



/*
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C48E4.c \
 *       --func func_021C48E4 --addr 0x021C48E4 --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021C48E4(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}
