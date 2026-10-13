/*
 * function: STARTMENU_SetRowActorY
 * address:  0x021BB5E0
 * packet:   pkt_ov088_021BB5E0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Moves menu sprite idx (array at +0x1C) to row y, keeping its x.
 *
 * symbols:
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 */

typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
} Pos;

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void STARTMENU_SetRowActorY(char *p, u32 idx, s16 y)
{
    Pos pos;
    CLACT_GetActorSurfacePos(((void **)(p + 0x1c))[idx], (struct PtS *)&pos, 0);
    pos.y = y;
    func_0204B404(((void **)(p + 0x1c))[idx], (const struct Vec2 *)(&pos), 0);
}
