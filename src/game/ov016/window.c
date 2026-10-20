/*
 * file:     window.c
 * unit:     yes
 * function: DWCi_WINlInitEx, DWCi_WINlEnd, DWCi_WINlGet, DWCi_WINlIsInit, taskV, taskMove, taskMain, taskMain1, disp, dispCell, pushButton, taskEnd, taskEnd1, taskEnd2, taskEnd3
 * address:  0x021D1208
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
 *   DWCi_MSGlGetEx                   0x021c1048 arm
 *   DWCi_HEAPlAllocEx                0x021d6414 arm
 *   G2x_SetBlendBrightness_          0x0207d658 arm
 *   DWCi_CEINlSetExCell              0x021d5394 arm
 *   DWCi_CELLlSetPosition            0x021d5118 arm
 *   DWCi_CELLlSetPriority            0x021d51f0 arm
 *   DWCi_FNTlFormEx                  0x021d5950 arm
 *   DWCi_CELLlForm                   0x021d4e1c arm
 *   DWCi_CMNlFontFlag                0x021bd3cc arm
 *   DWCi_FNTlDrawRect                0x021d5e5c arm
 *   DWCi_FNTlDisp                    0x021d5f28 arm
 *   DWCi_GXlSetWndPlane              0x021d61f4 arm
 *   DWCi_GXlSetWndPosition           0x021d60ec arm
 *   disp                             0x021d1868 arm
 *   DWCi_TSKlForm                    0x021d7680 arm
 *   sWindowTable15                       0x021daa58 data
 *   gCommentWork                       0x021de598 data
 *   gWindowWork                       0x021de658 data
 *   sWindowTable1                       0x021da9a0 data
 *   sWindowTable2                       0x021da9a6 data
 *   sWindowTable7                       0x021da9c8 data
 *   sWindowTable9                       0x021da9e6 data
 *   sWindowTable10                       0x021da9e8 data
 *   sWindowTable3                       0x021da9ac data
 *   taskV                            0x021d1598 arm  ov016
 *   taskMove                         0x021d15f0 arm  ov016
 *   DWCi_TSKlDelete   0x021D7724 arm
 *   MemWin            0x021DE658 data
 *   DWCi_WindowG2x_ChangeBlendBrightness_  0x0207D6C0  arm
 *   DWCi_TSKlChangeFunc  0x021D771C  arm  ov016
 *   DWCi_CELLlGetPosition  0x021D5250  arm  ov016
 *   sWindowTable11     0x021DA9FE  data
 *   DWCi_Coord2Rect  0x021D600C  arm  ov016
 *   DWCi_TPlCheckTrigger  0x021D696C  arm  ov016
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm  ov016
 *   sWindowTable14  0x021DAA2E  data
 *   sWindowTable4  0x021DA9B4  data
 *   sWindowTable8  0x021DA9D2  data
 *   sWindowTable5  0x021DA9BE  data
 *   sWindowTable6  0x021DA9BF  data
 *   DWCi_InputRect  0x021D5FF4  arm  ov016
 *   sWindowTable13  0x021DAA18  data
 *   sWindowTable12  0x021DAA16  data
 *   DWCi_CELLlGetState  0x021D4FEC  arm  ov016
 *   DWCi_CELLlSetEffect  0x021D4FF4  arm  ov016
 *   DWCi_CELLlGetObj  0x021D4FE0  arm  ov016
 *   DWCi_CEINlSet  0x021D52D4  arm  ov016
 *   DWCi_TSKlChangeFunc 0x021D771C arm
 *   taskEnd1           0x021D1B78 arm
 *   DWCi_CELLlDelete  0x021D4F60  arm  ov016
 *   DWCi_FNTlDelete  0x021D5A2C  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gMemWindow   0x021DE658  data
 */
#include "../../matched/include/G_MemWinT.h"
#include "../sdk_ioreg.h"
#include "../../matched/include/G_CoordT.h"

struct tagCOORD;
struct tagRECT;
#include "../types.h"

typedef unsigned char bool;

