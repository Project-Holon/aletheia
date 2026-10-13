/*
 * function: DWCi_BTNlInit
 * address:  0x021BC9E4
 * packet:   pkt_ov016_021BC9E4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_BTNlInit (libdwcutil.TWL.HYB.a button.o)
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_CEINlSetExCell  0x021D5394  arm  ov016
 *   DWCi_CELLlSetPriority  0x021D51F0  arm  ov016
 *   func_021BCBB4  0x021BCBB4  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   func_021BCC44  0x021BCC44  arm  ov016
 *   sButtonCountByKind  0x021DA008  data
 *   gButtonWork  0x021DE508  data
 *   sButtonCellIds  0x021DA018  data
 */

#include "../include/G_tagMEMBTN.h"

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, int head);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void func_021BCBB4(int y);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021BCC44(void *task);
extern unsigned char sButtonCountByKind[7];
extern struct tagMEMBTN *gButtonWork;
extern unsigned char sButtonCellIds[7][2];

void DWCi_BTNlInit(int kind)
{
    int btnNum;
    int i;

    btnNum = sButtonCountByKind[kind];
    gButtonWork = DWCi_HEAPlAllocEx(0x1c, 4);
    gButtonWork->input = -2;
    gButtonWork->kind = kind;
    for (i = 0; i < btnNum; i++) {
        gButtonWork->cellButton[i] = DWCi_CEINlSetExCell(0, sButtonCellIds[kind][i], 1);
        DWCi_CELLlSetPriority(gButtonWork->cellButton[i], -1, 1);
    }
    gButtonWork->cellBack = DWCi_CEINlSetExCell(0, 1, 1);
    DWCi_CELLlSetPriority(gButtonWork->cellBack, -1, 1);
    func_021BCBB4(0xc0);
    gButtonWork->task = DWCi_TSKlForm(0, (void (*)(void *, void *))func_021BCC44, 0, 0x78);
}
