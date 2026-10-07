/*
 * file:     btlv_effvm_p03.c
 * unit:     yes
 * function: func_021F6F48, func_021F7000
 * address:  0x021F6F48
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
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_021F918C  0x021F918C  thumb  ov094
 *   func_0207C768  0x0207C768  arm
 */
#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f) \
                                            : ((float)((x) << 12) - .5f)))
typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    char pad00[0x14];
    unsigned int flags;     /* 0x14 */
    VecFx32 cur0;           /* 0x18 */
    VecFx32 cur1;           /* 0x24 */
    VecFx32 dst0;           /* 0x30 */
    VecFx32 dst1;           /* 0x3c */
    VecFx32 step0;          /* 0x48 */
    VecFx32 step1;          /* 0x54 */
    char pad60[0x0c];
    int f6c;                /* 0x6c */
    int f70;                /* 0x70 */
    int f74;                /* 0x74 */
} Cam_021F6F48;

typedef struct {
    char pad00[0x14];
    unsigned int flags;     /* 0x14 */
    char pad18[0x60];
    int f78;                /* 0x78 */
    int f7c;                /* 0x7c */
    int f80;                /* 0x80 */
    int f84;                /* 0x84 */
    fx32 f88;               /* 0x88 */
    fx32 f8c;               /* 0x8c */
    int f90;                /* 0x90 */
    fx32 f94;               /* 0x94 */
    fx32 f98;               /* 0x98 */
    int f9c;                /* 0x9c */
    int fa0;                /* 0xa0 */
    int fa4;                /* 0xa4 */
    int fa8;                /* 0xa8 */
    int fac;                /* 0xac */
    int fb0;                /* 0xb0 */
} Cam_021F7000;

typedef unsigned int   u32;

extern void func_021F918C(const VecFx32 *a, const VecFx32 *b, VecFx32 *out, fx32 div);
extern u32 func_0207C768(u32 a, u32 b);
void func_021F6F48(Cam_021F6F48 *c, VecFx32 *a, VecFx32 *b, int n, int s, int t);
void func_021F7000(Cam_021F7000 *c, int mode, fx32 v, int unused, int n, int g, int h);


void func_021F6F48(Cam_021F6F48 *c, VecFx32 *a, VecFx32 *b, int n, int s, int t)
{
    c->f74 = t;
    c->f6c = s;
    c->f70 = s;
    if (a != 0) {
        c->dst0.x = a->x;
        c->dst0.y = a->y;
        c->dst0.z = a->z;
        func_021F918C(&c->cur0, a, &c->step0, FX_INT_TO_FX32(n));
        c->flags |= 1;
    }
    if (b != 0) {
        c->dst1.x = b->x;
        c->dst1.y = b->y;
        c->dst1.z = b->z;
        func_021F918C(&c->cur1, b, &c->step1, FX_INT_TO_FX32(n));
        c->flags |= 2;
    }
}


/*
 * Follower of func_021F6F48; bl from ov094 at 0x021FA08E.
 */
void func_021F7000(Cam_021F7000 *c, int mode, fx32 v, int unused, int n, int g, int h)
{
    c->f78 = 3;
    c->fa0 = n;
    c->fa4 = n;
    c->fa8 = 0;
    c->fac = g;
    c->f7c = 0;
    c->fb0 = h * 4;
    c->f80 = 0;
    c->f84 = 0;
    if (mode == 1) {
        c->f88 = v;
        c->f8c = 0;
        c->f94 = func_0207C768(v, FX_INT_TO_FX32(n));
        c->f98 = 0;
    } else {
        c->f88 = 0;
        c->f8c = v;
        c->f94 = 0;
        c->f98 = func_0207C768(v, FX_INT_TO_FX32(n));
    }
    c->f90 = 0;
    c->f9c = 0;
    c->flags |= 4;
}
