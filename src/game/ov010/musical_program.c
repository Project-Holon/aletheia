/*
 * file:     musical_program.c
 * unit:     yes
 * function: MUSICAL_PROGRAM_Create, MUSICAL_PROGRAM_Delete, MUSICAL_PROGRAM_SplitBonus, MUSICAL_PROGRAM_GetCategoryBonus, MUSICAL_PROGRAM_PackBonus, MUSICAL_PROGRAM_UnpackBonus, MUSICAL_PROGRAM_PackPicks, MUSICAL_PROGRAM_UnpackPicks, MUSICAL_PROGRAM_GetBestCategory, MUSICAL_PROGRAM_CreateNpcPerformer, MUSICAL_PROGRAM_GetBaseProgramId, MUSICAL_PROGRAM_GetPropRow, MUSICAL_PROGRAM_GetNpcPortraitClass, MUSICAL_PROGRAM_GetNpcNameId, MUSICAL_PROGRAM_GetCategoryShare
 * address:  0x02157028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_program.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MUSICAL_MCSS_LoadActorData  0x021F4F14  thumb  ov112
 *   MUSICAL_MCSS_GetElemA  0x021F5140  thumb  ov112
 *   MUSICAL_MCSS_FreeActorData  0x021F4F40  thumb  ov112
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   sMusicalProgramFileName  0x02172768  data
 *   MUSICAL_STAGE_SYS_CreateNpcPerformer 0x02156FD0 thumb ov010
 *   MUSICAL_STAGE_SYS_SetPerformerProp 0x0215700C thumb ov010
 *   _ull_mul                     0x0209C054  arm
 */
#include "event_ircbattle_shared_types.h"
#include "musical_event_shared_types.h"

#include "../types.h"

#include "../arm9/gfl_heap_wrap.h"


#include "../ov112/mus_item_data.h"



#include "../arm9/gf_standard.h"

extern const char sMusicalProgramFileName[];

#include "musical_stage_sys.h"


MusicalShowProgram *MUSICAL_PROGRAM_Create(u32 heapId, MusicalSystemHead *musicalSystem, u16 maxLevel);

int MUSICAL_PROGRAM_Delete(MusicalShowProgram *program);

void MUSICAL_PROGRAM_SplitBonus(u32 heapId, MusicalShowProgram *program, MusicalStage *stage);

u8 MUSICAL_PROGRAM_GetCategoryBonus(MusicalShowProgram *program, int index);

u32 MUSICAL_PROGRAM_PackBonus(const MusicalShowProgram *program);

void MUSICAL_PROGRAM_UnpackBonus(MusicalShowProgram *program, u32 packed);

u32 MUSICAL_PROGRAM_PackPicks(const MusicalShowProgram *program);

void MUSICAL_PROGRAM_UnpackPicks(MusicalShowProgram *program, u32 packed);

u8 MUSICAL_PROGRAM_GetBestCategory(MusicalShowProgram *program);

void MUSICAL_PROGRAM_CreateNpcPerformer(MusicalShowProgram *program, MusicalStage *stage, u8 slot, u8 npcIndex, u16 heapId);

u8 MUSICAL_PROGRAM_GetBaseProgramId(MusicalShowProgram *program);

int MUSICAL_PROGRAM_GetPropRow(MusicalShowProgram *program);

u8 MUSICAL_PROGRAM_GetNpcPortraitClass(MusicalShowProgram *program, u8 npcIndex);

u8 MUSICAL_PROGRAM_GetNpcNameId(MusicalShowProgram *program, int npcIndex);

u16 MUSICAL_PROGRAM_GetCategoryShare(MusicalShowProgram *program, int category);

static inline u32 RandBelow(u32 n)
{
    u32 r = GF_STANDARD_Rand();

    if (n != 0)
        r = ((u64)r * n) >> 32;
    return r;
}

/*
 * Creates the show program: copies the base program's category bonuses,
 * deals the extra bonus (bonusTotal / 5 steps of 5 points) to random
 * categories and picks three of the six NPC templates the musical level
 * allows. The candidate buffer is `u8 buf[6] = {0, ...}` in a nested block
 * (see docs/idioms/an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six explicit zero stores rematerialise sp+8 for the fill loop, and a plain
 * block-scope array hoists catalog out of it. RandBelow is the inline
 * `(u64)rand * n >> 32` helper; its n != 0 test folds away for constant n.
 */
