/*
 * function: func_021BCB88
 * address:  0x021BCB88
 * packet:   pkt_ov172_021BCB88
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCC40  0x021BCC40  thumb  ov172
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   _u32_div_f     0x0209C2B0  arm
 *
 * Redraws the fifteen list rows, counts the filled ones (+0x58 of each 0x1c-byte row) and, when the count changed (+0x14), shows the scroll bar (+0x404) for more than five rows, clamping the scroll offset (+4) and placing the thumb at 120 * offset / range (+6), or hides it and resets the offset.
 */
#include "../include/Obj01951.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;

struct SpritePos {
    s16 x;
    s16 y;
};

extern void func_021BCC40(void *ctx, char *list, char *row, int idx);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *spr, unsigned int on);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void func_021BCB88(void *ctx, char *list)
{
    struct SpritePos pos;
    u8 n = 0;
    u8 i;
    u32 range;

    for (i = 0; i < 15; i++)
        func_021BCC40(ctx, list, list + 0x40 + i * 0x1c, i);
    for (i = 0; i < 15; i++) {
        if (*(u8 *)(list + i * 0x1c + 0x58) != 0xff)
            n++;
    }
    if (((struct Obj01951 *)list)->f14 == n)
        return;
    if (n > 5) {
        range = (n - 5) * 32;
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01951 *)list)->f404, 1);
        if (((struct Obj01951 *)list)->f4 > range)
            ((struct Obj01951 *)list)->f4 = range;
        ((struct Obj01951 *)list)->f6 = ((struct Obj01951 *)list)->f4 * 0x78 / range;
        if (((struct Obj01951 *)list)->f10 == 0) {
            pos.x = 0xf8;
            pos.y = ((struct Obj01951 *)list)->f6 + 0x18;
            CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01951 *)list)->f404), (const struct Vec2 *)(&pos), 1);
        }
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01951 *)list)->f404, 0);
        ((struct Obj01951 *)list)->f4 = 0;
        ((struct Obj01951 *)list)->fC = 1;
    }
    ((struct Obj01951 *)list)->f14 = n;
}
