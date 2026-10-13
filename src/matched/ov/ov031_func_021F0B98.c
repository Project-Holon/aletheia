/*
 * function: func_021F0B98
 * address:  0x021F0B98
 * packet:   pkt_ov031_021F0B98
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0B98  0x021F0B98  thumb
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_0204B454  0x0204B454  arm
 *   func_02035C60  0x02035C60  arm
 *   func_0204B404  0x0204B404  arm
 */
#include "../include/Obj01128.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern int func_02035C60(void);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

int func_021F0B98(char *o)
{
    s16 buf[2];
    u32 x;
    u32 y;
    int r;

    if (TOUCHPANEL_GetPointCont(&x, &y) == 0)
        return 0;
    r = 1;
    func_0204B454((struct Actor *)((struct Obj01128 *)o)->f2C, (struct PtS *)buf, 1);
    if (((struct Obj01128 *)o)->f31 == 0) {
        if (func_02035C60() == 0)
            return 0;
        if ((u32)(buf[0] - 0xB) <= x && (u32)(buf[0] + 0xB) >= x &&
            (u32)(buf[1] - 0xB) <= y && (u32)(buf[1] + 0xB) >= y)
            return r;
    } else {
        if (y < 0x1C)
            y = 0x1C;
        else if (y > 0x9C)
            y = 0x9C;
        buf[1] = y;
        func_0204B404((struct Obj *)(((struct Obj01128 *)o)->f2C), (const struct Vec2 *)buf, 1);
        return 1;
    }
    return 0;
}
