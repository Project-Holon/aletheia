/*
 * file:     pokegra.c
 * unit:     yes
 * function: POKEGRA_GetArcID, POKEGRA_GetCgrArcIndex, POKEGRA_GetCbrArcIndex, POKEGRA_GetPalArcIndex, POKEGRA_GetCelArcIndex, POKEGRA_GetAnmArcIndex, POKEGRA_GetMCelArcIndex, POKEGRA_GetMAnmArcIndex, POKEGRA_GetNcecArcIndex, POKEGRA_ConvertCharTo2D, POKEGRA_ConvertCharTo1D, POKEGRA_DrawSpindaSpots, POKEGRA_CalcArcIndex, POKEGRA_GetTrainerArcID, POKEGRA_GetTrainerCgrArcIndex, POKEGRA_GetTrainerCbrArcIndex, POKEGRA_GetTrainerPalArcIndex, POKEGRA_GetTrainerCelArcIndex, POKEGRA_GetTrainerAnmArcIndex, POKEGRA_GetTrainerMCelArcIndex, POKEGRA_GetTrainerMAnmArcIndex, POKEGRA_GetTrainerNcecArcIndex, POKEGRA_LoadCharDataPP, POKEGRA_LoadCharData, POKEGRA_OpenHandle, POKEGRA_RegisterPalette, POKEGRA_RegisterCgr, POKEGRA_RegisterCellAnim, POKEGRA_RegisterPalettePP, POKEGRA_RegisterCgrPP, POKEGRA_RegisterCellAnimPP, POKEGRA_OpenTrainerHandle, POKEGRA_RegisterTrainerPalette, POKEGRA_RegisterTrainerCgr, POKEGRA_RegisterTrainerCellAnim, POKEGRA_LoadTrainerGraphics
 * address:  0x0202D060
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from bgwinfrm.c, pokegra.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   POKEGRA_CalcArcIndex 0x0202D4A8 thumb arm9
 *   PokegraFileName    0x020A77AC  data
 *   MIi_CpuCopyFast 0x02082B0C  arm
 *   SpindaSpotTables  0x020A779C  data
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   TrainerGraIndexTable  0x020A023C  data
 *   POKE_TOOL_GetBoxValue   0x02017E88  thumb
 *   POKE_TOOL_IsBoxShiny   0x02017EB4  thumb
 *   ARC_UTIL_LoadScreenDataFromArchive   0x02049E34  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter   0x0204A6C8  arm
 *   CLACT_TransferCharacter   0x0204A9D0  arm
 *   APP_ICON_GetBallCellFileId   0x02027710  thumb
 *   APP_ICON_GetBallPaletteFileId   0x02027714  thumb
 *   APP_ICON_GetArchiveId   0x020275E4  thumb
 *   ARC_TOOL_CreateHandle   0x020490F4  arm
 *   CLACT_RegisterCellAnim   0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle   0x02049238  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   ARC_UTIL_LoadScreenDataFromHandle  0x02049E74  arm
 *   CLACT_TransferPalette  0x0204ADEC  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   APP_ICON_GetBallAnimFileId  0x02027718  thumb
 *   APP_ICON_GetBallFrameFileId  0x0202771C  thumb
 *   POKEGRA_GetArcID 0x0202D060 thumb arm9
 *   POKEGRA_GetCgrArcIndex 0x0202D064 thumb arm9
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb arm9
 */
#include "iss_switch_sys_shared_types.h"
#include "iss_switch_set_shared_types.h"

#include "gfl_heap_wrap.h"


int POKEGRA_GetArcID(void);

s32 POKEGRA_GetCgrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetCbrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetPalArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetMCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetMAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetNcecArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

void POKEGRA_CalcArcIndex(u32 arcId, u32 monsNo, s32 formNo, s32 sex, u32 rare, u32 dir, u32 egg, u32 *outIndex, u32 *outDirOffset, u32 *outSex, u32 *outRare, u32 *outFormPalIndex, u32 isCgr);

int POKEGRA_GetArcID(void){ return 4; }

