/*
 * file:     field_place_name.c
 * unit:     yes
 * function: FIELD_PLACE_NAME_Create, FIELD_PLACE_NAME_Delete, FIELD_PLACE_NAME_Main, FIELD_PLACE_NAME_Draw, FIELD_PLACE_NAME_OnZoneChange, FIELD_PLACE_NAME_ShowForZone, FIELD_PLACE_NAME_ForceShowForZone, FIELD_PLACE_NAME_Cancel, FIELD_PLACE_NAME_RestoreWindow, FIELD_PLACE_NAME_SetupWindow, FIELD_PLACE_NAME_ReleaseWindow, FIELD_PLACE_NAME_ResetWindow, FIELD_PLACE_NAME_LoadPaletteFile, FIELD_PLACE_NAME_FreePaletteFile, FIELD_PLACE_NAME_TransferPalette, FIELD_PLACE_NAME_AllocBgChars, FIELD_PLACE_NAME_FreeBgChars, FIELD_PLACE_NAME_ClearWindow, FIELD_PLACE_NAME_CreateClactRenderer, FIELD_PLACE_NAME_DeleteClactRenderer, FIELD_PLACE_NAME_RegisterClactPalette, FIELD_PLACE_NAME_ReleaseClactPalette, FIELD_PLACE_NAME_CreateClactUnit, FIELD_PLACE_NAME_DeleteClactUnit, FIELD_PLACE_NAME_SetClactUnitRenderer, FIELD_PLACE_NAME_CreateLetters, FIELD_PLACE_NAME_DeleteLetters, FIELD_PLACE_NAME_CreateArcHandle, FIELD_PLACE_NAME_DeleteArcHandle, FIELD_PLACE_NAME_ResetSpawnCounts, FIELD_PLACE_NAME_SpawnNextLetter, FIELD_PLACE_NAME_IsAllSpawned, FIELD_PLACE_NAME_HideLetters, FIELD_PLACE_NAME_LaunchNextLetter, FIELD_PLACE_NAME_UpdateLetters, FIELD_PLACE_NAME_CreateBmpOamSys, FIELD_PLACE_NAME_DeleteBmpOamSys, FIELD_PLACE_NAME_ResetBlitCount, FIELD_PLACE_NAME_BlitNextLetter, FIELD_PLACE_NAME_IsAllBlitted, FIELD_PLACE_NAME_RequestForceShow, FIELD_PLACE_NAME_ClearForceShowRequest, FIELD_PLACE_NAME_GetZoneChangeRequest, FIELD_PLACE_NAME_SetZoneChangeRequest, FIELD_PLACE_NAME_ClearZoneChangeRequest, FIELD_PLACE_NAME_GetForceShowRequest, FIELD_PLACE_NAME_HasPlaceNameChanged, FIELD_PLACE_NAME_LoadMessage, FIELD_PLACE_NAME_UsesIntrudeTemplate, FIELD_PLACE_NAME_SetState, FIELD_PLACE_NAME_Interrupt, FIELD_PLACE_NAME_StateIdle, FIELD_PLACE_NAME_StatePrepare, FIELD_PLACE_NAME_StateFadeIn, FIELD_PLACE_NAME_StateFadeInWait, FIELD_PLACE_NAME_StateLettersLaunch, FIELD_PLACE_NAME_StateLettersLand, FIELD_PLACE_NAME_StateFadeOut, FIELD_PLACE_NAME_DrawIdle, FIELD_PLACE_NAME_DrawPrepare, FIELD_PLACE_NAME_DrawFadeIn, FIELD_PLACE_NAME_DrawFadeInWait, FIELD_PLACE_NAME_DrawLettersLaunch, FIELD_PLACE_NAME_DrawLettersLand, FIELD_PLACE_NAME_DrawFadeOut, FIELD_PLACE_NAME_AllocWork, FIELD_PLACE_NAME_InitWork, FIELD_PLACE_NAME_FreeWork, FIELD_PLACE_NAME_CreateWordSet, FIELD_PLACE_NAME_CreateMsgData, FIELD_PLACE_NAME_CreateMessage, FIELD_PLACE_NAME_CreateBmpWin, FIELD_PLACE_NAME_DeleteWordSet, FIELD_PLACE_NAME_DeleteMsgData, FIELD_PLACE_NAME_DeleteMessage, FIELD_PLACE_NAME_DeleteBmpWin, FIELD_PLACE_NAME_GetHeapId, FIELD_PLACE_NAME_GetArcHandle, FIELD_PLACE_NAME_SetHeapId, FIELD_PLACE_NAME_SetFont, FIELD_PLACE_NAME_SetStateRaw, FIELD_PLACE_NAME_GetState, FIELD_PLACE_NAME_ResetFrame, FIELD_PLACE_NAME_IncrementFrame, FIELD_PLACE_NAME_GetStep, FIELD_PLACE_NAME_ResetStep, FIELD_PLACE_NAME_IncrementStep, FIELD_PLACE_NAME_LoadZoneFromSave, FIELD_PLACE_NAME_SaveZoneToSave, FIELD_PLACE_NAME_GetZoneId, FIELD_PLACE_NAME_SetZoneId, FIELD_PLACE_NAME_GetMessage, FIELD_PLACE_NAME_GetMessageLength, FIELD_PLACE_NAME_HasWindow
 * address:  0x021BC388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_place_name.c at 0x021BC388 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   gFieldPlaceNameRendererParam     0x021D9B78  data  a4
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   GF_FONT_GetCharWidth   0x0201DC6C  thumb
 *   gPlaceNameLetterDefaultParam     0x021D9B88  data  a4
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Blit  0x020439A0  arm
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotFromMsg59  0x0201F158  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_GetLength  0x020458F8  arm
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   FIELD_STATUS_GetMapMode  0x0201444C  thumb
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   BG_SYS_InitSlot  0x020414C4  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   gFieldPlaceNameFileName     0x021DE354  data  a4
 *   MI_CpuFill8  0x02082BCC  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_02008998  0x02008998  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_020089A0  0x020089A0  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   STRBUF_Create  0x020457B0  arm
 *   PLACE_NAME_LETTER_Create 0x021BD148 thumb ov021
 *   PLACE_NAME_LETTER_Delete 0x021BD184 thumb ov021
 *   PLACE_NAME_LETTER_Setup 0x021BD19C thumb ov021
 *   PLACE_NAME_LETTER_Update 0x021BD1CC thumb ov021
 *   PLACE_NAME_LETTER_Start 0x021BD1D4 thumb ov021
 *   PLACE_NAME_LETTER_GetBmp 0x021BD1DC thumb ov021
 *   PLACE_NAME_LETTER_SetVisible 0x021BD1E4 thumb ov021
 *   PLACE_NAME_LETTER_GetWidth 0x021BD1EC thumb ov021
 *   PLACE_NAME_LETTER_GetHeight 0x021BD1F4 thumb ov021
 *   PLACE_NAME_LETTER_GetX 0x021BD1FC thumb ov021
 *   PLACE_NAME_LETTER_GetY 0x021BD204 thumb ov021
 *   PLACE_NAME_LETTER_IsActive 0x021BD20C thumb ov021
 *   BMP_OAM_CreateSys  0x02025538  thumb  arm9
 *   BMP_OAM_DeleteSys  0x02025588  thumb  arm9
 *   BMP_WIN_Create  0x020450F0  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_CreateRenderer  0x0204B034  arm  arm9
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 *   ZONEDATA_GetPlaceNameWindow  0x02013E6C  thumb  arm9
 *   CLACT_SetUnitDrawEnable  0x0204B22C  arm  arm9
 *   CLACT_SetUnitRenderer  0x0204B258  arm  arm9
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 *   BG_SYS_CreateRun  0x0203FA08  arm  arm9
 *   BG_SYS_DeleteHalf  0x0203FB44  arm  arm9
 *   BG_SYS_LoadPltt  0x02040E78  arm  arm9
 *   BG_SYS_FreeSlot  0x020414AC  arm  arm9
 *   MSGDATA_CreateFromArchive  0x02045B38  arm  arm9
 *   ARC_TOOL_CreateHandle  0x020490F4  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#include "field_place_name_types.h"

typedef struct GameSystem GameSystem;
typedef struct GameData GameData;
typedef struct WordSet WordSet;
typedef struct ArcFile ArcFile;
typedef struct MsgData MsgData;
typedef struct GfFont GfFont;
typedef struct Strbuf Strbuf;
typedef struct BmpWin BmpWin;
typedef struct Bmp Bmp;
typedef struct BmpOamSys BmpOamSys;
typedef struct ClactUnit ClactUnit;
typedef struct ClactRenderer ClactRenderer;
typedef struct NitroFileHeader NitroFileHeader;
struct BgTemplate;
struct FieldMsgContext;

#define REG_BLDCNT_ADDR 0x04000050
/* Address of the BG3 template table in the overlay data (a symbol here changes the literal pool relocation). */
#define FIELD_PLACE_NAME_BG_TEMPLATE_ADDR 0x021DE334

