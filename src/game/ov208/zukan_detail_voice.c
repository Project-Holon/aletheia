/*
 * file:     zukan_detail_voice.c
 * unit:     yes
 * function: ZUKAN_DETAIL_VOICE_SetHeapId, ZUKAN_DETAIL_VOICE_Init, ZUKAN_DETAIL_VOICE_Exit, ZUKAN_DETAIL_VOICE_Main, ZUKAN_DETAIL_VOICE_HandleKeyEvent, ZUKAN_DETAIL_VOICE_ApplyPendingDisplay, ZUKAN_DETAIL_VOICE_FadeOutBgm, ZUKAN_DETAIL_VOICE_RestoreBgm, ZUKAN_DETAIL_VOICE_UpdateBgmFade, ZUKAN_DETAIL_VOICE_CreateNumberActors, ZUKAN_DETAIL_VOICE_DeleteNumberActors, ZUKAN_DETAIL_VOICE_SetNumberDigits, ZUKAN_DETAIL_VOICE_LoadPokemonGraphics, ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics, ZUKAN_DETAIL_VOICE_UpdatePokemonScaleAnim, ZUKAN_DETAIL_VOICE_ResetPokemonTransform, ZUKAN_DETAIL_VOICE_FinishScaleAnim, ZUKAN_DETAIL_VOICE_CreateTimerWindow, ZUKAN_DETAIL_VOICE_DeleteTimerWindow, ZUKAN_DETAIL_VOICE_DrawSpeciesName, ZUKAN_DETAIL_VOICE_ClearTimerWindow, ZUKAN_DETAIL_VOICE_FlushTimerWindow, ZUKAN_DETAIL_VOICE_LoadWindowPalette, ZUKAN_DETAIL_VOICE_NoOpA, ZUKAN_DETAIL_VOICE_NoOpB, ZUKAN_DETAIL_VOICE_NoOpC, ZUKAN_DETAIL_VOICE_UpdatePlaybackTimer, ZUKAN_DETAIL_VOICE_StopVoice, ZUKAN_DETAIL_VOICE_SwitchPokemonSlot, ZUKAN_DETAIL_VOICE_HandlePlayInput, ZUKAN_DETAIL_VOICE_CreateWaveformWindow, ZUKAN_DETAIL_VOICE_DeleteWaveformWindow, ZUKAN_DETAIL_VOICE_UpdateWaveformDelay, ZUKAN_DETAIL_VOICE_InitWaveformState, ZUKAN_DETAIL_VOICE_ScrollWaveform, ZUKAN_DETAIL_VOICE_DrawWaveform, ZUKAN_DETAIL_VOICE_UpdateWaveformTiles, ZUKAN_DETAIL_VOICE_SetActorsNormalMode, ZUKAN_DETAIL_VOICE_SetActorsAlphaMode
 * address:  0x021C255C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_headbar.c, zukan_detail_page.c, zukan_detail_voice.c, zukan_detail_form.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_Delete        0x020437AC  arm
 *   MSGDATA_AllocString        0x02045EC0  arm
 *   PRINTSYS_PrintQueColor        0x0201C724  thumb
 *   STRBUF_Delete        0x02045808  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   ZUKAN_DETAIL_VOICE_SetHeapId 0x021C255C thumb
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   CLACT_AddActorSurfacePos        0x0204B404  arm
 *   CLACT_RegisterPaletteEx        0x0204AC18  arm
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   ZUKAN_DETAIL_PROCSYS_AllocBuffer 0x021BC32C thumb
 *   ZUKAN_DETAIL_COMMON_AllocBlendWork 0x021BC448 thumb
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone 0x021BC508 thumb
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork 0x021BC464 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_FreeBuffer 0x021BC34C thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb
 *   ZUKAN_DETAIL_COMMON_GetHeadbar 0x021BC3B8 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetMode 0x021BDAD0 thumb
 *   ZUKAN_DETAIL_COMMON_GetEntryCount 0x021BC3BC thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode 0x021BDAAC thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetEnabled 0x021BDAD4 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind 0x021BDBB8 thumb
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 *   ZUKAN_DETAIL_HEADBAR_GetIconKind 0x021BE840 thumb
 *   ZUKAN_DETAIL_HEADBAR_SetIconKind 0x021BE82C thumb
 *   ZUKAN_DETAIL_HEADBAR_SetIconSpecies 0x021BE844 thumb
 *   ZUKAN_DETAIL_COMMON_GetDisplay 0x021BC3A8 thumb
 *   ZUKAN_DETAIL_COMMON_GetGraphics 0x021BC3B0 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState 0x021BDBA0 thumb
 *   ZUKAN_DETAIL_HEADBAR_SetIconForm 0x021BE854 thumb
 *   ZUKAN_DETAIL_COMMON_UpdateBlendFades 0x021BC46C thumb
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies  0x021BC3CC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies  0x021BC40C  thumb  ov208
 *   GAME_DATA_SetRecentId  0x02012BE0  thumb
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   ZUKAN_SAVE_GetViewGenderAndForm 0x0200CC40 thumb
 *   ZUKAN_SAVE_GetSpindaPersonality 0x0200D288 thumb
 *   ZUKAN_DETAIL_COMMON_GetFont 0x021BC3AC thumb ov208
 *   ZUKAN_DETAIL_COMMON_FreeBgPalette 0x021BC97C thumb ov208
 *   ZUKAN_DETAIL_COMMON_DeletePaletteAnim 0x021BC61C thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetSource  0x021BC3A4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessFull 0x021BC4F4 thumb ov208
 *   ZUKAN_DETAIL_COMMON_TransferPalettes 0x021BC6BC thumb ov208
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   GF_FONT_MeasureWidestLine  0x0201D304  thumb
 *   BMP_GetWidth  0x020437DC  arm
 *   G2x_SetBlendAlpha_ 0x0207D63C  arm
 *   ZUKAN_DETAIL_GRAPHIC_Reset3dState  0x021BCF4C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault  0x021BC610  thumb  ov208
 *   PM_VOICE_IsAnyActive  0x02006650  thumb
 *   PM_VOICE_StopAll  0x020065D8  thumb
 *   ZUKAN_DETAIL_VOICE_DeleteWaveformWindow  0x021C3638  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBgScrollPacked  0x021BCA54  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_ClearTimerWindow  0x021C32FC  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_DeleteTimerWindow  0x021C3268  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_NoOpC  0x021C337C  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_NoOpA  0x021C3374  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_CreateTimerWindow 0x021C3218 thumb ov208
 *   ZUKAN_DETAIL_VOICE_DrawSpeciesName 0x021C3280 thumb ov208
 *   ZUKAN_DETAIL_VOICE_LoadWindowPalette 0x021C3354 thumb ov208
 *   ZUKAN_DETAIL_VOICE_NoOpB 0x021C3378 thumb ov208
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteRange 0x021BC9BC thumb ov208
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc 0x021BC844 thumb ov208
 *   ZUKAN_DETAIL_VOICE_CreateWaveformWindow 0x021C35DC thumb ov208
 *   ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots 0x021BC758 thumb ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeIn 0x021BC718 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SetActorsNormalMode 0x021C3AA8 thumb ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOut 0x021BC6D8 thumb ov208
 *   ZUKAN_DETAIL_COMMON_IsFadeBusy 0x021BC6C8 thumb ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOutAlt 0x021BC6F8 thumb ov208
 *   ZUKAN_DETAIL_VOICE_HandlePlayInput 0x021C3514 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SetActorsAlphaMode 0x021C3B14 thumb ov208
 *   ZUKAN_DETAIL_VOICE_UpdatePlaybackTimer 0x021C3380 thumb ov208
 *   ZUKAN_DETAIL_VOICE_UpdateWaveformDelay 0x021C3650 thumb ov208
 *   ZUKAN_DETAIL_VOICE_UpdatePokemonScaleAnim 0x021C301C thumb ov208
 *   ZUKAN_DETAIL_VOICE_FlushTimerWindow 0x021C3318 thumb ov208
 *   ZUKAN_DETAIL_COMMON_TickFlashEffect 0x021BC99C thumb ov208
 *   ZUKAN_DETAIL_COMMON_UpdatePaletteAnim 0x021BC678 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SwitchPokemonSlot  0x021C34A4  thumb  ov208
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   data_021C8704  0x021C8704  data
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   data_021C86EC 0x021C86EC data ov208 a1
 *   ZUKAN_DETAIL_COMMON_LoadPaletteToSlot 0x021BC738 thumb ov208
 *   CLACT_CreateAffineActor 0x0204B324 arm
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 *   CLACT_GetActorScale 0x0204B5C0 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_IsBgmFading  0x02005E50  thumb  arm9
 *   GFL_USE_PushBgm  0x02005E64  thumb  arm9
 *   GFL_USE_PopBgm  0x02005E9C  thumb  arm9
 *   ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics 0x021C2FEC thumb ov208
 *   ZUKAN_DETAIL_VOICE_LoadPokemonGraphics 0x021C2E6C thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq  0x021BDC14  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled 0x021BDAE8 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive 0x021BDC2C thumb ov208
 *   gSpeciesNameBank 0x020A7370 data a4
 *   OS_GetTick 0x020870D0 arm
 *   ZUKAN_DETAIL_VOICE_FinishScaleAnim 0x021C3208 thumb ov208
 *   ZUKAN_DETAIL_VOICE_NoOpC 0x021C337C thumb ov208
 *   ZUKAN_DETAIL_VOICE_NoOpB 0x021C3378 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SetNumberDigits 0x021C2DE0 thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry 0x021BC3C0 thumb ov208
 *   PM_VOICE_Play 0x02006984 thumb
 *   ZUKAN_DETAIL_VOICE_ResetPokemonTransform 0x021C31CC thumb ov208
 *   BMP_Create 0x02043678 arm
 *   data_021C8E28 0x021C8E28 data ov208 a1
 *   ZUKAN_DETAIL_VOICE_ScrollWaveform 0x021C36CC thumb ov208
 *   BMP_FillRect 0x02043AF4 arm
 *   BMP_Blit 0x020439A0 arm
 *   ZUKAN_DETAIL_VOICE_UpdateWaveformTiles 0x021C3A24 thumb ov208
 *   PM_VOICE_GetData 0x02006B5C thumb
 *   PM_VOICE_GetSampleRate 0x02006B94 thumb
 *   PM_VOICE_GetFrequency 0x02006B3C thumb
 *   PM_VOICE_GetDataSize 0x02006B78 thumb
 *   PM_VOICE_GetVolume 0x02006B20 thumb
 *   BMP_WIN_GetCharOffset 0x02045768 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 */
