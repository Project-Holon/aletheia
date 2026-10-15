/*
 * function: BR_CODEIN_CodeStepPokeList
 * address: 0x021E024C
 * packet: pkt_ov183_021E024C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021E02F6
 * symbols:
 *   BR_UTIL_MainListMenu 0x021FCD0C thumb ov186
 *   BR_UTIL_GetListMenuHitId 0x021FCDA8 thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_CODEIN_CodeSetMenuText 0x021E03B0 thumb ov183
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 */
#include "../include/Obj00277.h"
#include "../include/Obj00351.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Sub0200852CObj;
extern void BR_UTIL_MainListMenu(char *p);
extern int BR_UTIL_GetListMenuHitId(char *p);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(int, int, int *);
extern void BR_CODEIN_CodeSetMenuText(char *, char *, int);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
int BR_CODEIN_CodeStepPokeList(char *p, char *q)
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
        void *v;
        int a;
        TOUCHPANEL_GetPointTrg(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        BR_UTIL_StartEffect(((struct Obj00277 *)p)->f40, 1, args);
        v = GAME_DATA_GetMyStatus(((struct Obj00351 *)q)->f10);
        a = func_0200856C(v);
        ((struct Obj00351 *)q)->f17 = func_02008570(v);
        ((struct Obj00351 *)q)->f16 = a;
        BR_CODEIN_CodeSetMenuText(p, q, 2);
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
