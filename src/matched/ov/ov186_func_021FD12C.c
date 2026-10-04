/*
 * function: func_021FD12C
 * address: 0x021FD12C
 * packet: pkt_ov186_021FD12C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 */
#include "../include/Obj02901.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void *func_021FC6A4(u16,u32,u16,u16,u8,u8,void *,u16);
void *func_021FD12C(int a,void *owner,u16 heap)
{
    u8 *p;
    func_021FB964((void *)a,2,heap);
    p=func_021FC6A4(0,1,19,30,4,2,owner,heap);
    ((struct Obj02901 *)p)->f14=12;
    return p;
}
