/*
 * function: ITEMMENU_UpdateSlotActorPosition
 * address:  0x021BB398
 * packet:   pkt_ov070_021BB398
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 */
#include "../include/Obj20676.h"

typedef unsigned int u32;
typedef unsigned char u8;

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

void ITEMMENU_UpdateSlotActorPosition(int p, u32 val)
{
    short b[2];
    short a[2];
    unsigned i;

    CLACT_GetActorSurfacePos((struct Actor *)((struct Obj20676 *)p)->f6A4, (struct PtS *)b, 0);
    for (i = 0; i < 8; i++) {
        CLACT_GetActorSurfacePos((struct Actor *)*(int *)(p + i * 4 + 0x634), (struct PtS *)a, 0);
        if (a[1] == b[1]) {
            break;
        }
    }
    CLACT_SetActorPaletteOffset((struct Obj *)(*(int *)(p + i * 4 + 0x634)), (u8)val, 0);
}
