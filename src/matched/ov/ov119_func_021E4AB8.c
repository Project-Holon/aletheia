/*
 * function: POKETRADE_2D_SetIconObjMode
 * address:  0x021E4AB8
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Normalise the third argument to 0 or 1 and tail call the setter.
 *
 * symbols:
 *   CLACT_SetActorObjMode  0x0204B688  arm  arm9
 *   (none)
 */

typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

void POKETRADE_2D_SetIconObjMode(int a0, int a1, int a2)
{
    CLACT_SetActorObjMode((struct Actor *)a1, a2 != 0);
}

