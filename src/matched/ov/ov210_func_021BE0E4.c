/*
 * function: ZKNSEARCH_MAIN_SelectEntry1
 * address:  0x021BE0E4
 * packet:   pkt_ov210_021BE0E4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FRAME_LIST_SetCursor  0x021B93D4  thumb  ov067
 *   ZKNSEARCH_MAIN_PrintEntryCount  0x021BE8B8  thumb  ov210
 *   ZKNSEARCH_MAIN_PlaceColumnActor1  0x021BF85C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00085.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct S;
extern void FRAME_LIST_SetCursor(struct S *s, int v);
extern void ZKNSEARCH_MAIN_PrintEntryCount(u8 *p);
extern void ZKNSEARCH_MAIN_PlaceColumnActor1(char *p, int i, int flag);

void ZKNSEARCH_MAIN_SelectEntry1(u8 *p, u32 v)
{
    (*(u8 **)(*(u8 * *)&((struct Obj00085 *)p)->f0 + 8))[1] = v;
    FRAME_LIST_SetCursor(((struct Obj00085 *)p)->f1E0, v);
    ZKNSEARCH_MAIN_PrintEntryCount(p);
    ZKNSEARCH_MAIN_PlaceColumnActor1((char *)p, (u16)v, 1);
}
