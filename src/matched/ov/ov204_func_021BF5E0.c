/*
 * function: func_021BF5E0
 * address: 0x021BF5E0
 * packet: pkt_ov204_021BF5E0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02015BA4 0x02015BA4 thumb
 *   func_02014BA8 0x02014BA8 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj14626.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02015BA4(void *,void *);
extern void func_02014BA8(u8 *);
extern void func_020307B0(void *);
void func_021BF5E0(u8 *p)
{
    int i;
    for(i=0;i<8;i++)if(*(void **)((u32)p+(u32)i*12+8)!=0)func_02015BA4(((struct Obj14626 *)p)->f4,*(void **)((u32)p+(u32)i*12+8));
    func_02014BA8(*(u8 * *)&((struct Obj14626 *)p)->f4);
    func_020307B0(p);
}