/*
 * The two consecutive three-out-pointer wrappers around the 13-argument
 * text/window measurement routine at 0x0202D4A8, folded into one
 * translation unit. The first sets the trailing flag to one and returns the
 * plain sum of the three accumulators; the second leaves every flag zero
 * and adds two.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D064.c \
 *       --addr 0x0202D064 --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetCgrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;
    s32 sexOffset;

    POKEGRA_CalcArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), (u32 *)(&sexOffset), 0, 0, 1);
    return sexOffset + (index + dirOffset);
}

s32 POKEGRA_GetCbrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;
    s32 sexOffset;

    POKEGRA_CalcArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), (u32 *)(&sexOffset), 0, 0, 0);
    return sexOffset + (index + dirOffset + 2);
}

/*
 * One of a family of thin wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8: it forwards its own three stack
 * arguments, hands the callee out-pointers for two width accumulators and
 * a status word, and folds the results into a single returned extent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKEGRA_GetPalArcIndex.c \
 *       --func POKEGRA_GetPalArcIndex --addr 0x0202D0D4 --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetPalArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 rareOffset;
    s32 palIndex;

    palIndex = 0;
    POKEGRA_CalcArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), 0, 0, (u32 *)(&rareOffset), (u32 *)(&palIndex), 0);
    if (palIndex == 0) {
        palIndex = index + 0x12 + rareOffset;
    }
    return palIndex;
}

/*
 * The three consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (4, 5, 6).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D110.c \
 *       --addr 0x0202D110 --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 4;
}

s32 POKEGRA_GetAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 5;
}

s32 POKEGRA_GetMCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 6;
}

/*
 * The two consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (7, 8).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D1AC.c \
 *       --addr 0x0202D1AC --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetMAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 7;
}

s32 POKEGRA_GetNcecArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 8;
}


struct NNSG2dCharacterData;

struct ArcFile;

struct NitroFileHeader;

/* NitroSystem character data header (the real NNS layout). */
#include "nns_g2d_res_types.h"

typedef enum { POKEGRA_DIR_OFFSET_FRONT } PokegraDirOffset;

#include "mi_memory.h"

#include "poke_tool.h"

struct BoxPokemon;

struct BoxPokemon;


#include "arc_util.h"

#ifdef __MWERKS__
extern s32 CLACT_RegisterPaletteEx(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 first_color, u16 color_count, u16 heap_id);
extern u32 CLACT_RegisterCharacter(void *h, u32 file_idx, u32 compressed, u32 engine, u32 s0); /* original prototype; the definition differs in argument width, pointer type, return type */
extern void CLACT_TransferCharacter(s32 charIndex, struct NNSG2dCharacterData *data);
#else
#include "clact.h"
#endif


#include "app_icon.h"






struct ArcHandle;

#include "arc_tool.h"

struct PaletteData;


#include "nns_g2d_anim_bank.h"

void POKEGRA_ConvertCharTo2D(NNSG2dCharacterData *charData, u32 heapId);

void POKEGRA_ConvertCharTo1D(NNSG2dCharacterData *charData, u32 heapId);

void POKEGRA_DrawSpindaSpots(NNSG2dCharacterData *charData, u32 personality);

u32 POKEGRA_GetTrainerArcID(u32 isBack);

u32 POKEGRA_GetTrainerCgrArcIndex(u32 trType, u32 flags);

u32 POKEGRA_GetTrainerCbrArcIndex(u32 trType, u32 flags);

u32 POKEGRA_GetTrainerPalArcIndex(u32 trType, u32 flags);

u32 POKEGRA_GetTrainerCelArcIndex(u32 trType, u32 flags);

u32 POKEGRA_GetTrainerAnmArcIndex(u32 trType, u32 flags);

u32 POKEGRA_GetTrainerMCelArcIndex(u32 trType, u32 flags);

u32 POKEGRA_GetTrainerMAnmArcIndex(u32 trType, u32 flags);

u32 POKEGRA_GetTrainerNcecArcIndex(u32 trType, u32 flags);

void *POKEGRA_LoadCharDataPP(NNSG2dCharacterData **outCharData, void *pp, u32 dir, u16 heapId);

void *POKEGRA_LoadCharData(NNSG2dCharacterData **outCharData, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg, u32 personality, volatile u16 heapId);

void *POKEGRA_OpenHandle(u32 heapId);

int POKEGRA_RegisterPalette(void *handle, int monsNo, int formNo, int sex, u32 rare, int dir, int egg, int drawType, unsigned short palOffset, unsigned short heapId);

u32 POKEGRA_RegisterCgr(void *handle, u32 monsNo, u32 formNo, u32 sex, volatile u32 rare, volatile u32 dir, volatile u32 egg, volatile u32 personality, volatile u32 drawType, volatile u16 heapId);

