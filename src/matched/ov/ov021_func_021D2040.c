/*
 * function: EVENT_PERAP_RECORD_HopPokeIcon
 * address:  0x021D2040
 * packet:   pkt_ov021_021D2040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02103.h"

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
} Pt;

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

int EVENT_PERAP_RECORD_HopPokeIcon(u8 *w)
{
    Pt pt;

    if (w[0x4c] == 0) {
        ((struct Obj02103 *)w)->f4D = -4;
    }
    if (((struct Obj02103 *)w)->f4D == -4) {
        ((struct Obj02103 *)w)->f4D = 3;
        w[0x4c] = w[0x4c] + 1;
        if (w[0x4c] == 3) {
            return 0;
        }
    }
    CLACT_GetActorSurfacePos((struct Actor *)((struct Obj02103 *)w)->f3C, (struct PtS *)&pt, 0);
    pt.y = pt.y - ((struct Obj02103 *)w)->f4D;
    CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj02103 *)w)->f3C), (const struct Vec2 *)(&pt), 0);
    ((struct Obj02103 *)w)->f4D = ((struct Obj02103 *)w)->f4D - 1;
    return 1;
}
