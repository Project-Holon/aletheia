/*
 * file:     plist_plate.c
 * unit:     yes
 * function: PLIST_PLATE_Create, PLIST_PLATE_CreateEmpty, PLIST_PLATE_Delete, PLIST_PLATE_Update, PLIST_PLATE_CreateActors, PLIST_PLATE_CreateMonIcon, PLIST_PLATE_Draw, PLIST_PLATE_DrawMonInfo, PLIST_PLATE_DrawHpBar, PLIST_PLATE_DrawEgg, PLIST_PLATE_SetSelected, PLIST_PLATE_SetPalette, PLIST_PLATE_SetSlideOffset, PLIST_PLATE_ClearSlideTrail, PLIST_PLATE_SetMon, PLIST_PLATE_Redraw, PLIST_PLATE_RedrawHp, PLIST_PLATE_StartHpAnim, PLIST_PLATE_StepHpAnim, PLIST_PLATE_IsOccupied, PLIST_PLATE_GetCenterPos, PLIST_PLATE_GetTouchRect, PLIST_PLATE_GetLabelState, PLIST_PLATE_SetLabelState, PLIST_PLATE_GetHp, PLIST_PLATE_IsEgg, PLIST_PLATE_UpdateLabelState, PLIST_PLATE_CheckSelection, PLIST_PLATE_GetHpBarColor, PLIST_PLATE_GetActorOffset
 * address:  0x021BA6A0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   CLACT_SetSurfacePos 0x0204B09C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   gPlistPlateSourceName 0x021BED18 data ov091 a1
 *   gPlistPlateTileX 0x021BEC74 data ov091 a1
 *   gPlistPlateTileY 0x021BEC75 data ov091 a1
 *   gPlistPlatePaletteA 0x021BEC6C data ov091 a1
 *   gPlistPlatePaletteB 0x021BEC6D data ov091 a1
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   CLACT_GetActorAnimFrame  0x0204B8F4  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   POKE_TOOL_GetIconPalette  0x0201BBE8  thumb
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   BGWINFRM_ScaleRatio  0x0202D01C  thumb
 *   BMP_FillRect  0x02043AF4  arm
 *   gSpeciesNameBank     0x020A7370  data
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BMP_Clear  0x02043B5C  arm
 *   POKE_REGULATION_CheckPokemon 0x02019DA4 thumb
 *   BGWINFRM_GetScaleRank 0x0202D034 thumb
 *   CLACT_GetSurfacePos 0x0204B0C8 arm
 *   POKELIST_IsItemMode  0x021B9A84  thumb
 *   POKELIST_GetMoveLearnStatus  0x021B9AC8  thumb
 *   POKELIST_CheckEvolution  0x021B9BF4  thumb
 *   POKELIST_PrintTextMain  0x021B9C1C  thumb
 *   POKELIST_PrintTextSub  0x021B9C64  thumb
 *   POKELIST_PrintTextSubDirect  0x021B9CB0  thumb
 *   POKELIST_PrintExpandedTextMain  0x021B9CF4  thumb
 *   POKELIST_PrintExpandedTextSub  0x021B9D58  thumb
 *   POKELIST_PrintExpandedTextSubDirect  0x021B9DC0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

#include "pokelist_types.h"
#include "plist_plate_types.h"

struct Obj;
struct Bank;
struct Descriptor;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Bmp;
struct CharBuf;
struct Actor;

extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 value);
extern void CLACT_AddActorSurfacePos(struct Obj *actor, const PlistPlatePos *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 value);
extern void BG_SYS_MarkTileDirty(u32 bit);
struct PokemonParam;
extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);
extern u32 FILE_UTIL_IsMailItem(u16 item);
extern u32 GFL_HEAP_Free(void *mem);
struct Party;
extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);
struct Strbuf;
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
struct BmpWin;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_DrawTileEx(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, void *src, u8 sx, u8 sy, u8 sw, u8 sh);
extern struct Obj *CLACT_CreateRenderer(u16 *area, u32 mode, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *unit);
extern void CLACT_SetSurfacePos(void *unit, int index, void *offset);
extern struct Descriptor *BMP_WIN_Create(int bgLayer, u8 posX, u8 posY, int width, u8 height, u8 palette, u8 allocDir);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern void CLACT_DeleteActor(struct Actor *actor);
struct Renderer;
extern void CLACT_DeleteRenderer(struct Renderer *renderer);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ReleaseCharacter(u32 iconResource);
struct PrintQueue;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern u32 POKE_TOOL_GetStatusCondition(struct PokemonParam *pp);
extern u32 CLACT_GetActorAnimFrame(struct Actor *actor);
extern struct Obj *CLACT_CreateActor(struct Bank *bank, unsigned int char_idx, unsigned int pltt_idx, unsigned int cell_idx, const PlistPlateActorSpec *spec, u16 space, u16 heapId);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);
extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
struct BoxPokemon;
extern struct BoxPokemon *POKE_TOOL_GetBoxParam(struct PokemonParam *pp);
extern u32 POKE_TOOL_GetGraphicIndex(struct BoxPokemon *box);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 d, u16 heapId);
extern void ARC_TOOL_DeleteHandle(void *a);
extern u32 POKE_TOOL_GetIconPalette(struct BoxPokemon *box);
extern void CLACT_SetActorPaletteOffset(struct Actor *actor, u32 offset, u32 pltt_op);
extern struct WordSet *WORDSET_CreateDefault(u16 heapId);
extern void WORDSET_SetSlotMonNickname(struct WordSet *wordSet, u32 index, void *mon);
extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 index, u32 value, u32 digits, u32 padMode, u32 d);
extern u32 WORDSET_Delete(struct WordSet *wordSet);
extern u32 POKE_TOOL_CalcLevel(struct PokemonParam *pp);
extern u8 BGWINFRM_ScaleRatio(u32 a, u32 b, u32 c);
extern void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 w, u32 h, u32 value);
extern void WORDSET_SetSlotTag(struct WordSet *words, u32 slot, struct Strbuf *src, u32 grammarCase, u32 isPlural, u32 gender);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BMP_WIN_SetPosX(struct BmpWin *win, u8 posX);
extern void BG_SYS_SetTileEntry(u32 layer, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode);
extern void BMP_Clear(struct Bmp *bmp, u8 value);
struct Pokemon;
struct Regulation;
extern int POKE_REGULATION_CheckPokemon(struct Regulation *reg, struct Pokemon *mon);
extern u8 BGWINFRM_GetScaleRank(u32 a, u32 b);
extern void CLACT_GetSurfacePos(struct Obj *unit, u32 index, PlistPlatePos *out);
extern int POKELIST_IsItemMode(PokelistWork *work);
extern int POKELIST_GetMoveLearnStatus(PokelistWork *work, void *mon, u8 bit);
extern u32 POKELIST_CheckEvolution(PokelistWork *work, void *mon, u32 param);
extern void POKELIST_PrintTextMain(PokelistWork *work, struct Descriptor *window, u32 id, int x, s16 y, u16 color);
extern void POKELIST_PrintTextSub(PokelistWork *work, struct Descriptor *window, u32 idx, u32 x, s16 y, u16 color);
extern void POKELIST_PrintTextSubDirect(PokelistWork *work, struct Descriptor *window, u32 idx, u32 x, s16 y, u16 color);
extern void POKELIST_PrintExpandedTextMain(PokelistWork *work, struct Descriptor *window, struct WordSet *wordSet, u32 idx, s16 x, s16 y, u16 color);
extern void POKELIST_PrintExpandedTextSub(PokelistWork *work, struct Descriptor *window, struct WordSet *wordSet, u32 idx, s16 x, s16 y, u16 color);
extern void POKELIST_PrintExpandedTextSubDirect(PokelistWork *work, struct Descriptor *window, struct WordSet *wordSet, u32 idx, s16 x, s16 y, u16 color);

PlistPlate *PLIST_PLATE_Create(PokelistWork *work, int slot, void *mon);
PlistPlate *PLIST_PLATE_CreateEmpty(PokelistWork *work, int slot);
void PLIST_PLATE_Delete(void *unused, PlistPlate *plate);
void PLIST_PLATE_Update(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_CreateActors(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_CreateMonIcon(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_Draw(PokelistWork *work, PlistPlate *plate, int isRefresh);
void PLIST_PLATE_DrawMonInfo(PokelistWork *work, PlistPlate *plate, int isRefresh);
void PLIST_PLATE_DrawHpBar(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_DrawEgg(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_SetSelected(PokelistWork *work, PlistPlate *plate, int selected);
void PLIST_PLATE_SetPalette(PokelistWork *work, PlistPlate *plate, int palette);
void PLIST_PLATE_SetSlideOffset(PokelistWork *work, const PlistPlate *plate, int slideX);
void PLIST_PLATE_ClearSlideTrail(PokelistWork *work, PlistPlate *plate, int slideX);
void PLIST_PLATE_SetMon(PokelistWork *work, PlistPlate *plate, void *mon, int slideX);
void PLIST_PLATE_Redraw(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_RedrawHp(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_StartHpAnim(PokelistWork *work, PlistPlate *plate);
int PLIST_PLATE_StepHpAnim(PokelistWork *work, PlistPlate *plate);
int PLIST_PLATE_IsOccupied(void *unused, PlistPlate *plate);
void PLIST_PLATE_GetCenterPos(void *unused, PlistPlate *plate, PlistPlatePos *out);
void PLIST_PLATE_GetTouchRect(PokelistWork *work, PlistPlate *plate, PlistPlateRect *out);
int PLIST_PLATE_GetLabelState(PlistPlate *plate);
void PLIST_PLATE_SetLabelState(PokelistWork *work, PlistPlate *plate, int labelState);
u16 PLIST_PLATE_GetHp(PokelistWork *work, PlistPlate *plate);
int PLIST_PLATE_IsEgg(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_UpdateLabelState(PokelistWork *work, PlistPlate *plate);
int PLIST_PLATE_CheckSelection(PokelistWork *work, PlistPlate *plate);
u8 PLIST_PLATE_GetHpBarColor(PlistPlate *plate);
void PLIST_PLATE_GetActorOffset(PlistPlate *plate, int x, int y, PlistPlatePos *out);


extern const char gPlistPlateSourceName[];
extern const u8 gPlistPlateTileX[];
extern const u8 gPlistPlateTileY[];
extern const u8 gPlistPlatePaletteA[];
extern const u8 gPlistPlatePaletteB[];
extern void *gSpeciesNameBank;

PlistPlate *PLIST_PLATE_Create(PokelistWork *work, int slot, void *mon)
{
    u8 x = gPlistPlateTileX[slot * 2];
    u8 y = gPlistPlateTileY[slot * 2];
    u8 i;
    PlistPlate *plate;
    int tileX;
    int isOther = 0;
    enum PlateKind { PLATE_KIND_LEAD, PLATE_KIND_OTHER } kind;
    PlistPlateSurface surface;
    plate = GFL_HEAP_Alloc(work->heapId, 0x44, 0, gPlistPlateSourceName, 0x9f);
    plate->slot = slot;
    plate->mon = mon;
    plate->isEmpty = 0;
    plate->selected = 0;
    plate->textPending = 0;
    plate->hp = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_HP, 0);
    plate->targetHp = plate->hp;
    if (slot != 0) isOther = 1;
    kind = slot != 0;
    tileX = x + 0x10;
    BG_SYS_DrawTileEx(2, (u8)tileX, y, 0x10, 6, (void *)((u8 *)work->paletteData + 0xc),
                 gPlistPlatePaletteA[kind * 2], gPlistPlatePaletteB[isOther * 2], 0x20, 0x20);
    plate->isEgg = POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_IS_EGG, 0);
    surface.areaLeft = 0;
    surface.areaTop = 0;
    surface.areaWidth = 0x100;
    surface.areaHeight = 0xc0;
    surface.priority = 0;
    surface.bgPriority = 0;
    plate->clactUnit = CLACT_CreateRenderer(&surface.areaLeft, 1, work->heapId);
    plate->clactBank = CLACT_CreateUnit(6, 0, work->heapId);
    CLACT_SetUnitRenderer(plate->clactBank, plate->clactUnit);
    PLIST_PLATE_CreateActors(work, plate);
    PLIST_PLATE_CreateMonIcon(work, plate);
    surface.offsetX = -x * 8;
    surface.offsetY = -y * 8;
    CLACT_SetSurfacePos(plate->clactUnit, 0, &surface);
    plate->window = BMP_WIN_Create(1, tileX, (u8)y, 0x10, 6, 0xd, 1);
    PLIST_PLATE_UpdateLabelState(work, plate);
    if (POKELIST_IsItemMode(work) == 1) {
        for (i = 0; i < 6; i++) {
            if (plate->slot + 1 == work->arg->slotOrder[i]) plate->labelState = i;
        }
    }
    PLIST_PLATE_SetSelected(work, plate, 0);
    PLIST_PLATE_Draw(work, plate, 0);
    return plate;
}

PlistPlate *PLIST_PLATE_CreateEmpty(PokelistWork *work, int slot)
{
    PlistPlate *plate = GFL_HEAP_Alloc(work->heapId, 0x44, 0, gPlistPlateSourceName, 0xea);
    u8 *palette = (u8 *)work->paletteData + 0xc;

    BG_SYS_DrawTileEx(2, (u8)(gPlistPlateTileX[slot * 2] + 0x10), gPlistPlateTileY[slot * 2], 0x10, 6,
                  (void *)palette, 0, 0x13, 0x20, 0x20);
    plate->slot = slot;
    plate->mon = 0;
    plate->isEmpty = 1;
    plate->labelState = PLIST_PLATE_LABEL_NONE;
    BG_SYS_MarkTileDirty(2);
    return plate;
}

void PLIST_PLATE_Delete(void *unused, PlistPlate *plate)
{
    if (!plate->isEmpty) {
        BMP_WIN_Delete((struct BmpWin *)plate->window);
        CLACT_DeleteActor((struct Actor *)plate->monIconActor);
        CLACT_DeleteActor((struct Actor *)plate->frameActor);
        CLACT_DeleteActor((struct Actor *)plate->hpBarActor);
        CLACT_DeleteRenderer((struct Renderer *)plate->clactUnit);
        CLACT_DeleteUnit(plate->clactBank);
        CLACT_ReleaseCharacter(plate->iconResource);
    }
    GFL_HEAP_Free(plate);
}

void PLIST_PLATE_Update(PokelistWork *work, PlistPlate *plate)
{
    PlistPlatePos offset;
    if (plate->isEmpty != 0)
        return;
    if (plate->textPending == 1) {
        void *bitmap = BMP_WIN_GetBmp((struct BmpWin *)plate->window);
        if (PRINTSYS_QUE_IsExistTarget(work->printSys, bitmap) == 0) {
            /* stand-in: the original reuses the work argument for the window pointer;
               a separate local swaps the r4 and r5 assignment. */
            work = (PokelistWork *)plate->window;
            plate->textPending = 0;
            BMP_WIN_TransferChars((struct BmpWin *)work);
            BMP_WIN_MakeScreen((struct BmpWin *)work);
            BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)work));
        }
    }
    if (plate->selected == 1 && POKE_TOOL_GetStatusCondition(plate->mon) == 0 && plate->hp != 0) {
        PLIST_PLATE_GetActorOffset(plate, 0x1a, 0x13, &offset);
        if (CLACT_GetActorAnimFrame((struct Actor *)plate->monIconActor) == 1)
            offset.y = offset.y - 6;
        CLACT_AddActorSurfacePos(plate->monIconActor, &offset, 0);
    }
}

