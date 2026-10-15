/*
 * function: ZKNSEARCH_MAIN_UpdateConfirmDialog
 * address: 0x021BDFC0
 * packet: pkt_ov210_021BDFC0
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   ZKNSEARCH_MAIN_IsActorAnimActive 0x021BEDE0 thumb ov210
 *   ZKNSEARCH_MAIN_UpdateCursorActors 0x021BF728 thumb ov210
 */
#include "../include/Obj04618.h"
typedef unsigned char u8;
struct S;
extern int FRAME_LIST_Update(struct S *p);
extern int ZKNSEARCH_MAIN_IsActorAnimActive(int, int);
extern void ZKNSEARCH_MAIN_UpdateCursorActors(u8 *, int);
int ZKNSEARCH_MAIN_UpdateConfirmDialog(u8 *p)
{
    switch (((struct Obj04618 *)p)->f14) {
    case 0:
        if (FRAME_LIST_Update(((struct Obj04618 *)p)->f1E0) == -1)
            ++((struct Obj04618 *)p)->f14;
        break;
    case 1:
        if (p[0x2C1] != 57 && ZKNSEARCH_MAIN_IsActorAnimActive((int)p, p[0x2C1]) != 0)
            break;
        ((struct Obj04618 *)p)->f14 = 0;
        ZKNSEARCH_MAIN_UpdateCursorActors(p, 0);
        return ((struct Obj04618 *)p)->f18;
    }
    return 24;
}
