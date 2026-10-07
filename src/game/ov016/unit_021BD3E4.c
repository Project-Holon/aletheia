/*
 * file:     unit_021BD3E4.c
 * unit:     yes
 * function: func_021BD3E4, func_021BD404, func_021BD41C, func_021BD4C8, func_021BD5A8
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
 *   g_021DE550                       0x021DE550  data
 *   DWCi_FOCUSlDelete            0x021BD5A8  arm
 *   DWCi_HEAPlFree_              0x021D6438  arm
 *   DWCi_CEINlSetExCell              0x021D5394  arm  ov016
 *   DWCi_CELLlSetPriority            0x021D51F0  arm  ov016
 *   DWCi_CELLlSetPosition            0x021D5118  arm  ov016
 *   g_021DA084                       0x021DA084  data
 *   DWCi_CELLlDelete                 0x021D4F60  arm  ov016
 */
#include "../../matched/include/G_MemFocus.h"

typedef unsigned char u8;

typedef unsigned long u32;

typedef struct {
    void *cell[4];
} MemFocus;

extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);
extern void DWCi_FOCUSlDelete(void);
extern void DWCi_HEAPlFree_(void);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, int head);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlDelete(void *cell);
void func_021BD3E4(void);
asm void DWCi_FOCUSlEnd(void);
void func_021BD41C(int kind, int x0, int x1, int y);
void func_021BD4C8(int x0, int x1, int y0, int y1);
void func_021BD5A8(void);
extern struct MemFocus *g_021DE550;
extern u8 g_021DA084[][2];


/*
 * sdk:      DWCi_FOCUSlInit (libdwcutil.TWL.HYB.a(focus.o))
 */
void func_021BD3E4(void)
{
    g_021DE550 = DWCi_HEAPlAllocEx(sizeof(MemFocus), 4);
}


asm void DWCi_FOCUSlEnd(void)
{
	stmdb sp!, {r3, lr}
	bl DWCi_FOCUSlDelete
	ldr r0, =0x021DE550
	bl DWCi_HEAPlFree_
	ldmia sp!, {r3, pc}
}


void func_021BD41C(int kind, int x0, int x1, int y)
{
    int i;
    DWCi_FOCUSlDelete();
    for (i = 0; i < 2; i++) {
        g_021DE550->cell[i] = DWCi_CEINlSetExCell(0, g_021DA084[kind][i], 1);
        DWCi_CELLlSetPriority(g_021DE550->cell[i], -1, 1);
    }
    DWCi_CELLlSetPosition(g_021DE550->cell[0], -1, x0, y);
    DWCi_CELLlSetPosition(g_021DE550->cell[1], -1, x1, y);
}


/*
 * sdk:      DWCi_FOCUSlDisp4 (libdwcutil.TWL.HYB.a(focus.o))
 */
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


/*
 * sdk:      DWCi_FOCUSlDelete (libdwcutil.TWL.HYB.a(focus.o))
 */
void func_021BD5A8(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (g_021DE550->cell[i]) {
            DWCi_CELLlDelete(g_021DE550->cell[i]);
            g_021DE550->cell[i] = 0;
        }
    }
}
