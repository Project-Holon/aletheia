/*
 * file:     scenesetselectap_7.c
 * unit:     yes
 * function: func_021CC0E8, func_021CC208, endScene1, func_021CC2D0, func_021CC46C, func_021CC4E8, func_021CC6AC, func_021CC740, func_021CC8A0, func_021CC8C4
 * address:  0x021CC0E8
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
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_Entry                       0x021C0ED8  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_SETTINGlGetSetType          0x021CF7F4  arm
 *   DWCi_BTNlSetForce                0x021BCB44  arm
 *   DWCi_Language                    0x021C0EC8  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_SETTINGlSetSetting          0x021CF80C  arm
 *   g_021DE60C                       0x021DE60C  data
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   g_021DA724                       0x021DA724  data
 *   DWCi_STEPlEnd                    0x021d0580 arm
 *   DWCi_EFFlWait                    0x021d5790 arm
 *   scenesetselectap_bss             0x021de60c data
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_SETTIGNlGet                 0x021cf404 arm
 *   DWCi_BTNlEnd                     0x021bcae4 arm
 *   DWCi_EFFlFade                    0x021d55a4 arm
 *   endScene2                        0x021cc2d0 arm
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021D0A84  0x021D0A84  arm  ov016
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021D4F60  0x021D4F60  arm  ov016
 *   func_021BD5A8  0x021BD5A8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D4C68  0x021D4C68  arm  ov016
 *   func_021BD1D4  0x021BD1D4  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021CF404  0x021CF404  arm  ov016
 *   func_021C0E8C  0x021C0E8C  arm  ov016
 *   func_021CA5C0  0x021CA5C0  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   func_0207E51C  0x0207E51C  arm
 *   func_021C1984  0x021C1984  arm  ov016
 *   func_021CC998  0x021CC998  arm  ov016
 *   func_021C82FC  0x021C82FC  arm  ov016
 *   func_021CDCAC  0x021CDCAC  arm  ov016
 *   g_021DE610  0x021DE610  data
 *   @21063  0x021DB760  data
 *   DWCi_FOCUSlDisp4                 0x021bd4c8 arm
 *   DWCi_FOCUSlDisp                  0x021bd41c arm
 *   FocusPos                         0x021de60c data
 *   R_FOCUS                          0x021da77c data
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021CC46C  0x021CC46C  arm  ov016
 *   DWCi_CELLlGetObj                 0x021d4fe0 arm
 *   DWCi_CEINlSet                    0x021d52d4 arm
 *   DWCi_CELLlSetPosition            0x021d5118 arm
 *   DWCi_CELLlSetPriority            0x021d51f0 arm
 *   C_CELL                           0x021da72c data
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_SETTINGlErasePage           0x021CFBE4  arm
 *   DWCi_CELLlDelete                 0x021D4F60  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   g_021DA72C                       0x021DA72C  data
 *   g_021DA72E                       0x021DA72E  data
 *   DWCi_WINlIsInit                  0x021d157c arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   procScene                        0x021cbfd8 arm
 *   DWCi_SCREENlCopyPalette          0x021ce7b0 arm
 *   DWCi_CELLlSetPalette             0x021d5098 arm
 *   g_021DA7B4                      0x021da7b4 data
 *   g_021DA7B8                      0x021da7b8 data
 */
#include "../../matched/include/G_SCENESETSELECTAP_BSS.h"

#define NELEMS(a) (sizeof(a) / sizeof((a)[0]))
typedef _Bool bool;

typedef unsigned char u8;

typedef signed char s8;

struct SelApObj {
    u8 pad0[0x1d];
    u8 state;
};

/* scenesetselectap.o .bss at 0x021DE60C, members at their vendor offsets */
typedef struct {
    void          *palette;           /* 0x00 */
    void          *cellA[3];          /* 0x04 */
    void          *cellB[3];          /* 0x10 */
    unsigned char  pad0;              /* 0x1C */
    unsigned char  state;             /* 0x1D */
    unsigned char  pad1[2];
} SSSA;                               /* 0x20 */

typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    SSSA          *MemSssa;           /* 0x04 */
} SCENESETSELECTAP_BSS;

typedef struct tagSETTINGINFO {
    unsigned char pad[0xE7];
    unsigned char setting;            /* 0xE7 */
} SETTINGINFO;

typedef unsigned long u32;

typedef struct tagMEMSSSA {
    void *arc;                        /* 0x00 */
    void *cellA[3];                   /* 0x04 */
    void *cellB[3];                   /* 0x10 */
    unsigned char column;             /* 0x1C */
    unsigned char mode;               /* 0x1D */
} MEMSSSA;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

