/*
 * function: STARTMENU_ScrollRowActors
 * address:  0x021BB858
 * packet:   pkt_ov088_021BB858
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Shifts the six sprites at +0x1c..+0x30 vertically by d.
 *
 * symbols:
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 */

typedef short s16;
typedef unsigned int u32;
typedef struct { s16 x; s16 y; } Pos;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void STARTMENU_ScrollRowActors(char *p, int d)
{
    u32 i;
    Pos pos;
    for (i = 0; i < 6; i++) {
        CLACT_GetActorSurfacePos((struct Actor *)*(int *)((p + i * 4) + 0x1c), (struct PtS *)&pos, 0);
        pos.y += (s16)d;
        func_0204B404((struct Obj *)(*(int *)((p + i * 4) + 0x1c)), (const struct Vec2 *)(&pos), 0);
    }
}