void PLIST_PLATE_CreateActors(PokelistWork *work, PlistPlate *plate)
{
    PlistPlateActorSpec frameSpec;
    PlistPlateActorSpec hpBarSpec;
    PlistPlateActorSpec itemSpec;
    PlistPlateActorSpec statusSpec;
    struct Obj *actor;
    frameSpec.x = 16;
    frameSpec.y = 16;
    frameSpec.depth = 0;
    frameSpec.animation = 1;
    frameSpec.bgPriority = 2;
    actor = CLACT_CreateActor(plate->clactBank, work->palRes[1], work->charRes[0], work->cellRes[1], &frameSpec, 0, work->heapId);
    plate->frameActor = actor;
    CLACT_SetActorAutoAnim((struct Actor *)actor, 1);
    hpBarSpec.x = 0x54;
    hpBarSpec.y = 0x1c;
    hpBarSpec.depth = 0;
    hpBarSpec.animation = 0;
    hpBarSpec.bgPriority = 2;
    plate->hpBarActor = CLACT_CreateActor(plate->clactBank, work->palRes[6], work->charRes[5], work->cellRes[6], &hpBarSpec, 0, work->heapId);
    itemSpec.x = 32;
    itemSpec.y = 24;
    itemSpec.depth = 0;
    itemSpec.animation = 0;
    itemSpec.bgPriority = 2;
    actor = CLACT_CreateActor(plate->clactBank, work->palRes[3], work->charRes[2], work->cellRes[3], &itemSpec, 0, work->heapId);
    plate->itemIconActor = actor;
    CLACT_SetActorDrawEnable((struct Actor *)actor, 0);
    statusSpec.x = 32;
    statusSpec.y = 42;
    statusSpec.depth = 0;
    statusSpec.animation = 0;
    statusSpec.bgPriority = 2;
    actor = CLACT_CreateActor(plate->clactBank, work->palRes[5], work->charRes[4], work->cellRes[5], &statusSpec, 0, work->heapId);
    plate->statusIconActor = actor;
    CLACT_SetActorDrawEnable((struct Actor *)actor, 0);
}