u32 POKEGRA_RegisterCellAnim(u32 monsNo, u32 formNo, u32 sex, u32 rare, volatile u32 dir, volatile u32 egg, volatile u32 mapping, volatile u32 unusedArg, volatile u16 heapId);

int POKEGRA_RegisterPalettePP(void *handle, void *pp, int dir, int drawType, unsigned short palOffset, unsigned short heapId);

int POKEGRA_RegisterCgrPP(void *handle, void *pp, int dir, int drawType, unsigned short heapId);

u32 POKEGRA_RegisterCellAnimPP(void *pp, u32 dir, u32 mapping, u32 unusedArg, u16 heapId);

void *POKEGRA_OpenTrainerHandle(u32 heapId);

s32 POKEGRA_RegisterTrainerPalette(void *handle, u32 trType, u32 drawType, u32 palOffset, u16 heapId);

s32 POKEGRA_RegisterTrainerCgr(void *handle, u32 trType, u32 drawType, u32 heapId);

s32 POKEGRA_RegisterTrainerCellAnim(u32 unusedArg, u32 mapping, u32 drawType, u16 heapId);

void POKEGRA_LoadTrainerGraphics(void *handle, u32 trType, u32 charDst, u32 palDst, volatile u16 heapId);

extern const char PokegraFileName[];

extern const u8 *const SpindaSpotTables[4];

extern const u8 TrainerGraIndexTable[];

void POKEGRA_ConvertCharTo2D(NNSG2dCharacterData *charData, u32 heapId)
{
    u8 *raw = charData->pRawData;
    u8 *work;
    u32 rowBytes;
    int i;
    u32 offset;

    work = GFL_HEAP_Alloc((u16)((heapId & 0x7fff) | 0x8000), 0x1200, 1, PokegraFileName, 0x100);
    MIi_CpuCopyFast(raw, work, 0x1200);

    rowBytes = 0x180;
    offset = 0;
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(work + offset, raw + i * rowBytes, 0x100);
        offset += 0x100;
    }
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(work + offset, raw + (i * 12 + 8) * 32, 0x80);
        offset += 0x80;
    }

    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(work + offset, raw + (i * rowBytes + 0xc00), 0x100);
        offset += 0x100;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(work + offset, raw + (i * 12 + 0x68) * 32, 0x80);
        offset += 0x80;
    }
    GFL_HEAP_Free(work);
}

void POKEGRA_ConvertCharTo1D(NNSG2dCharacterData *charData, u32 heapId)
{
    u8 *raw;
    u8 *work;
    s32 i;
    s32 offset;

    raw = charData->pRawData;
    work = (u8 *)GFL_HEAP_Alloc((u16)((heapId & 0x7fff) | 0x8000), 0x1200,
                              1, PokegraFileName, 313);
    MIi_CpuCopyFast(raw, work, 0x1200);

    offset = 0;
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(work + i * 0x180, raw + offset, 0x100);
        offset += 0x100;
    }
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(work + (i * 12 + 8) * 32, raw + offset, 0x80);
        offset += 0x80;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(work + (0xc00 + i * 0x180), raw + offset, 0x100);
        offset += 0x100;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(work + (i * 12 + 0x68) * 32, raw + offset, 0x80);
        offset += 0x80;
    }
    GFL_HEAP_Free(work);
}

/*
 * pokegra.c (wave 13): stamp four shape tables into a 4bpp tile image.  For
 * each of the four 0xff-terminated (x, y) pair tables at 0x020A779C, offset
 * by the low nibble pair of a1 (minus 8 each, a1 then shifted down a byte per
 * table), locate the pixel's byte in a 12-tile-wide 8x8 tile layout and, when
 * its nibble is colour 1..3, move it to 6..8 (+5 low, +0x50 high).
 *
 * WHAT CLOSED IT (docs/notes/POKEGRA_DrawSpindaSpots.c.txt: 216 against 216, 29 to 39
 * bytes out, "idx in r0 / v in r2" allocation never reached by sixteen
 * spellings, permuter flat): there is NO hoisted byte local.  Each arm reads
 * the pixel byte itself and updates it with a compound assignment,
 * `n = blob[idx] & 0xf0; if (...) blob[idx] += 0x50;`.  The compiler hoists
 * the common load itself, after the `x & 1` test, and that is the register
 * assignment the image has.  The note's "v read inside each arm" attempt
 * (212 bytes) wrote `v = blob[idx]` per arm; the compound `+=` is what makes
 * the two arms' loads identical expressions the compiler can merge.  The
 * quotient locals cx/cy (second pass) and `j = 0` above the terminator test
 * (first pass) stand.
 */
