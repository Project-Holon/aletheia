/*
 * function: func_021C7658
 * address: 0x021C7658
 * packet: pkt_ov136_021C7658
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021C76D0 0x021C76D0 thumb ov136
 * func_02025CD0 0x02025CD0 thumb
 * d_021C7E40 0x021C7E40 data a4
 * d_021C7E1C 0x021C7E1C data a4
 */
#include "../../../matched/include/Obj06533.h"
#include "../../../matched/include/Obj23659.h"
#include "../../../matched/include/Obj23660.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Struct_02025CD0;
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void func_021C76D0(u8 *p, u32 v);
extern const u8 d_021C7E40[],d_021C7E1C[];
void func_021C7658(u8 *p)
{
    int v;
    u16 n=((struct Obj23659 *)(*(u8 * *)&((struct Obj06533 *)p)->f8))->f2FE;
    if (((struct Obj06533 *)p)->f1C>n) { ((struct Obj06533 *)p)->f1C=n; v=0; }
    else v=p[0x1e];
    ((struct Obj23660 *)(*(u8 * *)&((struct Obj06533 *)p)->f8))->f294=(u32)func_02025CD0((u32)d_021C7E40,(u32)d_021C7E1C,(u32)p,1,v,102);
    func_021C76D0(p,v);
}
