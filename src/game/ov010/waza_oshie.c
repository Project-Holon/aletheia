/*
 * file:     waza_oshie.c
 * unit:     yes
 * function: WAZA_OSHIE_Create, WAZA_OSHIE_Delete, WAZA_OSHIE_CreateMoveList, WAZA_OSHIE_IsListEntryValid
 * address:  0x0216F918
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from waza_oshie.c, town_map_spot.c by tools/splitfile.py.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   d_02172B74 0x02172B74 data ov010 a1
 *   POKE_PERSONAL_LoadDataDirect  0x0201ADD0  thumb
 */
#include "../types.h"

typedef struct LearnsetEntry {
    u16 move;
    u16 level;
} LearnsetEntry;
struct PokemonParam;

extern unsigned int POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);

extern void *GFL_HEAP_Alloc(u32 heap, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void MI_CpuFill8(void *p, int v, int n);

extern void POKE_PERSONAL_LoadDataDirect(unsigned int a, int b, void *buf);

void *WAZA_OSHIE_Create(u32 heapId);

void WAZA_OSHIE_Delete(void *work, unsigned unused1, unsigned unused2, unsigned unused3);

u16 *WAZA_OSHIE_CreateMoveList(void *pokemon, u32 heapId);

int WAZA_OSHIE_IsListEntryValid(u16 *p);

extern char d_02172B74[];

void *WAZA_OSHIE_Create(u32 heapId)
{
    void *work;

    work = GFL_HEAP_Alloc(heapId, 28, 0, d_02172B74, 35);
    MI_CpuFill8(work, 0, 28);
    return work;
}

/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into GFL_HEAP_Free, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WAZA_OSHIE_Delete.c \
 *       --func WAZA_OSHIE_Delete --addr 0x0216F940 --region ov010 --cc dsi/1.1p1 --thumb
 */
void WAZA_OSHIE_Delete(void *work, unsigned unused1, unsigned unused2, unsigned unused3)
{
    GFL_HEAP_Free(work);
}

static inline int LearnsetEntry_IsEnd(LearnsetEntry x)
{
    return x.move == 0xFFFF && x.level == 0xFFFF;
}

static inline u16 LearnsetEntry_Level(LearnsetEntry x)
{
    return x.level;
}

static inline u16 LearnsetEntry_Move(LearnsetEntry x)
{
    return x.move;
}

/*
 * Builds the list of level-up moves a mon could still learn: reads
 * species/form/level and its 4 current moves, loads the learnset (26
 * {move, level} pairs, 0xFFFF/0xFFFF terminated) with POKE_PERSONAL_LoadDataDirect, and
 * collects moves at or below its level that it neither knows nor already
 * collected. Returns the 0x34-byte list (caller frees); frees the learnset.
 *
 * pass 2 2026-10-06 P2L52: EXACT (also EXACT with --lang c). Load-bearing:
 *   - Every entry access is a by-value inline helper called on `tbl[j]`
 *     itself (no named entry local). The argument is not a plain local, so
 *     each call keeps its own parameter copy (the 8 stack LearnsetEntry slots of the
 *     image): CSE makes the shared tbl[j] temp at sp+0x18, loop invariants
 *     make the copies before the k and m loops, and the parameter copies in
 *     the loops keep their stores inside the loop. Named LearnsetEntry locals or
 *     helpers called on a plain local are copy-propagated or substituted.
 *   - `for` loops everywhere with `n = 0, j = 0` in the j loop (propagation
 *     on: the hoisted zero argument is the copy of i, the m guard is
 *     `cmp n,#0; bls`). A do-while k or m loop hoists the in-loop copy.
 *   - `LearnsetEntry *tbl` declared first: spill slots species 0x10, form 0xc, tbl 0x14.
 *   - The file name pool word is d_02172B74 (the old header said 02173B74).
 */
u16 *WAZA_OSHIE_CreateMoveList(void *mon, u32 heap)
{
    LearnsetEntry *tbl;
    u16 cur[4];
    u16 species;
    u8 form;
    u8 level;
    u8 i;
    u8 n;
    u8 j;
    u8 k;
    u8 m;
    u16 *out;

    species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    level = POKE_TOOL_GetPartyValue(mon, 0x9E, 0);
    for (i = 0; i < 4; i++)
        cur[i] = POKE_TOOL_GetPartyValue(mon, 0x36 + i, 0);
    tbl = (LearnsetEntry *)GFL_HEAP_Alloc(heap, 0x68, 0, d_02172B74, 0x55);
    out = (u16 *)GFL_HEAP_Alloc(heap, 0x34, 0, d_02172B74, 0x56);
    POKE_PERSONAL_LoadDataDirect(species, form, tbl);
    for (n = 0, j = 0; j < 26; j++) {
        if (LearnsetEntry_IsEnd(tbl[j])) {
            out[n] = 0xFFFF;
            break;
        }
        if (LearnsetEntry_Level(tbl[j]) > level)
            continue;
        for (k = 0; k < 4; k++) {
            if (cur[k] == LearnsetEntry_Move(tbl[j]))
                break;
        }
        if (k != 4)
            continue;
        for (m = 0; m < n; m++) {
            if (out[m] == LearnsetEntry_Move(tbl[j]))
                break;
        }
        if (m != n)
            continue;
        out[n] = LearnsetEntry_Move(tbl[j]);
        n++;
    }
    GFL_HEAP_Free(tbl);
    return out;
}

int WAZA_OSHIE_IsListEntryValid(u16 *p) { if (*p != 0xffff) return 1; return 0; }