typedef struct {
    void *cellWin;
    void *cellChar;
    void *button[2];
    void *canv;
    void *task;
    u16 countWait;
    signed char count;
    signed char input;
    u8 type;
    u8 wait;
    u8 dark;
} MemWinT;

struct tagMEMWIN {
    char pad[0x14];
    void *task;                  /* 0x14 */
    char pad2[0x1d - 0x18];
    unsigned char count;         /* 0x1d */
};

typedef struct { u16 x; u16 y; } CoordT;

typedef struct {
    u16 l, t, r, b;
} RectT;

typedef enum {
    EFF_NONE = 0,
    EFF_HIDE = 0x200
} Eff;

#include "message.h"
#include "heap.h"
#include "../arm9/g2.h"
extern void *DWCi_CEINlSetExCell(int lcd, int idx, bool head);
#include "cell.h"
typedef int bool_0;
#include "font.h"
#include "common.h"
#include "graphics.h"
struct tagRect;
struct TCB;
#include "task.h"
#include "foundation.h"
#include "input.h"
struct CellInfo;
union GXOamAttr;
#include "cellinfo.h"
struct Canvas;
void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
void DWCi_WINlEnd(void);
signed char DWCi_WINlGet(void);
int DWCi_WINlIsInit(void);
void taskEnd(void *task, void *work);
extern u8 sWindowTable15[6];
extern void *gCommentWork;
extern struct MemWinT *gWindowWork;
extern const u8 sWindowTable1[6];
extern const u8 sWindowTable2[6];
extern const u8 sWindowTable7[][2];
extern u16 sWindowTable9[];
extern u16 sWindowTable10[];
extern u16 sWindowTable3[4];
extern struct tagMEMWIN *MemWin;
extern struct CoordT sWindowTable11[];
extern struct CoordT sWindowTable14[][2];
extern u8 sWindowTable4[][2];
extern CoordT sWindowTable8[];
extern signed char sWindowTable5[][2];
extern signed char sWindowTable6[][2];
extern u16 sWindowTable13[][2];
extern u16 sWindowTable12[][2];
extern struct MemWinT *gMemWindow;

/*
 * closed (2026-10-01, wave 3 lane08): draft semantics were wrong in the
 *           button loop.  The image's r7 is a hoisted constant 0 copied from
 *           i at entry, so the loop calls are (0, CELL_BUTTON[type][i], 0),
 *           (.., -1, 0x100, 0), (.., -1, 0); and the bound BUTTON_NUM[type]
 *           is read once, so the tables are const (extern const).  With the
 *           real loop pressure, ms and dark spill on their own exactly as
 *           DWARF says ([fb+20], [fb+16]); the volatile `d` stand-in is gone.
 *
 * sdk:      DWCi_WINlInitEx (libdwcutil.TWL.HYB.a window.o)
 */

