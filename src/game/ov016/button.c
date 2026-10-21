/*
 * file:     button.c
 * unit:     yes
 * function: DWCi_BTNlInit, DWCi_BTNlEnd, DWCi_BTNlGet, DWCi_BTNlSet, DWCi_BTNlSetForce, DWCi_BTNlIsEnd, DWCi_BTNlEnable, DWCi_BTNlDisable, disp, taskStart, taskStart1, taskMain, DWCi_ButtonTaskEnd, taskEnd1, taskRelease
 * address:  0x021BC9E4
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
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_CEINlSetExCell  0x021D5394  arm  ov016
 *   DWCi_CELLlSetPriority  0x021D51F0  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   sButtonCountByKind  0x021DA008  data
 *   gButtonWork  0x021DE508  data
 *   sButtonCellIds  0x021DA018  data
 *   MemBtn                           0x021DE508  data
 *   DWCi_ButtonTaskEnd                          0x021BCE7C  arm
 *   DWCi_TSKlChangeFunc              0x021D771C  arm
 *   DWCi_CELLlSetPosition  0x021d5118  arm  ov016
 *   sButtonPositionIndex  0x021da026  data
 *   sButtonPositions  0x021da010  data
 *   DWCi_CELLlGetPosition  0x021d5250  arm  ov016
 *   DWCi_TSKlChangeFunc  0x021d771c  arm  ov016
 *   DWCi_Coord2Rect  0x021D600C  arm  ov016
 *   DWCi_TPlCheckTrigger  0x021D696C  arm  ov016
 *   DWCi_CELLlGetObj  0x021D4FE0  arm  ov016
 *   DWCi_CEINlSet  0x021D52D4  arm  ov016
 *   sButtonSize  0x021DA004  data
 *   DWCi_TSKlDelete  0x021d7724  arm  ov016
 *   DWCi_CELLlDelete  0x021d4f60  arm  ov016
 *   DWCi_HEAPlFree_  0x021d6438  arm  ov016
 *   gMemButton  0x021DE508  data
 */
struct tagMEMBTN {
    void *cellButton[2];
    void *cellBack;
    void *task;
    void *release;
    unsigned short count;
    signed char input;
    unsigned char kind;
    unsigned char disable;
    unsigned char end;
};

struct tagCOORD;
struct tagRECT;
struct MEMBTN {
    char pad[0xc];
    int task;
    char pad2[9];
    unsigned char ended;
};

typedef _Bool bool;

#include "dwcutil_types.h"

typedef struct { unsigned short l, t, r, b; } Rect;

typedef struct { unsigned short x, y; } Coord;

#include "../types.h"

typedef struct tagMEMBTN MEMBTN;

#include "heap.h"
extern void *DWCi_CEINlSetExCell(s32 lcd, s32 idx, bool head);
#include "cell.h"
struct TCB;
#include "task.h"
#include "foundation.h"
#include "input.h"
struct CellInfo;
union GXOamAttr;
#include "cellinfo.h"
struct CellInfo;
void DWCi_BTNlInit(int kind);
void DWCi_BTNlEnd(void);
signed char DWCi_BTNlGet(void);
void DWCi_BTNlSet(signed char v);
void DWCi_BTNlSetForce(int a);
int DWCi_BTNlIsEnd(void);
void DWCi_BTNlEnable(void);
void DWCi_BTNlDisable(void);
extern unsigned char sButtonCountByKind[7];
extern struct tagMEMBTN *gButtonWork;
extern unsigned char sButtonCellIds[7][2];
extern struct MEMBTN *MemBtn;
extern const unsigned char sButtonPositionIndex[][2];
extern const COORD sButtonPositions[];
extern Coord sButtonSize;
extern struct tagMEMBTN *gMemButton;

/*
 * sdk:      DWCi_BTNlInit (libdwcutil.TWL.HYB.a button.o)
 */

static void disp(int y);
static void taskStart(void *task);
static void taskStart1(void *task);
static void taskMain(void);
static void DWCi_ButtonTaskEnd(void *task);
static void taskEnd1(void *task);
static void taskRelease(void *task);
void DWCi_BTNlInit(int kind)
{
    int btnNum;
    int i;

    btnNum = sButtonCountByKind[kind];
    gButtonWork = DWCi_HEAPlAllocEx(0x1c, 4);
    gButtonWork->input = -2;
    gButtonWork->kind = kind;
    for (i = 0; i < btnNum; i++) {
        gButtonWork->cellButton[i] = DWCi_CEINlSetExCell(0, sButtonCellIds[kind][i], 1);
        DWCi_CELLlSetPriority(gButtonWork->cellButton[i], -1, 1);
    }
    gButtonWork->cellBack = DWCi_CEINlSetExCell(0, 1, 1);
    DWCi_CELLlSetPriority(gButtonWork->cellBack, -1, 1);
    disp(0xc0);
    gButtonWork->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskStart, 0, 0x78);
}

void DWCi_BTNlEnd(void)
{
    MemBtn->ended = 1;
    DWCi_TSKlChangeFunc((TCB *)MemBtn->task, (void (*)(void *, void *))DWCi_ButtonTaskEnd);
}

signed char DWCi_BTNlGet(void)
{
    return *(signed char *)(*(char **)0x021DE508 + 0x16);
}

