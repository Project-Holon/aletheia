/*
 * file:     unit_021D1208_p04.c
 * unit:     yes
 * function: func_021D1B3C, func_021D1B78, func_021D1C04, func_021D1C5C
 * address:  0x021D1B3C
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
 *   DWCi_TSKlChangeFunc 0x021D771C arm
 *   MemWin             0x021DE658 data
 *   taskEnd1           0x021D1B78 arm
 *   func_021D5250  0x021D5250  arm  ov016
 *   func_021D1868  0x021D1868  arm  ov016
 *   func_021D771C  0x021D771C  arm  ov016
 *   g_021DE658     0x021DE658  data
 *   func_0207D6C0  0x0207D6C0  arm
 *   func_021D4F60  0x021D4F60  arm  ov016
 *   func_021D5A2C  0x021D5A2C  arm  ov016
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE658_b   0x021DE658  data
 *   g_021DA9A6     0x021DA9A6  data
 */
#include "../../matched/include/G_MemWinT.h"

struct tagMEMWIN {
    char pad[0x14];
    void *task;                  /* 0x14 */
    char pad2[0x1d - 0x18];
    unsigned char count;         /* 0x1d */
};

typedef unsigned char u8;

typedef unsigned short u16;

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

typedef unsigned int   u32;

void taskEnd1(void *task);
void DWCi_TSKlChangeFunc(void *task, void (*func)(void *));
extern void func_021D5250(void *cell, int idx, int *x, int *y);
extern void func_021D1868(int y);
extern void func_021D771C(char *p, unsigned int v);
extern void func_0207D6C0(u32 addr, int brightness);
extern void func_021D4F60(u8 *p);
extern void func_021D5A2C(char *a);
extern void func_021D7724();
extern void func_021D6438(void **mem);
void taskEnd(void *task);
void func_021D1B78(void *task);
void func_021D1C04(void *task);
void func_021D1C5C(void *task);
extern struct tagMEMWIN *MemWin;
extern struct MemWinT *g_021DE658;
extern struct MemWinT *g_021DE658_b;
extern u8 g_021DA9A6[6];


void taskEnd(void *task)
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
        func_021D771C(task, (unsigned int)func_021D1C04);
    else
        func_021D771C(task, (unsigned int)func_021D1C5C);
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
    func_021D771C(task, (unsigned int)func_021D1C5C);
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
