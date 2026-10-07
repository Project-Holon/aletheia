/*
 * file:     unit_021D1208_p02.c
 * unit:     yes
 * function: func_021D17FC, func_021D1868
 * address:  0x021D17FC
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
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021D1B3C  0x021D1B3C  arm  ov016
 *   g_021DE658     0x021DE658  data
 *   func_021D5118  0x021D5118  arm  ov016
 *   func_021D19F4  0x021D19F4  arm  ov016
 *   func_021D5FF4  0x021D5FF4  arm  ov016
 *   func_021D60EC  0x021D60EC  arm  ov016
 *   g_021DA9FE  0x021DA9FE  data
 *   g_021DA9A6  0x021DA9A6  data
 *   g_021DA9B4  0x021DA9B4  data
 *   g_021DAA2E  0x021DAA2E  data
 *   g_021DAA18  0x021DAA18  data
 *   g_021DAA16  0x021DAA16  data
 */
#include "../../matched/include/G_MemWinT.h"
#include "../../matched/include/G_CoordT.h"
#include "../../matched/include/G_021DAA2E.h"

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

typedef struct {
    u16 x;
    u16 y;
} CoordT;

typedef struct {
    u16 l, t, r, b;
} RectT;

extern void func_021D7724();
extern void *func_021D7680();
extern void func_021D1B3C(void *task);
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D19F4(void *cell, int y);
extern void func_021D5FF4(int x0, int y0, int x1, int y1, RectT *r);
extern void func_021D60EC(int a, int b, RectT *r);
void func_021D17FC(void *task);
void func_021D1868(int y);
extern struct MemWinT *g_021DE658;
extern struct CoordT g_021DA9FE[];
extern u8 g_021DA9A6[6];
extern u8 g_021DA9B4[][2];
extern struct G_021DAA2E g_021DAA2E[][2];
extern u16 g_021DAA18[][2];
extern u16 g_021DAA16[][2];


/*
 * sdk:      taskMain1 (libdwcutil.TWL.HYB.a window.o)
 */
void func_021D17FC(void *task)
{
    g_021DE658->input = -1;
    g_021DE658->countWait++;
    if (g_021DE658->countWait < 0x78)
        return;
    func_021D7724(0, task);
    g_021DE658->task = func_021D7680(1, func_021D1B3C, 0, 0x78);
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