static void taskV(void *task);
static void taskMove(void *task);
static void taskMain(void *task, void *work);
static void taskMain1(void *task, void *work);
static void disp(int y);
static void dispCell(void *cell, int y);
static void pushButton(int idx);
static void taskEnd1(void *task);
static void taskEnd2(void *task);
static void taskEnd3(void *task);
void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num)
{
    u8 EFF[6];
    int obj;
    int i;
    u16 *ms;

    EFF[0] = sWindowTable15[0];
    EFF[1] = sWindowTable15[1];
    EFF[2] = sWindowTable15[2];
    EFF[3] = sWindowTable15[3];
    EFF[4] = sWindowTable15[4];
    EFF[5] = sWindowTable15[5];

    ms = DWCi_MSGlGetEx(gCommentWork, msg, n, num);
    gWindowWork = (struct MemWinT *)((MemWinT *)DWCi_HEAPlAllocEx(0x20, 4));
    gWindowWork->type = type;
    gWindowWork->input = -2;
    gWindowWork->dark = dark;
    G2x_SetBlendBrightness_(REG_BLDCNT_ADDR, 0x1f, 0);

    gWindowWork->cellWin = DWCi_CEINlSetExCell(0, sWindowTable1[type], 0);
    DWCi_CELLlSetPosition(gWindowWork->cellWin, -1, 0x100, 0);
    DWCi_CELLlSetPriority(gWindowWork->cellWin, -1, 0);

    for (i = 0; i < sWindowTable2[type]; i++) {
        gWindowWork->button[i] = DWCi_CEINlSetExCell(0, sWindowTable7[type][i], 0);
        DWCi_CELLlSetPosition(gWindowWork->button[i], -1, 0x100, 0);
        DWCi_CELLlSetPriority(gWindowWork->button[i], -1, 0);
    }

    gWindowWork->canv = DWCi_FNTlFormEx(0, 0x20, 0xc, 1, &obj, 0);
    gWindowWork->cellChar = DWCi_CELLlForm(0, obj, 0);
    DWCi_FNTlDrawRect(gWindowWork->canv, 0, 0, sWindowTable9[type * 2], sWindowTable10[type * 2], 2, DWCi_CMNlFontFlag(), ms);
    DWCi_FNTlDisp(gWindowWork->canv, 0x100, 0, gWindowWork->cellChar, 0);

    DWCi_GXlSetWndPlane(0, 0, 0x1f, 0);
    DWCi_GXlSetWndPlane(0, 1, 0x1f, EFF[gWindowWork->type]);
    DWCi_GXlSetWndPlane(0, 3, 0x1f, 1);
    DWCi_GXlSetWndPosition(0, 1, (struct tagRect *)sWindowTable3);

    disp(0xc0);
    *(volatile unsigned long *)0x04000000 = (*(volatile unsigned long *)0x04000000 & ~0xE000) | 0x6000;

    if (dark)
        gWindowWork->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskV, 0, 0x78);
    else
        gWindowWork->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskMove, 0, 0x78);
}

void DWCi_WINlEnd(void)
{
    DWCi_TSKlDelete(0, MemWin->task);
    MemWin->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskEnd, 0, 0x78);
}

/*
 * Signed byte at +0x1b of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_WINlGet.c \
 *       --func DWCi_WINlGet --addr 0x021D1568 --region ov016 --cc dsi/1.1p1 --arm
 */
signed char DWCi_WINlGet(void)
{
    return *(signed char *)(*(char **)0x021DE658 + 0x1b);
}

/*
 * True when the global pointer at 0x021DE658 is non-null.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_WINlIsInit.c \
 *       --func DWCi_WINlIsInit --addr 0x021D157C --region ov016 --cc dsi/1.1p1 --arm
 */
int DWCi_WINlIsInit(void)
{
    return *(void **)0x021DE658 != 0;
}

/*
 * sdk:      taskV (libdwcutil.TWL.HYB.a window.o)
 */
static void taskV(void *task)
{
    gWindowWork->count--;
    DWCi_WindowG2x_ChangeBlendBrightness_(REG_BLDCNT_ADDR, gWindowWork->count);
    if (gWindowWork->count > -12)
        return;
    DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskMove);
}

/*
 * 2026-10-01: closed with the DWARF prototypes (DWCi_TSKlForm takes a
 * `void (*)(void *, void *)`, `void *` work and u8 prio; taskMain is
 * `void (void)`), C_WIN as a CoordT[] at 0x021DA9FE read via `.y` (the
 * C_WIN+0x2 reloc), and the TSKlForm call written in each arm of an if/else
 * with casts. The held zero in r4 and the branchy select both follow.
 *
 * sdk:      taskMove (libdwcutil.TWL.HYB.a window.o)
 *
 * T6: 184 B vs 192. The object branches on the type test (`cmp r0,#5 /
 * bne / ldr r1,[pc,A] / b / ldr r1,[pc,B]`) while this build if-converts the
 * function-pointer select (`movne r1,...`), and that branch is the missing
 * 8 bytes; the object also keeps the 0 constant in r4 (needed across the
 * GetPosition call) where this build rematerialises immediates. Tried the
 * select as a `void (*fn)(void *)` local via ternary and via if/else in both
 * senses, as `void *` and as `unsigned long` with a cast at the call, as a
 * leading `fn = B` plus one if, as a switch, and with the call duplicated in
 * each arm: every spelling re-folds to 180 B, and no pin/flag cell matches.
 * U26: the object's `mov r4,#0` is the constant 0 held in a callee-saved register across the
 * DWCi_CELLlGetPosition call (it is `mov r1,r4` for the idx argument and `mov r0,r4`/`mov r2,r4` for the
 * two zero arguments of DWCi_TSKlForm).  Spelling that zero as a live local (`int z = 0;`, `z`
 * for all three) is folded straight back to immediate 0 by 1.1p1 - same 184 B / 130 diffs - so
 * the difference is mwcc 4.0.0.1025's rematerialisation policy, not a source shape.  Referencing
 * the same 0 through a helper or a cast does not survive either.
 */
