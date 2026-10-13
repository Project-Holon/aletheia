/*
 * file:     scenesetlistsave.c
 * unit:     yes
 * function: func_021CA5D0, func_021CA5F0, procInit, func_021CA6EC, func_021CA740, DWCi_SceneSetListSave_input, DWCi_SceneSetListSave_draw, func_021CA770, func_021CA7B4, func_021CA818
 * address:  0x021CA5D0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenemenu.o), symbol procInit (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under scenemenu.o; its bytes equal scenemenu.o's own
 * function and only the pool word differs (the next scene step of the copy's own range).
 * The object that owns this copy is not identified; the C is the same either way.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CA684.c \
 *       --func procInit --addr 0x021CA684 --region ov016 --cc 1.1p1 --arm --lang c99
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *   python tools/match.py one --src src/matched/func_021CA818.c \
 *       --func func_021CA818 --addr 0x021CA818 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   initGraphics                     0x021ca5f0 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_SETTINGlSet                 0x021cf8d8 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB600    0x021DB600  data
 *   dat_0207F0B8    0x0207F0B8  data
 *   dat_021DB618    0x021DB618  data
 *   dat_0207E3D0    0x0207E3D0  data
 *   dat_021DB630    0x021DB630  data
 *   dat_0207EB78    0x0207EB78  data
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_FOCUSlDisp4                 0x021BD4C8  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_SCREENlCopyPalette          0x021CE7B0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   dispPushButton                   0x021C1EDC  arm
 *   endScene2                        0x021C1DC4  arm
 *   moveFocus                        0x021C1E70  arm
 *   procInit2                        0x021C1B90  arm
 *   scenemenu_bss                    0x021DE59C  data
 *   scenemenu_init_20658             0x021DA474  data
 *   scenemenu_rodata                 0x021DA478  data
 *   DWCi_WINlInitEx                  0x021d1208 arm
 *   input                            0x021ca768 arm
 *   draw                             0x021ca76c arm
 *   DWCi_WINlIsInit                  0x021d157c arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_SceneSetSelectAp            0x021cbc90 arm
 */
#include "../../matched/include/G_SCENEMENU_BSS.h"

typedef unsigned short u16;

typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

/* scenemenu.o .bss at 0x021DE59C, members at their vendor offsets */
typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    void          *Palette;           /* 0x04 */
} SCENEMENU_BSS;

/* scenemenu.o .rodata at 0x021DA478, members at their vendor offsets */
typedef struct {
    RECT           R_TOUCH[2];        /* 0x00 */
    RECT           R_FOCUS[2];        /* 0x10 */
} SCENEMENU_RODATA;

/* PALETTE's initialiser is the compiler's @20658 in its own .rodata section */
typedef struct { unsigned char v[2]; } PALETTE_INIT;

extern void DWCi_HLlLoadSet(void);
extern void DWCi_SETTINGlSet(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlSet(int idx);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern bool DWCi_TPlCheckTrigger(RECT *r);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern void DWCi_SceneEnd(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern bool DWCi_WINlIsInit(void);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(void *param0, void *param1);
void DWCi_SceneSetListSave(void);
void func_021CA5F0(void);
void DWCi_SceneSetListSave_input(void);
void DWCi_SceneSetListSave_draw(void);
int func_021CA818(void);
extern unsigned short dat_021DB600[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_021DB618[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_021DB630[];
extern unsigned short dat_0207EB78[];
extern struct SCENEMENU_BSS scenemenu_bss;
extern const SCENEMENU_RODATA scenemenu_rodata;
extern const PALETTE_INIT scenemenu_init_20658;
extern int DWCi_SceneSetSelectAp;



static void initGraphics(void);


static void procInit(void);



void DWCi_SceneSetListSave(void)
{
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_SETTINGlSet();
    DWCi_ChangeScene(procInit);
}



/*
 * Load three tilemaps through func_021BD1D4, then set the low two bits of
 * 0x04001008, 0x0400100A, 0x0400000A and 0x0400000C.
 * Addresses are Black-image addresses.
 */
void func_021CA5F0(void)
{
    u16 *p;

    func_021BD1D4((char *)((int)dat_021DB600), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB618), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB630), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}


static void procInit1(void);

static void procInit2(void);

static void procScene(void);

static void endScene(void);

static void endScene1(void);

static void endScene2(void);

static void moveFocus(int dir);

static void dispPushButton(void);


static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x14, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x14);
    DWCi_ChangeScene(procInit1);
}



static void procInit1(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_WINlInitEx(0x44, 5, 1, -1, 0);
    DWCi_ChangeScene(procScene);
}



static void input(void);


static void draw(void);



static void procScene(void)
{
    input();
    draw();
    if (DWCi_WINlIsInit()) {
        return;
    }
    DWCi_ChangeScene(endScene);
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetListSave_input.c \
 *       --func DWCi_SceneSetListSave_input --addr 0x021CA768 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetListSave_input(void)
{
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetListSave_draw.c \
 *       --func DWCi_SceneSetListSave_draw --addr 0x021CA76C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetListSave_draw(void)
{
}



static void endScene(void)
{
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x14, 8);
    DWCi_ChangeScene(endScene1);
}



static void endScene1(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    DWCi_SetParam_((void *)2, (void *)1);
    DWCi_ChangeScene((void (*)())&DWCi_SceneSetSelectAp);
}

int func_021CA818(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}
