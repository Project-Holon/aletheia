/*
 * function: func_021C69C4
 * address: 0x021C69C4
 * packet: pkt_ov128_021C69C4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02045088 0x02045088 arm
 *   func_021C63AC 0x021C63AC thumb ov128
 *   func_020457B0 0x020457B0 arm
 */
#include "../include/Obj08126.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct U16Vec;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02045088(u16 heapId);
extern void func_021C63AC(void *,u32 *,u32,u32,u8,u8,u8,u8,u32,u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
void func_021C69C4(u8 *p,const u8 *q,u16 heap)
{
    func_02049B40(23,5,0,320,32,heap);
    func_02049B40(23,5,4,448,32,heap);
    func_0201F5BC(1,70,11,q[13],heap);
    func_02045088(heap);
    func_021C63AC(p,(u32 *)(p+12),1,1,0,24,3,10,100,0);
    ((struct Obj08126 *)p)->f14=func_020457B0(128,heap);
    ((struct Obj08126 *)p)->f18=func_020457B0(128,heap);
    ((struct Obj08126 *)p)->f1C=func_020457B0(128,heap);
    ((struct Obj08126 *)p)->f20=func_020457B0(128,heap);
}