void POKEGRA_DrawSpindaSpots(NNSG2dCharacterData *charData, u32 personality)
{
    u8 *raw = charData->pRawData;
    int i;
    int point;
    const u8 *spotTable;
    s32 x, y, tileX, tileY, byteIdx, nibble;

    for (i = 0; i < 4; i++) {
        spotTable = SpindaSpotTables[i];
        point = 0;
        if (spotTable[0] != 0xff) {
            s32 offsetX = (s32)(personality & 0xf) - 8;
            s32 offsetY = (s32)((personality & 0xf0) >> 4) - 8;
            do {
                x = offsetX + (spotTable[point * 2] + 0x16);
                y = offsetY + (spotTable[point * 2 + 1] + 0x10);
                tileX = x / 8;
                tileY = y / 8;
                byteIdx = ((x % 8) + (y % 8) * 8 + (tileX + tileY * 12) * 64) / 2;
                if (x & 1) {
                    nibble = raw[byteIdx] & 0xf0;
                    if (nibble >= 0x10 && nibble <= 0x30)
                        raw[byteIdx] += 0x50;
                } else {
                    nibble = raw[byteIdx] & 0xf;
                    if (nibble >= 1 && nibble <= 3)
                        raw[byteIdx] += 5;
                }
                point++;
            } while (spotTable[point * 2] != 0xff);
        }
        personality >>= 8;
    }
}

/*
 * pokegra.c: resolve a species/form/egg to its graphics archive index, the
 * shiny palette flag (0 or 9), the draw mode and base, checking the
 * narc for the gendered palette variant when mode 1 asks.
 *
 * The 4-byte residue that held through five lanes and 2320 permuter
 * compiles (docs/notes/POKEGRA_CalcArcIndex.c.txt: the two spilled values got
 * sp+4/sp+8 the wrong way round) is a declaration: the 2-way shiny value
 * written to *out_pal is an enum, which changes where the frame allocator
 * puts its spill slot (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md;
 * the permuter's `type` mutation only cycles integer types).  `case 1`
 * is written before `case 2`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKEGRA_CalcArcIndex.c  *       --func POKEGRA_CalcArcIndex --addr 0x0202D4A8 --thumb --cc 1.1p1
 */
void POKEGRA_CalcArcIndex(u32 arcId, u32 monsNo, s32 formNo, s32 sex,
                   u32 rare, u32 dir, u32 egg,
                   u32 *outIndex, u32 *outDirOffset, u32 *outSex, u32 *outRare,
                   u32 *outFormPalIndex, u32 isCgr)
{
    s32 index;
    s32 formCount;
    s32 formStart;
    s32 palOnlyForms;
    PokegraDirOffset dirOffset;
    s32 sexFileOffset;

    index = monsNo * 0x14;

    if (dir == 0) {
        dirOffset = 0;
    } else {
        dirOffset = 9;
    }

    if (isCgr != 0) {
        if (dir == 0) {
            sexFileOffset = 0;
        } else {
            sexFileOffset = 9;
        }
    } else {
        if (dir == 0) {
            sexFileOffset = 2;
        } else {
            sexFileOffset = 0xb;
        }
    }

    if (egg != 0) {
        s32 isManaphy;

        if (monsNo == 0x1ea) {
            isManaphy = 1;
        } else {
            isManaphy = 0;
        }
        index = (isManaphy + 0x28a) * 0x14;
    } else if (formNo != 0) {
        formStart = (s32)POKE_TOOL_GetPersonalParam((u16)monsNo, 0, 0x1f);
        palOnlyForms = (s32)POKE_TOOL_GetPersonalParam((u16)monsNo, 0, 0x23);
        formCount = (s32)POKE_TOOL_GetPersonalParam((u16)monsNo, 0, 0x20);
        if (formNo >= formCount) {
            formNo = 0;
        }
        if (palOnlyForms != 0) {
            if (outFormPalIndex != 0 && formNo != 0) {
                *outFormPalIndex = rare + (u32)((formStart + formNo - 1) * 2 + 0x37ad);
            }
        } else if (formNo != 0) {
            index = (formStart + formNo - 1) * 0x14 + 0x32f0;
        }
    }

    switch (sex) {
    case 0:
        break;
    case 1:
        formCount = ARC_TOOL_GetMemberSize(arcId, (u32)(index + sexFileOffset + 1));
        sex = 1;
        if (formCount == 0) {
            sex = 0;
        }
        break;
    case 2:
        sex = 0;
        break;
    default:
        break;
    }

    if (outIndex != 0) {
        *outIndex = (u32)index;
    }
    if (outDirOffset != 0) {
        *outDirOffset = (u32)dirOffset;
    }
    if (outSex != 0) {
        *outSex = (u32)sex;
    }
    if (outRare != 0) {
        *outRare = rare;
    }
}

