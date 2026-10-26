/*
 * file:     plist_battle.c
 * unit:     yes
 * function: PLIST_BATTLE_CreateTeamPanel, PLIST_BATTLE_DeleteTeamPanel, PLIST_BATTLE_UpdateTeamPanel, PLIST_BATTLE_CreateMiniCell, PLIST_BATTLE_DeleteMiniCell, PLIST_BATTLE_UpdateMiniCell, PLIST_BATTLE_RefreshOpponentMessage, PLIST_BATTLE_PrintOpponentMessage, PLIST_BATTLE_CreateTimerWindows, PLIST_BATTLE_DeleteTimerWindows, PLIST_BATTLE_UpdateTimer, PLIST_BATTLE_StartEffect, PLIST_BATTLE_FinishEffect, PLIST_BATTLE_UpdateEffect
 * address:  0x021BD05C
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
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
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
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   d_021BED48 0x021BED48 data ov091 a1
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   POKELIST_ShutdownBgPlane0 0x021B7034 thumb ov091
 *   POKELIST_SetupLight 0x021B6F28 thumb ov091
 *   POKELIST_ShutdownLight 0x021B7040 thumb ov091
 *   POKELIST_SetupBgPlanes 0x021B6F0C thumb ov091
 *   PARTICLE_GetEffectCount 0x02051614 arm
 *   PARTICLE_UpdateAllSystems 0x02051574 arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   PARTICLE_DrawAllSystems 0x02051534 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   PM_VOICE_IsSlotActive 0x02006BD0 thumb
 *   POKELIST_ShowMessage  0x021B9788  thumb
 *   POKELIST_PrintTextMain  0x021B9C1C  thumb
 *   POKELIST_PrintExpandedTextSub  0x021B9D58  thumb
 *   POKELIST_CloseMessageToList  0x021B9E20  thumb
 *   POKELIST_EndMessageToExit  0x021B9E3C  thumb
 *   POKELIST_ForceSelectionEnd  0x021BA4F8  thumb
 *   PLIST_PLATE_SetMon  0x021BB200  thumb
 *   PLIST_MESSAGE_OpenWindow  0x021BB714  thumb
 *   PLIST_MESSAGE_IsWindowOpen  0x021BB7D8  thumb
 *   PLIST_MESSAGE_PrintText  0x021BB7E8  thumb
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb
 *   PLIST_MESSAGE_SetWordSetPokemon  0x021BB99C  thumb
 *   PLIST_MESSAGE_SetWordSetString  0x021BBA0C  thumb
 *   PLIST_MESSAGE_LoadWindowFrame  0x021BBA54  thumb
 *   PLIST_DEMO_CreateParticles  0x021BDABC  thumb
 *   PLIST_DEMO_DeleteParticles  0x021BDBE0  thumb
 *   PM_VOICE_Play  0x02006984  thumb  arm9
 */
struct ClactActor;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct WordSet;
struct Cfg;
struct PrintSys;
struct CharBuf;
struct StrObj;
struct Strbuf;
#include "../types.h"

#include "pokelist_types.h"
#include "plist_battle_types.h"

