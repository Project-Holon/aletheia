/*
 * function: BEACON_VIEW_TaskProc
 * address:  0x021F2588
 * packet:   pkt_ov032_021F2588
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_TaskProc 0x021F2588 thumb
 *   BEACON_VIEW_TaskStateArrowAnim 0x021F25D4 thumb ov032
 *   BEACON_VIEW_TaskStateTasks 0x021F2608 thumb ov032
 *   BEACON_VIEW_TaskStateTaskMenu 0x021F2624 thumb ov032
 *   GAME_EVENT_ChangeEvent 0x0201235C thumb
 */
#include "../include/Obj09800.h"

typedef unsigned char  u8;
extern int BEACON_VIEW_TaskStateArrowAnim(u8 *p, int *st);
extern int BEACON_VIEW_TaskStateTasks(char *, int *);
extern int BEACON_VIEW_TaskStateTaskMenu(int, int *);
typedef unsigned int   u32;
struct S0201235C;
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int BEACON_VIEW_TaskProc(int a0, int a1, int *st)
{
    int r;
    char *o;

    r = 0;
    o = (char *)st[3];
    switch (st[5]) {
    case 0:
        r = BEACON_VIEW_TaskStateArrowAnim((u8 *)o, st);
        break;
    case 1:
        r = BEACON_VIEW_TaskStateTasks(o, st);
        break;
    case 2:
        r = BEACON_VIEW_TaskStateTaskMenu((int)o, st);
        break;
    }
    if (r) {
        ((struct Obj09800 *)o)->f72 = 0;
        GAME_EVENT_ChangeEvent((struct S0201235C *)a0, (u32 *)st[4]);
    }
    return 0;
}
