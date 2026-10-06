/*
 * function: func_021BA0E4
 * address:  0x021BA0E4
 * packet:   pkt_ov072_021BA0E4
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
 *   func_0203630C  0x0203630C  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020355C4  0x020355C4  arm
 *   func_021BA710  0x021BA710  thumb  ov072
 *   func_021BA69C  0x021BA69C  thumb  ov072
 *   func_021BA774  0x021BA774  thumb  ov072
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Mag        0x0207CBD0  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_020520A4  0x020520A4  arm
 *   func_0204B404  0x0204B404  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035D20  0x02035D20  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
typedef short s16;
typedef unsigned int u32;

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

struct Vec3 { int x; int y; int z; };

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef struct {
    int obj;
    int f4;
    Pt pt;
    int fc;
    int f10;
} Cur;

extern unsigned int func_0203630C(void);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
extern u8 func_020355C4(void);
extern char *func_021BA710(void *p, Cur *c);
extern void func_021BA69C(char *p, int *o);
extern int func_021BA774(char *p, int i);
extern void VEC_Subtract(const struct Vec3 *a, const struct Vec3 *b, struct Vec3 *d);
extern int VEC_Mag(const struct Vec3 *v);
extern void VEC_Normalize(const struct Vec3 *v, struct Vec3 *d);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *d);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 func_020362DC(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);

void func_021BA0E4(Cur *c, void *q)
{
    struct Vec3 dir = { 0, 0, 0 };
    struct Vec3 v = { 0, 0, 0 };
    struct Vec3 a;
    struct Vec3 b;
    int o[2];
    u32 tx;
    u32 ty;
    int moved;
    char *w;
    int dx;
    int dy;
    s16 t;

    moved = 0;
    c->fc = 0;
    if (func_0203630C() & 0x40) {
        func_020355D8(0);
        dir.y -= 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x80) {
        func_020355D8(0);
        dir.y += 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x20) {
        func_020355D8(0);
        dir.x -= 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x10) {
        func_020355D8(0);
        dir.x += 0x1000;
        moved = 1;
    }
    if (c->f10 != 0 && func_020355C4() == 0 && (w = func_021BA710(q, c)) != 0) {
        func_021BA69C(q, o);
        a.x = FX_F32_TO_FX32(o[0] + func_021BA774(w, 4));
        a.y = FX_F32_TO_FX32(o[1] + func_021BA774(w, 5));
        a.z = 0;
        b.x = FX_F32_TO_FX32(c->pt.x);
        b.y = FX_F32_TO_FX32(c->pt.y);
        b.z = 0;
        VEC_Subtract(&a, &b, &v);
        if (VEC_Mag(&v) > 0x1000) {
            VEC_Normalize(&v, &v);
            func_020520A4(&v, 0x1000, &v);
        }
        moved = 1;
    }
    if (moved) {
        VEC_Normalize(&dir, &dir);
        dx = v.x + dir.x * 3;
        dy = v.y + dir.y * 3;
        if (dx > 0 && dx < 0x1000)
            dx = 0x1000;
        else if (dx > -0x1000 && dx < 0)
            dx = -0x1000;
        if (dy > 0 && dy < 0x1000)
            dy = 0x1000;
        else if (dy > -0x1000 && dy < 0)
            dy = -0x1000;
        c->pt.x += (s16)(dx >> 12);
        c->pt.y += (s16)(dy >> 12);
        t = c->pt.x;
        if (t > 0xf8)
            t = 0xf8;
        else if (t < 0)
            t = 0;
        c->pt.x = t;
        t = c->pt.y;
        if (t > 0xa8)
            t = 0xa8;
        else if (t < 8)
            t = 8;
        c->pt.y = t;
        func_0204B404((struct Obj *)c->obj, (const struct Vec2 *)(&c->pt), 0);
    }
    if (func_020362DC() & 1) {
        func_020355D8(0);
        c->fc = 1;
    }
    if (func_02035D20(&tx, &ty)) {
        func_020355D8(1);
        if (tx <= 0xf8 && ty - 8 <= 0xa0) {
            c->fc = 1;
            c->pt.x = tx;
            c->pt.y = ty;
        }
    }
    if (func_020355C4() == 0)
        func_0204B3DC((struct Obj *)c->obj, 1);
    else
        func_0204B3DC((struct Obj *)c->obj, 0);
}
