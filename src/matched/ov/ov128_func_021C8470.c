/*
 * function: func_021C8470
 * address: 0x021C8470
 * packet: pkt_ov128_021C8470
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021C875C 0x021C875C thumb ov128
 *   func_021C8784 0x021C8784 thumb ov128
 *   d_021CA68C 0x021CA68C data a4
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 */
#include "../include/Obj06478.h"
typedef unsigned char u8;
extern void APP_TASKMENU_UpdateMenu(void *);
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u8 func_020355C4(void);
extern void func_021C875C(char *p, char *q);
extern void func_021C8784(char *);
extern const int d_021CA68C[][8];
int func_021C8470(u8 *p, int *a, void *b)
{
    int n;
    int result;
    APP_TASKMENU_UpdateMenu(((struct Obj06478 *)p)->f194);
    if (APP_TASKMENU_IsFinish(((struct Obj06478 *)p)->f194) == 1) {
        n = APP_TASKMENU_GetCursorPos(*(u8 * *)&((struct Obj06478 *)p)->f194);
        APP_TASKMENU_CloseMenu(((struct Obj06478 *)p)->f194);
    } else return 8;
    if (n == 3) {
        *a = func_020355C4();
        result = 2;
    } else {
        *a = func_020355C4();
        result = d_021CA68C[((struct Obj06478 *)p)->f198][n * 2];
    }
    if (result == 2) func_021C875C((char *)p, b);
    else if (result == 9 || result == 12) func_021C875C((char *)p, b);
    else func_021C8784((char *)p);
    return result;
}
