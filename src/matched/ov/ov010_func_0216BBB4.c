/*
 * function: SCRCMD_RESEARCH_GetMissionGoal
 * address: 0x0216BBB4
 * packet: pkt_ov010_0216BBB4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * arithmetic: address and stride are unsigned 32-bit additions, preserving
 * the original MUL/ADD wrapping for every input bit pattern.
 * symbols:
 *   sMissionGoal 0x021723C1 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 sMissionGoal[];
int SCRCMD_RESEARCH_GetMissionGoal(int index)
{
    return *(const u8 *)((u32)sMissionGoal + (u32)index * 7u);
}
