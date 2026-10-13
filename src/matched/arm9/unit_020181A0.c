/*
 * unit:     yes
 * address:  0x020181A0
 * packet:   pkt_02017FB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_RecoverBoxAllPP, func_020181F4, POKE_TOOL_SetBoxMoveSlot
 *
 * Two move-slot writers over the record's ids 0x36..0x39 (the four move ids),
 * 0x3A..0x3D (their current PP) and 0x3E..0x41 (their PP-up counts), the same
 * three groups POKE_TOOL_GetBoxValueRaw reads.  POKE_TOOL_RecoverBoxAllPP refills every non-empty
 * slot's PP to the maximum WAZA_TOOL_GetMaxPP computes from the move and its PP-up
 * count; POKE_TOOL_SetBoxMoveSlot writes one slot outright, clearing the PP-up count and
 * setting the PP to the fresh maximum, or to zero when the move is zero.
 * func_020181F4 in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk, `local` because its
 * target is the next function in this unit.
 *
 * POKE_TOOL_SetBoxMoveSlot is what makes this unit and src/matched/unit_02018094.c-shaped
 * callers attest each other: its two call sites in the image are the thunk
 * here and one inside POKE_TOOL_AddBoxMove, so neither range can hold both.
 *
 * Two spellings are load bearing.  POKE_TOOL_RecoverBoxAllPP's loop counter is unsigned,
 * because the bound test is `blo` and not `blt`; the counter of the otherwise
 * identical loop in POKE_TOOL_AddBoxMove and POKE_TOOL_FindBoxMoveSlot is signed and those use
 * `blt`.  And the two truncations in POKE_TOOL_RecoverBoxAllPP sit at the call, `(u16)m`
 * and `(u8)u` on word locals, rather than on narrower locals, which is the
 * same shape as src/matched/unit_02018430.c.
 *
 * Nothing here is version specific: 0x36, 0x3A and 0x3E are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020181A0.c \
 *       --addr 0x020181A0 --thumb
 *
 * symbols:
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);

void POKE_TOOL_SetBoxMoveSlot(void *p, u16 move, u32 slot);

void POKE_TOOL_RecoverBoxAllPP(void *p)
{
    u32 t = func_02017DBC(p);
    u32 i;

    for (i = 0; i < 4; i++) {
        u32 m = func_02017E88(p, 0x36 + i, 0);

        if (m != 0) {
            u32 u = func_02017E88(p, 0x3E + i, 0);

            POKE_TOOL_SetBoxValue(p, 0x3A + i, WAZA_TOOL_GetMaxPP((u16)m, (u8)u));
        }
    }
    func_02017DE4(p, t);
}

void func_020181F4(void *p, u16 move, u32 slot)
{
    POKE_TOOL_SetBoxMoveSlot(p, move, slot);
}

void POKE_TOOL_SetBoxMoveSlot(void *p, u16 move, u32 slot)
{
    u32 pp = 0;

    POKE_TOOL_SetBoxValue(p, 0x36 + slot, move);
    POKE_TOOL_SetBoxValue(p, 0x3E + slot, 0);
    if (move != 0) {
        pp = WAZA_TOOL_GetMaxPP(move, 0);
    }
    POKE_TOOL_SetBoxValue(p, 0x3A + slot, pp);
}
