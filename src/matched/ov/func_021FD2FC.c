/*
 * function: WORLDTRADE_LIST_DeleteStrings
 * address:  0x021FD2FC
 * packet:   pkt_021FD2FC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm  arm9
 *

 * Release the +0xb90, +0xb94 and +0xb88 handles.
 */
#include "../include/Obj09237.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);

void WORLDTRADE_LIST_DeleteStrings(u8 *p)
{
    STRBUF_Delete((struct U16Vec *)(((struct Obj09237 *)p)->fB90));
    STRBUF_Delete((struct U16Vec *)(((struct Obj09237 *)p)->fB94));
    STRBUF_Delete((struct U16Vec *)(((struct Obj09237 *)p)->fB88));
}
