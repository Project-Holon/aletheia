/*
 * function: MOVE_POKEMON_GetSkillEventFunc
 * address: 0x0215F0B8
 * packet: pkt_ov010_0215F0B8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZONEDATA_IsZoneInTableDFB8 0x02013FFC thumb
 *   d_02171254 0x02171254 data a4
 *   d_021711FC 0x021711FC data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 ZONEDATA_IsZoneInTableDFB8(u32 id);
extern int d_02171254[];
extern int d_021711FC[];
int MOVE_POKEMON_GetSkillEventFunc(u16 *p, int i)
{
    if (i >= 11) return 0;
    if (ZONEDATA_IsZoneInTableDFB8(*p)) return *(int *)((u32)d_02171254 + ((u32)i << 3));
    return *(int *)((u32)d_021711FC + ((u32)i << 3));
}
