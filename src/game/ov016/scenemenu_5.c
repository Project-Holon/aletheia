/*
 * file:     scenemenu_5.c
 * unit:     yes
 * function: func_021C1CFC, func_021C1D4C, func_021C1D6C, func_021C1DC4, func_021C1E70, func_021C1EDC
 * address:  0x021C1CFC
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
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
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
 *   endScene2                        0x021C1DC4  arm
 *   procInit1                        0x021C1B50  arm
 *   procInit2                        0x021C1B90  arm
 *   procScene                        0x021C1BB4  arm
 *   scenemenu_bss                    0x021DE59C  data
 *   scenemenu_init_20658             0x021DA474  data
 *   scenemenu_rodata                 0x021DA478  data
 *   func_021D5580  0x021D5580  arm
 *   func_021BD5A8  0x021BD5A8  arm
 *   func_021BD138  0x021BD138  arm
 *   func_021D4C68  0x021D4C68  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C0E50  0x021C0E50  arm
 *   func_021C0E40  0x021C0E40  arm
 *   dat_021DE59C   0x021DE59C  data
 *   func_021CBC90  0x021CBC90  arm
 *   func_021C2A3C  0x021C2A3C  arm
 */
#include "../../matched/include/G_SCENEMENU_BSS.h"

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

typedef unsigned char u8;

struct D {
    u8  f0;
    u8  pad01[3];
    int f4;
};

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
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
extern int  func_021D5580(int x);
extern void func_021BD5A8(void);
extern void func_021BD138(void);
extern void func_021D4C68(void *file);
extern void func_021D6090(int a, int b);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021CBC90(void);
extern void func_021C2A3C(void);
void func_021C1DC4(void);
extern struct SCENEMENU_BSS scenemenu_bss;
extern const SCENEMENU_RODATA scenemenu_rodata;
extern const PALETTE_INIT scenemenu_init_20658;
extern struct D dat_021DE59C;


static void procInit1(void);

static void procInit2(void);

static void procScene(void);

static void endScene(void);

static void endScene1(void);

static void endScene2(void);

static void moveFocus(int dir);

static void dispPushButton(void);


static void button(void)
{
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        DWCi_ChangeScene(DWCi_SceneEnd);
        break;
    case 1:
        DWCi_SNDlPlay(6);
        dispPushButton();
        DWCi_ChangeScene(endScene);
        break;
    }
}


static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x16, 8);
    DWCi_ChangeScene(endScene2);
}


void func_021C1DC4(void)
{
    if (func_021D5580(1) != 0)
        return;
    if (func_021D5580(0) != 0)
        return;
    func_021BD5A8();
    func_021BD138();
    func_021D4C68((void *)dat_021DE59C.f4);
    func_021D6090(1, 1);
    func_021D6090(0, 0x14);
    switch (dat_021DE59C.f0) {
    case 0:
        func_021C0E50(1, 0);
        func_021C0E40((unsigned int)func_021CBC90);
        return;
    case 1:
        func_021C0E50(0, 0);
        func_021C0E40((unsigned int)func_021C2A3C);
        return;
    }
}


static void moveFocus(int dir)
{
    if (dir != 1 && dir != 3) {
        scenemenu_bss.FocusPos ^= 1;
        DWCi_SNDlPlay(8);
        DWCi_FOCUSlDisp4(scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].l, scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].r,
                         scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].t, scenemenu_rodata.R_FOCUS[scenemenu_bss.FocusPos].b);
    }
}


static void dispPushButton(void)
{
    PALETTE_INIT PALETTE = scenemenu_init_20658;

    DWCi_SCREENlCopyPalette(scenemenu_bss.Palette, PALETTE.v[scenemenu_bss.FocusPos], PALETTE.v[scenemenu_bss.FocusPos]);
}
