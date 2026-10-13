/*
 * function: procErase
 * address:  0x021CC740
 * packet:   pkt_ov016_021CC740
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procErase (libdwcutil.TWL.HYB.a scenesetselectap)
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
 *   C_CELL                       0x021DA72C  data
 *   sSceneSetSelectApCellPosY                       0x021DA72E  data
 *   procErase1                       0x021CC8A0  arm   ov016
 */

#include "../include/G_SCENESETSELECTAP_BSS.h"

struct tagCOORD {
    unsigned short x;
    unsigned short y;
};
struct selobj {
    int f0;
    void *a[3];
    void *b[3];
};

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
extern struct SCENESETSELECTAP_BSS g_021DE60C;
extern struct tagCOORD C_CELL[6];
extern struct tagCOORD sSceneSetSelectApCellPosY[6];

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
        DWCi_CELLlSetPosition(g_021DE60C.MemSssa->a[ix], -1, C_CELL[ix].x, sSceneSetSelectApCellPosY[ix].x);
        DWCi_CELLlSetPriority(g_021DE60C.MemSssa->a[ix], -1, 3);
        DWCi_CELLlDelete(g_021DE60C.MemSssa->b[ix]);
        g_021DE60C.MemSssa->b[ix] = 0;
        break;
    case 0:
        DWCi_SNDlPlay(7);
        DWCi_CEINlSet(0, 0x11, DWCi_CELLlGetObj(g_021DE60C.MemSssa->b[ix], 0));
        DWCi_CELLlSetPosition(g_021DE60C.MemSssa->b[ix], -1, C_CELL[ix + 3].x, sSceneSetSelectApCellPosY[ix + 3].x);
        DWCi_CELLlSetPriority(g_021DE60C.MemSssa->b[ix], -1, 3);
        break;
    default:
        return;
    }
    DWCi_WINlEnd();
    DWCi_ChangeScene(procErase1);
}
