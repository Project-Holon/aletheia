/*
 * function: FIELD_MSGBG_DeleteInfoMsgWin
 * address:  0x0219082C
 * packet:   pkt_0219082C
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
 *   FIELD_MSGBG_DeleteSysFrameWindow  0x02192BC0  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgPrint  0x02190538  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12067.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
struct Slot;
extern void FIELD_MSGBG_DeleteMsgPrint(struct Slot *s);
extern void FIELD_MSGBG_DeleteSysFrameWindow(u8 *p);

int FIELD_MSGBG_DeleteInfoMsgWin(void *a)
{
FIELD_MSGBG_DeleteSysFrameWindow((u8 *)(((struct Obj12067 *)((u8 *)(a)))->f0));
FIELD_MSGBG_DeleteMsgPrint((struct Slot *)(((struct Obj12067 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}

