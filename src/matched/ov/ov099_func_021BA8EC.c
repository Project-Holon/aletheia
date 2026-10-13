/*
 * function: WIFICLUB_ClearTalkWindow
 * address: 0x021BA8EC
 * packet: pkt_ov099_021BA8EC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_DeleteTimeIcon 0x021BA8D4 thumb ov099
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned int u32;
struct PrintSys;
extern void WIFICLUB_DeleteTimeIcon(void *);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
struct Rec3;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern int WIFICLUB_DeleteWindow(void *);
void WIFICLUB_ClearTalkWindow(char *p)
{
    WIFICLUB_DeleteTimeIcon(p);
    if (PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj00008 *)p)->f1B8) == 0)
        PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj00008 *)p)->f1B8);
    if (((struct Obj00008 *)p)->f1BC != 0) {
        PRINTSYS_PrintStreamDelete(((struct Obj00008 *)p)->f1BC);
        *(int *)&((struct Obj00008 *)p)->f1BC = 0;
    }
    *(int *)&((struct Obj00008 *)p)->f190 = WIFICLUB_DeleteWindow(((struct Obj00008 *)p)->f190);
}
