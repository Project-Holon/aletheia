/*
 * function: POKE_TOOL_GetLevelMinExp
 * address:  0x02018544
 * packet:   pkt_02018544
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetBoxLevelMinExp 0x0201854C thumb
 */
typedef unsigned int u32;
extern u32 POKE_TOOL_GetBoxLevelMinExp(void *);
u32 POKE_TOOL_GetLevelMinExp(void *p) { return POKE_TOOL_GetBoxLevelMinExp(p); }
