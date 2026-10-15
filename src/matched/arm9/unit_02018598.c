/*
 * unit:     yes
 * address:  0x02018598
 * packet:   pkt_0201854C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_GetNature, POKE_TOOL_GetBoxNature, POKE_TOOL_SetNature
 *
 * The middle piece of the run 0x0201854C..0x0201862C.  Its two neighbours are
 * parked in src/pending/: POKE_TOOL_GetExpForLevel is the only caller of POKE_TOOL_GetExpValue
 * in the image and POKE_TOOL_RecalcParam the only caller of POKE_TOOL_CalcParam, so neither
 * has a witness outside itself and no cut reaches them.
 *
 * POKE_TOOL_GetNature carries no label: it is the eight byte pool-word tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md to the function that follows
 * it, so the site is the `local` class.
 *
 * symbols:
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   func_02017E88  0x02017E88  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void POKE_TOOL_RecalcParam(void *p);

u8 POKE_TOOL_GetBoxNature(void *p);

u8 POKE_TOOL_GetNature(void *p)
{
    return POKE_TOOL_GetBoxNature(p);
}

u8 POKE_TOOL_GetBoxNature(void *p)
{
    return (u8)func_02017E88(p, 0x70, 0);
}

void POKE_TOOL_SetNature(void *p, u32 v)
{
    POKE_TOOL_SetPartyValue(p, 0x70, v);
    POKE_TOOL_RecalcParam(p);
}
