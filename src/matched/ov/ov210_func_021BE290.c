/*
 * function: ZKNSEARCH_MAIN_ToggleEntry4
 * address: 0x021BE290
 * packet: pkt_ov210_021BE290
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: 93D4 receives full entry index in r1 without caller-side truncation;
 *      widen its legacy s16 declaration. FA7C explicitly narrows r1 to u16.
 * symbols:
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   FRAME_LIST_SetCursor 0x021B93D4 thumb ov067
 *   ZKNSEARCH_MAIN_PlaceColumnActor4 0x021BFA7C thumb ov210
 *   ZKNSEARCH_MAIN_ShowEntry6Actor 0x021BF618 thumb ov210
 */
#include "../include/Obj10919.h"
#include "../include/Obj25612.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct S;
extern int FRAME_LIST_GetScrollPos(char *);
extern void FRAME_LIST_SetCursor(struct S *, int);
extern void ZKNSEARCH_MAIN_PlaceColumnActor4(char *p, int i, int flag);
extern void ZKNSEARCH_MAIN_ShowEntry6Actor(char *p);
void ZKNSEARCH_MAIN_ToggleEntry4(u8 *p, int index)
{
    int sum = index + FRAME_LIST_GetScrollPos(*(char * *)&((struct Obj10919 *)p)->f1E0);
    u8 *data = *(u8 * *)&((struct Obj25612 *)(*(u8 * *)&((struct Obj10919 *)p)->f0))->f8;
    if (data[6] == sum) {
        data[6] = 255;
        ZKNSEARCH_MAIN_PlaceColumnActor4((char *)p, (u16)index, 0);
    } else {
        data[6] = sum;
        ZKNSEARCH_MAIN_PlaceColumnActor4((char *)p, (u16)index, 1);
    }
    FRAME_LIST_SetCursor(*(struct S * *)&((struct Obj10919 *)p)->f1E0, index);
    ZKNSEARCH_MAIN_ShowEntry6Actor((char *)p);
}