typedef struct tagCOORD { unsigned short x, y; } COORD;

typedef struct GXOamAttr GXOamAttr;

struct selobj {
    int f0;
    void *a[3];
    void *b[3];
};

/* the compiler's g_021DA7B4and g_021DA7B8initialisers, each in its own .rodata section */
typedef struct { unsigned char v[4]; } PLT4;

extern int DWCi_BTNlGet(void);
extern int DWCi_Entry(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_BTNlDisable(void);
extern void DWCi_ChangeScene(void (*scene)());
extern int DWCi_SETTINGlGetSetType(int idx);
extern void DWCi_BTNlSetForce(int idx);
extern int DWCi_Language(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_SETTINGlSetSetting(int idx);
extern void DWCi_SceneEnd(void);
extern void DWCi_STEPlEnd(void);
extern bool DWCi_EFFlWait(int frame);
extern bool DWCi_EFFlCheck(int lcd);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern int func_021D5580(int lcd);
extern int func_021D0A84(void);
extern int func_021BCB58(void);
extern void func_021D4F60(u8 *p);
extern void func_021BD5A8(void);
extern int func_021BD138(void);
extern void func_021D4C68(void *file);
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern SETTINGINFO *func_021CF404(void);
extern void func_021C0E8C(unsigned int a, unsigned int b);
extern void func_021CA5C0(unsigned char v);
extern void func_021C0E40(unsigned int v);
extern void func_021D6438(void **mem);
extern void func_0207E51C(void *, u32, u32);
extern void func_021C1984();
extern void func_021CC998();
extern void func_021C82FC();
extern void func_021CDCAC();
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y);
extern void func_021CFFAC(unsigned int v);
extern void func_021CC46C(void);
extern GXOamAttr *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern int DWCi_WINlGet(void);
extern void DWCi_SETTINGlErasePage(int page);
extern void DWCi_CELLlDelete(void *cell);
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);
extern struct SCENESETSELECTAP_BSS g_021DE60C;
extern const s8 g_021DA724[7];
extern SCENESETSELECTAP_BSS scenesetselectap_bss;
extern MEMSSSA *g_021DE610;
/* scenesetselectap.o .rodata at 0x021DA77C */
extern const RECT R_FOCUS[7];
/* scenesetselectap.o .bss at 0x021DE60C */
extern unsigned char FocusPos;
/* scenesetselectap.o .rodata at 0x021DA72C */
extern const COORD C_CELL[6];
extern struct tagCOORD g_021DA72C[6];
extern struct tagCOORD g_021DA72E[6];
extern const PLT4 g_021DA7B4;
extern const PLT4 g_021DA7B8;





static void dispPushClear(void);




static void dispPush(void);




static void procErase(void);




static void endScene(void);





static void button(void)
{
    int idx;
    int lang;

    switch (DWCi_BTNlGet()) {
    case 0:
        switch (DWCi_Entry()) {
        case 0:
            DWCi_SNDlPlay(7);
            ((struct SelApObj *)g_021DE60C.MemSssa)->state = 2;
            break;
        case 1:
            DWCi_BTNlDisable();
            DWCi_ChangeScene(DWCi_SceneEnd);
            return;
        }
        break;
    case 1:
        ((struct SelApObj *)g_021DE60C.MemSssa)->state = 1;
        if (g_021DE60C.FocusPos >= 4) {
            idx = g_021DE60C.FocusPos - 4;
            if (DWCi_SETTINGlGetSetType(idx) == 0xff) {
                DWCi_SNDlPlay(9);
                DWCi_BTNlSetForce(-1);
                return;
            }
            DWCi_SNDlPlay(6);
            lang = g_021DA724[DWCi_Language()];
            DWCi_WINlInitEx(0x46, 0, 1, lang, idx + 1);

            dispPushClear();
            DWCi_BTNlDisable();
            DWCi_ChangeScene(procErase);
            return;
        }
        if (g_021DE60C.FocusPos <= 2)
            DWCi_SETTINGlSetSetting(g_021DE60C.FocusPos);
        DWCi_SNDlPlay(6);
        dispPush();
        break;
    default:
        return;
    }
    DWCi_ChangeScene(endScene);
}





static void endScene1(void);





static void endScene(void)
{
    if (scenesetselectap_bss.MemSssa->state == 2) {
        DWCi_STEPlEnd();
    }
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}




