/*
 * function: FIELD_MSGBG_DeletePlainWin
 * address:  0x021915B4
 * packet:   pkt_021915B4
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
 *   FIELD_MSGBG_DeleteMsgStream  0x02190D48  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgPrint  0x02190538  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   TALKMSGWIN_DeleteFrameWindow  0x02194A48  thumb  ov021
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
extern u32 func_020307B0(void *p);
struct Slot;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void FIELD_MSGBG_DeleteMsgPrint(struct Slot *s);
extern int FIELD_MSGBG_DeleteMsgStream(void *a);
extern void FIELD_MSGBG_ExitCursor(u32 *p);
struct Descriptor;
extern u32 TALKMSGWIN_DeleteFrameWindow(u32 a, struct Descriptor *b);

int FIELD_MSGBG_DeletePlainWin(void *a)
{
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f1C != 0) {
    FIELD_MSGBG_DeleteMsgStream((void *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f1C));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f20 != 0) {
    FIELD_MSGBG_DeleteMsgPrint((struct Slot *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f20));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8 != 0) {
    STRBUF_Delete((struct U16Vec *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8));
}
TALKMSGWIN_DeleteFrameWindow(((struct Obj00005 *)((u8 *)(a)))->f10, (struct Descriptor *)(((struct Obj00005 *)((u8 *)(a)))->f18));
FIELD_MSGBG_ExitCursor((u32 *)a);
return func_020307B0(a);
}

