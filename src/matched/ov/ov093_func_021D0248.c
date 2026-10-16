/*
 * function: BTL_CLIENT_FindNaturalCureSwitch
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
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   BTL_CLIENT_FindMemberResistingType  0x021D05C4  thumb  ov093
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

extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
struct Rat;
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_POKEPARAM_GetHpRatioFixed(struct Rat *p);
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern int BTL_CLIENT_FindMemberResistingType(u8 *g, u8 a, int b, u8 *out);

int BTL_CLIENT_FindNaturalCureSwitch(struct G *g, void *m, u8 *out)
{
    u16 t[4];
    u8 idx;

    if (BTL_POKEPARAM_GetValue(m, 0x11) == 0x1e) {
        if (BTL_POKEPARAM_HasSick(m, 2) || BTL_POKEPARAM_HasSick(m, 3)) {
            if (BTL_POKEPARAM_GetHpRatioFixed(m) >= 0x32000) {
                if (BTL_POKEPARAM_GetHitRecord(m, 1, 0, t)) {
                    if (BTL_CLIENT_FindMemberResistingType((u8 *)g, ((u8 *)t)[4], 2, &idx)) {
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
