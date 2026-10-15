/*
 * function: ZKNSEARCH_MAIN_ToggleEntry3
 * address: 0x021BE22C
 * packet: pkt_ov210_021BE22C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: 93D4 receives full entry index in r1 without caller-side truncation;
 *      widen its legacy s16 declaration. F85C explicitly narrows r1 to u16.
 * symbols:
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   FRAME_LIST_SetCursor 0x021B93D4 thumb ov067
 *   ZKNSEARCH_MAIN_PlaceColumnActor1 0x021BF85C thumb ov210
 *   ZKNSEARCH_MAIN_PrintEntryCount4 0x021BEB8C thumb ov210
 */
#include "../include/Obj10917.h"
#include "../include/Obj25610.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct S;
extern int FRAME_LIST_GetScrollPos(char *);
extern void FRAME_LIST_SetCursor(struct S *, int);
extern void ZKNSEARCH_MAIN_PlaceColumnActor1(char *p, int i, int flag);
extern void ZKNSEARCH_MAIN_PrintEntryCount4(u8 *);
void ZKNSEARCH_MAIN_ToggleEntry3(u8 *p, int index)
{
    int sum = index + FRAME_LIST_GetScrollPos(*(char * *)&((struct Obj10917 *)p)->f1E0);
    u8 *data = *(u8 * *)&((struct Obj25610 *)(*(u8 * *)&((struct Obj10917 *)p)->f0))->f8;
    if (data[5] == sum) {
        data[5] = 255;
        ZKNSEARCH_MAIN_PlaceColumnActor1((char *)p, (u16)index, 0);
    } else {
        data[5] = sum;
        ZKNSEARCH_MAIN_PlaceColumnActor1((char *)p, (u16)index, 1);
    }
    FRAME_LIST_SetCursor(*(struct S * *)&((struct Obj10917 *)p)->f1E0, index);
    ZKNSEARCH_MAIN_PrintEntryCount4(p);
}
