/*
 * function: Wf2dmapFriend_DeleteItemWidgets
 * address: 0x021C7D48
 * packet: pkt_ov128_021C7D48
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_TOUCH_ClearSlotArray 0x021CA444 thumb ov128
 *   WF2DMAP_TOUCH_AddSlot 0x021CA458 thumb ov128
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WIFI_2DCHAR_ReleaseBmpCells 0x021C4080 thumb ov127
 *   WIFI_2DCHAR_Delete 0x021C3F80 thumb ov127
 *   Wf2dmapFriend_NoopC 0x021C88BC thumb ov128
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 */
#include "../include/Obj03281.h"
typedef unsigned char u8;
extern void WF2DMAP_TOUCH_ClearSlotArray(char *);
extern void WF2DMAP_TOUCH_AddSlot(char *p, void *q);
struct Descriptor;
struct Obj;
struct TaskMenuState;
struct U16Vec;
extern void CLACT_DeleteActor(struct Obj *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void WIFI_2DCHAR_ReleaseBmpCells(u8 *p);
extern void WIFI_2DCHAR_Delete(u8 *);
extern void Wf2dmapFriend_NoopC(void *a0, void *a1);
void Wf2dmapFriend_DeleteItemWidgets(u8 *p, void *unused, u8 *a)
{
    int i;
    int offset;
    WF2DMAP_TOUCH_ClearSlotArray((char *)a);
    WF2DMAP_TOUCH_AddSlot((char *)a,a + 12);
    CLACT_DeleteActor(((struct Obj03281 *)p)->f1A4);
    CLACT_DeleteActor(((struct Obj03281 *)p)->f1A0);
    BMP_WIN_Delete(((struct Obj03281 *)p)->f108);
    STRBUF_Delete(((struct Obj03281 *)p)->f110);
    APP_TASKMENU_RES_Delete(((struct Obj03281 *)p)->f190);
    STRBUF_Delete(((struct Obj03281 *)p)->f178);
    STRBUF_Delete(((struct Obj03281 *)p)->f184);
    offset=0x1a4;
    i=0;
    offset=0x118;
    for (; i < 4; i++) {
        STRBUF_Delete(*(void **)(p + i * 12 + offset));
        STRBUF_Delete(*(void **)(p + i * 12 + 0x148));
    }
    WIFI_2DCHAR_ReleaseBmpCells(((struct Obj03281 *)p)->f104);
    WIFI_2DCHAR_Delete(*(u8 * *)&((struct Obj03281 *)p)->f104);
    for(i=0;i<3;i++) Wf2dmapFriend_NoopC(p + 12 + i * 0x4c,a);
    for(i=0;i<2;i++) BMP_WIN_Delete(*(void **)(p + i * 8 + 0xf0));
}
