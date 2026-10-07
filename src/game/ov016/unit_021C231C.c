/*
 * file:     unit_021C231C.c
 * unit:     yes
 * function: func_021C231C, func_021C2340, func_021C23C0, func_021C23FC, func_021C2428
 * address:  0x021C231C
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
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_SETTINGlEraseAll            0x021CFC20  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   button                           0x021C2484  arm
 *   endScene                         0x021C24AC  arm
 *   endScene1                        0x021C24CC  arm
 *   endScene2                        0x021C2528  arm
 *   initGraphics                     0x021C2340  arm
 *   procScene                        0x021C244C  arm
 *   func_021BD1D4  0x021BD1D4  arm
 */
typedef _Bool bool;

typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_SETTINGlEraseAll(void);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_SNDlPlay(int no);
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
void DWCi_SceneOptErase1(void);
void func_021C2340(void);


static void initGraphics(void);

static void procInit(void);

static void procInit1(void);

static void procInit2(void);

static void procScene(void);

static void button(void);

static void endScene(void);

static void endScene1(void);

static void endScene2(void);


void DWCi_SceneOptErase1(void)
{
    initGraphics();
    DWCi_CMNlMsgDraw(0x19);
    DWCi_SETTINGlEraseAll();
    DWCi_ChangeScene(procInit);
}


void func_021C2340(void)
{
    func_021BD1D4((void *)0x021DB2C8, (void *)0x0207EB78);
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
    DWCi_CMNlButton(5);
    DWCi_ChangeScene(procInit2);
}


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}
