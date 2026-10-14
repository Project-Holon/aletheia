/*
 * function: BTLV_INPUT_CursorMoveTaskMain
 * address:  0x02204A88
 * packet:   pkt_ov094_02204A88
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   BTLV_INPUT_DeleteTask  0x0220687C  thumb  ov094
 */
typedef short s16;

typedef struct Main {
    unsigned char pad00[0x210];
    void *o210;
    void *o214;
} Main;

typedef struct Ctx {
    Main *main;
} Ctx;

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_CursorMoveTaskMain(int a0, Ctx *c)
{
    s16 v[2];

    CLACT_GetActorSurfacePos(c->main->o210, (struct PtS *)v, 1);
    v[0] -= 8;
    CLACT_AddActorSurfacePos(c->main->o210, (const struct Vec2 *)v, 1);
    CLACT_GetActorSurfacePos(c->main->o214, (struct PtS *)v, 1);
    v[0] -= 8;
    CLACT_AddActorSurfacePos(c->main->o214, (const struct Vec2 *)v, 1);
    if (v[0] == 0xe0) {
        BTLV_INPUT_DeleteTask((char *)c->main, (void *)a0);
    }
}
