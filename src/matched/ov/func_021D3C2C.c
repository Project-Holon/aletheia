/*
 * function: func_021D3C2C
 * address:  0x021D3C2C
 * packet:   pkt_021D377C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D3C2C   0x021D3C2C  thumb
 *   func_021B9934   0x021B9934  thumb
 *   func_021D6D70   0x021D6D70  thumb
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D6D70; movs r0, #1; pop {r3, pc}.
 */
#include "../include/Obj18391.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D3C2C  shape F4: (u8) of a word arg, then func_021D6D70 */
extern u8 *func_021B9934(char *p, int i);
extern void func_021D6D70(unsigned char *p);

int func_021D3C2C(u8 *p, int b, u32 *q)
{
    func_021D6D70(func_021B9934(*(char * *)&((struct Obj18391 *)p)->f4, (u8)*q));
    return 1;
}

