/*
 * file:     unit_021D1208_p03.c
 * unit:     yes
 * function: func_021D19F4, func_021D1A80
 * address:  0x021D19F4
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
 *   func_021D4FEC  0x021D4FEC  arm  ov016
 *   func_021D5250  0x021D5250  arm  ov016
 *   func_021D4FF4  0x021D4FF4  arm  ov016
 *   func_021D4FE0  0x021D4FE0  arm  ov016
 *   func_021D52D4  0x021D52D4  arm  ov016
 *   func_021D5118  0x021D5118  arm  ov016
 *   func_021D51F0  0x021D51F0  arm  ov016
 *   g_021DE658     0x021DE658  data
 *   g_021DA9C8     0x021DA9C8  data
 *   g_021DA9B4     0x021DA9B4  data
 *   g_021DAA2E     0x021DAA2E  data
 *   g_021DAA30     0x021DAA30  data
 */
#include "../../matched/include/G_MemWinT.h"

typedef enum {
    EFF_NONE = 0,
    EFF_HIDE = 0x200
} Eff;

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

extern unsigned char func_021D4FEC(char *p);
extern void func_021D5250(void *cell, int idx, int *x, int *y);
extern void func_021D4FF4(void *cell, int idx, Eff eff, int affine);
extern char *func_021D4FE0(char *p, unsigned int i);
extern void func_021D52D4();
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D51F0(void *cell, int idx, int priority);
void func_021D19F4(void *cell, int y);
void func_021D1A80(int idx);
extern struct MemWinT *g_021DE658;
extern u8 g_021DA9C8[][2];
extern u8 g_021DA9B4[][2];
extern u16 g_021DAA2E[][4];
extern u16 g_021DAA30[][4];


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

    num = func_021D4FEC(cell);
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
                  g_021DAA2E[g_021DE658->type][g_021DA9B4[g_021DE658->type][idx] * 2],
                  g_021DAA30[g_021DE658->type][g_021DA9B4[g_021DE658->type][idx] * 2]);
    func_021D51F0(g_021DE658->button[idx], -1, 0);
}
