/*
 * file:     fldmmdl_poslog.c
 * unit:     yes
 * function: FLDMMDL_GetMovedPosSaveSize, FLDMMDL_InitMovedPosSave, FLDMMDL_IsMovedPosSet, FLDMMDL_FindMovedPosSlot, FLDMMDL_GetMovedPosSlot, FLDMMDL_HasMovedPos, FLDMMDL_GetMovedPos, FLDMMDL_StoreMovedPos, FLDMMDL_CheckMovedPosAtMapPos, FLDMMDL_IsMovedPosObjCode, FLDMMDL_InitPosRecord, FLDMMDL_ApplyBurmyFormForPlace
 * address:  0x0216E474
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trcard_sys.c (it held four originals); __FILE__ anchors: event_battle.c 0x0216E95C, trcard_sys.c 0x0216F0AC, waza_oshie.c 0x0216F918.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   d_02172A70 0x02172A70 data a2
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_GetMmdlSys 0x0216D67C thumb ov010
 *   FLDMMDL_GetPos 0x0216D88C thumb ov010
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 *   FLDMMDL_HasMovedPos  0x0216E51C  thumb  ov010
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   d_02172554  0x02172554  data  ov010  a2
 *   d_02172556  0x02172556  data  ov010  a2
 */

struct Actor;
#include "../sdk_fx.h"

struct ZukanSave;
#include "../types.h"

#include "fldmmdl_types.h"
typedef VecFx32 MovedPos;

typedef struct
{
    char pad00[44];
    unsigned int movedPosTable;
} ObjContext;


#include "../arm9/mi_memory.h"
struct Mmdl;
#include "fldmmdl.h"
struct MmdlSys;
struct VecFx32;
int FLDMMDL_HasMovedPos();
int FLDMMDL_GetMovedPos(void *mmdl, MovedPos *out);
void FLDMMDL_StoreMovedPos(void *a);
struct MmdlSys;
#include "../arm9/zukan_save.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
int FLDMMDL_CheckMovedPosAtMapPos(void *map, const VecFx32 *pos);
int FLDMMDL_IsMovedPosObjCode(u16 id);
void FLDMMDL_ApplyBurmyFormForPlace(void *saveData, void *mon, int placeId);
u32 FLDMMDL_GetMovedPosSaveSize(void);
void FLDMMDL_InitMovedPosSave(void *block);
int FLDMMDL_IsMovedPosSet(const MovedPos *pos);
int FLDMMDL_FindMovedPosSlot(int a, int b);
int FLDMMDL_GetMovedPosSlot(int mmdl);
extern const u16 d_02172A70[][4];
extern u16 d_02172554[][2];
extern u16 d_02172556[][2];

/*
 * Save-table size callback: returns 0x168, the size of the block that
 * FLDMMDL_InitMovedPosSave fills.  Pointer word 0x0216E475 at arm9 0x0209DC90.
 */
u32 FLDMMDL_GetMovedPosSaveSize(void)
{
    return 0x168;
}

/*
 * Save-table init callback: fills the 0x168-byte block with 0xFF bytes
 * (tail call to MIi_CpuClear32 through the pool word at 0x0216E48C).
 * Pointer word 0x0216E47D at arm9 0x0209DC94.
 */
void FLDMMDL_InitMovedPosSave(void *block)
{
    MIi_CpuClear32(0xFFFFFFFF, block, 0x168);
}

int FLDMMDL_IsMovedPosSet(const MovedPos *pos)
{
    if (pos->x != -1 || pos->y != -1 || pos->z != -1)
        return 1;
    return 0;
}

/*
 * lever: declaring x and y before the unsigned-long index restores the
 * table base, sentinel and index register allocation. The once300
 * permuter found this ordering; explicit-region one resolves both pools.
 */
int FLDMMDL_FindMovedPosSlot(int gridX, int gridZ)
{
    int rowX;
    int rowZ;
    unsigned long i;
    i = 0;
    do
    {
        rowX = d_02172A70[i][0];
        rowZ = d_02172A70[i][1];
        if ((rowX == gridX) && (rowZ == gridZ))
            return d_02172A70[i][2];
        i++;
    }
    while ((rowX != 65535) && (rowZ != 65535));
    return 30;
}

int FLDMMDL_GetMovedPosSlot(int mmdl)
{
    int slot = 30;

    if (FLDMMDL_IsMovedPosObjCode(FLDMMDL_GetObjCode((void *)mmdl)) == 1)
        slot = FLDMMDL_FindMovedPosSlot(FLDMMDL_GetZoneId((void *)mmdl), FLDMMDL_GetObjId((void *)mmdl));
    return slot;
}

