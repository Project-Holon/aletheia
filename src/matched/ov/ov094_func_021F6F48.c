/*
 * function: func_021F6F48
 * address:  0x021F6F48
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_021F918C  0x021F918C  thumb  ov094
 */
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
} Cam;

extern void func_021F918C(const VecFx32 *a, const VecFx32 *b, VecFx32 *out, fx32 div);

#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f) \
                                            : ((float)((x) << 12) - .5f)))

void func_021F6F48(Cam *c, VecFx32 *a, VecFx32 *b, int n, int s, int t)
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
