/*
 * file:     unit_021BC9E4.c
 * unit:     yes
 * function: func_021BC9E4, func_021BCAE4, func_021BCB14, func_021BCB28, func_021BCB44, func_021BCB58, func_021BCB84, func_021BCB9C, func_021BCBB4, func_021BCC44, func_021BCCB0, func_021BCD00, func_021BCE7C, func_021BCEE0, func_021BCF5C
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5394  0x021D5394  arm  ov016
 *   func_021D51F0  0x021D51F0  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DA008  0x021DA008  data
 *   g_021DE508  0x021DE508  data
 *   g_021DA018  0x021DA018  data
 *   MemBtn                           0x021DE508  data
 *   taskEnd                          0x021BCE7C  arm
 *   DWCi_TSKlChangeFunc              0x021D771C  arm
 *   func_021D5118  0x021d5118  arm  ov016
 *   g_021DA026  0x021da026  data
 *   g_021DA010  0x021da010  data
 *   func_021D5250  0x021d5250  arm  ov016
 *   func_021D771C  0x021d771c  arm  ov016
 *   func_021D600C  0x021D600C  arm  ov016
 *   func_021D696C  0x021D696C  arm  ov016
 *   func_021D4FE0  0x021D4FE0  arm  ov016
 *   func_021D52D4  0x021D52D4  arm  ov016
 *   g_021DA004  0x021DA004  data
 *   func_021D7724  0x021d7724  arm  ov016
 *   func_021D4F60  0x021d4f60  arm  ov016
 *   func_021D6438  0x021d6438  arm  ov016
 *   g_021DE508_b  0x021DE508  data
 */
#include "../../matched/include/G_tagMEMBTN.h"

struct tagCOORD;
struct tagRECT;
struct MEMBTN {
    char pad[0xc];
    int f0C;
    char pad2[9];
    unsigned char f19;
};

typedef _Bool bool;

typedef struct tagCOORD { unsigned short x, y; } COORD;

typedef struct { unsigned short l, t, r, b; } Rect;

typedef struct { unsigned short x, y; } Coord;

typedef unsigned short u16;

typedef struct tagMEMBTN MEMBTN;

typedef unsigned char  u8;

extern void *func_021D6414(unsigned long size, int alignment);
extern void *func_021D5394(int lcd, int idx, int head);
extern void func_021D51F0(void *cell, int idx, int priority);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void DWCi_TSKlChangeFunc(int prm, void (*fn)(void *));
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D5250(void *cell, int idx, int *x, int *y);
extern void func_021D771C(char *p, unsigned int v);
extern void func_021D600C(const struct tagCOORD *coord, const struct tagCOORD *size, struct tagRECT *rect);
extern int func_021D696C(u16 *a);
extern char *func_021D4FE0(char *p, unsigned int i);
extern void func_021D52D4(int lcd, int idx, void *obj);
extern void func_021D7724(int kind, void *task);
extern void func_021D4F60(u8 *p);
extern void func_021D6438(void **mem);
void func_021BC9E4(int kind);
void DWCi_BTNlEnd(void);
signed char func_021BCB14(void);
void func_021BCB28(signed char v);
void func_021BCB44(int a);
int func_021BCB58(void);
void func_021BCB84(void);
void func_021BCB9C(void);
void func_021BCBB4(int y);
void func_021BCC44(void *task);
void func_021BCCB0(void *task);
void func_021BCD00(void);
void func_021BCE7C(void *task);
void func_021BCEE0(void *task);
void func_021BCF5C(void *task);
extern unsigned char g_021DA008[7];
extern struct tagMEMBTN *g_021DE508;
extern unsigned char g_021DA018[7][2];
extern struct MEMBTN *MemBtn;
extern const unsigned char g_021DA026[][2];
extern const COORD g_021DA010[];
extern Coord g_021DA004;
extern struct tagMEMBTN *g_021DE508_b;


/*
 * sdk:      DWCi_BTNlInit (libdwcutil.TWL.HYB.a button.o)
 */
void func_021BC9E4(int kind)
{
    int btnNum;
    int i;

    btnNum = g_021DA008[kind];
    g_021DE508 = func_021D6414(0x1c, 4);
    g_021DE508->input = -2;
    g_021DE508->kind = kind;
    for (i = 0; i < btnNum; i++) {
        g_021DE508->cellButton[i] = func_021D5394(0, g_021DA018[kind][i], 1);
        func_021D51F0(g_021DE508->cellButton[i], -1, 1);
    }
    g_021DE508->cellBack = func_021D5394(0, 1, 1);
    func_021D51F0(g_021DE508->cellBack, -1, 1);
    func_021BCBB4(0xc0);
    g_021DE508->task = func_021D7680(0, (void (*)(void *, void *))func_021BCC44, 0, 0x78);
}


static void taskEnd(void *task);


void DWCi_BTNlEnd(void)
{
    MemBtn->f19 = 1;
    DWCi_TSKlChangeFunc(MemBtn->f0C, taskEnd);
}

