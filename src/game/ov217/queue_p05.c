/*
 * file:     queue_p05.c
 * unit:     yes
 * function: func_021C0AF0, func_021C0AF8, func_021C0B0C
 * address:  0x021C0AF0
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
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
#include "../../matched/include/Obj00791.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_0204A5AC(void);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
void func_021C0AF0(void);
void func_021C0AF8(void *p);
void func_021C0B0C(u8 *p);


/*
 * Tail-call veneer: branch to func_0204A5AC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0AF0(void)
{
    func_0204A5AC();
}


/*
 * Clear three u32 slots at +0x14.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0AF8(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x14) = 0;
}

void func_021C0B0C(u8 *p)
{
    u16 heap = ((struct Obj00791 *)p)->f0;
    void *h = func_020490F4(83, (u16)((heap & 0x7FFF) | 0x8000));
    int a = func_0204A6C8((void *)((u32)h), 20, 0, 0, heap);
    int b = func_0204AC18((void *)((u32)h), 19, 0, 0, 0, 4, heap);
    int c = func_0204AF28((void *)((u32)h), 21, 24, heap);
    ((struct Obj00791 *)p)->f14 = a;
    ((struct Obj00791 *)p)->f18 = b;
    ((struct Obj00791 *)p)->f1C = c;
    func_02049238(h);
}
