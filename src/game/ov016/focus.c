/*
 * file:     focus.c
 * unit:     yes
 * function: DWCi_FOCUSlInit, DWCi_FOCUSlEnd, DWCi_FOCUSlDisp, DWCi_FOCUSlDisp4, DWCi_FOCUSlDelete
 * address:  0x021BD3E4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_HEAPlAllocEx                0x021D6414  arm  ov016
 *   gFocusWork                       0x021DE550  data
 *   DWCi_FOCUSlDelete            0x021BD5A8  arm
 *   DWCi_HEAPlFree_              0x021D6438  arm
 *   DWCi_CEINlSetExCell              0x021D5394  arm  ov016
 *   DWCi_CELLlSetPriority            0x021D51F0  arm  ov016
 *   DWCi_CELLlSetPosition            0x021D5118  arm  ov016
 *   sFocusCellIds                       0x021DA084  data
 *   DWCi_CELLlDelete                 0x021D4F60  arm  ov016
 */
#include "../../matched/include/G_MemFocus.h"

#include "../types.h"

typedef struct {
    void *cell[4];
} MemFocus;

extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);
void DWCi_FOCUSlDelete(void);
extern void DWCi_HEAPlFree_(void **mem);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, int head);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
struct CellInfo;
extern void DWCi_CELLlDelete(struct CellInfo *p);
void DWCi_FOCUSlInit(void);
void DWCi_FOCUSlEnd(void);
void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y);
void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern struct MemFocus *gFocusWork;
extern u8 sFocusCellIds[][2];

/*
 * sdk:      DWCi_FOCUSlInit (libdwcutil.TWL.HYB.a(focus.o))
 */

void DWCi_FOCUSlInit(void)
{
    gFocusWork = DWCi_HEAPlAllocEx(sizeof(MemFocus), 4);
}

void DWCi_FOCUSlEnd(void)
{
    DWCi_FOCUSlDelete();
    DWCi_HEAPlFree_((void **)&gFocusWork);
}

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

/*
 * sdk:      DWCi_FOCUSlDisp4 (libdwcutil.TWL.HYB.a(focus.o))
 */
void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1)
{
    int idx;
    int i;
    idx = 6;
    DWCi_FOCUSlDelete();
    for (i = 0; i < 4; i++, idx++) {
        gFocusWork->cell[i] = DWCi_CEINlSetExCell(0, idx, 1);
        DWCi_CELLlSetPriority(gFocusWork->cell[i], -1, 1);
    }
    DWCi_CELLlSetPosition(gFocusWork->cell[0], -1, x0, y0);
    DWCi_CELLlSetPosition(gFocusWork->cell[1], -1, x1, y0);
    DWCi_CELLlSetPosition(gFocusWork->cell[2], -1, x0, y1);
    DWCi_CELLlSetPosition(gFocusWork->cell[3], -1, x1, y1);
}

/*
 * sdk:      DWCi_FOCUSlDelete (libdwcutil.TWL.HYB.a(focus.o))
 */
void DWCi_FOCUSlDelete(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (gFocusWork->cell[i]) {
            DWCi_CELLlDelete(gFocusWork->cell[i]);
            gFocusWork->cell[i] = 0;
        }
    }
}
