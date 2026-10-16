/*
 * unit:     yes
 * address:  0x02018430
 * packet:   pkt_02017FB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_CalcLevel, POKE_TOOL_CalcBoxLevel
 *
 * The record's level accessor: it unlocks the block area, reads ids 5, 0x6F
 * and 8 out of it (species, form and experience), locks it again and hands the
 * three to POKE_TOOL_CalcLevelFromExp (src/matched/unit_0201850C.c), which is the same
 * computation id 0x9E of POKE_TOOL_GetBoxValueRaw performs directly on the substructs.
 * POKE_TOOL_CalcLevel in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk with no prologue, and
 * its pool word is `local` because its target is the next function in the same
 * unit.
 *
 * The three values are held in word locals and truncated at the call, not at
 * the assignment: the two `lsls #0x10` / `lsrs #0x10` pairs sit immediately in
 * front of the `bl`, after the lock call, which is what fixes POKE_TOOL_CalcLevelFromExp's
 * first two parameters as u16 and POKE_TOOL_GetBoxValue's return as a word.  The same
 * shape appears in src/matched/unit_02017E64.c and src/matched/unit_0201854C.c.
 *
 * The range stops at 0x02018480, where another eight byte thunk forwards to
 * POKE_TOOL_IsBoxOwnedByPlayer; that thunk's pool word is the only reference to POKE_TOOL_IsBoxOwnedByPlayer
 * in the image, and POKE_TOOL_IsBoxOwnedByPlayer in turn is the only caller of 0x020084F8, so
 * neither can be attested and both are left out.
 *
 * Nothing here is version specific: 5, 0x6F and 8 are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02018430.c \
 *       --addr 0x02018430 --thumb
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   POKE_TOOL_CalcLevelFromExp  0x0201850C  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_CalcLevelFromExp(u16 species, u16 form, u32 exp);

u32 POKE_TOOL_CalcBoxLevel(void *p);

u32 POKE_TOOL_CalcLevel(void *p)
{
    return POKE_TOOL_CalcBoxLevel(p);
}

u32 POKE_TOOL_CalcBoxLevel(void *p)
{
    u32 t = POKE_TOOL_DecodeBoxParam(p);
    u32 species = POKE_TOOL_GetBoxValue(p, 5, 0);
    u32 form = POKE_TOOL_GetBoxValue(p, 0x6F, 0);
    u32 exp = POKE_TOOL_GetBoxValue(p, 8, 0);

    POKE_TOOL_EncodeBoxParam(p, t);
    return POKE_TOOL_CalcLevelFromExp((u16)species, (u16)form, exp);
}
