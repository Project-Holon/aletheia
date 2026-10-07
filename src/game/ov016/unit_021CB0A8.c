/*
 * file:     unit_021CB0A8.c
 * unit:     yes
 * function: func_021CB0A8, func_021CB0E4, func_021CB164
 * address:  0x021CB0A8
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
 *   initGraphics                     0x021cb0e4 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_CMNlMsgDraw                 0x021bd29c arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   Count                            0x021de600 data
 *   func_021BD1D4  0x021BD1D4  arm
 *   DWCi_EFFlFade                    0x021d55a4 arm
 *   DWCi_GXlVisible                  0x021d603c arm
 *   procInit1                        0x021cb1a0 arm
 */
typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

extern void DWCi_HLlLoadSet(void);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
void DWCi_SceneSetRakuComplete(void);
void func_021CB0E4(void);
extern unsigned char Count;


static void initGraphics(void);

static void procInit(void);


void DWCi_SceneSetRakuComplete(void)
{
    Count = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x26);
    DWCi_SNDlPlay(0x10);
    DWCi_ChangeScene(procInit);
}


void func_021CB0E4(void)
{
    func_021BD1D4((void *)0x021DB66C, (void *)0x0207EB78);
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
