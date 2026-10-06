/*
 * function: func_021D7550
 * address: 0x021D7550
 * packet: pkt_ov120_021D7550
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021D73D8 0x021D73D8 thumb ov120
 */
#include "../include/Obj00625.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_02041B6C(u32);
extern void func_021D73D8(u8 *);
void func_021D7550(u8 *p)
{
    void *t=func_020490F4(144,((struct Obj00625 *)p)->fF4);
    func_02049990(t,14,2,0,(u16)(((struct Obj00625 *)p)->f4),0,0,((struct Obj00625 *)p)->fF4);
    func_02049990(t,13,0,0,(u16)(((struct Obj00625 *)p)->f4),0,0,((struct Obj00625 *)p)->fF4);
    func_02049990(t,16,3,0,(u16)(((struct Obj00625 *)p)->f4),0,0,((struct Obj00625 *)p)->fF4);
    func_02049238(t);
    func_021D73D8(p);
    func_02041B6C(2); func_02041B6C(0); func_02041B6C(3);
    ((struct Obj00625 *)p)->f110=0;
    ((struct Obj00625 *)p)->f114=1;
}
