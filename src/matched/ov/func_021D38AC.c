/*
 * function: BTL_CLIENT_CmdResetStatStages
 * address:  0x021D38AC
 * packet:   pkt_021D377C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_CLIENT_CmdResetStatStages   0x021D38AC  thumb
 *   func_021B9934   0x021B9934  thumb
 *   BTL_POKEPARAM_ResetStatStages   0x021D5F08  thumb
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl BTL_POKEPARAM_ResetStatStages; movs r0, #1; pop {r3, pc}.
 */
#include "../include/Obj18385.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D38AC  shape F4: (u8) of a word arg, then BTL_POKEPARAM_ResetStatStages */
extern u8 *func_021B9934(char *p, int i);
extern void BTL_POKEPARAM_ResetStatStages(char *p);

int BTL_CLIENT_CmdResetStatStages(u8 *p, int b, u32 *q)
{
    BTL_POKEPARAM_ResetStatStages((char *)func_021B9934(*(char * *)&((struct Obj18385 *)p)->f4, (u8)*q));
    return 1;
}

