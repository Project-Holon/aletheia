/*
 * function: POKE_TOOL_SetBoxDefaultMoves
 * address:  0x02017FB0
 * packet:   pkt_02017FB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb
 *   POKE_PERSONAL_LoadDataDirect  0x0201ADD0  thumb
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   POKE_TOOL_AddBoxMove  0x02018094  thumb
 *   POKE_TOOL_PushBoxMove  0x020180FC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   gLevelUpMoveBuf      0x02146330  data
 *
 * Reset a record's moves to its level-up set: clear the four move/PP/PP-up
 * slots, load the species/form learnset into the shared buffer at
 * 0x02146330, then teach every entry at or below the current level
 * (POKE_TOOL_AddBoxMove; 0xFFFF = no free slot, so push it in with POKE_TOOL_PushBoxMove).
 * Block-lock sandwich (POKE_TOOL_DecodeBoxParam / POKE_TOOL_EncodeBoxParam).  Wave 11, 2026-09-23.
 *
 * Load-bearing: ONE loop variable `i` for both phases (the clearing loop
 * and the learnset walk, re-zeroed in between).  With two variables the
 * zero value argument and the walk index take separate registers and every
 * callee-saved register shifts (docs/idioms: reusing a loop variable
 * across phases); the permuter's hill (800, --types) found only volatile
 * hacks.  The frame's four entry copies and the pointer-taking terminator
 * inline follow POKE_TOOL_GetLevelUpMove.c exactly (declaration order e, d, t, cur).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Learn { u16 move; u16 level; };

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern u32  POKE_TOOL_CalcBoxLevel(void *p);
extern void POKE_PERSONAL_LoadDataDirect(u32 species, int form, void *dest);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_AddBoxMove(void *p, u32 move);
extern void POKE_TOOL_PushBoxMove(void *p, u16 move);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern struct Learn gLevelUpMoveBuf[];

static inline int Learn_IsEnd(const struct Learn *t)
{
    int end = 0;
    if (t->move == 0xFFFF && t->level == 0xFFFF)
        end = 1;
    return end;
}

u32 POKE_TOOL_SetBoxDefaultMoves(void *p)
{
    u32 flag;
    u16 species;
    u32 form;
    u8 level;
    int i;
    struct Learn e;
    struct Learn d;
    struct Learn t;
    struct Learn cur;

    flag = POKE_TOOL_DecodeBoxParam(p);
    species = func_02017E88(p, 5, 0);
    form = func_02017E88(p, 0x6f, 0);
    level = POKE_TOOL_CalcBoxLevel(p);
    POKE_PERSONAL_LoadDataDirect(species, (u16)form, gLevelUpMoveBuf);

    for (i = 0; i < 4; i++) {
        POKE_TOOL_SetBoxValue(p, 0x36 + i, 0);
        POKE_TOOL_SetBoxValue(p, 0x3a + i, 0);
        POKE_TOOL_SetBoxValue(p, 0x3e + i, 0);
    }
    i = 0;
    while (cur = gLevelUpMoveBuf[i], t = cur, !Learn_IsEnd(&t)) {
        e = cur;
        if (e.level > level)
            break;
        d = cur;
        if (POKE_TOOL_AddBoxMove(p, d.move) == 0xFFFF)
            POKE_TOOL_PushBoxMove(p, d.move);
        i++;
    }
    return POKE_TOOL_EncodeBoxParam(p, flag);
}
