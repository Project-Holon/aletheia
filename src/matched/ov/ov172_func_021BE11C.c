/*
 * function: func_021BE11C
 * address: 0x021BE11C
 * packet: pkt_ov172_021BE11C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj08262.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 a,b,c,d; } Descriptor;
typedef struct { u32 handle; u16 value; u16 pad; u32 zero; } Item;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02027778(Descriptor *,u32);
extern void func_02045808(struct U16Vec *vec);
u32 func_021BE11C(u8 *p)
{
    Descriptor x={0};
    Item items[2]={0};
    u32 result;
    items[0].handle=(u32)func_02045EC0((struct MsgBank *)(((struct Obj08262 *)p)->f1CC),34);
    items[1].handle=(u32)func_02045EC0((struct MsgBank *)(((struct Obj08262 *)p)->f1CC),35);
    items[0].value=14819;
    items[1].value=14819;
    items[0].zero=0;
    items[1].zero=0;
    x.heap=((struct Obj08262 *)p)->f0;
    x.count=2;
    x.items=items;
    x.a=24;
    x.b=6;
    x.c=8;
    x.d=3;
    x.zero=0;
    result=func_02027778(&x,((struct Obj08262 *)p)->f1D4);
    func_02045808((struct U16Vec *)items[0].handle);
    func_02045808((struct U16Vec *)items[1].handle);
    return result;
}
