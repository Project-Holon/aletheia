/*
 * function: func_021D54F4
 * address: 0x021D54F4
 * packet: pkt_ov123_021D54F4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 02028590 is declared returning the live r0 used by the original
 * store at 021D55AC; its legacy matched source declares void.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02045088 0x02045088 arm
 *   func_0203101C 0x0203101C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   d_021DAA30 0x021DAA30 data a1
 */
#include "../include/Obj00499.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DAA30[];
extern void *func_02030734(u32,u32,int,const char *,u16);
struct GfFont;
struct R;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02028590(u32,u32,u32,u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
u8 *func_021D54F4(u32 heap,u32 bank)
{
    u8 *p;
    p=func_02030734(heap,0xb4,1,d_021DAA30,0x96);
    ((struct Obj00499 *)p)->fB0=heap;
    ((struct Obj00499 *)p)->f24=func_0201EC64(((struct Obj00499 *)p)->fB0);
    func_02045088(((struct Obj00499 *)p)->fB0); func_0201DD60();
    ((struct Obj00499 *)p)->f84=func_0203101C(((struct Obj00499 *)p)->fB0,((struct Obj00499 *)p)->fB0,2,0);
    ((struct Obj00499 *)p)->f88=func_0201C440((void *)(u32)((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f2C=func_020457B0(400,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f30=func_020457B0(400,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f28=func_0201D7EC(23,0,0,0,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f20=func_02045B38(0,2,(u16)bank,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f40=func_02028590(15,1,1,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->fA4=func_02027F60(5,9,*(u32 *)&((struct Obj00499 *)p)->f28,((struct Obj00499 *)p)->f88,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f8=func_0201F5DC((void *)5,12,0,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f4=func_0201F5DC((void *)6,12,0,((struct Obj00499 *)p)->fB0);
    func_02049B40(23,5,4,352,32,((struct Obj00499 *)p)->fB0);
    func_02049B40(23,5,0,352,32,((struct Obj00499 *)p)->fB0);
    return p;
}
