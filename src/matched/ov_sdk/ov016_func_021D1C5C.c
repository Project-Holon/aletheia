/*
 * function: func_021D1C5C
 * address:  0x021D1C5C
 * packet:   pkt_ov016_021D1C5C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd3 (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   func_021D4F60  0x021D4F60  arm  ov016
 *   func_021D5A2C  0x021D5A2C  arm  ov016
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE658     0x021DE658  data
 *   g_021DE658_b   0x021DE658  data
 *   g_021DA9A6     0x021DA9A6  data
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

extern void func_021D4F60(u8 *p);
extern void func_021D5A2C(char *a);
extern void func_021D7724();
extern void func_021D6438(void **mem);
extern struct MemWinT *g_021DE658;
extern struct MemWinT *g_021DE658_b;
extern u8 g_021DA9A6[6];

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
