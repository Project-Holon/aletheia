/*
 * function: func_021AB908
 * address:  0x021AB908
 * packet:   pkt_ov021_021AB908
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021AB760  0x021AB760  thumb
 *   func_0218E124  0x0218E124  thumb
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   _ll_mul  0x0209C054  arm
 *   func_0218EC90  0x0218EC90  thumb
 *   func_0218ECF4  0x0218ECF4  thumb
 *   d_020A1B38  0x020A1B38  data  a4
 */

typedef long long s64;
typedef int fx32;
typedef short fx16;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} V;

typedef struct {
    int pad[4];
    V p;
    int f1c;
    fx32 f20;
} S;

extern int func_021AB760(int a);
extern void func_0218E124(int h, int b);
extern void VEC_Subtract(const V *a, const V *b, V *out);
extern void VEC_Normalize(const V *a, V *out);
extern void func_0218EC90(int h, V *v);
extern void func_0218ECF4(int h, V *v);
extern const fx16 d_020A1B38[];

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800) >> 12);
}

static inline fx16 FX_SinIdx(int idx)
{
    return d_020A1B38[idx * 2];
}

static inline fx16 FX_CosIdx(int idx)
{
    return d_020A1B38[idx * 2 + 1];
}

/*
 * 2026-10-01: DIFF, register colouring only. Body, call order, stack layout
 * and the FX_Mul/FX_SinIdx/FX_CosIdx inline shape match; the image keeps y in
 * r7, zero in r6 and the table base in r4 (5 callee-saved regs) and stores
 * pos.y late; this source uses 4 regs. Moving `pos.y = y` later gives the
 * right param registers but recolours y/zero/table.
 */
void func_021AB908(int a, S *s, V *v)
{
    int h = func_021AB760(a);
    V dir;
    V pos;
    V n;
    V out;
    fx32 y;
    fx32 c;

    func_0218E124(h, 2);
    pos.x = s->p.x;
    pos.y = s->p.y;
    pos.z = s->p.z;
    dir = *v;
    y = pos.y;
    pos.y = 0;
    dir.y = 0;
    VEC_Subtract(&dir, &pos, &dir);
    VEC_Normalize(&dir, &n);
    pos.y = y;
    out.y = FX_Mul(FX_SinIdx(s->f1c >> 4), s->f20);
    c = FX_Mul(FX_CosIdx(s->f1c >> 4), s->f20);
    out.x = FX_Mul(n.x, c);
    out.z = FX_Mul(n.z, c);
    out.x += pos.x;
    out.y += pos.y;
    out.z += pos.z;
    func_0218EC90(h, &pos);
    func_0218ECF4(h, &out);
}
