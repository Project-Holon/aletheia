/*
 * function: func_021B9D04
 * address: 0x021B9D04
 * packet: pkt_ov092_021B9D04
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_SetStatusCondition 0x02017F9C thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb  arm9
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb  arm9
 * extent: code ends at 0x021B9D44; remaining handed extent is rodata.
 */
typedef unsigned int u32;
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetStatusCondition(void *p, u32 v);
void func_021B9D04(void *p)
{
    u32 saved;
    u32 zero;
    saved = POKE_TOOL_DecodePartyParam(p);
    zero = 0;
    if (func_02017E1C(p, 0x98, 0) == 14) {
        func_02017E40(p, 0xa0, func_02017E1C(p, 0xa1, zero));
        POKE_TOOL_SetStatusCondition(p, zero);
    }
    POKE_TOOL_EncodePartyParam(p, saved);
}
