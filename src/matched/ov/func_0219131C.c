/*
 * function: FIELD_MSGBG_ClearTalkWin
 * address:  0x0219131C
 * packet:   pkt_0219131C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   TALKMSGWIN_Release  0x0219492C  thumb  ov021
 *   FIELD_MSGBG_ExitCursor  0x021927E8  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
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
extern u32 func_02082BCC(u32, u32, u32);
extern void FIELD_MSGBG_ExitCursor(u32 *p);
extern void TALKMSGWIN_Release(u8 *p, int i);

int FIELD_MSGBG_ClearTalkWin(u32 a)
{
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    STRBUF_Delete((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
TALKMSGWIN_Release((u8 *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8), *(u8 *)((u8 *)(a) + 1));
FIELD_MSGBG_ExitCursor((u32 *)(a + 12));
return func_02082BCC(a, 0, 52);
}

