/*
 * function: func_021B9FC8
 * address:  0x021B9FC8
 * packet:   pkt_ov021_021B9FC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Walks the segments of the path object func_021B824C returns (slot i in
 * the record's +6 field, points from func_021B8028) looking for the one pos
 * projects onto; when the horizontal distance to the projection is within
 * func_021B8304's range + 0x10, fills the record's +4 field from it and
 * returns 1 when the record round-trips through func_021B8250 and
 * func_021B7D38. Sibling of func_021B9E84.
 * pos->x and pos->z read into x/z locals before the R stores: written
 * straight into R, pos keeps a callee-saved register, obj is spilled
 * instead, and 187 bytes move.
 *
 * symbols:
 *   func_021B8224  0x021B8224  thumb  ov021
 *   func_021B8230  0x021B8230  thumb  ov021
 *   func_021B8248  0x021B8248  thumb  ov021
 *   func_021B824C  0x021B824C  thumb  ov021
 *   func_021B8250  0x021B8250  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B8304  0x021B8304  thumb  ov021
 *   func_021B8378  0x021B8378  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_021BAE7C  0x021BAE7C  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CA68  0x0207CA68  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;
typedef long long      s64;

typedef struct { int x, y, z; } V;
typedef struct {
    u16 id;
    u8 f2;
    u8 f3;
    s16 f4;
    s16 f6;
} Rec;

int *func_021B8224(void *p, int k);
int *func_021B8230(void *p, int a);
u32 func_021B8248(u8 *p);
u32 func_021B824C(u8 *p);
void func_021B8250(void *p, Rec *r, Rec *o);
u32 func_021B82FC(u8 *p);
u32 func_021B8304(u8 *p);
int func_021B8378(int x);
int func_021B7D38(void *p, Rec *r, int c);
void func_021B7EE4(void *o, Rec *r);
void func_021B8028(void *o, V *v);
int func_021BAE7C(int *e0, int *e1, const V *pos, V *a, int *b, V *c);
int func_0207C768(int a, int b);
void func_0207C9D0(V *a, V *b, V *c);
void func_0207CA00(const V *a, V *b, V *c);
int func_0207CA68(V *a, V *b);
void func_0207CAE8(V *a, V *b, V *c);
int func_0207CBD0(V *a);
void func_0207CCA4(V *a, V *b);
int func_0207CF3C(const V *a, const V *b);
typedef signed int     s32;
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);

static inline int FX_Mul(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

int func_021B9FC8(int a, void *p, const V *pos, Rec *out, int arg)
{
    V P;
    V Q;
    V D;
    V E;
    V F;
    V A;
    V C;
    V R;
    V S;
    V G;
    V H;
    int B;
    Rec buf;
    int len;
    u32 lim;
    u32 n;
    int k;
    u32 i;
    int *info;
    int *e0;
    int *e1;
    void *obj;
    int m;
    int t;
    int d;
    int u;
    u32 dist;
    int x;
    int z;

    info = func_021B8230(p, a);
    e0 = func_021B8224(p, info[0]);
    e1 = func_021B8224(p, info[1]);
    if (func_021BAE7C(e0, e1, pos, &A, &B, &C) == 0) {
        return 0;
    }
    out->id = a;
    out->f2 = 1;
    out->f3 = 3;
    out->f4 = 0;
    out->f6 = 0;
    obj = (void *)func_021B824C(p);
    func_021B7EE4(obj, out);
    n = func_021B82FC(obj) >> 4;
    func_021B8028(obj, &P);
    Q.x = P.x;
    Q.y = P.y;
    Q.z = P.z;
    k = func_021B8248(p);
    for (i = 1; i < n; i++) {
        out->f6 = i;
        func_021B7EE4(obj, out);
        func_021B8028(obj, &P);
        lim = func_021B8304(obj);
        func_0207CA00(&Q, &P, &D);
        func_0207CA00(pos, &P, &E);
        func_0207CCA4(&D, &F);
        len = func_0207CBD0(&D);
        func_0207CCA4(&D, &G);
        func_0207CCA4(&E, &H);
        func_0207CAE8(&G, &H, &C);
        D = F;
        m = func_0207CBD0(&E);
        func_0207CCA4(&E, &E);
        t = func_0207C768(m, len);
        E.x = FX_Mul(E.x, t);
        E.y = FX_Mul(E.y, t);
        E.z = FX_Mul(E.z, t);
        d = func_0207CA68(&D, &E);
        if (d <= 0x1000 && d >= 0) {
            u = FX_Mul(d, len);
            A.x = FX_Mul(F.x, u);
            A.y = FX_Mul(F.y, u);
            A.z = FX_Mul(F.z, u);
            func_0207C9D0(&P, &A, &A);
            x = pos->x;
            z = pos->z;
            R.x = x;
            R.z = z;
            R.y = 0;
            S.x = A.x;
            S.y = 0;
            S.z = A.z;
            dist = func_0207C768(func_0207CF3C(&R, &S), k) >> 12;
            lim += 0x10;
            if (lim >= dist) {
                if (C.y >= 0) {
                    out->f4 = func_021B8378(dist);
                } else {
                    out->f4 = -func_021B8378(dist);
                }
                func_021B8250(p, out, &buf);
                func_021B7D38(p, out, arg);
                if (func_0203EFC8((const u8 *)out, (const u8 *)(&buf), 8) == 0) {
                    return 1;
                }
                return 0;
            }
        }
        Q.x = P.x;
        Q.y = P.y;
        Q.z = P.z;
    }
    return 0;
}
