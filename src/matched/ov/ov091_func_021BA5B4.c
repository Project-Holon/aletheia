/*
 * function: POKELIST_TryLearnMove
 * address: 0x021BA5B4
 * packet: pkt_ov091_021BA5B4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: arm9 0x02018238 has no outside witness; tu --suggest-split cannot cut it free.
 * Verified blocker C (one --thumb, no region, EXACT, 8 bytes):
 * typedef unsigned int u32; typedef unsigned short u16;
 * extern u32 POKE_TOOL_AddBoxMoveAlt(void *,u16);
 * u32 POKE_TOOL_AddMoveAlt(void *p,u16 move) { return POKE_TOOL_AddBoxMoveAlt(p,move); }
 * symbols: POKE_TOOL_AddBoxMoveAlt 0x02018240 thumb
 * Extent ends with two bytes alignment padding.
 * symbols:
 *   POKE_TOOL_AddMove 0x0201808C thumb
 *   POKE_TOOL_AddMoveAlt 0x02018238 thumb
 
 * 2026-10-05 (D8 lane 15): 02018238 now filed EXACT as src/matched/arm9/POKE_TOOL_AddMoveAlt.c.
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 POKE_TOOL_AddMove(void *,u32);
extern u32 POKE_TOOL_AddMoveAlt(void *,u16);
u32 POKELIST_TryLearnMove(u8 *p, void *q) { u8 *s=*(u8 **)(p+0x280); if (*(u32 *)(s+0x34)==5 || *(u32 *)(s+0x34)==8) return POKE_TOOL_AddMove(q,*(u16 *)(s+0x46)); else return POKE_TOOL_AddMoveAlt(q,*(u16 *)(s+0x46)); }
