/*
 * function: BTL_SERVER_FLOW_CountFasterPokes
 * address:  0x021C81D0
 * packet:   pkt_ov093_021C81D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_InitFieldPokeIter  0x021BD2B4  thumb  ov093
 *   BTL_SERVER_FLOW_NextFieldPokeIter  0x021BD34C  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper  0x021C81C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *it, u8 **q);
extern int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *it, u8 **q, u8 **x);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u16 BTL_SERVER_FLOW_CalcPokeSpeedWrapper(u8 *p, u8 *x, int flag);

u16 BTL_SERVER_FLOW_CountFasterPokes(u8 *p, u8 *a, u32 y)
{
    u32 it;
    u8 *x;
    u16 n;
    u32 base = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(p, a, y);
    int k = BTL_POKEPARAM_GetPokeId(a);
    n = 0;
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)p);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)p, &x)) {
        if (k != BTL_POKEPARAM_GetPokeId(x)) {
            if (BTL_SERVER_FLOW_CalcPokeSpeedWrapper(p, x, y) > base) {
                n++;
            }
        }
    }
    return n;
}
