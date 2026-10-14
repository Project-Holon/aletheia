/*
 * function: MAILVIEW_SetupStep
 * address: 0x021C4BFC
 * packet: pkt_ov136_021C4BFC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 0x021C4C9A..0x021C4C9C is a zero alignment halfword.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   MAILVIEW_InitBgs 0x021C4DE4 thumb ov136
 *   MAILVIEW_LoadGraphics 0x021C4EEC thumb ov136
 *   MAILVIEW_CreateWindows 0x021C515C thumb ov136
 *   MAILVIEW_InitActorSystem 0x021C5420 thumb ov136
 *   MAILVIEW_CreatePmsDraw 0x021C4D54 thumb ov136
 *   MAILVIEW_PrintSentences 0x021C5360 thumb ov136
 *   MAILVIEW_CreateButtons 0x021C5268 thumb ov136
 *   MAILVIEW_StartCursorBlendTask 0x021C4C9C thumb ov136
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 */
#include "../include/Obj00160.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MAILVIEW_InitBgs(u32 *p);
extern void MAILVIEW_LoadGraphics(u8 *);
extern void MAILVIEW_CreateWindows(u8 *);
extern void MAILVIEW_InitActorSystem(u8 *);
struct R;
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void MAILVIEW_CreatePmsDraw(u8 *);
extern void MAILVIEW_PrintSentences(u8 *);
extern void MAILVIEW_CreateButtons(u8 *);
extern void MAILVIEW_StartCursorBlendTask(u8 *);
int MAILVIEW_SetupStep(u8 *p)
{
    switch (((struct Obj00160 *)p)->f8) {
    case 0:
        ((struct Obj00160 *)p)->f20 = func_02045B38(0, 2, 60, (u16)((struct Obj00160 *)p)->f0);
        ((struct Obj00160 *)p)->f34 = STRBUF_Create(128, (u16)((struct Obj00160 *)p)->f0);
        MAILVIEW_InitBgs((u32 *)p);
        break;
    case 1:
        MAILVIEW_LoadGraphics(p);
        break;
    case 2:
        MAILVIEW_CreateWindows(p);
        break;
    case 3:
        MAILVIEW_InitActorSystem(p);
        ((struct Obj00160 *)p)->f108 = APP_TASKMENU_RES_Create(0, 8, (u32)(((struct Obj00160 *)p)->f24), (u32)(((struct Obj00160 *)p)->f98), (u16)((struct Obj00160 *)p)->f0);
        ((struct Obj00160 *)p)->f8 = 0;
        MAILVIEW_CreatePmsDraw(p);
        MAILVIEW_PrintSentences(p);
        MAILVIEW_CreateButtons(p);
        MAILVIEW_StartCursorBlendTask(p);
        return 1;
    }
    (((struct Obj00160 *)p)->f8)++;
    return 0;
}
