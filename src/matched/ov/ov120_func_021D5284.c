/*
 * function: GTSNEGO_DISP_ListCursorDown
 * address: 0x021D5284
 * packet: pkt_ov120_021D5284
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_CursorDown 0x021D6E1C thumb ov120
 *   GTSNEGO_MSG_SetScrollState 0x021D6FF8 thumb ov120
 *   GTSNEGO_MSG_PrintListEntryAt 0x021D822C thumb ov120
 */
#include "../include/Obj04487.h"
typedef unsigned char u8;
extern int GTSNEGO_MSG_CursorDown(void *unused, int *p);
extern void GTSNEGO_MSG_SetScrollState(u8 *p, int state);
extern void GTSNEGO_MSG_PrintListEntryAt(char *p, void *q, int index);
int GTSNEGO_DISP_ListCursorDown(u8 *p)
{
    int result = GTSNEGO_MSG_CursorDown(((struct Obj04487 *)p)->f3C, (int *)(p + 0x150));
    switch (result) {
    case 0: break;
    case 1:
        if (((struct Obj04487 *)p)->f164 != 8)
            (((struct Obj04487 *)p)->f164)++;
        break;
    case 2:
        GTSNEGO_MSG_SetScrollState(((struct Obj04487 *)p)->f3C, 2);
        GTSNEGO_MSG_PrintListEntryAt(((struct Obj04487 *)p)->f40, ((struct Obj04487 *)p)->f2C, ((struct Obj04487 *)p)->f158 + 2);
        break;
    }
    return result;
}
