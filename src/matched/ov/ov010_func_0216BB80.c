/*
 * function: FIELD_G3D_MAP_GetMissionTargetCount
 * address: 0x0216BB80
 * packet: pkt_ov010_0216BB80
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * arithmetic: address and stride are unsigned 32-bit additions, preserving
 * the original MUL/ADD wrapping for every input bit pattern.
 * symbols:
 *   sMissionTargetCount 0x021723BD data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 sMissionTargetCount[];
int FIELD_G3D_MAP_GetMissionTargetCount(int index)
{
    return *(const u8 *)((u32)sMissionTargetCount + (u32)index * 7u);
}