#include "../arm9/gfl_use.h"
struct Actor;
#include "../arm9/clact.h"
#include "../arm9/bg_sys.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
#include "../arm9/file_util.h"
#include "../arm9/gfl_heap_wrap.h"
struct Party;
#include "../arm9/pokeparty.h"
#include "../arm9/msgdata.h"
struct BmpWin;
struct Bmp;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
struct GfFont;
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
#ifdef __MWERKS__
#define BMP_WIN_Create BMP_WIN_CreateHeader
#endif
#include "../arm9/bmp_win.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef BMP_WIN_Create
extern struct BmpWin *BMP_WIN_Create(int,u8,u8,int,u8,u8,u8);
#endif
struct BmpWin;
extern u32 BMP_WIN_Delete(struct BmpWin *win);
struct Bmp;
struct PrintQueue;
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
#include "../arm9/arc_tool.h"
struct BoxPokemon;
#include "../arm9/poke_tool_ext.h"
#include "../arm9/gf_font.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
struct TaskMenuWin;
#include "../arm9/app_taskmenu.h"
#include "../arm9/nns_gfd_vram_transfer.h"
#include "pokelist.h"
struct ParticleSys;
#include "../arm9/particle.h"
#include "../arm9/pm_voice.h"
#include "../arm9/g3d_system.h"
struct PlistPlate;
struct PokelistWork;
#include "plist_plate.h"
struct PlistMessage;
#include "plist_message.h"
PlistTeamPanel *PLIST_BATTLE_CreateTeamPanel(PokelistWork *work, PlistTeamSource *source, u8 x, u8 y, u8 width);
void PLIST_BATTLE_DeleteTeamPanel(PokelistWork *work, PlistTeamPanel *panel);
void PLIST_BATTLE_UpdateTeamPanel(PokelistWork *work, PlistTeamPanel *panel);
PlistMiniCell *PLIST_BATTLE_CreateMiniCell(PokelistWork *work, void *mon, s16 x, u16 y);
void PLIST_BATTLE_DeleteMiniCell(PokelistWork *unusedWork, PlistMiniCell *cell);
void PLIST_BATTLE_UpdateMiniCell(PokelistWork *work, PlistMiniCell *cell);
void PLIST_BATTLE_RefreshOpponentMessage(PokelistWork *work);
void PLIST_BATTLE_PrintOpponentMessage(PokelistWork *work);
void PLIST_BATTLE_CreateTimerWindows(PokelistWork *work);
void PLIST_BATTLE_DeleteTimerWindows(PokelistWork *work);
void PLIST_BATTLE_UpdateTimer(PokelistWork *work);
void PLIST_BATTLE_StartEffect(PokelistWork *work);
void PLIST_BATTLE_FinishEffect(PokelistWork *work);
void PLIST_BATTLE_UpdateEffect(PokelistWork *work);
#include "plist_demo.h"
extern const char d_021BED48[];
extern s16 FX_SinCosTable_[];

PlistTeamPanel *PLIST_BATTLE_CreateTeamPanel(PokelistWork *work, PlistTeamSource *source, u8 x, u8 y, u8 width)
{
    PlistTeamPanel *panel;
    u8 count;
    u8 i;
    struct Strbuf *nameBuf;
    u32 active;

    panel = (PlistTeamPanel *)GFL_HEAP_Alloc(work->heapId, sizeof(PlistTeamPanel), 0, d_021BED48, 0x143);
    count = POKEPARTY_GetCount(source->party);
    for (i = 0; i < 6; i++) {
        if (i < count) {
            int column = i % 2;
            u8 cellX = x + column * (width + 5);
            u8 cellY = y + (i / 2) * 6 + 4;
            int pixelOffset = 4;
            if (column != 0) pixelOffset = 0;
            panel->cells[i] = PLIST_BATTLE_CreateMiniCell(work, POKEPARTY_GetMember(source->party, i), (u8)((u8)pixelOffset + (cellX << 3)), (u8)(cellY << 3));
        } else {
            panel->cells[i] = 0;
        }
    }
    active = 1;
    panel->nameWindow = BMP_WIN_Create((int)4, (u8)(x + 1 + ((u32)width >> 1)), (u8)(y + 1), (int)10, 2, 0xe, active);
    nameBuf = STRBUF_Create(0x10, work->heapId);
    STRBUF_SetString(nameBuf, source->name);
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(panel->nameWindow), 0, 0, nameBuf, work->fontMain, 0x3c40);
    STRBUF_Delete(nameBuf);
    panel->active = active;
    return panel;
}

void PLIST_BATTLE_DeleteTeamPanel(PokelistWork *work, PlistTeamPanel *panel)
{
    u8 i;
    for (i = 0; i < 6; i++) {
        PlistMiniCell *cell = panel->cells[i];
        if (cell) PLIST_BATTLE_DeleteMiniCell(work, cell);
    }
    BMP_WIN_Delete(panel->nameWindow);
    GFL_HEAP_Free(panel);
}

