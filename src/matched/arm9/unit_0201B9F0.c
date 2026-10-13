/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201B9F0
 * packet:   pkt_0201B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_HealFull, POKE_TOOL_HealParty
 *
 * pokeparty.c's healer: POKE_TOOL_HealFull restores one Pokemon (current HP to its
 * maximum, status to zero, and every move slot that is short of PP back to
 * full), and POKE_TOOL_HealParty runs it over every occupied slot of a party.
 * POKE_TOOL_HealParty is the packet's only entry point, reached from 0x02011062.
 *
 * Both of its calls into the neighbouring functions resolve, and the second one
 * is the interesting one.  0x0201B920 is covered by src/matched/
 * unit_0201B920.c, so the `matched` class would carry it on its own;
 * 0x0201B970 is a near miss (docs/notes/POKE_TOOL_RestorePP.c.txt) and has no matched
 * entry at all, and the only `bl` to it inside arm9_main is the one in this
 * file.  What attests it is an overlay: ov118 branches to 0x0201B970 at
 * 0x021BE4D0, and to 0x0201B920 at 0x021BDF2A, and those are real instructions
 * outside the compared range, which is exactly what the `label` class asks for
 * once it reads branches from the whole image rather than from arm9 alone.
 * The two functions here would otherwise have had to be split apart or parked.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  0x7F is the "fill the slot" sentinel
 * POKE_TOOL_RestorePP tests for and has to stay in step with it; 4 is the move slot
 * count written out as the loop bound; 0xA9, 0xA0, 0xA1 and 0x9D are party
 * record ids in src/matched/POKE_TOOL_GetPartyValueRaw.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The id 0xA1 read is used directly as the id 0xA0 write's third argument with
 * nothing bound to a local, so the result reaches r2 straight out of r0; this
 * is the site where the inline spelling is the right one
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * POKE_TOOL_HealFull's `for` runs 0 to 3 with no entry guard, because the compiler
 * can see the bound; the 0x7F is hoisted into r6 in front of the loop and the
 * index's zero is set before the two writes that precede it.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201B9F0.c \
 *       --addr 0x0201B9F0 --thumb
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_IsPPRestorable  0x0201B920  thumb
 *   POKE_TOOL_RestorePP  0x0201B970  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern u32  POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u8   POKE_TOOL_IsPPRestorable(void *mon, u32 slot);
extern u32  POKE_TOOL_RestorePP(void *mon, u32 slot, u32 amount);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);

void POKE_TOOL_HealFull(void *mon)
{
    s32 i;

    POKE_TOOL_SetPartyValue(mon, 0xA0, POKE_TOOL_GetPartyValue(mon, 0xA1, 0));
    POKE_TOOL_SetPartyValue(mon, 0x9D, 0);
    for (i = 0; i < 4; i++) {
        if (POKE_TOOL_IsPPRestorable(mon, i) == 1) {
            POKE_TOOL_RestorePP(mon, i, 0x7F);
        }
    }
}

void POKE_TOOL_HealParty(void *party)
{
    s32 n;
    s32 i;
    void *mon;

    n = POKEPARTY_GetCount(party);
    for (i = 0; i < n; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(mon, 0xA9, 0) != 0) {
            POKE_TOOL_HealFull(mon);
        }
    }
}
