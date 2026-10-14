/*
 * function: ZUKAN_DETAIL_FORM_UpdateScrollMarkers
 * address:  0x021C6AFC
 * packet:   pkt_ov208_021C6AFC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_CountEntriesBefore  0x021C6E30  thumb
 *   ZUKAN_DETAIL_FORM_GetScrollSlotRange  0x021C6D6C  thumb
 *   CLACT_AddActorSurfacePos        0x0204B404  arm
 *   CLACT_SetActorDrawEnable        0x0204B3DC  arm
 */
#include "../include/Obj01979.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Ov208Pos;

extern u16  ZUKAN_DETAIL_FORM_CountEntriesBefore(void *unused, u8 *p, int unused2, u16 skip, u16 stop);
extern void ZUKAN_DETAIL_FORM_GetScrollSlotRange(int n, int i, u8 *lo, u8 *mid, u8 *hi);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void ZUKAN_DETAIL_FORM_UpdateScrollMarkers(void *a0, u8 *p, int a2)
{
    int on = 0;
    u16 n;
    u8 mid;
    Ov208Pos pos;

    switch (((struct Obj01979 *)p)->f6B8) {
    case 0:
        break;
    case 4:
        if (((struct Obj01979 *)p)->f548 >= 3)
            on = 1;
        break;
    }
    if (on) {
        n = ZUKAN_DETAIL_FORM_CountEntriesBefore(a0, p, a2, ((struct Obj01979 *)p)->f54E, ((struct Obj01979 *)p)->f550);
        ZUKAN_DETAIL_FORM_GetScrollSlotRange((u16)(((struct Obj01979 *)p)->f548 - 1), n, 0, &mid, 0);
        pos.x = mid;
        pos.y = 0x30;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01979 *)p)->f5E8), (const struct Vec2 *)(&pos), 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01979 *)p)->f5E4, 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01979 *)p)->f5E8, 1);
        ((struct Obj01979 *)p)->f698 = 0;
        ((struct Obj01979 *)p)->f6D4 = 0;
        ((struct Obj01979 *)p)->f69C = 0;
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01979 *)p)->f5E4, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01979 *)p)->f5E8, 0);
    }
}