void PLIST_BATTLE_UpdateTeamPanel(PokelistWork *work, PlistTeamPanel *panel)
{
    u8 i;
    struct BmpWin *window;
    for (i = 0; i < 6; i++) {
        if (panel->cells[i] != 0)
            PLIST_BATTLE_UpdateMiniCell(work, panel->cells[i]);
    }
    if (panel->active == 1 && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printSys, (void *)BMP_WIN_GetBmp(panel->nameWindow)) == 0) {
        window = panel->nameWindow;
        panel->active = 0;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
    }
}

/*
 * lever: u16 y pins x's front spill; declare the u8 offset before gx to restore r7/r6 allocation.
 */
PlistMiniCell *PLIST_BATTLE_CreateMiniCell(PokelistWork *work, void *mon, s16 x, u16 y)
{
    PlistActorParam iconParam;
    PlistActorParam markParam;
    PlistMiniCell *cell;
    void *iconFile;
    void *boxMon;
    int paletteIndex;
    u32 heldItem;
    u32 sex;
    int level;
    int isEgg;
    int xOffset;
    u8 xShift;
    int cellX;
    u32 cellY;
    struct WordSet *wordSet;
    cell = GFL_HEAP_Alloc(work->heapId, sizeof(PlistMiniCell), 0, d_021BED48, 0x199);
    isEgg = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EGG_FLAG, 0);
    iconFile = ARC_TOOL_CreateHandle(7, work->heapId);
    boxMon = POKE_TOOL_GetBoxParam(mon);
    cell->iconRes = CLACT_RegisterCharacter(iconFile, POKE_TOOL_GetGraphicIndex(boxMon), 0, 1, work->heapId);
    ARC_TOOL_DeleteHandle(iconFile);
    paletteIndex = POKE_TOOL_GetIconPalette(boxMon);
    iconParam.x = x + 16; iconParam.y = y + 8; iconParam.animNo = 1; iconParam.softPriority = 16; iconParam.bgPriority = 2;
    {
        struct ClactActor *actor = CLACT_CreateActor((struct Unit *)work->actorSystem, cell->iconRes, work->charRes[7], work->cellRes[7], (const struct ActorInitParam *)&iconParam, 1, work->heapId);
        cell->iconActor = actor;
        CLACT_SetActorPaletteOffset((struct ClactActor *)actor, paletteIndex, 1);
    }
    CLACT_SetActorAutoAnim(cell->iconActor, 1);
    heldItem = POKE_TOOL_GetPartyValue(mon, PLIST_MON_HELD_ITEM, 0);
    markParam.x = x + 32; markParam.y = y + 16; markParam.animNo = 0; markParam.softPriority = 8; markParam.bgPriority = 2;
    cell->itemMarkActor = CLACT_CreateActor((struct Unit *)work->actorSystem, work->palRes[4], work->charRes[3], work->cellRes[4], (const struct ActorInitParam *)&markParam, 1, work->heapId);
    if (heldItem != 0) {
        CLACT_SetActorDrawEnable(cell->itemMarkActor, 1);
        if (FILE_UTIL_IsMailItem(heldItem) == 1) CLACT_SetActorAnimSeq(cell->itemMarkActor, 1);
        else CLACT_SetActorAnimSeq(cell->itemMarkActor, 0);
    } else CLACT_SetActorDrawEnable(cell->itemMarkActor, 0);
    sex = POKE_TOOL_GetPartyValue(mon, PLIST_MON_SEX, 0);
    xOffset = x % 8;
    xShift = xOffset;
    cellY = (u32)y >> 3;
    cellX = (u32)x >> 3;
    cell->sexWindow = BMP_WIN_Create(4, (u8)cellX + 3, cellY, 3, 2, 13, 1);
    if (isEgg == 0) {
        if (sex == 0) POKELIST_PrintTextMain((PokelistWork *)work, (struct Descriptor *)cell->sexWindow, 7, (u16)(xShift + 4), 0, 0x14c0);
        else if (sex == 1) POKELIST_PrintTextMain((PokelistWork *)work, (struct Descriptor *)cell->sexWindow, 8, (u16)(xShift + 4), 0, 0xc80);
    }
    level = POKE_TOOL_CalcLevel((void *)(mon));
    xShift = xOffset;
    cell->levelWindow = BMP_WIN_Create(4, (u8)cellX, (u8)cellY + 3, 6, 1, 14, 1);
    if (isEgg == 0) {
        wordSet = WORDSET_CreateDefault(work->heapId);
        WORDSET_SetSlotNumber(wordSet, 0, level, 3, 0, 1);
        POKELIST_PrintExpandedTextSub((PokelistWork *)work, (struct Descriptor *)cell->levelWindow, (void *)wordSet, 2, (s16)xShift, (s16)0, 0x3c40);
        WORDSET_Delete(wordSet);
    }
    cell->active = 1;
    return cell;
}