u32 POKEGRA_GetTrainerArcID(u32 isBack)
{
    if (isBack != 0) {
        return 0x49;
    }
    return 0x48;
}

u32 POKEGRA_GetTrainerCgrArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8;
}

u32 POKEGRA_GetTrainerCbrArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 1;
}

u32 POKEGRA_GetTrainerPalArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 7;
}

u32 POKEGRA_GetTrainerCelArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 2;
}

u32 POKEGRA_GetTrainerAnmArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 3;
}

u32 POKEGRA_GetTrainerMCelArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 4;
}

u32 POKEGRA_GetTrainerMAnmArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 5;
}

u32 POKEGRA_GetTrainerNcecArcIndex(u32 trType, u32 flags)
{
    u32 index;

    if (flags & 1) {
        index = (u8)trType;
    } else if (trType > 0x69) {
        index = 0;
    } else {
        index = TrainerGraIndexTable[trType];
    }
    return index * 8 + 6;
}

/*
 * Unpacks a party mon into the nine-argument sprite request of
 * POKEGRA_LoadCharData: species (5), form (0x6F), gender (0x6E), the shiny
 * predicate POKE_TOOL_IsBoxShiny, isEgg (0x4C) and the personality word (id 0)
 * are read in that order, then forwarded along with the caller's own
 * a2/a3 pass-throughs.
 */
void *POKEGRA_LoadCharDataPP(NNSG2dCharacterData **outCharData, void *pp, u32 dir, u16 heapId)
{
    u32 monsNo;
    u32 formNo;
    u32 sex;
    u32 rare;
    u32 egg;

    monsNo = POKE_TOOL_GetBoxValue(pp, 5, 0);
    formNo = POKE_TOOL_GetBoxValue(pp, 0x6F, 0);
    sex = POKE_TOOL_GetBoxValue(pp, 0x6E, 0);
    rare = POKE_TOOL_IsBoxShiny(pp);
    egg = POKE_TOOL_GetBoxValue(pp, 0x4C, 0);
    return POKEGRA_LoadCharData(outCharData, monsNo, formNo, sex, rare, dir, egg,
                         POKE_TOOL_GetBoxValue(pp, 0, 0), heapId);
}

/*
 * Builds a sprite/resource request: POKEGRA_GetCgrArcIndex turns the mon
 * descriptor (species/form/gender plus the three stack words) into a
 * resource id, which ARC_UTIL_LoadScreenDataFromArchive instantiates with the caller's
 * out-slot `a0` as its a3 payload.  When the species word a1 is the
 * sentinel 0x147 the freshly filled *a0 is additionally run through the
 * POKEGRA_ConvertCharTo2D / POKEGRA_DrawSpindaSpots / POKEGRA_ConvertCharTo1D triple, which is why
 * `*a0` is re-read before each of them (POKEGRA_DrawSpindaSpots may store through
 * it, so the load cannot be cached).  This answers the open question in
 * docs/notes/POKEGRA_RegisterCgr.c.txt: a0 is a genuine out-parameter, written
 * by ARC_UTIL_LoadScreenDataFromArchive via its a3, not read-only.
 *
 * Blocked at MATCH: every concrete byte is identical.  2026-09-21, unblock
 * lane: ONE OF THE TWO BLOCKING SITES IS NOW CLEARED.  POKEGRA_ConvertCharTo1D was
 * filed EXACT (src/matched/POKEGRA_ConvertCharTo1D.c, shard arm9/pkt_0202D2EC.json),
 * so the +0x58 THM_CALL resolves `matched`.  Only +0x50, the call to
 * POKEGRA_DrawSpindaSpots, is still wildcarded: this function is that address's only
 * caller image-wide, so no evidence class (label/matched) can attest it and
 * nothing but an EXACT at 0x0202D3D0 will promote this file.  That function
 * is a documented near miss, now at 29 concrete mismatches (down from 41)
 * and stuck on one register-assignment decision -- see
 * docs/notes/POKEGRA_DrawSpindaSpots.c.txt, which records the lever that halved it
 * and the twelve spellings that do not move it further.
 */
