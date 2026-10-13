/*
 * function: func_021BA138
 * address: 0x021BA138
 * packet: pkt_ov218_021BA138
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B991C 0x021B991C thumb ov218
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   func_021B9F98 0x021B9F98 thumb ov218
 *   func_021B9944 0x021B9944 thumb ov218
 *   func_021B9C74 0x021B9C74 thumb ov218
 *   func_021B9914 0x021B9914 thumb ov218
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 */
#include "../include/Obj04644.h"
extern void func_021B991C(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern unsigned char APP_TASKMENU_GetCursorPos(const unsigned char *);
extern void func_021B9F98(u8 *p, int mode);
extern void func_021B9944(void);
extern void func_021B9C74(u8 *p);
extern void func_021B9914(struct TaskMenu *p);
extern void UI_SCENE_SetNextScene(unsigned char *task, int value);
int func_021BA138(unsigned char *task, char *ctx)
{
    func_021B991C(((struct Obj04644 *)ctx)->f1C);
    if (APP_TASKMENU_IsFinish(((struct Obj04644 *)ctx)->f1C) != 0) {
        switch (APP_TASKMENU_GetCursorPos(((struct Obj04644 *)ctx)->f1C)) {
        case 0:
            func_021B9F98((u8 *)ctx, 0);
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            UI_SCENE_SetNextScene(task, 65534);
            break;
        case 1:
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            UI_SCENE_SetNextScene(task, 0);
            break;
        }
        return 1;
    }
    return 0;
}
