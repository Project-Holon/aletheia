/*
 * function: BEACON_DETAIL_GRA_SetActorPos
 * address:  0x021BCE8C
 * packet:   pkt_021BCE8C
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void BEACON_DETAIL_GRA_SetActorPos(void *a0, short a1, short a2, int a3)
{
    u16 tmp[2];
    tmp[0] = a1;
    tmp[1] = a2;
    CLACT_AddActorSurfacePos(a0, (const struct Vec2 *)tmp, a3);
}
