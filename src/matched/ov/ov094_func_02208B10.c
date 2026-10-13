/*
 * function: func_02208B10
 * address: 0x02208B10
 * packet: pkt_ov094_02208B10
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef signed short s16;
typedef struct E {
    void *f0, *f4, *f8, *fc, *f10, *f14;
    char p18[0x2c];
    int f44;
    char p48[0x28];
    unsigned int lo:16, count:4, hi:12;
    char p74[8];
    void *f7c;
} E;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Node;
extern void func_02030EAC(struct Node *n);
void func_02208B10(void *h, E *e)
{
    int step;
    s16 v[2];
    if (e->f44 != 0) step = 8;
    else step = -8;
    CLACT_GetActorSurfacePos(e->f0, (struct PtS *)v, 0);
    v[0] += (s16)step;
    CLACT_AddActorSurfacePos(e->f0, (const struct Vec2 *)v, 0);
    CLACT_GetActorSurfacePos(e->f8, (struct PtS *)v, 0);
    v[0] += (s16)step;
    CLACT_AddActorSurfacePos(e->f8, (const struct Vec2 *)v, 0);
    CLACT_GetActorSurfacePos(e->f14, (struct PtS *)v, 0);
    v[0] += (s16)step;
    CLACT_AddActorSurfacePos(e->f14, (const struct Vec2 *)v, 0);
    if (e->f44 == 0) {
        CLACT_GetActorSurfacePos(e->f4, (struct PtS *)v, 0);
        v[0] += (s16)step;
        CLACT_AddActorSurfacePos(e->f4, (const struct Vec2 *)v, 0);
    }
    if (e->f10 != 0) {
        CLACT_GetActorSurfacePos(e->f10, (struct PtS *)v, 0);
        v[0] += (s16)step;
        CLACT_AddActorSurfacePos(e->f10, (const struct Vec2 *)v, 0);
    }
    e->count--;
    if (e->count == 0) {
        func_02030EAC(h);
        e->f7c = 0;
    }
}
