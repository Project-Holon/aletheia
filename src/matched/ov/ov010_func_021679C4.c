/*
 * function: COMM_PLAYER_SetEffect
 * address:  0x021679C4
 * packet:   pkt_ov010_021679C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_COMM_ACTOR_CTRL_GetMmdl  0x021943EC  thumb  ov021
 *   FLDEFF_GYOE_StartHeld  0x021BB578  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Ent {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Work {
    void *sys;
    void *obj;
    Ent e[4];
} Work;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Tbl;
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u32 FIELD_COMM_ACTOR_CTRL_GetMmdl(struct Tbl *t, u32 key);
extern u32 FLDEFF_GYOE_StartHeld(void *a, void *b, int c, int d);

int COMM_PLAYER_SetEffect(Work *w, int i)
{
    Ent *e;
    void *a;

    e = &w->e[i];
    if (w->obj == 0 || e->used == 0 || e->f18 != 0)
        return 0;
    a = (void *)FIELDMAP_GetEffect(GAMESYSTEM_GetFieldMap(w->sys));
    e->f18 = FLDEFF_GYOE_StartHeld(a, (void *)FIELD_COMM_ACTOR_CTRL_GetMmdl(w->obj, i), 0, 0);
    return 1;
}