void PLIST_PLATE_CreateMonIcon(PokelistWork *work, PlistPlate *plate)
{
    void *iconFile;
    void *boxMon;
    int palette;
    PlistPlateActorSpec spec;
    iconFile = ARC_TOOL_CreateHandle(7, work->heapId);
    boxMon = POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(work->arg->party, plate->slot));
    plate->iconResource = CLACT_RegisterCharacter(iconFile, POKE_TOOL_GetGraphicIndex(boxMon), 0, 0, work->heapId);
    ARC_TOOL_DeleteHandle(iconFile);
    palette = POKE_TOOL_GetIconPalette(boxMon);
    spec.x = 0x18;
    spec.y = 0x10;
    spec.depth = 1;
    spec.animation = 0;
    spec.bgPriority = 2;
    {
        struct Obj *actor = CLACT_CreateActor(plate->clactBank, plate->iconResource, work->charRes[6],
                                          work->cellRes[7], &spec, 0, work->heapId);
        plate->monIconActor = actor;
        CLACT_SetActorPaletteOffset((struct Actor *)actor, palette, 1);
    }
    CLACT_SetActorAutoAnim((struct Actor *)plate->monIconActor, 1);
}

void PLIST_PLATE_Draw(PokelistWork *work, PlistPlate *plate, int isRefresh)
{
    if (plate->isEgg == 0) {
        PLIST_PLATE_DrawMonInfo(work, plate, isRefresh);
        PLIST_PLATE_DrawHpBar(work, plate);
    } else
        PLIST_PLATE_DrawEgg(work, plate);
}

