/*
 * function: UNION_SUBDISP_CheckTrackTouch
 * address:  0x021F0D64
 * packet:   pkt_ov031_021F0D64
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   UNION_SUBDISP_CheckTrackTouch  0x021F0D64  thumb
 *   func_02035D20  0x02035D20  arm
 *   func_0204B404  0x0204B404  arm
 */
#include "../include/Obj20411.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_02035D20(u32 *outA, u32 *outB);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

int UNION_SUBDISP_CheckTrackTouch(char *p)
{
    unsigned short t[2];
    u32 x;
    u32 y;

    if (func_02035D20(&x, &y) == 0)
        return 0;
    if (x >= 0xE9 && x <= 0xFF && y >= 0x1C && y <= 0x9C) {
        t[0] = 0xF4;
        t[1] = y;
        func_0204B404((struct Obj *)(((struct Obj20411 *)p)->f2C), (const struct Vec2 *)t, 1);
        return 1;
    }
    return 0;
}
