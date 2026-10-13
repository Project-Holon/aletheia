/*
 * function: SODATEYA_CopyInheritedIvs
 * address:  0x021C3FC0
 * packet:   pkt_ov021_021C3FC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   sSodateyaParentIvIds     0x021DA918  data  ov021  a4
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct { u32 v[6]; } T;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern T sSodateyaParentIvIds;

void SODATEYA_CopyInheritedIvs(u32 *a, u32 *b)
{
    T t = sSodateyaParentIvIds;
    u32 *pt = t.v;
    int i;

    for (i = 0; i < 6; i++) {
        u32 *e = b + i;

        if (e[0x16] != 0)
            e[6] = POKE_TOOL_GetPartyValue((void *)a[0], pt[i], 0);
        if (e[0x1c] != 0)
            e[6] = POKE_TOOL_GetPartyValue((void *)a[1], pt[i], 0);
    }
}
