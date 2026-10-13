/*
 * function: TR_AI_GetPosition
 * address:  0x0218A160
 * packet:   pkt_ov096_0218A160
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetOwnLanePos  0x021B8C38  thumb  ov093
 */
#include "../include/Obj00067.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u8 BTL_MAIN_GetOwnLanePos(u32 flags, u32 v);

u8 TR_AI_GetPosition(u8 *p, int k)
{
    u32 v;
    switch (k) {
    case 1:
        return p[0x94];
    default:
    case 0:
        return p[0x95];
    case 3:
        switch (*(int *)&((struct Obj00067 *)p)->f98) {
        case 0:
        case 3:
            return p[0x94];
        case 1:
            return 2 ^ p[0x94];
        case 2:
            v = (u32)p[0x94] >> 1;
            if (v != 2)
                v = v + 1;
            else
                v = 1;
            return BTL_MAIN_GetOwnLanePos(p[0x94], (u8)v);
        }
        break;
    case 2:
        switch (*(int *)&((struct Obj00067 *)p)->f98) {
        case 0:
        case 3:
            return p[0x95];
        case 1:
            return 2 ^ p[0x95];
        case 2:
            v = (u32)p[0x95] >> 1;
            if (v != 2)
                v = v + 1;
            else
                v = 1;
            return BTL_MAIN_GetOwnLanePos(p[0x95], (u8)v);
        }
        break;
    }
}