void PLIST_BATTLE_DeleteMiniCell(PokelistWork *unusedWork, PlistMiniCell *cell)
{
    BMP_WIN_Delete(cell->sexWindow);
    BMP_WIN_Delete(cell->levelWindow);
    CLACT_DeleteActor(cell->itemMarkActor);
    CLACT_DeleteActor(cell->iconActor);
    CLACT_ReleaseCharacter(cell->iconRes);
    GFL_HEAP_Free(cell);
}

void PLIST_BATTLE_UpdateMiniCell(PokelistWork *work, PlistMiniCell *cell)
{
    struct BmpWin *window;
    if (cell->active == 1
        && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printSys, (void *)BMP_WIN_GetBmp(cell->sexWindow)) == 0
        && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printSys, (void *)BMP_WIN_GetBmp(cell->levelWindow)) == 0) {
        window = cell->sexWindow;
        cell->active = 0;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
        window = cell->levelWindow;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
    }
}

void PLIST_BATTLE_RefreshOpponentMessage(PokelistWork *work)
{
    PLIST_BATTLE_PrintOpponentMessage(work);
    work->timerShown = work->arg->timerExpired;
}

void PLIST_BATTLE_PrintOpponentMessage(PokelistWork *work)
{
    struct Strbuf *text;
    if (work->arg->timerExpired == 0)
        return;
    if (PLIST_MESSAGE_IsWindowOpen(work, work->messageWindow) == 0)
        PLIST_MESSAGE_OpenWindow(work, work->messageWindow, 1);
    if (work->arg->battleKind == 1) {
        text = STRBUF_Create(0x10, work->heapId);
        STRBUF_SetString(text, work->arg->entries[1].name);
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetString(work, work->messageWindow, 0, (void *)text, work->arg->entries[1].gender);
        PLIST_MESSAGE_PrintText(work, work->messageWindow, 0xA9);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        STRBUF_Delete(text);
    } else {
        PLIST_MESSAGE_PrintText(work, work->messageWindow, work->arg->timerExpired + 0xA9);
    }
}

void PLIST_BATTLE_CreateTimerWindows(PokelistWork *work)
{
    struct Strbuf *text;
    work->timerLabelWindow = (void *)BMP_WIN_Create(4, 7, 0x15, 0xB, 3, 0xE, 1);
    work->timerValueWindow = (void *)BMP_WIN_Create(4, 0x14, 0x15, 5, 3, 0xE, 1);
    text = MSGDATA_AllocString((struct MsgBank *)work->msgBank, 0xAD);
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp((struct BmpWin *)work->timerLabelWindow), 0, 4, text,
                  work->fontMain, 0x3C40);
    STRBUF_Delete(text);
    work->timerLabelPrinting = 1;
}