#include "zukan_detail_types.h"
#include "zukan_detail_shared_types.h"
#include "zukan_detail_form_types.h"

extern u32 GFL_HEAP_Free(void *p);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void TCB_DeleteTask(struct Node *n);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void *GFL_USE_AddMainTask(unsigned,unsigned,unsigned);

extern void *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);

extern void BG_SYS_ChangeScrollImmediate(unsigned,unsigned,unsigned);

extern void BG_SYS_SetPriority(int,u16);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void BMP_Delete(struct Bmp *p);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, struct GfFont *e, u16 f);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void *ZUKAN_SAVE_GetFromGameData(void *a);

#include "zukan_detail_voice_types.h"
extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void BG_SYS_FreeSlot(u8);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern u32  CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern u32  CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void BG_SYS_PushTile(u8 channel);

extern struct Obj *CLACT_CreateActor(u32 owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);

extern void UI_SetInputMode(u8 v);

extern u32 KEY_GetTrg(void);

extern void CLACT_SetActorDrawEnable(struct Obj *p,u32 v);

extern void *ZUKAN_DETAIL_PROCSYS_AllocBuffer(struct Ov208Buf *p, u32 size, u32 heap);

extern void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap);

extern void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(void *p);

extern void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, void *p);

extern void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *p);

extern void ZUKAN_DETAIL_PROCSYS_FreeBuffer(char *);

extern int ZUKAN_DETAIL_TOUCHBAR_GetMode(void *s);

extern void ZUKAN_DETAIL_TOUCHBAR_SetMode(void *s, u32 a, u32 b, u32 c);

extern void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(void *s, int a);

extern void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(void *s, u32 a);

extern int GAME_DATA_ContainsRecentId(void *gd, int b);

extern int ZUKAN_DETAIL_HEADBAR_GetIconKind(void *s);

extern void ZUKAN_DETAIL_HEADBAR_SetIconKind(void *s, int a);

extern void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(void *s);

extern void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(void *s);

extern void ZUKAN_DETAIL_HEADBAR_SetIconForm(void *s);

extern void ZUKAN_DETAIL_COMMON_UpdateBlendFades(void *a, void *b);

extern void GAME_DATA_SetRecentId(void *p, u32 a, u32 b);

extern void CLACT_SetActorObjMode(struct Obj *p,u32 value);

extern void ZUKAN_SAVE_GetViewGenderAndForm(void *, u32, u32 *, u32 *, u32 *, u16);

extern u32 ZUKAN_SAVE_GetSpindaPersonality(struct Blk37 *, u32);

extern void ZUKAN_DETAIL_COMMON_FreeBgPalette(void *p);

extern void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(void *p);

extern void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int flag, void *p);

extern void ZUKAN_DETAIL_COMMON_TransferPalettes(void *p);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void ARC_UTIL_UploadPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);

extern void CLACT_GetActorSurfacePos(struct Obj *actor, struct PtS *out, u16 space);

extern u32 ZUKAN_DETAIL_GRAPHIC_Reset3dState(void *display);

extern void *ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(u32 heap);

extern int PM_VOICE_IsAnyActive(void);

extern void PM_VOICE_StopAll(void);

extern void ZUKAN_DETAIL_COMMON_SetBgScrollPacked(u32 a, u32 packed);

extern u32 ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(int,u16,u8,u8,u8,u8,u32,u32,u32,u32,u32);

extern struct Ov208Win *ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16,u32,u8,u8,u8);

extern void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(void *p);

extern void ZUKAN_DETAIL_COMMON_StartFadeIn(void *p);

extern void ZUKAN_DETAIL_COMMON_StartFadeOut(void *p);

extern int ZUKAN_DETAIL_COMMON_IsFadeBusy(void *p);

extern void ZUKAN_DETAIL_COMMON_StartFadeOutAlt(void *p);

extern void ZUKAN_DETAIL_COMMON_TickFlashEffect(void *p);

extern void ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(void *p);

extern void GFL_USE_FadeOutBgm(u32 v);

extern int GFL_USE_PopBgm(void);

extern void GFL_USE_SetBgmPaused(void *p);

extern void GFL_USE_FadeInBgmFull(u32 a);

