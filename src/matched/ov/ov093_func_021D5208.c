/*
 * function: BTL_POKEPARAM_SetMoveInfo
 * address: 0x021D5208
 * packet: pkt_ov093_021D5208
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Interface evidence: unlike narrow declarations in other callers,
 * 021D5224 forwards full r1 into r0 without truncation; u32 preserves it.
 * symbols:
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { u16 f00; u8 f02; u8 f03; u8 f04; u8 lo : 4; u8 hi : 4; };
extern u32 WAZA_TOOL_GetMaxPP(u32, u32);
void BTL_POKEPARAM_SetMoveInfo(struct S *p, u32 a, u32 b)
{
    p->f00 = a;
    p->lo = 0;
    p->hi = 0;
    if (a != 0) p->f03 = WAZA_TOOL_GetMaxPP(a, 0);
    else p->f03 = 0;
    if (b != 0 && p->f03 > b) p->f03 = b;
    p->f02 = p->f03;
}
