/*
 * file:     sceneoptmovconfirm.c
 * unit:     yes
 * function: DWCi_SceneOptMovConfirm, func_021C3610, func_021C3678, func_021C36B4, func_021C36F0, DWCi_SceneOptMovConfirm_procScene, func_021C3728, DWCi_SceneOptMovConfirm_draw, button, endScene
 * address:  0x021C35F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovconfi.o), symbol DWCi_SceneOptMovConfirm
 * (name and prototype from the vendor object DWARF). The object is stamped Metrowerks
 * C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so it stays on 1.1p1.
 * Call func_021C3728, DWCi_SceneOptMovConfirm_draw, func_021C374C.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovConfirm_procScene.c \
 *       --func DWCi_SceneOptMovConfirm_procScene --addr 0x021C3714 --region ov016 --cc dsi/1.1p1 --arm
 * Guard: if (func_021D6824(1)) call func_021D6824.
 *   python tools/match.py one --src src/matched/func_021C3728.c \
 *       --func func_021C3728 --addr 0x021C3728 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovConfirm_draw.c \
 *       --func DWCi_SceneOptMovConfirm_draw --addr 0x021C3748 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   initGraphics                     0x021C3610  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   procScene                        0x021C3714  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_SETTINGlEraseAll            0x021CFC20  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneOptErase1              0x021C231C  arm
 *   endScene2                        0x021C2528  arm
 *   endScene1                        0x021C3794  arm
 */
typedef volatile unsigned short vu16;

typedef _Bool bool;

extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void func_021C374C(void);
extern int func_021D6824(unsigned int f);
extern void func_021BCB28(signed char v);
extern void DWCi_SETTINGlEraseAll(void);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_BTNlDisable(void);
extern void DWCi_SNDlPlay(int no);
void DWCi_SceneOptMovConfirm(void);
void func_021C3610(void);
void DWCi_SceneOptMovConfirm_procScene(void);
void func_021C3728(void);
void DWCi_SceneOptMovConfirm_draw(void);


static void initGraphics(void);

static void procInit(void);


void DWCi_SceneOptMovConfirm(void)
{
    initGraphics();
    DWCi_CMNlMsgDraw(0x1a);
    DWCi_ChangeScene(procInit);
}



/*
 * sdk:      initGraphics (libdwcutil.TWL.HYB.a(sceneoptmovcompl))
 */
void func_021C3610(void)
{
    *(vu16 *)0x04001008 = (*(vu16 *)0x04001008 & ~3) | 3;
    *(vu16 *)0x0400100A = (*(vu16 *)0x0400100A & ~3) | 3;
    *(vu16 *)0x04000008 = (*(vu16 *)0x04000008 & ~3) | 3;
    *(vu16 *)0x0400000A = (*(vu16 *)0x0400000A & ~3) | 3;
    *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & ~3) | 3;
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
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(4);
    DWCi_ChangeScene(procInit2);
}



static void procScene(void);



static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


void DWCi_SceneOptMovConfirm_procScene(void)
{
    func_021C3728();
    DWCi_SceneOptMovConfirm_draw();
    func_021C374C();
}


void func_021C3728(void)
{
    if (func_021D6824(1))
        func_021BCB28(0);
}

void DWCi_SceneOptMovConfirm_draw(void)
{
}


static void button(void);


static void endScene(void);


static void endScene1(void);


static void endScene2(void);



static void button(void)
{
    if (DWCi_BTNlGet() != 0)
        return;
    DWCi_SNDlPlay(6);
    DWCi_ChangeScene(endScene);
}



static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}
