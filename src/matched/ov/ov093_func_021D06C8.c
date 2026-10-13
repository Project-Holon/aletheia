/*
 * function: BTL_CLIENT_PickRotationPosition
 * address:  0x021D06C8
 * packet:   pkt_ov093_021D06C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SLOT_GetRotateSrcIndex  0x021B9AB0  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   _ull_mul       0x0209C054  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef unsigned long long u64;

struct G {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
    u8 pad1[0xc];
    void *list;
};

extern int BTL_SLOT_GetRotateSrcIndex(int k);
struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *m);

u8 BTL_CLIENT_PickRotationPosition(struct G *g)
{
    u8 buf[2];
    u32 cnt;
    u32 v;

    cnt = 1;
    buf[0] = 1;
    if (BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(g->list, (u8)BTL_SLOT_GetRotateSrcIndex(2))) == 0) {
        buf[cnt++] = 2;
    }
    if (BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(g->list, (u8)BTL_SLOT_GetRotateSrcIndex(3))) == 0) {
        buf[cnt++] = 3;
    }
    if (cnt > 1) {
        g->seed = g->mul * g->seed + g->add;
        if (cnt == 0) {
            v = (u32)(g->seed >> 32);
        } else {
            v = (u32)(((g->seed >> 32) * (u32)cnt) >> 32);
        }
        return buf[v];
    }
    return 1;
}
