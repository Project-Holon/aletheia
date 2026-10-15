/*
 * function: RESEARCH_LIST_UpdateScrollbarActor
 * address:  0x021BC168
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_LIST_GetScrollbarY  0x021BC1AC  thumb  ov217
 *   RESEARCH_LIST_NeedsScrollbar  0x021BC428  thumb  ov217
 *   RESEARCH_LIST_GetActor  0x021BC720  thumb  ov217
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
 *
 * Packs a 0xF8 message (second halfword from RESEARCH_LIST_GetScrollbarY()) and pushes
 * it through the +0x0c channel, on the path where RESEARCH_LIST_NeedsScrollbar() is clear.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00801.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int RESEARCH_LIST_GetScrollbarY(void *p);
extern int RESEARCH_LIST_NeedsScrollbar(void *p);
extern u32 RESEARCH_LIST_GetActor(void *p, u32 i);
void RESEARCH_LIST_UpdateScrollbarActor(u32 a0)
{
    u8 s[4];
    u32 v1 = RESEARCH_LIST_GetActor((void *)a0, 0);
    if (RESEARCH_LIST_NeedsScrollbar((void *)a0) == 0) {
    CLACT_SetActorDrawEnable((struct Obj *)v1, 0);
    return;
    }
    ((struct Obj00801 *)((u8*)s))->f0 = 248;
    *(u16 *)&((struct Obj00801 *)(((u8*)s)))->f2 = RESEARCH_LIST_GetScrollbarY((void *)a0);
    CLACT_AddActorSurfacePos((struct Obj *)v1, (const struct Vec2 *)s, 0);
    CLACT_SetActorDrawEnable((struct Obj *)v1, 1);
}