static void taskMove(void *task)
{
    int x;
    int y;

    DWCi_CELLlGetPosition(gWindowWork->cellWin, 0, &x, &y);
    y -= 12;
    if (y > sWindowTable11[gWindowWork->type].y) {
        disp(y);
        return;
    }
    disp(sWindowTable11[gWindowWork->type].y);
    if (gWindowWork->type == 5)
        gWindowWork->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskMain1, 0, 0x78);
    else
        gWindowWork->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskMain, 0, 0x78);
    DWCi_TSKlDelete(1, task);
}

/*
 * sdk:      taskMain (libdwcutil.TWL.HYB.a window.o)
 */
static void taskMain(void *task, void *work)
{
    RectT r;
    int i;

    for (i = 0; i < sWindowTable2[gWindowWork->type]; i++) {
        DWCi_Coord2Rect((const struct tagCOORD *)(&sWindowTable14[gWindowWork->type][sWindowTable4[gWindowWork->type][i]]),
                      (const struct tagCOORD *)(&sWindowTable8[gWindowWork->type]), (struct tagRECT *)(&r));
        if (DWCi_TPlCheckTrigger((u16 *)(&r))) {
            gWindowWork->input = i;
            break;
        }
    }
    if (DWCi_IPTlCheckTrigger(1))
        gWindowWork->input = sWindowTable5[gWindowWork->type][0];
    if (DWCi_IPTlCheckTrigger(2))
        gWindowWork->input = sWindowTable6[gWindowWork->type][0];
    for (i = 0; i < sWindowTable2[gWindowWork->type]; i++) {
        if (i == gWindowWork->input) {
            pushButton(i);
            return;
        }
    }
    gWindowWork->input = -1;
}

/*
 * sdk:      taskMain1 (libdwcutil.TWL.HYB.a window.o)
 */
static void taskMain1(void *task, void *work)
{
    gWindowWork->input = -1;
    gWindowWork->countWait++;
    if (gWindowWork->countWait < 0x78)
        return;
    DWCi_TSKlDelete(0, task);
    gWindowWork->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskEnd, 0, 0x78);
}

/*
 * sdk:      disp (libdwcutil.TWL.HYB.a window.o)
 *
 * The two u16 screen-x lookups are hoisted into named locals before the y1
 * clamp: spelled inline the 1.1p1 scheduler issues the &r add and the clamp
 * cmp ahead of the pair of ldrh, giving 10 reordered instructions at +0128.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021D1868.c \n *       --func disp --addr 0x021D1868 --region ov016 --arm --cc 1.1p1 --lang c99
 */