int FLDMMDL_HasMovedPos(mmdl, unused)
void *mmdl;
int unused;
{
    int slot;
    ObjContext *ctx;

    slot = FLDMMDL_GetMovedPosSlot((int)mmdl);
    if (slot != 30) {
        ctx = (void *)FLDMMDL_GetMmdlSys(mmdl);
        return FLDMMDL_IsMovedPosSet((const MovedPos *)(ctx->movedPosTable + slot * 12));
    }
    return 0;
}

int FLDMMDL_GetMovedPos(void *mmdl, MovedPos *out)
{
    int slot;
    MovedPos *entry;
    ObjContext *ctx;

    slot = FLDMMDL_GetMovedPosSlot((int)mmdl);
    if (slot != 30) {
        ctx = (void *)FLDMMDL_GetMmdlSys(mmdl);
        entry = (MovedPos *)(ctx->movedPosTable + slot * 12);
        if (FLDMMDL_IsMovedPosSet(entry)) {
            *out = *entry;
            return 1;
        }
    }
    return 0;
}

/*
 * lever: binding the getter's pointer result to tmp restores the base
 * load before the stride, while retaining the unsigned raw address sum.
 * ObjContext shape: matched CC58 allocates 0x48 and stores input c at +44.
 * E4EC returns 30 unless E4FA compares equal to 1, then returns E4B0's
 * halfword or 30. Thus i <=65535 and i*12 <=786420; no Vec array bound
 * is assumed. D88C unconditionally initializes all 12 bytes of v.
 */
void FLDMMDL_StoreMovedPos(void *mmdl)
{
    int slot;
    MovedPos *entry;
    MovedPos curPos;
    ObjContext *ctx;
    slot = FLDMMDL_GetMovedPosSlot((int)mmdl);
    if (slot != 30)
    {
        ctx = (void *)FLDMMDL_GetMmdlSys(mmdl);
        entry = (MovedPos *) (ctx->movedPosTable + (slot * 12));
        FLDMMDL_GetPos(mmdl, (struct VecFx32 *)&curPos);
        *entry = curPos;
    }
}

/*
 * Whether the map cell under pos (x, z in whole tiles of 16 units) holds a
 * hit whose check returns 1.
 */
int FLDMMDL_CheckMovedPosAtMapPos(void *map, const VecFx32 *pos)
{
    void *mmdl = FLDMMDL_SysSearchGridPosHeight((struct MmdlSys *)map, (s16)((pos->x >> 4) / 4096), (s16)((pos->z >> 4) / 4096), pos->y, 0x20000, (int)0);

    if (mmdl != 0 && FLDMMDL_HasMovedPos(mmdl) == 1)
        return 1;
    return 0;
}

/*
 * True for kind 0x6D and 0x2003..0x2005. The range test must be written
 * as `(u16)(id + 0xDFFD) <= 2`: `id >= 0x2003 && id <= 0x2005` keeps two
 * compares, `(u16)(id - 0x2003)` pools 0x2003 and subtracts.
 */
int FLDMMDL_IsMovedPosObjCode(u16 objCode)
{
    if (objCode == 0x6D || (u16)(objCode + 0xDFFD) <= 2)
        return 1;
    return 0;
}

/*
 * Unlabelled leaf (sole blocker of ov018 INTRUDE_FIELD_InitMmdlCopyAnime): clears the word
 * at +0x18 (posType) and fills the grid position at +0x1C of a field model header.
 */
void FLDMMDL_InitPosRecord(MmdlHeader *header, u16 gridX, u16 gridZ, int posY)
{
    MmdlHeaderGridPos *pos;

    header->posType = 0;
    pos = (MmdlHeaderGridPos *)header->pos;
    pos->gridX = gridX;
    pos->gridZ = gridZ;
    pos->posY = posY;
}

void FLDMMDL_ApplyBurmyFormForPlace(void *saveData, void *mon, int placeId)
{
    struct ZukanSave *zukan;
    int species;
    int i;

    zukan = ZUKAN_SAVE_GetFromGameData(saveData);
    species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    for (i = 0; i < 25; i++) {
        if (placeId == d_02172554[i][0]) {
            int form = d_02172556[i][0];
            if (species == 0x19c) {
                POKE_TOOL_ChangeForm(mon, (u16)form);
                ZUKAN_SAVE_RegisterSeen(zukan, mon);
            }
            return;
        }
    }
}
