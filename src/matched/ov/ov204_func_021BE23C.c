/*
 * unit: yes
 * function: func_021BE23C, func_021BE308, func_021BE314
 * address: 0x021BE23C
 * packet: pkt_ov204_021BE23C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: lead and two store/return followers; function_starts 021BE308,021BE314.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj25339.h"
#include "../include/Obj25341.h"
#include "../include/Obj25343.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *,u32,u32,void **,u16);
extern void MIi_CpuCopy16(const void *,void *,u32);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
int func_021BE23C(char *p,void *unused,int *state)
{
    u16 heap;
    void *arc,*out,*buf;
    heap=((struct Obj25339 *)p)->f0;
    arc=func_020490F4(0xAA,heap);
    func_02049B68(arc,1,0,0,64,heap);
    func_02049B68(arc,1,4,0,32,heap);
    func_02049658(arc,0,6,0,0,0,heap);
    func_020498F4(arc,2,6,0,0,0,heap);
    func_02049658(arc,0,3,0,0,0,heap);
    func_020498F4(arc,3,3,0,0,0,heap);
    if (*state==1) {
        func_02049658(arc,12,2,0,0,0,heap);
        buf=ARC_UTIL_LoadPaletteDataFromHandle(arc,14,0,(void **)&out,heap);
        MIi_CpuCopy16((char *)out+12,p+0xA8,4096);
        func_020307B0(buf);
    }
    ARC_TOOL_DeleteHandle(arc);
    return 1;
}
int func_021BE308(char *p,void *unused,u32 *r)
{
    ((struct Obj25343 *)(*(char * *)&((struct Obj25341 *)p)->f4))->f14=*r;
    return 1;
}
int func_021BE314(void *unused,int *q,int *r)
{
    if (q[1]>*r) return 1;
    q[1]++;
    return 0;
}