static void endScene2(void);




static void endScene1(void)
{
    if (DWCi_EFFlCheck(1)) {
        return;
    }
    if (scenesetselectap_bss.MemSssa->state == 1) {
        if (scenesetselectap_bss.FocusPos == 3 || DWCi_SETTIGNlGet()->setting != 0xFF) {
            DWCi_BTNlEnd();
        }
    }
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x14, 8);
    DWCi_ChangeScene(endScene2);
}




/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(scenesetselectap))
 *
 * The object reaches MemSssa (0x021DE610) through FocusPos (0x021DE60C) + 4, and
 * takes &MemSssa through its own pool word; both spellings are declared.
 */
static void func_021CC2D0(void)
{
    int i;

    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    if (!func_021D0A84())
        return;
    if (!func_021BCB58())
        return;

    for (i = 0; i < NELEMS(((MEMSSSA *)g_021DE60C.MemSssa)->cellA); i++) {
        if (((MEMSSSA *)g_021DE60C.MemSssa)->cellA[i])
            func_021D4F60(((MEMSSSA *)g_021DE60C.MemSssa)->cellA[i]);
    }
    for (i = 0; i < NELEMS(((MEMSSSA *)g_021DE60C.MemSssa)->cellB); i++) {
        if (((MEMSSSA *)g_021DE60C.MemSssa)->cellB[i])
            func_021D4F60(((MEMSSSA *)g_021DE60C.MemSssa)->cellB[i]);
    }
    func_021BD5A8();
    func_021BD138();
    func_021D4C68(((MEMSSSA *)g_021DE60C.MemSssa)->arc);
    func_021BD1D4("char/ybObjMain.ncl.l", func_0207E51C);
    func_021D6090(1, 1);
    func_021D6090(0, 0x14);

    if (((MEMSSSA *)g_021DE60C.MemSssa)->mode == 2) {
        func_021C0E50((unsigned int)((void *)0), (unsigned int)((void *)0));
        func_021C0E40((unsigned int)func_021C1984);
    } else {
        switch (g_021DE60C.FocusPos) {
        case 0:
        case 1:
        case 2:
            func_021C0E50((unsigned int)((void *)2), (unsigned int)((void *)0));
            if (func_021CF404()->setting == 0xff) {
                func_021C0E40((unsigned int)func_021CC998);
            } else {
                func_021C0E8C((unsigned int)((void *)0), (unsigned int)((void *)0));
                func_021CA5C0(0);
                func_021C0E40((unsigned int)func_021C82FC);
            }
            break;
        case 3:
            func_021C0E50((unsigned int)((void *)2), (unsigned int)((void *)1));
            func_021C0E40((unsigned int)func_021CDCAC);
            break;
        }
    }
    func_021D6438((void **)&g_021DE610);
}




static void dispFocus(void)
{
    if (FocusPos < 4) {
        DWCi_FOCUSlDisp4(R_FOCUS[FocusPos].l, R_FOCUS[FocusPos].r, R_FOCUS[FocusPos].t, R_FOCUS[FocusPos].b);
    } else {
        DWCi_FOCUSlDisp(0, R_FOCUS[FocusPos].l, R_FOCUS[FocusPos].r, R_FOCUS[FocusPos].t);
    }
}




/*
 * sdk:      moveFocus (libdwcutil.TWL.HYB.a(scenesetselectap))
 *
 * FocusPos (0x021DE60C) anchors the statics; MemSssa sits at +4. The DWARF lists
 * only move and clear; the object computes clear + 4 unconditionally before the
 * dir test, which the second local next reproduces.
 */
