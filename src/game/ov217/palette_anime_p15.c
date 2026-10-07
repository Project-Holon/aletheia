/*
 * file:     palette_anime_p15.c
 * unit:     yes
 * function: func_021C28CC, func_021C28DC, func_021C28EC, func_021C28FC, func_021C2914, func_021C291C, func_021C2934, func_021C2950, func_021C2958
 * address:  0x021C28CC
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
 *   func_021C295C  0x021C295C  thumb  ov217
 *   func_021C29B4  0x021C29B4  thumb  ov217
 *   func_021C299C  0x021C299C  thumb  ov217
 */
#include "../../matched/include/Obj10967.h"
#include "../../matched/include/Obj26033.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_020307B0(void *p);
extern u32 func_021C295C();
extern void func_021C29B4(void *p, const void *src);
extern void func_021C299C(int *);
void func_021C28CC(const u32 *p, u16 *a, u16 *b);
void func_021C28DC(const u32 *p, u16 *a, u16 *b);
void func_021C28EC(const u32 *p, u16 *a, u16 *b);
u32 func_021C28FC(u32 a0);
u32 func_021C2914(void *a0);
void func_021C291C(char *p, u16 v);
u32 func_021C2934(u32 a0, u32 a1, u32 a2);
void func_021C2950(u32 a0);
void func_021C2958(void *p, u32 v);


void func_021C28CC(const u32 *p, u16 *a, u16 *b)
{
    *a = p[1] + 0x14;
    *b = p[2] - 8;
}


void func_021C28DC(const u32 *p, u16 *a, u16 *b)
{
    *a = p[1] + 0xF;
    *b = p[2] - 8;
}


void func_021C28EC(const u32 *p, u16 *a, u16 *b)
{
    *a = p[1] + 0xA;
    *b = p[2] - 8;
}

u32 func_021C28FC(u32 a0)
{
    return (u32)func_02030734(a0, 52, 0, (const char *)0x21C407C, 420);
}


/*
 * Tail-call veneer: branch to func_020307B0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2914(void *a0)
{
    return func_020307B0(a0);
}


void func_021C291C(char *p, u16 v)
{
    int i;
    ((struct Obj10967 *)p)->f0 = v;
    ((struct Obj10967 *)p)->f2 = 0;
    ((struct Obj10967 *)p)->fC = 0;
    for (i = 0; i < 4; i++)
        *(int *)(p + 0x10 + i * 4) = 0;
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2934(u32 a0, u32 a1, u32 a2)
{
    func_021C2958((void *)a0, a2);
    func_021C29B4((void *)a0, (const void *)a1);
    return func_021C295C(a0);
}


/*
 * Tail-call veneer: branch to func_021C299C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2950(u32 a0)
{
    func_021C299C((int *)a0);
}


/*
 * Field setter, u32 at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2958(void *p, u32 v)
{
    ((struct Obj26033 *)p)->fC = v;
}
