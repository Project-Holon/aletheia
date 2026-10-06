/*
 * function: func_021BC07C
 * address: 0x021BC07C
 * packet: pkt_ov217_021BC07C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: original visibly supplies r1 to C0F5C; preserve second argument omitted by legacy source.
 * symbols:
 *   func_021C0F5C 0x021C0F5C thumb ov217
 *   d_021C309E 0x021C309E data a1
 *   d_021C3094 0x021C3094 data a1
 *   d_021C30D0 0x021C30D0 data a1
 *   d_021C30A8 0x021C30A8 data a1
 *   d_021C3080 0x021C3080 data a1
 *   d_021C308A 0x021C308A data a1
 */
#include "../include/Obj05558.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021C0F5C(u32 object,u32 value);
extern const u8 d_021C309E[],d_021C3094[],d_021C30D0[],d_021C30A8[],d_021C3080[],d_021C308A[];
int func_021BC07C(u8 *p, u8 index)
{
    func_021C0F5C(((struct Obj05558 *)p)->fE4,d_021C309E[index]);
    func_021C0F5C(((struct Obj05558 *)p)->fE8,d_021C3094[index]);
    func_021C0F5C(((struct Obj05558 *)p)->fEC,d_021C30D0[d_021C30A8[index]]);
    func_021C0F5C(((struct Obj05558 *)p)->fF0,d_021C30D0[d_021C3080[index]]);
    return func_021C0F5C(((struct Obj05558 *)p)->fF4,d_021C30D0[d_021C308A[index]]);
}
