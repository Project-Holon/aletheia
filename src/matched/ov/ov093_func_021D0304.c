/*
 * function: func_021D0304
 * address: 0x021D0304
 * packet: pkt_ov093_021D0304
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D0644 0x021D0644 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D6940 0x021D6940 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021D7F2C 0x021D7F2C thumb ov093
 *   func_021CFBBC 0x021CFBBC thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021D799C 0x021D799C thumb ov093
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct G { void *p0; u8 pad[0xf0]; u64 seed; u64 mul; u64 add; u8 pad2[0xc]; void *list; u8 start; };
extern int func_021D0644(void *, void *, void *, int);
extern int func_021D59B4(u8 *p, int k);
struct Q1;
struct S2;
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern u8 func_021B9B94(struct Q1 *p);
extern u32 func_021B8588(void **p);
extern u8 func_021D7F2C(u32 a, u8 b);
typedef signed char    s8;
extern int func_021CFBBC(s8 *p, int v);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern u16 func_021D57FC(void *);
extern int func_021D799C(int, int);
int func_021D0304(struct G *g, void *mon, void *target, u8 *out)
{
    u16 hist[4];
    u32 sum;
    u32 i;
    u32 n;
    u8 *other;
    int affinity;
    if (func_021D0644(g, mon, target, 4)) {
        g->seed = g->mul * g->seed + g->add;
        if ((u32)(((g->seed >> 32) * 10) >> 32) != 0) return 0;
    }
    sum = 0;
    for (i = 1; i <= 7; i++) sum += func_021D59B4(mon, i);
    if (sum >= 4) return 0;
    if (func_021D6940(mon, 1, 0, hist)) {
        n = func_021B9B94(g->list);
        i = func_021D7F2C(func_021B8588(g->p0), g->start);
        for (; i < n; i++) {
            if (!func_021CFBBC((s8 *)g, (u8)i)) {
                other = func_021B9C00(g->list, (u8)i);
                if (func_021D0644(g, other, target, 4)) {
                    affinity = func_021D799C(((u8 *)hist)[4], func_021D57FC(other));
                    if (affinity == 0) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 2) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    } else if (affinity < 3) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 3) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