void PLIST_PLATE_DrawMonInfo(PokelistWork *work, PlistPlate *plate, int isRefresh)
{
    int isTeachMode = 0;
    struct WordSet *wordSet;
    struct WordSet *wordSetB;
    struct WordSet *wordSetC;
    u32 msgId;
    u32 label;
    u32 heldItem;
    u32 hpBarColor;
    u32 value;
    u16 iconAnim;
    PokelistArg *arg;
    if (work->arg->mode == PLIST_PLATE_MODE_BATTLE_ORDER || work->restoreMode18 == 1) {
        isTeachMode = 1;
    }
    if (isRefresh == 0) {
        wordSet = WORDSET_CreateDefault(work->heapId);
        WORDSET_SetSlotMonNickname(wordSet, 0, plate->mon);
        POKELIST_PrintExpandedTextMain(work, plate->window, wordSet, 3, 0x29, 9, 0x440);
        WORDSET_Delete(wordSet);
    }
    if (isRefresh == 0) {
        if (POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_NICKNAME_NOT_DEFAULT_NIDORAN, 0) == 1) {
            value = POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_GENDER, 0);
            if (value == 0) {
                POKELIST_PrintTextMain(work, plate->window, PLIST_PLATE_MSG_GENDER_MALE, 0x69, 9, 0x14c0);
            } else if (value == 1) {
                POKELIST_PrintTextMain(work, plate->window, PLIST_PLATE_MSG_GENDER_FEMALE, 0x69, 9, 0xc80);
            }
        }
    }
    if (isTeachMode == 0) {
        if ((POKE_TOOL_GetStatusCondition(plate->mon) == 0 && plate->hp != 0) || plate->labelState != PLIST_PLATE_LABEL_NONE) {
            wordSetB = WORDSET_CreateDefault(work->heapId);
            WORDSET_SetSlotNumber(wordSetB, 0, POKE_TOOL_CalcLevel(plate->mon), 3, 0, 1);
            if (isRefresh == 0) {
                POKELIST_PrintExpandedTextSub(work, plate->window, wordSetB, 2, 9, 0x23, 0x440);
            } else {
                POKELIST_PrintExpandedTextSubDirect(work, plate->window, wordSetB, 2, 9, 0x23, 0x440);
            }
            WORDSET_Delete(wordSetB);
            CLACT_SetActorDrawEnable((struct Actor *)plate->statusIconActor, 0);
        } else {
            if (plate->hp == 0) {
                CLACT_SetActorAnimSeq((struct Actor *)plate->statusIconActor, 6);
            } else {
                switch (POKE_TOOL_GetStatusCondition(plate->mon)) {
                case 1: CLACT_SetActorAnimSeq((struct Actor *)plate->statusIconActor, 1); break;
                case 2: CLACT_SetActorAnimSeq((struct Actor *)plate->statusIconActor, 3); break;
                case 3: CLACT_SetActorAnimSeq((struct Actor *)plate->statusIconActor, 2); break;
                case 4: CLACT_SetActorAnimSeq((struct Actor *)plate->statusIconActor, 5); break;
                case 5: CLACT_SetActorAnimSeq((struct Actor *)plate->statusIconActor, 4); break;
                }
            }
            CLACT_SetActorDrawEnable((struct Actor *)plate->statusIconActor, 1);
        }
    }
    label = plate->labelState;
    if (label != PLIST_PLATE_LABEL_NONE) {
        if (label == PLIST_PLATE_LABEL_NOT_ELIGIBLE) {
            label = PLIST_PLATE_MSG_NOT_ELIGIBLE;
        } else if (label == PLIST_PLATE_LABEL_ELIGIBLE) {
            label = PLIST_PLATE_MSG_ELIGIBLE;
        } else {
            label = label + PLIST_PLATE_MSG_ORDER_FIRST;
        }
        POKELIST_PrintTextMain(work, plate->window, (u16)label, 0x2e, 0x1f, 0x440);
        CLACT_SetActorDrawEnable((struct Actor *)plate->hpBarActor, 0);
    } else if (isTeachMode == 1) {
        switch (POKELIST_GetMoveLearnStatus(work, plate->mon, plate->slot)) {
        case 0:
        case 1: msgId = PLIST_PLATE_MSG_TEACH_ABLE; break;
        case 2: msgId = PLIST_PLATE_MSG_TEACH_KNOWN; break;
        case 3: msgId = PLIST_PLATE_MSG_TEACH_NOT_ABLE; break;
        }
        POKELIST_PrintTextMain(work, plate->window, (u16)msgId, 0x1d, 0x1f, 0x440);
        CLACT_SetActorDrawEnable((struct Actor *)plate->hpBarActor, 0);
    } else {
        arg = work->arg;
        if (arg->mode == PLIST_PLATE_MODE_EVOLVE_ITEM) {
            value = POKELIST_CheckEvolution(work, plate->mon, arg->itemId);
            label = PLIST_PLATE_MSG_EVOLVE_NOT_ABLE;
            if (value != 0) {
                label = PLIST_PLATE_MSG_EVOLVE_ABLE;
            }
            POKELIST_PrintTextMain(work, plate->window, (u16)label, 0x2e, 0x1f, 0x440);
            CLACT_SetActorDrawEnable((struct Actor *)plate->hpBarActor, 0);
        } else {
            wordSetB = WORDSET_CreateDefault(work->heapId);
            WORDSET_SetSlotNumber(wordSetB, 0, POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_MAX_HP, 0), 3, 0, 1);
            if (isRefresh == 0) {
                POKELIST_PrintExpandedTextSub(work, plate->window, wordSetB, 4, 0x5b, 0x23, 0x440);
            } else {
                POKELIST_PrintExpandedTextSubDirect(work, plate->window, wordSetB, 4, 0x5b, 0x23, 0x440);
            }
            WORDSET_Delete(wordSetB);
            wordSetC = WORDSET_CreateDefault(work->heapId);
            WORDSET_SetSlotNumber(wordSetC, 0, plate->hp, 3, 1, 1);
            if (isRefresh == 0) {
                POKELIST_PrintExpandedTextSub(work, plate->window, wordSetC, 5, 0x39, 0x23, 0x440);
            } else {
                POKELIST_PrintExpandedTextSubDirect(work, plate->window, wordSetC, 5, 0x39, 0x23, 0x440);
            }
            WORDSET_Delete(wordSetC);
            if (isRefresh == 0) {
                POKELIST_PrintTextSub(work, plate->window, 6, 0x52, 0x23, 0x440);
            } else {
                POKELIST_PrintTextSubDirect(work, plate->window, 6, 0x52, 0x23, 0x440);
            }
        }
    }
    heldItem = POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_HELD_ITEM, 0);
    if (heldItem != 0) {
        CLACT_SetActorDrawEnable((struct Actor *)plate->itemIconActor, 1);
        if (FILE_UTIL_IsMailItem(heldItem) == 1) {
            CLACT_SetActorAnimSeq((struct Actor *)plate->itemIconActor, 1);
        } else {
            CLACT_SetActorAnimSeq((struct Actor *)plate->itemIconActor, 0);
        }
    } else {
        CLACT_SetActorDrawEnable((struct Actor *)plate->itemIconActor, 0);
    }
    hpBarColor = PLIST_PLATE_GetHpBarColor(plate);
    iconAnim = 1;
    if (hpBarColor == PLIST_PLATE_HPBAR_FULL) {
        iconAnim = 0;
    } else if (POKE_TOOL_GetStatusCondition(plate->mon) != 0) {
        iconAnim = 5;
    } else if (hpBarColor == PLIST_PLATE_HPBAR_GREEN) {
        iconAnim = 4;
    } else if (hpBarColor == PLIST_PLATE_HPBAR_YELLOW) {
        iconAnim = 3;
    } else if (hpBarColor == PLIST_PLATE_HPBAR_RED) {
        iconAnim = 2;
    }
    CLACT_SetActorAnimSeq((struct Actor *)plate->monIconActor, iconAnim);
    plate->textPending = 1;
}