static void disp(int y)
{
    RectT r;
    int y0;
    int y1;
    int i;
    u16 x1, x2;

    DWCi_CELLlSetPosition(gWindowWork->cellWin, -1, sWindowTable11[gWindowWork->type].x, y);
    DWCi_CELLlSetPosition(gWindowWork->cellChar, -1, sWindowTable11[gWindowWork->type].x + 8, y + 8);
    dispCell(gWindowWork->cellWin, y);
    dispCell(gWindowWork->cellChar, y);
    for (i = 0; i < sWindowTable2[gWindowWork->type]; i++) {
        int idx = sWindowTable4[gWindowWork->type][i];
        DWCi_CELLlSetPosition(gWindowWork->button[i], -1,
                      sWindowTable14[gWindowWork->type][idx].x,
                      y + sWindowTable14[gWindowWork->type][idx].y - sWindowTable11[gWindowWork->type].y);
        dispCell(gWindowWork->button[i], y);
    }
    y0 = (u8)y;
    if (y0 >= 0xc0) {
        y1 = 0;
        y0 = y1;
    } else {
        y1 = y0 + sWindowTable13[gWindowWork->type][0];
    }
    x1 = sWindowTable11[gWindowWork->type].x;
    x2 = sWindowTable12[gWindowWork->type][0];
    if (y1 > 0xc0)
        y1 = 0xc0;
    DWCi_InputRect(x1, y0, x1 + x2, y1, (u16 *)&r);
    DWCi_GXlSetWndPosition(0, 0, (struct tagRect *)&r);
}

/*
 * sdk:      dispCell (libdwcutil.TWL.HYB.a window.o)
 */
static void dispCell(void *cell, int y)
{
    Eff eff;
    int num;
    int x;
    int cy;
    int i;

    num = DWCi_CELLlGetState(cell);
    for (i = 0; i < num; i++) {
        DWCi_CELLlGetPosition(cell, i, &x, &cy);
        if (cy >= y && cy < 192)
            eff = EFF_NONE;
        else
            eff = EFF_HIDE;
        DWCi_CELLlSetEffect(cell, i, eff, 0);
    }
}

/*
 * sdk:      pushButton (libdwcutil.TWL.HYB.a window.o)
 */
static void pushButton(int idx)
{
    void *obj;

    obj = DWCi_CELLlGetObj(gWindowWork->button[idx], 0);
    DWCi_CEINlSet(0, sWindowTable7[gWindowWork->type][idx] + 1, obj);
    DWCi_CELLlSetPosition(gWindowWork->button[idx], -1,
                  sWindowTable14[gWindowWork->type][sWindowTable4[gWindowWork->type][idx]].x,
                  sWindowTable14[gWindowWork->type][sWindowTable4[gWindowWork->type][idx]].y);
    DWCi_CELLlSetPriority(gWindowWork->button[idx], -1, 0);
}

void taskEnd(void *task, void *work)
{
    MemWin->count++;
    if (MemWin->count < 8)
        return;
    DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskEnd1);
}

/*
 * sdk:      taskEnd1 (libdwcutil.TWL.HYB.a window.o)
 */
static void taskEnd1(void *task)
{
    int x;
    int y;

    DWCi_CELLlGetPosition(gWindowWork->cellWin, 0, &x, &y);
    y += 12;
    disp(y);
    if (y < 192)
        return;
    if (gWindowWork->dark != 0)
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskEnd2);
    else
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskEnd3);
}

/*
 * sdk:      taskEnd2 (libdwcutil.TWL.HYB.a window.o)
 */
static void taskEnd2(void *task)
{
    gWindowWork->count++;
    DWCi_WindowG2x_ChangeBlendBrightness_(REG_BLDCNT_ADDR, gWindowWork->count);
    if (gWindowWork->count < 0)
        return;
    DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskEnd3);
}

/*
 * sdk:      taskEnd3 (libdwcutil.TWL.HYB.a window.o)
 */
static void taskEnd3(void *task)
{
    int i;

    *(volatile unsigned int *)0x04000000 &= ~0xE000;
    DWCi_CELLlDelete(gWindowWork->cellWin);
    DWCi_CELLlDelete(gWindowWork->cellChar);
    for (i = 0; i < sWindowTable2[gWindowWork->type]; i++) {
        if (gWindowWork->button[i] != 0)
            DWCi_CELLlDelete(gWindowWork->button[i]);
    }
    DWCi_FNTlDelete(gWindowWork->canv);
    DWCi_TSKlDelete(1, task);
    DWCi_HEAPlFree_((void **)(&gMemWindow));
}
