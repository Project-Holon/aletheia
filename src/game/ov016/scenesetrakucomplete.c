/*
 * file:     scenesetrakucomplete.c
 * unit:     yes
 * function: DWCi_SceneSetRakuComplete, initGraphics, procInit, procInit1, DWCi_SceneSetRakuComplete_procScene, DWCi_SceneSetRakuComplete_draw, endScene, endScene1, wait
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
 * sdk:      procInit1 (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovdisco), symbol endScene (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneoptmovdisco; its bytes equal the object's own
 * function and only the pool words differ (the copy's own data and next scene step).
 * The object that owns this copy is not identified; the C is the same either way.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB1D8.c \
 *       --func endScene --addr 0x021CB1D8 --region ov016 --cc 1.1p1 --arm --lang c99
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a(scenesetaosscomp))
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovdisco), symbol wait (name and prototype from the
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB294.c \
 *       --func wait --addr 0x021CB294 --region ov016 --cc 1.1p1 --arm --lang c99
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   initGraphics                     0x021cb0e4 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_CMNlMsgDraw                 0x021bd29c arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   Count                            0x021de600 data
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_EFFlFade                    0x021d55a4 arm
 *   DWCi_GXlVisible                  0x021d603c arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_MOVlIsEnd                   0x021C11B8  arm
 *   DWCi_SceneOptMenu                0x021C2A3C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   GX_LoadBG2Scr                    0x0207EB78  arm
 *   endScene1                        0x021CB21C  arm
 *   procScene                        0x021C3C94  arm
 *   sceneoptmovdisco_str_20611       0x021DB390  data
 *   DWCi_SetParam2_  0x021C0E8C  arm
 *   DWCi_SceneSetTestConfirm  0x021CD80C  arm
 */
#define reg_G2S_DB_BG0CNT (*(volatile unsigned short *)0x04001008)
#define reg_G2S_DB_BG1CNT (*(volatile unsigned short *)0x0400100A)
#define reg_G2_BG1CNT     (*(volatile unsigned short *)0x0400000A)
#define reg_G2_BG2CNT     (*(volatile unsigned short *)0x0400000C)
#include "../types.h"

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

extern void DWCi_HLlLoadSet(void);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_SNDlPlay(u32 v);
extern void DWCi_ChangeScene(u32 v);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void GX_LoadBG2Scr(void *src, unsigned long offset, unsigned long size);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern int DWCi_MOVlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_SceneSetTestConfirm(void);
void DWCi_SceneSetRakuComplete(void);
void DWCi_SceneSetRakuComplete_procScene(void);
void DWCi_SceneSetRakuComplete_draw(void);
extern unsigned char Count;
/* the resource file name, the compiler's @20611 in .rodata */
extern char sceneoptmovdisco_str_20611[];

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void endScene(void);
static void endScene1(void);
static void wait(void);

void DWCi_SceneSetRakuComplete(void)
{
    Count = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x26);
    DWCi_SNDlPlay(0x10);
    DWCi_ChangeScene((u32)procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB66C, (void *)0x0207EB78);
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
    DWCi_ChangeScene((u32)procInit1);
}

static void procInit1(void)
{
    if (!DWCi_EFFlCheck(0))
        DWCi_ChangeScene((u32)DWCi_SceneSetRakuComplete_procScene);
}

/*
 * Call wait, DWCi_SceneSetRakuComplete_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetRakuComplete_procScene.c \
 *       --func DWCi_SceneSetRakuComplete_procScene --addr 0x021CB1C4 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetRakuComplete_procScene(void)
{
    wait();
    DWCi_SceneSetRakuComplete_draw();
}

void DWCi_SceneSetRakuComplete_draw(void)
{
}

static void procScene(void);

static void endScene(void)
{
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((u32)endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1) != 0)
        return;
    if (DWCi_EFFlCheck(0) != 0)
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 0);
    DWCi_SetParam2_(0, 1);
    DWCi_ChangeScene((u32)DWCi_SceneSetTestConfirm);
}

static void wait(void)
{
    if (++Count >= 120)
        DWCi_ChangeScene((u32)endScene);
}