void PLIST_PLATE_DrawHpBar(PokelistWork *work, PlistPlate *plate)
{
    u8 hpBarColor;
    int paletteA;
    int paletteB;
    int filledDots;
    struct Bmp *bitmap;
    if (POKELIST_IsItemMode(work) != 0)
        return;
    if (work->arg->mode == PLIST_PLATE_MODE_BATTLE_ORDER)
        return;
    hpBarColor = PLIST_PLATE_GetHpBarColor(plate);
    filledDots = BGWINFRM_ScaleRatio(plate->hp, POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_MAX_HP, 0), 0x30);
    bitmap = BMP_WIN_GetBmp((struct BmpWin *)plate->window);
    if (hpBarColor == PLIST_PLATE_HPBAR_GREEN || hpBarColor == PLIST_PLATE_HPBAR_FULL) {
        paletteA = 0xe;
        paletteB = 0xf;
    } else if (hpBarColor == PLIST_PLATE_HPBAR_YELLOW) {
        paletteA = 0xc;
        paletteB = 0xd;
    } else {
        paletteA = 0xa;
        paletteB = 0xb;
    }
    BMP_FillRect(bitmap, 0x3d, 0x1b, filledDots, 1, paletteA);
    BMP_FillRect(bitmap, 0x3d, 0x1c, filledDots, 1, paletteB);
    CLACT_SetActorDrawEnable((struct Actor *)plate->hpBarActor, 1);
}

