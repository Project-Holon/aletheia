/*
 * function: ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown
 * address:  0x021C0C50
 * packet:   pkt_ov208_021C0C50
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_AREA_FindPlayerTownIndex  0x021C0C14  thumb  ov208
 *   TOWNMAP_GRH_GetTownInfoValue  0x021BBB3C  thumb  ov072
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 */
#include "../include/Obj10903.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern u8   ZUKAN_DETAIL_AREA_FindPlayerTownIndex(u16 *heap, u8 *p, int key);
struct Obj;
struct Vec2;
extern unsigned short TOWNMAP_GRH_GetTownInfoValue(char *p, int a, int b);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(u16 *heap, u8 *p, int key)
{
    u8 idx;
    u16 pos[2];

    idx = ZUKAN_DETAIL_AREA_FindPlayerTownIndex(heap, p, key);
    if (idx != 0xff) {
        pos[0] = TOWNMAP_GRH_GetTownInfoValue((char *)(((struct Obj10903 *)p)->f3C8), idx, 2);
        pos[1] = TOWNMAP_GRH_GetTownInfoValue((char *)(((struct Obj10903 *)p)->f3C8), idx, 3);
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj10903 *)p)->fD4), (const struct Vec2 *)pos, 0);
    }
}
