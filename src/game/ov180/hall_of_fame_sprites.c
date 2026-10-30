/*
 * file:     hall_of_fame_sprites.c
 * unit:     yes
 * function: HALL_OF_FAME_LoadUiPalette, HALL_OF_FAME_DeleteTextPlate, HALL_OF_FAME_DeleteAllTextPlates, HALL_OF_FAME_PrintToPlate, HALL_OF_FAME_CreateMonPlates, HALL_OF_FAME_PrintMonInfo, HALL_OF_FAME_CreateTrainerPlates, HALL_OF_FAME_UpdatePlatePositions, HALL_OF_FAME_SetPlateEnabled, HALL_OF_FAME_LoadUiResources, HALL_OF_FAME_CreateMonSceneObjects, HALL_OF_FAME_DeleteMonSceneObjects, HALL_OF_FAME_DrawMonScene, HALL_OF_FAME_CreateTrainerSceneObjects, HALL_OF_FAME_DeleteTrainerSceneObjects, HALL_OF_FAME_DrawTrainerScene, HALL_OF_FAME_SpawnSparkles
 * address:  0x021B7750
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   gHallOfFameTrainerPaletteIds 0x021B82D4 data a4
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_Create 0x02043678 arm
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   WORDSET_SetSlotMonNicknameAlt 0x0201EF14 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   MYSTATUS_GetIdLow16 0x02008534 thumb
 *   PLAYTIME_GetHours 0x0200864C thumb
 *   PLAYTIME_GetMinutes 0x02008650 thumb
 *   HALL_OF_FAME_GetActorPos 0x021B7408 thumb ov180
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   HALL_OF_FAME_CreateActorFromTemplate 0x021B75A4 thumb ov180
 *   HALL_OF_FAME_SetActorVisible 0x021B746C thumb ov180
 *   gHallOfFamePlateLeftTemplate 0x021B81BC data a4
 *   gHallOfFamePlateRightTemplate 0x021B81D4 data a4
 *   gHallOfFameVoiceMarkTemplate 0x021B81A4 data a4
 *   HALL_OF_FAME_DeleteAllActors  0x021B7604  thumb  ov180
 *   HALL_OF_FAME_ReleaseAllResources  0x021B756C  thumb  ov180
 *   DOUBLE3DDISP_GetMode 0x0204EA38 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   HALL_OF_FAME_UpdateActors 0x021B73B0 thumb ov180
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetRendererCulling 0x0204B0F4 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   POKEGRA_OpenTrainerHandle 0x0202DA04 thumb
 *   POKEGRA_RegisterTrainerCgr 0x0202DA48 thumb
 *   POKEGRA_RegisterTrainerPalette 0x0202DA18 thumb
 *   POKEGRA_RegisterTrainerCellAnim 0x0202DA6C thumb
 *   gHallOfFameRendererSetup 0x021B82B4 data a4
 *   gHallOfFameRingTopTemplate 0x021B8204 data a4
 *   gHallOfFameRingBottomTemplate 0x021B81EC data a4
 *   gHallOfFameTrainerTopTemplate 0x021B824C data a4
 *   gHallOfFameTrainerBottomTemplate 0x021B8264 data a4
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   HALL_OF_FAME_IsActorAnimActive  0x021B74B4  thumb ov180
 *   HALL_OF_FAME_DeleteActor  0x021B75E8  thumb ov180
 *   HALL_OF_FAME_PlayActorAnim  0x021B7488  thumb ov180
 *   gHallOfFameSparkleTemplateA  0x021B821C  data  a4
 *   gHallOfFameSparkleTemplateB  0x021B8234  data  ov180
 */
#include "hall_of_fame.h"

struct Grid;
struct Bmp;
struct Sys;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct BmpOamParam;
struct Sav;
struct WordSet;
struct StrObj;
struct Player;
struct PlayTime;
struct Sub0200852CObj;
struct Actor;
struct Bank;

#include "../types.h"

/* Setup block of the actor renderer (32 bytes). */
typedef struct HofRendererSetup {
    u32 words[8];
} HofRendererSetup;