void PLIST_PLATE_DrawEgg(PokelistWork *work, PlistPlate *plate)
{
    struct WordSet *wordSet;
    void *eggText;
    wordSet = WORDSET_CreateDefault(work->heapId);
    eggText = MSGDATA_AllocString(gSpeciesNameBank, PLIST_PLATE_MSG_EGG);
    WORDSET_SetSlotTag(wordSet, 0, eggText, 0, 1, 2);
    POKELIST_PrintExpandedTextMain(work, plate->window, wordSet, 3, 0x29, 9, 0x440);
    STRBUF_Delete(eggText);
    WORDSET_Delete(wordSet);
    CLACT_SetActorDrawEnable((struct Actor *)plate->hpBarActor, 0);
    CLACT_SetActorAnimSeq((struct Actor *)plate->monIconActor, 1);
    plate->textPending = 1;
}

static inline PlistPlatePos *getActorOffset(PlistPlate *plate, int x, int y, PlistPlatePos *buf)
{
    PLIST_PLATE_GetActorOffset(plate, x, y, buf);
    return buf;
}

void PLIST_PLATE_SetSelected(PokelistWork *work, PlistPlate *plate, int selected)
{
    PlistPlatePos selectedOffset;
    PlistPlatePos normalOffset;
    PlistPlatePos *offset;
    if (selected == 1) {
        if (work->phase == PLIST_PLATE_PHASE_SWAP || work->phase == PLIST_PLATE_PHASE_HEAL)
            PLIST_PLATE_SetPalette(work, plate, 8);
        else if (POKELIST_IsItemMode(work) == 1 && plate->labelState < 6)
            PLIST_PLATE_SetPalette(work, plate, 8);
        else
            PLIST_PLATE_SetPalette(work, plate, 6);
        CLACT_SetActorAnimSeq((struct Actor *)plate->frameActor, 1);
        offset = getActorOffset(plate, 0x1a, 0x13, &selectedOffset);
    } else {
        if ((work->phase == PLIST_PLATE_PHASE_SWAP && work->swapSourceSlot == plate->slot) ||
            (work->phase == PLIST_PLATE_PHASE_HEAL && work->healSourceSlot == plate->slot))
            PLIST_PLATE_SetPalette(work, plate, 5);
        else if (POKELIST_IsItemMode(work) == 1 && plate->labelState < 6)
            PLIST_PLATE_SetPalette(work, plate, 5);
        else
            PLIST_PLATE_SetPalette(work, plate, 3);
        CLACT_SetActorAnimSeq((struct Actor *)plate->frameActor, 0);
        offset = getActorOffset(plate, 0x18, 0x10, &normalOffset);
    }
    CLACT_AddActorSurfacePos(plate->monIconActor, offset, 0);
    plate->selected = selected;
}

