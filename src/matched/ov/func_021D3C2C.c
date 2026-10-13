/*
 * function: BTL_CLIENT_StepClearSubstitute
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
 *   BTL_CLIENT_StepClearSubstitute   0x021D3C2C  thumb
 *   BTL_SIDE_GetPokeByIdThunk   0x021B9934  thumb
 *   BTL_POKEPARAM_ClearSubstitute   0x021D6D70  thumb
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl BTL_SIDE_GetPokeByIdThunk; bl BTL_POKEPARAM_ClearSubstitute; movs r0, #1; pop {r3, pc}.
 */
#include "../include/Obj18391.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D3C2C  shape F4: (u8) of a word arg, then BTL_POKEPARAM_ClearSubstitute */
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_ClearSubstitute(unsigned char *p);

int BTL_CLIENT_StepClearSubstitute(u8 *p, int b, u32 *q)
{
    BTL_POKEPARAM_ClearSubstitute(BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj18391 *)p)->f4, (u8)*q));
    return 1;
}