#define FIELD_PLACE_NAME_BG_LAYER 3
#define FIELD_PLACE_NAME_MAX_MESSAGE_CHARS 32
#define FIELD_PLACE_NAME_PLACE_COUNT 0x75
#define FIELD_PLACE_NAME_FADE_IN_FRAMES 10
#define FIELD_PLACE_NAME_FADE_OUT_FRAMES 20
#define FIELD_PLACE_NAME_LETTER_INTERVAL 3
#define FIELD_PLACE_NAME_HOLD_FRAMES 30

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short line);
extern u32 GFL_HEAP_Free(void *p);
extern GfFont *FIELD_MSGBG_GetFont(struct FieldMsgContext *msgContext);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeLayerBuf(u32 bgId);
extern void BMP_WIN_TransferChars(BmpWin *bmpWin);
extern void BMP_WIN_MakeScreen(BmpWin *bmpWin);
extern unsigned char BMP_WIN_GetBgLayer(BmpWin *bmpWin);
extern void BG_SYS_PushTile(unsigned int bgLayer);
extern void BG_SYS_SetVisibleLayer(int bgId, unsigned short priority);
extern void BG_SYS_SetPlaneVisible(unsigned char bgId, unsigned char enable);
extern void G2x_SetBlendAlpha_(int regAddr, int plane1, int plane2, int evA, int evB);
extern void BG_SYS_FreeSlot(int bgId);
extern u32 ARC_TOOL_GetHandleMemberSize(ArcFile *arc, u32 member);
extern void ARC_TOOL_ReadHandleMember(ArcFile *arc, u32 member, void *dst);
extern s32 NNS_G2dGetUnpackedPaletteData(NitroFileHeader *file, void **out);
extern void BG_SYS_LoadPltt(u32 bgId, void *src, u32 size, u32 offset);
extern u32 BG_SYS_CreateRun(u32 bgId, u32 size, u32 top);
extern void BG_SYS_DeleteHalf(u32 bgId, u32 offset, u32 size);
extern Bmp *BMP_WIN_GetBmp(BmpWin *bmpWin);
extern void BMP_Clear(Bmp *bmp, u8 value);
extern ClactRenderer *CLACT_CreateRenderer(const u8 *initParam, u32 count, u32 heapId);
extern void CLACT_DeleteRenderer(ClactRenderer *renderer);
extern s32 CLACT_RegisterPaletteEx(ArcFile *arc, u32 type, u32 index, u32 size, u16 plane, u16 compress, u16 heapId);
extern void CLACT_ReleasePalette(u32 paletteId);
extern ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDrawEnable(ClactUnit *unit, u32 mode);
extern u32 CLACT_DeleteUnit(ClactUnit *unit);
extern void CLACT_SetUnitRenderer(ClactUnit *unit, ClactRenderer *renderer);
extern ArcFile *ARC_TOOL_CreateHandle(u32 arcId, u32 heapId);
extern void ARC_TOOL_DeleteHandle(ArcFile *arc);
extern void STRBUF_ToChars(Strbuf *strbuf, u16 *out, u32 count);
extern u32 GF_FONT_GetCharWidth(GfFont *font, u16 ch);
extern BmpOamSys *BMP_OAM_CreateSys(unsigned int heapId, ClactUnit *unit);
extern void BMP_OAM_DeleteSys(BmpOamSys *sys);
extern void BMP_Blit(Bmp *dst, Bmp *src, u32 x, u32 y, int srcX, int srcY, u32 w, u32 h, u32 key);
extern u32 ZONEDATA_GetPlaceNameId(u32 zoneId);
extern unsigned int ICA_ANIME_GetField24(const GameSystem *gameSystem);
extern int INTRUDE_COMM_GetWorkIfRunning(int gameComm);
extern int GAME_DATA_GetIntrudeIdByte(GameData *gameData);
extern int GAME_DATA_GetMyStatusByNetId(GameData *gameData, int netId);
extern Strbuf *MSGDATA_AllocString(MsgData *msgData, u32 index);
extern void func_02045CAC(MsgData *msgData, u32 index, Strbuf *dst);
extern void WORDSET_SetSlotMyStatus(WordSet *wordSet, u32 index, void *myStatus);
extern void WORDSET_SetSlotFromMsg59(WordSet *wordSet, u32 index, u32 value);
extern void WORDSET_CopyTaggedText(WordSet *wordSet, Strbuf *dst, Strbuf *src);
extern void STRBUF_Delete(Strbuf *strbuf);
extern u16 STRBUF_GetLength(Strbuf *strbuf);
extern void *GAME_DATA_GetMoveModelSys(const GameData *gameData);
extern u8 GAME_DATA_GetOwnNetId(const GameData *gameData);
extern unsigned int FIELD_STATUS_GetMapMode(void *fieldStatus);
extern u32 ZONEDATA_IsZone117(u32 zoneId);
extern void BG_SYS_InitSlot(u32 bgId);
extern void BG_SYS_ClearSlot(u32 bgId);
extern void MI_CpuFill8(void *dst, int value, int size);
extern void *ICA_ANIME_GetField1C(const GameSystem *gameSystem);
extern WordSet *WORDSET_CreateDefault(u32 heapId);
extern MsgData *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern BmpWin *BMP_WIN_Create(u32 bgId, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 WORDSET_DeleteStrbufED04(WordSet *wordSet);
extern u32 MSGDATA_Delete(MsgData *msgData);
extern u32 BMP_WIN_Delete(BmpWin *bmpWin);
extern void *GAME_DATA_GetSaveControl(GameData *gameData);
extern void *func_02008854(void *saveControl);
extern u16 func_02008998(const void *location);
extern u32 func_020089A0(u32 location, u32 zoneId);
extern u32 ZONEDATA_GetPlaceNameWindow(u32 zoneId);
extern const u8 gFieldPlaceNameRendererParam[16];
extern const PlaceNameLetterParam gPlaceNameLetterDefaultParam;
extern u8 gFieldPlaceNameFileName[20];

FieldPlaceName *FIELD_PLACE_NAME_Create(GameSystem *gameSystem, u32 heapId, struct FieldMsgContext *msgContext);
void FIELD_PLACE_NAME_Delete(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_Main(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_Draw(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_OnZoneChange(FieldPlaceName *placeName, int zoneId);
void FIELD_PLACE_NAME_ShowForZone(FieldPlaceName *placeName, int zoneId);
void FIELD_PLACE_NAME_ForceShowForZone(FieldPlaceName *placeName, int zoneId);
int FIELD_PLACE_NAME_Cancel(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_RestoreWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetupWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ReleaseWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_LoadPaletteFile(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_FreePaletteFile(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_TransferPalette(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_AllocBgChars(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_FreeBgChars(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ClearWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateClactRenderer(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteClactRenderer(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_RegisterClactPalette(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ReleaseClactPalette(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateClactUnit(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteClactUnit(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetClactUnitRenderer(FieldPlaceName *placeName, int unitIndex);
void FIELD_PLACE_NAME_CreateLetters(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteLetters(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateArcHandle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteArcHandle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetSpawnCounts(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SpawnNextLetter(FieldPlaceName *placeName);
int FIELD_PLACE_NAME_IsAllSpawned(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_HideLetters(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_LaunchNextLetter(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_UpdateLetters(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateBmpOamSys(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteBmpOamSys(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetBlitCount(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_BlitNextLetter(FieldPlaceName *placeName);
int FIELD_PLACE_NAME_IsAllBlitted(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_RequestForceShow(FieldPlaceName *placeName);
FieldPlaceName *FIELD_PLACE_NAME_ClearForceShowRequest(FieldPlaceName *placeName);
u32 FIELD_PLACE_NAME_GetZoneChangeRequest(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetZoneChangeRequest(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ClearZoneChangeRequest(FieldPlaceName *placeName);
u32 FIELD_PLACE_NAME_GetForceShowRequest(FieldPlaceName *placeName);
int FIELD_PLACE_NAME_HasPlaceNameChanged(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_LoadMessage(FieldPlaceName *placeName);
int FIELD_PLACE_NAME_UsesIntrudeTemplate(FieldPlaceName *placeName, int zoneId);
void FIELD_PLACE_NAME_SetState(FieldPlaceName *placeName, int newState);
void FIELD_PLACE_NAME_Interrupt(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateIdle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StatePrepare(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateFadeIn(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateFadeInWait(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateLettersLaunch(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateLettersLand(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateFadeOut(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawIdle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawPrepare(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawFadeIn(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawFadeInWait(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawLettersLaunch(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawLettersLand(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawFadeOut(FieldPlaceName *placeName);
FieldPlaceName *FIELD_PLACE_NAME_AllocWork(u32 heapId);
void FIELD_PLACE_NAME_InitWork(FieldPlaceName *placeName, GameSystem *gameSystem);
void FIELD_PLACE_NAME_FreeWork(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateWordSet(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateMsgData(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateMessage(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateBmpWin(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteWordSet(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteMsgData(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteMessage(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteBmpWin(FieldPlaceName *placeName);
u16 FIELD_PLACE_NAME_GetHeapId(FieldPlaceName *placeName);
ArcFile *FIELD_PLACE_NAME_GetArcHandle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetHeapId(FieldPlaceName *placeName, int heapId);
void FIELD_PLACE_NAME_SetFont(FieldPlaceName *placeName, GfFont *font);
void FIELD_PLACE_NAME_SetStateRaw(FieldPlaceName *placeName, int state);
u32 FIELD_PLACE_NAME_GetState(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetFrame(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_IncrementFrame(FieldPlaceName *placeName);
u8 FIELD_PLACE_NAME_GetStep(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetStep(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_IncrementStep(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_LoadZoneFromSave(FieldPlaceName *placeName);
int FIELD_PLACE_NAME_SaveZoneToSave(FieldPlaceName *placeName);
u16 FIELD_PLACE_NAME_GetZoneId(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetZoneId(FieldPlaceName *placeName, u16 zoneId);
Strbuf *FIELD_PLACE_NAME_GetMessage(FieldPlaceName *placeName);
u8 FIELD_PLACE_NAME_GetMessageLength(FieldPlaceName *placeName);
u32 FIELD_PLACE_NAME_HasWindow(u32 zoneId);
PlaceNameLetter *PLACE_NAME_LETTER_Create(u32 heapId, BmpOamSys *bmpOamSys, u16 space, int paletteId);
void PLACE_NAME_LETTER_Delete(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Setup(PlaceNameLetter *letter, const PlaceNameLetterParam *param);
void PLACE_NAME_LETTER_Update(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Start(PlaceNameLetter *letter);
Bmp *PLACE_NAME_LETTER_GetBmp(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetVisible(PlaceNameLetter *letter, unsigned int visible);
int PLACE_NAME_LETTER_GetWidth(PlaceNameLetter *letter);
int PLACE_NAME_LETTER_GetHeight(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetX(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetY(PlaceNameLetter *letter);
unsigned int PLACE_NAME_LETTER_IsActive(PlaceNameLetter *letter);

/* Creates the banner work and every part of it; msgContext supplies the font. */
FieldPlaceName *FIELD_PLACE_NAME_Create(GameSystem *gameSystem, u32 heapId, struct FieldMsgContext *msgContext)
{
    FieldPlaceName *placeName;

    placeName = FIELD_PLACE_NAME_AllocWork(heapId);
    FIELD_PLACE_NAME_InitWork(placeName, gameSystem);
    FIELD_PLACE_NAME_LoadZoneFromSave(placeName);
    FIELD_PLACE_NAME_CreateArcHandle(placeName);
    FIELD_PLACE_NAME_CreateWordSet(placeName);
    FIELD_PLACE_NAME_CreateMsgData(placeName);
    FIELD_PLACE_NAME_CreateMessage(placeName);
    FIELD_PLACE_NAME_SetHeapId(placeName, heapId);
    FIELD_PLACE_NAME_SetFont(placeName, FIELD_MSGBG_GetFont(msgContext));
    FIELD_PLACE_NAME_CreateClactRenderer(placeName);
    FIELD_PLACE_NAME_RegisterClactPalette(placeName);
    FIELD_PLACE_NAME_CreateClactUnit(placeName);
    FIELD_PLACE_NAME_SetClactUnitRenderer(placeName, 0);
    FIELD_PLACE_NAME_CreateBmpOamSys(placeName);
    FIELD_PLACE_NAME_CreateLetters(placeName);
    BG_SYS_InitBgLayer(FIELD_PLACE_NAME_BG_LAYER, (const struct BgTemplate *)FIELD_PLACE_NAME_BG_TEMPLATE_ADDR, 0);
    FIELD_PLACE_NAME_LoadPaletteFile(placeName);
    FIELD_PLACE_NAME_AllocBgChars(placeName);
    FIELD_PLACE_NAME_CreateBmpWin(placeName);
    FIELD_PLACE_NAME_SetState(placeName, FIELD_PLACE_NAME_STATE_IDLE);
    return placeName;
}

void FIELD_PLACE_NAME_Delete(FieldPlaceName *placeName)
{
    FIELD_PLACE_NAME_SaveZoneToSave(placeName);
    FIELD_PLACE_NAME_FreePaletteFile(placeName);
    FIELD_PLACE_NAME_DeleteLetters(placeName);
    FIELD_PLACE_NAME_DeleteMessage(placeName);
    FIELD_PLACE_NAME_DeleteBmpOamSys(placeName);
    FIELD_PLACE_NAME_DeleteClactUnit(placeName);
    FIELD_PLACE_NAME_ReleaseClactPalette(placeName);
    FIELD_PLACE_NAME_DeleteClactRenderer(placeName);
    FIELD_PLACE_NAME_DeleteWordSet(placeName);
    FIELD_PLACE_NAME_DeleteMsgData(placeName);
    FIELD_PLACE_NAME_DeleteBmpWin(placeName);
    FIELD_PLACE_NAME_FreeBgChars(placeName);
    FIELD_PLACE_NAME_DeleteArcHandle(placeName);
    BG_SYS_FreeLayerBuf(FIELD_PLACE_NAME_BG_LAYER);
    FIELD_PLACE_NAME_FreeWork(placeName);
}

/* Per-frame update: advances the frame counter, runs the state handler, then moves the letters. */
void FIELD_PLACE_NAME_Main(FieldPlaceName *placeName)
{
    FIELD_PLACE_NAME_IncrementFrame(placeName);
    switch (FIELD_PLACE_NAME_GetState(placeName)) {
    case FIELD_PLACE_NAME_STATE_IDLE:
        FIELD_PLACE_NAME_StateIdle(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_PREPARE:
        FIELD_PLACE_NAME_StatePrepare(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN:
        FIELD_PLACE_NAME_StateFadeIn(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN_WAIT:
        FIELD_PLACE_NAME_StateFadeInWait(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_LETTERS_LAUNCH:
        FIELD_PLACE_NAME_StateLettersLaunch(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_LETTERS_LAND:
        FIELD_PLACE_NAME_StateLettersLand(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_OUT:
        FIELD_PLACE_NAME_StateFadeOut(placeName);
        break;
    }
    FIELD_PLACE_NAME_UpdateLetters(placeName);
}

/* Per-frame draw: the hardware blend of the plate follows the state. */
void FIELD_PLACE_NAME_Draw(FieldPlaceName *placeName)
{
    switch (FIELD_PLACE_NAME_GetState(placeName)) {
    case FIELD_PLACE_NAME_STATE_IDLE:
        FIELD_PLACE_NAME_DrawIdle(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_PREPARE:
        FIELD_PLACE_NAME_DrawPrepare(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN:
        FIELD_PLACE_NAME_DrawFadeIn(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN_WAIT:
        FIELD_PLACE_NAME_DrawFadeInWait(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_LETTERS_LAUNCH:
        FIELD_PLACE_NAME_DrawLettersLaunch(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_LETTERS_LAND:
        FIELD_PLACE_NAME_DrawLettersLand(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_OUT:
        FIELD_PLACE_NAME_DrawFadeOut(placeName);
        break;
    }
}

/* Zone change: shows the banner when the new zone has a place name window and its place name differs. */
void FIELD_PLACE_NAME_OnZoneChange(FieldPlaceName *placeName, int zoneId)
{
    FIELD_PLACE_NAME_SetZoneId(placeName, (u16)zoneId);
    if (FIELD_PLACE_NAME_HasWindow((u16)zoneId)) {
        FIELD_PLACE_NAME_Interrupt(placeName);
        FIELD_PLACE_NAME_SetZoneChangeRequest(placeName);
    }
}

/* Zone change: shows the banner whenever the new zone has a place name window. */
void FIELD_PLACE_NAME_ShowForZone(FieldPlaceName *placeName, int zoneId)
{
    FIELD_PLACE_NAME_SetZoneId(placeName, (u16)zoneId);
    if (FIELD_PLACE_NAME_HasWindow((u16)zoneId)) {
        FIELD_PLACE_NAME_Interrupt(placeName);
        FIELD_PLACE_NAME_RequestForceShow(placeName);
    }
}

/* Zone change: shows the banner in every case. */
void FIELD_PLACE_NAME_ForceShowForZone(FieldPlaceName *placeName, int zoneId)
{
    FIELD_PLACE_NAME_SetZoneId(placeName, (u16)zoneId);
    FIELD_PLACE_NAME_Interrupt(placeName);
    FIELD_PLACE_NAME_RequestForceShow(placeName);
}

/* Stops the banner now and drops pending show requests. */
int FIELD_PLACE_NAME_Cancel(FieldPlaceName *placeName)
{
    FIELD_PLACE_NAME_SetState(placeName, FIELD_PLACE_NAME_STATE_IDLE);
    FIELD_PLACE_NAME_ClearZoneChangeRequest(placeName);
    return (int)FIELD_PLACE_NAME_ClearForceShowRequest(placeName);
}

/* Rebuilds the BG window (used after another screen took the BG layer). */
void FIELD_PLACE_NAME_RestoreWindow(FieldPlaceName *placeName)
{
    FIELD_PLACE_NAME_ResetWindow(placeName);
    FIELD_PLACE_NAME_ClearWindow(placeName);
}

/* Sets up the BG window: palette, char area, window bitmap, blend registers. */
void FIELD_PLACE_NAME_SetupWindow(FieldPlaceName *placeName)
{
    BmpWin *bmpWin;

    FIELD_PLACE_NAME_TransferPalette(placeName);
    FIELD_PLACE_NAME_AllocBgChars(placeName);
    FIELD_PLACE_NAME_CreateBmpWin(placeName);
    bmpWin = placeName->bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmpWin));
    BG_SYS_SetVisibleLayer(FIELD_PLACE_NAME_BG_LAYER, 1);
    BG_SYS_SetPlaneVisible(FIELD_PLACE_NAME_BG_LAYER, 0);
    G2x_SetBlendAlpha_(REG_BLDCNT_ADDR, 8, 0x11, 0x10, 4);
}

/* Releases the BG window resources. */
void FIELD_PLACE_NAME_ReleaseWindow(FieldPlaceName *placeName)
{
    BG_SYS_FreeSlot(FIELD_PLACE_NAME_BG_LAYER);
    FIELD_PLACE_NAME_FreeBgChars(placeName);
    FIELD_PLACE_NAME_DeleteBmpWin(placeName);
}

void FIELD_PLACE_NAME_ResetWindow(FieldPlaceName *placeName)
{
    FIELD_PLACE_NAME_ReleaseWindow(placeName);
    FIELD_PLACE_NAME_SetupWindow(placeName);
}

/* Loads the palette file (archive member 1) and unpacks it. */
void FIELD_PLACE_NAME_LoadPaletteFile(FieldPlaceName *placeName)
{
    int heapId;
    ArcFile *arcHandle;
    NitroFileHeader *file;

    heapId = FIELD_PLACE_NAME_GetHeapId(placeName);
    arcHandle = FIELD_PLACE_NAME_GetArcHandle(placeName);
    file = (NitroFileHeader *)GFL_HEAP_Alloc(heapId, ARC_TOOL_GetHandleMemberSize(arcHandle, 1), 0, (const char *)gFieldPlaceNameFileName, 0x2c8);
    placeName->paletteFile = file;
    ARC_TOOL_ReadHandleMember(arcHandle, 1, file);
    NNS_G2dGetUnpackedPaletteData(placeName->paletteFile, (void **)&placeName->paletteBlock);
}

void FIELD_PLACE_NAME_FreePaletteFile(FieldPlaceName *placeName)
{
    if (placeName->paletteFile != 0) {
        GFL_HEAP_Free(placeName->paletteFile);
        placeName->paletteFile = 0;
        placeName->paletteBlock = 0;
    }
}

/* Transfers the plate palette to the BG layer. */
void FIELD_PLACE_NAME_TransferPalette(FieldPlaceName *placeName)
{
    BG_SYS_LoadPltt(FIELD_PLACE_NAME_BG_LAYER, placeName->paletteBlock->colors, 0x20, 0);
}

void FIELD_PLACE_NAME_AllocBgChars(FieldPlaceName *placeName)
{
    if (placeName->bgCharOffset == FIELD_PLACE_NAME_NO_CHAR_OFFSET) {
        placeName->bgCharOffset = BG_SYS_CreateRun(FIELD_PLACE_NAME_BG_LAYER, 0x20, 0);
    }
}

void FIELD_PLACE_NAME_FreeBgChars(FieldPlaceName *placeName)
{
    if (placeName->bgCharOffset != FIELD_PLACE_NAME_NO_CHAR_OFFSET) {
        BG_SYS_DeleteHalf(FIELD_PLACE_NAME_BG_LAYER, placeName->bgCharOffset, 0x20);
        placeName->bgCharOffset = FIELD_PLACE_NAME_NO_CHAR_OFFSET;
    }
}

/* Clears the window bitmap. */
void FIELD_PLACE_NAME_ClearWindow(FieldPlaceName *placeName)
{
    BMP_Clear(BMP_WIN_GetBmp(placeName->bmpWin), 3);
}

void FIELD_PLACE_NAME_CreateClactRenderer(FieldPlaceName *placeName)
{
    placeName->clactRenderer = CLACT_CreateRenderer(gFieldPlaceNameRendererParam, 1, placeName->heapId);
}

void FIELD_PLACE_NAME_DeleteClactRenderer(FieldPlaceName *placeName)
{
    ClactRenderer *renderer = placeName->clactRenderer;
    if (renderer != 0) {
        CLACT_DeleteRenderer(renderer);
        placeName->clactRenderer = 0;
    }
}

void FIELD_PLACE_NAME_RegisterClactPalette(FieldPlaceName *placeName)
{
    u16 heapId = FIELD_PLACE_NAME_GetHeapId(placeName);
    ArcFile *arcHandle = FIELD_PLACE_NAME_GetArcHandle(placeName);
    placeName->clactPaletteId = CLACT_RegisterPaletteEx(arcHandle, 3, 0, 0x20, 0, 1, heapId);
}

void FIELD_PLACE_NAME_ReleaseClactPalette(FieldPlaceName *placeName)
{
    CLACT_ReleasePalette(placeName->clactPaletteId);
}

void FIELD_PLACE_NAME_CreateClactUnit(FieldPlaceName *placeName)
{
    placeName->clactUnit[0] = CLACT_CreateUnit(FIELD_PLACE_NAME_MAX_LETTERS, 1, FIELD_PLACE_NAME_GetHeapId(placeName));
    CLACT_SetUnitDrawEnable(placeName->clactUnit[0], 1);
}

void FIELD_PLACE_NAME_DeleteClactUnit(FieldPlaceName *placeName)
{
    CLACT_DeleteUnit(placeName->clactUnit[0]);
}

void FIELD_PLACE_NAME_SetClactUnitRenderer(FieldPlaceName *placeName, int unitIndex)
{
    if (placeName->clactRenderer != 0) {
        CLACT_SetUnitRenderer(placeName->clactUnit[unitIndex], placeName->clactRenderer);
    }
}

void FIELD_PLACE_NAME_CreateLetters(FieldPlaceName *placeName)
{
    int i;
    for (i = 0; i < FIELD_PLACE_NAME_MAX_LETTERS; i++) {
        placeName->letters[i] = PLACE_NAME_LETTER_Create(placeName->heapId, placeName->bmpOamSys, 0, placeName->clactPaletteId);
    }
}

void FIELD_PLACE_NAME_DeleteLetters(FieldPlaceName *placeName)
{
    int i;
    for (i = 0; i < FIELD_PLACE_NAME_MAX_LETTERS; i++) {
        PLACE_NAME_LETTER_Delete(placeName->letters[i]);
    }
}

void FIELD_PLACE_NAME_CreateArcHandle(FieldPlaceName *placeName)
{
    placeName->arcHandle = ARC_TOOL_CreateHandle(0x54, FIELD_PLACE_NAME_GetHeapId(placeName));
}

void FIELD_PLACE_NAME_DeleteArcHandle(FieldPlaceName *placeName)
{
    ArcFile *arcHandle = placeName->arcHandle;
    if (arcHandle != 0) {
        ARC_TOOL_DeleteHandle(arcHandle);
        placeName->arcHandle = 0;
    }
}

/* Clears the spawned and skipped letter counters. */
void FIELD_PLACE_NAME_ResetSpawnCounts(FieldPlaceName *placeName)
{
    placeName->spawnedCount = 0;
    placeName->skippedSpaceCount = 0;
}

/*
 * Starts the next letter of the message. Its target x is the sum of the
 * widths of the letters before it (plus one pixel each); a space takes no
 * letter and counts as skipped.
 * The x accumulation is a compound add inside each if/else arm (the two arms
 * cross-jump into one shared `ldr x; _fadd; str x` tail), then `+= 1.0f`
 * after the join, which is why the original re-loads x it has just stored:
 * a single `x += w` after the if/else forwards the value instead.
 * The call argument is the assignment itself: `f(p->shownLetters[n] = v, &param)`
 * gives the `str r0, [r2, r1]` with the shownLetters base hoisted.
 */
void FIELD_PLACE_NAME_SpawnNextLetter(FieldPlaceName *placeName)
{
    int letterIndex;
    int i;
    u16 chars[FIELD_PLACE_NAME_MAX_MESSAGE_CHARS];
    PlaceNameLetterParam param;

    letterIndex = placeName->spawnedCount;
    STRBUF_ToChars(FIELD_PLACE_NAME_GetMessage(placeName), chars, FIELD_PLACE_NAME_MAX_MESSAGE_CHARS);
    param = gPlaceNameLetterDefaultParam;
    param.font = placeName->font;
    param.ch = chars[letterIndex];
    for (i = 0; i < letterIndex; i++) {
        if (placeName->shownLetters[i] == 0) {
            param.targetX += GF_FONT_GetCharWidth(placeName->font, 0x20);
        } else {
            param.targetX += PLACE_NAME_LETTER_GetWidth(placeName->shownLetters[i]);
        }
        param.targetX += 1.0f;
    }
    if (param.ch == 0x20) {
        placeName->shownLetters[letterIndex] = 0;
        placeName->skippedSpaceCount++;
    } else {
        PLACE_NAME_LETTER_Setup(placeName->shownLetters[letterIndex] = placeName->letters[letterIndex - placeName->skippedSpaceCount], &param);
    }
    placeName->spawnedCount++;
}

/* 1 when every character of the message has been started. */
int FIELD_PLACE_NAME_IsAllSpawned(FieldPlaceName *placeName)
{
    if (FIELD_PLACE_NAME_GetMessageLength(placeName) <= placeName->spawnedCount) {
        return 1;
    }
    return 0;
}

void FIELD_PLACE_NAME_HideLetters(FieldPlaceName *placeName)
{
    int i;
    for (i = 0; i < FIELD_PLACE_NAME_MAX_LETTERS; i++) {
        PLACE_NAME_LETTER_SetVisible(placeName->letters[i], 0);
    }
}

/* Starts the next shown letter flying and makes it visible. */
void FIELD_PLACE_NAME_LaunchNextLetter(FieldPlaceName *placeName)
{
    u8 i = placeName->launchedCount++;
    if (placeName->shownLetters[i] != 0) {
        PLACE_NAME_LETTER_Start(placeName->shownLetters[i]);
        PLACE_NAME_LETTER_SetVisible(placeName->shownLetters[i], 1);
    }
}

/* Moves every started letter. */
void FIELD_PLACE_NAME_UpdateLetters(FieldPlaceName *placeName)
{
    int count = FIELD_PLACE_NAME_GetMessageLength(placeName);
    int i;
    for (i = 0; i < count; i++) {
        if (placeName->shownLetters[i] != 0) {
            PLACE_NAME_LETTER_Update(placeName->shownLetters[i]);
        }
    }
}

void FIELD_PLACE_NAME_CreateBmpOamSys(FieldPlaceName *placeName)
{
    placeName->bmpOamSys = BMP_OAM_CreateSys(FIELD_PLACE_NAME_GetHeapId(placeName), placeName->clactUnit[0]);
}

void FIELD_PLACE_NAME_DeleteBmpOamSys(FieldPlaceName *placeName)
{
    if (placeName->bmpOamSys != 0) {
        BMP_OAM_DeleteSys(placeName->bmpOamSys);
        placeName->bmpOamSys = 0;
    }
}

void FIELD_PLACE_NAME_ResetBlitCount(FieldPlaceName *placeName)
{
    placeName->blittedCount = 0;
}

/* Copies the next shown letter's bitmap into the window bitmap at its final position. */
void FIELD_PLACE_NAME_BlitNextLetter(FieldPlaceName *placeName)
{
    PlaceNameLetter *letter;
    Bmp *letterBmp;
    Bmp *windowBmp;
    u16 srcX, srcY, width, height;

    letter = placeName->shownLetters[placeName->blittedCount];
    if (letter != 0) {
        letterBmp = PLACE_NAME_LETTER_GetBmp(letter);
        windowBmp = BMP_WIN_GetBmp(placeName->bmpWin);
        srcX = PLACE_NAME_LETTER_GetX(letter);
        srcY = PLACE_NAME_LETTER_GetY(letter) - 8;
        width = PLACE_NAME_LETTER_GetWidth(letter);
        height = PLACE_NAME_LETTER_GetHeight(letter);
        BMP_Blit(letterBmp, windowBmp, 0, 0, srcX, srcY, width, height, 0);
    }
    (placeName->blittedCount)++;
}

/* 1 when every letter of the message has been blitted. */
int FIELD_PLACE_NAME_IsAllBlitted(FieldPlaceName *placeName)
{
    if ((int)FIELD_PLACE_NAME_GetMessageLength(placeName) <= placeName->blittedCount) {
        return 1;
    }
    return 0;
}

void FIELD_PLACE_NAME_RequestForceShow(FieldPlaceName *placeName)
{
    placeName->forceShowRequested = 1;
}

FieldPlaceName *FIELD_PLACE_NAME_ClearForceShowRequest(FieldPlaceName *placeName)
{
    placeName->forceShowRequested = 0;
    return placeName;
}

u32 FIELD_PLACE_NAME_GetZoneChangeRequest(FieldPlaceName *placeName)
{
    return placeName->zoneChangeRequested;
}

void FIELD_PLACE_NAME_SetZoneChangeRequest(FieldPlaceName *placeName)
{
    placeName->zoneChangeRequested = 1;
}

void FIELD_PLACE_NAME_ClearZoneChangeRequest(FieldPlaceName *placeName)
{
    placeName->zoneChangeRequested = 0;
}

u32 FIELD_PLACE_NAME_GetForceShowRequest(FieldPlaceName *placeName)
{
    return placeName->forceShowRequested;
}

/* 1 when the previous and the current zone have different place names. */
int FIELD_PLACE_NAME_HasPlaceNameChanged(FieldPlaceName *placeName)
{
    int prevPlaceNameId = ZONEDATA_GetPlaceNameId(placeName->prevZoneId);
    if (prevPlaceNameId != ZONEDATA_GetPlaceNameId(placeName->zoneId)) {
        return 1;
    }
    return 0;
}

/*
 * Reads the message for the current zone's place name into the message buffer.
 * With a visitor in the Palace the message is a template that also names the
 * player. A zone without a place name cancels the banner.
 */
void FIELD_PLACE_NAME_LoadMessage(FieldPlaceName *placeName)
{
    int zoneId;
    int myStatus;
    unsigned int placeNameId;
    Strbuf *template;

    zoneId = FIELD_PLACE_NAME_GetZoneId(placeName);
    placeNameId = ZONEDATA_GetPlaceNameId((unsigned int)zoneId);
    if (placeNameId >= FIELD_PLACE_NAME_PLACE_COUNT) {
        placeNameId = 0;
    }
    if (placeNameId == 0) {
        FIELD_PLACE_NAME_Cancel(placeName);
        return;
    }
    if (FIELD_PLACE_NAME_UsesIntrudeTemplate(placeName, zoneId) != 0) {
        INTRUDE_COMM_GetWorkIfRunning((int)ICA_ANIME_GetField24(placeName->gameSystem));
        myStatus = GAME_DATA_GetMyStatusByNetId(placeName->gameData, GAME_DATA_GetIntrudeIdByte(placeName->gameData));
        template = MSGDATA_AllocString(placeName->msgData, 3);
        func_02045CAC(placeName->msgData, placeNameId, placeName->message);
        WORDSET_SetSlotMyStatus(placeName->wordSet, 0, (void *)myStatus);
        WORDSET_SetSlotFromMsg59(placeName->wordSet, 1, placeNameId);
        WORDSET_CopyTaggedText(placeName->wordSet, placeName->message, template);
        STRBUF_Delete(template);
    } else {
        func_02045CAC(placeName->msgData, placeNameId, placeName->message);
    }
    placeName->messageLength = STRBUF_GetLength(placeName->message);
}

/*
 * 1 when the banner must use the Palace template: a Palace connection is
 * running and either the map mode is 1 or the zone is zone 117 while the
 * player stands in another player's Palace.
 */
int FIELD_PLACE_NAME_UsesIntrudeTemplate(FieldPlaceName *placeName, int zoneId)
{
    int intrudeId;
    void *fieldStatus;
    int ownNetId;

    intrudeId = INTRUDE_COMM_GetWorkIfRunning((int)ICA_ANIME_GetField24(placeName->gameSystem));
    fieldStatus = GAME_DATA_GetMoveModelSys(placeName->gameData);
    ownNetId = GAME_DATA_GetOwnNetId(placeName->gameData);
    if (intrudeId != 0) {
        intrudeId = GAME_DATA_GetIntrudeIdByte(placeName->gameData);
        if (FIELD_STATUS_GetMapMode(fieldStatus) == 1) {
            return 1;
        }
        if (ZONEDATA_IsZone117(zoneId) != 0 && ownNetId != intrudeId) {
            return 1;
        }
    }
    return 0;
}

/* Enters a new state: resets step and frame; going idle also hides the plate and the letters. */
void FIELD_PLACE_NAME_SetState(FieldPlaceName *placeName, int newState)
{
    FIELD_PLACE_NAME_SetStateRaw(placeName, newState);
    FIELD_PLACE_NAME_ResetFrame(placeName);
    FIELD_PLACE_NAME_ResetStep(placeName);
    if (newState == FIELD_PLACE_NAME_STATE_IDLE) {
        BG_SYS_SetPlaneVisible(FIELD_PLACE_NAME_BG_LAYER, 0);
        FIELD_PLACE_NAME_HideLetters(placeName);
    }
}

/*
 * A new request arrives while a banner is up: jumps to the matching point of
 * the fade out. States idle, letters launch and fade out ignore it.
 */
void FIELD_PLACE_NAME_Interrupt(FieldPlaceName *placeName)
{
    int newState;
    int newFrame;
    switch (placeName->state) {
    case FIELD_PLACE_NAME_STATE_IDLE:
    case FIELD_PLACE_NAME_STATE_LETTERS_LAUNCH:
    case FIELD_PLACE_NAME_STATE_FADE_OUT:
        return;
    case FIELD_PLACE_NAME_STATE_FADE_IN_WAIT:
    case FIELD_PLACE_NAME_STATE_LETTERS_LAND:
        newState = FIELD_PLACE_NAME_STATE_LETTERS_LAND;
        newFrame = FIELD_PLACE_NAME_HOLD_FRAMES;
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN:
        newState = FIELD_PLACE_NAME_STATE_FADE_OUT;
        newFrame = (int)(20.0f * (1.0f - (float)(u32)placeName->frame / 10.0f));
        break;
    case FIELD_PLACE_NAME_STATE_PREPARE:
        newState = FIELD_PLACE_NAME_STATE_IDLE;
        newFrame = 0;
        break;
    }
    FIELD_PLACE_NAME_SetState(placeName, newState);
    placeName->frame = newFrame;
}

/* Idle state: starts the banner when a request is pending. */
void FIELD_PLACE_NAME_StateIdle(FieldPlaceName *placeName)
{
    int show = 0;
    if (FIELD_PLACE_NAME_GetForceShowRequest(placeName)) {
        show = 1;
        FIELD_PLACE_NAME_ClearForceShowRequest(placeName);
    } else if (FIELD_PLACE_NAME_GetZoneChangeRequest(placeName)) {
        if (FIELD_PLACE_NAME_HasPlaceNameChanged(placeName)) {
            show = 1;
        }
        FIELD_PLACE_NAME_ClearZoneChangeRequest(placeName);
    }
    if (show) {
        FIELD_PLACE_NAME_SetState(placeName, FIELD_PLACE_NAME_STATE_PREPARE);
    }
}

/* Prepare state: reads the message, resets the BG, then starts one letter per frame. */
void FIELD_PLACE_NAME_StatePrepare(FieldPlaceName *placeName)
{
    BmpWin *bmpWin;
    switch (FIELD_PLACE_NAME_GetStep(placeName)) {
    case 0:
        FIELD_PLACE_NAME_LoadMessage(placeName);
        FIELD_PLACE_NAME_IncrementStep(placeName);
        break;
    case 1:
        BG_SYS_InitSlot(FIELD_PLACE_NAME_BG_LAYER);
        BG_SYS_ClearSlot(FIELD_PLACE_NAME_BG_LAYER);
        FIELD_PLACE_NAME_TransferPalette(placeName);
        FIELD_PLACE_NAME_IncrementStep(placeName);
        break;
    case 2:
        FIELD_PLACE_NAME_ClearWindow(placeName);
        bmpWin = placeName->bmpWin;
        BMP_WIN_TransferChars(bmpWin);
        BMP_WIN_MakeScreen(bmpWin);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmpWin));
        BG_SYS_SetVisibleLayer(FIELD_PLACE_NAME_BG_LAYER, 1);
        BG_SYS_SetPlaneVisible(FIELD_PLACE_NAME_BG_LAYER, 0);
        G2x_SetBlendAlpha_(REG_BLDCNT_ADDR, 8, 0x11, 0x10, 4);
        FIELD_PLACE_NAME_ResetSpawnCounts(placeName);
        FIELD_PLACE_NAME_IncrementStep(placeName);
        break;
    case 3:
        FIELD_PLACE_NAME_SpawnNextLetter(placeName);
        if (FIELD_PLACE_NAME_IsAllSpawned(placeName)) {
            FIELD_PLACE_NAME_SetState(placeName, FIELD_PLACE_NAME_STATE_FADE_IN);
        }
        break;
    }
}

/* Fade in state: shows the plate, then waits out the blend. */
void FIELD_PLACE_NAME_StateFadeIn(FieldPlaceName *placeName)
{
    switch (FIELD_PLACE_NAME_GetStep(placeName)) {
    case 0:
        FIELD_PLACE_NAME_DrawFadeIn(placeName);
        BG_SYS_SetPlaneVisible(FIELD_PLACE_NAME_BG_LAYER, 1);
        FIELD_PLACE_NAME_IncrementStep(placeName);
        break;
    case 1:
        if (placeName->frame > FIELD_PLACE_NAME_FADE_IN_FRAMES) {
            FIELD_PLACE_NAME_SetState(placeName, FIELD_PLACE_NAME_STATE_FADE_IN_WAIT);
        }
        break;
    }
}

void FIELD_PLACE_NAME_StateFadeInWait(FieldPlaceName *placeName)
{
    if (placeName->frame > FIELD_PLACE_NAME_FADE_IN_FRAMES) {
        FIELD_PLACE_NAME_SetState(placeName, FIELD_PLACE_NAME_STATE_LETTERS_LAUNCH);
    }
}

/* Letters launch state: one letter every 3 frames. */
void FIELD_PLACE_NAME_StateLettersLaunch(FieldPlaceName *placeName)
{
    switch (FIELD_PLACE_NAME_GetStep(placeName)) {
    case 0:
        placeName->launchedCount = 0;
        FIELD_PLACE_NAME_IncrementStep(placeName);
        break;
    case 1:
        if (placeName->frame % FIELD_PLACE_NAME_LETTER_INTERVAL == 0) {
            FIELD_PLACE_NAME_LaunchNextLetter(placeName);
            if (placeName->messageLength <= placeName->launchedCount) {
                FIELD_PLACE_NAME_SetState(placeName, FIELD_PLACE_NAME_STATE_LETTERS_LAND);
            }
        }
        break;
    }
}

/*
 * Letters land state: waits until no letter moves, blits the letters into
 * the window one per frame, transfers the window, hides the letters and
 * holds the plate for 30 frames.
 */
void FIELD_PLACE_NAME_StateLettersLand(FieldPlaceName *placeName)
{
    int allLanded = 1;
    int i;
    switch (FIELD_PLACE_NAME_GetStep(placeName)) {
    case 0:
        for (i = 0; i < placeName->messageLength; i++) {
            PlaceNameLetter *letter = placeName->shownLetters[i];
            if (letter != 0 && PLACE_NAME_LETTER_IsActive(letter) != 0) {
                allLanded = 0;
                break;
            }
        }
        if (allLanded != 0) {
            FIELD_PLACE_NAME_ResetBlitCount(placeName);
            FIELD_PLACE_NAME_IncrementStep(placeName);
        }
        break;
    case 1:
        FIELD_PLACE_NAME_BlitNextLetter(placeName);
        if (FIELD_PLACE_NAME_IsAllBlitted(placeName) != 0) {
            FIELD_PLACE_NAME_IncrementStep(placeName);
        }
        break;
    case 2:
        BMP_WIN_TransferChars(placeName->bmpWin);
        FIELD_PLACE_NAME_IncrementStep(placeName);
        break;
    case 3:
        FIELD_PLACE_NAME_HideLetters(placeName);
        FIELD_PLACE_NAME_IncrementStep(placeName);
        break;
    case 4:
        if (placeName->frame > FIELD_PLACE_NAME_HOLD_FRAMES) {
            FIELD_PLACE_NAME_SetState(placeName, FIELD_PLACE_NAME_STATE_FADE_OUT);
        }
        break;
    }
}

/* Fade out state: after 20 frames the banner is gone. */
void FIELD_PLACE_NAME_StateFadeOut(FieldPlaceName *placeName)
{
    if (placeName->frame > FIELD_PLACE_NAME_FADE_OUT_FRAMES) {
        FIELD_PLACE_NAME_SetState(placeName, FIELD_PLACE_NAME_STATE_IDLE);
        BG_SYS_SetPlaneVisible(FIELD_PLACE_NAME_BG_LAYER, 0);
        FIELD_PLACE_NAME_HideLetters(placeName);
    }
}

/* Draw handler of the idle state: nothing to draw. */
void FIELD_PLACE_NAME_DrawIdle(FieldPlaceName *placeName)
{
}

/* Draw handler of the prepare state: nothing to draw. */
void FIELD_PLACE_NAME_DrawPrepare(FieldPlaceName *placeName)
{
}

/* Draw handler of the fade in state: blend weights move from (0, 16) to (16, 4). */
void FIELD_PLACE_NAME_DrawFadeIn(FieldPlaceName *placeName)
{
    float progress;
    int evA;
    progress = (float)(u32)placeName->frame / 10.0f;
    evA = (int)(16.0f * progress);
    G2x_SetBlendAlpha_(REG_BLDCNT_ADDR, 8, 0x11, evA, (int)(4.0f + 12.0f * (1.0f - progress)));
}

/* Draw handler of the fade in wait state: nothing to draw. */
void FIELD_PLACE_NAME_DrawFadeInWait(FieldPlaceName *placeName)
{
}

/* Draw handler of the letters launch state: nothing to draw. */
void FIELD_PLACE_NAME_DrawLettersLaunch(FieldPlaceName *placeName)
{
}

/* Draw handler of the letters land state: nothing to draw. */
void FIELD_PLACE_NAME_DrawLettersLand(FieldPlaceName *placeName)
{
}

/* Draw handler of the fade out state: blend weights move back from (16, 4). */
void FIELD_PLACE_NAME_DrawFadeOut(FieldPlaceName *placeName)
{
    float progress;
    int evA;
    progress = (float)(u32)placeName->frame / 20.0f;
    evA = (int)(16.0f * (1.0f - progress));
    G2x_SetBlendAlpha_(REG_BLDCNT_ADDR, 8, 0x11, evA, (int)(4.0f + 12.0f * progress));
}

FieldPlaceName *FIELD_PLACE_NAME_AllocWork(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, 0x154, 1, (const char *)&gFieldPlaceNameFileName, 0x73C);
}

void FIELD_PLACE_NAME_InitWork(FieldPlaceName *placeName, GameSystem *gameSystem)
{
    MI_CpuFill8(placeName, 0, 0x154);
    placeName->gameSystem = gameSystem;
    placeName->gameData = ICA_ANIME_GetField1C(gameSystem);
    placeName->bgCharOffset = -1;
    placeName->forceShowRequested = 0;
    placeName->zoneChangeRequested = 0;
    placeName->prevZoneId = 0x1AB;
    placeName->zoneId = 0x1AB;
}

void FIELD_PLACE_NAME_FreeWork(FieldPlaceName *placeName)
{
    GFL_HEAP_Free(placeName);
}

void FIELD_PLACE_NAME_CreateWordSet(FieldPlaceName *placeName)
{
    placeName->wordSet = WORDSET_CreateDefault(FIELD_PLACE_NAME_GetHeapId(placeName));
}

void FIELD_PLACE_NAME_CreateMsgData(FieldPlaceName *placeName)
{
    placeName->msgData = MSGDATA_CreateFromArchive(0, 2, 0x59, FIELD_PLACE_NAME_GetHeapId(placeName));
}

void FIELD_PLACE_NAME_CreateMessage(FieldPlaceName *placeName)
{
    placeName->message = STRBUF_Create(0x21, FIELD_PLACE_NAME_GetHeapId(placeName));
}

void FIELD_PLACE_NAME_CreateBmpWin(FieldPlaceName *placeName)
{
    FIELD_PLACE_NAME_GetHeapId(placeName);
    placeName->bmpWin = BMP_WIN_Create(FIELD_PLACE_NAME_BG_LAYER, 0, 1, 0x20, 2, 0, 0);
}

void FIELD_PLACE_NAME_DeleteWordSet(FieldPlaceName *placeName)
{
    if (placeName->wordSet != 0) {
        WORDSET_DeleteStrbufED04(placeName->wordSet);
        placeName->wordSet = 0;
    }
}

void FIELD_PLACE_NAME_DeleteMsgData(FieldPlaceName *placeName)
{
    MsgData *msgData = placeName->msgData;
    if (msgData != 0) {
        MSGDATA_Delete(msgData);
        placeName->msgData = 0;
    }
}

void FIELD_PLACE_NAME_DeleteMessage(FieldPlaceName *placeName)
{
    Strbuf *message = placeName->message;
    if (message != 0) {
        STRBUF_Delete(message);
        placeName->message = 0;
    }
}

void FIELD_PLACE_NAME_DeleteBmpWin(FieldPlaceName *placeName)
{
    if (placeName->bmpWin != 0) {
        BMP_WIN_Delete(placeName->bmpWin);
        placeName->bmpWin = 0;
    }
}

u16 FIELD_PLACE_NAME_GetHeapId(FieldPlaceName *placeName)
{
    return placeName->heapId;
}

ArcFile *FIELD_PLACE_NAME_GetArcHandle(FieldPlaceName *placeName)
{
    return placeName->arcHandle;
}

void FIELD_PLACE_NAME_SetHeapId(FieldPlaceName *placeName, int heapId)
{
    placeName->heapId = heapId;
}

void FIELD_PLACE_NAME_SetFont(FieldPlaceName *placeName, GfFont *font)
{
    placeName->font = font;
}

void FIELD_PLACE_NAME_SetStateRaw(FieldPlaceName *placeName, int state)
{
    placeName->state = state;
}

u32 FIELD_PLACE_NAME_GetState(FieldPlaceName *placeName)
{
    return placeName->state;
}

void FIELD_PLACE_NAME_ResetFrame(FieldPlaceName *placeName)
{
    placeName->frame = 0;
}

void FIELD_PLACE_NAME_IncrementFrame(FieldPlaceName *placeName)
{
    placeName->frame++;
}

u8 FIELD_PLACE_NAME_GetStep(FieldPlaceName *placeName)
{
    return placeName->step;
}

void FIELD_PLACE_NAME_ResetStep(FieldPlaceName *placeName)
{
    placeName->step = 0;
}

void FIELD_PLACE_NAME_IncrementStep(FieldPlaceName *placeName)
{
    placeName->step++;
}

/* Reads the player's current zone from the save data. */
void FIELD_PLACE_NAME_LoadZoneFromSave(FieldPlaceName *placeName)
{
    placeName->zoneId = func_02008998(func_02008854(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(placeName->gameSystem))));
}

/* Writes the banner's current zone back to the save data. */
int FIELD_PLACE_NAME_SaveZoneToSave(FieldPlaceName *placeName)
{
    return func_020089A0((u32)func_02008854(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(placeName->gameSystem))), placeName->zoneId);
}

u16 FIELD_PLACE_NAME_GetZoneId(FieldPlaceName *placeName)
{
    return placeName->zoneId;
}

void FIELD_PLACE_NAME_SetZoneId(FieldPlaceName *placeName, u16 zoneId)
{
    placeName->prevZoneId = placeName->zoneId;
    placeName->zoneId = zoneId;
}

Strbuf *FIELD_PLACE_NAME_GetMessage(FieldPlaceName *placeName)
{
    return placeName->message;
}

u8 FIELD_PLACE_NAME_GetMessageLength(FieldPlaceName *placeName)
{
    return placeName->messageLength;
}

/* Whether the zone has a place name window. */
u32 FIELD_PLACE_NAME_HasWindow(u32 zoneId)
{
    return ZONEDATA_GetPlaceNameWindow(zoneId);
}