void PLIST_PLATE_SetPalette(PokelistWork *work, PlistPlate *plate, int palette)
{
    if (palette == 3 && PLIST_PLATE_GetHpBarColor(plate) == PLIST_PLATE_HPBAR_FULL)
        BG_SYS_FillTileMap(2, gPlistPlateTileX[plate->slot * 2] + 0x10, gPlistPlateTileY[plate->slot * 2], 0x10, 6, 4);
    else if (palette == 6 && PLIST_PLATE_GetHpBarColor(plate) == PLIST_PLATE_HPBAR_FULL)
        BG_SYS_FillTileMap(2, gPlistPlateTileX[plate->slot * 2] + 0x10, gPlistPlateTileY[plate->slot * 2], 0x10, 6, 7);
    else
        BG_SYS_FillTileMap(2, gPlistPlateTileX[plate->slot * 2] + 0x10, gPlistPlateTileY[plate->slot * 2], 0x10, 6, palette);
    BG_SYS_MarkTileDirty(2);
}

void PLIST_PLATE_SetSlideOffset(PokelistWork *work, const PlistPlate *plate, int slideX)
{
    int slot = plate->slot;
    int x = gPlistPlateTileX[slot * 2];
    u8 y = gPlistPlateTileY[slot * 2];
    PlistPlatePos pos;
    int isOther;
    enum PlateKind { PLATE_KIND_LEAD, PLATE_KIND_OTHER } kind;
    if (slot % 2 == 0) slideX = -slideX;
    BMP_WIN_SetPosX((struct BmpWin *)plate->window, slideX + (x + 16));
    pos.x = -(x + slideX) * 8;
    pos.y = -y * 8;
    CLACT_SetSurfacePos(plate->clactUnit, 0, &pos);
    isOther = 0;
    if (plate->slot != 0) isOther = 1;
    kind = plate->slot != 0;
    x += 16;
    slideX = (unsigned)x + slideX;
    BG_SYS_DrawTileEx(2, (u8)slideX, y, 16, 6, (void *)((u8 *)work->paletteData + 12), gPlistPlatePaletteA[kind * 2], gPlistPlatePaletteB[isOther * 2], 32, 32);
    BG_SYS_FillTileMap(2, slideX, y, 16, 6, 5);
    BMP_WIN_MakeScreen((struct BmpWin *)plate->window);
    BG_SYS_MarkTileDirty(1);
    BG_SYS_MarkTileDirty(2);
}

void PLIST_PLATE_ClearSlideTrail(PokelistWork *work, PlistPlate *plate, int slideX)
{
    int slot = plate->slot;
    int x = gPlistPlateTileX[slot * 2];
    u8 y = gPlistPlateTileY[slot * 2];
    int left;
    if (slot % 2 == 0)
        slideX = -slideX;
    left = x + 0x10 + slideX;
    BG_SYS_SetTileEntry(2, 0, left, y, 0x10, 6, 5);
    BG_SYS_SetTileEntry(1, 0, left, y, 0x10, 6, 5);
}

void PLIST_PLATE_SetMon(PokelistWork *work, PlistPlate *plate, void *mon, int slideX)
{
    PlistPlatePos pos[2];
    int slot = plate->slot;
    int x = gPlistPlateTileX[slot * 2];
    int y = gPlistPlateTileY[slot * 2];
    if (slot % 2 == 0)
        slideX = -slideX;
    plate->mon = mon;
    plate->textPending = 0;
    plate->isEgg = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_IS_EGG, 0);
    plate->hp = POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_HP, 0);
    plate->targetHp = plate->hp;
    CLACT_DeleteActor((struct Actor *)plate->monIconActor);
    CLACT_ReleaseCharacter(plate->iconResource);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)plate->window), 0);
    CLACT_SetActorDrawEnable((struct Actor *)plate->itemIconActor, 0);
    CLACT_SetActorDrawEnable((struct Actor *)plate->statusIconActor, 0);
    pos[1].x = 0;
    pos[1].y = 0;
    CLACT_SetSurfacePos(plate->clactUnit, 0, &pos[1]);
    PLIST_PLATE_CreateMonIcon(work, plate);
    pos[0].x = -(x + slideX) * 8;
    pos[0].y = -y * 8;
    CLACT_SetSurfacePos(plate->clactUnit, 0, pos);
    PLIST_PLATE_Draw(work, plate, 0);
}

void PLIST_PLATE_Redraw(PokelistWork *work, PlistPlate *plate)
{
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)plate->window), 0);
    PLIST_PLATE_Draw(work, plate, 0);
}

void PLIST_PLATE_RedrawHp(PokelistWork *work, PlistPlate *plate)
{
    BMP_FillRect(BMP_WIN_GetBmp((struct BmpWin *)plate->window), 0, 26, 128, 22, 0);
    PLIST_PLATE_Draw(work, plate, 1);
}

