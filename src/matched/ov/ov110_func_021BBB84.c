/*
 * function: PMSIV_CATEGORY_StartSelectAnim
 * address: 0x021BBB84
 * packet: pkt_ov110_021BBB84
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   _u32_div_f 0x0209C2B0 arm
 *   PMSI_SEARCH_GetKeyPosition 0x021BB224 thumb ov110
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj05290.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { s16 x, y; } Vec2;
typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMSI_SEARCH_GetKeyPosition(unsigned, int *, int *);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void PMSIV_CATEGORY_StartSelectAnim(u8 *p, unsigned index)
{
    Vec2 pos;
    int x, y;
    int state;
    ((struct Obj05290 *)p)->f58 = CLACT_GetActorDrawEnable(((struct Obj05290 *)p)->f54);
    CLACT_SetActorDrawEnable(((struct Obj05290 *)p)->f54, 1);
    if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj05290 *)p)->f4) == 0 && index != 254) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        state = 31;
    } else {
        state = 16;
        switch (index) {
        case 252: case 253: case 254: break;
        default:
            PMSI_SEARCH_GetKeyPosition(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            state = 30;
            break;
        }
    }
    CLACT_AddActorSurfacePos(((struct Obj05290 *)p)->f54, (const struct Vec2 *)(&pos), 0);
    CLACT_SetActorAnimSeq(((struct Obj05290 *)p)->f54, state);
}
