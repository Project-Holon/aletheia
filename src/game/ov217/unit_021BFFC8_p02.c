/*
 * file:     unit_021BFFC8_p02.c
 * unit:     yes
 * function: func_021C0250, func_021C02A8, func_021C02C8, func_021C0358, func_021C0384, func_021C03A0
 * address:  0x021C0250
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
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204AC18 0x0204AC18 arm
 *   d_021C3620  0x021C3620  data  a2
 *   d_021C3618  0x021C3618  data  a1
 *   func_0204B100  0x0204B100  arm
 */
#include "../../matched/include/Obj08438.h"
#include "../../matched/include/Obj10960.h"
#include "../../matched/include/Obj06713.h"
#include "../../matched/include/Obj08439.h"
#include "../../matched/include/Obj25960.h"

struct Bank;
typedef unsigned int u32;

typedef unsigned short u16;

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
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
void func_021C0250(char *p);
u32 func_021C02A8(u32 a0);
void func_021C02C8(char *p);
u32 func_021C0358(u32 a0);
void func_021C0384(void *p);
void func_021C03A0(u8 *p);
extern const u16 d_021C3620[];
extern const u8 d_021C3618[];

void func_021C0250(char *p)
{
    u16 heap = ((struct Obj08438 *)p)->f4;
    void *h = func_020490F4(192, heap);
    int a = func_0204A6C8((void *)((u32)h), 15, 0, 1, heap);
    int b = func_0204ABF0((void *)h, 16, 1, 0, heap);
    int c = func_0204AF28((void *)((u32)h), 14, 17, heap);
    ((struct Obj08438 *)p)->f378 = a;
    ((struct Obj08438 *)p)->f37C = b;
    ((struct Obj08438 *)p)->f380 = c;
    func_02049238(h);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C02A8(u32 a0)
{
    func_0204A8D4(((struct Obj10960 *)(((u8*)a0)))->f378);
    func_0204ADA4(((struct Obj10960 *)(((u8*)a0)))->f37C);
    return func_0204AFD8(((struct Obj10960 *)(((u8*)a0)))->f380);
}

void func_021C02C8(char *p)
{
    u16 heap = ((struct Obj06713 *)p)->f4;
    void *h = func_020490F4(192, heap);
    int a = func_0204A6C8((void *)((u32)h), 15, 0, 0, heap);
    int b = func_0204AC18((void *)((u32)h), 16, 0, 192, 0, 3, heap);
    int c = func_0204AF28((void *)((u32)h), 14, 17, heap);
    int d;
    func_02049238(h);
    h = func_020490F4(83, heap);
    d = func_0204AC18((void *)((u32)h), 31, 0, 128, 0, 2, heap);
    func_02049238(h);
    ((struct Obj06713 *)p)->f368 = a;
    ((struct Obj06713 *)p)->f36C = b;
    ((struct Obj06713 *)p)->f374 = d;
    ((struct Obj06713 *)p)->f370 = c;
}

u32 func_021C0358(u32 a0)
{
    func_0204A8D4(((struct Obj08439 *)(((u8*)a0)))->f368);
    func_0204ADA4(((struct Obj08439 *)(((u8*)a0)))->f36C);
    func_0204ADA4(((struct Obj08439 *)(((u8*)a0)))->f374);
    return func_0204AFD8(((struct Obj08439 *)(((u8*)a0)))->f370);
}


void func_021C0384(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x384) = 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C03A0(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(int *)(p + i * 4 + 0x384) = (int)func_0204B100(d_021C3620[i], d_021C3618[i], ((struct Obj25960 *)p)->f4);
}
