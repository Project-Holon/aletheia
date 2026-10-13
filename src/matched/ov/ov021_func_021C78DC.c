/*
 * function: FIELD_TASK_CreateMmdlPosOffsetTween
 * address:  0x021C78DC
 * packet:   pkt_ov021_021C78DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_TASK_UpdateMmdlPosOffsetTween  0x021C7A7C  thumb  ov021
 *
 * Twin of FIELD_TASK_CreateMmdlDrawOffsetTween (only the callback differs).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec;
typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    int f8;
    u16 fC;
    u16 fE;
    Vec f10;
    int f1C[3];
    int f28;
} Obj;

extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int FIELD_TASK_Create(int, int, int (*)(Obj *));
typedef unsigned int   u32;
extern u32 FIELD_TASK_GetWork(u8 *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern int FIELD_TASK_UpdateMmdlPosOffsetTween(Obj *);

/* The Vec copy is a VEC_Set-style inline setter: its arguments are
 * evaluated right to left, which is what puts y in r1 and z in r2
 * (three plain field copies swap them; a struct assignment is ldm/stm). */
static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

int FIELD_TASK_CreateMmdlPosOffsetTween(int a, int b, const Vec *c, int d)
{
    Obj *o;
    int h;

    h = FIELD_TASK_Create(FIELDMAP_GetHeapId((u8 *)a), 0x2c, FIELD_TASK_UpdateMmdlPosOffsetTween);
    o = (Obj *)FIELD_TASK_GetWork((u8 *)h);
    o->f0 = 0;
    o->f4 = a;
    o->f28 = d;
    FLDMMDL_GetPos((const struct Actor *)d, (struct VecFx32 *)o->f1C);
    if (b >= 0) {
        o->f8 = 0;
        o->fC = 0;
        o->fE = b;
    } else {
        o->f8 = 1;
        o->fC = 0;
        o->fE = -b;
    }
    vset(&o->f10, c->x, c->y, c->z);
    return h;
}
