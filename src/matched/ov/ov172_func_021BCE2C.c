/*
 * function: func_021BCE2C
 * address:  0x021BCE2C
 * packet:   pkt_ov172_021BCE2C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *
 * Places the three cursor sprites (+0x8, +0xc, +0x10) on list row idx relative to the scroll offset at +4: hidden when no row is selected (+0x18 == 0xff) or the row is off screen; the third sprite shows only when the selected entry's flag at +0x1f0 is set, animated from the row's cell at +0x50.
 */
#include "../include/Obj01560.h"
#include "../include/Obj24103.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;

struct SpritePos {
    s16 x;
    s16 y;
};

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *spr, unsigned int on);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void func_021BCE2C(void *ctx, char *list, char *cur, u8 idx)
{
    struct SpritePos pos;
    s16 y;

    if (((struct Obj01560 *)cur)->f18 == 0xff) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f8, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->fC, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
        return;
    }
    y = idx * 32 - ((struct Obj24103 *)list)->f4;
    if (y >= -32 && y <= 0xa0) {
        pos.x = 0x80;
        pos.y = y + 0x10;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01560 *)cur)->f8), (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f8, 1);
        pos.x = 0x12;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01560 *)cur)->fC), (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->fC, 1);
        pos.x = 0xc8;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01560 *)cur)->f10), (const struct Vec2 *)(&pos), 1);
        if (*(u32 *)(list + ((struct Obj01560 *)cur)->f18 * 0x24 + 0x1f0) == 1) {
            CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(list + idx * 0x1c + 0x50)), 0x12);
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 1);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
        }
        return;
    }
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f8, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->fC, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
}
