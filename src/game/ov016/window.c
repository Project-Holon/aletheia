/*
 * file:     window.c
 * unit:     yes
 * function: func_021D1208, func_021D1524, func_021D1568, func_021D157C, func_021D1598, func_021D15F0, func_021D16B0, func_021D17FC, func_021D1868, func_021D19F4, func_021D1A80, func_021D1B3C, func_021D1B78, func_021D1C04, func_021D1C5C
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
 *   g_021DAA58                       0x021daa58 data
 *   g_021DE598                       0x021de598 data
 *   g_021DE658                       0x021de658 data
 *   g_021DA9A0                       0x021da9a0 data
 *   g_021DA9A6                       0x021da9a6 data
 *   g_021DA9C8                       0x021da9c8 data
 *   g_021DA9E6                       0x021da9e6 data
 *   g_021DA9E8                       0x021da9e8 data
 *   g_021DA9AC                       0x021da9ac data
 *   taskV                            0x021d1598 arm  ov016
 *   taskMove                         0x021d15f0 arm  ov016
 *   DWCi_TSKlDelete   0x021D7724 arm
 *   MemWin            0x021DE658 data
 *   func_0207D6C0  0x0207D6C0  arm
 *   DWCi_TSKlSetParam  0x021D771C  arm  ov016
 *   func_021D5250  0x021D5250  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021D7724  0x021D7724  arm  ov016
 *   g_021DA9FE     0x021DA9FE  data
 *   func_021D600C  0x021D600C  arm  ov016
 *   func_021D696C  0x021D696C  arm  ov016
 *   func_021D6824  0x021D6824  arm  ov016
 *   g_021DAA2E  0x021DAA2E  data
 *   g_021DA9B4  0x021DA9B4  data
 *   g_021DA9D2  0x021DA9D2  data
 *   g_021DA9BE  0x021DA9BE  data
 *   g_021DA9BF  0x021DA9BF  data
 *   func_021D5118  0x021D5118  arm  ov016
 *   func_021D5FF4  0x021D5FF4  arm  ov016
 *   func_021D60EC  0x021D60EC  arm  ov016
 *   g_021DAA18  0x021DAA18  data
 *   g_021DAA16  0x021DAA16  data
 *   DWCi_CELLlGetState  0x021D4FEC  arm  ov016
 *   func_021D4FF4  0x021D4FF4  arm  ov016
 *   func_021D4FE0  0x021D4FE0  arm  ov016
 *   func_021D52D4  0x021D52D4  arm  ov016
 *   func_021D51F0  0x021D51F0  arm  ov016
 *   DWCi_TSKlChangeFunc 0x021D771C arm
 *   taskEnd1           0x021D1B78 arm
 *   func_021D4F60  0x021D4F60  arm  ov016
 *   func_021D5A2C  0x021D5A2C  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE658_b   0x021DE658  data
 */
#include "../../matched/include/G_MemWinT.h"
#include "../../matched/include/G_CoordT.h"
#include "../../matched/include/G_021DAA2E.h"

struct tagCOORD;
struct tagRECT;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32_021D1208;

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

typedef unsigned int   u32_021D1598;

typedef struct { u16 x; u16 y; } CoordT;

typedef struct {
    u16 l, t, r, b;
} RectT;

typedef enum {
    EFF_NONE = 0,
    EFF_HIDE = 0x200
} Eff;

typedef unsigned int   u32;

