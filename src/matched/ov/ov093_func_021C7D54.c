/*
 * function: BTL_SERVER_FLOW_CollectOpponentPokeIds
 * address:  0x021C7D54
 * packet:   pkt_ov093_021C7D54
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_InitFieldPokeIter  0x021BD2B4  thumb  ov093
 *   BTL_SERVER_FLOW_NextFieldPokeIter  0x021BD34C  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *it, u8 **q);
extern int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *it, u8 **q, u8 **x);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);

u8 BTL_SERVER_FLOW_CollectOpponentPokeIds(u8 *p, u8 *k, u8 *out)
{
    u32 it;
    u8 *x;
    u8 n = 0;
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)p);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)p, &x)) {
        if (BTL_MAIN_IsPokeSamePair((u32)k, BTL_POKEPARAM_GetPokeId(x)) == 0) {
            out[n++] = BTL_POKEPARAM_GetPokeId(x);
        }
    }
    return n;
}
