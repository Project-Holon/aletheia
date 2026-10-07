/*
 * function: func_021D1A80
 * address:  0x021D1A80
 * packet:   pkt_ov016_021D1A80
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      pushButton (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
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

#include "../include/G_MemWinT.h"

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

extern char *func_021D4FE0(char *p, unsigned int i);
extern void func_021D52D4();
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D51F0(void *cell, int idx, int priority);
extern struct MemWinT *g_021DE658;
extern u8 g_021DA9C8[][2];
extern u8 g_021DA9B4[][2];
extern u16 g_021DAA2E[][4];
extern u16 g_021DAA30[][4];

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
