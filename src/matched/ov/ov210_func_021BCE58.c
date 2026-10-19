/*
 * function: ZKNSEARCH_MAIN_UpdateScrollMove
 * address: 0x021BCE58
 * packet: pkt_ov210_021BCE58
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   ZKNSEARCH_MAIN_GetActorSurfacePos 0x021BEE58 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb ov210
 * BEE38 parameters widened: original call uses signed full-width loads.
 */
#include "../include/Obj00085.h"
typedef unsigned short u16;
typedef signed short s16;
struct WinMgr;
typedef unsigned int   u32;
extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void ZKNSEARCH_MAIN_GetActorSurfacePos(char *, int, short *, short *, unsigned short);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
int ZKNSEARCH_MAIN_UpdateScrollMove(char *p)
{
    unsigned int i;
    short x, y;
    int magnitude;
    if (((struct Obj00085 *)p)->f2C8 == 0) return 0;
    BGWINFRM_UpdateMoves(*(struct WinMgr * *)&((struct Obj00085 *)p)->f20);
    BG_SYS_ChangeScroll(4, 4, ((struct Obj00085 *)p)->f2CA);
    BG_SYS_ChangeScroll(7, 4, ((struct Obj00085 *)p)->f2CA);
    for (i = 2; i <= 4; i++) {
        ZKNSEARCH_MAIN_GetActorSurfacePos(p, i, &x, &y, 0);
        y += ((struct Obj00085 *)p)->f2CA;
        ZKNSEARCH_MAIN_SetActorSurfacePos(p, i, x, y, 0);
    }
    magnitude = ((struct Obj00085 *)p)->f2CA;
    if (magnitude < 0) magnitude = -magnitude;
    ((struct Obj00085 *)p)->f2C8 -= (u16)magnitude;
    return 1;
}