void PLIST_BATTLE_DeleteTimerWindows(PokelistWork *work)
{
    BMP_WIN_Delete((struct BmpWin *)work->timerLabelWindow);
    BMP_WIN_Delete((struct BmpWin *)work->timerValueWindow);
}

/*
 * note: minute and second are u8 locals: widening the explicit byte casts
 *   to u32 keeps the size but moves the text spill before outgoing stores.
 */
void PLIST_BATTLE_UpdateTimer(PokelistWork *work)
{
    u32 width;
    u8 minute;
    u8 second;
    void *text;
    struct U16Vec *buf;
    struct WordSet *words;
    u16 timer;
    struct Descriptor *window;
    u8 amount;
    u8 i;
    u8 red;
    u8 green;
    u8 blue;
    u16 color;
    int value;
    timer = work->arg->timeLeft;
    if (work->shownSeconds != timer) {
        minute = (u8)(timer / 60);
        second = (u8)(timer % 60);
        buf = (struct U16Vec *)STRBUF_Create(32, work->heapId);
        words = WORDSET_CreateDefault(work->heapId);
        if (minute == 0) {
            text = MSGDATA_AllocString(work->msgBank, 175);
            WORDSET_SetSlotNumber(words, 1, second, 2, 1, 1);
        } else {
            text = MSGDATA_AllocString(work->msgBank, 174);
            WORDSET_SetSlotNumber(words, 0, minute, 2, 1, 1);
            WORDSET_SetSlotNumber(words, 1, second, 2, 2, 1);
        }
        BMP_Clear(BMP_WIN_GetBmp(work->timerValueWindow), 0);
        WORDSET_CopyTaggedText(words, (struct Strbuf *)buf, text);
        width = PRINTSYS_MeasureWidestLine((struct Strbuf *)buf, work->fontMain, 0);
        PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(work->timerValueWindow), (s16)(36 - width), 4, (struct Strbuf *)buf, work->fontMain, 0x3c40);
        WORDSET_Delete(words);
        STRBUF_Delete((struct Strbuf *)buf);
        STRBUF_Delete(text);
        work->timerValuePrinting = 1;
        work->shownSeconds = work->arg->timeLeft;
    }
    if (work->arg->timeLeft == 0) POKELIST_ForceSelectionEnd(work);
    if (work->timerValuePrinting == 1) {
        if (PRINTSYS_QUE_IsExistTarget(work->printSys, BMP_WIN_GetBmp(work->timerValueWindow)) == 0) {
            work->timerValuePrinting = 0;
            window = work->timerValueWindow;
            BMP_WIN_TransferChars((struct BmpWin *)window);
            BMP_WIN_MakeScreen((struct BmpWin *)window);
            BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)window));
        }
    }
    if (work->timerLabelPrinting == 1) {
        if (PRINTSYS_QUE_IsExistTarget(work->printSys, BMP_WIN_GetBmp(work->timerLabelWindow)) == 0) {
            work->timerLabelPrinting = 0;
            window = work->timerLabelWindow;
            BMP_WIN_TransferChars((struct BmpWin *)window);
            BMP_WIN_MakeScreen((struct BmpWin *)window);
            BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)window));
        }
    }
    if (work->arg->timeLeft <= 10) {
        amount = (FX_SinCosTable_[(((work->timerPalPhase << 16) / 60) >> 4) * 2 + 1] + 4096) * 32 / 8192;
        for (i = 0; i < 16; i++) {
            color = work->timerPalSrc[i];
            green = (color & 0x3e0) >> 5;
            blue = (color & 0x7c00) >> 10;
            red = color & 31;
            value = red + amount;
            if (value > 31) value = 31;
            red = value;
            work->timerPalDst[i] = (blue << 10) | (red | (green << 5));
        }
        NNS_GfdRegisterNewVramTransferTask(31, 64, work->timerPalDst, 32);
        work->timerPalPhase++;
        if (work->timerPalPhase >= 60) work->timerPalPhase = 0;
    }
}

