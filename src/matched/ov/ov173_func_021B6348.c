/*
 * function: POKE_SUMMARY_MAIN_DeleteTaskMenu
 * address: 0x021B6348
 * packet: pkt_ov173_021B6348
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two zero alignment bytes at 021B638E.
 * symbols:
 *   POKE_SUMMARY_ACTOR_ToggleTaskMenu 0x021B7EB0 thumb ov173
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 */
#include "../include/Obj00362.h"
typedef unsigned int u32;
typedef unsigned char u8;
extern void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *p, int flag);
struct PrintSys;
struct TaskMenuState;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
void POKE_SUMMARY_MAIN_DeleteTaskMenu(u8 *p)
{
    POKE_SUMMARY_ACTOR_ToggleTaskMenu((char *)p, 0);
    STRBUF_Delete((struct U16Vec *)(((struct Obj00362 *)p)->f1E4));
    STRBUF_Delete((struct U16Vec *)(((struct Obj00362 *)p)->f1F0));
    STRBUF_Delete((struct U16Vec *)(((struct Obj00362 *)p)->f1FC));
    STRBUF_Delete((struct U16Vec *)(((struct Obj00362 *)p)->f208));
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj00362 *)p)->f1DC));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00362 *)p)->f218));
}