extern int GFL_USE_IsBgmFading(void);

extern int GFL_USE_PushBgm(void);

extern void CLACT_SetActorAnimIndex(struct Obj *actor, int animIndex);

extern int POKEGRA_OpenHandle(int heapId);

extern u32 POKEGRA_RegisterCgr(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern int POKEGRA_RegisterPalette(int handle, int monsNo, int formNo, int sex, int rare, int dir, int egg, int drawType, unsigned short palOffset, unsigned short heapId);

extern u32 POKEGRA_RegisterCellAnim(u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern int POKEGRA_GetArcID(void);

extern s32 POKEGRA_GetPalArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 s5, u32 s6, u32 s7);

extern void ZUKAN_DETAIL_COMMON_LoadPaletteToSlot(void *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);

extern struct Obj *CLACT_CreateAffineActor(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);

extern void CLACT_GetActorScale(const struct Obj *o, struct Pair *p);

extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(struct Ov208Scene *p, int b);

int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on);

struct Ov208Win;
struct Ov208PalFade;
typedef unsigned long long u64;
extern const u8 data_021C8704[7][9];
extern const struct ZukanDetailVoiceDigitSlots data_021C86EC;

extern void BG_SYS_MarkTileDirty(u32 bit);

typedef signed char    s8;

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void *MSGDATA_AllocString(struct MsgBank *bank,u32 index);

extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s,struct GfFont *a,u32 b);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern u16 BMP_GetWidth(const struct Bmp *p);

extern void STRBUF_Delete(struct U16Vec *s);

extern void BMP_Clear(struct CharBuf *p, u8 v);

extern u64 OS_GetTick(void);

extern u32 PM_VOICE_Play(u32 species, u32 form, u32 pan, u32 dual, u32 volumeBiasB, u32 frequencyOffsetB, u32 reverse, u32 recordedVoice);

extern void *GFL_HEAP_Alloc(u32 heap,u32 size,int clear,const char *file,u16 line);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern void BMP_FillRect(struct Bmp *p,u32 a,u32 b,u32 c,u32 d,u32 e);

extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y,
                          int sx, int sy, u32 w, u32 h, u32 key);

extern u32 PM_VOICE_GetData(u32 i);

extern u32 PM_VOICE_GetSampleRate(u32 i);

extern u32 PM_VOICE_GetFrequency(u32 i);

extern u32 PM_VOICE_GetDataSize(u32 i);

extern s8 PM_VOICE_GetVolume(u32 i);

extern u16 BMP_WIN_GetCharOffset(struct Descriptor *p);

extern void BG_SYS_DrawTile(u32 index,u32 a,u32 b,u32 c,u8 d,u8 e);

extern void G2x_SetBlendAlpha_(u32 reg,int a,int b,int ev1,int ev2);

extern struct MsgBank *gSpeciesNameBank;

extern const char data_021C8E28[];

