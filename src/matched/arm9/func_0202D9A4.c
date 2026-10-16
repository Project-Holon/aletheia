/*
 * function: POKEGRA_RegisterCellAnimPP
 * address:  0x0202D9A4
 * packet:   pkt_0202D7D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Collects five properties off the handle (POKE_TOOL_GetBoxValue with selectors 5,
 * 0x6f, 0x6e and 0x4c, plus POKE_TOOL_IsBoxShiny) and forwards them into
 * POKEGRA_RegisterCellAnim together with this function's own three trailing words and
 * its u16 key, tail-position, returning what POKEGRA_RegisterCellAnim returns.
 *
 * Arity note (this is what the earlier note was blocked on): POKEGRA_RegisterCellAnim
 * itself is written with a by-value `volatile struct Args` trailing
 * parameter, because that is the only shape that reproduces ITS body -- but
 * the caller must NOT be written that way. Declaring the extern with the
 * aggregate, and building it in a named local (volatile or not), makes the
 * front end materialise the struct in the frame and copy it out with
 * ldm/stm: `sub sp` grows 0x24 -> 0x38 and 49 bytes differ. A C99 compound
 * literal at the call site is worse still (zero-fills first, 77 bytes).
 * Spelling the same five trailing words as plain scalars in this
 * translation unit's own prototype writes them straight into the outgoing
 * block and is EXACT. The two spellings agree on the ABI, so both files are
 * correct about the boundary; only the callee's side needs the aggregate.
 *
 * EXACT* only: the follower at 0x0202DA04 is unlabelled, so the inferred
 * extent runs over the trailing alignment halfword. Never a byte difference.
 * symbols:
 *   POKE_TOOL_GetBoxValue   0x02017E88  thumb
 *   POKE_TOOL_IsBoxShiny   0x02017EB4  thumb
 *   POKEGRA_RegisterCellAnim   0x0202D898  thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_IsBoxShiny(void *p);
extern u32 POKEGRA_RegisterCellAnim(u32 a0, u32 a1, u32 a2, u32 a3,
                         u32 w0, u32 w1, u32 w2, u32 w3, u32 key);

u32 POKEGRA_RegisterCellAnimPP(u32 h, u32 b1, u32 b2, u32 b3, u16 key)
{
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    v1 = POKE_TOOL_GetBoxValue((void *)h, 5, 0);
    v2 = POKE_TOOL_GetBoxValue((void *)h, 0x6f, 0);
    v3 = POKE_TOOL_GetBoxValue((void *)h, 0x6e, 0);
    v4 = POKE_TOOL_IsBoxShiny((void *)h);

    return POKEGRA_RegisterCellAnim(v1, v2, v3, v4,
                         b1, POKE_TOOL_GetBoxValue((void *)h, 0x4c, 0), b2, b3, key);
}
