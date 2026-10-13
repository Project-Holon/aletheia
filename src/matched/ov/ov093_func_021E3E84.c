/*
 * function: HAND_WAZA_BideFindTarget
 * address:  0x021E3E84
 * packet:   pkt_ov093_021E3E84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetHitCount  0x021D6920  thumb  ov093
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetHitCount(u8 *p, u32 n);
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
extern u32 BTL_CALC_Random(u32 range);

int HAND_WAZA_BideFindTarget(int u, void *a, int c, int *w)
{
    u8 buf[16];
    void *q;
    unsigned i;
    int x;
    int t;
    int r;

    q = BTL_SERVER_FLOW_GetPokeParam(a, c);
    for (i = 0; i < 3; i++) {
        if (BTL_POKEPARAM_GetHitCount(q, (u8)i) != 0) {
            BTL_POKEPARAM_GetHitRecord(q, (u8)i, (int)0, (u16 *)(&buf[6]));
            x = buf[0xb];
            if (BTL_SERVER_FLOW_GetFrontPosOfPoke(a, x) == 6) {
                t = BTL_SERVER_FLOW_GetPokeViewPos(a, c);
                r = BTL_SERVER_FLOW_CollectAlivePokeIds(a, (u16)(0x100 | t), buf);
                if (r != 0)
                    x = buf[(u8)BTL_CALC_Random(r)];
                else
                    x = 0x1f;
            }
            return x;
        }
    }
    return 0x1f;
}
