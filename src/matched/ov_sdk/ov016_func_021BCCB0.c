/*
 * function: func_021BCCB0
 * address:  0x021BCCB0
 * packet:   pkt_ov016_021BCCB0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskStart1 (libdwcutil.TWL.HYB.a(button.o))
 *
 * symbols:
 *   DWCi_TSKlSetParam  0x021d771c  arm  ov016
 *   g_021DE508  0x021de508  data
 *   func_021BCD00  0x021bcd00  arm  ov016
 */

#include "../include/G_tagMEMBTN.h"

typedef _Bool bool;

extern struct tagMEMBTN *g_021DE508;

extern void DWCi_TSKlSetParam(char *p, unsigned int v);
extern void func_021BCD00(void);

void func_021BCCB0(void *task)
{
    g_021DE508->input = -1;
    g_021DE508->count++;
    if (g_021DE508->count >= 4) {
        g_021DE508->count = 0;
        DWCi_TSKlSetParam(task, (unsigned int)func_021BCD00);
    }
}