static void func_021CC4E8(int dir)
{
    int clear;
    int next;
    int move = 1;

    switch (g_021DE60C.FocusPos) {
    case 0:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 0;
        if (dir == 0)
            g_021DE60C.FocusPos = 2;
        else if (dir == 2)
            g_021DE60C.FocusPos = 1;
        else if (dir == 1)
            g_021DE60C.FocusPos = 3;
        else
            g_021DE60C.FocusPos = 4;
        break;
    case 1:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 1;
        if (dir == 0)
            g_021DE60C.FocusPos = 0;
        else if (dir == 2)
            g_021DE60C.FocusPos = 2;
        else if (dir == 1)
            g_021DE60C.FocusPos = 3;
        else
            g_021DE60C.FocusPos = 5;
        break;
    case 2:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 2;
        if (dir == 0)
            g_021DE60C.FocusPos = 1;
        else if (dir == 2)
            g_021DE60C.FocusPos = 0;
        else if (dir == 1)
            g_021DE60C.FocusPos = 3;
        else
            g_021DE60C.FocusPos = 6;
        break;
    case 3:
        clear = ((MEMSSSA *)g_021DE60C.MemSssa)->column;
        next = clear + 4;
        if (dir == 1)
            g_021DE60C.FocusPos = next;
        else if (dir == 3)
            g_021DE60C.FocusPos = clear;
        else
            move = 0;
        break;
    case 4:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 0;
        if (dir == 0)
            g_021DE60C.FocusPos = 6;
        else if (dir == 2)
            g_021DE60C.FocusPos = 5;
        else if (dir == 1)
            g_021DE60C.FocusPos = 0;
        else
            g_021DE60C.FocusPos = 3;
        break;
    case 5:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 1;
        if (dir == 0)
            g_021DE60C.FocusPos = 4;
        else if (dir == 2)
            g_021DE60C.FocusPos = 6;
        else if (dir == 1)
            g_021DE60C.FocusPos = 1;
        else
            g_021DE60C.FocusPos = 3;
        break;
    case 6:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 2;
        if (dir == 0)
            g_021DE60C.FocusPos = 5;
        else if (dir == 2)
            g_021DE60C.FocusPos = 4;
        else if (dir == 1)
            g_021DE60C.FocusPos = 2;
        else
            g_021DE60C.FocusPos = 3;
        break;
    }
    if (move) {
        func_021CFFAC(8);
        func_021CC46C();
    }
}




static void dispPushClear(void)
{
    int fp = scenesetselectap_bss.FocusPos - 4;

    DWCi_CEINlSet(0, 0x32, DWCi_CELLlGetObj(scenesetselectap_bss.MemSssa->cellB[fp], 0));
    DWCi_CELLlSetPosition(scenesetselectap_bss.MemSssa->cellB[fp], -1, C_CELL[fp + 3].x, C_CELL[fp + 3].y);
    DWCi_CELLlSetPriority(scenesetselectap_bss.MemSssa->cellB[fp], -1, 3);
}




static void procErase1(void);




static void procErase(void)
{
    int ix;

    ix = g_021DE60C.FocusPos - 4;
    switch (DWCi_WINlGet()) {
    case 1:
        DWCi_SNDlPlay(14);
        DWCi_SETTINGlErasePage(ix);
        DWCi_CEINlSet(0, 0x56, DWCi_CELLlGetObj(g_021DE60C.MemSssa->a[ix], 0));
        DWCi_CELLlSetPosition(g_021DE60C.MemSssa->a[ix], -1, g_021DA72C[ix].x, g_021DA72E[ix].x);
        DWCi_CELLlSetPriority(g_021DE60C.MemSssa->a[ix], -1, 3);
        DWCi_CELLlDelete(g_021DE60C.MemSssa->b[ix]);
        g_021DE60C.MemSssa->b[ix] = 0;
        break;
    case 0:
        DWCi_SNDlPlay(7);
        DWCi_CEINlSet(0, 0x11, DWCi_CELLlGetObj(g_021DE60C.MemSssa->b[ix], 0));
        DWCi_CELLlSetPosition(g_021DE60C.MemSssa->b[ix], -1, g_021DA72C[ix + 3].x, g_021DA72E[ix + 3].x);
        DWCi_CELLlSetPriority(g_021DE60C.MemSssa->b[ix], -1, 3);
        break;
    default:
        return;
    }
    DWCi_WINlEnd();
    DWCi_ChangeScene(procErase1);
}




static void procScene(void);




static void procErase1(void)
{
    if (DWCi_WINlIsInit()) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}




static void dispPush(void)
{
    PLT4 PALETTE = g_021DA7B4;
    PLT4 OBJ_PLTT = g_021DA7B8;
    int type = scenesetselectap_bss.FocusPos;

    if ((unsigned int)type > 3) {
        return;
    }
    DWCi_SCREENlCopyPalette(scenesetselectap_bss.MemSssa->palette, PALETTE.v[type], PALETTE.v[type]);
    if (scenesetselectap_bss.FocusPos == 3) {
        return;
    }
    type = DWCi_SETTINGlGetSetType(scenesetselectap_bss.FocusPos);
    if (type > 2) {
        type = 3;
    }
    DWCi_CELLlSetPalette(scenesetselectap_bss.MemSssa->cellA[scenesetselectap_bss.FocusPos], -1, 0, OBJ_PLTT.v[type]);
}