void PLIST_BATTLE_StartEffect(PokelistWork *work)
{
    work->effectFrame = 0;
    work->effectStarted = 0;
    work->cryStarted = 0;
    BG_SYS_SetPlaneVisible(0, 0);
    POKELIST_ShutdownBgPlane0(work);
    POKELIST_SetupLight(work);
    PLIST_DEMO_CreateParticles(work);
    work->phase = 15;
}

void PLIST_BATTLE_FinishEffect(PokelistWork *work)
{
    void (*callback)(PokelistWork *);
    PLIST_DEMO_DeleteParticles(work);
    POKELIST_ShutdownLight(work);
    POKELIST_SetupBgPlanes(work);
    PLIST_MESSAGE_LoadWindowFrame(work, work->messageWindow);
    if (work->evolveCheckKind == 1) {
        callback = POKELIST_EndMessageToExit;
        if (work->arg->mode == 0) callback = POKELIST_CloseMessageToList;
        PLIST_MESSAGE_CreateWordSet((PokelistWork *)work, (PlistMessage *)work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon((struct PokelistWork *)work, (PlistMessage *)work->messageWindow, 0, work->selectedMon);
        POKELIST_ShowMessage((PokelistWork *)work, 0xa6, 1, callback);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
    } else if (work->evolveCheckKind == 2) {
        callback = POKELIST_EndMessageToExit;
        if (work->arg->mode == 0) callback = POKELIST_CloseMessageToList;
        PLIST_MESSAGE_CreateWordSet((PokelistWork *)work, (PlistMessage *)work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon((struct PokelistWork *)work, (PlistMessage *)work->messageWindow, 0, work->selectedMon);
        POKELIST_ShowMessage((PokelistWork *)work, 0xa6, 1, callback);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
    } else if (work->evolveCheckKind == 3) {
        PLIST_MESSAGE_CreateWordSet((PokelistWork *)work, (PlistMessage *)work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon((struct PokelistWork *)work, (PlistMessage *)work->messageWindow, 0, work->selectedMon);
        POKELIST_ShowMessage((PokelistWork *)work, 0xa6, 1, POKELIST_EndMessageToExit);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
    } else {
        work->phase = 0x13;
    }
}

/*
 *   unsigned int PARTICLE_GetEffectCount(unsigned int **p) { return (*p)[2]; }
 */
void PLIST_BATTLE_UpdateEffect(PokelistWork *work)
{
    u32 species, form;
    if (work->effectStarted == 0) {
        work->effectFrame++;
        if (work->effectFrame == 1) {
            BG_SYS_SetPlaneVisible(0, 1);
            if (work->evolveCheckKind - 1 <= 1) GFL_USE_PlaySeDefaultVolume(0x643);
            else if (work->evolveCheckKind == 3) GFL_USE_PlaySeDefaultVolume(0x644);
        }
        if (work->effectFrame > work->effectLength) {
            PLIST_PLATE_SetMon(work, (struct PlistPlate *)work->plates[work->selectedSlot], work->selectedMon, 0);
            work->effectStarted = 1;
        }
    }
    if (PARTICLE_GetEffectCount((struct ParticleSys *)work->particleSystem) <= 0 && GFL_USE_IsAnySeBusy() == 0) {
        if (work->cryStarted == 0) {
            species = POKE_TOOL_GetPartyValue(work->selectedMon, PLIST_MON_SPECIES, 0);
            form = POKE_TOOL_GetPartyValue(work->selectedMon, PLIST_MON_FORM, 0);
            work->cryHandle = PM_VOICE_Play(species, form, 0x40, 0, 0, 0, 0, 0);
            work->cryStarted = 1;
        } else {
            if (PM_VOICE_IsSlotActive(work->cryHandle) == 0) work->phase = 0x10;
        }
    }
    PARTICLE_UpdateAllSystems();
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    PARTICLE_DrawAllSystems();
    G3D_SYSTEM_DrawEnd();
}
