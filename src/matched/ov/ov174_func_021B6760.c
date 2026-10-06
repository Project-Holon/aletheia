/*
 * function: func_021B6760
 * address:  0x021B6760
 * packet:   pkt_021B6760
 * region:   ov174
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_02049B90  0x02049B90  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201C440  0x0201C440  thumb
 *   func_02028590  0x02028590  thumb
 *   func_0201DD78  0x0201DD78  thumb
 */
#include "../include/Obj00918.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GfFont;
struct MsgBank;
struct Tcbl;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u8 func_0201F548(int i);
extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201DD68(void);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern u32 func_02028590(int a, int b, int c, u32 d);
extern void func_0201DD78(u32 r, u32 g, u32 b);

void func_021B6760(u8 *p)
{
    ((struct Obj00918 *)p)->f60 = (u32)func_0201D7EC(0x17, 0, 0, 0, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f68 = (u32)func_02045B38(0, 2, 0xc6, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f6C = (u32)func_02045B38(0, 2, (u16)(*(u16 *)(((struct Obj00918 *)p)->f30) + 0xbf), ((struct Obj00918 *)p)->f0);
    func_0201F5BC(0, 1, 0xd, 0, ((struct Obj00918 *)p)->f0);
    func_02049B90(5, func_0201F548(0), 0, 0x20, 0x1a0, 0x20, ((struct Obj00918 *)p)->f0);
    func_02049B40(0x17, 7, 0, 0x180, 0x20, ((struct Obj00918 *)p)->f0);
    func_0201DD68();
    ((struct Obj00918 *)p)->f58 = (u32)func_0203101C(((struct Obj00918 *)p)->f0, ((struct Obj00918 *)p)->f0, 3, 0x100);
    ((struct Obj00918 *)p)->f64 = 0;
    ((struct Obj00918 *)p)->f5C = 0;
    ((struct Obj00918 *)p)->f70 = 0;
    ((struct Obj00918 *)p)->f74 = 0;
    ((struct Obj00918 *)p)->f78 = func_0201C440((void *)(((struct Obj00918 *)p)->f0));
    ((struct Obj00918 *)p)->f7C = func_02028590(0xf, 1, 1, ((struct Obj00918 *)p)->f0);
    func_0201DD78(1, 2, 0xf);
}
