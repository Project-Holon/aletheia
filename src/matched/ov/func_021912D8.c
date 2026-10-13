/*
 * function: FIELD_MSGBG_DeleteTalkWin
 * address:  0x021912D8
 * packet:   pkt_021912D8
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
 *   STRBUF_Delete  0x02045808  arm
 *   FIELD_MSGBG_ExitCursor  0x021927E8  thumb  ov021
 *   TALKMSGWIN_Close  0x02194950  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void FIELD_MSGBG_ExitCursor(u32 *p);
extern u32 TALKMSGWIN_Close(u32, u32);

int FIELD_MSGBG_DeleteTalkWin(u32 a)
{
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    STRBUF_Delete((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
FIELD_MSGBG_ExitCursor((u32 *)(a + 12));
return TALKMSGWIN_Close(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8, *(u8 *)((u8 *)(a) + 1));
}

