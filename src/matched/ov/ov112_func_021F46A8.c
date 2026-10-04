/*
 * function: func_021F46A8
 * address: 0x021F46A8
 * packet: pkt_ov112_021F46A8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte padding at 0x021F4746.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0203101C 0x0203101C arm
 */
#include "../include/Obj01147.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
struct Cfg;
struct GfFont;
struct MsgBank;
struct Tcbl;
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049B40(int,int,int,int,int,u16);
extern void func_0201DD68(u32);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
void func_021F46A8(u8 *p)
{
    int zero;
    ((struct Obj01147 *)p)->f1C=func_020450F0(4,1,1,30,4,10,1);
    func_02045334((struct Descriptor *)((struct Obj01147 *)p)->f1C);
    func_02045374((struct Cfg *)(((struct Obj01147 *)p)->f1C));
    func_020409B4(4);
    zero=0;
    ((struct Obj01147 *)p)->f20=(u32)func_0201D7EC(23,0,0,0,((struct Obj01147 *)p)->f0);
    ((struct Obj01147 *)p)->f28=(u32)func_02045B38(0,2,78,((struct Obj01147 *)p)->f0);
    func_0201F5BC(4,1,11,0,((struct Obj01147 *)p)->f0);
    func_0201DD68(func_02049B40(23,5,4,320,32,((struct Obj01147 *)p)->f0));
    ((struct Obj01147 *)p)->f18=(u32)func_0203101C(((struct Obj01147 *)p)->f0,((struct Obj01147 *)p)->f0,3,256);
    ((struct Obj01147 *)p)->f24=zero;
    ((struct Obj01147 *)p)->f2C=zero;
    ((struct Obj01147 *)p)->f30=zero;
    ((struct Obj01147 *)p)->f34=zero;
    ((struct Obj01147 *)p)->f38=func_0201C440((void *)(((struct Obj01147 *)p)->f0));
}
