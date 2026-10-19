/*
 * function: BTL_SERVER_FLOW_CalcTypeEffectiveness
 * address: 0x021C6E3C
 * packet: pkt_ov093_021C6E3C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTL_TYPEPAIR_GetHigh 0x021E8CFC thumb ov093
 *   BTL_TYPEPAIR_GetLow 0x021E8D04 thumb ov093
 *   BTL_TYPEPAIR_IsSingleType 0x021E8DA8 thumb ov093
 *   BTL_SERVER_FLOW_CalcSingleTypeAffinity 0x021C7038 thumb ov093
 *   BTL_CALC_CombineTypeAffinity 0x021D79E8 thumb ov093
 *   BTL_SERVER_FLOW_IsPokeGrounded 0x021C6F0C thumb ov093
 *   BTL_SERVER_FLOW_PushNoEffectMessage 0x021C5750 thumb ov093
 *   BTL_SERVER_FLOW_ProcImmunityOverrideNotice 0x021C6FC0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 BTL_POKEPARAM_GetTypePair(void *);
extern u8 BTL_TYPEPAIR_GetHigh(int);
extern int BTL_TYPEPAIR_GetLow(int);
extern int BTL_TYPEPAIR_IsSingleType(int);
extern int BTL_SERVER_FLOW_CalcSingleTypeAffinity(u8 *, u8 *, u8 *, u32, u8);
extern int BTL_CALC_CombineTypeAffinity(int, int);
extern int BTL_SERVER_FLOW_IsPokeGrounded(u8 *, u8 *, int);
extern void BTL_SERVER_FLOW_PushNoEffectMessage(u8 *, u8 *);
extern void BTL_SERVER_FLOW_ProcImmunityOverrideNotice(u8 *, u8 *);
int BTL_SERVER_FLOW_CalcTypeEffectiveness(u8 *p, u8 *a, u8 *b, u8 *q, int flag)
{
    int r, x;
    int changed = 0;
    if (q[6] == 17) return 3;
    x = BTL_POKEPARAM_GetTypePair(b);
    r = BTL_SERVER_FLOW_CalcSingleTypeAffinity(p, a, b, q[6], BTL_TYPEPAIR_GetHigh(x));
    if (BTL_TYPEPAIR_IsSingleType(x) == 0)
        r = BTL_CALC_CombineTypeAffinity(r, BTL_SERVER_FLOW_CalcSingleTypeAffinity(p, a, b, q[6], BTL_TYPEPAIR_GetLow(x)));
    if (r != 0) {
        if (q[6] != 4) return r;
        changed = BTL_SERVER_FLOW_IsPokeGrounded(p, b, 0);
        if (changed == 0) return r;
        r = 0;
    } else if (q[6] == 4) {
        if (BTL_SERVER_FLOW_IsPokeGrounded(p, b, 1) == 0) return 3;
    }
    if (r == 0 && flag != 0) {
        if (changed == 0) BTL_SERVER_FLOW_PushNoEffectMessage(p, b);
        else BTL_SERVER_FLOW_ProcImmunityOverrideNotice(p, b);
    }
    return r;
}