void DWCi_BTNlSet(signed char v)
{
    unsigned char *p = *(unsigned char **)0x021DE508;

    if (*(signed char *)(p + 0x16) == -1)
        *(signed char *)(p + 0x16) = v;
}

void DWCi_BTNlSetForce(int a)
{
    *(unsigned char *)(*(char **)0x021DE508 + 0x16) = a;
}

int DWCi_BTNlIsEnd(void)
{
    unsigned char *p = *(unsigned char **)0x021DE508;

    if (p == 0)
        return 1;
    if (p[0x19] == 0)
        return 1;
    return 0;
}

/*
 * Clear the byte at +0x18 of the object behind the global pointer at 0x021DE508.
 * Addresses are Black-image addresses.
 */
void DWCi_BTNlEnable(void)
{
    *(unsigned char *)(*(char **)0x021DE508 + 0x18) = 0;
}

void DWCi_BTNlDisable(void)
{
    *(unsigned char *)(*(char **)0x021DE508 + 0x18) = 1;
}

static void disp(int y)
{
    int btnNum;
    int cy;
    int i;

    btnNum = sButtonCountByKind[gButtonWork->kind];
    DWCi_CELLlSetPosition(gButtonWork->cellBack, -1, 0, y);
    for (i = 0; i < btnNum; i++) {
        DWCi_CELLlSetPosition(gButtonWork->cellButton[i], -1, sButtonPositions[sButtonPositionIndex[gButtonWork->kind][i]].x, y + 4);
    }
}

/*
 * sdk:      taskStart (libdwcutil.TWL.HYB.a(button.o))
 */
static void taskStart(void *task)
{
    int x, y;

    DWCi_CELLlGetPosition(gButtonWork->cellBack, 0, &x, &y);
    y -= 4;
    disp(y);
    if (y > 168)
        return;
    disp(168);
    DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskStart1);
}

/*
 * sdk:      taskStart1 (libdwcutil.TWL.HYB.a(button.o))
 */
static void taskStart1(void *task)
{
    gButtonWork->input = -1;
    gButtonWork->count++;
    if (gButtonWork->count >= 4) {
        gButtonWork->count = 0;
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskMain);
    }
}

static void taskMain(void)
{
    Rect r;
    int btnNum;
    int i;

    btnNum = sButtonCountByKind[gButtonWork->kind];
    if (!gButtonWork->disable) {
        if (gButtonWork->input != -1)
            return;
        for (i = 0; i < btnNum; i++) {
            DWCi_Coord2Rect((const struct tagCOORD *)(&sButtonPositions[sButtonPositionIndex[gButtonWork->kind][i]]), (const struct tagCOORD *)(&sButtonSize), (struct tagRECT *)(&r));
            if (DWCi_TPlCheckTrigger((u16 *)(&r))) {
                if (gButtonWork->release)
                    break;
                {
                    int cellIdx = sButtonCellIds[gButtonWork->kind][i];
                    DWCi_CEINlSet(0, cellIdx + 1, DWCi_CELLlGetObj(gButtonWork->cellButton[i], 0));
                }
                DWCi_CELLlSetPosition(gButtonWork->cellButton[i], -1,
                              sButtonPositions[sButtonPositionIndex[gButtonWork->kind][i]].x,
                              sButtonPositions[sButtonPositionIndex[gButtonWork->kind][i]].y);
                DWCi_CELLlSetPriority(gButtonWork->cellButton[i], -1, 1);
                gButtonWork->release = DWCi_TSKlForm(0, (void (*)(void *, void *))taskRelease, 0, 0x6e);
                gButtonWork->input = i;
                return;
            }
        }
    }
    gButtonWork->input = -1;
}

static void DWCi_ButtonTaskEnd(void *task)
{
    int x, y;

    DWCi_CELLlGetPosition(gButtonWork->cellBack, 0, &x, &y);
    y += 4;
    disp(y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskEnd1);
}

/*
 * sdk:      taskEnd1 (libdwcutil.TWL.HYB.a(button.o))
 */
static void taskEnd1(void *task)
{
    int i;

    DWCi_TSKlDelete(0, task);
    if (gButtonWork->release)
        DWCi_TSKlDelete(0, gButtonWork->release);
    for (i = 0; i < 2; i++) {
        if (gButtonWork->cellButton[i])
            DWCi_CELLlDelete(gButtonWork->cellButton[i]);
    }
    DWCi_CELLlDelete(gButtonWork->cellBack);
    DWCi_HEAPlFree_((void **)&gMemButton);
}

/*
 * sdk:      taskRelease (libdwcutil.TWL.HYB.a(button.o))
 */
static void taskRelease(void *task)
{
    int btnNum;
    int i;

    gButtonWork->count++;
    if (gButtonWork->count < 16)
        return;
    btnNum = sButtonCountByKind[gButtonWork->kind];
    for (i = 0; i < btnNum; i++) {
        {
            int idx = sButtonCellIds[gButtonWork->kind][i];
            DWCi_CEINlSet(0, idx, DWCi_CELLlGetObj(gButtonWork->cellButton[i], 0));
        }
        DWCi_CELLlSetPriority(gButtonWork->cellButton[i], -1, 1);
    }
    disp(168);
    gButtonWork->count = 0;
    gButtonWork->input = -1;
    if (gButtonWork->release) {
        gButtonWork->release = 0;
        DWCi_TSKlDelete(0, task);
    }
}
