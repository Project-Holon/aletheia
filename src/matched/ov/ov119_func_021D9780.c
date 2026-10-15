/*
 * function: POKETRADE_PROC_PlaceCursorIcon
 * address: 0x021D9780
 * packet: pkt_ov119_021D9780
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-02: the 0204B404 call is written in each branch of the a1 test (tail-merged
 *  by the compiler, so the 0xf0c pool constant is not hoisted across blocks);
 *  020355C4 is a void getter called on its own; the 021D8FA4 result is a local.
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKETRADE_2D_PlaceTouchbarActors 0x021E5B6C thumb ov119
 *   POKETRADE_SAVE_ShowSummaryMon 0x021E219C thumb ov119
 *   gCursorIconPos0 0x021E7580 data a2
 *   gCursorIconPos1 0x021E757C data a2
 */
#include "../include/Obj05326.h"
typedef unsigned short u16;
typedef struct Pt { u16 x; u16 y; } Pt;
extern const Pt gCursorIconPos0;
extern const Pt gCursorIconPos1;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void *POKETRADE_PROC_GetSideMon(void *p, int a);
extern void POKETRADE_2D_PlaceTouchbarActors(int p, int b, int c);
extern void POKETRADE_SAVE_ShowSummaryMon(char *p, void *mon, int side, int flag);
void POKETRADE_PROC_PlaceCursorIcon(char *p, int a1, int a2)
{
    Pt t0, t1;
    if (a1 == 0) {
        t0 = gCursorIconPos0;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj05326 *)p)->fF0C), (const struct Vec2 *)(&t0), 1);
    } else {
        t1 = gCursorIconPos1;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj05326 *)p)->fF0C), (const struct Vec2 *)(&t1), 1);
    }
    if (func_020355C4()) {
        POKETRADE_2D_PlaceTouchbarActors((int)p, a1, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj05326 *)p)->fF0C, 0);
    } else {
        POKETRADE_2D_PlaceTouchbarActors((int)p, a1, 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj05326 *)p)->fF0C, 1);
    }
    if (a2 != 0) {
        void *v;

        v = POKETRADE_PROC_GetSideMon(p, ((struct Obj05326 *)p)->f10A0);
        POKETRADE_SAVE_ShowSummaryMon(p, v, ((struct Obj05326 *)p)->f10A0, 1);
    }
}
