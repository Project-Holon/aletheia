/*
 * function: SODATEYA_ApplyIncenseBabyRule
 * address:  0x021C3B2C
 * packet:   pkt_ov021_021C3B2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   SODATEYA_GetSpeciesParent  0x021C3BB0  thumb  ov021
 *   sSodateyaIncenseBabyTable     0x021DA960  data  ov021  a4
 */

typedef unsigned int u32;

typedef struct { u32 a, b, c; } E;
typedef struct { E e[12]; } T;

extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);
extern int SODATEYA_GetSpeciesParent(u32 a);
extern T sSodateyaIncenseBabyTable;

void SODATEYA_ApplyIncenseBabyRule(u32 *p, u32 *q)
{
    T t = sSodateyaIncenseBabyTable;
    int i;
    u32 r5, r3;
    u32 x = SODATEYA_GetSpeciesParent((u32)p);

    i = 0;
    POKE_TOOL_GetPartyValue((void *)x, 5, 0);
    POKE_TOOL_GetPartyValue((void *)x, 6, 0);
    r5 = POKE_TOOL_GetPartyValue((void *)p[0], 6, 0);
    r3 = POKE_TOOL_GetPartyValue((void *)p[1], 6, 0);
    for (; i < 12; i++) {
        if (*q == t.e[i].a && r5 != t.e[i].b && r3 != t.e[i].b) {
            *q = t.e[i].c;
            return;
        }
    }
}