extern u16 *DWCi_MSGlGetEx(void *msg, int id, int n, int num);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void G2x_SetBlendBrightness_(unsigned long addr, int plane, int brightness);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, bool head);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void *DWCi_FNTlFormEx(int lcd, int width, int height, bool head, int *obj, int font);
extern void *DWCi_CELLlForm(int lcd, int num, bool head);
extern unsigned long DWCi_CMNlFontFlag(void);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, u16 *txt);
extern void DWCi_FNTlDisp(void *canvas, int x, int y, void *cell, int prio);
extern void DWCi_GXlSetWndPlane(int lcd, int wnd, int plane, bool effect);
extern void DWCi_GXlSetWndPosition(int lcd, int wnd, void *r);
extern void disp(int y);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void taskV(void *task);
extern void taskMove(void *task);
void DWCi_TSKlDelete(int kind, void *task);
extern void func_0207D6C0(u32_021D1598 addr, int brightness);
extern void DWCi_TSKlSetParam(char *p, unsigned int v);
extern void func_021D5250(void *cell, int idx, int *x, int *y);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021D7724(int kind, void *task);
extern void func_021D600C(const struct tagCOORD *coord, const struct tagCOORD *size, struct tagRECT *rect);
extern int func_021D696C(u16 *a);
extern int func_021D6824(unsigned int f);
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D5FF4(int x0, int y0, int x1, int y1, RectT *r);
extern void func_021D60EC(int a, int b, RectT *r);
extern unsigned char DWCi_CELLlGetState(char *p);
extern void func_021D4FF4(void *cell, int idx, Eff eff, int affine);
extern char *func_021D4FE0(char *p, unsigned int i);
extern void func_021D52D4();
extern void func_021D51F0(void *cell, int idx, int priority);
void taskEnd1(void *task);
void DWCi_TSKlChangeFunc(void *task, void (*func)(void *));
extern void func_021D4F60(u8 *p);
extern void func_021D5A2C(char *a);
extern void func_021D6438(void **mem);
void func_021D1208(int msg, int type, bool dark, int n, int num);
void DWCi_WINlEnd(void);
signed char func_021D1568(void);
int func_021D157C(void);
void func_021D1598(void *task);
void func_021D15F0(void *task);
void func_021D16B0(void *task, void *work);
void func_021D17FC(void *task, void *work);
void func_021D1868(int y);
void func_021D19F4(void *cell, int y);
void func_021D1A80(int idx);
void taskEnd(void *task, void *work);
void func_021D1B78(void *task);
void func_021D1C04(void *task);
void func_021D1C5C(void *task);
extern u8 g_021DAA58[6];
extern void *g_021DE598;
extern struct MemWinT *g_021DE658;
extern const u8 g_021DA9A0[6];
extern const u8 g_021DA9A6[6];
extern const u8 g_021DA9C8[][2];
extern u16 g_021DA9E6[];
extern u16 g_021DA9E8[];
extern u16 g_021DA9AC[4];
extern struct tagMEMWIN *MemWin;
extern struct CoordT g_021DA9FE[];
extern struct G_021DAA2E g_021DAA2E[][2];
extern u8 g_021DA9B4[][2];
extern CoordT g_021DA9D2[];
extern signed char g_021DA9BE[][2];
extern signed char g_021DA9BF[][2];
extern u16 g_021DAA18[][2];
extern u16 g_021DAA16[][2];
extern struct MemWinT *g_021DE658_b;




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
void func_021D1208(int msg, int type, bool dark, int n, int num)
{
    u8 EFF[6];
    int obj;
    int i;
    u16 *ms;

    EFF[0] = g_021DAA58[0];
    EFF[1] = g_021DAA58[1];
    EFF[2] = g_021DAA58[2];
    EFF[3] = g_021DAA58[3];
    EFF[4] = g_021DAA58[4];
    EFF[5] = g_021DAA58[5];

    ms = DWCi_MSGlGetEx(g_021DE598, msg, n, num);
    g_021DE658 = (struct MemWinT *)((MemWinT *)DWCi_HEAPlAllocEx(0x20, 4));
    g_021DE658->type = type;
    g_021DE658->input = -2;
    g_021DE658->dark = dark;
    G2x_SetBlendBrightness_(0x04000050, 0x1f, 0);

    g_021DE658->cellWin = DWCi_CEINlSetExCell(0, g_021DA9A0[type], 0);
    DWCi_CELLlSetPosition(g_021DE658->cellWin, -1, 0x100, 0);
    DWCi_CELLlSetPriority(g_021DE658->cellWin, -1, 0);

    for (i = 0; i < g_021DA9A6[type]; i++) {
        g_021DE658->button[i] = DWCi_CEINlSetExCell(0, g_021DA9C8[type][i], 0);
        DWCi_CELLlSetPosition(g_021DE658->button[i], -1, 0x100, 0);
        DWCi_CELLlSetPriority(g_021DE658->button[i], -1, 0);
    }

    g_021DE658->canv = DWCi_FNTlFormEx(0, 0x20, 0xc, 1, &obj, 0);
    g_021DE658->cellChar = DWCi_CELLlForm(0, obj, 0);
    DWCi_FNTlDrawRect(g_021DE658->canv, 0, 0, g_021DA9E6[type * 2], g_021DA9E8[type * 2], 2, DWCi_CMNlFontFlag(), ms);
    DWCi_FNTlDisp(g_021DE658->canv, 0x100, 0, g_021DE658->cellChar, 0);

    DWCi_GXlSetWndPlane(0, 0, 0x1f, 0);
    DWCi_GXlSetWndPlane(0, 1, 0x1f, EFF[g_021DE658->type]);
    DWCi_GXlSetWndPlane(0, 3, 0x1f, 1);
    DWCi_GXlSetWndPosition(0, 1, g_021DA9AC);

    disp(0xc0);
    *(volatile u32_021D1208 *)0x04000000 = (*(volatile u32_021D1208 *)0x04000000 & ~0xE000) | 0x6000;

    if (dark)
        g_021DE658->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskV, 0, 0x78);
    else
        g_021DE658->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskMove, 0, 0x78);
}




