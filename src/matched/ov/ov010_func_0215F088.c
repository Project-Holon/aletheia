/*
 * function: MOVE_POKEMON_GetSkillCheckFunc
 * address: 0x0215F088
 * packet: pkt_ov010_0215F088
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02013FFC 0x02013FFC thumb
 *   d_02171258 0x02171258 data a4
 *   d_02171200 0x02171200 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02013FFC(u32 id);
extern int d_02171258[];
extern int d_02171200[];
int MOVE_POKEMON_GetSkillCheckFunc(u16 *p, int i)
{
    if (i >= 11) return 0;
    if (func_02013FFC(*p)) return *(int *)((u32)d_02171258 + ((u32)i << 3));
    return *(int *)((u32)d_02171200 + ((u32)i << 3));
}