void PLIST_PLATE_StartHpAnim(PokelistWork *work, PlistPlate *plate)
{
    plate->targetHp = POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_HP, 0);
    work->hpStep = (plate->targetHp - plate->hp) / 100;
    if (plate->targetHp > plate->hp)
        work->hpStep = work->hpStep + 1;
    else
        work->hpStep = work->hpStep - 1;
}

int PLIST_PLATE_StepHpAnim(PokelistWork *work, PlistPlate *plate)
{
    if (plate->hp < plate->targetHp) {
        if (plate->hp == 0) {
            PLIST_PLATE_SetPalette(work, plate, 6);
        }
        {
            u16 current = plate->hp;
            signed char step = work->hpStep;
            u16 limit = plate->targetHp;
            if (current + step > limit) {
                plate->hp = limit;
            } else {
                plate->hp = current + (u16)step;
            }
        }
        PLIST_PLATE_RedrawHp(work, plate);
        return 0;
    }
    if (plate->hp > plate->targetHp) {
        signed char step = work->hpStep;
        if (plate->hp + step < plate->targetHp) {
            plate->hp = plate->targetHp;
        } else {
            plate->hp = plate->hp + (u16)step;
        }
        PLIST_PLATE_RedrawHp(work, plate);
        return 0;
    }
    return 1;
}

int PLIST_PLATE_IsOccupied(void *unused, PlistPlate *plate)
{
    if (plate->isEmpty != 1) return 1;
    return 0;
}

void PLIST_PLATE_GetCenterPos(void *unused, PlistPlate *plate, PlistPlatePos *out)
{
    out->x = (gPlistPlateTileX[plate->slot * 2] + 8) << 3;
    out->y = (gPlistPlateTileY[plate->slot * 2] + 3) << 3;
}

void PLIST_PLATE_GetTouchRect(PokelistWork *work, PlistPlate *plate, PlistPlateRect *out)
{
    out->left = gPlistPlateTileX[plate->slot * 2] << 3;
    out->top = gPlistPlateTileY[plate->slot * 2] << 3;
    out->right = (gPlistPlateTileX[plate->slot * 2] + 16) << 3;
    out->bottom = (gPlistPlateTileY[plate->slot * 2] + 6) << 3;
}

int PLIST_PLATE_GetLabelState(PlistPlate *plate)
{
    return plate->labelState;
}

void PLIST_PLATE_SetLabelState(PokelistWork *work, PlistPlate *plate, int labelState)
{
    if (plate->labelState != labelState) {
        if (labelState < 6) {
            plate->labelState = labelState;
        } else {
            PLIST_PLATE_UpdateLabelState(work, plate);
        }
        PLIST_PLATE_Redraw(work, plate);
    }
}

u16 PLIST_PLATE_GetHp(PokelistWork *work, PlistPlate *plate)
{
    return plate->hp;
}

int PLIST_PLATE_IsEgg(PokelistWork *work, PlistPlate *plate)
{
    return plate->isEgg;
}

void PLIST_PLATE_UpdateLabelState(PokelistWork *work, PlistPlate *plate)
{
    if (POKELIST_IsItemMode(work) == 0) {
        plate->labelState = PLIST_PLATE_LABEL_NONE;
        return;
    }
    if (POKE_REGULATION_CheckPokemon((struct Regulation *)work->arg->regulation, plate->mon) == 0) {
        plate->labelState = PLIST_PLATE_LABEL_NOT_ELIGIBLE;
        return;
    }
    plate->labelState = PLIST_PLATE_LABEL_ELIGIBLE;
}

int PLIST_PLATE_CheckSelection(PokelistWork *work, PlistPlate *plate)
{
    int species;
    int heldItem;
    PokelistRegulation *rules;
    u8 i;
    if (plate->labelState != PLIST_PLATE_LABEL_NOT_ELIGIBLE) {
        return 1;
    }
    i = 0;
    species = POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_SPECIES, 0);
    heldItem = POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_HELD_ITEM, 0);
    rules = work->arg->regulation;
    do {
        u8 order;
        order = work->arg->slotOrder[i];
        if (order >= 1) {
            void *other = (work->plates[order - 1])->mon;
            int otherSpecies = POKE_TOOL_GetPartyValue(other, POKE_TOOL_PARAM_SPECIES, 0);
            int otherItem = POKE_TOOL_GetPartyValue(other, POKE_TOOL_PARAM_HELD_ITEM, 0);
            if (species == otherSpecies && rules->allowSameSpecies == 0) {
                return 2;
            }
            if (heldItem == otherItem && heldItem != 0 && rules->allowSameItem == 0) {
                return 3;
            }
        }
        i = i + 1;
    } while (i < 6);
    if (work->selectedCount == rules->maxPartySize) {
        return 4;
    }
    return 0;
}

u8 PLIST_PLATE_GetHpBarColor(PlistPlate *plate)
{
    return BGWINFRM_GetScaleRank(plate->hp, POKE_TOOL_GetPartyValue(plate->mon, POKE_TOOL_PARAM_MAX_HP, 0));
}

void PLIST_PLATE_GetActorOffset(PlistPlate *plate, int x, int y, PlistPlatePos *out)
{
    PlistPlatePos surfacePos;
    CLACT_GetSurfacePos(plate->clactUnit, 0, &surfacePos);
    out->x = x - surfacePos.x;
    out->y = y - surfacePos.y;
}
