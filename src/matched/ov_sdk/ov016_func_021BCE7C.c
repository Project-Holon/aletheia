/*
 * function: DWCi_ButtonTaskEnd
 * address:  0x021BCE7C
 * packet:   pkt_ov016_021BCE7C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd (libdwcutil.TWL.HYB.a(button.o))
 *
 * symbols:
 *   DWCi_CELLlGetPosition  0x021d5250  arm  ov016
 *   func_021BCBB4  0x021bcbb4  arm  ov016
 *   DWCi_TSKlChangeFunc  0x021d771c  arm  ov016
 *   gButtonWork  0x021de508  data
 *   func_021BCEE0  0x021bcee0  arm  ov016
 */

#include "../include/G_tagMEMBTN.h"

typedef _Bool bool;

extern struct tagMEMBTN *gButtonWork;

extern void DWCi_CELLlGetPosition(void *cell, int idx, int *x, int *y);
extern void func_021BCBB4(int y);
extern void DWCi_TSKlChangeFunc(char *p, unsigned int v);
extern void func_021BCEE0(void *task);

void DWCi_ButtonTaskEnd(void *task)
{
    int x, y;

    DWCi_CELLlGetPosition(gButtonWork->cellBack, 0, &x, &y);
    y += 4;
    func_021BCBB4(y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, (unsigned int)func_021BCEE0);
}
