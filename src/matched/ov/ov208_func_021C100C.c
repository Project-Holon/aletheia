/*
 * function: ZUKAN_DETAIL_AREA_GetTownPointDistance
 * address: 0x021C100C
 * packet: pkt_ov208_021C100C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: 021C1066..021C1068 is two zero alignment bytes, not a follower.
 * symbols:
 *   TOWNMAP_GRH_GetTownInfoValue 0x021BBB3C thumb ov072
 */
#include "../include/Obj14656.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 TOWNMAP_GRH_GetTownInfoValue(char *, int, int);
int ZUKAN_DETAIL_AREA_GetTownPointDistance(void *unused, char *p, int key, u8 index, u8 x, u8 y, unsigned *out)
{
    unsigned dx, dy, distance;
    if (*(unsigned *)(p + index * 8 + 0x1e0) == 1) return 0;
    dx = TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Obj14656 *)p)->f3C8, index, 4);
    dy = TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Obj14656 *)p)->f3C8, index, 5);
    dy -= y;
    dx -= x;
    distance = dx * dx + dy * dy;
    if (distance < 144) {
        if (out) *out = distance;
        return 1;
    }
    return 0;
}
