/*
 * function: POKE_SUMMARY_MAIN_UpdateMenu
 * address: 0x021B6AAC
 * packet: pkt_ov173_021B6AAC
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   POKE_SUMMARY_ACTOR_SetSubBrightness 0x021B81B0 thumb ov173
 *   d_021B8228 0x021B8228 data a4
 */
#include "../include/Obj08264.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef int (*Callback)(u8 *);
typedef struct { Callback a,b; } Pair;
extern Pair d_021B8228[];
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void APP_TASKMENU_UpdateMenu(u32);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void POKE_SUMMARY_ACTOR_SetSubBrightness(int);
int POKE_SUMMARY_MAIN_UpdateMenu(u8 *p)
{
    int result=4;
    if (APP_TASKMENU_IsFinish((struct TaskMenu *)(((struct Obj08264 *)p)->f1E0))) {
        if (APP_TASKMENU_GetCursorPos((const u8 *)(((struct Obj08264 *)p)->f1E0)) == 0)
            result=d_021B8228[p[0x1ba]].a(p);
        else
            result=d_021B8228[p[0x1ba]].b(p);
        POKE_SUMMARY_ACTOR_SetSubBrightness(0);
    }
    APP_TASKMENU_UpdateMenu(((struct Obj08264 *)p)->f1E0);
    if (result != 4) APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj08264 *)p)->f1E0));
    return result;
}
