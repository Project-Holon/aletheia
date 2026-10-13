/*
 * function: OEKAKI_CloseYesNoMenu
 * address: 0x02186694
 * packet: pkt_ov023_02186694
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x021866C2.
 * symbols:
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 */
#include "../include/Obj03625.h"
struct TaskMenu;
struct TaskMenuState;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
void OEKAKI_CloseYesNoMenu(char *p)
{
    APP_TASKMENU_CloseMenu(*(struct TaskMenu * *)&((struct Obj03625 *)p)->f178);
    STRBUF_Delete(((struct Obj03625 *)p)->f188);
    STRBUF_Delete(((struct Obj03625 *)p)->f17C);
    APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj03625 *)p)->f174);
    *(int *)&((struct Obj03625 *)p)->f178 = 0;
}