#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
struct PaletteData;
#include "../arm9/clact.h"
#include "../arm9/gfl_heap_wrap.h"
struct BmpOam;
#include "../arm9/bmp_oam.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
struct GfFont;
struct Strbuf;
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define PRINTSYS_PrintColor PRINTSYS_PrintColor_header
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintColor
extern void PRINTSYS_PrintColor(struct Bmp *, short, s16, struct Strbuf *, struct GfFont *, u16);
#endif
struct BmpOamParam;
struct BmpOamSys;
#include "../arm9/msgdata.h"
#include "../arm9/strbuf.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
struct BoxPokemon;
#include "../arm9/wordset.h"
struct MyStatus;
#include "../arm9/mystatus.h"
#include "../arm9/playtime.h"
#include "../arm9/double3Ddisp.h"
#include "../arm9/bg_sys.h"
#include "../arm9/gfl_use.h"
struct SurfaceInit;
struct Renderer;
#include "../arm9/pokegra.h"
#include "../version.h"
extern unsigned gHallOfFameTrainerPaletteIds[];
extern const HallOfFameActorTemplate gHallOfFamePlateLeftTemplate, gHallOfFamePlateRightTemplate, gHallOfFameVoiceMarkTemplate;
extern const HofRendererSetup gHallOfFameRendererSetup;
extern const HallOfFameActorTemplate gHallOfFameRingBottomTemplate, gHallOfFameRingTopTemplate, gHallOfFameTrainerTopTemplate, gHallOfFameTrainerBottomTemplate;
extern const HallOfFameActorTemplate gHallOfFameSparkleTemplateA;
extern const HallOfFameActorTemplate gHallOfFameSparkleTemplateB;

void HALL_OF_FAME_LoadUiPalette(HallOfFameWork *work)
{
    void *palette;
    unsigned char *bank;
    void *buffer;
    bank = ARC_TOOL_CreateHandle(216, 0x808d);
    buffer = ARC_UTIL_LoadPaletteBlockFromHandle((void *)bank, gHallOfFameTrainerPaletteIds[work->effectStyle], &palette, HOF_HEAP_ID);
    CLACT_TransferPalette(work->paletteIds[2], palette, 1);
    GFL_HEAP_Free(buffer);
    ARC_TOOL_DeleteHandle(bank);
}

void HALL_OF_FAME_DeleteTextPlate(HallOfFameWork *work, int plate)
{
    if (work->plates[plate].oam) {
        BMP_OAM_Delete(work->plates[plate].oam);
        BMP_Delete(work->plates[plate].bmp);
        work->plates[plate].oam = 0;
    }
}

void HALL_OF_FAME_DeleteAllTextPlates(HallOfFameWork *work)
{
    unsigned int i;
    for (i = 0; i < HOF_TEXT_PLATE_COUNT; i++)
        HALL_OF_FAME_DeleteTextPlate(work, i);
}

/*
 * Add the far offset before the index; see the far-offset-before-the-index idiom.
 */
void HALL_OF_FAME_PrintToPlate(HallOfFameWork *work, int plate, void *font, void *str, int x, int y)
{
    PRINTSYS_PrintColor(work->plates[plate].bmp, x, y, str, font, 0x3c40);
    BMP_OAM_UploadChars(work->plates[plate].oam);
}

/*
 * lever: paired Grid/Bmp holder pointer formed before allocation preserves
 *   the destination across the call; direct raw stores were eight bytes short.
 */
