/*
 * function: ZKNSEARCH_MAIN_ToggleEntry1
 * address: 0x021BE12C
 * packet: pkt_ov210_021BE12C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 93D4's s16 parameter widened: caller passes r4 without truncation; F85C r1 is explicitly narrowed to u16.
 * symbols:
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   FRAME_LIST_SetCursor 0x021B93D4 thumb ov067
 *   ZKNSEARCH_MAIN_PlaceColumnActor1 0x021BF85C thumb ov210
 *   ZKNSEARCH_MAIN_PrintEntryCount2 0x021BE978 thumb ov210
 */
#include "../include/Obj10915.h"
#include "../include/Obj25606.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int FRAME_LIST_GetScrollPos(char *p);
struct S;
extern void FRAME_LIST_SetCursor(struct S *s, int v);
extern void ZKNSEARCH_MAIN_PlaceColumnActor1(char *p, int i, int flag);
extern void ZKNSEARCH_MAIN_PrintEntryCount2(u8 *);
void ZKNSEARCH_MAIN_ToggleEntry1(u8 *p, int n)
{
    int value = n + FRAME_LIST_GetScrollPos(((struct Obj10915 *)p)->f1E0);
    u8 *data = *(u8 * *)&((struct Obj25606 *)(*(u8 * *)&((struct Obj10915 *)p)->f0))->f8;
    if (data[2] == value) {
        data[2] = 255;
        ZKNSEARCH_MAIN_PlaceColumnActor1((char *)p, (u16)n, (unsigned int)0);
    } else {
        data[2] = value;
        ZKNSEARCH_MAIN_PlaceColumnActor1((char *)p, (u16)n, (unsigned int)1);
    }
    FRAME_LIST_SetCursor(((struct Obj10915 *)p)->f1E0, n);
    ZKNSEARCH_MAIN_PrintEntryCount2(p);
}
