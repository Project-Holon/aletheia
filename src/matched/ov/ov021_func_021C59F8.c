/*
 * function: SHORTCUT_MENU_SetActorsY
 * address:  0x021C59F8
 * packet:   pkt_ov021_021C59F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sets the y offset of the three sprite handles (EXACT*: pad). The split i =
 * 0; y = v; ordering is what schedules the zero before the sign extension.
 *
 * symbols:
 *   CLACT_GetActorSurfacePos  0x0204B454  arm  arm9
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
} P2;

typedef struct {
    u8 pad[0x28];
    u32 h[3];
} S;

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void SHORTCUT_MENU_SetActorsY(S *p, int v)
{
    s16 y;
    int i;
    P2 t;

    i = 0;
    y = v;
    for (; i < 3; i++) {
        CLACT_GetActorSurfacePos((struct Actor *)p->h[i], (struct PtS *)&t, 0);
        t.y = y;
        func_0204B404((struct Obj *)p->h[i], (const struct Vec2 *)(&t), 0);
    }
}
