/*
 * function: SODATEYA_CalcCompatibility
 * address:  0x021C36EC
 * packet:   pkt_ov021_021C36EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Breeding compatibility of two party Pokemon (egg groups 0x18/0x19,
 * Ditto 0x84, gender 0x6E). EXACT* only for the 2-byte pad before
 * SODATEYA_CalcCompatibilityScore. The last test is spelled as the negated conjunction
 * returning 0, so the fall-through is the call.
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_02019C90  0x02019C90  thumb
 *   SODATEYA_CalcCompatibilityScore  0x021C37F8  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern int SODATEYA_CalcCompatibilityScore(u32 a, u32 b);

int SODATEYA_CalcCompatibility(u32 a, u32 b)
{
    u32 sp[2];
    u32 fm[2];
    u32 gd[2];
    u32 g1[2];
    u32 g2[2];
    u32 m[2];
    int i;

    m[0] = a;
    m[1] = b;
    for (i = 0; i < 2; i++) {
        sp[i] = POKE_TOOL_GetPartyValue((void *)m[i], 5, 0);
        POKE_TOOL_GetPartyValue((void *)m[i], 7, 0);
        fm[i] = POKE_TOOL_GetPartyValue((void *)m[i], 0x6f, 0);
        gd[i] = POKE_TOOL_GetPartyValue((void *)m[i], 0x6e, 0);
        g1[i] = func_02019C90(sp[i], fm[i], 0x18);
        g2[i] = func_02019C90(sp[i], fm[i], 0x19);
    }
    if (g1[0] == 0xf || g1[1] == 0xf || g2[0] == 0xf || g2[1] == 0xf)
        return 0;
    if (sp[0] == 0x84 && sp[1] == 0x84)
        return 0;
    if (sp[0] == 0x84 || sp[1] == 0x84)
        return SODATEYA_CalcCompatibilityScore(a, b);
    if (gd[0] == gd[1])
        return 0;
    if (gd[0] == 2 || gd[1] == 2)
        return 0;
    if (g1[0] != g1[1] && g1[0] != g2[1] && g2[0] != g1[1] && g2[0] != g2[1])
        return 0;
    return SODATEYA_CalcCompatibilityScore(a, b);
}
