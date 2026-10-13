/*
 * function: func_0220074C
 * address:  0x0220074C
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   FX_Div   0x0207C768  arm
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F918C  0x021F918C  thumb  ov094
 *   d_0220AE7C     0x0220AE7C  data   ov094  a1
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *owner;        /* 0x000 */
    char pad[0x540 - 4];
    u16 heap;           /* 0x540 */
} Work;

typedef struct {
    Work *w;            /* 0x00 */
    int i;              /* 0x04 */
    VecFx32 cur;        /* 0x08 */
    int kind;           /* 0x14 */
    VecFx32 start;      /* 0x18 */
    VecFx32 end;        /* 0x24 */
    VecFx32 step;       /* 0x30 */
    int frames;         /* 0x3c */
    int left;           /* 0x40 */
    int count;          /* 0x44 */
    int f48;            /* 0x48 */
    int f4c;            /* 0x4c */
    int f50;            /* 0x50 */
} Mover;

extern const char d_0220AE7C[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern u32 FX_Div(u32 a, u32 b);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F918C(const VecFx32 *a, const VecFx32 *b, VecFx32 *out, fx32 div);

#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f)                                             : ((float)((x) << 12) - .5f)))

void func_0220074C(Work *w, int i, int kind, VecFx32 *p, VecFx32 *q, int n,
                   int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50)
{
    Mover *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x54, 0, d_0220AE7C, 0xa4e);

    o->w = w;
    o->i = i;
    o->kind = kind;
    o->frames = n;
    o->left = n;
    o->count = 0;
    o->f48 = f48;
    o->f4c = f4c * 2;
    o->start.x = p->x;
    o->start.y = p->y;
    o->start.z = p->z;
    o->end.x = q->x;
    o->end.y = q->y;
    o->end.z = q->z;
    o->cur.x = p->x;
    o->cur.y = p->y;
    o->cur.z = p->z;
    o->f50 = f50;
    switch (kind) {
    case 0:
        break;
    case 1:
    case 4:
        func_021F918C(&o->start, q, &o->step, FX_INT_TO_FX32(n));
        break;
    case 3:
        o->f4c *= 2;
    case 2:
        o->step.x = FX_Div(q->x, FX_INT_TO_FX32(n));
        o->step.y = FX_Div(q->y, FX_INT_TO_FX32(n));
        o->step.z = FX_Div(q->z, FX_INT_TO_FX32(n));
        if ((i & 1) && flip) {
            o->step.x *= -1;
            o->step.z *= -1;
        }
        break;
    }
    func_021F896C(func_02030DA8(w->owner, fn, o, 0), cb, 2);
}
