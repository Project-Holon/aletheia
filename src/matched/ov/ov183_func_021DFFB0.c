/*
 * function: func_021DFFB0
 * address: 0x021DFFB0
 * packet: pkt_ov183_021DFFB0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_MainListMenu 0x021FCD0C thumb ov186
 *   BR_UTIL_GetListMenuHitId 0x021FCDA8 thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   func_021E03B0 0x021E03B0 thumb ov183
 */
#include "../include/Obj00277.h"
#include "../include/Obj00351.h"
typedef unsigned int   u32;
extern void BR_UTIL_MainListMenu(char *p);
extern int BR_UTIL_GetListMenuHitId(char *p);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(int, int, int *);
extern void func_021E03B0(char *, char *, int);
int func_021DFFB0(char *p, char *q)
{
    int selected, pressed;
    unsigned int x, y;
    BR_UTIL_MainListMenu(((struct Obj00277 *)p)->f18);
    selected = BR_UTIL_GetListMenuHitId(((struct Obj00277 *)p)->f18);
    pressed = TOUCHPANEL_GetPointTrg(&x, &y);
    pressed &= BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj00277 *)p)->fC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        int args[2];
        TOUCHPANEL_GetPointTrg(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        BR_UTIL_StartEffect(((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00351 *)q)->f18 = selected;
        func_021E03B0(p, q, 0);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        int args[2];
        TOUCHPANEL_GetPointTrg(&x2, &y2);
        args[0] = x2;
        args[1] = y2;
        BR_UTIL_StartEffect(((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    }
    return 0;
}
