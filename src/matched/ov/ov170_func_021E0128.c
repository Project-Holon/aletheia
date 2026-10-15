/*
 * function: BOX2_MAIN_IsSeqStep
 * address:  0x021E0128
 * packet:   pkt_ov170_021E0128
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_UI_IsInfoBarOpen 0x021EF770 thumb
 *   BOX2_UI_DeleteSlotIcon 0x021EDF5C thumb
 *   func_02041EE4 0x02041EE4 arm
 *   BOX2_SEQ_ShiftSlotIcons 0x021EC804 thumb
 *   BOX2_UI_ShiftSlotOams 0x021EE26C thumb
 *   BOX2_UI_UpdateListPacks 0x021EF5C4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23873.h"
#include "../include/Obj23874.h"
#include "../include/Obj23875.h"
#include "../include/Obj23876.h"
#include "../include/Obj23877.h"

struct WinMgr;
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr);
extern void BOX2_UI_DeleteSlotIcon(unsigned char *p);
extern void func_02041EE4(unsigned index, unsigned a, unsigned b);
extern void BOX2_SEQ_ShiftSlotIcons(char **p, short dx);
extern void BOX2_UI_ShiftSlotOams(char *p, int d);
extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);

int BOX2_MAIN_IsSeqStep(char *p)
{
    if (((struct Obj23873 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f66 == 0x17) {
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        if (BOX2_UI_IsInfoBarOpen(*(struct WinMgr * *)&((struct Obj23874 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 1)
            BOX2_UI_DeleteSlotIcon((unsigned char *)p);
        ((struct Obj23875 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f66 = 0;
        return 0;
    }
    func_02041EE4(3, 1, 8);
    BOX2_SEQ_ShiftSlotIcons((char **)p, -8);
    BOX2_UI_ShiftSlotOams(*(char * *)&((struct Obj00000 *)p)->f2C, -8);
    BOX2_UI_UpdateListPacks(*(struct WinMgr * *)&((struct Obj23876 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74);
    (((struct Obj23877 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f66)++;
    return 1;
}
