/*
 * file:     unit_021CC0E8_p04.c
 * unit:     yes
 * function: func_021CC740, func_021CC8A0, func_021CC8C4
 * address:  0x021CC740
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
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SETTINGlErasePage           0x021CFBE4  arm
 *   DWCi_CELLlGetObj                 0x021D4FE0  arm
 *   DWCi_CEINlSet                    0x021D52D4  arm
 *   DWCi_CELLlSetPosition            0x021D5118  arm
 *   DWCi_CELLlSetPriority            0x021D51F0  arm
 *   DWCi_CELLlDelete                 0x021D4F60  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   g_021DE60C                       0x021DE60C  data
 *   g_021DA72C                       0x021DA72C  data
 *   g_021DA72E                       0x021DA72E  data
 *   DWCi_WINlIsInit                  0x021d157c arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   procScene                        0x021cbfd8 arm
 *   DWCi_SCREENlCopyPalette          0x021ce7b0 arm
 *   DWCi_SETTINGlGetSetType          0x021cf7f4 arm
 *   DWCi_CELLlSetPalette             0x021d5098 arm
 *   g_021DA7B4                      0x021da7b4 data
 *   g_021DA7B8                      0x021da7b8 data
 *   scenesetselectap_bss             0x021de60c data
 */
#include "../../matched/include/G_SCENESETSELECTAP_BSS.h"

struct tagCOORD {
    unsigned short x;
    unsigned short y;
};

struct selobj {
    int f0;
    void *a[3];
    void *b[3];
};

typedef _Bool bool;

/* the compiler's g_021DA7B4and g_021DA7B8initialisers, each in its own .rodata section */
typedef struct { unsigned char v[4]; } PLT4;

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

extern int DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_SETTINGlErasePage(int page);
extern void *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CEINlSet(int lcd, int idx, void *obj);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void DWCi_CELLlDelete(void *cell);
extern void DWCi_WINlEnd(void);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_WINlIsInit(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern int DWCi_SETTINGlGetSetType(int idx);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);
extern struct SCENESETSELECTAP_BSS g_021DE60C;
extern struct tagCOORD g_021DA72C[6];
extern struct tagCOORD g_021DA72E[6];
extern const PLT4 g_021DA7B4;
extern const PLT4 g_021DA7B8;
extern SCENESETSELECTAP_BSS scenesetselectap_bss;


static void procErase1(void);


static void procErase(void)
{
    int ix;

    ix = g_021DE60C.FocusPos - 4;
    switch (DWCi_WINlGet()) {
    case 1:
        DWCi_SNDlPlay(14);
        DWCi_SETTINGlErasePage(ix);
        DWCi_CEINlSet(0, 0x56, DWCi_CELLlGetObj(g_021DE60C.MemSssa->a[ix], 0));
        DWCi_CELLlSetPosition(g_021DE60C.MemSssa->a[ix], -1, g_021DA72C[ix].x, g_021DA72E[ix].x);
        DWCi_CELLlSetPriority(g_021DE60C.MemSssa->a[ix], -1, 3);
        DWCi_CELLlDelete(g_021DE60C.MemSssa->b[ix]);
        g_021DE60C.MemSssa->b[ix] = 0;
        break;
    case 0:
        DWCi_SNDlPlay(7);
        DWCi_CEINlSet(0, 0x11, DWCi_CELLlGetObj(g_021DE60C.MemSssa->b[ix], 0));
        DWCi_CELLlSetPosition(g_021DE60C.MemSssa->b[ix], -1, g_021DA72C[ix + 3].x, g_021DA72E[ix + 3].x);
        DWCi_CELLlSetPriority(g_021DE60C.MemSssa->b[ix], -1, 3);
        break;
    default:
        return;
    }
    DWCi_WINlEnd();
    DWCi_ChangeScene(procErase1);
}


static void procScene(void);


static void procErase1(void)
{
    if (DWCi_WINlIsInit()) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


static void dispPush(void)
{
    PLT4 PALETTE = g_021DA7B4;
    PLT4 OBJ_PLTT = g_021DA7B8;
    int type = scenesetselectap_bss.FocusPos;

    if ((unsigned int)type > 3) {
        return;
    }
    DWCi_SCREENlCopyPalette(scenesetselectap_bss.MemSssa->palette, PALETTE.v[type], PALETTE.v[type]);
    if (scenesetselectap_bss.FocusPos == 3) {
        return;
    }
    type = DWCi_SETTINGlGetSetType(scenesetselectap_bss.FocusPos);
    if (type > 2) {
        type = 3;
    }
    DWCi_CELLlSetPalette(scenesetselectap_bss.MemSssa->cellA[scenesetselectap_bss.FocusPos], -1, 0, OBJ_PLTT.v[type]);
}
