/*
 * function: BTL_SERVER_FLOW_RecheckOpponentAbilityEffects
 * address:  0x021C3FDC
 * packet:   pkt_ov093_021C3FDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_InitFieldPokeIter  0x021BD2B4  thumb  ov093
 *   BTL_SERVER_FLOW_NextFieldPokeIter  0x021BD34C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction  0x021C195C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *it, u8 **q);
extern int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *it, u8 **q, u8 **x);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);

void BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(u8 *p, u8 *a)
{
    u32 it;
    u8 *cur;
    int k = BTL_POKEPARAM_GetPokeId(a);
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)p);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)p, &cur)) {
        if (BTL_MAIN_IsPokeSamePair(k, BTL_POKEPARAM_GetPokeId(cur)) == 0)
            BTL_SERVER_FLOW_ProcDamagedItemReaction(p, cur, 0);
    }
}
