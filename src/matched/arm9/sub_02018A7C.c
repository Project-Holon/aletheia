/*
 * function: POKE_TOOL_CalcParam
 * address:  0x02018A7C
 * packet:   pkt_02018A7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 660 bytes, one function, no jump table.
 *
 * The six-stat recalculation of poke_tool.c, and the only thing in the region
 * that reads and writes the record through both halves of the dispatcher
 * quartet at once.  It takes no arguments but the record pointer: everything
 * it needs is read back through POKE_TOOL_GetPartyValue (src/matched/unit_02017E1C.c)
 * and everything it produces is written through POKE_TOOL_SetPartyValue
 * (src/matched/unit_02017E40.c), so the whole function is seventeen reads, a
 * base-stat table lookup, six formulas and six writes.
 *
 * Its single caller is POKE_TOOL_RecalcParam (src/pending/unit_020185C4.c), which was
 * MATCH-capped on exactly this address; with this entry EXACT the `matched`
 * class carries that site and the parked file graduates.
 *
 * ---------------------------------------------------------------------------
 * THE IDS, AND WHERE THE FIELD MAP FOR THEM IS
 * ---------------------------------------------------------------------------
 * The party-area ids are POKE_TOOL_GetPartyValueRaw's (src/matched/POKE_TOOL_GetPartyValueRaw.c) and the
 * block-area ids are POKE_TOOL_GetBoxValueRaw's (src/pending/POKE_TOOL_GetBoxValueRaw.c, whose header
 * carries the full map).  What this function uses:
 *
 *   read  0x9E  level          0xA1  current max HP   0xA0  current HP
 *   read  0x46..0x4B           the six 5 bit IVs, in stat order
 *   read  0x0D..0x12           the six effort values, capped at 510 together
 *   read  0x6F  form           0x05  species
 *   write 0xA1  max HP
 *   write 0xA2..0xA6           attack, defence, speed, sp. attack, sp. defence
 *   write 0xA0  current HP, and only when the result is non zero
 *
 * POKE_TOOL_GetPersonalData(species, form) returns the species' base-stat record and the
 * first six bytes of it are the six base stats, indexed here in the same order
 * the ids are: HP, attack, defence, speed, sp. attack, sp. defence.  The
 * nature multiplier POKE_TOOL_ApplyNatureModifier (src/matched/unit_02019B04.c) is indexed
 * differently, 1, 2, 5, 3, 4 for that same sequence, so its table is in
 * attack, defence, sp. attack, sp. defence, speed order.  That permutation is
 * in the game and not in this reconstruction; the two orderings are visible
 * side by side in the five `movs r2, #k` immediates.
 *
 * The formulas are the ordinary third-generation-onwards ones, in signed
 * arithmetic throughout (the divides are `_s32_div_f`, and `ev / 4` carries
 * the rounding correction a signed shift needs):
 *
 *   max HP = (base * 2 + iv + ev / 4) * level / 100 + level + 10
 *   stat   = ((base * 2 + iv + ev / 4) * level / 100 + 5) scaled by nature
 *
 * Species 292 is the exception: its max HP is 1 and its current HP is 1,
 * whatever its level, IVs or EVs are.  The constant appears twice and the
 * compiler materialises it two different ways, `0x6F + 0xB5` off the id
 * constant that is still live from the id 0x6F read, and `0x49 << 2` in the
 * tail where nothing is live; both are written `292` in the source.
 *
 * ---------------------------------------------------------------------------
 * THE THREE THINGS THAT COST THE MOST TIME
 * ---------------------------------------------------------------------------
 * **The nature multiplier's first argument is a named local.**  Written
 * inline, `POKE_TOOL_ApplyNatureModifier(POKE_TOOL_GetNature(p), (u16)stat, k)`, the first three
 * stats are byte for byte right and the last two are not: the compiler hoists
 * the `bl POKE_TOOL_GetNature` in front of the arithmetic, which costs the `adds r5,
 * r0, #5` its fold and adds three instructions per stat, twelve bytes and 203
 * concrete bytes in total.  Binding the call result to a local before the
 * outer call, `nature = POKE_TOOL_GetNature(p);`, pins the evaluation order for all
 * five and is EXACT.  This is the store form of
 * docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md
 * seen at an argument rather than at a field, and the new file
 * docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md
 * records it, because the asymmetry (three sites right, two wrong, from one
 * source shape) is what makes it expensive to read back.
 *
 * **The named local also decides the two callee-saved registers.**  With the
 * call inline, level lands in r7 and the current HP in r6; with `nature`
 * bound, they are the original's r6 and r7.  Nothing about the register
 * numbering points at the argument that caused it.
 *
 * **Max HP is two statements, not one.**  The original stores the running
 * value into the max-HP slot, adds ten, and stores it again; the dead first
 * store is what says the source wrote `newMax = ... + level;` and then
 * `newMax = newMax + 10;`.  Written as one expression the `+ 10` folds into
 * the same instruction stream, the first `str` disappears, and the species 292
 * arm's `b` then cross-jumps onto a different store.
 *
 * The five IVs and five EVs that reach the stack are grouped, all five IVs at
 * sp+0x30 down to sp+0x20 and then all five EVs at sp+0x1C down to sp+0x0C,
 * which is what says they were declared in two runs rather than interleaved in
 * the order they are read; declared read-interleaved every slot is right by
 * four bytes and nothing else moves.  See
 * docs/idioms/local-declaration-order-is-stack-order.md.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * One content id: 292, the species whose max HP is forced to 1.  It appears
 * twice, at the max-HP branch and in the current-HP tail.  Black and White
 * share their species numbering, so it is expected to be identical in IRAO,
 * but it is the one number to re-read.  Everything else here is a structure
 * offset, a stat index or a formula constant (2, 4, 100, 5, 10), and the stat
 * formulas themselves are content in the sense that they decide the game's
 * numbers: if a White build ever diverges here, it diverges on 292 or on the
 * base-stat table POKE_TOOL_GetPersonalData hands back, not on this code.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_CalcParam.c \
 *       --func POKE_TOOL_CalcParam --addr 0x02018A7C --cc 1.1p1
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_GetNature  0x02018598  thumb
 *   POKE_TOOL_ApplyNatureModifier  0x02019B04  thumb
 *   POKE_TOOL_GetPersonalData  0x02019C54  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32  POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u8 POKE_TOOL_GetNature(void *p);
extern u32  POKE_TOOL_ApplyNatureModifier(u32 a, u32 b, u32 n);
extern void *POKE_TOOL_GetPersonalData(u32 a, u32 b);

void POKE_TOOL_CalcParam(void *p)
{
    s32 cur;
    s32 level;
    s32 form;
    s32 iv0;
    s32 oldMax;
    s32 iv1;
    s32 iv2;
    s32 iv3;
    s32 iv4;
    s32 iv5;
    s32 ev1;
    s32 ev2;
    s32 ev3;
    s32 ev4;
    s32 ev5;
    s32 species;
    const u8 *base;
    s32 newMax;
    s32 ev0;
    s32 stat;
    u32 nature;
    s32 delta;

    level = POKE_TOOL_GetPartyValue(p, 0x9E, 0);
    oldMax = POKE_TOOL_GetPartyValue(p, 0xA1, 0);
    cur = POKE_TOOL_GetPartyValue(p, 0xA0, 0);
    iv0 = POKE_TOOL_GetPartyValue(p, 0x46, 0);
    ev0 = POKE_TOOL_GetPartyValue(p, 0x0D, 0);
    iv1 = POKE_TOOL_GetPartyValue(p, 0x47, 0);
    ev1 = POKE_TOOL_GetPartyValue(p, 0x0E, 0);
    iv2 = POKE_TOOL_GetPartyValue(p, 0x48, 0);
    ev2 = POKE_TOOL_GetPartyValue(p, 0x0F, 0);
    iv3 = POKE_TOOL_GetPartyValue(p, 0x49, 0);
    ev3 = POKE_TOOL_GetPartyValue(p, 0x10, 0);
    iv4 = POKE_TOOL_GetPartyValue(p, 0x4A, 0);
    ev4 = POKE_TOOL_GetPartyValue(p, 0x11, 0);
    iv5 = POKE_TOOL_GetPartyValue(p, 0x4B, 0);
    ev5 = POKE_TOOL_GetPartyValue(p, 0x12, 0);
    form = POKE_TOOL_GetPartyValue(p, 0x6F, 0);
    species = POKE_TOOL_GetPartyValue(p, 0x05, 0);
    base = POKE_TOOL_GetPersonalData((u16)species, (u16)form);

    if (species == 292) {
        newMax = 1;
    } else {
        newMax = (base[0] * 2 + iv0 + ev0 / 4) * level / 100 + level;
        newMax = newMax + 10;
    }
    POKE_TOOL_SetPartyValue(p, 0xA1, newMax);

    stat = (base[1] * 2 + iv1 + ev1 / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(p);
    POKE_TOOL_SetPartyValue(p, 0xA2, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 1));

    stat = (base[2] * 2 + iv2 + ev2 / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(p);
    POKE_TOOL_SetPartyValue(p, 0xA3, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 2));

    stat = (base[3] * 2 + iv3 + ev3 / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(p);
    POKE_TOOL_SetPartyValue(p, 0xA4, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 5));

    stat = (base[4] * 2 + iv4 + ev4 / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(p);
    POKE_TOOL_SetPartyValue(p, 0xA5, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 3));

    stat = (base[5] * 2 + iv5 + ev5 / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(p);
    POKE_TOOL_SetPartyValue(p, 0xA6, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 4));

    if (cur != 0 || oldMax == 0) {
        if (species == 292) {
            cur = 1;
        } else if (cur == 0) {
            cur = newMax;
        } else {
            delta = newMax - oldMax;
            if (delta < 0) {
                if (cur > newMax) {
                    cur = newMax;
                }
            } else {
                cur = cur + delta;
            }
        }
    }
    if (cur != 0) {
        POKE_TOOL_SetPartyValue(p, 0xA0, cur);
    }
}
