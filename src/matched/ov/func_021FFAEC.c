/*
 * function: WORLDTRADE_SUBLCD_SetActorSurfacePos
 * address:  0x021FFAEC
 * packet:   pkt_021FFAEC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_AddActorSurfacePos  0x0204B404  arm

 *
 * Send a one-entry u16 table {(u16)(b - 8), c} to CLACT_AddActorSurfacePos.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void WORLDTRADE_SUBLCD_SetActorSurfacePos(u32 a, int b, int c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c - 8;
    CLACT_AddActorSurfacePos((struct Obj *)a, (const struct Vec2 *)t, 1);
}