void DWCi_WINlEnd(void)
{
    DWCi_TSKlDelete(0, MemWin->task);
    MemWin->task = DWCi_TSKlForm(1, taskEnd, 0, 0x78);
}



/*
 * Signed byte at +0x1b of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D1568.c \
 *       --func func_021D1568 --addr 0x021D1568 --region ov016 --cc dsi/1.1p1 --arm
 */
signed char func_021D1568(void)
{
    return *(signed char *)(*(char **)0x021DE658 + 0x1b);
}



/*
 * True when the global pointer at 0x021DE658 is non-null.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D157C.c \
 *       --func func_021D157C --addr 0x021D157C --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021D157C(void)
{
    return *(void **)0x021DE658 != 0;
}




/*
 * sdk:      taskV (libdwcutil.TWL.HYB.a window.o)
 */
void func_021D1598(void *task)
{
    g_021DE658->count--;
    func_0207D6C0(0x04000050, g_021DE658->count);
    if (g_021DE658->count > -12)
        return;
    DWCi_TSKlSetParam(task, (unsigned int)func_021D15F0);
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
 * func_021D5250 call (it is `mov r1,r4` for the idx argument and `mov r0,r4`/`mov r2,r4` for the
 * two zero arguments of func_021D7680).  Spelling that zero as a live local (`int z = 0;`, `z`
 * for all three) is folded straight back to immediate 0 by 1.1p1 - same 184 B / 130 diffs - so
 * the difference is mwcc 4.0.0.1025's rematerialisation policy, not a source shape.  Referencing
 * the same 0 through a helper or a cast does not survive either.
 */
void func_021D15F0(void *task)
{
    int x;
    int y;

    func_021D5250(g_021DE658->cellWin, 0, &x, &y);
    y -= 12;
    if (y > g_021DA9FE[g_021DE658->type].y) {
        func_021D1868(y);
        return;
    }
    func_021D1868(g_021DA9FE[g_021DE658->type].y);
    if (g_021DE658->type == 5)
        g_021DE658->task = func_021D7680(0, func_021D17FC, 0, 0x78);
    else
        g_021DE658->task = func_021D7680(0, func_021D16B0, 0, 0x78);
    func_021D7724(1, task);
}




/*
 * sdk:      taskMain (libdwcutil.TWL.HYB.a window.o)
 */
void func_021D16B0(void *task, void *work)
{
    RectT r;
    int i;

    for (i = 0; i < g_021DA9A6[g_021DE658->type]; i++) {
        func_021D600C((const struct tagCOORD *)(&g_021DAA2E[g_021DE658->type][g_021DA9B4[g_021DE658->type][i]]),
                      (const struct tagCOORD *)(&g_021DA9D2[g_021DE658->type]), (struct tagRECT *)(&r));
        if (func_021D696C((u16 *)(&r))) {
            g_021DE658->input = i;
            break;
        }
    }
    if (func_021D6824(1))
        g_021DE658->input = g_021DA9BE[g_021DE658->type][0];
    if (func_021D6824(2))
        g_021DE658->input = g_021DA9BF[g_021DE658->type][0];
    for (i = 0; i < g_021DA9A6[g_021DE658->type]; i++) {
        if (i == g_021DE658->input) {
            func_021D1A80(i);
            return;
        }
    }
    g_021DE658->input = -1;
}




/*
 * sdk:      taskMain1 (libdwcutil.TWL.HYB.a window.o)
 */
void func_021D17FC(void *task, void *work)
{
    g_021DE658->input = -1;
    g_021DE658->countWait++;
    if (g_021DE658->countWait < 0x78)
        return;
    func_021D7724(0, task);
    g_021DE658->task = func_021D7680(1, taskEnd, 0, 0x78);
}




/*
 * sdk:      disp (libdwcutil.TWL.HYB.a window.o)
 *
 * The two u16 screen-x lookups are hoisted into named locals before the y1
 * clamp: spelled inline the 1.1p1 scheduler issues the &r add and the clamp
 * cmp ahead of the pair of ldrh, giving 10 reordered instructions at +0128.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021D1868.c \n *       --func func_021D1868 --addr 0x021D1868 --region ov016 --arm --cc 1.1p1 --lang c99
 */
void func_021D1868(int y)
{
    RectT r;
    int y0;
    int y1;
    int i;
    u16 x1, x2;

    func_021D5118(g_021DE658->cellWin, -1, g_021DA9FE[g_021DE658->type].x, y);
    func_021D5118(g_021DE658->cellChar, -1, g_021DA9FE[g_021DE658->type].x + 8, y + 8);
    func_021D19F4(g_021DE658->cellWin, y);
    func_021D19F4(g_021DE658->cellChar, y);
    for (i = 0; i < g_021DA9A6[g_021DE658->type]; i++) {
        int idx = g_021DA9B4[g_021DE658->type][i];
        func_021D5118(g_021DE658->button[i], -1,
                      g_021DAA2E[g_021DE658->type][idx].x,
                      y + g_021DAA2E[g_021DE658->type][idx].y - g_021DA9FE[g_021DE658->type].y);
        func_021D19F4(g_021DE658->button[i], y);
    }
    y0 = (u8)y;
    if (y0 >= 0xc0) {
        y1 = 0;
        y0 = y1;
    } else {
        y1 = y0 + g_021DAA18[g_021DE658->type][0];
    }
    x1 = g_021DA9FE[g_021DE658->type].x;
    x2 = g_021DAA16[g_021DE658->type][0];
    if (y1 > 0xc0)
        y1 = 0xc0;
    func_021D5FF4(x1, y0, x1 + x2, y1, &r);
    func_021D60EC(0, 0, &r);
}




/*
 * sdk:      dispCell (libdwcutil.TWL.HYB.a window.o)
 */
void func_021D19F4(void *cell, int y)
{
    Eff eff;
    int num;
    int x;
    int cy;
    int i;

    num = DWCi_CELLlGetState(cell);
    for (i = 0; i < num; i++) {
        func_021D5250(cell, i, &x, &cy);
        if (cy >= y && cy < 192)
            eff = EFF_NONE;
        else
            eff = EFF_HIDE;
        func_021D4FF4(cell, i, eff, 0);
    }
}




/*
 * sdk:      pushButton (libdwcutil.TWL.HYB.a window.o)
 */
void func_021D1A80(int idx)
{
    void *obj;

    obj = func_021D4FE0(g_021DE658->button[idx], 0);
    func_021D52D4(0, g_021DA9C8[g_021DE658->type][idx] + 1, obj);
    func_021D5118(g_021DE658->button[idx], -1,
                  g_021DAA2E[g_021DE658->type][g_021DA9B4[g_021DE658->type][idx]].x,
                  g_021DAA2E[g_021DE658->type][g_021DA9B4[g_021DE658->type][idx]].y);
    func_021D51F0(g_021DE658->button[idx], -1, 0);
}




void taskEnd(void *task, void *work)
{
    MemWin->count++;
    if (MemWin->count < 8)
        return;
    DWCi_TSKlChangeFunc(task, taskEnd1);
}




/*
 * sdk:      taskEnd1 (libdwcutil.TWL.HYB.a window.o)
 */
void func_021D1B78(void *task)
{
    int x;
    int y;

    func_021D5250(g_021DE658->cellWin, 0, &x, &y);
    y += 12;
    func_021D1868(y);
    if (y < 192)
        return;
    if (g_021DE658->dark != 0)
        DWCi_TSKlSetParam(task, (unsigned int)func_021D1C04);
    else
        DWCi_TSKlSetParam(task, (unsigned int)func_021D1C5C);
}




/*
 * sdk:      taskEnd2 (libdwcutil.TWL.HYB.a window.o)
 */
void func_021D1C04(void *task)
{
    g_021DE658->count++;
    func_0207D6C0(0x04000050, g_021DE658->count);
    if (g_021DE658->count < 0)
        return;
    DWCi_TSKlSetParam(task, (unsigned int)func_021D1C5C);
}




/*
 * sdk:      taskEnd3 (libdwcutil.TWL.HYB.a window.o)
 */
void func_021D1C5C(void *task)
{
    int i;

    *(volatile unsigned int *)0x04000000 &= ~0xE000;
    func_021D4F60(g_021DE658->cellWin);
    func_021D4F60(g_021DE658->cellChar);
    for (i = 0; i < g_021DA9A6[g_021DE658->type]; i++) {
        if (g_021DE658->button[i] != 0)
            func_021D4F60(g_021DE658->button[i]);
    }
    func_021D5A2C(g_021DE658->canv);
    func_021D7724(1, task);
    func_021D6438((void **)(&g_021DE658_b));
}
