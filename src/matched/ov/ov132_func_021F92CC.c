/*
 * function: func_021F92CC
 * address: 0x021F92CC
 * packet: pkt_ov132_021F92CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   MSGDATA_CreateFromMemory 0x02045C44 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 */
#include "../include/Obj01257.h"
#include "../include/Obj23182.h"
#include "../include/Obj23183.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
struct Cfg;
struct GfFont;
struct MsgBank;
struct Tcbl;
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *);
void func_021F92CC(u8 *p)
{
    int zero;
    ((struct Obj01257 *)p)->fD0=func_020450F0(1,4,20,24,4,15,1);
    func_02045334((struct Descriptor *)((struct Obj01257 *)p)->fD0);
    func_02045374((struct Cfg *)(((struct Obj01257 *)p)->fD0));
    func_020409B4(1);
    zero=0;
    ((struct Obj01257 *)p)->fD4=(u32)func_0201D7EC(23,0,0,0,((struct Obj01257 *)p)->f0);
    ((struct Obj01257 *)p)->fDC=(u32)MSGDATA_CreateFromMemory(((struct Obj23183 *)(*(u8 * *)&((struct Obj23182 *)(*(u8 * *)&((struct Obj01257 *)p)->f30))->f18))->f8,((struct Obj01257 *)p)->f0);
    func_02049B40(23,5,0,480,32,((struct Obj01257 *)p)->f0);
    ((struct Obj01257 *)p)->fCC=(u32)func_0203101C(((struct Obj01257 *)p)->f0,((struct Obj01257 *)p)->f0,3,256);
    ((struct Obj01257 *)p)->fD8=zero;
    ((struct Obj01257 *)p)->fE0=zero;
    ((struct Obj01257 *)p)->fE4=zero;
    ((struct Obj01257 *)p)->fE8=func_0201C440((void *)(u32)((struct Obj01257 *)p)->f0);
}
