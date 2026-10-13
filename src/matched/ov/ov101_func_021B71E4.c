/*
 * function: func_021B71E4
 * address:  0x021B71E4
 * packet:   pkt_ov101_021B71E4
 * region:   ov101
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_WIN_IsTouch  0x0202824C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 */
#include "../include/Obj02158.h"

extern unsigned int APP_TASKMENU_WIN_IsTouch(void **p);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
typedef unsigned char  u8;
struct Obj;
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void APP_TASKMENU_WIN_Update(u8 *p);

void func_021B71E4(int a)
{
    if (((struct Obj02158 *)a)->f5C != 0) {
        switch (((struct Obj02158 *)a)->f50) {
        case 0:
            ((struct Obj02158 *)a)->f44 = -1;
            if (APP_TASKMENU_WIN_IsTouch((void **)(((struct Obj02158 *)a)->f0))) {
                func_020061E4(0x551);
                APP_TASKMENU_WIN_SetDecide((char *)(((struct Obj02158 *)a)->f0), 1);
                ((struct Obj02158 *)a)->f50 = 1;
            }
            break;
        case 1:
            if (APP_TASKMENU_WIN_IsFinish((u8 *)(((struct Obj02158 *)a)->f0))) {
                APP_TASKMENU_WIN_ResetDecide((struct Obj *)(((struct Obj02158 *)a)->f0));
                APP_TASKMENU_WIN_SetActive((struct Obj *)(((struct Obj02158 *)a)->f0), 0);
                ((struct Obj02158 *)a)->f50 = 2;
            }
            break;
        case 2:
            ((struct Obj02158 *)a)->f44 = 1;
            break;
        }
        APP_TASKMENU_WIN_Update((u8 *)(((struct Obj02158 *)a)->f0));
    }
}
