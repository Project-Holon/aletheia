/*
 * function: func_021BCEE0
 * address:  0x021BCEE0
 * packet:   pkt_ov016_021BCEE0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd1 (libdwcutil.TWL.HYB.a(button.o))
 *
 * symbols:
 *   func_021D7724  0x021d7724  arm  ov016
 *   func_021D4F60  0x021d4f60  arm  ov016
 *   func_021D6438  0x021d6438  arm  ov016
 *   g_021DE508  0x021de508  data
 *   g_021DE508_b  0x021DE508  data
 */

#include "../include/G_tagMEMBTN.h"

typedef _Bool bool;

typedef struct tagMEMBTN MEMBTN;

extern struct tagMEMBTN *g_021DE508;

extern void func_021D7724(int kind, void *task);
typedef unsigned char  u8;
extern void func_021D4F60(u8 *p);
extern void func_021D6438(void **mem);
extern struct tagMEMBTN *g_021DE508_b;

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
