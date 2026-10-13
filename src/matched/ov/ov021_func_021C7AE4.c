/*
 * function: FIELD_TASK_CreateCameraTargetTween
 * address:  0x021C7AE4
 * packet:   pkt_ov021_021C7AE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The source vector is `const V *`: the const lets the scheduler hoist each
 * load above the preceding store (ldr x; str fC; ldr y; str x; ...).  The
 * sibling FIELD_TASK_CreatePlayerPosTween takes a plain `V *` and keeps loads after the fC store.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FIELD_TASK_UpdateCameraTargetTween  0x021C7B1C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u32 x, y, z; } V;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern Q *FIELD_TASK_Create(u32 heap, u32 size, void *fn);
extern u32 FIELD_TASK_GetWork(u8 *p);
typedef struct { u8 f0; u32 f4; u32 f8; u32 fC; u8 pad[0xc]; V f1C; } X;
extern int FIELD_TASK_UpdateCameraTargetTween(X *x);
static inline void set3(V *d, u32 x, u32 y, u32 z) { d->x = x; d->y = y; d->z = z; }
Q *FIELD_TASK_CreateCameraTargetTween(u32 a, u32 b, const V *v)
{
    Q *q = FIELD_TASK_Create(FIELDMAP_GetHeapId((u8 *)a), 0x28, FIELD_TASK_UpdateCameraTargetTween);
    X *x = (X *)FIELD_TASK_GetWork((u8 *)q);
    x->f0 = 0;
    x->f4 = a;
    x->f8 = 0;
    x->fC = b;
    set3(&x->f1C, v->x, v->y, v->z);
    return q;
}
