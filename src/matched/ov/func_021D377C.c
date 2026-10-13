/*
 * function: BTL_CLIENT_CmdHpZero
 * address:  0x021D377C
 * packet:   pkt_021D377C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_CLIENT_CmdHpZero   0x021D377C  thumb
 *   func_021B9934   0x021B9934  thumb
 *   BTL_POKEPARAM_ZeroHp   0x021D5FB8  thumb
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl BTL_POKEPARAM_ZeroHp; movs r0, #1; pop {r3, pc}.
 */
#include "../include/Obj18381.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D377C  shape F4: (u8) of a word arg, then BTL_POKEPARAM_ZeroHp */
extern u8 *func_021B9934(char *p, int i);
extern void BTL_POKEPARAM_ZeroHp(u8 *p);

int BTL_CLIENT_CmdHpZero(u8 *p, int b, u32 *q)
{
    BTL_POKEPARAM_ZeroHp(func_021B9934(*(char * *)&((struct Obj18381 *)p)->f4, (u8)*q));
    return 1;
}