void ZUKAN_DETAIL_VOICE_SetHeapId(u16 *dst, u16 value);
u32 ZUKAN_DETAIL_VOICE_Init(void *workAlloc, u32 unused, u16 *heapIdPtr, u32 unused2, struct Ov208Ctx *ctx);
u32 ZUKAN_DETAIL_VOICE_Exit(void *workAlloc, u32 unused, void *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
int ZUKAN_DETAIL_VOICE_Main(void *unused, int *seq, u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_HandleKeyEvent(void *unused, void *unused2, void *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx, int key);
void ZUKAN_DETAIL_VOICE_ApplyPendingDisplay(void *unused, struct ZukanDetailVoice *voice);
void ZUKAN_DETAIL_VOICE_FadeOutBgm(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_RestoreBgm(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_UpdateBgmFade(int unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_CreateNumberActors(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DeleteNumberActors(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_SetNumberDigits(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *unused2, int seconds, u16 hundredths);
void ZUKAN_DETAIL_VOICE_LoadPokemonGraphics(u16 *heapIdPtr, u8 *p, struct Ov208Ctx *ctx, u32 slot);
void ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *unused2, u32 slot);
void ZUKAN_DETAIL_VOICE_UpdatePokemonScaleAnim(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_ResetPokemonTransform(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_FinishScaleAnim(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_CreateTimerWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DeleteTimerWindow(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DrawSpeciesName(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_ClearTimerWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_FlushTimerWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_LoadWindowPalette(unsigned short *heapIdPtr, void *unused, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_NoOpA(void *unused, void *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_NoOpB(void *unused, void *voice, struct Ov208Ctx *ctx, int seconds, int hundredths);
void ZUKAN_DETAIL_VOICE_NoOpC(void *unused, void *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_UpdatePlaybackTimer(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_StopVoice(int unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_SwitchPokemonSlot(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_HandlePlayInput(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_CreateWaveformWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DeleteWaveformWindow(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_UpdateWaveformDelay(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_InitWaveformState(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_ScrollWaveform(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DrawWaveform(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx, u16 species, u16 form);
void ZUKAN_DETAIL_VOICE_UpdateWaveformTiles(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_SetActorsNormalMode(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_SetActorsAlphaMode(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);

void ZUKAN_DETAIL_VOICE_SetHeapId(u16 *dst, u16 value)
{
    *dst = value;
}

u32 ZUKAN_DETAIL_VOICE_Init(void *workAlloc, u32 unused, u16 *heapIdPtr, u32 unused2, struct Ov208Ctx *ctx)
{
    struct ZukanDetailVoice *voice;
    u8 i;

    voice = ZUKAN_DETAIL_PROCSYS_AllocBuffer(workAlloc, 0xd4, *heapIdPtr);
    MI_CpuFill8(voice, 0, 0xd4);
    i = 0;
    voice->clactSys = ZUKAN_DETAIL_GRAPHIC_Reset3dState(ZUKAN_DETAIL_COMMON_GetDisplay(ctx));
    voice->font = ZUKAN_DETAIL_COMMON_GetFont(ctx);
    voice->printQue = ZUKAN_DETAIL_COMMON_GetGraphics(ctx);
    voice->waveBgDirty = 0;
    voice->voicePlaying = 0;
    voice->elapsedMs = 0;
    voice->shownMs = 1;
    voice->bgmPhase = 0;
    ZUKAN_DETAIL_VOICE_FadeOutBgm(heapIdPtr, voice, ctx);
    voice->task = GFL_USE_AddMainTask((unsigned)ZUKAN_DETAIL_VOICE_ApplyPendingDisplay, (unsigned)voice, 1);
    voice->blendTop = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heapIdPtr);
    voice->blendBottom = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heapIdPtr);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(voice->blendTop);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(voice->blendBottom);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(0, voice->blendTop);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(1, voice->blendBottom);
    voice->palFade = ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(*heapIdPtr);
    voice->exitMode = 0;
    voice->inputEnabled = 1;
    for (i = 0; i < 2; i++) {
        voice->pokemonActor[i] = 0;
    }
    voice->currentSlot = 0;
    return 1;
}

u32 ZUKAN_DETAIL_VOICE_Exit(void *workAlloc, u32 unused, void *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    u8 i;

    if (PM_VOICE_IsAnyActive() != 0) {
        PM_VOICE_StopAll();
    }
    ZUKAN_DETAIL_VOICE_DeleteWaveformWindow(heapIdPtr, voice, ctx);
    ZUKAN_DETAIL_COMMON_FreeBgPalette(voice->footerWin);
    ZUKAN_DETAIL_COMMON_FreeBgPalette(voice->headerWin);
    ZUKAN_DETAIL_COMMON_SetBgScrollPacked(2, voice->bgPaletteRange);
    for (i = 0; i < 2; i++) {
        ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(heapIdPtr, voice, ctx, i);
    }
    ZUKAN_DETAIL_VOICE_ClearTimerWindow(heapIdPtr, voice, ctx);
    ZUKAN_DETAIL_VOICE_DeleteTimerWindow(heapIdPtr, voice, ctx);
    ZUKAN_DETAIL_VOICE_NoOpC(heapIdPtr, voice, ctx);
    ZUKAN_DETAIL_VOICE_NoOpA(heapIdPtr, voice, ctx);
    ZUKAN_DETAIL_VOICE_DeleteNumberActors(heapIdPtr, voice, ctx);
    ZUKAN_DETAIL_COMMON_DeletePaletteAnim(voice->palFade);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(voice->blendBottom);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(voice->blendTop);
    if (voice->bgmPhase != 3) {
        ZUKAN_DETAIL_VOICE_RestoreBgm(heapIdPtr, voice, ctx);
    }
    TCB_DeleteTask(voice->task);
    ZUKAN_DETAIL_PROCSYS_FreeBuffer(workAlloc);
    return 1;
}

/* Explicit caller r2 loads preserve trailing arguments on setup/update helpers. */
int ZUKAN_DETAIL_VOICE_Main(void *unused, int *seq, u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    void *scene;
    struct Ov208Icon *icon;
    u8 i;
    int ready;
    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(ctx);
    icon = (struct Ov208Icon *)ZUKAN_DETAIL_COMMON_GetHeadbar(ctx);
    switch (*seq) {
    case 0:
        *seq = 1;
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                BG_SYS_ChangeScrollImmediate(i, 0, 0);
                BG_SYS_ChangeScrollImmediate(i, 3, 0);
                BG_SYS_FreeSlot(i);
            }
        }
        BG_SYS_SetPriority(2, 1);
        BG_SYS_SetPriority(3, 2);
        BG_SYS_SetPriority(0, 3);
        BG_SYS_SetPriority(6, 1);
        BG_SYS_SetPriority(4, 3);
        ZUKAN_DETAIL_VOICE_CreateNumberActors(heapIdPtr, voice, ctx);
        ZUKAN_DETAIL_VOICE_LoadPokemonGraphics(heapIdPtr, (u8 *)voice, ctx, voice->currentSlot);
        CLACT_SetActorObjMode(voice->pokemonActor[voice->currentSlot], 1);
        ZUKAN_DETAIL_VOICE_CreateTimerWindow(heapIdPtr, voice, ctx);
        ZUKAN_DETAIL_VOICE_DrawSpeciesName(heapIdPtr, voice, ctx);
        ZUKAN_DETAIL_VOICE_LoadWindowPalette(heapIdPtr, voice, ctx);
        ZUKAN_DETAIL_VOICE_NoOpB(heapIdPtr, voice, ctx, 0, 0);
        voice->bgPaletteRange = ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(0, *heapIdPtr, 2, 1, 0, 5, 0x9f, 1, 0xb, 0x2a, 0);
        voice->headerWin = ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(*heapIdPtr, 2, 0, 2, 3);
        voice->footerWin = ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(*heapIdPtr, 2, 4, 1, 2);
        ZUKAN_DETAIL_VOICE_SetNumberDigits(heapIdPtr, voice, ctx, 0, 0);
        ZUKAN_DETAIL_VOICE_CreateWaveformWindow(heapIdPtr, voice, ctx);
        ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(voice->palFade);
        ZUKAN_DETAIL_COMMON_StartFadeIn(voice->palFade);
        break;
    case 1:
        *seq = 2;
        ZUKAN_DETAIL_COMMON_SetBrightnessFull(0, voice->blendTop);
        ZUKAN_DETAIL_COMMON_SetBrightnessFull(1, voice->blendBottom);
        ZUKAN_DETAIL_VOICE_SetActorsNormalMode(heapIdPtr, voice, ctx);
        break;
    case 2:
        *seq = 3;
        ZUKAN_DETAIL_COMMON_StartFadeOut(voice->palFade);
        if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) != 2) {
            ZUKAN_DETAIL_TOUCHBAR_SetMode(scene, 0, 2, ZUKAN_DETAIL_COMMON_GetEntryCount(ctx) > 1);
            ZUKAN_DETAIL_TOUCHBAR_SetEnabled(scene, 0);
        } else ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(scene, 2);
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 0);
        ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq((struct Ov208Scene *)scene, GAME_DATA_ContainsRecentId(ZUKAN_DETAIL_COMMON_GetSource(ctx), 0x13));
        if (ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) != 2) {
            ZUKAN_DETAIL_HEADBAR_SetIconKind(icon, 2);
            ZUKAN_DETAIL_HEADBAR_SetIconSpecies(icon);
        }
        break;
    case 3:
        if (ZUKAN_DETAIL_COMMON_IsFadeBusy(voice->palFade) == 0 && ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) == 2 && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 2) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(scene);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
            *seq = 4;
        }
        break;
    case 4:
        if (voice->exitMode != 0) {
            *seq = 5;
            ZUKAN_DETAIL_COMMON_StartFadeOutAlt(voice->palFade);
            ZUKAN_DETAIL_HEADBAR_SetIconForm(icon);
            if (voice->exitMode == 2) ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled((struct Ov208Scene *)scene, 0);
            ZUKAN_DETAIL_VOICE_RestoreBgm(heapIdPtr, voice, ctx);
        } else ZUKAN_DETAIL_VOICE_HandlePlayInput(heapIdPtr, voice, ctx);
        break;
    case 5:
        ready = 0;
        if (ZUKAN_DETAIL_COMMON_IsFadeBusy(voice->palFade) == 0 && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 0) {
            if (voice->exitMode == 2) {
                if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) == 0) ready = 1;
            } else ready = 1;
        }
        if (ready) *seq = 6;
        break;
    case 6:
        *seq = 7;
        ZUKAN_DETAIL_VOICE_SetActorsAlphaMode(heapIdPtr, voice, ctx);
        ZUKAN_DETAIL_COMMON_SetBrightnessNone(0, voice->blendTop);
        ZUKAN_DETAIL_COMMON_SetBrightnessNone(1, voice->blendBottom);
        break;
    case 7:
        return 1;
    }
    if (*seq >= 3) {
        ZUKAN_DETAIL_VOICE_UpdatePlaybackTimer(heapIdPtr, voice, ctx);
        ZUKAN_DETAIL_VOICE_UpdateWaveformDelay(heapIdPtr, voice, ctx);
        ZUKAN_DETAIL_VOICE_UpdatePokemonScaleAnim(heapIdPtr, voice, ctx);
    }
    if (*seq >= 2) {
        ZUKAN_DETAIL_VOICE_FlushTimerWindow(heapIdPtr, voice, ctx);
        ZUKAN_DETAIL_COMMON_TickFlashEffect(voice->headerWin);
        ZUKAN_DETAIL_COMMON_TickFlashEffect(voice->footerWin);
    }
    ZUKAN_DETAIL_COMMON_UpdateBlendFades(voice->blendTop, voice->blendBottom);
    ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(voice->palFade);
    ZUKAN_DETAIL_VOICE_UpdateBgmFade((int)heapIdPtr, voice, ctx);
    return 0;
}

void ZUKAN_DETAIL_VOICE_HandleKeyEvent(void *unused, void *unused2, void *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx, int key)
{
    void *sceneObj;
    u32 flag;

    if (voice == 0) {
        return;
    }
    sceneObj = ZUKAN_DETAIL_COMMON_GetWorkPtr(ctx);
    flag = 0;
    switch (key) {
    case 17:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 18:
        voice->inputEnabled = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 9:
        flag = 1;
        voice->inputEnabled = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 oldSpecies = ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx);
        ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(ctx);
        if (oldSpecies != ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx)) {
            ZUKAN_DETAIL_VOICE_SwitchPokemonSlot(heapIdPtr, voice, ctx);
        }
        break;
    }
    case 13: {
        u16 oldSpecies = ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx);
        ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(ctx);
        if (oldSpecies != ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx)) {
            ZUKAN_DETAIL_VOICE_SwitchPokemonSlot(heapIdPtr, voice, ctx);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        voice->exitMode = 2;
        return;
    case 6: case 7: case 9:
        voice->exitMode = 1;
        return;
    case 3:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState((struct Ov208Scene *)sceneObj);
        return;
    case 4:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState((struct Ov208Scene *)sceneObj);
        return;
    case 5:
        GAME_DATA_SetRecentId(ZUKAN_DETAIL_COMMON_GetSource(ctx), 0x13, ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive((char *)sceneObj));
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState((struct Ov208Scene *)sceneObj);
        return;
    default:
        if (flag != 0) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState((struct Ov208Scene *)sceneObj);
        }
        break;
    }
}

/* Task callback: applies the pending BG scroll and the palette fade step. */
void ZUKAN_DETAIL_VOICE_ApplyPendingDisplay(void *unused, struct ZukanDetailVoice *voice)
{
    if (voice->waveBgDirty != 0) {
        BG_SYS_ChangeScrollImmediate(3, 0, voice->scrollSubPixels - 1);
        BG_SYS_ChangeScrollImmediate(3, 3, 0);
        BG_SYS_PushTile(3);
        voice->waveBgDirty = 0;
    }
    ZUKAN_DETAIL_COMMON_TransferPalettes(voice->palFade);
}

void ZUKAN_DETAIL_VOICE_FadeOutBgm(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    GFL_USE_FadeOutBgm(0x1e);
    voice->bgmPhase = 1;
}

/*
 * Leaves state 2 and moves bgmPhase to state 3.
 */
void ZUKAN_DETAIL_VOICE_RestoreBgm(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    if (voice->bgmPhase == 2) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPaused(0);
    }
    GFL_USE_FadeInBgmFull(0x3c);
    voice->bgmPhase = 3;
}

/*
 * Moves bgmPhase from state 1 to state 2.
 */
void ZUKAN_DETAIL_VOICE_UpdateBgmFade(int unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    if (voice->bgmPhase == 1) {
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_SetBgmPaused((void *)1);
            GFL_USE_PushBgm();
            voice->bgmPhase = 2;
        }
    }
}

/*
 * note: 2026-10-05 (wave D4 lane 02): the loop back edge in the image goes to the memset call,
 *         so the memset is the first statement of the loop body. The loop-invariant &pos
 *         (add r7, sp, #0x10) is then hoisted into the preheader, before the call.
 */
void ZUKAN_DETAIL_VOICE_CreateNumberActors(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    int arc;
    u8 i;
    struct ZukanDetailVoiceActorPos pos;

    arc = (int)ARC_TOOL_CreateHandle(0x9f, *heapIdPtr);
    i = 0;
    voice->gfxRes[1] = CLACT_RegisterPaletteEx((void *)arc, 3, 0, 0, 0, 4, *heapIdPtr);
    voice->gfxRes[0] = CLACT_RegisterCharacter((void *)arc, 0xd, 0, 0, *heapIdPtr);
    voice->gfxRes[2] = CLACT_RegisterCellAnim((void *)arc, 0x1b, 0x2c, *heapIdPtr);
    voice->gfxRes[4] = CLACT_RegisterPaletteEx((void *)arc, 8, 1, 0x40, 0, 1, *heapIdPtr);
    voice->gfxRes[3] = CLACT_RegisterCharacter((void *)arc, 0x18, 0, 1, *heapIdPtr);
    voice->gfxRes[5] = CLACT_RegisterCellAnim((void *)arc, 0x1e, 0x2f, *heapIdPtr);
    ARC_TOOL_DeleteHandle((void *)arc);
    do {
        const u8 *row;
        MI_CpuFill8(&pos, 0, 8);
        row = data_021C8704[i];
        pos.x = row[0];
        pos.y = row[1];
        pos.z = row[2];
        pos.animSeq = row[3];
        pos.priority = row[4];
        voice->actor[i] = CLACT_CreateActor(voice->clactSys, voice->gfxRes[row[5]], voice->gfxRes[row[6]], voice->gfxRes[row[7]], &pos, row[8], *heapIdPtr);
        CLACT_SetActorDrawEnable(voice->actor[i], 1);
        CLACT_SetActorObjMode(voice->actor[i], 1);
        i++;
    } while (i < 7);
    CLACT_SetActorAutoAnim(voice->actor[6], 1);
}

void ZUKAN_DETAIL_VOICE_DeleteNumberActors(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    u8 i;
    for (i = 0; i < 7; i++)
        CLACT_DeleteActor(voice->actor[i]);
    CLACT_ReleasePalette(voice->gfxRes[1]);
    CLACT_ReleaseCharacter(voice->gfxRes[0]);
    CLACT_ReleaseCellAnim(voice->gfxRes[2]);
    CLACT_ReleasePalette(voice->gfxRes[4]);
    CLACT_ReleaseCharacter(voice->gfxRes[3]);
    CLACT_ReleaseCellAnim(voice->gfxRes[5]);
}

void ZUKAN_DETAIL_VOICE_SetNumberDigits(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *unused2, int seconds, u16 hundredths)
{
    struct ZukanDetailVoiceDigitSlots digitSlots;
    u16 digits[4];
    u8 i;
    digitSlots = data_021C86EC;
    digits[0] = seconds / 10;
    if (digits[0] > 9) digits[0] = 9;
    digits[1] = seconds % 10;
    digits[2] = hundredths / 10;
    if (digits[2] > 9) digits[2] = 9;
    digits[3] = hundredths % 10;
    for (i = 0; i < 4; i++)
        CLACT_SetActorAnimIndex(voice->actor[digitSlots.slot[i]], digits[i]);
}

void ZUKAN_DETAIL_VOICE_LoadPokemonGraphics(u16 *heapIdPtr, u8 *p, struct Ov208Ctx *ctx, u32 slot)
{
    struct ZukanDetailVoiceAffineDesc desc;
    u32 gender, shiny, formNo;
    u32 arc, spindaPersonality, species;
    void *zukanSave;
    species = ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx);
    spindaPersonality = 0;
    zukanSave = ZUKAN_SAVE_GetFromGameData(ZUKAN_DETAIL_COMMON_GetSource(ctx));
    ZUKAN_SAVE_GetViewGenderAndForm(zukanSave, species, &gender, &shiny, &formNo, *heapIdPtr);
    if (species == 327) spindaPersonality = ZUKAN_SAVE_GetSpindaPersonality(zukanSave, spindaPersonality);
    arc = POKEGRA_OpenHandle(*heapIdPtr);
    *(u32 *)((u32)p + 0x44 + slot * 4) = POKEGRA_RegisterCgr(arc, species, formNo, gender, shiny, 0, 0, spindaPersonality, 1, *heapIdPtr);
    *(u32 *)((u32)p + 0x3c + slot * 4) = POKEGRA_RegisterPalette(arc, species, formNo, gender, shiny, 0, 0, 1, (u16)(slot << 5), *heapIdPtr);
    *(u32 *)((u32)p + 0x4c + slot * 4) = POKEGRA_RegisterCellAnim(species, formNo, gender, shiny, 0, 0, 2, 1, *heapIdPtr);
    ZUKAN_DETAIL_COMMON_LoadPaletteToSlot(((struct ZukanDetailVoice *)p)->palFade, arc, POKEGRA_GetPalArcIndex(POKEGRA_GetArcID(), species, formNo, gender, shiny, 0, 0), *heapIdPtr, 3, 32, (u16)(slot << 4), 0);
    ARC_TOOL_DeleteHandle((void *)arc);
    MI_CpuFill8(&desc, 0, 24);
    desc.x = 128; desc.y = 128; desc.z = 0; desc.animSeq = 0; desc.priority = 0; desc.palOffset = 0; desc.flipMode = 0;
    desc.scaleX = 4096; desc.scaleY = 4096; desc.rotation = 0; desc.drawMode = 2;
    *(u32 *)((u32)p + 0x54 + slot * 4) = (u32)CLACT_CreateAffineActor(((struct ZukanDetailVoice *)p)->clactSys, *(u32 *)((u32)p + 0x44 + slot * 4), *(u32 *)((u32)p + 0x3c + slot * 4), *(u32 *)((u32)p + 0x4c + slot * 4), (u32)(&desc), 1, *heapIdPtr);
    CLACT_SetActorObjMode((struct Obj *)(*(u32 *)((u32)p + 0x54 + slot * 4)), 0);
    ((struct ZukanDetailVoice *)p)->scaleState = 0;
}

void ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *unused2, u32 slot)
{
    if (voice->pokemonActor[slot] != 0) {
        CLACT_DeleteActor(voice->pokemonActor[slot]);
        voice->pokemonActor[slot] = 0;
        CLACT_ReleasePalette(voice->palRes[slot]);
        CLACT_ReleaseCharacter(voice->charRes[slot]);
        CLACT_ReleaseCellAnim(voice->cellRes[slot]);
    }
}

void ZUKAN_DETAIL_VOICE_UpdatePokemonScaleAnim(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    struct { s16 x; s16 y; } pos;
    struct Pair scale;
    float scaleY;
    switch (voice->scaleState) {
    case 0:
    case 2:
        break;
    case 1:
        CLACT_GetActorSurfacePos(voice->pokemonActor[voice->currentSlot], (struct PtS *)&pos, 1);
        CLACT_GetActorScale(voice->pokemonActor[voice->currentSlot], &scale);
        scaleY = (float)scale.y / 4096.0f;
        scaleY += 0.01f;
        if (scaleY >= 1.1f) {
            scaleY = 1.1f;
            voice->scaleState = 2;
        }
        pos.y = 0x80 - (int)(96.0f * (scaleY - 1.0f) / 2.0f);
        if (scaleY > 0.0f)
            scale.y = (int)(4096.0f * scaleY + 0.5f);
        else
            scale.y = (int)(4096.0f * scaleY - 0.5f);
        CLACT_AddActorSurfacePos(voice->pokemonActor[voice->currentSlot], (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorScale(voice->pokemonActor[voice->currentSlot], &scale);
        break;
    case 3:
        CLACT_GetActorSurfacePos(voice->pokemonActor[voice->currentSlot], (struct PtS *)&pos, 1);
        CLACT_GetActorScale(voice->pokemonActor[voice->currentSlot], &scale);
        scaleY = (float)scale.y / 4096.0f - 0.01f;
        if (scaleY <= 1.0f) {
            scaleY = 1.0f;
            voice->scaleState = 0;
            pos.y = 0x80;
        } else {
            pos.y = 0x80 - (int)(96.0f * (scaleY - 1.0f) / 2.0f);
        }
        if (scaleY > 0.0f)
            scale.y = (int)(4096.0f * scaleY + 0.5f);
        else
            scale.y = (int)(4096.0f * scaleY - 0.5f);
        CLACT_AddActorSurfacePos(voice->pokemonActor[voice->currentSlot], (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorScale(voice->pokemonActor[voice->currentSlot], &scale);
        break;
    }
}

/*
 * Hands the current Pokemon actor a 0x80 position pair and a 0x1000 scale pair
 * and starts the grow animation (scaleState 1).
 *
 * Blocker resolved: 0x0204B5AC was matched in arm9 (src/matched/
 * CLACT_SetActorScale.c, shard pkt_0204B5AC), so the call at +0x30 attests as
 * `matched`.  All 58 concrete bytes equal (the 60-byte listing extent is 58
 * plus two padding bytes); the extent ran two bytes long because the follower
 * has no func_ label.
 */
void ZUKAN_DETAIL_VOICE_ResetPokemonTransform(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    struct {
        unsigned int scale[2];
        unsigned short pos[2];
    } buf;

    buf.pos[0] = 0x80;
    buf.pos[1] = 0x80;
    buf.scale[0] = 0x1000;
    buf.scale[1] = 0x1000;
    CLACT_AddActorSurfacePos(voice->pokemonActor[voice->currentSlot], (const struct Vec2 *)buf.pos, 1);
    CLACT_SetActorScale(voice->pokemonActor[voice->currentSlot], (struct Pair *)buf.scale);
    voice->scaleState = 1;
}

/*
 * Moves scaleState from grow (1) or hold (2) to shrink (3).
 */
void ZUKAN_DETAIL_VOICE_FinishScaleAnim(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    unsigned int state = voice->scaleState;

    state -= 1;
    if (state <= 1)
        voice->scaleState = 3;
}

void ZUKAN_DETAIL_VOICE_CreateTimerWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    ARC_UTIL_UploadPaletteFromArchive(23, 5, 4, 0, 0, 32, *heapIdPtr);
    voice->nameWin = (struct Descriptor *)BMP_WIN_Create(6, 10, 5, 12, 4, 0, 1);
    voice->namePending = 0;
    ZUKAN_DETAIL_VOICE_ClearTimerWindow(heapIdPtr, voice, ctx);
    BMP_WIN_TransferChars(voice->nameWin);
}

/*
 * Clears namePending and releases the print queue and the name window.
 */
void ZUKAN_DETAIL_VOICE_DeleteTimerWindow(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    voice->namePending = 0;
    PRINTSYS_QUE_Clear(voice->printQue);
    BMP_WIN_Delete(voice->nameWin);
}

void ZUKAN_DETAIL_VOICE_DrawSpeciesName(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    struct StrObj *name;
    u16 textWidth;
    u16 winWidth;
    name = MSGDATA_AllocString(gSpeciesNameBank, ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx));
    textWidth = GF_FONT_MeasureWidestLine(name, voice->font, 0);
    winWidth = BMP_GetWidth(BMP_WIN_GetBmp(voice->nameWin));
    PRINTSYS_PrintQueColor(voice->printQue, (u32)BMP_WIN_GetBmp(voice->nameWin), (s16)((u16)((winWidth - textWidth) / 2)), (s16)1, (u32)name, voice->font, 0x3c40);
    STRBUF_Delete((struct U16Vec *)name);
    voice->namePending = 1;
    ZUKAN_DETAIL_VOICE_FlushTimerWindow(heapIdPtr, voice, ctx);
}

void ZUKAN_DETAIL_VOICE_ClearTimerWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    voice->namePending = 0;
    PRINTSYS_QUE_Clear(voice->printQue);
    BMP_Clear(BMP_WIN_GetBmp(voice->nameWin), 0);
}

void ZUKAN_DETAIL_VOICE_FlushTimerWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    struct Descriptor *win;
    if (voice->namePending != 0) {
        if (PRINTSYS_QUE_IsExistTarget(voice->printQue, BMP_WIN_GetBmp(voice->nameWin)) == 0) {
            win = voice->nameWin;
            BMP_WIN_TransferChars(win);
            BMP_WIN_MakeScreen((struct Cfg *)win);
            BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
            voice->namePending = 0;
        }
    }
}

/*
 * Loads palette archive entry 0x17 for the heap in the halfword at +0.
 */
void ZUKAN_DETAIL_VOICE_LoadWindowPalette(unsigned short *heapIdPtr, void *unused, struct Ov208Ctx *ctx)
{
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 0, 0, 0x20, 0x20, *heapIdPtr);
}

/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void ZUKAN_DETAIL_VOICE_NoOpA(void *unused, void *voice, struct Ov208Ctx *ctx)
{
}

void ZUKAN_DETAIL_VOICE_NoOpB(void *unused, void *voice, struct Ov208Ctx *ctx, int seconds, int hundredths)
{
}

void ZUKAN_DETAIL_VOICE_NoOpC(void *unused, void *voice, struct Ov208Ctx *ctx)
{
}

void ZUKAN_DETAIL_VOICE_UpdatePlaybackTimer(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    u64 now;
    u64 start;
    u64 diff;
    u64 ms;
    u16 cur;
    u16 secs;
    u16 rem;
    u16 hund;
    if (voice->voicePlaying != 0) {
        now = OS_GetTick();
        start = *(u64 *)&voice->startTick[0];
        if (now >= start)
            diff = now - start;
        else
            diff = now + (0xFFFFFFFFFFFFFFFFULL - start);
        ms = (diff * 64) / 33514;
        if (ms > 9990)
            ms = 9990;
        voice->elapsedMs = (u16)ms;
        if (voice->elapsedMs >= voice->voiceLengthMs) {
            voice->elapsedMs = voice->voiceLengthMs;
            voice->voicePlaying = 0;
            ZUKAN_DETAIL_VOICE_FinishScaleAnim(heapIdPtr, voice, ctx);
        }
    }
    cur = voice->elapsedMs;
    if (cur != voice->shownMs) {
        secs = cur / 1000;
        rem = cur % 1000;
        hund = rem / 10 + ((rem % 10) >= 5 ? 1 : 0);
        ZUKAN_DETAIL_VOICE_NoOpC((void *)(heapIdPtr), (void *)(voice), ctx);
        ZUKAN_DETAIL_VOICE_NoOpB(heapIdPtr, voice, ctx, secs, hund);
        ZUKAN_DETAIL_VOICE_SetNumberDigits((void *)(heapIdPtr), (struct ZukanDetailVoice *)(voice), ctx, (int)(secs), (u16)(hund));
        voice->shownMs = voice->elapsedMs;
    }
}

/*
 * BLOCKED.  Unverifiable: PM_VOICE_StopAll resolves only through the `matched` class and layout/matched/ov093 holds BTL_MAIN_ReturnZero in two shards, which aborts every manifest load.
 */
void ZUKAN_DETAIL_VOICE_StopVoice(int unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    int active;

    if (voice->voicePlaying != 0) {
        active = PM_VOICE_IsAnyActive();
        if (active != 0)
            PM_VOICE_StopAll();
        voice->voicePlaying = 0;
    }
    voice->elapsedMs = 0;
}

void ZUKAN_DETAIL_VOICE_SwitchPokemonSlot(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    if (voice->pokemonActor[voice->currentSlot])
        CLACT_SetActorDrawEnable(voice->pokemonActor[voice->currentSlot], 0);
    voice->currentSlot = (voice->currentSlot + 1) % 2;
    ZUKAN_DETAIL_VOICE_ClearTimerWindow(heapIdPtr, voice, ctx);
    ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(heapIdPtr, voice, ctx, voice->currentSlot);
    ZUKAN_DETAIL_VOICE_LoadPokemonGraphics(heapIdPtr, (u8 *)voice, ctx, voice->currentSlot);
    ZUKAN_DETAIL_VOICE_DrawSpeciesName(heapIdPtr, voice, ctx);
    ZUKAN_DETAIL_VOICE_StopVoice((int)heapIdPtr, voice, ctx);
    ZUKAN_DETAIL_VOICE_InitWaveformState(heapIdPtr, voice, ctx);
}

void ZUKAN_DETAIL_VOICE_HandlePlayInput(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    u32 hit;
    u16 species;
    u32 touchX;
    u32 touchY;
    u32 formNo;
    u32 gender;
    u32 shiny;
    void *zukanSave;
    hit = 0;
    if (voice->inputEnabled != 0) {
        if (KEY_GetTrg() & 1) {
            UI_SetInputMode(0);
            hit = 1;
        } else if (TOUCHPANEL_GetPointTrg(&touchX, &touchY) != 0) {
            if (touchX < 0x100 && touchY < 0xa8) {
                hit = 1;
                UI_SetInputMode(1);
            }
        }
    }
    if (hit != 0) {
        zukanSave = ZUKAN_SAVE_GetFromGameData(ZUKAN_DETAIL_COMMON_GetSource(ctx));
        species = ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx);
        ZUKAN_SAVE_GetViewGenderAndForm(zukanSave, species, &gender, &shiny, &formNo, *heapIdPtr);
        voice->voiceHandle = PM_VOICE_Play(species, formNo, 0x40, 0, 0, 0, 0, 0);
        voice->elapsedMs = 0;
        *(u64 *)&voice->startTick[0] = OS_GetTick();
        voice->voicePlaying = 1;
        ZUKAN_DETAIL_VOICE_DrawWaveform(heapIdPtr, voice, ctx, species, formNo);
        ZUKAN_DETAIL_VOICE_ResetPokemonTransform(heapIdPtr, voice, ctx);
    }
}

void ZUKAN_DETAIL_VOICE_CreateWaveformWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    voice->waveTileMap = GFL_HEAP_Alloc(*heapIdPtr, 0x3a2, 1, data_021C8E28, 0x8a1);
    voice->waveWin = (struct Descriptor *)BMP_WIN_Create(3, 1, 2, 31, 15, 1, 1);
    ZUKAN_DETAIL_VOICE_InitWaveformState(heapIdPtr, voice, ctx);
    voice->waveBmp = BMP_Create(121, 15, 32, *heapIdPtr);
}

/*
 * Releases the waveform bitmap, the waveform window and the tile map.
 */
void ZUKAN_DETAIL_VOICE_DeleteWaveformWindow(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    BMP_Delete((struct Bmp *)voice->waveBmp);
    BMP_WIN_Delete(voice->waveWin);
    GFL_HEAP_Free(voice->waveTileMap);
}

void ZUKAN_DETAIL_VOICE_UpdateWaveformDelay(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    if (voice->waveDelay != 0) {
        voice->waveDelay--;
        return;
    }
    ZUKAN_DETAIL_VOICE_ScrollWaveform(heapIdPtr, voice, ctx);
    voice->waveDelay = 0;
}

void ZUKAN_DETAIL_VOICE_InitWaveformState(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    struct Bmp *bmp;
    voice->waveDelay = 0;
    voice->scrollSubPixels = 0;
    voice->scrollColumn = 0;
    voice->shownSpecies = 0;
    voice->shownForm = 0;
    voice->waveWidth = 0;
    voice->waveCopied = voice->waveWidth;
    voice->voiceLengthMs = 0;
    bmp = BMP_WIN_GetBmp(voice->waveWin);
    BMP_Clear((struct CharBuf *)bmp, 0);
    BMP_FillRect(bmp, 0, 0x37, 0xee, 1, 0xf);
    ZUKAN_DETAIL_VOICE_UpdateWaveformTiles(heapIdPtr, voice, ctx);
}

void ZUKAN_DETAIL_VOICE_ScrollWaveform(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    s16 *copiedPtr;
    struct Bmp *bmp;
    s16 x;
    s16 *subPixelsPtr;
    s16 drawn;
    bmp = BMP_WIN_GetBmp(voice->waveWin);
    x = (s16)(((s16)(voice->scrollSubPixels + (voice->scrollColumn << 3)) + 0xee) % 0xf8);
    drawn = 0;
    subPixelsPtr = &voice->scrollSubPixels;
    voice->scrollSubPixels = *subPixelsPtr + 2;
    while (voice->scrollSubPixels >= 8) {
        BMP_FillRect(bmp, (s16)(voice->scrollColumn << 3), 0, 8, 0x78, 0);
        voice->scrollColumn = (voice->scrollColumn + 1) % 0x1f;
        *subPixelsPtr = *subPixelsPtr - 8;
    }
    if (voice->scrollSubPixels > 0)
        BMP_FillRect(bmp, (s16)(voice->scrollColumn << 3), 0, (u16)voice->scrollSubPixels, 0x78, 0);
    copiedPtr = &voice->waveCopied;
    while (drawn < 2) {
        s16 end;
        s16 remaining;
        int width;
        remaining = voice->waveWidth - voice->waveCopied;
        end = (s16)(x + 2 - drawn);
        if (remaining <= 0)
            break;
        if (end > 0xf8)
            end = 0xf8;
        if (end - x > remaining)
            end = (s16)(x + remaining);
        width = end - x;
        BMP_Blit(voice->waveBmp, bmp, voice->waveCopied, 0, x, 0, width, 0x78, 0xffff);
        drawn = (s16)(drawn + (s16)width);
        x = (s16)(end % 0xf8);
        *copiedPtr = *copiedPtr + drawn;
    }
    while (drawn < 2) {
        s16 end;
        int width;
        end = (s16)(x + 2 - drawn);
        if (end > 0xf8)
            end = 0xf8;
        width = end - x;
        BMP_FillRect(bmp, x, 0x37, (u16)width, 1, 0xf);
        drawn = (s16)(drawn + (s16)width);
        x = (s16)(end % 0xf8);
    }
    ZUKAN_DETAIL_VOICE_UpdateWaveformTiles(heapIdPtr, voice, ctx);
}

void ZUKAN_DETAIL_VOICE_DrawWaveform(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx, u16 species, u16 form)
{
    u32 sampleRate;
    u32 frequency;
    u32 column;
    u32 sample;
    u32 end;
    int lo;
    int hi;
    int amplitude;
    s16 level;
    int scaled;
    voice->voiceData = (s8 *)PM_VOICE_GetData(voice->voiceHandle);
    voice->waveCopied = 0;
    if (species == voice->shownSpecies && form == voice->shownForm)
        return;
    voice->shownSpecies = species;
    voice->shownForm = form;
    sampleRate = PM_VOICE_GetSampleRate(voice->voiceHandle);
    frequency = PM_VOICE_GetFrequency(voice->voiceHandle);
    voice->voiceLengthMs = (u32)(1000.0f * (32768.0f * (float)PM_VOICE_GetDataSize(voice->voiceHandle)
                                           / (float)(int)sampleRate
                                           / (float)(int)frequency) + 0.5f);
    BMP_Clear((struct CharBuf *)voice->waveBmp, 0);
    column = 0;
    sample = 0;
    while (sample < PM_VOICE_GetDataSize(voice->voiceHandle)) {
        frequency = PM_VOICE_GetFrequency(voice->voiceHandle);
        sampleRate = PM_VOICE_GetSampleRate(voice->voiceHandle);
        end = (u32)((float)(column + 1) * ((float)(int)sampleRate * (float)(int)frequency / 32768.0f / 60.0f / 2.0f));
        if (end > PM_VOICE_GetDataSize(voice->voiceHandle))
            end = PM_VOICE_GetDataSize(voice->voiceHandle);
        if (column < 0x3c0) {
            lo = 500;
            hi = -500;
            for (; sample < end; sample++) {
                scaled = voice->voiceData[sample] * 0x2f * PM_VOICE_GetVolume(voice->voiceHandle) / 128;
                amplitude = (s16)(scaled / 128);
                if (amplitude > 500)
                    amplitude = 500;
                else if (amplitude < -500)
                    amplitude = -500;
                level = amplitude;
                if (level < lo)
                    lo = level;
                if (level > hi)
                    hi = level;
            }
            if (lo <= hi) {
                if (lo < -55)
                    lo = -55;
                if (hi > 0x37)
                    hi = 0x37;
                BMP_FillRect(voice->waveBmp, (s16)column, (s16)(0x37 - hi), 1, (u16)(hi - lo + 1), 0xf);
            }
        }
        column++;
        sample = end + 1;
    }
    if (column > 0x3c0)
        column = 0x3c0;
    voice->waveWidth = column;
}

void ZUKAN_DETAIL_VOICE_UpdateWaveformTiles(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    u16 tile;
    u16 row;
    u16 index;
    u16 col;
    int base;
    tile = BMP_WIN_GetCharOffset(voice->waveWin);
    index = 0;
    for (row = 0; row < 15; row++) {
        base = tile + row * 31;
        for (col = 0; col < 31; col++) {
            voice->waveTileMap[index] = (u16)(base + (col + voice->scrollColumn) % 31) | 0x1000;
            index++;
        }
    }
    BG_SYS_DrawTile(3, (u32)voice->waveTileMap, 1, 2, 31, 15);
    voice->waveBgDirty = 1;
    BMP_WIN_TransferChars(voice->waveWin);
}

void ZUKAN_DETAIL_VOICE_SetActorsNormalMode(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (voice->pokemonActor[i])
            CLACT_SetActorObjMode(voice->pokemonActor[i], 0);
    }
    for (i = 0; i < 6; i++)
        CLACT_SetActorObjMode(voice->actor[i], 0);
    G2x_SetBlendAlpha_(0x04000050, 4, 0x3f, 0x10, 8);
    G2x_SetBlendAlpha_(0x04001050, 0, 0x3f, 0xc, 4);
}

void ZUKAN_DETAIL_VOICE_SetActorsAlphaMode(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (voice->pokemonActor[i])
            CLACT_SetActorObjMode(voice->pokemonActor[i], 1);
    }
    for (i = 0; i < 6; i++)
        CLACT_SetActorObjMode(voice->actor[i], 1);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(voice->blendTop);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(voice->blendBottom);
}
