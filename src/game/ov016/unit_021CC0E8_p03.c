/*
 * file:     unit_021CC0E8_p03.c
 * unit:     yes
 * function: func_021CC4E8, func_021CC6AC
 * address:  0x021CC4E8
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
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021CC46C  0x021CC46C  arm  ov016
 *   g_021DE60C  0x021DE60C  data
 *   DWCi_CELLlGetObj                 0x021d4fe0 arm
 *   DWCi_CEINlSet                    0x021d52d4 arm
 *   DWCi_CELLlSetPosition            0x021d5118 arm
 *   DWCi_CELLlSetPriority            0x021d51f0 arm
 *   scenesetselectap_bss             0x021de60c data
 *   C_CELL                           0x021da72c data
 */
#include "../../matched/include/G_SCENESETSELECTAP_BSS.h"

typedef unsigned char u8;

typedef struct tagMEMSSSA {
    char pad[0x1c];
    u8 column;          /* +0x1c */
} MEMSSSA;

typedef struct tagCOORD { unsigned short x, y; } COORD;

typedef struct GXOamAttr GXOamAttr;

/* scenesetselectap.o .bss at 0x021DE60C, members at their vendor offsets */
typedef struct {
    void          *palette;           /* 0x00 */
    void          *cellA[3];          /* 0x04 */
    void          *cellB[3];          /* 0x10 */
    unsigned char  pad0;              /* 0x1C */
    unsigned char  state;             /* 0x1D */
    unsigned char  pad1[2];
} SSSA;                               /* 0x20 */

typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    SSSA          *MemSssa;           /* 0x04 */
} SCENESETSELECTAP_BSS;

extern void func_021CFFAC(unsigned int v);
extern void func_021CC46C(void);
extern GXOamAttr *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern struct SCENESETSELECTAP_BSS g_021DE60C;
/* scenesetselectap.o .rodata at 0x021DA72C */
extern const COORD C_CELL[6];
extern SCENESETSELECTAP_BSS scenesetselectap_bss;


/*
 * sdk:      moveFocus (libdwcutil.TWL.HYB.a(scenesetselectap))
 *
 * FocusPos (0x021DE60C) anchors the statics; MemSssa sits at +4. The DWARF lists
 * only move and clear; the object computes clear + 4 unconditionally before the
 * dir test, which the second local next reproduces.
 */
static void func_021CC4E8(int dir)
{
    int clear;
    int next;
    int move = 1;

    switch (g_021DE60C.FocusPos) {
    case 0:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 0;
        if (dir == 0)
            g_021DE60C.FocusPos = 2;
        else if (dir == 2)
            g_021DE60C.FocusPos = 1;
        else if (dir == 1)
            g_021DE60C.FocusPos = 3;
        else
            g_021DE60C.FocusPos = 4;
        break;
    case 1:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 1;
        if (dir == 0)
            g_021DE60C.FocusPos = 0;
        else if (dir == 2)
            g_021DE60C.FocusPos = 2;
        else if (dir == 1)
            g_021DE60C.FocusPos = 3;
        else
            g_021DE60C.FocusPos = 5;
        break;
    case 2:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 2;
        if (dir == 0)
            g_021DE60C.FocusPos = 1;
        else if (dir == 2)
            g_021DE60C.FocusPos = 0;
        else if (dir == 1)
            g_021DE60C.FocusPos = 3;
        else
            g_021DE60C.FocusPos = 6;
        break;
    case 3:
        clear = ((MEMSSSA *)g_021DE60C.MemSssa)->column;
        next = clear + 4;
        if (dir == 1)
            g_021DE60C.FocusPos = next;
        else if (dir == 3)
            g_021DE60C.FocusPos = clear;
        else
            move = 0;
        break;
    case 4:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 0;
        if (dir == 0)
            g_021DE60C.FocusPos = 6;
        else if (dir == 2)
            g_021DE60C.FocusPos = 5;
        else if (dir == 1)
            g_021DE60C.FocusPos = 0;
        else
            g_021DE60C.FocusPos = 3;
        break;
    case 5:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 1;
        if (dir == 0)
            g_021DE60C.FocusPos = 4;
        else if (dir == 2)
            g_021DE60C.FocusPos = 6;
        else if (dir == 1)
            g_021DE60C.FocusPos = 1;
        else
            g_021DE60C.FocusPos = 3;
        break;
    case 6:
        ((MEMSSSA *)g_021DE60C.MemSssa)->column = 2;
        if (dir == 0)
            g_021DE60C.FocusPos = 5;
        else if (dir == 2)
            g_021DE60C.FocusPos = 4;
        else if (dir == 1)
            g_021DE60C.FocusPos = 2;
        else
            g_021DE60C.FocusPos = 3;
        break;
    }
    if (move) {
        func_021CFFAC(8);
        func_021CC46C();
    }
}


static void dispPushClear(void)
{
    int fp = scenesetselectap_bss.FocusPos - 4;

    DWCi_CEINlSet(0, 0x32, DWCi_CELLlGetObj(scenesetselectap_bss.MemSssa->cellB[fp], 0));
    DWCi_CELLlSetPosition(scenesetselectap_bss.MemSssa->cellB[fp], -1, C_CELL[fp + 3].x, C_CELL[fp + 3].y);
    DWCi_CELLlSetPriority(scenesetselectap_bss.MemSssa->cellB[fp], -1, 3);
}