void *POKEGRA_LoadCharData(NNSG2dCharacterData **outCharData, u32 monsNo, u32 formNo, u32 sex,
                    u32 rare, u32 dir, u32 egg, u32 personality, volatile u16 heapId)
{
    u32 arcIndex;
    void *file;

    arcIndex = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), monsNo, formNo, sex, rare, dir, egg);
    file = ARC_UTIL_LoadScreenDataFromArchive(POKEGRA_GetArcID(), arcIndex, 1, outCharData, heapId);
    if (monsNo == 0x147) {
        POKEGRA_ConvertCharTo2D(*outCharData, heapId);
        POKEGRA_DrawSpindaSpots(*outCharData, personality);
        POKEGRA_ConvertCharTo1D(*outCharData, heapId);
    }
    return file;
}

void *POKEGRA_OpenHandle(u32 heapId)
{
    return ARC_TOOL_CreateHandle(POKEGRA_GetArcID(), heapId);
}

int POKEGRA_RegisterPalette(void *handle, int monsNo, int formNo, int sex, u32 rare, int dir, int egg, int drawType,
                   unsigned short palOffset, unsigned short heapId)
{
    int arcId = POKEGRA_GetArcID();
    int palIndex = POKEGRA_GetPalArcIndex(arcId, monsNo, formNo, sex, rare, dir, egg);
    return CLACT_RegisterPaletteEx(handle, palIndex, drawType, palOffset, 0, 1, heapId);
}

/*
 * Issues a request through CLACT_RegisterCharacter built from a by-value tail struct
 * in the caller's frame (five words plus a u16 key at +0x14) and the
 * context POKEGRA_GetArcID()/POKEGRA_GetCgrArcIndex() pair; when a1 is the sentinel
 * 0x147 it additionally runs the same tail through POKEGRA_LoadCharData with the
 * address of a local out-slot, hands that slot's word to CLACT_TransferCharacter
 * alongside the request handle, and releases POKEGRA_LoadCharData's result through
 * GFL_HEAP_Free. The request handle is returned either way.
 *
 * Three things the C has to say exactly, all found this session (the
 * earlier DIFF is docs/notes/POKEGRA_RegisterCgr.c.txt):
 *   - the tail parameter must be `volatile`. Without it the front end
 *     re-homes the register arguments into the frame, grows `sub sp` from
 *     0x18 to 0x28 and 89 bytes differ.
 *   - the key sits at +0x14 of the tail, not +0x10: the struct carries five
 *     u32 words (s0..s4) ahead of it, and s4 is CLACT_RegisterCharacter's own stack
 *     argument read from [sp,#0x40].
 *   - `k` and `v` must be separate named locals read in that order just
 *     before the CLACT_RegisterCharacter call. Passing `t.key`/`t.s4` inline (in
 *     either order, with or without a cast away from volatile, and with the
 *     stack arg typed u16) schedules `ldr r3,[sp,#0x40]` after the
 *     `movs r2,#1`/`str r0,[sp]` pair instead of before it: the last 6 bytes
 *     of the DIFF, and the only thing that moves them.
 *
 * The out-slot at sp+0x14 is real: POKEGRA_LoadCharData reads `*a0` three times and
 * never stores through it, so the `ldr r1,[sp,#0x14]` after the call reads
 * back an uninitialised local. That is what the original does; the note's
 * open question about a hidden write inside POKEGRA_LoadCharData is resolved as
 * "there is none, and the C does not need one".
 */
u32 POKEGRA_RegisterCgr(void *handle, u32 monsNo, u32 formNo, u32 sex, volatile u32 rare, volatile u32 dir,
                  volatile u32 egg, volatile u32 personality, volatile u32 drawType, volatile u16 heapId)
{
    void *charFile;
    u32 cgrIndex;
    u32 cgrArcIndex;
    u32 heap;
    u32 vramType;
    NNSG2dCharacterData *charData;

    cgrArcIndex = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), monsNo, formNo, sex, rare, dir, egg);
    heap = heapId;
    vramType = drawType;
    cgrIndex = CLACT_RegisterCharacter(handle, cgrArcIndex, 1, vramType, heap);
    if (monsNo == 0x147) {
        charFile = POKEGRA_LoadCharData(&charData, monsNo, formNo, sex, rare, dir, egg, personality, heapId);
        CLACT_TransferCharacter(cgrIndex, charData);
        GFL_HEAP_Free(charFile);
    }
    return cgrIndex;
}

