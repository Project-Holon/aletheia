/*
 * function: func_021BCBB4
 * address:  0x021BCBB4
 * packet:   pkt_ov016_021BCBB4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      disp (libdwcutil.TWL.HYB.a(button.o))
 *
 * symbols:
 *   func_021D5118  0x021d5118  arm  ov016
 *   g_021DE508  0x021de508  data
 *   g_021DA008  0x021da008  data
 *   g_021DA026  0x021da026  data
 *   g_021DA010  0x021da010  data
 */

#include "../include/G_tagMEMBTN.h"

typedef _Bool bool;

extern struct tagMEMBTN *g_021DE508;

typedef struct tagCOORD { unsigned short x, y; } COORD;

extern const unsigned char g_021DA008[];
extern const unsigned char g_021DA026[][2];
extern const COORD g_021DA010[];
extern void func_021D5118(void *cell, int idx, int x, int y);

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
