/*
 * function: POKE_REGULATION_AdjustPartyLevels
 * address:  0x0201A2A8
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT* note: the 98 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A30A before the next labelled function at 0x0201A30C.
 *
 * symbols:
 *   REGULATION_GetRuleValue   0x0200AE54  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   POKEPARTY_GetMember   0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 *   POKE_REGULATION_AdjustLevel   0x0201A26C  thumb
 *   POKE_TOOL_SetLevelAndRecalc   0x02019CA0  thumb
 *
 * Sweeps the records of the second argument and rewrites those whose 0xA9
 * flag is set and whose recomputed value disagrees with what the first
 * argument's own query returns.  The value from before the loop is a spilled
 * local, so it is re-read from the frame at the one place it is used.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_AdjustPartyLevels.c \
 *       --func POKE_REGULATION_AdjustPartyLevels --addr 0x0201A2A8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Reg;
extern u32 REGULATION_GetRuleValue(struct Reg *p, u32 id);
extern u32  POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32  POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32  POKE_REGULATION_AdjustLevel(void *a0, u32 a1);
extern void POKE_TOOL_SetLevelAndRecalc(void *p, u32 v);

void POKE_REGULATION_AdjustPartyLevels(void *a0, void *a1)
{
    u32 v = REGULATION_GetRuleValue(a0, 4);
    int i;

    for (i = 0; i < (int)POKEPARTY_GetCount(a1); i++) {
        void *e = POKEPARTY_GetMember(a1, i);

        if (POKE_TOOL_GetPartyValue(e, 0xA9, 0) != 0) {
            u32 w = POKE_TOOL_GetPartyValue(e, 0x9E, 0);

            if (POKE_REGULATION_AdjustLevel(a0, w) != w)
                POKE_TOOL_SetLevelAndRecalc(e, v);
        }
    }
}
