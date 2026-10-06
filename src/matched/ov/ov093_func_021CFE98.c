/*
 * function: func_021CFE98
 * address: 0x021CFE98
 * packet: pkt_ov093_021CFE98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021CFFAA, followed by labelled func_021CFFAC.
 * symbols:
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_0201C314 0x0201C314 thumb
 *   func_0201C1C8 0x0201C1C8 thumb
 *   func_021D799C 0x021D799C thumb ov093
 *   func_021D055C 0x021D055C thumb ov093
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct G { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };
extern u16 func_021D57FC(void *);
struct QG;
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u32 func_0201C314(void *p);
extern u8 func_0201C1C8(void *p);
extern int func_021D799C(int, int);
extern int func_021D055C(u8 *g, void *a, int b);
int func_021CFE98(struct G *g, void *a, void *b)
{
    u8 n;
    int k;
    u32 c;
    u32 i;
    u32 v;
    k = func_021D57FC(b);
    n = func_021D5448(a);
    c = 0;
    for (i = 0; i < n; i++) {
        v = (u32)func_021D54C0(a, (u8)i);
        if (func_0201C314((void *)v)) {
            if (func_021D799C(func_0201C1C8((void *)v), k))
                return 0;
            c++;
        }
    }
    if (c >= 2) {
        if (func_021D055C((u8 *)g, b, 4)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
        }
        if (func_021D055C((u8 *)g, b, 3)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
        }
    }
    return 0;
}
