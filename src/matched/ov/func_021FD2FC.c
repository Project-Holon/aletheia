/*
 * function: func_021FD2FC
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
 *

 * Release the +0xb90, +0xb94 and +0xb88 handles.
 */
#include "../include/Obj09237.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);

void func_021FD2FC(u8 *p)
{
    func_02045808((struct U16Vec *)(((struct Obj09237 *)p)->fB90));
    func_02045808((struct U16Vec *)(((struct Obj09237 *)p)->fB94));
    func_02045808((struct U16Vec *)(((struct Obj09237 *)p)->fB88));
}
