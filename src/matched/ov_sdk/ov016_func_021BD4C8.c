/*
 * function: func_021BD4C8
 * address:  0x021BD4C8
 * packet:   pkt_ov016_021BD4C8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FOCUSlDisp4 (libdwcutil.TWL.HYB.a(focus.o))
 *
 * symbols:
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm  ov016
 *   DWCi_CEINlSetExCell              0x021D5394  arm  ov016
 *   DWCi_CELLlSetPriority            0x021D51F0  arm  ov016
 *   DWCi_CELLlSetPosition            0x021D5118  arm  ov016
 *   g_021DE550                       0x021DE550  data
 */

#include "../include/G_MemFocus.h"

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    void *cell[4];
} MemFocus;

extern struct MemFocus *g_021DE550;
extern void DWCi_FOCUSlDelete(void);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, int head);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);

void func_021BD4C8(int x0, int x1, int y0, int y1)
{
    int idx;
    int i;
    idx = 6;
    DWCi_FOCUSlDelete();
    for (i = 0; i < 4; i++, idx++) {
        g_021DE550->cell[i] = DWCi_CEINlSetExCell(0, idx, 1);
        DWCi_CELLlSetPriority(g_021DE550->cell[i], -1, 1);
    }
    DWCi_CELLlSetPosition(g_021DE550->cell[0], -1, x0, y0);
    DWCi_CELLlSetPosition(g_021DE550->cell[1], -1, x1, y0);
    DWCi_CELLlSetPosition(g_021DE550->cell[2], -1, x0, y1);
    DWCi_CELLlSetPosition(g_021DE550->cell[3], -1, x1, y1);
}
