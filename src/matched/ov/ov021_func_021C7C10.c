/*
 * function: FIELD_TASK_CreateCameraLerp
 * address:  0x021C7C10
 * packet:   pkt_ov021_021C7C10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   VEC_Subtract  0x0207CA00  arm
 *   FIELD_TASK_UpdateCameraLerp  0x021C7C74  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec;
typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    u16 f8;
    u16 fA;
    Vec fC;
    Vec f18;
    Vec f24;
    int f30;
} Obj;

extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_GetCamera(void *p);
extern int FIELD_TASK_Create(int, int, int (*)(Obj *));
typedef unsigned int   u32;
extern u32 FIELD_TASK_GetWork(u8 *p);
extern void VEC_Subtract(Vec *, Vec *, Vec *);
extern int FIELD_TASK_UpdateCameraLerp(Obj *);

int FIELD_TASK_CreateCameraLerp(int a, int b, const Vec *c, const Vec *d)
{
    int w;
    int h;
    Obj *o;

    w = FIELDMAP_GetHeapId((u8 *)a);
    FIELDMAP_GetCamera((void *)a);
    h = FIELD_TASK_Create(w, 0x34, FIELD_TASK_UpdateCameraLerp);
    o = (Obj *)FIELD_TASK_GetWork((u8 *)h);
    o->f0 = 0;
    o->f4 = a;
    o->f8 = 0;
    o->fA = b;
    o->fC = *c;
    o->f18 = *d;
    VEC_Subtract(&o->f18, &o->fC, &o->f24);
    return h;
}
