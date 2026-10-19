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
struct Obj;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct WordSet;
struct Cfg;
struct PrintSys;
struct CharBuf;
struct StrObj;
struct Strbuf;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short s16;
typedef signed int     s32;

#include "pokelist_types.h"
#include "plist_battle_types.h"

extern void GFL_USE_PlaySeDefaultVolume(u32 id);
struct Actor;
extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 value);
extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 value);
extern void BG_SYS_MarkTileDirty(u32 bit);
struct PokemonParam;
extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);
extern u32 FILE_UTIL_IsMailItem(u16);
extern u32 GFL_HEAP_Free(void *p);
struct Party;
extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
struct BmpWin;
struct Bmp;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
struct GfFont;
struct PrintQueue;
extern void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, unsigned int x, short y, struct Strbuf *str, struct GfFont *font, unsigned short color);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 BMP_WIN_Create(int,u8,u8,int,u8,u8,u8);
struct BmpWin;
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern void CLACT_DeleteActor(struct Actor *actor);
extern void CLACT_ReleaseCharacter(u32);
struct Bmp;
struct PrintQueue;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);
extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
struct BoxPokemon;
extern struct BoxPokemon *POKE_TOOL_GetBoxParam(struct PokemonParam *pp);
extern u32 POKE_TOOL_GetGraphicIndex(struct BoxPokemon *box);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *a);
extern u32 POKE_TOOL_GetIconPalette(struct BoxPokemon *box);
extern void CLACT_SetActorPaletteOffset(struct Actor *actor, u32 offset, u32 pltt_op);
extern struct WordSet *WORDSET_CreateDefault(u16 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 POKE_TOOL_CalcLevel(struct PokemonParam *pp);
extern void BMP_Clear(struct Bmp *bmp, unsigned char value);
extern int GFL_USE_IsAnySeBusy(void);
struct TaskMenuWin;
void APP_TASKMENU_WIN_SetDecide(struct TaskMenuWin *win, s32 isDecide);
extern u32 POKEPARTY_GetCount(struct Party *party);
extern u32 PRINTSYS_MeasureWidestLine(struct Strbuf *text, struct GfFont *font, unsigned int spacing);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern int NNS_GfdRegisterNewVramTransferTask(void *,u32,u32,int);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void POKELIST_ShutdownBgPlane0(PokelistWork *work);
extern void POKELIST_SetupLight(PokelistWork *work);
extern void POKELIST_ShutdownLight(PokelistWork *work);
extern void POKELIST_SetupBgPlanes(PokelistWork *work);
struct ParticleSys;
extern int PARTICLE_GetEffectCount(struct ParticleSys *sys);
extern u32 PM_VOICE_Play(u32 species, u32 form, u32 pan, u32 dual, u32 volumeBiasB, u32 frequencyOffsetB, u32 reverse, void **recordedVoice);
extern u32 PM_VOICE_IsSlotActive(u32 i);
extern int PARTICLE_UpdateAllSystems(void);
extern void G3D_SYSTEM_DrawStart(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern int PARTICLE_DrawAllSystems(void);
extern void G3D_SYSTEM_DrawEnd(void);
void POKELIST_ShowMessage(PokelistWork *work, int messageId, int waitForKey, int onDone);
void POKELIST_PrintTextMain(PokelistWork *work, u32 win, u32 id, int x, s16 y, u16 color);
void POKELIST_PrintExpandedTextSub(PokelistWork *work, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
void POKELIST_CloseMessageToList(PokelistWork *work);
void POKELIST_EndMessageToExit(PokelistWork *work);
void POKELIST_ForceSelectionEnd(PokelistWork *work);
struct PlistPlate;
struct PokelistWork;
void PLIST_PLATE_SetMon(struct PokelistWork *work, struct PlistPlate *plate, void *mon, s32 slideX);
struct PlistMessage;
void PLIST_MESSAGE_OpenWindow(struct PokelistWork *work, struct PlistMessage *msg, u32 kind);
int PLIST_MESSAGE_IsWindowOpen(struct PokelistWork *work, struct PlistMessage *msg);
void PLIST_MESSAGE_PrintText(struct PokelistWork *work, struct PlistMessage *msg, u32 messageId);
void PLIST_MESSAGE_CreateWordSet(struct PokelistWork *work, struct PlistMessage *msg);
void PLIST_MESSAGE_DestroyWordSet(struct PokelistWork *work, struct PlistMessage *msg);
void PLIST_MESSAGE_SetWordSetPokemon(struct PokelistWork *unused, struct PlistMessage *msg, u32 index, void *mon);
void PLIST_MESSAGE_SetWordSetString(struct PokelistWork *unused, struct PlistMessage *msg, u32 index, void *src, s32 n);
void PLIST_MESSAGE_LoadWindowFrame(PokelistWork *work, u32 window);
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
void PLIST_DEMO_CreateParticles(PokelistWork *work);
void PLIST_DEMO_DeleteParticles(PokelistWork *work);
extern const char d_021BED48[];
extern s16 FX_SinCosTable_[];

PlistTeamPanel *PLIST_BATTLE_CreateTeamPanel(PokelistWork *work, PlistTeamSource *source, u8 x, u8 y, u8 width)
{
    PlistTeamPanel *panel;
    u8 count;
    u8 i;
    u32 nameBuf;
    u32 active;

    panel = (PlistTeamPanel *)GFL_HEAP_Alloc(work->heapId, 0x20, 0, d_021BED48, 0x143);
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
    nameBuf = (u32)STRBUF_Create(0x10, work->heapId);
    STRBUF_SetString((struct Strbuf *)nameBuf, source->name);
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp((struct BmpWin *)panel->nameWindow), 0, 0, (struct Strbuf *)nameBuf, work->fontMain, 0x3c40);
    STRBUF_Delete((struct Strbuf *)nameBuf);
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
    BMP_WIN_Delete((struct BmpWin *)panel->nameWindow);
    GFL_HEAP_Free(panel);
}

void PLIST_BATTLE_UpdateTeamPanel(PokelistWork *work, PlistTeamPanel *panel)
{
    u8 i;
    u32 window;
    for (i = 0; i < 6; i++) {
        if (panel->cells[i] != 0)
            PLIST_BATTLE_UpdateMiniCell(work, panel->cells[i]);
    }
    if (panel->active == 1 && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printSys, (void *)BMP_WIN_GetBmp((struct BmpWin *)panel->nameWindow)) == 0) {
        window = panel->nameWindow;
        panel->active = 0;
        BMP_WIN_TransferChars((struct BmpWin *)window);
        BMP_WIN_MakeScreen((struct BmpWin *)window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)window));
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
    int boxMon;
    int paletteIndex;
    u32 heldItem;
    u32 sex;
    int level;
    int isEgg;
    int xOffset;
    u8 xShift;
    int cellX;
    u32 cellY;
    u32 wordSet;
    cell = GFL_HEAP_Alloc(work->heapId, 24, 0, d_021BED48, 0x199);
    isEgg = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EGG_FLAG, 0);
    iconFile = ARC_TOOL_CreateHandle(7, work->heapId);
    boxMon = (int)POKE_TOOL_GetBoxParam(mon);
    cell->iconRes = CLACT_RegisterCharacter(iconFile, POKE_TOOL_GetGraphicIndex((void *)boxMon), 0, 1, work->heapId);
    ARC_TOOL_DeleteHandle(iconFile);
    paletteIndex = POKE_TOOL_GetIconPalette((void *)boxMon);
    iconParam.x = x + 16; iconParam.y = y + 8; iconParam.animNo = 1; iconParam.softPriority = 16; iconParam.bgPriority = 2;
    {
        int actor = (int)CLACT_CreateActor(work->actorSystem, cell->iconRes, work->charRes[7], work->cellRes[7], &iconParam, 1, work->heapId);
        cell->iconActor = actor;
        CLACT_SetActorPaletteOffset((struct Actor *)actor, paletteIndex, 1);
    }
    CLACT_SetActorAutoAnim((struct Actor *)cell->iconActor, 1);
    heldItem = POKE_TOOL_GetPartyValue(mon, PLIST_MON_HELD_ITEM, 0);
    markParam.x = x + 32; markParam.y = y + 16; markParam.animNo = 0; markParam.softPriority = 8; markParam.bgPriority = 2;
    cell->itemMarkActor = (u32)CLACT_CreateActor(work->actorSystem, work->palRes[4], work->charRes[3], work->cellRes[4], &markParam, 1, work->heapId);
    if (heldItem != 0) {
        CLACT_SetActorDrawEnable((struct Actor *)cell->itemMarkActor, 1);
        if (FILE_UTIL_IsMailItem(heldItem) == 1) CLACT_SetActorAnimSeq((struct Actor *)cell->itemMarkActor, 1);
        else CLACT_SetActorAnimSeq((struct Actor *)cell->itemMarkActor, 0);
    } else CLACT_SetActorDrawEnable((struct Actor *)cell->itemMarkActor, 0);
    sex = POKE_TOOL_GetPartyValue(mon, PLIST_MON_SEX, 0);
    xOffset = x % 8;
    xShift = xOffset;
    cellY = (u32)y >> 3;
    cellX = (u32)x >> 3;
    cell->sexWindow = BMP_WIN_Create(4, (u8)cellX + 3, cellY, 3, 2, 13, 1);
    if (isEgg == 0) {
        if (sex == 0) POKELIST_PrintTextMain(work, cell->sexWindow, 7, (u16)(xShift + 4), 0, 0x14c0);
        else if (sex == 1) POKELIST_PrintTextMain(work, cell->sexWindow, 8, (u16)(xShift + 4), 0, 0xc80);
    }
    level = POKE_TOOL_CalcLevel((void *)((int)mon));
    xShift = xOffset;
    cell->levelWindow = BMP_WIN_Create(4, (u8)cellX, (u8)cellY + 3, 6, 1, 14, 1);
    if (isEgg == 0) {
        wordSet = (u32)WORDSET_CreateDefault(work->heapId);
        WORDSET_SetSlotNumber((struct WordSet *)wordSet, 0, level, 3, 0, 1);
        POKELIST_PrintExpandedTextSub(work, cell->levelWindow, (void *)wordSet, 2, (s16)xShift, (s16)0, 0x3c40);
        WORDSET_Delete((struct WordSet *)wordSet);
    }
    cell->active = 1;
    return cell;
}

