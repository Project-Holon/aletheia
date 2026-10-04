/*
 * function: func_021D0248
 * address:  0x021D0248
 * packet:   pkt_ov093_021D0248
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021D6940  0x021D6940  thumb  ov093
 *   func_021D05C4  0x021D05C4  thumb  ov093
 *   _ull_mul       0x0209C054  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef unsigned long long u64;

struct G {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
};

extern int func_021D59B4(u8 *p, int k);
struct Rat;
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D5C44(struct Rat *p);
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern int func_021D05C4(u8 *g, u8 a, int b, u8 *out);

int func_021D0248(struct G *g, void *m, u8 *out)
{
    u16 t[4];
    u8 idx;

    if (func_021D59B4(m, 0x11) == 0x1e) {
        if (func_021D62C4(m, 2) || func_021D62C4(m, 3)) {
            if (func_021D5C44(m) >= 0x32000) {
                if (func_021D6940(m, 1, 0, t)) {
                    if (func_021D05C4((u8 *)g, ((u8 *)t)[4], 2, &idx)) {
                        *out = idx;
                        return 1;
                    }
                } else {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 2) >> 32) ? 0 : 1;
                }
            }
        }
    }
    return 0;
}
