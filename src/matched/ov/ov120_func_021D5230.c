/*
 * function: GTSNEGO_DISP_ListCursorUp
 * address: 0x021D5230
 * packet: pkt_ov120_021D5230
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D5282 precede labelled 0x021D5284.
 * symbols:
 *   GTSNEGO_MSG_CursorUp 0x021D6E50 thumb ov120
 *   GTSNEGO_MSG_SetScrollState 0x021D6FF8 thumb ov120
 *   GTSNEGO_MSG_PrintListEntryN 0x021D82D8 thumb ov120
 */
#include "../include/Obj04486.h"
typedef unsigned char u8;
extern int GTSNEGO_MSG_CursorUp(void *unused, int *p);
extern void GTSNEGO_MSG_SetScrollState(u8 *p, int state);
extern void GTSNEGO_MSG_PrintListEntryN(char *p, void *q, int n);
int GTSNEGO_DISP_ListCursorUp(u8 *p)
{
    int result = GTSNEGO_MSG_CursorUp(((struct Obj04486 *)p)->f3C, (int *)(p + 0x150));
    switch (result) {
    case 0: break;
    case 1:
        if (((struct Obj04486 *)p)->f164 != 6)
            (((struct Obj04486 *)p)->f164)--;
        break;
    case 2: {
        int index;
        GTSNEGO_MSG_SetScrollState(((struct Obj04486 *)p)->f3C, 1);
        index = ((struct Obj04486 *)p)->f158 - 1;
        if (index >= 0)
            GTSNEGO_MSG_PrintListEntryN(((struct Obj04486 *)p)->f40, ((struct Obj04486 *)p)->f2C, index);
        break;
    }
    }
    return result;
}