void PLIST_BATTLE_DeleteMiniCell(PokelistWork *unusedWork, PlistMiniCell *cell)
{
    BMP_WIN_Delete((struct BmpWin *)cell->sexWindow);
    BMP_WIN_Delete((struct BmpWin *)cell->levelWindow);
    CLACT_DeleteActor((struct Actor *)cell->itemMarkActor);
    CLACT_DeleteActor((struct Actor *)cell->iconActor);
    CLACT_ReleaseCharacter(cell->iconRes);
    GFL_HEAP_Free(cell);
}

void PLIST_BATTLE_UpdateMiniCell(PokelistWork *work, PlistMiniCell *cell)
{
    u32 window;
    if (cell->active == 1
        && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printSys, (void *)BMP_WIN_GetBmp((struct BmpWin *)cell->sexWindow)) == 0
        && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printSys, (void *)BMP_WIN_GetBmp((struct BmpWin *)cell->levelWindow)) == 0) {
        window = cell->sexWindow;
        cell->active = 0;
        BMP_WIN_TransferChars((struct BmpWin *)window);
        BMP_WIN_MakeScreen((struct BmpWin *)window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)window));
        window = cell->levelWindow;
        BMP_WIN_TransferChars((struct BmpWin *)window);
        BMP_WIN_MakeScreen((struct BmpWin *)window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)window));
    }
}

