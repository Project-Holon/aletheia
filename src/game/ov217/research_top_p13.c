/*
 * file:     research_top_p13.c
 * unit:     yes
 * function: func_021BCDF0, func_021BCE5C, func_021BCE7C
 * address:  0x021BCDF0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AC18 0x0204AC18 arm
 */
#include "../../matched/include/Obj00025.h"
#include "../../matched/include/Obj10957.h"

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef signed char    s8;

typedef signed short   s16;

extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_0204AFD8();
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
void func_021BCDF0(char *p);
u32 func_021BCE5C(u32 a0);
void func_021BCE7C(char *p);

/*
 * 0204ABF0 is void in its source but forwards to the int-returning
 * 0204AC18; the original stores its live r0 result. 020490F4 narrows heap.
 */
void func_021BCDF0(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c;
    heap = ((struct Obj00025 *)p)->f8;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = func_0204A6C8((void *)((u32)arc), 15, 0, 1, heap);
    b = func_0204ABF0((void *)arc, 16, 1, 0, heap);
    c = func_0204AF28((void *)((u32)arc), 14, 17, heap);
    ((struct Obj00025 *)p)->f108 = a;
    ((struct Obj00025 *)p)->f10C = b;
    ((struct Obj00025 *)p)->f110 = c;
    func_02049238(arc);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BCE5C(u32 a0)
{
    func_0204A8D4(((struct Obj10957 *)(((u8*)a0)))->f108);
    func_0204ADA4(((struct Obj10957 *)(((u8*)a0)))->f10C);
    return func_0204AFD8(((struct Obj10957 *)(((u8*)a0)))->f110);
}

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
