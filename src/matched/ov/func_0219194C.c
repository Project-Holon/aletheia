/*
 * function: FIELD_MSGBG_FreeSubMsgWin
 * address:  0x0219194C
 * packet:   pkt_0219194C
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
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07210.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TALKMSGWIN_Release(u8 *p, int i);

int FIELD_MSGBG_FreeSubMsgWin(void *a)
{
if (((struct Obj07210 *)((u8 *)(a)))->f0 != 0) {
    STRBUF_Delete((struct U16Vec *)(((struct Obj07210 *)((u8 *)(a)))->f0));
}
TALKMSGWIN_Release((u8 *)(((struct Obj07210 *)((u8 *)(a)))->fC), ((struct Obj07210 *)((u8 *)(a)))->f8);
return func_020307B0(a);
}