void PLIST_BATTLE_RefreshOpponentMessage(PokelistWork *work)
{
    PLIST_BATTLE_PrintOpponentMessage(work);
    work->timerShown = work->arg->timerExpired;
}

void PLIST_BATTLE_PrintOpponentMessage(PokelistWork *work)
{
    int text;
    if (work->arg->timerExpired == 0)
        return;
    if (PLIST_MESSAGE_IsWindowOpen(work, (struct PlistMessage *)work->messageWindow) == 0)
        PLIST_MESSAGE_OpenWindow(work, (struct PlistMessage *)work->messageWindow, 1);
    if (work->arg->battleKind == 1) {
        text = (int)STRBUF_Create(0x10, work->heapId);
        STRBUF_SetString((struct Strbuf *)text, work->arg->entries[1].name);
        PLIST_MESSAGE_CreateWordSet(work, (struct PlistMessage *)work->messageWindow);
        PLIST_MESSAGE_SetWordSetString(work, (struct PlistMessage *)work->messageWindow, 0, (void *)text, work->arg->entries[1].gender);
        PLIST_MESSAGE_PrintText(work, (struct PlistMessage *)work->messageWindow, 0xA9);
        PLIST_MESSAGE_DestroyWordSet(work, (struct PlistMessage *)work->messageWindow);
        STRBUF_Delete((struct Strbuf *)text);
    } else {
        PLIST_MESSAGE_PrintText(work, (struct PlistMessage *)work->messageWindow, work->arg->timerExpired + 0xA9);
    }
}

