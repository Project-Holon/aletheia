/*
 * function: DWCi_FOCUSlDisp
 * address:  0x021BD41C
 * packet:   pkt_ov016_021BD41C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FOCUSlDisp (libdwcutil.TWL.HYB.a(focus.o))
 *
 * symbols:
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm  ov016
 *   DWCi_CEINlSetExCell              0x021D5394  arm  ov016
 *   DWCi_CELLlSetPriority            0x021D51F0  arm  ov016
 *   DWCi_CELLlSetPosition            0x021D5118  arm  ov016
 *   sFocusCellIds                       0x021DA084  data
 *   gFocusWork                       0x021DE550  data
 */

#include "../include/G_MemFocus.h"

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    void *cell[4];
} MemFocus;

extern struct MemFocus *gFocusWork;
extern void DWCi_FOCUSlDelete(void);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, int head);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern u8 sFocusCellIds[][2];

void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y)
{
    int i;
    DWCi_FOCUSlDelete();
    for (i = 0; i < 2; i++) {
        gFocusWork->cell[i] = DWCi_CEINlSetExCell(0, sFocusCellIds[kind][i], 1);
        DWCi_CELLlSetPriority(gFocusWork->cell[i], -1, 1);
    }
    DWCi_CELLlSetPosition(gFocusWork->cell[0], -1, x0, y);
    DWCi_CELLlSetPosition(gFocusWork->cell[1], -1, x1, y);
}