signed char func_021BCB14(void)
{
    return *(signed char *)(*(char **)0x021DE508 + 0x16);
}

void func_021BCB28(signed char v)
{
    unsigned char *p = *(unsigned char **)0x021DE508;

    if (*(signed char *)(p + 0x16) == -1)
        *(signed char *)(p + 0x16) = v;
}

void func_021BCB44(int a)
{
    *(unsigned char *)(*(char **)0x021DE508 + 0x16) = a;
}

int func_021BCB58(void)
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
void func_021BCB84(void)
{
    *(unsigned char *)(*(char **)0x021DE508 + 0x18) = 0;
}

void func_021BCB9C(void)
{
    *(unsigned char *)(*(char **)0x021DE508 + 0x18) = 1;
}


void func_021BCBB4(int y)
{
    int btnNum;
    int cy;
    int i;

    btnNum = g_021DA008[g_021DE508->kind];
    func_021D5118(g_021DE508->cellBack, -1, 0, y);
    for (i = 0; i < btnNum; i++) {
        func_021D5118(g_021DE508->cellButton[i], -1, g_021DA010[g_021DA026[g_021DE508->kind][i]].x, y + 4);
    }
}


/*
 * sdk:      taskStart (libdwcutil.TWL.HYB.a(button.o))
 */
void func_021BCC44(void *task)
{
    int x, y;

    func_021D5250(g_021DE508->cellBack, 0, &x, &y);
    y -= 4;
    func_021BCBB4(y);
    if (y > 168)
        return;
    func_021BCBB4(168);
    func_021D771C(task, (unsigned int)func_021BCCB0);
}


/*
 * sdk:      taskStart1 (libdwcutil.TWL.HYB.a(button.o))
 */
void func_021BCCB0(void *task)
{
    g_021DE508->input = -1;
    g_021DE508->count++;
    if (g_021DE508->count >= 4) {
        g_021DE508->count = 0;
        func_021D771C(task, (unsigned int)func_021BCD00);
    }
}


void func_021BCD00(void)
{
    Rect r;
    int btnNum;
    int i;

    btnNum = g_021DA008[g_021DE508->kind];
    if (!g_021DE508->disable) {
        if (g_021DE508->input != -1)
            return;
        for (i = 0; i < btnNum; i++) {
            func_021D600C((const struct tagCOORD *)(&g_021DA010[g_021DA026[g_021DE508->kind][i]]), (const struct tagCOORD *)(&g_021DA004), (struct tagRECT *)(&r));
            if (func_021D696C((u16 *)(&r))) {
                if (g_021DE508->release)
                    break;
                {
                    int cellIdx = g_021DA018[g_021DE508->kind][i];
                    func_021D52D4(0, cellIdx + 1, func_021D4FE0(g_021DE508->cellButton[i], 0));
                }
                func_021D5118(g_021DE508->cellButton[i], -1,
                              g_021DA010[g_021DA026[g_021DE508->kind][i]].x,
                              g_021DA010[g_021DA026[g_021DE508->kind][i]].y);
                func_021D51F0(g_021DE508->cellButton[i], -1, 1);
                g_021DE508->release = func_021D7680(0, (void (*)(void *, void *))func_021BCF5C, 0, 0x6e);
                g_021DE508->input = i;
                return;
            }
        }
    }
    g_021DE508->input = -1;
}


void func_021BCE7C(void *task)
{
    int x, y;

    func_021D5250(g_021DE508->cellBack, 0, &x, &y);
    y += 4;
    func_021BCBB4(y);
    if (y >= 192)
        func_021D771C(task, (unsigned int)func_021BCEE0);
}


/*
 * sdk:      taskEnd1 (libdwcutil.TWL.HYB.a(button.o))
 */
void func_021BCEE0(void *task)
{
    int i;

    func_021D7724(0, task);
    if (g_021DE508->release)
        func_021D7724(0, g_021DE508->release);
    for (i = 0; i < 2; i++) {
        if (g_021DE508->cellButton[i])
            func_021D4F60(g_021DE508->cellButton[i]);
    }
    func_021D4F60(g_021DE508->cellBack);
    func_021D6438((void **)&g_021DE508_b);
}


/*
 * sdk:      taskRelease (libdwcutil.TWL.HYB.a(button.o))
 */
void func_021BCF5C(void *task)
{
    int btnNum;
    int i;

    g_021DE508->count++;
    if (g_021DE508->count < 16)
        return;
    btnNum = g_021DA008[g_021DE508->kind];
    for (i = 0; i < btnNum; i++) {
        {
            int idx = g_021DA018[g_021DE508->kind][i];
            func_021D52D4(0, idx, func_021D4FE0(g_021DE508->cellButton[i], 0));
        }
        func_021D51F0(g_021DE508->cellButton[i], -1, 1);
    }
    func_021BCBB4(168);
    g_021DE508->count = 0;
    g_021DE508->input = -1;
    if (g_021DE508->release) {
        g_021DE508->release = 0;
        func_021D7724(0, task);
    }
}