void HALL_OF_FAME_CreateMonPlates(HallOfFameWork *work)
{
    HallOfFameOamParam param;
    struct U16Vec *str;
    HallOfFameTextPlate *plate;
    param.palette = work->paletteIds[3];
    param.reserved0C = 0;
    param.priority = 4;
    param.reserved11 = 0;
    param.tag = 0xffff;
    param.reserved14 = 0;
    plate = &work->plates[0];
    plate->bmp = BMP_Create(22, 2, 32, HOF_HEAP_ID);
    param.bmp = plate->bmp;
    param.x = -184;
    param.y = 16;
    work->plates[0].oam = BMP_OAM_Create(work->oamSys, (struct BmpOamParam *)&param);
    BMP_Clear(work->plates[0].bmp, 0);
    str = (struct U16Vec *)MSGDATA_AllocString(work->msgData, 0);
    HALL_OF_FAME_PrintToPlate(work, 0, work->fontMain, str, 12, 0);
    STRBUF_Delete((struct Strbuf *)str);
    plate = &work->plates[1];
    plate->bmp = BMP_Create(22, 2, 32, HOF_HEAP_ID);
    param.bmp = plate->bmp;
    param.x = 264;
    param.y = 160;
    work->plates[1].oam = BMP_OAM_Create(work->oamSys, (struct BmpOamParam *)&param);
}

