/*
 * file:     unit_021CCE04.c
 * unit:     yes
 * function: func_021CCE04, func_021CCE58, func_021CCE78, func_021CCEE4, func_021CD018, func_021CD108
 * address:  0x021CCE04
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
 *   func_021BCB14  0x021BCB14  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE614     0x021DE614  data
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   func_021D5790  0x021D5790  arm  ov016
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCAE4  0x021BCAE4  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021CCEE4  0x021CCEE4  arm  ov016
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_ARClRelease                 0x021D4C68  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_SetParam2_                  0x021C0E8C  arm
 *   DWCi_SetListReturn               0x021CA5C0  arm
 *   DWCi_SceneSetSelectAp            0x021CBC90  arm
 *   DWCi_SceneSetSearch              0x021CB780  arm
 *   DWCi_SceneSetAossButton          0x021C4904  arm
 *   DWCi_SceneSetRakuReady           0x021CB2E8  arm
 *   DWCi_SceneSetList                0x021C82FC  arm
 *   func_021C0EF0  0x021C0EF0  arm  ov016
 *   func_021BD4C8  0x021BD4C8  arm  ov016
 *   g_021DA7DF     0x021DA7DF  data
 *   g_021DA858     0x021DA858  data
 *   g_021DA85A     0x021DA85A  data
 *   g_021DA85C     0x021DA85C  data
 *   g_021DA85E     0x021DA85E  data
 *   func_021CE7B0  0x021CE7B0  arm  ov016
 *   g_021DA7D4     0x021DA7D4  data
 */
#include "../../matched/include/G_FocusState.h"

typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;

typedef _Bool bool;

typedef signed char s8;

typedef unsigned char u8;

typedef struct { unsigned short left, top, right, bottom; } Rect;

typedef struct { unsigned char b[4]; } Palette4;

extern signed char func_021BCB14(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021BCB9C(void);
extern int func_021D5790(int frame);
extern int func_021D5580(int lcd);
extern void func_021BCAE4(void);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021CCEE4(void);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_FOCUSlDelete(void);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_ARClRelease(void *file);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(int param0, int param1);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SetParam2_(int param2, int param3);
extern void DWCi_SetListReturn(int scene);
extern void DWCi_SceneSetSelectAp(void);
extern void DWCi_SceneSetSearch(void);
extern void DWCi_SceneSetAossButton(void);
extern void DWCi_SceneSetRakuReady(void);
extern void DWCi_SceneSetList(void);
extern int func_021C0EF0(unsigned long flag);
extern void func_021BD4C8(int x0, int x1, int y0, int y1);
extern void func_021CE7B0(void *src, int sColor, int dColor);
void func_021CCE04(void);
void func_021CCE58(void);
void func_021CCE78(void);
void func_021CD018(int dir);
void func_021CD108(void);
extern struct FocusState g_021DE614;
extern signed char g_021DA7DF[2][4][4];
extern Rect g_021DA858[2][4];
extern Palette4 g_021DA7D4;


/*
 * sdk:      button (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE04.c \n *       --func func_021CCE04 --addr 0x021CCE04 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CCE04(void)
{
    switch (func_021BCB14()) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(6);
        func_021CD108();
        g_021DE614.flag = 1;
        break;
    default:
        return;
    }
    func_021C0E40((unsigned int)func_021CCE58);
}


/*
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE58.c \n *       --func func_021CCE58 --addr 0x021CCE58 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CCE58(void)
{
    func_021BCB9C();
    func_021D5790(8);
    func_021C0E40((unsigned int)func_021CCE78);
}


/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE78.c \n *       --func func_021CCE78 --addr 0x021CCE78 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CCE78(void)
{
    if (func_021D5580(1))
        return;
    if (g_021DE614.flag)
        func_021BCAE4();
    func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 20, 8);
    func_021C0E40((unsigned int)func_021CCEE4);
}


static void endScene2(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_ARClRelease(g_021DE614.screen);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    if (g_021DE614.flag == 0) {
        DWCi_SetParam_(2, 0);
        DWCi_ChangeScene(DWCi_SceneSetSelectAp);
        return;
    }
    switch (g_021DE614.cur) {
    case 0:
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene(DWCi_SceneSetSearch);
        break;
    case 1:
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene(DWCi_SceneSetAossButton);
        break;
    case 2:
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene(DWCi_SceneSetRakuReady);
        break;
    case 3:
        DWCi_SetParam_(2, 0);
        DWCi_SetParam2_(0, 0);
        DWCi_SetListReturn(1);
        DWCi_ChangeScene(DWCi_SceneSetList);
        break;
    }
}


/*
 * sdk:      moveFocus (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD018.c \n *       --func func_021CD018 --addr 0x021CD018 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CD018(int dir)
{
    signed char prev = g_021DE614.cur;
    signed char next = g_021DA7DF[func_021C0EF0(1)][prev][dir];
    if (next == -1)
        return;
    if (next == 0)
        g_021DE614.last = prev;
    if (next == -2)
        g_021DE614.cur = g_021DE614.last;
    else
        g_021DE614.cur = next;
    func_021CFFAC(8);
    func_021BD4C8(g_021DA858[func_021C0EF0(1)][g_021DE614.cur].left,
                  g_021DA858[func_021C0EF0(1)][g_021DE614.cur].right,
                  g_021DA858[func_021C0EF0(1)][g_021DE614.cur].top,
                  g_021DA858[func_021C0EF0(1)][g_021DE614.cur].bottom);
}


/*
 * sdk:      dispPush (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD108.c \n *       --func func_021CD108 --addr 0x021CD108 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CD108(void)
{
    Palette4 palette = g_021DA7D4;
    func_021CE7B0(g_021DE614.screen, palette.b[g_021DE614.cur], palette.b[g_021DE614.cur]);
}
