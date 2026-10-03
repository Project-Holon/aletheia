/*
 * function: func_021B8AE4
 * address:  0x021B8AE4
 * packet:   pkt_021B8AE4
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02035BA4  0x02035BA4  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_021B8A88  0x021B8A88  thumb
 *   func_0202EE0C  0x0202EE0C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct S {
    u8 _0[0x12];
    u8 f12;
    u8 _13[0x62 - 0x13];
    s16 f62;
    u16 f64;
    u8 _66[0x74 - 0x66];
    u32 f74;
    u8 _78[0x7f - 0x78];
    u8 f7f;
};

extern int func_02035BA4(void *p);
extern void func_02035CB8(int *a, int *b);
extern void func_021B8A88(struct S *s, u8 *b, u8 *a);
extern u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e);

int func_021B8AE4(struct S *s, unsigned int v)
{
    u8 b, a;
    int o1, o2;
    unsigned int lo, hi;

    if (s->f7f == 1) {
        if (func_02035BA4(&s->f74) != -1) {
            func_02035CB8(&o1, &o2);
            return o2;
        }
        return v;
    }
    func_021B8A88(s, &b, &a);
    lo = func_0202EE0C(s->f64, s->f62, b, a, s->f12);
    if (s->f64 == s->f62)
        hi = a;
    else
        hi = func_0202EE0C(s->f64, s->f62 + 1, b, a, s->f12);
    if (v >= lo && v < hi)
        return v;
    return lo;
}
