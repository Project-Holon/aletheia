/*
 * function: FIELD_MSGBG_DeleteInfoSysWin
 * address:  0x02191008
 * packet:   pkt_02191008
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
 *   FIELD_MSGBG_DeleteMsgStream  0x02190D48  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgPrint  0x02190538  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   FIELD_MSGBG_ExitCursor  0x021927E8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
struct Slot;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void FIELD_MSGBG_DeleteMsgPrint(struct Slot *s);
extern int FIELD_MSGBG_DeleteMsgStream(void *a);
extern void FIELD_MSGBG_ExitCursor(u32 *p);
extern void FIELD_MSGBG_DeleteSysFrameWindow(u8 *p);

int FIELD_MSGBG_DeleteInfoSysWin(u32 a)
{
FIELD_MSGBG_DeleteSysFrameWindow((u8 *)(((struct Obj00005 *)((u8 *)(a)))->f0));
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    FIELD_MSGBG_DeleteMsgStream((void *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8 != 0) {
    FIELD_MSGBG_DeleteMsgPrint((struct Slot *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8));
}
STRBUF_Delete((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f10));
FIELD_MSGBG_ExitCursor((u32 *)(a + 24));
return func_020307B0(a);
}

