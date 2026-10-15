/*
 * function: func_021C72A0
 * address: 0x021C72A0
 * packet: pkt_ov128_021C72A0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_TOUCH_ClearSlotArray 0x021CA444 thumb ov128
 *   WF2DMAP_TOUCH_AddSlot 0x021CA458 thumb ov128
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj04505.h"
typedef unsigned char u8;
extern void WF2DMAP_TOUCH_ClearSlotArray(char *);
extern void WF2DMAP_TOUCH_AddSlot(char *p, void *q);
struct Descriptor;
struct TaskMenuState;
struct U16Vec;
extern unsigned int APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021C72A0(u8 *p, u8 *unused, u8 *q)
{
    WF2DMAP_TOUCH_ClearSlotArray((char *)q);
    WF2DMAP_TOUCH_AddSlot((char *)q,q+12);
    APP_TASKMENU_RES_Delete(((struct Obj04505 *)p)->f48);
    STRBUF_Delete(((struct Obj04505 *)p)->f30);
    STRBUF_Delete(((struct Obj04505 *)p)->f3C);
    STRBUF_Delete(((struct Obj04505 *)p)->f2C);
    BMP_WIN_Delete(((struct Obj04505 *)p)->f1C);
    BMP_WIN_Delete(((struct Obj04505 *)p)->fC);
    func_020307B0(((struct Obj04505 *)p)->f14);
}
