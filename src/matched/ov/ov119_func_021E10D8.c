/*
 * function: func_021E10D8
 * address: 0x021E10D8
 * packet: pkt_ov119_021E10D8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02028590 tail forwarder has a void legacy declaration; caller stores its live r0 at 021E117E.
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0203101C 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   func_02027F60 0x02027F60 thumb
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;
struct MsgBank;
struct R;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201C440(void *p);
extern void func_0201DD78(u32,u32,u32);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(u32,u32,u32,u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
void func_021E10D8(char *p)
{
    ((struct Obj00001 *)p)->f724=func_0201EC64(((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f720=func_02045B38(0,2,159,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f728=func_0201D7EC(23,0,0,0,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f730=func_020457B0(128,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f734=func_020457B0(128,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f738=func_020457B0(128,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f73C=func_020457B0(128,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f740=(void *)func_0201C440((void *)(((struct Obj00001 *)p)->f5F4));
    func_0201DD78(1,2,15);
    ((struct Obj00001 *)p)->f744=func_0203101C(((struct Obj00001 *)p)->f5F4,((struct Obj00001 *)p)->f5F4,2,0);
    ((struct Obj00001 *)p)->f74C=func_02028590(15,1,0,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f6B0=func_02027F60(6,9,*(u32 *)&((struct Obj00001 *)p)->f728,*(u32 *)&((struct Obj00001 *)p)->f740,((struct Obj00001 *)p)->f5F4);
}
