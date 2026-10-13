/*
 * function: FIELD_MENU_PlaceCursor
 * address:  0x021A9080
 * packet:   pkt_ov021_021A9080
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 */

typedef short s16;

typedef struct {
    s16 x;
    s16 y;
} P;

typedef struct {
    char pad0[0x124];
    int f124;
    int pad128[3];
    int f134;
} S;

typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void FIELD_MENU_PlaceCursor(S *s, s16 x, s16 y)
{
    P v;
    v.x = x;
    v.y = y;
    CLACT_AddActorSurfacePos((struct Obj *)s->f124, (const struct Vec2 *)(&v), 0);
    s->f134 = 0;
}
