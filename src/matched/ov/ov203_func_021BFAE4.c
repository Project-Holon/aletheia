/*
 * function: DEMO3D_EXP_C_CRUISER_Update
 * address: 0x021BFAE4
 * packet: pkt_ov203_021BFAE4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BFB12 rereads byte just incremented at 021BFB10.
 * symbols:
 *   func_021BE620 0x021BE620 thumb ov203
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   d_021C3BD0 0x021C3BD0 data a2
 */
#include "../include/Obj04607.h"
#include "../include/Obj14600.h"
struct Obj; struct Vec2 { short x, y; };
extern int func_021BE620(char *p);
extern void CLACT_AddActorSurfacePos(struct Obj *, const struct Vec2 *, unsigned);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned);
extern const struct Vec2 d_021C3BD0[];
void DEMO3D_EXP_C_CRUISER_Update(char *p)
{
    unsigned char *a = *(unsigned char * *)&((struct Obj14600 *)p)->f10;
    int progress = func_021BE620(((struct Obj14600 *)p)->f8) >> 12;
    if (*a < 54 && *a * 100 <= progress) {
        CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj04607 *)a)->f14, d_021C3BD0 + *a, 1);
        ++*a;
        if (*(volatile unsigned char *)&((struct Obj04607 *)a)->f0 == 54)
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj04607 *)a)->f14, 0);
    }
}