void PLIST_BATTLE_CreateTimerWindows(PokelistWork *work)
{
    int text;
    work->timerLabelWindow = (void *)BMP_WIN_Create(4, 7, 0x15, 0xB, 3, 0xE, 1);
    work->timerValueWindow = (void *)BMP_WIN_Create(4, 0x14, 0x15, 5, 3, 0xE, 1);
    text = (int)MSGDATA_AllocString((struct MsgBank *)work->msgBank, 0xAD);
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp((struct BmpWin *)work->timerLabelWindow), 0, 4, (struct Strbuf *)text,
                  work->fontMain, 0x3C40);
    STRBUF_Delete((struct Strbuf *)text);
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
        NNS_GfdRegisterNewVramTransferTask((void *)31, 64, (u32)work->timerPalDst, 32);
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
        PLIST_MESSAGE_CreateWordSet(work, (struct PlistMessage *)work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, (struct PlistMessage *)work->messageWindow, 0, (void *)work->selectedMon);
        POKELIST_ShowMessage(work, 0xa6, 1, (int)callback);
        PLIST_MESSAGE_DestroyWordSet(work, (struct PlistMessage *)work->messageWindow);
    } else if (work->evolveCheckKind == 2) {
        callback = POKELIST_EndMessageToExit;
        if (work->arg->mode == 0) callback = POKELIST_CloseMessageToList;
        PLIST_MESSAGE_CreateWordSet(work, (struct PlistMessage *)work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, (struct PlistMessage *)work->messageWindow, 0, (void *)work->selectedMon);
        POKELIST_ShowMessage(work, 0xa6, 1, (int)callback);
        PLIST_MESSAGE_DestroyWordSet(work, (struct PlistMessage *)work->messageWindow);
    } else if (work->evolveCheckKind == 3) {
        PLIST_MESSAGE_CreateWordSet(work, (struct PlistMessage *)work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, (struct PlistMessage *)work->messageWindow, 0, (void *)work->selectedMon);
        POKELIST_ShowMessage(work, 0xa6, 1, (int)POKELIST_EndMessageToExit);
        PLIST_MESSAGE_DestroyWordSet(work, (struct PlistMessage *)work->messageWindow);
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
            PLIST_PLATE_SetMon(work, (struct PlistPlate *)work->plates[work->selectedSlot], (void *)work->selectedMon, 0);
            work->effectStarted = 1;
        }
    }
    if (PARTICLE_GetEffectCount((struct ParticleSys *)work->particleSystem) <= 0 && GFL_USE_IsAnySeBusy() == 0) {
        if (work->cryStarted == 0) {
            species = POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_SPECIES, 0);
            form = POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_FORM, 0);
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
