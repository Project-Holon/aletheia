/*
 * function: ZKNSEARCH_MAIN_ShowResultActors
 * address: 0x021BF418
 * packet: pkt_ov210_021BF418
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: matched caller BD118 consumes r0. The inactive arm retains the
 *      nested object pointer; the active arm retains BEDF0's return register.
 *      Declare BEDF0's observable r0 return despite void legacy declarations.
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorAnim 0x021BED98 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb ov210
 */
#include "../include/Obj25626.h"
#include "../include/Obj25627.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned ZKNSEARCH_MAIN_SetActorVisible(u8 *, unsigned, unsigned);
extern void ZKNSEARCH_MAIN_SetActorAnim(char *, int, int);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
unsigned ZKNSEARCH_MAIN_ShowResultActors(u8 *p)
{
    u8 *data;
    ZKNSEARCH_MAIN_SetActorVisible(p, 6, 0);
    ZKNSEARCH_MAIN_SetActorVisible(p, 5, 0);
    ZKNSEARCH_MAIN_SetActorVisible(p, 2, 1);
    ZKNSEARCH_MAIN_SetActorVisible(p, 3, 1);
    ZKNSEARCH_MAIN_SetActorVisible(p, 4, 1);
    data = *(u8 * *)&((struct Obj25627 *)(*(u8 * *)&((struct Obj25626 *)p)->f0))->f8;
    if (data[6] != 255) {
        ZKNSEARCH_MAIN_SetActorAnim((char *)p, 7, data[6]);
        ZKNSEARCH_MAIN_SetActorSurfacePos((char *)p, 7, 192, 116, 0);
        return ZKNSEARCH_MAIN_SetActorVisible(p, 7, 1);
    }
    return (unsigned)data;
}
