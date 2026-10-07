/*
 * function: func_021BCF5C
 * address:  0x021BCF5C
 * packet:   pkt_ov016_021BCF5C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskRelease (libdwcutil.TWL.HYB.a(button.o))
 *
 * symbols:
 *   func_021D4FE0  0x021d4fe0  arm  ov016
 *   func_021D52D4  0x021d52d4  arm  ov016
 *   func_021D51F0  0x021d51f0  arm  ov016
 *   func_021BCBB4  0x021bcbb4  arm  ov016
 *   func_021D7724  0x021d7724  arm  ov016
 *   g_021DE508  0x021de508  data
 *   g_021DA008  0x021da008  data
 *   g_021DA018  0x021da018  data
 */

#include "../include/G_tagMEMBTN.h"

typedef _Bool bool;

extern struct tagMEMBTN *g_021DE508;

extern const unsigned char g_021DA008[];
extern const unsigned char g_021DA018[][2];
extern char *func_021D4FE0(char *p, unsigned int i);
extern void func_021D52D4(int lcd, int idx, void *obj);
extern void func_021D51F0(void *cell, int idx, int priority);
extern void func_021BCBB4(int y);
extern void func_021D7724(int kind, void *task);

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
