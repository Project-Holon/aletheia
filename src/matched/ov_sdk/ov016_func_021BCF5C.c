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
 *   DWCi_CELLlGetObj  0x021d4fe0  arm  ov016
 *   DWCi_CEINlSet  0x021d52d4  arm  ov016
 *   DWCi_CELLlSetPriority  0x021d51f0  arm  ov016
 *   func_021BCBB4  0x021bcbb4  arm  ov016
 *   DWCi_TSKlDelete  0x021d7724  arm  ov016
 *   gButtonWork  0x021de508  data
 *   sButtonCountByKind  0x021da008  data
 *   sButtonCellIds  0x021da018  data
 */

#include "../include/G_tagMEMBTN.h"

typedef _Bool bool;

extern struct tagMEMBTN *gButtonWork;

extern const unsigned char sButtonCountByKind[];
extern const unsigned char sButtonCellIds[][2];
extern char *DWCi_CELLlGetObj(char *p, unsigned int i);
extern void DWCi_CEINlSet(int lcd, int idx, void *obj);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void func_021BCBB4(int y);
extern void DWCi_TSKlDelete(int kind, void *task);

void func_021BCF5C(void *task)
{
    int btnNum;
    int i;

    gButtonWork->count++;
    if (gButtonWork->count < 16)
        return;
    btnNum = sButtonCountByKind[gButtonWork->kind];
    for (i = 0; i < btnNum; i++) {
        {
            int idx = sButtonCellIds[gButtonWork->kind][i];
            DWCi_CEINlSet(0, idx, DWCi_CELLlGetObj(gButtonWork->cellButton[i], 0));
        }
        DWCi_CELLlSetPriority(gButtonWork->cellButton[i], -1, 1);
    }
    func_021BCBB4(168);
    gButtonWork->count = 0;
    gButtonWork->input = -1;
    if (gButtonWork->release) {
        gButtonWork->release = 0;
        DWCi_TSKlDelete(0, task);
    }
}