/*
 * Builds a record out of an argument struct passed by value in the caller's
 * frame: both cursors come from APP_ICON_GetBallCellFileId/APP_ICON_GetBallPaletteFileId on the same +8
 * word, the handle from ARC_TOOL_CreateHandle keyed on the +0x10 halfword with the
 * mode word from APP_ICON_GetArchiveId, and CLACT_RegisterCellAnim assembles the pair into
 * it; the handle is released before the assembled record is returned.
 *
 * The `volatile` on the by-value struct parameter is load-bearing, not
 * decoration: without it this front end proves the two callees cannot touch
 * the caller's frame, keeps args.w2 live in r5 across the first call and
 * drops the second `ldr r0,[sp,#0x20]`, and it also hoists the `ldrh` of
 * args.key above the inline APP_ICON_GetArchiveId() call. Qualifying the whole
 * parameter (rather than aliasing it through a volatile pointer, which
 * turns the two w2 loads into `[r5,#8]` and loses the `add r7,sp,#0x18`)
 * reproduces the reload, the argument scheduling and both `ldrh`s exactly.
 * See docs/notes/POKEGRA_RegisterCellAnim.c.txt for the DIFF this replaces.
 *
 * EXACT* only: the follower at 0x0202D8D0 is unlabelled, so the inferred
 * extent runs 2 bytes long over the alignment halfword. Never a byte
 * difference.
 */
u32 POKEGRA_RegisterCellAnim(u32 monsNo, u32 formNo, u32 sex, u32 rare, volatile u32 dir, volatile u32 egg,
                  volatile u32 mapping, volatile u32 unusedArg, volatile u16 heapId)
{
    u32 cellDatId;
    u32 anmDatId;
    void *handle;
    u32 cellIndex;

    cellDatId = APP_ICON_GetBallCellFileId(mapping);
    anmDatId = APP_ICON_GetBallPaletteFileId(mapping);
    handle = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), heapId);
    cellIndex = CLACT_RegisterCellAnim(handle, cellDatId, anmDatId, heapId);
    ARC_TOOL_DeleteHandle(handle);
    return cellIndex;
}

int POKEGRA_RegisterPalettePP(void *handle, void *pp, int dir, int drawType, unsigned short palOffset, unsigned short heapId)
{
    int monsNo = POKE_TOOL_GetBoxValue(pp, 5, 0);
    int formNo = POKE_TOOL_GetBoxValue(pp, 0x6f, 0);
    int sex = POKE_TOOL_GetBoxValue(pp, 0x6e, 0);
    int rare = POKE_TOOL_IsBoxShiny(pp);
    int egg = POKE_TOOL_GetBoxValue(pp, 0x4c, 0);

    return POKEGRA_RegisterPalette(handle, monsNo, formNo, sex, rare, dir, egg, drawType, palOffset, heapId);
}

int POKEGRA_RegisterCgrPP(void *handle, void *pp, int dir, int drawType, unsigned short heapId)
{
    int monsNo = POKE_TOOL_GetBoxValue(pp, 5, 0);
    int formNo = POKE_TOOL_GetBoxValue(pp, 0x6f, 0);
    int sex = POKE_TOOL_GetBoxValue(pp, 0x6e, 0);
    int rare = POKE_TOOL_IsBoxShiny(pp);
    int egg = POKE_TOOL_GetBoxValue(pp, 0x4c, 0);
    int personality = POKE_TOOL_GetBoxValue(pp, 0, 0);

    return POKEGRA_RegisterCgr(handle, monsNo, formNo, sex, rare, dir, egg, personality, drawType, heapId);
}

