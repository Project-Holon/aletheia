/*
 * function: POKE_TOOL_LearnLevelUpMove
 * address:  0x02018328
 * packet:   pkt_02018328
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_PERSONAL_LoadDataDirect  0x0201ADD0  thumb
 *   POKE_TOOL_AddMove  0x0201808C  thumb
 *   func_020307B0  0x020307B0  arm
 *   sPokeToolFile  0x020A72E4  data
 *
 * Level-up learnset scan: load the species/form learnset (POKE_PERSONAL_LoadDataDirect) into
 * a 0x68-byte heap block (poke_tool.c line 0x644), then walk it from *idx
 * until the {0xFFFF, 0xFFFF} terminator.  For an entry at the record's
 * level, try to teach it (POKE_TOOL_AddMove): 0xFFFF (no free slot) answers the
 * move with bit 15 set, 0xFFFE (already known) keeps scanning, anything else
 * is returned; *idx is left one past the entry.  Wave 11, 2026-09-23.
 *
 * Load-bearing, found by hand after the permuter's hill (800, --types) and
 * the r12 lane's register swap:
 *   - `species` is u16 (truncated at the assignment) but `form` is u32 and
 *     the (u16) lands at the POKE_PERSONAL_LoadDataDirect call; `level` is u8.
 *   - FIVE 4-byte struct copies live in the frame, in this declaration
 *     order (later declaration at the lower address): e, d, f, t, cur.
 *     They are by-value copies of the entry (e for the level test, d for the
 *     move, f for the final re-read, t for the terminator test).  Written
 *     as inline helpers taking the struct by value, the compiler elides one
 *     copy and swaps two slots; spelled as explicit locals it does not.
 *   - the terminator test is an inline taking `const struct Learn *` with
 *     the `end = 0; if (..) end = 1;` accumulator, called in the `while`
 *     condition so the loop is rotated (entry `b` to the test).
 *   - `level == e.level` (level first: cmp r0, r1).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Learn { u16 move; u16 level; };

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32   POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void  POKE_PERSONAL_LoadDataDirect(u32 species, int form, void *dest);
extern u16   POKE_TOOL_AddMove(void *p, u16 move);
extern u32 func_020307B0(void *p);
extern u8    sPokeToolFile;

static inline int Learn_IsEnd(const struct Learn *t)
{
    int end = 0;
    if (t->move == 0xFFFF && t->level == 0xFFFF)
        end = 1;
    return end;
}

u16 POKE_TOOL_LearnLevelUpMove(void *p, u32 *idx, u32 heap)
{
    struct Learn *tbl;
    u16 species;
    u32 form;
    u8 level;
    u16 ret = 0;
    struct Learn e;
    struct Learn d;
    struct Learn f;
    struct Learn t;
    struct Learn cur;

    tbl = func_02030734((u16)((heap & 0x7fff) | 0x8000), 0x68, 0, (const char *)&sPokeToolFile, 0x644);
    species = POKE_TOOL_GetPartyValue(p, 5, 0);
    form = POKE_TOOL_GetPartyValue(p, 0x6f, 0);
    level = POKE_TOOL_GetPartyValue(p, 0x9e, 0);
    POKE_PERSONAL_LoadDataDirect(species, (u16)form, tbl);

    while (cur = tbl[*idx], t = cur, !Learn_IsEnd(&t)) {
        e = cur;
        if (level == e.level) {
            d = cur;
            ret = POKE_TOOL_AddMove(p, d.move);
            if (ret == 0xFFFF) {
                f = tbl[*idx];
                ret = f.move | 0x8000;
                (*idx)++;
                break;
            }
            if (ret != 0xFFFE) {
                (*idx)++;
                break;
            }
        }
        (*idx)++;
    }
    func_020307B0(tbl);
    return ret;
}
