/*
 * file:     zukan_detail_graphic_p32.c
 * unit:     yes
 * function: func_021C24A4, func_021C24F0, func_021C252C, func_021C255C
 * address:  0x021C24A4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B688  0x0204B688  arm
 *   func_0207D63C  0x0207D63C  arm
 *   ov208_func_021BC518  0x021BC518  thumb  ov208
 */
#include "../../matched/include/Obj10905.h"

struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            s32;

extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0207D63C(volatile void *reg, int plane1, int plane2, int ev1, int ev2);
extern void ov208_func_021BC518(u32 blend);
void ov208_func_021C24A4(u16 *heap, u8 *p, int key);
void ov208_func_021C24F0(u16 *heap, u8 *p, int key);
void ov208_func_021C252C(u16 *heap, u8 *p, int key);
void func_021C255C(u16 *dst, u16 value);


void ov208_func_021C24A4(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0xbc)), 1);
    }
    for (i = 0; i < 0x3d; i++) {
        if (*(u32 *)(p + i * 8 + 0x1e0) == 2)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
    }
}


void ov208_func_021C24F0(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            func_0204B688((struct Actor *)(((u32 *)(p + 0x5c))[i]), 0);
    }
    func_0207D63C((volatile void *)0x04001050, 8, 0x3f, 12, 4);
}


void ov208_func_021C252C(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            func_0204B688((struct Actor *)(((u32 *)(p + 0x5c))[i]), 1);
    }
    ov208_func_021BC518(((struct Obj10905 *)p)->f41C);
}


void func_021C255C(u16 *dst, u16 value)
{
    *dst = value;
}
