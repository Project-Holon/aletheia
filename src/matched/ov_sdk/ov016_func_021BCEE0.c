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
 *   DWCi_TSKlDelete  0x021d7724  arm  ov016
 *   DWCi_CELLlDelete  0x021d4f60  arm  ov016
 *   DWCi_HEAPlFree_  0x021d6438  arm  ov016
 *   gButtonWork  0x021de508  data
 *   gMemButton  0x021DE508  data
 */

#include "../include/G_tagMEMBTN.h"

typedef _Bool bool;

typedef struct tagMEMBTN MEMBTN;

extern struct tagMEMBTN *gButtonWork;

extern void DWCi_TSKlDelete(int kind, void *task);
typedef unsigned char  u8;
extern void DWCi_CELLlDelete(u8 *p);
extern void DWCi_HEAPlFree_(void **mem);
extern struct tagMEMBTN *gMemButton;

void func_021BCEE0(void *task)
{
    int i;

    DWCi_TSKlDelete(0, task);
    if (gButtonWork->release)
        DWCi_TSKlDelete(0, gButtonWork->release);
    for (i = 0; i < 2; i++) {
        if (gButtonWork->cellButton[i])
            DWCi_CELLlDelete(gButtonWork->cellButton[i]);
    }
    DWCi_CELLlDelete(gButtonWork->cellBack);
    DWCi_HEAPlFree_((void **)&gMemButton);
}
