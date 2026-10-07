/*
 * function: func_021BAA90
 * address:  0x021BAA90
 * packet:   pkt_ov072_021BAA90
 * region:   ov072
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
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_02051F1C  0x02051F1C  arm
 *   func_0205207C  0x0205207C  arm
 *   func_02051F34  0x02051F34  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

struct Vec3 { int x; int y; int z; };

struct Seg {
    struct Vec3 p0;
    struct Vec3 dir;
    u32 pad18;
};

struct Ball {
    struct Vec3 c;
    int r;
};

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W;

extern int func_021BA774(W *p, int i);
struct Out;
struct S12;
struct Vec;
extern void func_02051F1C(struct Ball *dst, struct Vec *src, unsigned radius);
extern void func_0205207C(char *p, struct S12 *q, struct S12 *r, u32 v);
extern u32 func_02051F34(struct Seg *seg, struct Ball *b, struct Out *out);

u32 func_021BAA90(W *p, int *a, int *b)
{
    struct Ball ball;
    struct Seg seg;
    struct Vec3 v0;
    struct Vec3 v1;

    v0.x = FX_F32_TO_FX32(a[0]);
    v0.y = FX_F32_TO_FX32(a[1]);
    v0.z = 0;
    func_02051F1C(&ball, (struct Vec *)(&v0), 0);
    v0.x = FX_F32_TO_FX32(b[0] + func_021BA774(p, 6));
    v0.y = FX_F32_TO_FX32(b[1] + func_021BA774(p, 7));
    v0.z = 0;
    v1.x = FX_F32_TO_FX32(b[0] + func_021BA774(p, 8));
    v1.y = FX_F32_TO_FX32(b[1] + func_021BA774(p, 9));
    v1.z = 0;
    func_0205207C((char *)(&seg), (struct S12 *)(&v0), (struct S12 *)(&v1), FX_F32_TO_FX32(func_021BA774(p, 10)));
    if (p->f40 != 0)
        return 0;
    return func_02051F34(&seg, &ball, 0);
}