/*
 * Collects five properties off the handle (POKE_TOOL_GetBoxValue with selectors 5,
 * 0x6f, 0x6e and 0x4c, plus POKE_TOOL_IsBoxShiny) and forwards them into
 * POKEGRA_RegisterCellAnim together with this function's own three trailing words and
 * its u16 key, tail-position, returning what POKEGRA_RegisterCellAnim returns.
 *
 * Arity note (this is what the earlier note was blocked on): POKEGRA_RegisterCellAnim
 * itself is written with a by-value `volatile struct Args` trailing
 * parameter, because that is the only shape that reproduces ITS body -- but
 * the caller must NOT be written that way. Declaring the extern with the
 * aggregate, and building it in a named local (volatile or not), makes the
 * front end materialise the struct in the frame and copy it out with
 * ldm/stm: `sub sp` grows 0x24 -> 0x38 and 49 bytes differ. A C99 compound
 * literal at the call site is worse still (zero-fills first, 77 bytes).
 * Spelling the same five trailing words as plain scalars in this
 * translation unit's own prototype writes them straight into the outgoing
 * block and is EXACT. The two spellings agree on the ABI, so both files are
 * correct about the boundary; only the callee's side needs the aggregate.
 *
 * EXACT* only: the follower at 0x0202DA04 is unlabelled, so the inferred
 * extent runs over the trailing alignment halfword. Never a byte difference.
 */
u32 POKEGRA_RegisterCellAnimPP(void *pp, u32 dir, u32 mapping, u32 unusedArg, u16 heapId)
{
    u32 monsNo;
    u32 formNo;
    u32 sex;
    u32 rare;

    monsNo = POKE_TOOL_GetBoxValue((void *)pp, 5, 0);
    formNo = POKE_TOOL_GetBoxValue((void *)pp, 0x6f, 0);
    sex = POKE_TOOL_GetBoxValue((void *)pp, 0x6e, 0);
    rare = POKE_TOOL_IsBoxShiny((void *)pp);

    return POKEGRA_RegisterCellAnim(monsNo, formNo, sex, rare,
                         dir, POKE_TOOL_GetBoxValue((void *)pp, 0x4c, 0), mapping, unusedArg, heapId);
}

void *POKEGRA_OpenTrainerHandle(u32 heapId)
{
    return ARC_TOOL_CreateHandle(POKEGRA_GetTrainerArcID(0), heapId);
}

s32 POKEGRA_RegisterTrainerPalette(void *handle, u32 trType, u32 drawType, u32 palOffset, u16 heapId)
{
    return CLACT_RegisterPaletteEx(handle, POKEGRA_GetTrainerPalArcIndex(trType, 0), drawType, palOffset, 0, 1, heapId);
}

s32 POKEGRA_RegisterTrainerCgr(void *handle, u32 trType, u32 drawType, u32 heapId)
{
    return CLACT_RegisterCharacter(handle, POKEGRA_GetTrainerCgrArcIndex(trType, 0), 1, drawType, heapId);
}

s32 POKEGRA_RegisterTrainerCellAnim(u32 unusedArg, u32 mapping, u32 drawType, u16 heapId)
{
    u32 cellDatId;
    u32 anmDatId;
    void *handle;
    s32 cellIndex;

    cellDatId = APP_ICON_GetBallAnimFileId(mapping);
    anmDatId = APP_ICON_GetBallFrameFileId(mapping);
    handle = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), heapId);
    cellIndex = CLACT_RegisterCellAnim(handle, cellDatId, anmDatId, heapId);
    ARC_TOOL_DeleteHandle(handle);
    return cellIndex;
}

/*
 * Loads two archived resources into a pair of consumers.  Each half
 * turns the caller's id into an archive entry index (POKEGRA_GetTrainerPalArcIndex for
 * the first, POKEGRA_GetTrainerCgrArcIndex for the second), pulls the entry out of the
 * archive set named by the fifth, stack-passed u16 argument, hands the
 * unpacked payload to its consumer and then frees the container with
 * the common finalizer GFL_HEAP_Free.
 *
 * The u16 fifth argument is re-read from the incoming argument area for
 * the second call rather than cached, so it is spelled as a `volatile
 * u16' stack parameter.
 */
void POKEGRA_LoadTrainerGraphics(void *handle, u32 trType, u32 charDst, u32 palDst, volatile u16 heapId)
{
    void *file;
    void *palData;
    NNSG2dCharacterData *charData;

    file = ARC_TOOL_LoadHandleMember(handle, POKEGRA_GetTrainerPalArcIndex(trType, 0), heapId);
    NNS_G2dGetUnpackedPaletteData(file, &palData);
    CLACT_TransferPalette(palDst, palData, 1);
    GFL_HEAP_Free(file);

    file = ARC_UTIL_LoadScreenDataFromHandle((void *)handle, POKEGRA_GetTrainerCgrArcIndex(trType, 0), 1, (&charData), heapId);
    CLACT_TransferCharacter(charDst, charData);
    GFL_HEAP_Free(file);
}