void HALL_OF_FAME_PrintMonInfo(HallOfFameWork *work)
{
    struct Sav *mon;
    u32 lock, width;
    struct StrObj *str;
    mon = (struct Sav *)POKE_TOOL_CastToBoxParam(work->partyMons[work->monIndex]);
    lock = POKE_TOOL_DecodeBoxParam((struct BoxPokemon *)mon);
    BMP_Clear(work->plates[1].bmp, 0);
    str = (struct StrObj *)MSGDATA_AllocString(work->msgData, 1);
    WORDSET_SetSlotMonNicknameAlt(work->wordSet, 0, mon);
    WORDSET_CopyTaggedText(work->wordSet, (struct Strbuf *)work->strBuf, (struct Strbuf *)str);
    HALL_OF_FAME_PrintToPlate(work, 1, work->fontMain, work->strBuf, 8, 0);
    STRBUF_Delete((struct Strbuf *)str);
    str = (struct StrObj *)MSGDATA_AllocString(work->msgData, 2);
    width = PRINTSYS_MeasureWidestLine((struct Strbuf *)str, work->fontMain, 0);
    HALL_OF_FAME_PrintToPlate(work, 1, work->fontMain, str, 112, 0);
    STRBUF_Delete((struct Strbuf *)str);
    str = (struct StrObj *)MSGDATA_AllocString(work->msgData, 3);
    WORDSET_SetSlotNumber(work->wordSet, 0, POKE_TOOL_GetBoxValue((struct BoxPokemon *)mon, 158, 0), 3, 0, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText(work->wordSet, (struct Strbuf *)work->strBuf, (struct Strbuf *)str);
    HALL_OF_FAME_PrintToPlate(work, 1, work->fontMain, work->strBuf, width + 112, 0);
    STRBUF_Delete((struct Strbuf *)str);
    POKE_TOOL_EncodeBoxParam((struct BoxPokemon *)mon, lock);
}

void HALL_OF_FAME_CreateTrainerPlates(HallOfFameWork *work)
{
    HallOfFameOamParam param;
    HallOfFameTextPlate *plate;
    struct StrObj *str;
    u32 width;
    param.palette = work->paletteIds[3];
    param.reserved0C = 0;
    param.priority = 4;
    param.reserved11 = 0;
    param.tag = 0xffff;
    plate = &work->plates[2];
    param.reserved14 = 0;
    plate->bmp = BMP_Create(32, 2, 32, HOF_HEAP_ID);
    param.bmp = plate->bmp;
    param.x = 0;
    param.y = 16;
    work->plates[2].oam = BMP_OAM_Create(work->oamSys, (struct BmpOamParam *)&param);
    BMP_OAM_SetEnabled(work->plates[2].oam, 0);
    BMP_Clear(work->plates[2].bmp, 0);
    str = (struct StrObj *)MSGDATA_AllocString(work->msgData, 4);
    width = PRINTSYS_MeasureWidestLine((struct Strbuf *)str, work->fontMain, 0);
    HALL_OF_FAME_PrintToPlate(work, 2, work->fontMain, str, (256 - width) / 2, 0);
    STRBUF_Delete((struct Strbuf *)str);
    plate = &work->plates[3];
    plate->bmp = BMP_Create(32, 2, 32, HOF_HEAP_ID);
    param.bmp = plate->bmp;
    param.x = 0;
    param.y = 160;
    work->plates[3].oam = BMP_OAM_Create(work->oamSys, (struct BmpOamParam *)&param);
    BMP_OAM_SetEnabled(work->plates[3].oam, 0);
    BMP_Clear(work->plates[3].bmp, 0);
    str = (struct StrObj *)MSGDATA_AllocString(work->msgData, 5);
    WORDSET_SetSlotMyStatus(work->wordSet, 0, work->args->myStatus);
    WORDSET_CopyTaggedText(work->wordSet, (struct Strbuf *)work->strBuf, (struct Strbuf *)str);
    HALL_OF_FAME_PrintToPlate(work, 3, work->fontMain, work->strBuf, 8, 0);
    STRBUF_Delete((struct Strbuf *)str);
    str = (struct StrObj *)MSGDATA_AllocString(work->msgData, 6);
    WORDSET_SetSlotNumber(work->wordSet, 0, MYSTATUS_GetIdLow16(work->args->myStatus), 5, 2, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText(work->wordSet, (struct Strbuf *)work->strBuf, (struct Strbuf *)str);
    HALL_OF_FAME_PrintToPlate(work, 3, work->fontMain, work->strBuf, 92, 0);
    STRBUF_Delete((struct Strbuf *)str);
    str = (struct StrObj *)MSGDATA_AllocString(work->msgData, 7);
    WORDSET_SetSlotNumber(work->wordSet, 0, PLAYTIME_GetHours(work->args->playTime), 3, 0, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_SetSlotNumber(work->wordSet, 1, PLAYTIME_GetMinutes(work->args->playTime), 2, 2, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText(work->wordSet, (struct Strbuf *)work->strBuf, (struct Strbuf *)str);
    HALL_OF_FAME_PrintToPlate(work, 3, work->fontMain, work->strBuf, 200, 0);
    STRBUF_Delete((struct Strbuf *)str);
}

void HALL_OF_FAME_UpdatePlatePositions(HallOfFameWork *work)
{
    short x, y;
    HALL_OF_FAME_GetActorPos(work, HOF_ACTOR_PLATE_LEFT, &x, &y);
    BMP_OAM_SetPos(work->plates[0].oam, x - 176, y - 8);
    HALL_OF_FAME_GetActorPos(work, HOF_ACTOR_PLATE_RIGHT, &x, &y);
    BMP_OAM_SetPos(work->plates[1].oam, x, y - 8);
}

/*
 * follower: 0x021B7C60 tail-call stub included in this verified unit.
 */
void HALL_OF_FAME_SetPlateEnabled(HallOfFameWork *work, int plate, unsigned enabled)
{
    BMP_OAM_SetEnabled(work->plates[plate].oam, enabled);
}

void HALL_OF_FAME_LoadUiResources(HallOfFameWork *work)
{
    void *handle = ARC_TOOL_CreateHandle(0xD8, 0x808D);
    work->charIds[2] = CLACT_RegisterCharacter(handle, 0x18, 0, 0, 0x8D);
    work->paletteIds[2] = CLACT_RegisterPalette(handle, 3, 0, 0, 0x8D);
    work->cellAnimIds[2] = CLACT_RegisterCellAnim(handle, 0x1A, 0x20, 0x8D);
    ARC_TOOL_DeleteHandle(handle);
    handle = ARC_TOOL_CreateHandle(0x17, 0x808D);
    work->paletteIds[3] = CLACT_RegisterPaletteCompressed(handle, 5, 0, 0xA0, 0x8D);
    ARC_TOOL_DeleteHandle(handle);
}

void HALL_OF_FAME_CreateMonSceneObjects(HallOfFameWork *work)
{
    HALL_OF_FAME_LoadUiResources(work);
    HALL_OF_FAME_LoadUiPalette(work);
    work->actors[HOF_ACTOR_PLATE_LEFT] = HALL_OF_FAME_CreateActorFromTemplate(work, &gHallOfFamePlateLeftTemplate);
    work->actors[HOF_ACTOR_PLATE_RIGHT] = HALL_OF_FAME_CreateActorFromTemplate(work, &gHallOfFamePlateRightTemplate);
    work->actors[HOF_ACTOR_VOICE_MARK] = HALL_OF_FAME_CreateActorFromTemplate(work, &gHallOfFameVoiceMarkTemplate);
    HALL_OF_FAME_SetActorVisible(work, HOF_ACTOR_VOICE_MARK, 0);
    HALL_OF_FAME_CreateMonPlates(work);
}

void HALL_OF_FAME_DeleteMonSceneObjects(HallOfFameWork *work)
{
    HALL_OF_FAME_DeleteAllTextPlates(work);
    HALL_OF_FAME_DeleteAllActors(work);
    HALL_OF_FAME_ReleaseAllResources(work);
}

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
void HALL_OF_FAME_DrawMonScene(HallOfFameWork *work)
{
    if (DOUBLE3DDISP_GetMode() == 1)
        BG_SYS_SetMainPlaneVisible(16, 0);
    else
        BG_SYS_SetMainPlaneVisible(16, 1);
    HALL_OF_FAME_UpdateActors(work);
}

/*
 *   src/matched/arm9/unit_0204B22C.c defines CLACT_SetUnitRenderer but its function:
 *   line lists only CLACT_SetUnitDrawEnable. the integrator must add the missing unit entry.
 *   Scratch one --arm, dsi/1.1p1 -O4,p -lang c99: EXACT, 24 bytes, no sites.
 *   Verified C:
 *   typedef unsigned char u8;
 *   typedef unsigned int u32;
 *   struct Bank {
 *       u8 pad00[8]; void *f8; u8 pad0c[2];
 *       u8 source:4; u8 mode:4; u8 pad0f[9];
 *   };
 *   void CLACT_SetUnitRenderer(struct Bank *bank,void *p) {
 *       bank->f8=p;
 *       bank->source=1;
 *   }
 * arity: caller consumes live r0 after void 75A4/2DA48/2DA18;
 *   B0F4 forwards caller-loaded object and flag to BE38; 2DA04's unused
 *   trailing parameters are neither supplied nor read/forwarded in its body.
 */
void HALL_OF_FAME_CreateTrainerSceneObjects(HallOfFameWork *work)
{
    HofRendererSetup setup;
    u8 *handle;
    int trainerGender;
    HALL_OF_FAME_LoadUiResources(work);
    setup = gHallOfFameRendererSetup;
    work->renderer = CLACT_CreateRenderer((struct SurfaceInit *)&setup, 2, HOF_HEAP_ID);
    CLACT_SetRendererCulling((struct Renderer *)work->renderer, 1);
    CLACT_SetUnitRenderer(work->clactUnit, work->renderer);
    work->actors[HOF_ACTOR_RING_TOP] = HALL_OF_FAME_CreateActorFromTemplate(work, &gHallOfFameRingTopTemplate);
    work->actors[HOF_ACTOR_RING_BOTTOM] = HALL_OF_FAME_CreateActorFromTemplate(work, &gHallOfFameRingBottomTemplate);
    HALL_OF_FAME_SetActorVisible(work, HOF_ACTOR_RING_TOP, 0);
    HALL_OF_FAME_SetActorVisible(work, HOF_ACTOR_RING_BOTTOM, 0);
    handle = ARC_TOOL_CreateHandle(216, 0x808d);
    work->charIds[5] = CLACT_RegisterCharacter(handle, 25, 0, 1, HOF_HEAP_ID);
    work->paletteIds[6] = CLACT_RegisterPalette(handle, 3, 1, 0, HOF_HEAP_ID);
    work->cellAnimIds[5] = CLACT_RegisterCellAnim(handle, 27, 33, HOF_HEAP_ID);
    ARC_TOOL_DeleteHandle(handle);
    trainerGender = 1;
    if (!MYSTATUS_GetSex(work->args->myStatus))
        trainerGender = 0;
    handle = (u8 *)POKEGRA_OpenTrainerHandle(0x808d);
    work->charIds[3] = POKEGRA_RegisterTrainerCgr((handle), trainerGender, 0, HOF_HEAP_ID);
    work->paletteIds[4] = POKEGRA_RegisterTrainerPalette((handle), trainerGender, 0, 192, HOF_HEAP_ID);
    work->cellAnimIds[3] = POKEGRA_RegisterTrainerCellAnim(trainerGender, 2, 0, HOF_HEAP_ID);
    work->charIds[4] = POKEGRA_RegisterTrainerCgr((handle), trainerGender, 1, HOF_HEAP_ID);
    work->paletteIds[5] = POKEGRA_RegisterTrainerPalette((handle), trainerGender, 1, 96, HOF_HEAP_ID);
    work->cellAnimIds[4] = POKEGRA_RegisterTrainerCellAnim(trainerGender, 0, 1, HOF_HEAP_ID);
    ARC_TOOL_DeleteHandle(handle);
    work->actors[HOF_ACTOR_TRAINER_TOP] = HALL_OF_FAME_CreateActorFromTemplate(work, &gHallOfFameTrainerTopTemplate);
    work->actors[HOF_ACTOR_TRAINER_BOTTOM] = HALL_OF_FAME_CreateActorFromTemplate(work, &gHallOfFameTrainerBottomTemplate);
    HALL_OF_FAME_CreateTrainerPlates(work);
}

void HALL_OF_FAME_DeleteTrainerSceneObjects(HallOfFameWork *work)
{
    HALL_OF_FAME_DeleteAllTextPlates(work);
    HALL_OF_FAME_DeleteAllActors(work);
    CLACT_DeleteRenderer(work->renderer);
    HALL_OF_FAME_ReleaseAllResources(work);
}

void HALL_OF_FAME_DrawTrainerScene(HallOfFameWork *work)
{
    HALL_OF_FAME_UpdateActors(work);
}

/*
 * Earlier blocker (closed): register allocation, ~120 concrete bytes.  The original keeps
 * `p` in r5 and the loop index in r4 across both loops; every spelling
 * tried (int/u16 index, while/do-for, count-up from 0, explicit cursor)
 * makes mwcc place `p` in r4 and the index in r5 instead, which then
 * cascades through both loops.  Length 216 == original 216.  Two ABS32
 * sites (the two 24-byte row tables at 0x021B821C / 0x021B8234) stay
 * wildcarded for lack of an outside witness.
 *
 * note 2026-10-05: the random value n = (u16)GFL_USE_GetRandom(4) is a real spilled local:
 * the last call takes n + 4 (not i + 4); that gives the [sp] slot and the 0x20 frame.
 * The slot read and store written `actors[i]` share one i*4.
 */
void HALL_OF_FAME_SpawnSparkles(HallOfFameWork *work)
{
    s16 x;
    u16 i;
    u16 n;

    for (i = HOF_ACTOR_SPARKLE_FIRST; i < HOF_ACTOR_COUNT; i++) {
        if (work->actors[i] != 0) {
            if (HALL_OF_FAME_IsActorAnimActive(work, i) != 1)
                HALL_OF_FAME_DeleteActor(work, i);
        }
    }

    n = (u16)GFL_USE_GetRandom(4);
    if (n >= 2)
        return;

    for (i = HOF_ACTOR_SPARKLE_FIRST; i < HOF_ACTOR_COUNT; i++) {
        if (work->actors[i] == 0) {
            int y;
            HallOfFameActorTemplate local;

            x = (s16)GFL_USE_GetRandom(0x100);
            y = (s16)GFL_USE_GetRandom(0xd8);

            if (y < 0xc0) {
                local = gHallOfFameSparkleTemplateA;
                local.x = x;
                local.y = y;
            } else {
                local = gHallOfFameSparkleTemplateB;
                local.x = x;
                local.y = y - 0x18;
            }
            work->actors[i] = HALL_OF_FAME_CreateActorFromTemplate(work, &local);
            HALL_OF_FAME_PlayActorAnim(work, i, n + 4);
            return;
        }
    }
}
