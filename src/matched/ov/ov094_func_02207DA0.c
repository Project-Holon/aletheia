/*
 * function: func_02207DA0
 * address:  0x02207DA0
 * packet:   pkt_ov094_02207DA0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: q->f48 is read from the struct in both statements (no local), so
 * the load stays after the 0x50 store.
 *
 * symbols:
 *   func_0220793C  0x0220793C  thumb  ov094
 *   func_0220868C  0x0220868C  thumb  ov094
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */

typedef unsigned int u32;
typedef short s16;

typedef struct S {
    char p0[8];
    void *f8;
    void *fc;
    char p10[0x38];
    int f48;
    int f4c;
    u32 f50;
    char p54[0x14];
    int f68;
    int p6c;
    u32 lo : 1;
    u32 hi : 31;
    char p74[4];
    int f78;
} S;

struct Obj;
struct Vec2;
extern void func_0220793C(char *p);
extern void func_0220868C(void *obj, S *q, int n);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void func_02207DA0(void *obj, S *q, int n)
{
    s16 v[2];

    q->f50 = 0x80000000;
    q->f68 = q->f48 - n;
    if (q->f48 < 0) {
        q->f48 = 0;
    }
    if (q->f48 > q->f4c) {
        q->f48 = q->f4c;
    }
    q->lo = 1;
    if (q->f68 > 0) {
        func_0220793C((char *)q);
        CLACT_GetActorSurfacePos(q->f8, (struct PtS *)v, 0);
        v[0] = v[0] - (s16)(0x30 - q->f78);
        CLACT_AddActorSurfacePos(q->fc, (const struct Vec2 *)v, 0);
        CLACT_SetActorDrawEnable(q->fc, 1);
        func_0220868C(obj, q, q->f78);
    }
}