MusicalShowProgram *MUSICAL_PROGRAM_Create(u32 heapId, MusicalSystemHead *musicalSystem, u16 maxLevel)
{
    MusicalShowProgram *program;
    u8 i;
    u8 remaining;
    u8 chunk;
    u8 count;
    u8 first;
    u8 second;
    u8 round;

    program = GFL_HEAP_Alloc(heapId, 0x10, 0, sMusicalProgramFileName, 100);
    program->catalog.programs = musicalSystem->programs;
    for (i = 0; i < 4; i++) {
        program->categoryBonus[i] = 0;
        program->sharePerProp[i] = 0;
    }
    for (i = 0; i < 4; i++)
        program->categoryBonus[i] = program->catalog.programs->bonus[i];
    remaining = program->catalog.programs->bonusTotal / 5;
    while (remaining != 0) {
        chunk = RandBelow(3) + 1;
        if (chunk > remaining)
            chunk = remaining;
        program->categoryBonus[RandBelow(4)] += (u8)(chunk * 5);
        remaining -= chunk;
    }
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};

        count = 0;
        for (i = 0; i < 6; i++) {
            if (program->catalog.programs[i].levelRequired <= maxLevel) {
                buf[count] = i;
                count++;
            }
        }
        if (count < 3) {
            buf[0] = 0;
            buf[1] = 1;
            buf[2] = 2;
            count = 3;
        }
        for (round = 0; round < 30; round++) {
            first = RandBelow(count);
            second = RandBelow(count);
            chunk = buf[first];
            buf[first] = buf[second];
            buf[second] = chunk;
        }
        for (i = 0; i < 3; i++)
            program->picks[i] = buf[i];
    }
    return program;
}

/*
 * Frees the show program (tail call through a pool word and `bx r3`:
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 */
int MUSICAL_PROGRAM_Delete(MusicalShowProgram *program){

    return GFL_HEAP_Free(program);
}

/*
 * Splits each category bonus over the four performers by how many of their
 * nine props fall in that category: sharePerProp = bonus / props in the
 * category, appealScore = share * the performer's props there. recoup: the
 * loop 2 and loop 4 performer pointer and the loop 2 byte counter j are
 * block-local declarations (MusicalPerformer *performer inside each for
 * body, u8 j inside the loop 2 body). Function-scope declarations gave 21
 * bytes of register swaps.
 */
void MUSICAL_PROGRAM_SplitBonus(u32 heapId, MusicalShowProgram *program, MusicalStage *stage)
{
    void *propTable;
    u8 i;
    u8 j;
    u8 category;
    u8 score;
    u8 propsInCategory[4];
    u8 propsOfPerformer[4][4];

    propTable = MUSICAL_MCSS_LoadActorData(heapId);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            propsOfPerformer[j][i] = 0;
        propsInCategory[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        MusicalPerformer *performer = stage->performers[i];
        u8 j;
        for (j = 0; j < 9; j++) {
            if (performer->equips[j].propId != 0xFF) {
                category = (u32)MUSICAL_MCSS_GetElemA(propTable, (u16)performer->equips[j].propId);
                propsOfPerformer[i][category]++;
                propsInCategory[category]++;
            }
        }
    }
    for (i = 0; i < 4; i++)
        program->sharePerProp[i] = program->categoryBonus[i] / propsInCategory[i];
    for (i = 0; i < 4; i++) {
        MusicalPerformer *performer = stage->performers[i];
        for (j = 0; j < 4; j++) {
            score = program->sharePerProp[j] * propsOfPerformer[i][j];
            performer->totalScore += score;
            performer->appealScore[j] = score;
        }
    }
    MUSICAL_MCSS_FreeActorData(propTable);
}

/*
 * Reads the category bonus byte at index.
 */
u8 MUSICAL_PROGRAM_GetCategoryBonus(MusicalShowProgram *program, int index) { return program->categoryBonus[index]; }

/*
 * Little-endian 32-bit read of the category bonuses (inverse of
 * MUSICAL_PROGRAM_UnpackBonus).
 */
