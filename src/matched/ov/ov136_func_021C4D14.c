/*
 * function: MAILVIEW_Teardown
 * address:  0x021C4D14
 * packet:   pkt_ov136_021C4D14
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAILVIEW_Teardown 0x021C4D14 thumb
 *   MAILVIEW_DeletePmsDraw 0x021C4DA8 thumb
 *   MAILVIEW_ExitActorSystem 0x021C5470 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   MAILVIEW_DeleteWindows 0x021C52F8 thumb
 *   MAILVIEW_FreeGraphics 0x021C5114 thumb
 *   MAILVIEW_FreeBgs 0x021C4EC4 thumb
 */
#include "../include/Obj01751.h"
typedef unsigned char u8;
struct Rec;
struct TaskMenuState;
struct U16Vec;
extern void MAILVIEW_DeletePmsDraw(u8 *p);
extern void MAILVIEW_ExitActorSystem(u8 *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void MAILVIEW_DeleteWindows(u8 *p);
extern void MAILVIEW_FreeGraphics(u8 *p);
extern void MAILVIEW_FreeBgs(void *p);
int MAILVIEW_Teardown(u8 *p)
{
    MAILVIEW_DeletePmsDraw(p);
    MAILVIEW_ExitActorSystem(p);
    if (p + 0x28) MSGDATA_Delete(((struct Obj01751 *)p)->f20);
    STRBUF_Delete(((struct Obj01751 *)p)->f34);
    APP_TASKMENU_RES_Delete(((struct Obj01751 *)p)->f108);
    MAILVIEW_DeleteWindows(p);
    MAILVIEW_FreeGraphics(p);
    MAILVIEW_FreeBgs(p);
    return 1;
}
