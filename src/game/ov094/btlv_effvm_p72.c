/*
 * file:     btlv_effvm_p72.c
 * unit:     yes
 * function: func_0220074C, func_02200904
 * address:  0x0220074C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   sub_0207C768   0x0207C768  arm
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F918C  0x021F918C  thumb  ov094
 *   d_0220AE7C     0x0220AE7C  data   ov094  a1
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_02015C30  0x02015C30  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 */
#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f)                                             : ((float)((x) << 12) - .5f)))
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
} Work_0220074C;

typedef struct {
    Work_0220074C *w;            /* 0x00 */
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
} Mover_0220074C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x542 - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x542 */
} Work_02200904;

typedef struct {
    char body[0x3c];
} Mover_02200904;

typedef struct {
    Work_02200904 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_02200904 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern u32 sub_0207C768(u32 a, u32 b);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F918C(const VecFx32 *a, const VecFx32 *b, VecFx32 *out, fx32 div);
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void func_021F89BC(void *h);
extern int func_021F9260(Mover_02200904 *m, VecFx32 *out);
extern int func_022019F4(char *p, int key);
void func_0220074C(Work_0220074C *w, int i, int kind, VecFx32 *p, VecFx32 *q, int n, int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50);
void func_02200904(void *h, Ctx *c);
extern const char d_0220AE7C[];


void func_0220074C(Work_0220074C *w, int i, int kind, VecFx32 *p, VecFx32 *q, int n,
                   int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50)
{
    Mover_0220074C *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x54, 0, d_0220AE7C, 0xa4e);

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
        o->step.x = sub_0207C768(q->x, FX_INT_TO_FX32(n));
        o->step.y = sub_0207C768(q->y, FX_INT_TO_FX32(n));
        o->step.z = sub_0207C768(q->z, FX_INT_TO_FX32(n));
        if ((i & 1) && flip) {
            o->step.x *= -1;
            o->step.z *= -1;
        }
        break;
    }
    func_021F896C(func_02030DA8(w->owner, fn, o, 0), cb, 2);
}


/*
 * Task callback, twin of func_02200A84 on the +0xE0 vector.
 */
void func_02200904(void *h, Ctx *c)
{
    Work_02200904 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    func_02015C30(w->e[i].h, (u32 *)(&v));
    r = func_021F9260(&c->mv, &v);
    func_02015C48(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}
