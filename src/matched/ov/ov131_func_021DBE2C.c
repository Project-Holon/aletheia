/*
 * function: P_STA_OAM_SetBitmapActorsPos
 * address: 0x021DBE2C
 * packet: pkt_ov131_021DBE2C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj08149.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Point { s16 x, y; };
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void P_STA_OAM_SetBitmapActorsPos(u8 *p, s16 x, s16 y)
{
    struct Point pt;
    int i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            pt.x = (s16)(x + (j << 6));
            pt.y = (s16)(y + (i << 5));
            func_0204B404(*(void **)(p + 4 + (j + i * p[0x22]) * 4), (const struct Vec2 *)(&pt), ((struct Obj08149 *)p)->f20);
        }
    }
}
