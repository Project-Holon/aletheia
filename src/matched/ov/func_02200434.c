/*
 * function: func_02200434
 * address:  0x02200434
 * packet:   pkt_02200434
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

 * Release the two +0xb88/+0xb8c handles.
 */
#include "../include/Obj12227.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);

void func_02200434(u8 *p)
{
    STRBUF_Delete((struct U16Vec *)(((struct Obj12227 *)p)->fB88));
    STRBUF_Delete((struct U16Vec *)(((struct Obj12227 *)p)->fB8C));
}
