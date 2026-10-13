/*
 * function: BTL_CLIENT_CmdCureMajorSick
 * address:  0x021D3900
 * packet:   pkt_021D377C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_CLIENT_CmdCureMajorSick   0x021D3900  thumb
 *   BTL_SIDE_GetPokeByIdThunk   0x021B9934  thumb
 *   BTL_POKEPARAM_ClearMajorStatus   0x021D61F0  thumb
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl BTL_SIDE_GetPokeByIdThunk; bl BTL_POKEPARAM_ClearMajorStatus; movs r0, #1; pop {r3, pc}.
 */
#include "../include/Obj18387.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D3900  shape F4: (u8) of a word arg, then BTL_POKEPARAM_ClearMajorStatus */
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
struct UtilSlots;
extern void BTL_POKEPARAM_ClearMajorStatus(struct UtilSlots *p);

int BTL_CLIENT_CmdCureMajorSick(u8 *p, int b, u32 *q)
{
    BTL_POKEPARAM_ClearMajorStatus((struct UtilSlots *)BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj18387 *)p)->f4, (u8)*q));
    return 1;
}

