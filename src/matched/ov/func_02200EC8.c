/*
 * function: func_02200EC8
 * address:  0x02200EC8
 * packet:   pkt_02200EC8
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

 *
 * Tail call into STRBUF_Delete with the pointer held at +0xb88.
 */
#include "../include/Obj18611.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);

void func_02200EC8(u8 *p)
{
    STRBUF_Delete((struct U16Vec *)(((struct Obj18611 *)p)->fB88));
}
