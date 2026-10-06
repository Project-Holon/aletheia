/*
 * function: func_021D7724
 * address: 0x021D7724
 * packet: pkt_ov120_021D7724
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: 0201EC74 heap widened because caller passes the entire ldrh value without byte truncation.
 * symbols:
 *   s_021D8BEC 0x021D8BEC data a1
 *   func_02030734 0x02030734 arm
 *   func_02045088 0x02045088 arm
 *   func_0203101C 0x0203101C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 */
#include "../include/Obj00496.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern const char s_021D8BEC[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
struct GfFont;
struct R;
struct Tcbl;
struct U16Vec;
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201EC74(u32,u32,u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
char *func_021D7724(u32 heap,u32 n)
{
    char *p=func_02030734(heap,0xd0,1,s_021D8BEC,0xa9);
    ((struct Obj00496 *)p)->fC8=heap;
    func_02045088(((struct Obj00496 *)p)->fC8);
    func_0201DD60();
    ((struct Obj00496 *)p)->fA0=func_0203101C(((struct Obj00496 *)p)->fC8,((struct Obj00496 *)p)->fC8,1,0);
    ((struct Obj00496 *)p)->fA4=(void *)func_0201C440((void *)(u32)((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f1C=func_020457B0(240,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f18=func_020457B0(240,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f20=func_020457B0(240,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f14=func_0201D7EC(23,0,0,0,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->fC=func_02045B38(0,2,(u16)n,(u16)(((struct Obj00496 *)p)->fC8));
    ((struct Obj00496 *)p)->f10=func_0201EC74(6,64,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->fC0=func_02027F60(5,9,*(u32 *)&((struct Obj00496 *)p)->f14,*(u32 *)&((struct Obj00496 *)p)->fA4,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f4=func_0201F5DC((void *)1,12,0,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f0=func_0201F5DC((void *)6,12,0,((struct Obj00496 *)p)->fC8);
    func_02049B40(23,5,4,0x160,32,((struct Obj00496 *)p)->fC8);
    func_02049B40(23,5,0,0x160,32,((struct Obj00496 *)p)->fC8);
    return p;
}
