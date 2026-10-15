/*
 * function: WF2DMAP_TOUCH_DeleteScreens
 * address: 0x021C9154
 * packet: pkt_ov128_021C9154
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_TOUCH_ClearSlotArray 0x021CA444 thumb ov128
 *   WF2DMAP_TOUCH_AddSlot 0x021CA458 thumb ov128
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10489.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WF2DMAP_TOUCH_ClearSlotArray(char *);
extern void WF2DMAP_TOUCH_AddSlot(char *p, void *q);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 func_020307B0(void *p);
void WF2DMAP_TOUCH_DeleteScreens(char *p,int unused,char *q) { WF2DMAP_TOUCH_ClearSlotArray(q);WF2DMAP_TOUCH_AddSlot(q,q+12);BMP_WIN_Delete(((struct Obj10489 *)p)->f0);BMP_WIN_Delete(((struct Obj10489 *)p)->f8);func_020307B0(((struct Obj10489 *)p)->f10);}