u32 MUSICAL_PROGRAM_PackBonus(const MusicalShowProgram *program)
{
    return program->categoryBonus[0] + (program->categoryBonus[1] << 8) + (program->categoryBonus[2] << 16) + (program->categoryBonus[3] << 24);
}

/*
 * Stores a packed 32-bit word into the category bonuses.
 */
void MUSICAL_PROGRAM_UnpackBonus(MusicalShowProgram *program, u32 packed)
{
    program->categoryBonus[0] = packed;
    program->categoryBonus[1] = (packed & 0xFF00) >> 8;
    program->categoryBonus[2] = (packed & 0xFF0000) >> 16;
    program->categoryBonus[3] = (packed & 0xFF000000) >> 24;
}

/*
 * Little-endian 24-bit read of the three picks (inverse of MUSICAL_PROGRAM_UnpackPicks).
 */
u32 MUSICAL_PROGRAM_PackPicks(const MusicalShowProgram *program)
{
    return program->picks[0] + (program->picks[1] << 8) + (program->picks[2] << 16);
}

/*
 * Stores a packed 24-bit word into the three picks.
 */
void MUSICAL_PROGRAM_UnpackPicks(MusicalShowProgram *program, u32 packed)
{
    program->picks[0] = packed;
    program->picks[1] = (packed & 0xFF00) >> 8;
    program->picks[2] = (packed & 0xFF0000) >> 16;
}

/*
 * Index of the category with the highest bonus (first one on a tie).
 * Declaration order i, best, index is what colours them r2, r3, r4.
 */
u8 MUSICAL_PROGRAM_GetBestCategory(MusicalShowProgram *program)
{
    u8 i;
    u8 best;
    u8 index;

    best = 0;
    index = 0;
    for (i = 0; i < 4; i++) {
        if (best < program->categoryBonus[i]) {
            best = program->categoryBonus[i];
            index = i;
        }
    }
    return index;
}

/*
 * Creates the NPC performer for stage slot `slot` from the template picked
 * as npcIndex, then equips its props. The stage slot is a u8 (as wide as
 * either callee's parameter); a u32 or int is reloaded from its spill one
 * instruction early. The personality u32 is spelled out in the call, not
 * through an inline reader, so the top byte is loaded once and kept in ip
 * for the fourth argument.
 */
void MUSICAL_PROGRAM_CreateNpcPerformer(MusicalShowProgram *program, MusicalStage *stage, u8 slot, u8 npcIndex, u16 heapId)
{
    MusicalRivalEntry *rival;
    u8 j;

    rival = &program->catalog.rivals->entries[program->picks[npcIndex]];
    MUSICAL_STAGE_SYS_CreateNpcPerformer(stage, slot, rival->monsNo, rival->personality[3], rival->personality[0] + (rival->personality[1] << 8) + (rival->personality[2] << 16) + (rival->personality[3] << 24), rival->appealBase, heapId);
    for (j = 0; j < 8; j++) {
        if (rival->props[j].propId != 0x1FE && rival->props[j].propId != 0x1FF)
            MUSICAL_STAGE_SYS_SetPerformerProp(stage, slot, rival->props[j].bodySlot, rival->props[j].propId, 0, j);
    }
}

/*
 * Id of the base program (first catalog entry).
 */
u8 MUSICAL_PROGRAM_GetBaseProgramId(MusicalShowProgram *program)
{
    return program->catalog.programs->id;
}

/*
 * Prop row of the base program (selects the row of the reward prop table).
 */
int MUSICAL_PROGRAM_GetPropRow(MusicalShowProgram *program)
{
    return program->catalog.programs->propRow;
}

/*
 * Portrait class byte of the picked NPC template npcIndex.
 */
u8 MUSICAL_PROGRAM_GetNpcPortraitClass(MusicalShowProgram *program, u8 npcIndex)
{
    return program->catalog.npcInfo[program->picks[npcIndex]].portraitClass;
}

/*
 * Name id byte of the picked NPC template npcIndex.
 */
u8 MUSICAL_PROGRAM_GetNpcNameId(MusicalShowProgram *program, int npcIndex)
{
    return program->catalog.npcInfo[program->picks[npcIndex]].nameId;
}

/*
 * Share of the bonus per prop for a category.
 */
u16 MUSICAL_PROGRAM_GetCategoryShare(MusicalShowProgram *program, int category)
{
    return program->sharePerProp[category];
}
