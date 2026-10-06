/*
 * function: func_021B9CBC
 * address: 0x021B9CBC
 * packet: pkt_ov110_021B9CBC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00135.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);
void func_021B9CBC(u8 *p)
{
    func_02030EAC(*(void **)(*(u32 *)&((struct Obj00135 *)p)->f0 + ((struct Obj00135 *)p)->f10 * 4 + 8));
    *(u32 *)(*(u32 *)&((struct Obj00135 *)p)->f0 + ((struct Obj00135 *)p)->f10 * 4 + 8) = 0;
    func_020307B0(p);
}
