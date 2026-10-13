/*
 * function: SODATEYA_GetCurrentLevel
 * address:  0x021C341C
 * packet:   pkt_ov021_021C341C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_0200BCD8  0x0200BCD8  thumb
 *   SODATEYA_AddExpSaturated  0x021C3510  thumb  ov021
 *   POKE_TOOL_CalcLevelFromExp  0x0201850C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0200BCA8(u32, u32);
extern u32 func_0200BC2C(u32, u32);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
struct Obj;
extern u32 func_0200BCD8(struct Obj *p, u32 i);
extern u32 SODATEYA_AddExpSaturated(u32, u32);
extern u32 POKE_TOOL_CalcLevelFromExp(u16 species, u16 form, u32 exp);

int SODATEYA_GetCurrentLevel(u32 *p, u32 b)
{
    u32 m;
    u32 s0;
    u32 s1;
    u32 s2;

    if (func_0200BCA8(p[2], b) != 1)
        return 1;
    m = func_0200BC2C(p[2], b);
    s2 = POKE_TOOL_GetPartyValue((void *)m, 5, 0);
    s0 = POKE_TOOL_GetPartyValue((void *)m, 0x6F, 0);
    s1 = POKE_TOOL_GetPartyValue((void *)m, 8, 0);
    POKE_TOOL_GetPartyValue((void *)m, 0x9E, 0);
    return POKE_TOOL_CalcLevelFromExp(s2, s0, SODATEYA_AddExpSaturated(s1, func_0200BCD8((struct Obj *)p[2], b)));
}
