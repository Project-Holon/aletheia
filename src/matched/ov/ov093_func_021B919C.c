/*
 * function: func_021B919C
 * address:  0x021B919C
 * packet:   pkt_ov093_021B919C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201119C  0x0201119C  thumb
 *
 * The extent runs long because the follower func_021B91E4 has no label
 * (already filed as ov093_func_021B91E4.c).
 */
#include "../include/Obj06219.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
    u8 c : 1;
    u8 d : 1;
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
} B;

extern u32 func_0201119C(u32 v);

u32 func_021B919C(u8 *p)
{
    if (((B *)p)->d == 0) {
        if (((B *)p)->g) {
            ((struct Obj06219 *)p)->f430 = ((struct Obj06219 *)p)->f430 << 1;
        }
        ((struct Obj06219 *)p)->f430 = func_0201119C(((struct Obj06219 *)p)->f430);
        ((B *)p)->d = 1;
    }
    return ((struct Obj06219 *)p)->f430;
}
