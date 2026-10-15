/*
 * function: BEACON_VIEW_UpdateSelectTouch
 * address:  0x021F055C
 * packet:   pkt_ov032_021F055C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   BEACON_VIEW_RequestTransition  0x021F253C  thumb  ov032
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   BEACON_VIEW_HitTestActorTouch  0x021F0A18  thumb  ov032
 *   BEACON_VIEW_HitTestRow  0x021F08E4  thumb  ov032
 *   BEACON_VIEW_ShowTouchedRow  0x021F1F00  thumb  ov032
 *   BEACON_VIEW_HitTestIcon  0x021F096C  thumb  ov032
 *   BEACON_VIEW_StartSlide  0x021F1340  thumb  ov032
 */
#include "../include/Obj00188.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u32 x, y; } Pair;

struct Ctx;
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern void BEACON_VIEW_RequestTransition(char *p, int v);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BEACON_VIEW_HitTestActorTouch(u8 *p, u32 *v);
extern int BEACON_VIEW_HitTestRow(u8 *p, void *pt);
extern void BEACON_VIEW_ShowTouchedRow(char *p, int a);
extern int BEACON_VIEW_HitTestIcon(u8 *p, void *pt);
extern void BEACON_VIEW_StartSlide(char *this, int a, u8 b);

int BEACON_VIEW_UpdateSelectTouch(u8 *p)
{
    Pair v;
    int r;
    int s;

    if (GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)(((struct Obj00188 *)p)->f0)) != 0) {
        BEACON_VIEW_RequestTransition((char *)p, 1);
        return 6;
    }
    if (TOUCHPANEL_GetPointTrg(&v.x, &v.y) == 0)
        return 2;
    if (BEACON_VIEW_HitTestActorTouch(p, (u32 *)(&v)) == 2)
        return 6;
    r = BEACON_VIEW_HitTestRow(p, &v);
    if (r != -1) {
        p[0x7e] = r;
        BEACON_VIEW_ShowTouchedRow((char *)p, (u8)r);
        return 4;
    }
    s = BEACON_VIEW_HitTestIcon(p, &v);
    if (s != -1) {
        BEACON_VIEW_StartSlide((char *)p, s, (int)5);
        return 3;
    }
    return 2;
}
