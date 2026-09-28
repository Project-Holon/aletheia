/*
 * function: func_021F7000
 * address:  0x021F7000
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C768  0x0207C768  arm
 *
 * Follower of func_021F6F48; bl from ov094 at 0x021FA08E.
 */
typedef int fx32;

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
} Cam;

extern fx32 func_0207C768(fx32 a, fx32 b);

#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f) \
                                            : ((float)((x) << 12) - .5f)))

void func_021F7000(Cam *c, int mode, fx32 v, int unused, int n, int g, int h)
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
