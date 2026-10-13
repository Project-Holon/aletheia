/*
 * function: FIELD_MSGBG_DeleteMenuFunc
 * address:  0x021909BC
 * packet:   pkt_021909BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *   FIELD_MSGBG_DeleteWindow  0x02193130  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgPrint  0x02190538  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07209.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj;
struct Slot;
extern u32 BMP_MENUWORK_Delete(void *p);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 func_020307B0(void *p);
extern void FIELD_MSGBG_DeleteMsgPrint(struct Slot *s);
struct Descriptor;
extern int FIELD_MSGBG_DeleteWindow(struct Descriptor *a);

int FIELD_MSGBG_DeleteMenuFunc(void *a)
{
BMP_MENULIST_Delete((struct Obj *)(((struct Obj07209 *)((u8 *)(a)))->f10), 0, 0);
BMP_MENUWORK_Delete((void *)(((struct Obj07209 *)((u8 *)(a)))->fC));
FIELD_MSGBG_DeleteWindow((struct Descriptor *)(((struct Obj07209 *)((u8 *)(a)))->f8));
FIELD_MSGBG_DeleteMsgPrint((struct Slot *)(((struct Obj07209 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}

