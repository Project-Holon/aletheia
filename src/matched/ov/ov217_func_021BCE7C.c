/*
 * function: func_021BCE7C
 * address: 0x021BCE7C
 * packet: pkt_ov217_021BCE7C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 * Original narrows heap at 020490F4; its extern takes u16.
 */
#include "../include/Obj00025.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
void func_021BCE7C(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c, d;
    heap = ((struct Obj00025 *)p)->f8;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = func_0204A6C8((void *)((u32)arc), 15, 0, 0, heap);
    b = func_0204AC18((void *)((u32)arc), 16, 0, 192, 0, 4, heap);
    c = func_0204AF28((void *)((u32)arc), 14, 17, heap);
    func_02049238(arc);
    arc = func_020490F4(83, (u16)heap);
    d = func_0204AC18((void *)((u32)arc), 31, 0, 128, 0, 2, heap);
    func_02049238(arc);
    ((struct Obj00025 *)p)->fF8 = a;
    ((struct Obj00025 *)p)->fFC = b;
    ((struct Obj00025 *)p)->f100 = c;
    ((struct Obj00025 *)p)->f104 = d;
}
