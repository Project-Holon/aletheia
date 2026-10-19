/*
 * file:     b_plist_draw.c
 * unit:     yes
 * function: B_PLIST_DRAW_CreateStateWindows, B_PLIST_DRAW_ToggleAuxWindow, B_PLIST_DRAW_DeleteAuxWindow, B_PLIST_DRAW_ClearWindowBitmaps, B_PLIST_DRAW_DeleteStateWindows, B_PLIST_DRAW_DeleteAllWindows, B_PLIST_DRAW_DrawModePage, B_PLIST_DRAW_PrintRowName, B_PLIST_DRAW_PrintSlotValue, B_PLIST_DRAW_PrintNameWithValues, B_PLIST_DRAW_FillTypeBar, B_PLIST_DRAW_PrintRowValue, B_PLIST_DRAW_PrintItemOrName, B_PLIST_DRAW_PrintNumberAt, B_PLIST_DRAW_PrintTextAt, B_PLIST_DRAW_PrintHeader, B_PLIST_DRAW_PrintHeader9, B_PLIST_DRAW_PrintHeader10, B_PLIST_DRAW_PrintCenteredText, B_PLIST_DRAW_PrintStatsFields, B_PLIST_DRAW_PrintAttackStat, B_PLIST_DRAW_PrintDefenseStat, B_PLIST_DRAW_PrintSpeedStat, B_PLIST_DRAW_PrintSpAttackStat, B_PLIST_DRAW_PrintSpDefenseStat, B_PLIST_DRAW_PrintDualValue, B_PLIST_DRAW_PrintBankEntry, B_PLIST_DRAW_PrintAccuracyLabel, B_PLIST_DRAW_PrintAccuracyValue, B_PLIST_DRAW_PrintPowerLabel, B_PLIST_DRAW_PrintPowerValue, B_PLIST_DRAW_PrintMoveDescription, B_PLIST_DRAW_PrintCategoryLabel, B_PLIST_DRAW_PrintCategoryName, B_PLIST_DRAW_PrintPpPair, B_PLIST_DRAW_PrintMoveRowLabel, B_PLIST_DRAW_PrintWordAndRefresh, B_PLIST_DRAW_PrintMoveRowValues, B_PLIST_DRAW_DrawRows, B_PLIST_DRAW_DrawRowValueBars, B_PLIST_DRAW_PrintValueIfUnset, B_PLIST_DRAW_DrawMonMenuPage, B_PLIST_DRAW_DrawRowCenteredName, B_PLIST_DRAW_DrawMoveListPage, B_PLIST_DRAW_DrawSummaryPage, B_PLIST_DRAW_DrawMoveDetailPage, B_PLIST_DRAW_DrawMoveListWithNewMovePage, B_PLIST_DRAW_DrawMoveDetailWithNewMovePage, B_PLIST_DRAW_DrawMoveListForItemPage, B_PLIST_DRAW_ClearAndPrintStream, B_PLIST_DRAW_PrintStream, B_PLIST_DRAW_FormatRowWord, B_PLIST_DRAW_UpdateToolWindows, B_PLIST_DRAW_ShowToolWindows, B_PLIST_DRAW_ShowSubWindow, B_PLIST_DRAW_Init, B_PLIST_DRAW_ClearIds, B_PLIST_DRAW_RegisterRowCharacters, B_PLIST_DRAW_RegisterIconSet1, B_PLIST_DRAW_RegisterIconSet2, B_PLIST_DRAW_RegisterIconSet3, B_PLIST_DRAW_RegisterIconSet4, B_PLIST_DRAW_RegisterIconSet5, B_PLIST_DRAW_CreateActorFromParams, B_PLIST_DRAW_CreateActors, B_PLIST_DRAW_DeleteActors, B_PLIST_DRAW_PlaceActor, B_PLIST_DRAW_ApplyActorPalettes, B_PLIST_DRAW_TransferCharacter, B_PLIST_DRAW_TransferCharacterToggle, B_PLIST_DRAW_SetActorAnim, B_PLIST_DRAW_SwapActorPair, B_PLIST_DRAW_SetActorAnimByMode, B_PLIST_DRAW_LayoutActors, B_PLIST_DRAW_LayoutPartyListPage, B_PLIST_DRAW_LayoutMonMenuPage, B_PLIST_DRAW_LayoutSummaryPage, B_PLIST_DRAW_LayoutMoveListPage, B_PLIST_DRAW_LayoutMoveDetailPage, B_PLIST_DRAW_LayoutMoveListWithNewMovePage, B_PLIST_DRAW_LayoutMoveDetailWithNewMovePage, B_PLIST_DRAW_LayoutMoveListForItemPage
 * address:  0x0220BC70
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_02211BDA 0x02211BDA data a1
 *   d_02211B80 0x02211B80 data a1
 *   d_02211CB0 0x02211CB0 data a1
 *   d_02211BFE 0x02211BFE data a1
 *   d_02211C24 0x02211C24 data a1
 *   d_02211B98 0x02211B98 data a1
 *   d_02211BB6 0x02211BB6 data a1
 *   d_02211C68 0x02211C68 data a1
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_GetPalette 0x02045778 arm
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   d_02211B68 0x02211B68 data ov198 a4
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotFromMsgB6 0x0201EF8C thumb
 *   BGWINFRM_ScaleRatio 0x0202D01C thumb
 *   BGWINFRM_GetScaleRank 0x0202D034 thumb
 *   BMP_FillRect 0x02043AF4 arm
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   APP_ICON_GetStatusIconAnim  0x020276C4  thumb
 *   d_02211AFF  0x02211AFF  data  a1
 *   d_02211AF4 0x02211AF4 data a1
 *   B_PLIST_MAIN_GetRowStatus 0x02210DA8 thumb ov198
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   d_02211B06 0x02211B06 data a1
 *   d_02211B3C 0x02211B3C data a4
 *   d_02211B50 0x02211B50 data a1
 *   d_02211B20 0x02211B20 data a1
 *   d_02211B0D 0x02211B0D data a1
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   d_02211B2C 0x02211B2C data a1
 *   WAZA_TOOL_IsAlwaysHit 0x0201C1F4 thumb
 *   d_02211AF9 0x02211AF9 data a1
 *   FILE_UTIL_GetItemParam 0x02020FE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   B_APP_TOOL_Update 0x0220B0B0 thumb ov196
 *   B_APP_TOOL_ShowWindows 0x0220B094 thumb ov196
 *   B_APP_TOOL_ShowWindow 0x0220B07C thumb ov196
 *   B_PLIST_MAIN_CreateToolActors 0x0220F1F4 thumb ov198
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   POKE_TOOL_GetIconCellArcIdSub  0x0201BC78  thumb
 *   POKE_TOOL_GetIconCellEntryIdSub  0x0201BCEC  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   APP_ICON_GetMoveKindCellFileId 0x02027610 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetGearCellFileId 0x0202775C thumb
 *   APP_ICON_GetNoneFileId 0x02027758 thumb
 *   APP_ICON_GetGearPaletteFileId 0x02027760 thumb
 *   APP_ICON_GetGearAnimFileId 0x02027764 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   d_02211DFC 0x02211DFC data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   B_APP_TOOL_DeleteActors 0x0220AFC4 thumb ov196
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   APP_ICON_GetMoveKindPaletteOffset 0x02027604 thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   d_02211DB4 0x02211DB4 data a2
 *   d_02211DCC 0x02211DCC data a2
 *   d_02211DE4 0x02211DE4 data a2
 *   d_02211D34 0x02211D34 data a2
 *   B_PLIST_MAIN_SyncMoveActors 0x0220F060 thumb ov198
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 */
#include "b_plist_types.h"

struct Descriptor;
struct CharBuf;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
struct Bmp;
struct Rec;
struct Config;
struct Cfg;
struct Entry;
struct Obj;
struct Bank;
struct PalAnmSlot;
struct Vec2;
struct Sub0204A9D0;


typedef struct Item { u8 a,b,c,d,e,f; } Item;






struct B_PlistSlotView {
    u8 pad[0x16];
    u8 a0 : 7;
    u8 a1 : 1;
    u8 b0 : 3;
    u8 b1 : 4;
    u8 b2 : 1;
};

struct BPlHdr { char pad[0xC]; u32 font; u16 heapId; };

struct BPlDrawViewA { struct BPlHdr *hdr; char pad[0x1E9C]; void *msgBank; void *wordSet; void *pad8; u32 printQue; };



struct BPlDrawViewB { char pad[0x1E9C]; u32 fontSmall; void *msgBank; void *wordSet; void *strBuf; u32 printQue; };

struct Flags { u8 pad[0x2177]; u8 low:4; u8 high:4; };



typedef struct {
    int config;
    int party;
    int partnerParty;
    int font;
    unsigned short heapId;
} Sub;

typedef struct {
    Sub *owner;
    char pad04[0x1ea0 - 4];
    int msgBank;
    int wordSet;
    int strBuf;
    int printQue;
    char pad1eb0[0x1f98 - 0x1eb0];
    int win7;
    unsigned char win7Visible;
    char pad1f9d[0x1fe0 - 0x1f9d];
    int win18;
    unsigned char win18Visible;
} Big;


struct BPlDrawViewC { struct BPlHdr *hdr; char pad[0x1E9C]; void *msgBank; void *wordSet; void *pad8; u32 printQue; };

typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;

typedef struct { u8 pad0[4]; void *obj; u16 cnt; u8 pad1[0x1B-0xA]; Bits fl; u8 pad2[0x4C-0x1C]; } Rec;



typedef struct { char *volatile global; } Context;



typedef struct {short x,y,z; u8 a,b;} Point;

typedef struct {u8 half:3; u8 middle:4; u8 egg:1;} BPlIconFlags;

typedef struct {char pad0[8];u16 species;char padA[34];unsigned form;char rest[28];} BPlSummaryRec;



typedef struct {short x,y;} Pair;



typedef struct {u8 bytes[76];} BPlLayoutRec;

typedef struct {u8 low:6;u8 bit:1;u8 high:1;} Flag;

typedef struct {u8 low:6;u8 a:1;u8 b:1;} Fl;

typedef struct {char pad[0x1F58];u8 *a;u8 *b;} Q;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern u8 BMP_WIN_GetPalette(struct Descriptor *p);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *, int);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, s16 b, s16 c, void *d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u32 PRINTSYS_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_SetSlotFromMsgB6(struct WordSet *p, u32 i, u32 v);
extern u8 BGWINFRM_ScaleRatio(u32,u32,u32);
extern int BGWINFRM_GetScaleRank(u32,u32);
extern void BMP_FillRect(struct Bmp *b, u32 x, u32 y, u32 w, u32 h, u32 value);
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern int APP_ICON_GetStatusIconAnim(int pp);
extern int B_PLIST_MAIN_GetRowStatus(u8 *p);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void BG_SYS_MarkTileDirty(unsigned);
extern unsigned WAZA_TOOL_GetParam(u16,unsigned);
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
extern u32 FILE_UTIL_GetItemParam(void *a, u32 sel, u32 id);
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);
extern unsigned GF_FONT_SetTextColor(unsigned,unsigned,unsigned);
extern int MSG_SPEED_GetWait(unsigned);
extern int PRINTSYS_PrintStream(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
extern void B_APP_TOOL_Update(struct Entry *,int,u32);
extern void B_APP_TOOL_ShowWindows(char *,u8 *);
extern void B_APP_TOOL_ShowWindow(void *);
extern void B_PLIST_MAIN_CreateToolActors(u8 *p);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void *POKE_TOOL_GetBoxParam(void *p);
extern u32 POKE_TOOL_GetGraphicIndex(void *mon);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int CLACT_RegisterPaletteCompressed(void *h, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);
extern int POKE_TOOL_GetIconCellArcIdSub(void);
extern int POKE_TOOL_GetIconCellEntryIdSub(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern int CLACT_RegisterPalette(void *, unsigned, unsigned, unsigned, u16);
extern unsigned APP_ICON_GetTypeCellFileId(unsigned);
extern unsigned APP_ICON_GetMoveKindCellFileId(unsigned);
extern int CLACT_RegisterPaletteEx(void *,unsigned,unsigned,unsigned,u16,u16,u16);
extern unsigned APP_ICON_GetArchiveId(void);
extern int APP_ICON_GetGearCellFileId(int);
extern int APP_ICON_GetNoneFileId(void);
extern int APP_ICON_GetGearPaletteFileId(int);
extern int APP_ICON_GetGearAnimFileId(int);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void CLACT_DeleteActor(struct Obj *p);
extern void B_APP_TOOL_DeleteActors(u8 *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned POKE_TOOL_CalcIconPalette(unsigned,unsigned,unsigned,unsigned);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);
extern void CLACT_TransferCharacter(int,struct Sub0204A9D0 *);
extern u32 GFL_HEAP_Free(void *p);
extern u8 APP_ICON_GetTypePaletteOffset(int i);
extern u8 APP_ICON_GetMoveKindPaletteOffset(u8 i);
extern void CLACT_AddActorSurfacePos(struct Obj *,const struct Vec2 *,u32),CLACT_SetActorAnimSeq(struct Obj *,u32);
extern u32 FILE_UTIL_IsMailItem(u32);
extern void B_PLIST_MAIN_SyncMoveActors(u8 *p);
void B_PLIST_DRAW_CreateStateWindows(u8 *p,u32 state);
void B_PLIST_DRAW_ToggleAuxWindow(u8 *p);
void B_PLIST_DRAW_DeleteAuxWindow(u8 *p);
void B_PLIST_DRAW_ClearWindowBitmaps(u8 *p);
void B_PLIST_DRAW_DeleteStateWindows(char *p);
void B_PLIST_DRAW_DeleteAllWindows(u8 *p);
void B_PLIST_DRAW_DrawModePage(char *a, int idx);
void B_PLIST_DRAW_PrintRowName(u8 *p, int slot, u16 rowIndex, u8 xPos, u8 extra);
void B_PLIST_DRAW_PrintSlotValue(u8 *p,int slot,int index,s16 value,u8 extra);
void B_PLIST_DRAW_PrintNameWithValues(u8 *p, int slot, int index, u8 x0, u8 extra);
void B_PLIST_DRAW_FillTypeBar(u8 *p,int slot,int index,u16 value,u8 extra);
void B_PLIST_DRAW_PrintRowValue(u8 *p,int slot,int index);
void B_PLIST_DRAW_PrintItemOrName(char *p, int i, int index);
void B_PLIST_DRAW_PrintNumberAt(char *p,int value,int slot,int id,u16 x,s16 y,u32 color);
void B_PLIST_DRAW_PrintTextAt(char *p, int i, s16 x, s16 y);
void B_PLIST_DRAW_PrintHeader(char *p, int id);
void B_PLIST_DRAW_PrintHeader9(char *p);
void B_PLIST_DRAW_PrintHeader10(char *p);
void B_PLIST_DRAW_PrintCenteredText(char *p, int i, int id);
void B_PLIST_DRAW_PrintStatsFields(u8 *p,int index);
void B_PLIST_DRAW_PrintAttackStat(char *obj, int i);
void B_PLIST_DRAW_PrintDefenseStat(char *p, int i);
void B_PLIST_DRAW_PrintSpeedStat(char *p, int i);
void B_PLIST_DRAW_PrintSpAttackStat(char *p, int i);
void B_PLIST_DRAW_PrintSpDefenseStat(char *p, int i);
void B_PLIST_DRAW_PrintDualValue(u8 *p,int index);
void B_PLIST_DRAW_PrintBankEntry(char *p, int index);
void B_PLIST_DRAW_PrintAccuracyLabel(char *p, int i);
void B_PLIST_DRAW_PrintAccuracyValue(char *p, int winIndex, int value);
void B_PLIST_DRAW_PrintPowerLabel(char *p, int i);
void B_PLIST_DRAW_PrintPowerValue(char *p, int winIndex, u32 value);
void B_PLIST_DRAW_PrintMoveDescription(char *p, int i, int id);
void B_PLIST_DRAW_PrintCategoryLabel(char *p, int i);
void B_PLIST_DRAW_PrintCategoryName(char *p, int i, int selector);
void B_PLIST_DRAW_PrintPpPair(u8 *p, int slot, int leftValue, int rightValue);
void B_PLIST_DRAW_PrintMoveRowLabel(char *p, int i);
void B_PLIST_DRAW_PrintWordAndRefresh(u8 *p);
void B_PLIST_DRAW_PrintMoveRowValues(char *p,u8 *record,int slot);
void B_PLIST_DRAW_DrawRows(u8 *p);
void B_PLIST_DRAW_DrawRowValueBars(u8 *p, int i);
void B_PLIST_DRAW_PrintValueIfUnset(u8 *p,int a);
void B_PLIST_DRAW_DrawMonMenuPage(char *p);
void B_PLIST_DRAW_DrawRowCenteredName(u8 *p, int idx);
void B_PLIST_DRAW_DrawMoveListPage(char *p);
void B_PLIST_DRAW_DrawSummaryPage(char *p);
void B_PLIST_DRAW_DrawMoveDetailPage(char *p);
void B_PLIST_DRAW_DrawMoveListWithNewMovePage(char *p);
void B_PLIST_DRAW_DrawMoveDetailWithNewMovePage(char *p);
void B_PLIST_DRAW_DrawMoveListForItemPage(char *p);
void B_PLIST_DRAW_ClearAndPrintStream(u8 *p);
void B_PLIST_DRAW_PrintStream(char *p);
void B_PLIST_DRAW_FormatRowWord(u8 *p);
void B_PLIST_DRAW_UpdateToolWindows(u8 *p);
void B_PLIST_DRAW_ShowToolWindows(u8 *p);
void B_PLIST_DRAW_ShowSubWindow(u8 *p);
void B_PLIST_DRAW_Init(char *p);
void B_PLIST_DRAW_ClearIds(char *p);
void B_PLIST_DRAW_RegisterRowCharacters(u8 *p);
void B_PLIST_DRAW_RegisterIconSet1(char *p);
void B_PLIST_DRAW_RegisterIconSet2(char *p);
void B_PLIST_DRAW_RegisterIconSet3(char *p);
void B_PLIST_DRAW_RegisterIconSet4(char *p);
void B_PLIST_DRAW_RegisterIconSet5(char *p);
unsigned B_PLIST_DRAW_CreateActorFromParams(char *p,const int *q);
void B_PLIST_DRAW_CreateActors(char *p);
void B_PLIST_DRAW_DeleteActors(char *p);
void B_PLIST_DRAW_PlaceActor(u8 *p, u32 b);
void B_PLIST_DRAW_ApplyActorPalettes(BPlSummaryRec *records);
void B_PLIST_DRAW_TransferCharacter(char *p,void *obj,int index,int which);
void B_PLIST_DRAW_TransferCharacterToggle(char *p,int first,int index,int which);
void B_PLIST_DRAW_SetActorAnim(int mode,u8 *p,const struct Vec2 *q);
void B_PLIST_DRAW_SwapActorPair(char *p,u8 *q,const Pair *pos);
void B_PLIST_DRAW_SetActorAnimByMode(u32 mode,u8 *p,const struct Vec2 *q);
void B_PLIST_DRAW_LayoutActors(char *p,unsigned mode);
void B_PLIST_DRAW_LayoutPartyListPage(BPlLayoutRec *records);
void B_PLIST_DRAW_LayoutMonMenuPage(BPlLayoutRec *records);
void B_PLIST_DRAW_LayoutSummaryPage(u8 *p);
void B_PLIST_DRAW_LayoutMoveListPage(u8 *p);
void B_PLIST_DRAW_LayoutMoveDetailPage(u8 *p);
void B_PLIST_DRAW_LayoutMoveListWithNewMovePage(u8 *p);
void B_PLIST_DRAW_LayoutMoveDetailWithNewMovePage(u8 *p);
void B_PLIST_DRAW_LayoutMoveListForItemPage(u8 *p);
extern Item d_02211BDA[],d_02211B80[],d_02211CB0[],d_02211BFE[],d_02211C24[],d_02211B98[],d_02211BB6[],d_02211C68[];
extern u32 d_02211B68[];
extern u8 d_02211AFF[];
extern u8 d_02211AF4[];
extern u8 d_02211B06[];
extern const int d_02211B3C[];
extern u8 d_02211B50[];
extern u8 d_02211B20[];
extern u8 d_02211B0D[];
extern u8 d_02211B2C[];
extern u8 d_02211AF9[];
extern const int d_02211DFC[][5];
extern const Pair d_02211DB4[],d_02211DCC[],d_02211DE4[];
extern Pair d_02211D34[27];









#define P ((struct BPlDrawViewA *)p)












/*
 * precondition: game callers supply state 0..8; every case initializes s.
 * evidence: C88's nine callers pass constants0..8; F4E0 dominates BC24
 * with state-byte2180 stores0/4/6. C88 stores its bounded state at2177+9.
 * Domain and decoded-call audit: Wave30 S26/BC70-domain-review.md.
 */
void B_PLIST_DRAW_CreateStateWindows(u8 *p,u32 state)
{
    Item *s;
    u32 i;
    B_PLIST_DRAW_DeleteAuxWindow(p);
    B_PLIST_DRAW_ToggleAuxWindow(p);
    switch(state) {
    case 0: case 8: s=d_02211BDA; p[0x2174]=6; break;
    case 1: s=d_02211B80; p[0x2174]=4; break;
    case 2: s=d_02211CB0; p[0x2174]=22; break;
    case 3: s=d_02211BFE; p[0x2174]=6; break;
    case 4: s=d_02211C24; p[0x2174]=11; break;
    case 5: s=d_02211B98; p[0x2174]=5; break;
    case 6: s=d_02211BB6; p[0x2174]=6; break;
    case 7: s=d_02211C68; p[0x2174]=12; break;
    }
    for(i=0;i<p[0x2174];i++,s++)
        *(void **)(p+i*8+0x1F70)=(void *)BMP_WIN_Create(s->a,s->b,s->c,s->d,s->e,s->f,1);
}












void B_PLIST_DRAW_ToggleAuxWindow(u8 *p)
{
    if (((struct B_PlistWork *)p)->winFlags.bc.low == 1)
        ((struct B_PlistWork *)p)->u2170.ptr=(void *)BMP_WIN_Create(5,0,0,32,16,0,1);
    ((struct B_PlistWork *)p)->winFlags.bc.low ^= 1;
}













/*
 * Addresses are Black-image addresses.
 */
void B_PLIST_DRAW_DeleteAuxWindow(u8 *p)
{
    u32 t = ((struct B_PlistWork *)p)->u2170.word;

    if (t != 0) {
        BMP_WIN_Delete((struct Descriptor *)t);
        ((struct B_PlistWork *)p)->u2170.word = 0;
    }
}












void B_PLIST_DRAW_ClearWindowBitmaps(u8 *p){u32 i;for(i=0;i<p[0x2174];i++)BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+i*8+0x1f70)),0);}













void B_PLIST_DRAW_DeleteStateWindows(char *p)
{
    unsigned int i;
    for (i = 0; i < ((struct B_PlistWork *)p)->winCount; i++)
    {
        BMP_WIN_Delete(*(void **)(p + 0x1f70 + i * 8));
    }
}












void B_PLIST_DRAW_DeleteAllWindows(u8 *p){u32 i;B_PLIST_DRAW_DeleteStateWindows((char *)p);for(i=0;i<2;i++)BMP_WIN_Delete(*(struct Descriptor **)(p+i*8+0x1f60));B_PLIST_DRAW_DeleteAuxWindow(p);}













void B_PLIST_DRAW_DrawModePage(char *a, int idx)
{
    switch (idx) {
    case 0: {
        unsigned char c;
        B_PLIST_DRAW_DrawRows((u8 *)a);
        c = *(unsigned char *)(*(int *)&((struct B_PlistHost *)a)->config + 0x1f);
        if (c == 3)
            B_PLIST_DRAW_PrintHeader(a, 7);
        else if (c == 2)
            B_PLIST_DRAW_PrintHeader(a, 9);
        else
            B_PLIST_DRAW_PrintHeader(a, 6);
        break;
    }
    case 8:
        B_PLIST_DRAW_DrawRows((u8 *)a);
        B_PLIST_DRAW_PrintHeader(a, 0xa);
        break;
    case 1:
        B_PLIST_DRAW_DrawMonMenuPage(a);
        break;
    case 2:
        B_PLIST_DRAW_DrawSummaryPage(a);
        break;
    case 3:
        B_PLIST_DRAW_DrawMoveListPage(a);
        break;
    case 4:
        B_PLIST_DRAW_DrawMoveDetailPage(a);
        break;
    case 5:
        B_PLIST_DRAW_DrawMoveListForItemPage(a);
        break;
    case 6:
        B_PLIST_DRAW_DrawMoveListWithNewMovePage(a);
        break;
    case 7:
        B_PLIST_DRAW_DrawMoveDetailWithNewMovePage(a);
        break;
    }
}











/*
 * lever: rec is passed as `*(void **)rec` (a real variable, not a CSE temp); ex is an s16 local (the callee's
 *   parameter type) set in each head arm; a2 is u16 (the caller passes `(u16)i`); tail colour depends on b0
 * 2026-10-05 (wD9r lane121): 45 -> EXACT. Fixes: (1) the 0201EEF4 argument written `*(void **)rec`, so rec is a
 *   declared variable with its own slot (the `base + off` form made it a CSE temp in the lowest slot); (2) lane 94's
 *   declaration order (w2, w, off, handle, rec, vec, msg, x, k, c90, cn0, c91, cn1, ex, m3, m2, x2) with the four
 *   tail ctx values as function-scope locals; (3) ex as s16 (the 0201C724 parameter type), assigned in each head
 *   arm: a u8 copy coalesced with the stack parameter; (4) logic fix: the tail colour is 0x2960 for b0 == 0 and
 *   0x31A0 for b0 == 1 in both k arms (the draft had it per k); (5) a2 as u16 (the matched caller passes
 *   `(u16)i`), which puts the a2 spill store first at entry.
 */
void B_PLIST_DRAW_PrintRowName(u8 *p, int slot, u16 rowIndex, u8 xPos, u8 extra)
{
    u32 w2;
    u32 w;
    u32 off;
    void *handle;
    struct B_PlistSlotView *rec;
    void *vec;
    void *msg;
    u32 maleX;
    u32 k;
    u32 c90;
    u32 cn0;
    u32 c91;
    u32 cn1;
    s16 ex;
    void *m3;
    void *m2;
    u32 femaleX;
    int n;
    u8 *base;
    u8 *tab;

    slot = slot * 8;
    tab = p + 0x1F70;
    handle = *(void **)(tab + slot);
    k = BMP_WIN_GetPalette(handle);
    n = B_PLIST_MAIN_GetOrderIndex(p, rowIndex);
    base = p + 4;
    off = n * 0x4C;
    rec = (struct B_PlistSlotView *)(base + off);
    vec = STRBUF_Create(12, P->hdr->heapId);
    msg = MSGDATA_AllocString(P->msgBank, d_02211B68[rowIndex]);
    WORDSET_SetSlotMonNickname(P->wordSet, 0, *(void **)rec);
    WORDSET_CopyTaggedText(P->wordSet, vec, msg);
    if (k == 9) {
        u32 h9 = P->printQue;
        ex = extra;
        PRINTSYS_PrintQueColor((void *)h9, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), xPos, ex, vec, P->hdr->font, 0x3DC0);
        *(p + 0x1F74 + slot) = 1;
    } else {
        u32 hn = P->printQue;
        ex = extra;
        PRINTSYS_PrintQueColor((void *)hn, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), xPos, ex, vec, P->hdr->font, 0x3DC0);
        *(p + 0x1F74 + slot) = 1;
    }
    STRBUF_Delete(msg);
    STRBUF_Delete(vec);
    if (rec->a1 || rec->b2)
        return;
    if (rec->b0 == 0) {
        m2 = MSGDATA_AllocString(P->msgBank, 0x16);
        w = BMP_WIN_GetWidth(handle);
        maleX = (u16)((w << 3) - PRINTSYS_MeasureWidestLine(m2, P->hdr->font, 0));
        if (k == 9) {
            c90 = P->printQue;
            PRINTSYS_PrintQueColor((void *)c90, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), maleX, ex, m2, P->hdr->font, 0x2960);
            *(p + 0x1F74 + slot) = 1;
        } else {
            cn0 = P->printQue;
            PRINTSYS_PrintQueColor((void *)cn0, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), maleX, ex, m2, P->hdr->font, 0x2960);
            *(p + 0x1F74 + slot) = 1;
        }
        STRBUF_Delete(m2);
    } else if (rec->b0 == 1) {
        m3 = MSGDATA_AllocString(P->msgBank, 0x17);
        w2 = BMP_WIN_GetWidth(handle);
        femaleX = (u16)((w2 << 3) - PRINTSYS_MeasureWidestLine(m3, P->hdr->font, 0));
        if (k == 9) {
            c91 = P->printQue;
            PRINTSYS_PrintQueColor((void *)c91, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), femaleX, ex, m3, P->hdr->font, 0x31A0);
            *(p + 0x1F74 + slot) = 1;
        } else {
            cn1 = P->printQue;
            PRINTSYS_PrintQueColor((void *)cn1, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), femaleX, ex, m3, P->hdr->font, 0x31A0);
            *(p + 0x1F74 + slot) = 1;
        }
        STRBUF_Delete(m3);
    }
}









void B_PLIST_DRAW_PrintSlotValue(u8 *p,int slot,int index,s16 value,u8 extra)
{
    char *elem=(char *)(p+4)+B_PLIST_MAIN_GetOrderIndex(p,index)*0x4C;
    void *text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,11);
    u32 context;
    u32 surface;
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet,0,((struct B_PlistSlot *)elem)->levelBits.level,3,0,1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet,(void *)(((struct B_PlistWork *)p)->u1EA8.strBufWord),text);
    context=((struct B_PlistWork *)p)->u1EAC.printQueWord;
    surface=(u32)BMP_WIN_GetBmp(*(void **)(p+slot*8+0x1F70));
    PRINTSYS_PrintQueColor((void *)context,surface,value,extra,(void *)((struct B_PlistWork *)p)->u1EA8.strBufWord,((struct B_PlistWork *)p)->u1E9C.fontSmallWord,0x3DC0);
    (p+slot*8)[0x1F74]=1;
    STRBUF_Delete(text);
}








#undef P







#undef P






#undef P





#undef P




#undef P



#undef P


#undef P

#undef P
#define P ((struct BPlDrawViewB *)p)









static inline u32 half(u32 w) { return w >> 1; }









/*
 * 2026-10-05 (wD9r lane164): EXACT in both --lang c99 and --lang c. The steering cast `(u32)n >> 1` is gone:
 *   the halving is a single-parameter helper `static inline u32 half(u32 w) { return w >> 1; }` (shape of
 *   ov097 021F6D70 center_x), so the u32 parameter gives lsrs. Plain `x0 - (n >> 1)` is DIFF. Locals are
 *   declared at the top in the same order (C89 form), assignments in place; same bytes.
 * 2026-10-05 (wD9r lane156): EXACT. n is a u8 local (`u8 n = PRINTSYS_MeasureWidestLine(...)`), widened to u32 for the
 *   halving shift (`x0 - ((u32)n >> 1)`, keeps lsrs). mwcc keeps the reload of a spilled narrow local below the
 *   outgoing stack stores (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md).
 * 2026-10-05 (wD9r lane138): still 22 bytes. Tried the matched ov198 sibling prototype (0220C694, 0220D628:
 *   `PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16)` with an (s16) cast at the call): 54, the ex reload
 *   then hoists above the stack stores in all three calls. Also (u32, u32, int, int): 327 (frame grows, slot
 *   spilled); (int, s16): 328; (s16, int): 54; (short, short): 22. Finding: with an s16 parameter the ex
 *   reload stays below the outgoing stores, with u32 or int it hoists, so the s16 prototype is right and the
 *   parameter type changes where a reload lands. The x0 + n add still heads the chain in every form.
 * 2026-10-05 (wD9r lane127): still 22 bytes. Tried two new forms of the 'n lives in memory' idea:
 *   n written through a static inline out-parameter helper `getw(text, font, &n)` (u32 and u8 n; mwcc
 *   promotes the inlined address-taken local, same 22 or 29 lines); and `y = x0 + n;` reusing the call 2
 *   s16 local for call 3 (same 22). Check of the hint: no register parameter here can be a homed narrow
 *   parameter (all four are used in registers at entry, no entry store), and a homed slot would add bytes
 *   (image is 396, ours 396). The 0xC slot is the narrow stack parameter `extra` copied to the frame.
 * 2026-10-05 (wD9r lane111): still 22 bytes. New finding (diagnostic): a reassigned NARROW real parameter
 *   (index declared u16, short or signed char, then `index = (u8)PRINTSYS_MeasureWidestLine(...)` and `x0 + index` in call 3)
 *   is memory-homed by mwcc, and call 3 then has the image order exactly (three stack stores, ldr r2 n,
 *   ldr r0 ctx3, adds, lsls, ldr r3, asrs). But the home costs an entry store `str r2,[sp,#0xc]` and a reload
 *   for the first call, and the slot is the lowest one (image: no entry store, n at 0x28), so not the source.
 *   A u8 index is not homed (40, still hoisted). Also tried: the body after the 0201D304 call as a static
 *   inline `rest(..., u32/u16/short n)` with n as an inline parameter (328, slot param spilled; the n reload
 *   is still hoisted, inline parameters are not homed). So the image n has the alias class of a param home
 *   or escaped local (ov097 lane95), but no source form with neither an entry store nor an `add rX,sp` found.
 * 2026-10-05 (wD9r lane56): still 22 bytes. Tried: n as u16 (40, n >> 1 becomes asrs and slots shift); the
 *   third x through `static inline s16 xsum(u8 a, u32 b) { return a + b; }` (22, the sum is still evaluated
 *   before the outgoing stack stores). Reading: in this compiler a load does not pass an earlier store (see
 *   ov194 021F3FBC entry), so the original evaluates the stack arguments of call 3 before the x sum and ours
 *   evaluates the sum first; the argument evaluation order, not alias, is the residue.
 * 2026-10-05 (wD9r lane43): still 22 bytes. Tried n declared u8 with the callee result assigned directly
 *   (the narrow-parameter idiom applied to the spilled local): 40 bytes, slots shift and the n reload still hoists
 *   above the stack stores. Compared with the EXACT sibling 0220D494: its third call `x + w1` has u32 x, here x0
 *   is a u8 parameter; no source form found that blocks the hoist.
 * 2026-10-05 (wD9r lane26): still 22 bytes. Tried int return types on 0201EFA4, 0201F250, 02045808 and 0201C724
 *   (the lever that closed ov217 021B9920): same 22. In ov097 021F6D70 an early s16 local for the sum is sunk to
 *   the call by mwcc, so the chain position is decided at the use, not by where the sum is written.
 * 2026-10-05 (wD9r lane12): still 22 bytes. Tried: the 0201D304 result in a u32 local w, then n = (u8)w (two
 *   variables, same 22); the third x through a pointer round trip (stand-in probe only, same 22). Same residue
 *   as ov097 021F6D70: the n reload heads the r2 chain in ours and sits below the stack stores in the image.
 *
 * note: DIFF vs 2026-10-04: 22 bytes differ, only the last 201C724 call: original stores the three stack args first and loads n and adds x0+n late (ldr r2,[sp,#0x28] after the stack stores), ours hoists the n load and add before the stack stores. Everything else matches (declaration order sets slots; x0 param reassigned; ctx and A/B locals). Tried: (s16)(x0+n), n+x0, a y local assigned before the call.
 * note 2026-10-05 (wave D4 lane 10): still DIFF (22 bytes). Tried ctx3 inlined as P->printQue (115 bytes) and
 *   A/B locals for the third call as in the second (no change). The sibling 0220D494 (EXACT this wave)
 *   computes its x+w1 early like ours, so the late `ldr r2,[sp,#0x28]; adds` here hints the third x is a
 *   different expression or variable in the original; not found.
 * note 2026-10-05 (wave D5 lane 10): still DIFF (22 bytes). Tried: a static inline put helper for all three calls
 *   (s16 x: no change; int x: 334 bytes), the helper on the third call only with int x (122), u8/int/s16 n (23-40),
 *   `y = x0 + n` before or after ctx3 (no change). The original treats the n reload as if it may alias the outgoing
 *   stack stores; ours hoists it above them.
 * 2026-10-05 (wD6 lane07): still 22 bytes. Tried: the 02045770 result in a block local before the call, with and
 *   without `y = x0 + n` and B3/A3 locals for the stack arguments placed after it (no change: the scheduler, not the
 *   source order, places the n reload); volatile n (337); int prototype for x with (s16) casts (327). In the original
 *   the n reload is not moved above the outgoing stack stores; ours is.
 * 2026-10-05 (wD7 lane10): still DIFF, 22 bytes. Read the scheduling: in the original, every spill reload before
 *   the three 0201C724 calls stays below the outgoing stack stores (call 2 leaves the `ldr r0,[sp,#0x10]; str r0,[sp]`
 *   stall open), so the n reload is blocked by a dependence, not by priority. In ours the n reload heads a 5-instruction
 *   chain and fills the stalls. Tests: an int y in call 2 (needs a conversion) also hoists its reload above the
 *   stores, so chain length drives the hoist in our build. n as a one-element array, n passed by address to a
 *   static inline adder, n used alone as x (no add), u8 n: the reload still hoists. A new u8 local x for
 *   x0 - (n >> 1) instead of reassigning x0: 328. No ex local, no tab local: no change; ctx1 inlined: 314.
 *   Open: what makes the original x chain depend on the stack stores.
 * 2026-10-05 (wD8 lane09): still 22 bytes. Same scheduler residue as ov116 021D7D0C (a spill reload kept
 *   below the outgoing stack stores in the image, hoisted in ours). No new form tested beyond the listing check.
 * 2026-10-05 (wD9 lane20): still 22 bytes. Tested whether n lives in memory in the original (a reload that may alias
 *   the outgoing stores): n as a one-field local struct `struct { u32 v; } n;` is still promoted to a register and
 *   spilled; the reload still hoists above the stack stores (35 bytes, slots shift). Not a memory variable.
 * 2026-10-05 (wD9r lane79): still 22 bytes. Tried the sum as a reassignment before the call: `n = x0 + n;`
 *   then pass n (400 bytes, 99, n gets a new register and slot), and `x0 = x0 + n;` then pass x0 (23, adds a u8
 *   truncation). Neither keeps the n reload below the outgoing stack stores.
 * 2026-10-05 (wD9r lane87): still 22 bytes. Tried the house prototype of PRINTSYS_PrintQueColor with a u16 colour
 *   (ov021 021905C8, arm9 0202E1F0), with and without a const text pointer: same 22. The n reload still
 *   heads the x chain above the outgoing stack stores.
 * 2026-10-05 (wD9r lane98): still 22 bytes. Reading: in both builds the direct-move reloads (y, ex, ctx) sit
 *   below the outgoing stack stores and do not fill the `ldr; str [sp]` stalls, so reloads never pass those stores;
 *   ours therefore has the n reload (the x0 + n add) before the stores in its IR. Tried: a block u32 x3 = x0 + n and
 *   int x3 = n + x0 before ctx3 (22, sunk to the same place); the 02045770 result in a block local h3 with ctx3
 *   before it (22) and with P->printQue inline as the first argument (115). No new source form found.
 * 2026-10-05 (wD9r lane104): still 22 bytes. Tried the short idiom (ov116 021D7D0C): n as short or u16
 *   (40, n >> 1 becomes asrs and slots shift, reload still hoists), PRINTSYS_MeasureWidestLine returning short (22),
 *   x0 as a short parameter (24, the x0 truncation becomes 16-bit, reload still hoists), and the dead int
 *   parameter `index` reused for n as short/u16/u8 (40) or int/u32 (376). None keeps the n reload below the
 *   outgoing stack stores.
 */
void B_PLIST_DRAW_PrintNameWithValues(u8 *p, int slot, int index, u8 x0, u8 extra)
{
    char *elem;
    void *text;
    u8 n;
    u32 ctx1;
    u8 ex;
    u8 *tab;
    u8 *fl;
    void *text2;
    void *text3;
    u32 ctx2;
    s16 y;
    u32 ctx3;
    u32 A;
    void *B;
    elem = (char *)(p + 4) + B_PLIST_MAIN_GetOrderIndex(p, index) * 0x4C;
    text = MSGDATA_AllocString(P->msgBank, 12);
    n = PRINTSYS_MeasureWidestLine(text, P->fontSmall, 0);
    x0 = x0 - half(n);
    ctx1 = P->printQue;
    ex = extra;
    slot = slot * 8;
    tab = p + 0x1F70;
    fl = p + 0x1F74;
    PRINTSYS_PrintQueColor((void *)ctx1, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), x0, ex, text, P->fontSmall, 0x3DC0);
    fl[slot] = 1;
    STRBUF_Delete(text);
    text2 = MSGDATA_AllocString(P->msgBank, 13);
    WORDSET_SetSlotNumber(P->wordSet, 0, *(u16 *)(elem + 0x10), 3, 0, 1);
    WORDSET_CopyTaggedText(P->wordSet, P->strBuf, text2);
    A = P->fontSmall;
    B = P->strBuf;
    y = x0 - PRINTSYS_MeasureWidestLine(B, A, 0);
    ctx2 = P->printQue;
    PRINTSYS_PrintQueColor((void *)ctx2, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), y, ex, B, A, 0x3DC0);
    fl[slot] = 1;
    STRBUF_Delete(text2);
    text3 = MSGDATA_AllocString(P->msgBank, 13);
    WORDSET_SetSlotNumber(P->wordSet, 0, *(u16 *)(elem + 0x12), 3, 0, 1);
    WORDSET_CopyTaggedText(P->wordSet, P->strBuf, text3);
    ctx3 = P->printQue;
    PRINTSYS_PrintQueColor((void *)ctx3, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), x0 + n, ex, P->strBuf, P->fontSmall, 0x3DC0);
    fl[slot] = 1;
    STRBUF_Delete(text3);
}







#undef P






#undef P





#undef P




#undef P



#undef P


#undef P

#undef P

#define P ((struct BPlDrawViewC *)p)









/*
 * lever: u16 value and u8 width/return preserve stack-store scheduling.
 */
void B_PLIST_DRAW_FillTypeBar(u8 *p,int slot,int index,u16 value,u8 extra)
{
    char *elem=(char *)(p+4)+B_PLIST_MAIN_GetOrderIndex(p,index)*0x4C;
    u8 color=1;
    u8 width=BGWINFRM_ScaleRatio(((struct B_PlistSlot *)elem)->hp,((struct B_PlistSlot *)elem)->maxHp,48);
    switch(BGWINFRM_GetScaleRank(((struct B_PlistSlot *)elem)->hp,((struct B_PlistSlot *)elem)->maxHp)) {
    case 3: return;
    case 0: color=1; break;
    case 1: color=3; break;
    case 2: color=5; break;
    }
    BMP_FillRect((struct Bmp *)((u32)BMP_WIN_GetBmp(*(void **)(p+0x1F70+slot*8))),(u16)value,(s16)(extra+3),width,(u8)1,(u8)color);
    color++;
    BMP_FillRect((struct Bmp *)((u32)BMP_WIN_GetBmp(*(void **)(p+0x1F70+slot*8))),(u16)value,(s16)(extra+4),width,(u8)1,(u8)color);
}









void B_PLIST_DRAW_PrintRowValue(u8 *p,int slot,int index)
{
    char *elem=(char *)(p+4)+B_PLIST_MAIN_GetOrderIndex(p,index)*0x4C;
    u32 buf=(u32)STRBUF_Create(16,((struct B_PlistWork *)p)->owner->heapId);
    void *text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,14);
    u32 context;
    u32 surface;
    WORDSET_SetSlotFromMsgB6(((struct B_PlistWork *)p)->wordSet,0,((struct B_PlistSlot *)elem)->abilityId);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet,(void *)buf,text);
    context=((struct B_PlistWork *)p)->u1EAC.printQueWord;
    surface=(u32)BMP_WIN_GetBmp(*(void **)(p+slot*8+0x1F70));
    PRINTSYS_PrintQueColor((void *)context,surface,0,0,(void *)buf,((struct B_PlistWork *)p)->owner->font,0x3DC0);
    (p+slot*8)[0x1F74]=1;
    STRBUF_Delete(text);
    STRBUF_Delete((void *)buf);
}









void B_PLIST_DRAW_PrintItemOrName(char *p, int i, int index)
{
    char *elem;
    void *t;
    void *format;
    void *f;
    elem = p + 4 + B_PLIST_MAIN_GetOrderIndex((u8 *)p, index) * 0x4C;
    if (((struct B_PlistSlot *)elem)->u1A.heldItem == 0)
        t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x1E);
    else {
        t = (void *)STRBUF_Create(0x12, ((struct B_PlistWork *)p)->owner->heapId);
        format = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 15);
        WORDSET_SetSlotFromMsg36(((struct B_PlistWork *)p)->wordSet, 0, ((struct B_PlistSlot *)elem)->u1A.heldItem);
        WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet, (void *)((u32)t), format);
        STRBUF_Delete(format);
    }
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}









void B_PLIST_DRAW_PrintNumberAt(char *p,int value,int slot,int id,u16 x,s16 y,u32 color)
{
    void *handle;
    void *buf;
    void *text;
    void *context;
    u32 width;
    handle=*(void **)(p+0x1F70+slot*8);
    buf=STRBUF_Create(16,((struct B_PlistWork *)p)->owner->heapId);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,id);
    WORDSET_SetSlotFromMsgCB(((struct B_PlistWork *)p)->wordSet,0,value);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet,buf,text);
    if (x==0xFFFF) {
        width=BMP_WIN_GetWidth(handle);
        x=((width<<3)-PRINTSYS_MeasureWidestLine(buf,((struct B_PlistWork *)p)->owner->font,0))>>1;
    }
    context=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(*(void **)(p+0x1F70+slot*8)),x,y,buf,((struct B_PlistWork *)p)->owner->font,(u16)color);
    *(u8 *)(p+slot*8+0x1F74)=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
}









void B_PLIST_DRAW_PrintTextAt(char *p, int i, s16 x, s16 y)
{
    void *t;
    void *f;
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x14);
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), x, y, t, ((struct B_PlistWork *)p)->owner->font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}









void B_PLIST_DRAW_PrintHeader(char *p, int id)
{
    void *t;
    void *f;
    BMP_Clear((void *)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[0].handle), 15);
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, id);
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[0].handle), 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x440);
    ((struct B_PlistWork *)p)->win[0].visible = 1;
    STRBUF_Delete(t);
    ((struct Flags *)p)->high = 1;
}









void B_PLIST_DRAW_PrintHeader9(char *p){B_PLIST_DRAW_PrintHeader(p,9);}









void B_PLIST_DRAW_PrintHeader10(char *p){B_PLIST_DRAW_PrintHeader(p,10);}









void B_PLIST_DRAW_PrintCenteredText(char *p, int i, int id)
{
    void *t;
    void *handle;
    void *f;
    u32 width;
    u32 font;
    s16 x;
    handle = *(void **)(p + 0x1F70 + i * 8);
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, id);
    width = PRINTSYS_MeasureWidestLine(t, ((struct B_PlistWork *)p)->owner->font, 0);
    font = ((struct B_PlistWork *)p)->owner->font;
    x = (s16)(((BMP_WIN_GetWidth(handle) << 3) - width) >> 1);
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), x, 5, t, font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}









void B_PLIST_DRAW_PrintStatsFields(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    void *thirdContext;
    u32 width;
    u16 x;
    elem=p+4+B_PLIST_MAIN_GetOrderIndex(p,index)*0x4C;
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x21);
    context=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[21].handle),0,0,text,((struct B_PlistWork *)p)->owner->font,0x3DC0);
    ((struct B_PlistWork *)p)->win[21].visible=1;
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x22);
    buf=STRBUF_Create(8,((struct B_PlistWork *)p)->owner->heapId);
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet,0,((struct B_PlistSlot *)elem)->levelBits.level,3,0,1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet,buf,text);
    secondContext=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(secondContext,(u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[13].handle),0,0,buf,((struct B_PlistWork *)p)->owner->font,0x3DC0);
    ((struct B_PlistWork *)p)->win[13].visible=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x23);
    thirdContext=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(thirdContext,(u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[22].handle),0,0,text,((struct B_PlistWork *)p)->owner->font,0x3DC0);
    ((struct B_PlistWork *)p)->win[22].visible=1;
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x24);
    buf=STRBUF_Create(14,((struct B_PlistWork *)p)->owner->heapId);
    if (((struct B_PlistSlot *)elem)->levelBits.level<100) {
        WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet,0,((struct B_PlistSlot *)elem)->expMax-((struct B_PlistSlot *)elem)->expCurrent,6,1,1);
    } else {
        WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet,0,0,6,1,1);
    }
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet,buf,text);
    width=BMP_WIN_GetWidth(((struct B_PlistWork *)p)->win[14].handle);
    x=(width<<3)-PRINTSYS_MeasureWidestLine(buf,((struct B_PlistWork *)p)->owner->font,0);
    context=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[14].handle),x,0,buf,((struct B_PlistWork *)p)->owner->font,0x2120);
    ((struct B_PlistWork *)p)->win[14].visible=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
}










static inline void put(Big *view, int win, int sel, s16 x, int h, int color)
{
    PRINTSYS_PrintQueColor((void *)win, (int)BMP_WIN_GetBmp((struct Descriptor *)sel), x, 0, (void *)h, view->owner->font, color);
}










/*
 * lever: both 0201C724 calls are one static inline helper; the centred x is a u8 local declared after v
 */
void B_PLIST_DRAW_PrintAttackStat(char *obj, int i)
{
    Big *view = (Big *)obj;
    char *entry = (char *)view + 4 + B_PLIST_MAIN_GetOrderIndex((u8 *)view, i) * 0x4c;
    int h1;
    int h2;
    int p;
    int v;
    unsigned char x;

    h1 = (int)MSGDATA_AllocString((struct MsgBank *)view->msgBank, 0x2a);
    put(view, view->printQue, view->win18, 0, h1, 0x3dc0);
    view->win18Visible = 1;
    STRBUF_Delete((struct U16Vec *)h1);

    h2 = (int)MSGDATA_AllocString((struct MsgBank *)view->msgBank, 0x2b);
    p = (int)STRBUF_Create(8, view->owner->heapId);
    WORDSET_SetSlotNumber((struct WordSet *)view->wordSet, 0, *(unsigned short *)(entry + 6), 3, 0, 1);
    WORDSET_CopyTaggedText((struct WordSet *)view->wordSet, (void *)p, (void *)h2);

    v = (unsigned char)PRINTSYS_MeasureWidestLine((struct StrObj *)p, view->owner->font, 0);
    x = (BMP_WIN_GetWidth((struct Descriptor *)view->win7) << 3) - v;
    put(view, view->printQue, view->win7, x, p, 0x2120);
    view->win7Visible = 1;
    STRBUF_Delete((struct U16Vec *)h2);
    STRBUF_Delete((struct U16Vec *)p);
}










void B_PLIST_DRAW_PrintDefenseStat(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + B_PLIST_MAIN_GetOrderIndex((u8 *)p, i) * 0x4c;
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x2c);
    x = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
    y = (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[17].handle);
    PRINTSYS_PrintQueColor((void *)x, y, 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x3dc0);
    ((struct B_PlistWork *)p)->win[17].visible = 1;
    STRBUF_Delete(t);
    t2 = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x2d);
    h = (u32)STRBUF_Create(8, ((struct B_PlistWork *)p)->owner->heapId);
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet, 0, ((struct B_PlistSlot *)elem)->active, 3, 0, 1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet, (void *)h, t2);
    b = PRINTSYS_MeasureWidestLine((struct StrObj *)h, ((struct B_PlistWork *)p)->owner->font, 0);
    c = (BMP_WIN_GetWidth(((struct B_PlistWork *)p)->win[8].handle) << 3) - b;
    d = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
    e = (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[8].handle);
    PRINTSYS_PrintQueColor((void *)d, e, c, 0, (void *)h, ((struct B_PlistWork *)p)->owner->font, 0x2120);
    ((struct B_PlistWork *)p)->win[8].visible = 1;
    STRBUF_Delete(t2);
    STRBUF_Delete((void *)h);
}










void B_PLIST_DRAW_PrintSpeedStat(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + B_PLIST_MAIN_GetOrderIndex((u8 *)p, i) * 0x4c;
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x32);
    x = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
    y = (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[18].handle);
    PRINTSYS_PrintQueColor((void *)x, y, 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x3dc0);
    ((struct B_PlistWork *)p)->win[18].visible = 1;
    STRBUF_Delete(t);
    t2 = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x33);
    h = (u32)STRBUF_Create(8, ((struct B_PlistWork *)p)->owner->heapId);
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet, 0, ((struct B_PlistSlot *)elem)->speed, 3, 0, 1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet, (void *)h, t2);
    b = PRINTSYS_MeasureWidestLine((struct StrObj *)h, ((struct B_PlistWork *)p)->owner->font, 0);
    c = (BMP_WIN_GetWidth(((struct B_PlistWork *)p)->win[9].handle) << 3) - b;
    d = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
    e = (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[9].handle);
    PRINTSYS_PrintQueColor((void *)d, e, c, 0, (void *)h, ((struct B_PlistWork *)p)->owner->font, 0x2120);
    ((struct B_PlistWork *)p)->win[9].visible = 1;
    STRBUF_Delete(t2);
    STRBUF_Delete((void *)h);
}










void B_PLIST_DRAW_PrintSpAttackStat(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + B_PLIST_MAIN_GetOrderIndex((u8 *)p, i) * 0x4c;
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x2e);
    x = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
    y = (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[19].handle);
    PRINTSYS_PrintQueColor((void *)x, y, 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x3dc0);
    ((struct B_PlistWork *)p)->win[19].visible = 1;
    STRBUF_Delete(t);
    t2 = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x2f);
    h = (u32)STRBUF_Create(8, ((struct B_PlistWork *)p)->owner->heapId);
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet, 0, ((struct B_PlistSlot *)elem)->spAttack, 3, 0, 1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet, (void *)h, t2);
    b = PRINTSYS_MeasureWidestLine((struct StrObj *)h, ((struct B_PlistWork *)p)->owner->font, 0);
    c = (BMP_WIN_GetWidth(((struct B_PlistWork *)p)->win[10].handle) << 3) - b;
    d = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
    e = (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[10].handle);
    PRINTSYS_PrintQueColor((void *)d, e, c, 0, (void *)h, ((struct B_PlistWork *)p)->owner->font, 0x2120);
    ((struct B_PlistWork *)p)->win[10].visible = 1;
    STRBUF_Delete(t2);
    STRBUF_Delete((void *)h);
}










void B_PLIST_DRAW_PrintSpDefenseStat(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + B_PLIST_MAIN_GetOrderIndex((u8 *)p, i) * 0x4c;
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x30);
    x = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
    y = (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[20].handle);
    PRINTSYS_PrintQueColor((void *)x, y, 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x3dc0);
    ((struct B_PlistWork *)p)->win[20].visible = 1;
    STRBUF_Delete(t);
    t2 = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x31);
    h = (u32)STRBUF_Create(8, ((struct B_PlistWork *)p)->owner->heapId);
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet, 0, ((struct B_PlistSlot *)elem)->spDefense, 3, 0, 1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet, (void *)h, t2);
    b = PRINTSYS_MeasureWidestLine((struct StrObj *)h, ((struct B_PlistWork *)p)->owner->font, 0);
    c = (BMP_WIN_GetWidth(((struct B_PlistWork *)p)->win[11].handle) << 3) - b;
    d = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
    e = (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[11].handle);
    PRINTSYS_PrintQueColor((void *)d, e, c, 0, (void *)h, ((struct B_PlistWork *)p)->owner->font, 0x2120);
    ((struct B_PlistWork *)p)->win[11].visible = 1;
    STRBUF_Delete(t2);
    STRBUF_Delete((void *)h);
}









void B_PLIST_DRAW_PrintDualValue(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    u32 width;
    u32 otherWidth;
    u16 x;
    elem=p+4+B_PLIST_MAIN_GetOrderIndex(p,index)*0x4C;
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x26);
    context=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[15].handle),0,0,text,((struct B_PlistWork *)p)->owner->font,0x3DC0);
    ((struct B_PlistWork *)p)->win[15].visible=1;
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x29);
    width=PRINTSYS_MeasureWidestLine(text,((struct B_PlistWork *)p)->owner->font,0);
    x=((BMP_WIN_GetWidth(((struct B_PlistWork *)p)->win[6].handle)<<3)-width)>>1;
    secondContext=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(secondContext,(u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[6].handle),x,0,text,((struct B_PlistWork *)p)->owner->font,0x2120);
    ((struct B_PlistWork *)p)->win[6].visible=1;
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x27);
    buf=STRBUF_Create(8,((struct B_PlistWork *)p)->owner->heapId);
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet,0,((struct B_PlistSlot *)elem)->hp,3,0,1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet,buf,text);
    otherWidth=PRINTSYS_MeasureWidestLine(buf,((struct B_PlistWork *)p)->owner->font,0);
    context=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[6].handle),(x-otherWidth),0,buf,((struct B_PlistWork *)p)->owner->font,0x2120);
    ((struct B_PlistWork *)p)->win[6].visible=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x28);
    buf=STRBUF_Create(8,((struct B_PlistWork *)p)->owner->heapId);
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet,0,((struct B_PlistSlot *)elem)->maxHp,3,0,1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet,buf,text);
    context=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[6].handle),(x+width),0,buf,((struct B_PlistWork *)p)->owner->font,0x2120);
    ((struct B_PlistWork *)p)->win[6].visible=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
}









void B_PLIST_DRAW_PrintBankEntry(char *p, int index)
{
    char *elem;
    void *bank;
    void *t;
    void *f;
    elem = p + 4 + B_PLIST_MAIN_GetOrderIndex((u8 *)p, index) * 0x4C;
    bank = MSGDATA_CreateFromArchive(0, 2, 0xB7, ((struct B_PlistWork *)p)->owner->heapId);
    t = MSGDATA_AllocString(bank, ((struct B_PlistSlot *)elem)->abilityId);
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(((struct B_PlistWork *)p)->win[4].handle), 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x2120);
    ((struct B_PlistWork *)p)->win[4].visible = 1;
    STRBUF_Delete(t);
    MSGDATA_Delete(bank);
}









void B_PLIST_DRAW_PrintAccuracyLabel(char *p, int i)
{
    void *t;
    void *f;
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x3D);
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}










void B_PLIST_DRAW_PrintAccuracyValue(char *p, int winIndex, int value)
{
    u32 handle;
    void *t;
    u16 w;

    handle = *(u32 *)(p + 0x1f70 + winIndex * 8);
    if (value == 0) {
        u32 f;

        t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x3c);
        w = PRINTSYS_MeasureWidestLine((struct StrObj *)((u32)t), ((struct B_PlistWork *)p)->owner->font, 0);
        w = (BMP_WIN_GetWidth((void *)handle) << 3) - w;
        f = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
        PRINTSYS_PrintQueColor((void *)f,
                      (u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + 0x1f70 + winIndex * 8)), w, 0,
                      t, ((struct B_PlistWork *)p)->owner->font, 0x2120);
        *(u8 *)(p + winIndex * 8 + 0x1f74) = 1;
        STRBUF_Delete(t);
    } else {
        void *t2;
        u32 h;
        u32 f;
        u16 w0;
        u16 w2;

        t2 = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x3e);
        h = (u32)STRBUF_Create(8, ((struct B_PlistWork *)p)->owner->heapId);
        WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet, 0, value, 3, 0, 1);
        WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet, (void *)h, t2);
        w0 = PRINTSYS_MeasureWidestLine((struct StrObj *)h, ((struct B_PlistWork *)p)->owner->font, 0);
        w2 = (BMP_WIN_GetWidth((void *)handle) << 3) - w0;
        f = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
        PRINTSYS_PrintQueColor((void *)f,
                      (u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + 0x1f70 + winIndex * 8)), w2, 0,
                      (void *)h, ((struct B_PlistWork *)p)->owner->font, 0x2120);
        *(u8 *)(p + winIndex * 8 + 0x1f74) = 1;
        STRBUF_Delete(t2);
        STRBUF_Delete((void *)h);
    }
}









void B_PLIST_DRAW_PrintPowerLabel(char *p, int i)
{
    void *t;
    void *f;
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x3A);
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}










void B_PLIST_DRAW_PrintPowerValue(char *p, int winIndex, u32 value)
{
    u32 handle;
    void *t;
    u16 w;

    handle = *(u32 *)(p + 0x1f70 + winIndex * 8);
    if (value <= 1) {
        u32 f;

        t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x3c);
        w = PRINTSYS_MeasureWidestLine((struct StrObj *)((u32)t), ((struct B_PlistWork *)p)->owner->font, 0);
        w = (BMP_WIN_GetWidth((void *)handle) << 3) - w;
        f = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
        PRINTSYS_PrintQueColor((void *)f,
                      (u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + 0x1f70 + winIndex * 8)), w, 0,
                      t, ((struct B_PlistWork *)p)->owner->font, 0x2120);
        *(u8 *)(p + winIndex * 8 + 0x1f74) = 1;
        STRBUF_Delete(t);
    } else {
        void *t2;
        u32 h;
        u32 f;
        u16 w0;
        u16 w2;

        t2 = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x3b);
        h = (u32)STRBUF_Create(8, ((struct B_PlistWork *)p)->owner->heapId);
        WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet, 0, value, 3, 0, 1);
        WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet, (void *)h, t2);
        w0 = PRINTSYS_MeasureWidestLine((struct StrObj *)h, ((struct B_PlistWork *)p)->owner->font, 0);
        w2 = (BMP_WIN_GetWidth((void *)handle) << 3) - w0;
        f = ((struct B_PlistWork *)p)->u1EAC.printQueWord;
        PRINTSYS_PrintQueColor((void *)f,
                      (u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + 0x1f70 + winIndex * 8)), w2, 0,
                      (void *)h, ((struct B_PlistWork *)p)->owner->font, 0x2120);
        *(u8 *)(p + winIndex * 8 + 0x1f74) = 1;
        STRBUF_Delete(t2);
        STRBUF_Delete((void *)h);
    }
}









void B_PLIST_DRAW_PrintMoveDescription(char *p, int i, int id)
{
    void *bank;
    void *t;
    void *f;
    bank = MSGDATA_CreateFromArchive(0, 2, 0xCA, ((struct B_PlistWork *)p)->owner->heapId);
    t = MSGDATA_AllocString(bank, id);
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
    MSGDATA_Delete(bank);
}









void B_PLIST_DRAW_PrintCategoryLabel(char *p, int i)
{
    void *t;
    void *f;
    t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x3F);
    PRINTSYS_MeasureWidestLine(t, ((struct B_PlistWork *)p)->owner->font, 0);
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct B_PlistWork *)p)->owner->font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}









/*
 * note: the switch has no default; a selector outside 0..2 branches from
 *   0220D42C straight to the print tail with r7 (t) never assigned, as the
 *   image does. The earlier `default: return;` spelling was a guard the
 *   original lacks.
 */
void B_PLIST_DRAW_PrintCategoryName(char *p, int i, int selector)
{
    struct U16Vec *t;
    void *f;
    switch (selector) {
    case 0: t = MSGDATA_AllocString(*(struct MsgBank **)(p + 0x1EA0), 0x41); break;
    case 1: t = MSGDATA_AllocString(*(struct MsgBank **)(p + 0x1EA0), 0x40); break;
    case 2: t = MSGDATA_AllocString(*(struct MsgBank **)(p + 0x1EA0), 0x42); break;
    }
    f = *(void **)(p + 0x1EAC);
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x1F70 + i * 8)), 0, 0, t, *(u32 *)(*(char **)p + 12), 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}










/*
 * Near miss: the body is byte-for-byte right in shape; the residue is pure
 * register allocation / frame packing. The original keeps `handle` in r7
 * (used only for the 45738 call, then r7 is recycled by the shifted coordinate)
 * with `base` in [sp+0x1c] and `off` in r6, and packs the frame as
 * push {r3,r4,r5,r6,r7,lr} / sub sp,#0x40.  Naming base/off or inlining the
 * array, splitting f/y per block, and hoisting handle all leave the allocator
 * choosing a different split (5-reg push + #0x44) and one extra instruction.
 * Needs a different spelling of the three draw blocks; not an evidence problem.
 *
 * Re-verified (DIFF fixer): still 391 concrete bytes; all 15 relocations
 * resolve, so it is a frame-packing/allocation residue, not evidence.
 */
void B_PLIST_DRAW_PrintPpPair(u8 *p, int slot, int leftValue, int rightValue)
{
    u8 *tab;
    void *handle;
    void *text;
    u32 w1;
    u32 x;
    u32 ctx1;
    u8 *fl;
    void *text2;
    void *h2;
    u32 w2;
    u32 ctx2;
    void *text3;
    void *h3;
    u32 ctx3;

    slot = slot * 8;
    tab = p + 0x1F70;
    handle = *(void **)(tab + slot);
    text = MSGDATA_AllocString(P->msgBank, 0x38);
    w1 = PRINTSYS_MeasureWidestLine(text, P->hdr->font, 0);
    x = ((BMP_WIN_GetWidth(handle) << 3) - w1) >> 1;
    ctx1 = P->printQue;
    PRINTSYS_PrintQueColor((void *)ctx1, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), x, 0, text, P->hdr->font, (u32)0x3DC0);
    fl = p + 0x1F74;
    fl[slot] = 1;
    STRBUF_Delete(text);
    text2 = MSGDATA_AllocString(P->msgBank, 0x36);
    h2 = STRBUF_Create(6, P->hdr->heapId);
    WORDSET_SetSlotNumber(P->wordSet, 0, leftValue, 3, 0, 1);
    WORDSET_CopyTaggedText(P->wordSet, h2, text2);
    w2 = PRINTSYS_MeasureWidestLine(h2, P->hdr->font, 0);
    ctx2 = P->printQue;
    PRINTSYS_PrintQueColor((void *)ctx2, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), (x - w2), 0, h2, P->hdr->font, (u32)0x3DC0);
    fl[slot] = 1;
    STRBUF_Delete(text2);
    STRBUF_Delete(h2);
    text3 = MSGDATA_AllocString(P->msgBank, 0x37);
    h3 = STRBUF_Create(6, P->hdr->heapId);
    WORDSET_SetSlotNumber(P->wordSet, 0, rightValue, 3, 0, 1);
    WORDSET_CopyTaggedText(P->wordSet, h3, text3);
    ctx3 = P->printQue;
    PRINTSYS_PrintQueColor((void *)ctx3, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), (x + w1), 0, h3, P->hdr->font, (u32)0x3DC0);
    fl[slot] = 1;
    STRBUF_Delete(text3);
    STRBUF_Delete(h3);
}









void B_PLIST_DRAW_PrintMoveRowLabel(char *p, int i)
{
    void *t;
    void *f;
    u32 width;
    if (((struct B_PlistWork *)p)->owner->moveKind == 4)
        t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x45);
    else
        t = MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank, 0x44);
    width = PRINTSYS_MeasureWidestLine(t, ((struct B_PlistWork *)p)->owner->font, 0);
    f = ((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), ((96 - width) >> 1), 5, t, ((struct B_PlistWork *)p)->owner->font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}









void B_PLIST_DRAW_PrintWordAndRefresh(u8 *p){void *s=MSGDATA_AllocString(*(struct MsgBank * *)&((struct B_PlistWork *)p)->msgBank,70);WORDSET_CopyTaggedText(*(struct WordSet * *)&((struct B_PlistWork *)p)->wordSet,((struct B_PlistWork *)p)->u1EA8.strBuf,s);STRBUF_Delete(s);B_PLIST_DRAW_ClearAndPrintStream(p);}









void B_PLIST_DRAW_PrintMoveRowValues(char *p,u8 *record,int slot)
{
    void *buf;
    void *text;
    void *context;
    void *secondContext;
    u32 width;
    u32 otherWidth;
    buf=STRBUF_Create(6,((struct B_PlistWork *)p)->owner->heapId);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x35);
    context=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(*(void **)(p+0x1F70+slot*8)),40,24,text,((struct B_PlistWork *)p)->owner->font,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x38);
    width=PRINTSYS_MeasureWidestLine(text,((struct B_PlistWork *)p)->owner->font,0);
    secondContext=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(secondContext,(u32)BMP_WIN_GetBmp(*(void **)(p+0x1F70+slot*8)),80,24,text,((struct B_PlistWork *)p)->owner->font,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x37);
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet,0,record[3],2,0,1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet,buf,text);
    context=((struct B_PlistWork *)p)->u1EAC.printQue;
    width+=80;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(*(void **)(p+0x1F70+slot*8)),width,24,buf,((struct B_PlistWork *)p)->owner->font,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(((struct B_PlistWork *)p)->msgBank,0x36);
    WORDSET_SetSlotNumber(((struct B_PlistWork *)p)->wordSet,0,record[2],2,0,1);
    WORDSET_CopyTaggedText(((struct B_PlistWork *)p)->wordSet,buf,text);
    otherWidth=PRINTSYS_MeasureWidestLine(buf,((struct B_PlistWork *)p)->owner->font,0);
    context=((struct B_PlistWork *)p)->u1EAC.printQue;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(*(void **)(p+0x1F70+slot*8)),(80-otherWidth),24,buf,((struct B_PlistWork *)p)->owner->font,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
}









void B_PLIST_DRAW_DrawRows(u8 *p)
{
    s16 i;
    int idx;

    *(void **)(p + 0x253C) = d_02211AFF;
    for (i = 0; i < 6; i++) {
        BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp(*(struct Descriptor **)(p + i * 8 + 0x1F70)), 0);
        idx = B_PLIST_MAIN_GetOrderIndex(p, i);
        if (((Rec *)p)[idx].cnt == 0) {
            *(u8 *)(p + i * 8 + 0x1F74) = 1;
        } else {
            B_PLIST_DRAW_PrintRowName(p, i, (u16)i, 0x20, 7);
            if (!((Rec *)p)[idx].fl.high) {
                B_PLIST_DRAW_DrawRowValueBars(p, (u8)i);
            }
            if (APP_ICON_GetStatusIconAnim((int)(((Rec *)p)[idx].obj)) == 8) {
                B_PLIST_DRAW_PrintValueIfUnset(p, (u8)i);
            }
        }
    }
}









void B_PLIST_DRAW_DrawRowValueBars(u8 *p, int i)
{
    char *base;
    base = (char *)p + 0x1f70;
    BMP_FillRect(BMP_WIN_GetBmp(*(void **)(base + i * 8)), 92, 32, 24, 8, 0);
    BMP_FillRect(BMP_WIN_GetBmp(*(void **)(base + i * 8)), 64, 24, 64, 8, 0);
    B_PLIST_DRAW_PrintNameWithValues(p, i, i, 92, 32);
    B_PLIST_DRAW_FillTypeBar(p, i, i, 64, 24);
}









void B_PLIST_DRAW_PrintValueIfUnset(u8 *p,int a){if(((Bits *)(p+(u32)B_PLIST_MAIN_GetOrderIndex(p,a)*76+0x1b))->high==0)B_PLIST_DRAW_PrintSlotValue(p,a,a,8,32);}












void B_PLIST_DRAW_DrawMonMenuPage(char *p)
{
    int state, id, i;
    void *obj;
    *(u8 * *)&((struct B_PlistWork *)p)->toolWinIds = d_02211AF4;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    B_PLIST_DRAW_DrawRowCenteredName((u8 *)p, (*(u8 **)p)[32]);
    state = B_PLIST_MAIN_GetRowStatus((u8 *)p);
    if (state == 2) id = 26;
    else if (state == 3) id = 27;
    else if (state == 4) id = 28;
    else if (state == 1) id = 29;
    else id = 21;
    B_PLIST_DRAW_PrintCenteredText(p,1,id);
    i = B_PLIST_MAIN_GetOrderIndex((u8 *)p, (*(u8 **)p)[32]);
    if (((struct B_PlistSlot *)(p + i * 76))->u1A.bits.flags.high == 0) {
        B_PLIST_DRAW_PrintCenteredText(p,2,24);
        B_PLIST_DRAW_PrintCenteredText(p,3,25);
        return;
    }
    obj = ((struct B_PlistWork *)p)->win[4].handle;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(obj));
    obj = ((struct B_PlistWork *)p)->win[5].handle;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(obj));
}













static inline u8 center_x(int w)
{
    return w / 2;
}













static inline void put_slot(u8 *p, void *win, void *sel, short x, u32 y, void *h, u16 color)
{
    PRINTSYS_PrintQueColor(win, (u32)BMP_WIN_GetBmp(sel), x, y, h, *(u32 *)(*(u8 **)p + 0xc), color);
    *(u8 *)(p + 0x1F74) = 1;
}













/*
 * lever: 2026-10-05 (wD9r lane160): three source facts. (1) half is a narrow local: the centre is a static
 *   inline `u8 center_x(int w)` (signed /2) assigned to a `short half`, and t is u8; the put x and the callee x
 *   are short, so half reaches the first call with no s16 conversion and its reload stays below the outgoing
 *   stack stores. (2) The dirty flag store p[0x1F74] = 1 is inside the put helper, which keeps the 0x1EAC base
 *   in r5 across the arms and frees the msg2 arms for cross-jumping. (3) a short (not u8) half takes its
 *   declaration slot 0x18 above the window temps; a u8 half takes the lowest slot. Before: DIFF 153.
 */
void B_PLIST_DRAW_DrawRowCenteredName(u8 *p, int idx)
{
    void *msg;
    u32 off;
    void *o;
    struct B_PlistSlotView *rec;
    void *vec;
    u8 t;
    short half;
    void *msg2;
    int a;
    int b;
    u8 *base;
    int n;

    o = *(void **)(p + 0x1F70);
    n = B_PLIST_MAIN_GetOrderIndex(p, idx);
    base = p + 4;
    off = n * 0x4c;
    rec = (struct B_PlistSlotView *)(base + off);
    vec = STRBUF_Create(12, *(u16 *)(*(u8 **)p + 0x10));
    msg = MSGDATA_AllocString(*(struct MsgBank **)(p + 0x1EA0), d_02211B68[idx]);
    WORDSET_SetSlotMonNickname(*(struct WordSet **)(p + 0x1EA4), 0, *(void **)rec);
    msg2 = 0;
    WORDSET_CopyTaggedText(*(struct WordSet **)(p + 0x1EA4), vec, msg);
    STRBUF_Delete(msg);
    if (!rec->a1 && !rec->b2) {
        if (rec->b0 == 0) {
            msg2 = MSGDATA_AllocString(*(struct MsgBank **)(p + 0x1EA0), 0x16);
        } else if (rec->b0 == 1) {
            msg2 = MSGDATA_AllocString(*(struct MsgBank **)(p + 0x1EA0), 0x17);
        }
    }
    a = 0;
    t = PRINTSYS_MeasureWidestLine(vec, *(u32 *)(*(u8 **)p + 0xc), 0);
    if (msg2 == 0) {
        b = 0;
    } else {
        a = (u8)PRINTSYS_MeasureWidestLine(msg2, *(u32 *)(*(u8 **)p + 0xc), a);
        b = 8;
    }
    half = center_x(BMP_WIN_GetWidth(o) * 8 - t - a - b);
    put_slot(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), half, 7, vec, 0x3DC0);
    STRBUF_Delete(vec);
    if (msg2 != 0) {
        if (rec->b0 == 0) {
            put_slot(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), b + (half + t), 8, msg2, 0x2960);
        } else {
            put_slot(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), b + (half + t), 8, msg2, 0x31A0);
        }
        STRBUF_Delete(msg2);
    }
}












void B_PLIST_DRAW_DrawMoveListPage(char *p)
{
    long i;
    int index, offset;
    char *base, *rec;
    u16 value;
    *(u8 * *)&((struct B_PlistWork *)p)->toolWinIds = d_02211B06;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    B_PLIST_DRAW_PrintRowName((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base = (char *)p + 0x30;
    for (i=0; i<4u; i++) {
        offset = i * 8;
        value = ((u16 *)(rec = base + B_PLIST_MAIN_GetOrderIndex((u8 *)p,(*(u8 **)p)[32]) * 76))[i * 4];
        if (value == 0) *(u8 *)(p + offset + 0x1f7c) = 1;
        else {
            B_PLIST_DRAW_PrintNumberAt((char *)p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            B_PLIST_DRAW_PrintMoveRowValues((char *)p,(u8 *)(rec+offset),i+1);
        }
    }
    B_PLIST_DRAW_PrintCenteredText((char *)p,5,24);
}












void B_PLIST_DRAW_DrawSummaryPage(char *p) {
    *(u8 * *)&((struct B_PlistWork *)p)->toolWinIds=d_02211B50;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    B_PLIST_DRAW_PrintRowName((u8 *)p,0,(*(u8 **)p)[32],0,0);
    B_PLIST_DRAW_PrintDualValue((u8 *)p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_FillTypeBar((u8 *)p,10,(*(u8 **)p)[32],0,0);
    BMP_WIN_TransferChars(((struct B_PlistWork *)p)->win[12].handle);
    B_PLIST_DRAW_PrintStatsFields((u8 *)p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintAttackStat(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintDefenseStat(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintSpeedStat(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintSpAttackStat(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintSpDefenseStat(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintRowValue((u8 *)p,1,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintItemOrName(p,3,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintBankEntry(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintCenteredText(p,21,25);
}












void B_PLIST_DRAW_DrawMoveDetailPage(char *p) {
    u8 *owner;
    char *base,*rec;
    unsigned offset;
    *(u8 * *)&((struct B_PlistWork *)p)->toolWinIds=d_02211B20;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    owner=*(u8 * *)&((struct B_PlistWork *)p)->owner;
    base=p+0x30+B_PLIST_MAIN_GetOrderIndex((u8 *)p,owner[32])*76;
    offset=owner[0x4b]*8;
    rec=base+offset;
    B_PLIST_DRAW_PrintRowName((u8 *)p,6,owner[32],0,0);
    B_PLIST_DRAW_PrintTextAt(p,7,0,0);
    B_PLIST_DRAW_PrintNumberAt(p,*(u16 *)(base+offset),0,d_02211B3C[(*(u8 **)p)[0x4b]],0,0,0x3dc0);
    B_PLIST_DRAW_PrintAccuracyLabel(p,8);
    B_PLIST_DRAW_PrintAccuracyValue(p,2,(u8)rec[6]);
    B_PLIST_DRAW_PrintPowerLabel(p,9);
    B_PLIST_DRAW_PrintPowerValue(p,3,(u8)rec[7]);
    B_PLIST_DRAW_PrintMoveDescription(p,4,*(u16 *)(base+offset));
    B_PLIST_DRAW_PrintCategoryLabel(p,10);
    B_PLIST_DRAW_PrintCategoryName(p,5,(u8)rec[5]);
    B_PLIST_DRAW_PrintPpPair((u8 *)p,1,(u8)rec[2],(u8)rec[3]);
}












void B_PLIST_DRAW_DrawMoveListWithNewMovePage(char *p) {
    long i;
    int offset;
    char *base,*rec;
    u16 value;
    u8 local[8];
    *(u8 * *)&((struct B_PlistWork *)p)->toolWinIds=d_02211B0D;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    B_PLIST_DRAW_PrintRowName((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base=p+0x30;
    for(i=0;i<4u;i++) {
        offset=i*8;
        value=((u16 *)(rec=base+B_PLIST_MAIN_GetOrderIndex((u8 *)p,(*(u8 **)p)[32])*76))[i*4];
        if(value==0) *(u8 *)(p+offset+0x1f7c)=1;
        else {
            B_PLIST_DRAW_PrintNumberAt(p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            B_PLIST_DRAW_PrintMoveRowValues(p,(u8 *)(rec+offset),i+1);
        }
    }
    B_PLIST_DRAW_PrintNumberAt(p,((struct B_PlistWork *)p)->owner->moveId,5,0x53,65535,7,0x3dc0);
    local[2]=WAZA_TOOL_GetParam(((struct B_PlistWork *)p)->owner->moveId,5);
    local[3]=local[2];
    B_PLIST_DRAW_PrintMoveRowValues(p,(u8 *)local,5);
}












void B_PLIST_DRAW_DrawMoveDetailWithNewMovePage(char *p) {
    unsigned index,offset,type;
    char *base,*rec;
    *(u8 * *)&((struct B_PlistWork *)p)->toolWinIds=d_02211B2C;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    B_PLIST_DRAW_PrintRowName((u8 *)p,0,(*(u8 **)p)[32],0,0);
    B_PLIST_DRAW_PrintTextAt(p,2,0,0);
    B_PLIST_DRAW_PrintAccuracyLabel(p,4);
    B_PLIST_DRAW_PrintPowerLabel(p,5);
    B_PLIST_DRAW_PrintCategoryLabel(p,9);
    index=(*(u8 **)p)[0x4b];
    if(index<4) {
        base=p+0x30+B_PLIST_MAIN_GetOrderIndex((u8 *)p,(*(u8 **)p)[32])*76;
        offset=index*8;
        rec=base+offset;
        B_PLIST_DRAW_PrintNumberAt(p,*(u16 *)(base+offset),1,d_02211B3C[index],0,0,0x3dc0);
        B_PLIST_DRAW_PrintAccuracyValue(p,6,(u8)rec[6]);
        B_PLIST_DRAW_PrintPowerValue(p,7,(u8)rec[7]);
        B_PLIST_DRAW_PrintMoveDescription(p,8,*(u16 *)(base+offset));
        B_PLIST_DRAW_PrintCategoryName(p,10,(u8)rec[5]);
        B_PLIST_DRAW_PrintPpPair((u8 *)p,3,(u8)rec[2],(u8)rec[3]);
    } else {
        type=WAZA_TOOL_GetParam(((struct B_PlistWork *)p)->owner->moveId,5);
        B_PLIST_DRAW_PrintNumberAt(p,((struct B_PlistWork *)p)->owner->moveId,1,0x53,0,0,0x3dc0);
        B_PLIST_DRAW_PrintMoveDescription(p,8,((struct B_PlistWork *)p)->owner->moveId);
        if(WAZA_TOOL_IsAlwaysHit(((struct B_PlistWork *)p)->owner->moveId)==1) B_PLIST_DRAW_PrintAccuracyValue(p,6,0);
        else B_PLIST_DRAW_PrintAccuracyValue(p,6,WAZA_TOOL_GetParam(((struct B_PlistWork *)p)->owner->moveId,4));
        B_PLIST_DRAW_PrintPowerValue(p,7,WAZA_TOOL_GetParam(((struct B_PlistWork *)p)->owner->moveId,3));
        B_PLIST_DRAW_PrintCategoryName(p,10,WAZA_TOOL_GetParam(((struct B_PlistWork *)p)->owner->moveId,2));
        B_PLIST_DRAW_PrintPpPair((u8 *)p,3,type,type);
    }
    B_PLIST_DRAW_PrintMoveRowLabel(p,11);
}












void B_PLIST_DRAW_DrawMoveListForItemPage(char *p)
{
    long i;
    int index, offset;
    char *base, *rec;
    u16 value;
    *(u8 * *)&((struct B_PlistWork *)p)->toolWinIds = d_02211AF9;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    B_PLIST_DRAW_PrintRowName((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base = (char *)p + 0x30;
    for (i=0; i<4u; i++) {
        offset = i * 8;
        value = ((u16 *)(rec = base + B_PLIST_MAIN_GetOrderIndex((u8 *)p,(*(u8 **)p)[32]) * 76))[i * 4];
        if (value == 0) *(u8 *)(p + offset + 0x1f7c) = 1;
        else {
            B_PLIST_DRAW_PrintNumberAt((char *)p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            B_PLIST_DRAW_PrintMoveRowValues((char *)p,(u8 *)(rec+offset),i+1);
        }
    }
    if (FILE_UTIL_GetItemParam((void *)(((struct B_PlistWork *)p)->owner->itemId),40,((struct B_PlistWork *)p)->owner->heapId) == 0)
        B_PLIST_DRAW_PrintHeader((char *)p,104);
}












void B_PLIST_DRAW_ClearAndPrintStream(u8 *p){BMP_MENUWORK_DrawWindow(((struct B_PlistWork *)p)->win[1].handle,2,1,14);BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct B_PlistWork *)p)->win[1].handle),15);B_PLIST_DRAW_PrintStream((char *)p);}












/*
 * volatile: global pointer re-read at 0220E17C and 0220E196 before PRINTSYS_PrintStream.
 */
void B_PLIST_DRAW_PrintStream(char *p)
{
    int v;
    void *obj;
    v = MSG_SPEED_GetWait(GF_FONT_SetTextColor(1,2,0));
    ((struct B_PlistWork *)p)->u1EB0.printStreamWord = PRINTSYS_PrintStream(*(unsigned *)&((struct B_PlistWork *)p)->win[1].handle,0,0,*(unsigned *)&((struct B_PlistWork *)p)->u1EA8.strBuf,((struct B_PlistHost *)(((Context *)p)->global))->font,v,((struct B_PlistWork *)p)->u1D4.tcblWord,10,((struct B_PlistHost *)(((Context *)p)->global))->heapId,15);
    obj = ((struct B_PlistWork *)p)->win[1].handle;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(obj));
}












/*
 * lever: the row pointer p + 4 + idx * 0x4c is one statement before the
 *   MSGDATA_AllocString allocation, so p + 4 (r6) and idx * 0x4c (r7) stay live
 *   across it and the allocation result spills to [sp]; computing the row
 *   address only at its use (the earlier note's base + i) left t in r7 and
 *   rematerialised p + 4 after the call (DIFF 16).
 */
void B_PLIST_DRAW_FormatRowWord(u8 *p)
{
    u8 *row;
    void *t;
    row = p + 4 + B_PLIST_MAIN_GetOrderIndex(p, (*(u8 **)p)[32]) * 0x4c;
    t = MSGDATA_AllocString(*(struct MsgBank **)(p + 0x1ea0), 105);
    WORDSET_SetSlotMonNickname(*(struct WordSet **)(p + 0x1ea4), 0, *(void **)row);
    WORDSET_SetSlotFromMsgCB(*(struct WordSet **)(p + 0x1ea4), 1, 373);
    WORDSET_CopyTaggedText(*(struct WordSet **)(p + 0x1ea4), *(void **)(p + 0x1ea8), t);
    STRBUF_Delete(t);
}












/*
 * evidence: enum offset k retained across the call; j saves k+0x10 before k-=0xb4. Parenthesised offsets and the sequenced local match the 48-byte original.
 */
void B_PLIST_DRAW_UpdateToolWindows(u8 *p){enum{K=0x1f60}k=K;u32 j;B_APP_TOOL_Update((struct Entry *)(p+k),*(int *)(p+(k-0xb4)),2);j=k+0x10;k-=0xb4;B_APP_TOOL_Update((struct Entry *)(p+j),*(int *)(p+k),p[0x2174]);}












void B_PLIST_DRAW_ShowToolWindows(u8 *p){B_APP_TOOL_ShowWindows((char *)p+0x1f70,*(u8 * *)&((struct B_PlistWork *)p)->toolWinIds);B_PLIST_DRAW_ShowSubWindow(p);}












void B_PLIST_DRAW_ShowSubWindow(u8 *p){if(((struct B_PlistWork *)p)->stateFlags.flags==1){BMP_MENUWORK_DrawWindow(((struct B_PlistWork *)p)->win[0].handle,2,1,14);B_APP_TOOL_ShowWindow(p+0x1f60);((struct B_PlistWork *)p)->stateFlags.flags=0;}}












/*
 * extent: 0220E2F6 alignment padding.
 */
void B_PLIST_DRAW_Init(char *p)
{
    B_PLIST_DRAW_ClearIds(p);
    B_PLIST_DRAW_RegisterRowCharacters((u8 *)p);
    B_PLIST_DRAW_RegisterIconSet1(p);
    B_PLIST_DRAW_RegisterIconSet3(p);
    B_PLIST_DRAW_RegisterIconSet2(p);
    B_PLIST_DRAW_RegisterIconSet4(p);
    B_PLIST_DRAW_RegisterIconSet5(p);
    B_PLIST_DRAW_CreateActors(p);
    B_PLIST_MAIN_CreateToolActors((u8 *)p);
    BG_SYS_SetSubPlaneVisible(16, 1);
}












void B_PLIST_DRAW_ClearIds(char *p)
{
    unsigned int i;
    for (i = 0; i < 26; i++) *(int *)(p + i * 4 + 0x24a4) = -1;
    for (i = 0; i < 6; i++) *(int *)(p + i * 4 + 0x250c) = -1;
    for (i = 0; i < 6; i++) *(int *)(p + i * 4 + 0x2524) = -1;
}













/*
 * pass 2 2026-10-06 P2L21: EXACT (was 9 bytes off, arc/arr r6/r7 swap). Closing form: the A6C8 call and the
 *   array store written in each if/else arm, with the store address as integer arithmetic
 *   `*(int *)((u32)p + 0x24A4 + i * 4)` (no named array pointer; LICM hoists p + 0x24A4, the ov097 021F6F88
 *   `icons + i * 4` style). Either part alone stays at 9 bytes (named arr in both arms, or the integer
 *   address with one join store). EXACT in --lang c99 and --lang c.
 */
void B_PLIST_DRAW_RegisterRowCharacters(u8 *p)
{
    void *arc;
    u16 i;

    arc = ARC_TOOL_CreateHandle(7, (u16)((*(u16 *)(*(u8 **)p + 0x10) & 0x7FFF) | 0x8000));
    for (i = 0; i < 6; i++) {
        u8 *e = p + i * 0x4C;
        if (*(u16 *)(e + 8) != 0) {
            *(int *)((u32)p + 0x24A4 + i * 4) = CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(POKE_TOOL_GetBoxParam(*(void **)(e + 4))), 0, 1, *(u16 *)(*(u8 **)p + 0x10));
        } else {
            *(int *)((u32)p + 0x24A4 + i * 4) = CLACT_RegisterCharacter(arc, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 1, *(u16 *)(*(u8 **)p + 0x10));
        }
    }
    *(int *)(p + 0x250C) = CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 1, 0, *(u16 *)(*(u8 **)p + 0x10));
    *(s32 *)(p + 0x2524) = CLACT_RegisterCellAnim(arc, POKE_TOOL_GetIconCellArcIdSub(), POKE_TOOL_GetIconCellEntryIdSub(), *(u16 *)(*(u8 **)p + 0x10));
    ARC_TOOL_DeleteHandle(arc);
}












void B_PLIST_DRAW_RegisterIconSet1(char *p)
{
    void *owner;
    owner = ARC_TOOL_CreateHandle(83,(u16)((((struct B_PlistWork *)p)->owner->heapId & 0x7fff) | 0x8000));
    ((struct B_PlistWork *)p)->field24BC = CLACT_RegisterCharacter(owner, 12, 0, 1, ((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->field2510 = CLACT_RegisterPalette(owner, 11, 1, 96, ((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->field2528 = CLACT_RegisterCellAnim(owner, 13, 16, ((struct B_PlistWork *)p)->owner->heapId);
    ARC_TOOL_DeleteHandle(owner);
}












void B_PLIST_DRAW_RegisterIconSet2(char *p)
{
    void *owner;
    unsigned i;
    owner = ARC_TOOL_CreateHandle(83,(u16)((((struct B_PlistWork *)p)->owner->heapId & 0x7fff) | 0x8000));
    ((struct B_PlistWork *)p)->typeIconPal = CLACT_RegisterPalette(owner, 33, 1, 160, ((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->typeIconCell = CLACT_RegisterCellAnim(owner, 59, 62, ((struct B_PlistWork *)p)->owner->heapId);
    for (i = 8; i <= 21; i++)
        ((int *)(p + 0x24a4))[i] = CLACT_RegisterCharacter(owner, APP_ICON_GetTypeCellFileId(0), 0, 1, ((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->moveKindChar = CLACT_RegisterCharacter(owner, APP_ICON_GetMoveKindCellFileId(0), 0, 1, ((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->moveKindCharAlt = CLACT_RegisterCharacter(owner, APP_ICON_GetMoveKindCellFileId(0), 0, 1, ((struct B_PlistWork *)p)->owner->heapId);
    ARC_TOOL_DeleteHandle(owner);
}












void B_PLIST_DRAW_RegisterIconSet3(char *p)
{
    void *owner;
    owner = ARC_TOOL_CreateHandle(83,(u16)((((struct B_PlistWork *)p)->owner->heapId & 0x7fff) | 0x8000));
    ((struct B_PlistWork *)p)->field24C0 = CLACT_RegisterCharacter(owner, 65, 0, 1, ((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->field2514 = CLACT_RegisterPalette(owner, 66, 1, 128, ((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->field252C = CLACT_RegisterCellAnim(owner, 67, 70, ((struct B_PlistWork *)p)->owner->heapId);
    ARC_TOOL_DeleteHandle(owner);
}












void B_PLIST_DRAW_RegisterIconSet4(char *p)
{
    void *owner;
    owner=ARC_TOOL_CreateHandle(11,(u16)((((struct B_PlistWork *)p)->owner->heapId&0x7fff)|0x8000));
    ((struct B_PlistWork *)p)->toolChar=CLACT_RegisterCharacter(owner,119,0,1,((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->toolPal=CLACT_RegisterPaletteEx(owner,116,1,256,4,1,((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->toolCell=CLACT_RegisterCellAnim(owner,120,121,((struct B_PlistWork *)p)->owner->heapId);
    ARC_TOOL_DeleteHandle(owner);
}












void B_PLIST_DRAW_RegisterIconSet5(char *p)
{
    void *owner;
    int first;
    owner=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),(u16)((((struct B_PlistWork *)p)->owner->heapId&0x7fff)|0x8000));
    ((struct B_PlistWork *)p)->gearChar=CLACT_RegisterCharacter(owner,APP_ICON_GetGearCellFileId(0),0,1,((struct B_PlistWork *)p)->owner->heapId);
    ((struct B_PlistWork *)p)->gearPal=CLACT_RegisterPalette(owner,APP_ICON_GetNoneFileId(),1,0x120,((struct B_PlistWork *)p)->owner->heapId);
    first=APP_ICON_GetGearPaletteFileId(0);
    ((struct B_PlistWork *)p)->gearCell=CLACT_RegisterCellAnim(owner,first,APP_ICON_GetGearAnimFileId(0),((struct B_PlistWork *)p)->owner->heapId);
    ARC_TOOL_DeleteHandle(owner);
}












unsigned B_PLIST_DRAW_CreateActorFromParams(char *p,const int *q)
{
    Point point;
    point.x=0;
    point.y=0;
    point.z=0;
    point.a=q[4];
    point.b=q[3];
    return (unsigned)CLACT_CreateActor((void *)((struct B_PlistWork *)p)->u1EB8.unitId,*(unsigned *)(p+q[0]*4+0x24a4),*(unsigned *)(p+q[1]*4+0x250c),*(unsigned *)(p+q[2]*4+0x2524),&point,1,((struct B_PlistWork *)p)->owner->heapId);
}












void B_PLIST_DRAW_CreateActors(char *p)
{
    unsigned i;
    ((struct B_PlistWork *)p)->u1EB8.unitId=(unsigned int)CLACT_CreateUnit((unsigned)45,(unsigned)0,(u16)((((struct B_PlistWork *)p)->owner->heapId&0x7fff)|0x8000));
    for(i=0;i<41;i++) *(unsigned *)(p+i*4+0x1ebc)=B_PLIST_DRAW_CreateActorFromParams(p,d_02211DFC[i]);
    GFL_NET_RefreshWmIconAtTopRight(0,((struct B_PlistWork *)p)->owner->heapId);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(((struct B_PlistWork *)p)->u1D8.palAnmWord),(int)3,(int)0,(int)0x1e0);
    B_PLIST_DRAW_ApplyActorPalettes((BPlSummaryRec *)p);
}












void B_PLIST_DRAW_DeleteActors(char *p)
{
    unsigned i;
    for(i=0;i<41;i++) CLACT_DeleteActor(*(void **)(p+i*4+0x1ebc));
    B_APP_TOOL_DeleteActors(((struct B_PlistWork *)p)->u2188.ptr);
    for(i=0;i<26;i++) CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+0x24a4)));
    for(i=0;i<6;i++) CLACT_ReleasePalette((u32)(*(void **)(p+i*4+0x250c)));
    for(i=0;i<6;i++) CLACT_ReleaseCellAnim((u32)(*(void **)(p+i*4+0x2524)));
    CLACT_DeleteUnit(((struct B_PlistWork *)p)->u1EB8.unitPtr);
}












/*
 * Addresses are Black-image addresses.
 */
void B_PLIST_DRAW_PlaceActor(u8 *p, u32 b)
{
    CLACT_SetActorDrawEnable((struct Obj *)p, 1);
    CLACT_AddActorSurfacePos((struct Obj *)p, (const struct Vec2 *)b, 1);
}











void B_PLIST_DRAW_ApplyActorPalettes(BPlSummaryRec *records)
{
    char *p=(char *)records;
    char *flags;
    short i;
    unsigned value;
    i=0;
    flags=p+0x1b;
    for(;i<6;i++) {
        if(records[i].species!=0) {
            value=POKE_TOOL_CalcIconPalette(records[i].species,records[i].form,((BPlIconFlags *)(flags+i*0x4c))->half,((BPlIconFlags *)(flags+i*0x4c))->egg);
            CLACT_SetActorPaletteOffset(*(void **)(p+i*4+0x1ed8),value,1);
        }
    }
}











/*
 * Verified scratch one: EXACT 12 bytes, Thumb, dsi/1.1p1 -O4,p.
 *  * extern const u8 _PokeTypePltOffset[];
 * unsigned APP_ICON_GetTypePaletteOffset(u8 index){return _PokeTypePltOffset[index];}
 */
void B_PLIST_DRAW_TransferCharacter(char *p,void *obj,int index,int which)
{
    void *owner,*data;
    struct Sub0204A9D0 *out;
    owner=ARC_TOOL_CreateHandle(83,(u16)((*(u16 *)(*(char **)p+16)&0x7fff)|0x8000));
    data=ARC_UTIL_LoadScreenDataFromHandle((void *)((unsigned)owner),APP_ICON_GetTypeCellFileId((u8)which),0,(unsigned)&out,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    CLACT_TransferCharacter(*(unsigned *)(p+index*4+0x24a4),out);
    GFL_HEAP_Free(data);
    ARC_TOOL_DeleteHandle(owner);
    CLACT_SetActorPaletteOffset(obj,(unsigned)APP_ICON_GetTypePaletteOffset((u8)which),1);
}











/*
 * Verified scratch one: EXACT 12 bytes, Thumb, dsi/1.1p1 -O4,p.
 *  * extern const u8 _WazaKindPltOffset[];
 * unsigned APP_ICON_GetMoveKindPaletteOffset(u8 index){return _WazaKindPltOffset[index];}
 */
void B_PLIST_DRAW_TransferCharacterToggle(char *p,int first,int index,int which)
{
    void *owner,*data;
    struct Sub0204A9D0 *out;
    int toggle;
    toggle=((struct B_PlistWork *)p)->winFlags.e8b4.flip;
    first+=toggle;
    index+=toggle;
    owner=ARC_TOOL_CreateHandle(83,(u16)((*(u16 *)(*(char **)p+16)&0x7fff)|0x8000));
    data=ARC_UTIL_LoadScreenDataFromHandle((void *)((unsigned)owner),APP_ICON_GetMoveKindCellFileId((u8)which),0,(unsigned)&out,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    CLACT_TransferCharacter(*(int *)(p+index*4+0x24a4),out);
    GFL_HEAP_Free(data);
    ARC_TOOL_DeleteHandle(owner);
    CLACT_SetActorPaletteOffset(*(void **)(p+first*4+0x1ebc),(unsigned)APP_ICON_GetMoveKindPaletteOffset(which),1);
    ((struct B_PlistWork *)p)->winFlags.e8b4.flip^=1;
}











void B_PLIST_DRAW_SetActorAnim(int mode,u8 *p,const struct Vec2 *q) { if(mode==8)CLACT_AddActorSurfacePos((struct Obj *)p,q,1);else {CLACT_SetActorAnimSeq((struct Obj *)p,mode);B_PLIST_DRAW_PlaceActor(p,(u32)q);} }










void B_PLIST_DRAW_SwapActorPair(char *p,u8 *q,const Pair *pos)
{
    int first,index;
    char *base;
    if(((struct B_PlistWork *)p)->winFlags.e9a0.flip==0){first=25;index=8;}
    else{first=27;index=10;}
    base=p+0x1ebc;
    B_PLIST_DRAW_TransferCharacter(p,*(void **)(base+first*4),index,q[20]);
    B_PLIST_DRAW_PlaceActor(*(u8 **)(base+first*4),(unsigned)pos);
    if(q[20]!=q[21]){
        B_PLIST_DRAW_TransferCharacter(p,*(void **)(p+0x1ebc+(first+1)*4),index+1,q[21]);
        B_PLIST_DRAW_PlaceActor(*(u8 **)(p+0x1ebc+(first+1)*4),(unsigned)(pos+1));
    }
    ((struct B_PlistWork *)p)->winFlags.e9a0.flip^=1;
}










void B_PLIST_DRAW_SetActorAnimByMode(u32 mode,u8 *p,const struct Vec2 *q) { if(mode==0)CLACT_AddActorSurfacePos((struct Obj *)p,q,1);else {if(FILE_UTIL_IsMailItem(mode)==1)CLACT_SetActorAnimSeq((struct Obj *)p,1);else CLACT_SetActorAnimSeq((struct Obj *)p,0);B_PLIST_DRAW_PlaceActor(p,(u32)q);} }








void B_PLIST_DRAW_LayoutActors(char *p,unsigned mode)
{
    unsigned i;
    for(i=0;i<41;i++)CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x1ebc),0);
    switch(mode){
    case 0: case 8: B_PLIST_DRAW_LayoutPartyListPage((BPlLayoutRec *)p);return;
    case 1: B_PLIST_DRAW_LayoutMonMenuPage((BPlLayoutRec *)p);return;
    case 2: B_PLIST_DRAW_LayoutSummaryPage((u8 *)p);return;
    case 3: B_PLIST_DRAW_LayoutMoveListPage((u8 *)p);return;
    case 4: B_PLIST_DRAW_LayoutMoveDetailPage((u8 *)p);return;
    case 5: B_PLIST_DRAW_LayoutMoveListForItemPage((u8 *)p);return;
    case 6: B_PLIST_DRAW_LayoutMoveListWithNewMovePage((u8 *)p);return;
    case 7: B_PLIST_DRAW_LayoutMoveDetailWithNewMovePage((u8 *)p);return;
    }
}








/*
 * lever: the final pointer-table subscript preserves the unscaled index
 * spill and its fresh shift. Byte-offset pointer arithmetic CSEs that shift.
 */
void B_PLIST_DRAW_LayoutPartyListPage(BPlLayoutRec *records) {
    u8 *p=(u8 *)records;
    short i;
    int index,offset;
    Pair pair;
    for(i=0;i<6;i++) {
        index=B_PLIST_MAIN_GetOrderIndex(p,i);
        offset=index*76;
        if(*(u16 *)((char *)records+offset+8)!=0) {
            B_PLIST_DRAW_PlaceActor(*(u8 **)(p+index*4+0x1ed8),(unsigned)&d_02211DB4[i]);
            B_PLIST_DRAW_SetActorAnim(((Bits *)(p+0x1b))[offset].kind,*(u8 **)(p+index*4+0x1ef0),(const struct Vec2 *)(&d_02211DCC[i]));
            if(((Bits *)(p+0x1b))[offset].high==0)
                B_PLIST_DRAW_PlaceActor(*(u8 **)(p+index*4+0x1f08),(unsigned)&d_02211DE4[i]);
            pair=d_02211DB4[i];
            pair.x+=8;
            pair.y+=8;
            B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)((char *)records+offset+0x1e),((u8 **)(p+0x1ebc))[index],(const struct Vec2 *)(&pair));
        }
    }
}








/*
 * lever: a char cast only on the later resource access prevents CSE of
 * the base-plus-index sum, preserving the byte-offset spill across E7CC.
 */
void B_PLIST_DRAW_LayoutMonMenuPage(BPlLayoutRec *records)
{
    u8 *p=(u8 *)records;
    int i;
    Pair pair;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    pair=d_02211D34[0];
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(unsigned)&pair);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(p+i*0x4c+0x1e),*(u8 **)((char *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
}





void B_PLIST_DRAW_LayoutSummaryPage(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[4];
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(unsigned)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[13]));
    B_PLIST_DRAW_SwapActorPair((char *)p,rec,&d_02211D34[25]);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(((struct B_PlistSlot *)rec)->u1A.heldItem,*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    B_PLIST_DRAW_SetActorAnimByMode(((struct B_PlistSlot *)rec)->u1A.heldItem,*(u8 * *)&((struct B_PlistWork *)p)->resHandle,(const struct Vec2 *)(&d_02211D34[1]));
    B_PLIST_DRAW_PlaceActor(*(u8 * *)&((struct B_PlistWork *)p)->resHandle2,(unsigned)&d_02211D34[16]);
}




void B_PLIST_DRAW_LayoutMoveListPage(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i = B_PLIST_MAIN_GetOrderIndex(p, (*(u8 **)p)[0x20]);
    rec = p + 4 + i * 0x4c;
    pair = d_02211D34[15];
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p + i * 4 + 0x1ed8), (u32)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec + 0x17))->kind, *(u8 **)((char *)p + i * 4 + 0x1ef0), (const struct Vec2 *)&d_02211D34[14]);
    B_PLIST_DRAW_SwapActorPair((char *)p, rec, &d_02211D34[17]);
    pair.x += 8;
    pair.y += 8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(rec + 0x1a), *(u8 **)((const u8 *)p + i * 4 + 0x1ebc), (const struct Vec2 *)&pair);
    B_PLIST_MAIN_SyncMoveActors(p);
}




/*
 * note 2026-10-05 (wD6 lane16): EXACT. The 0x1ebc call is written in each arm of the idx if/else (tail-merged), so the
 *   0x1ED8 pool word stays CSE-live into it; the 0x1F58/0x1F5C read is a ternary of two loads; rec + k*8 + 0x31 as pointer adds.
 */
void B_PLIST_DRAW_LayoutMoveDetailPage(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    int idx;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[12];
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[11]));
    B_PLIST_DRAW_SwapActorPair((char *)p,rec,&d_02211D34[21]);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    if (((Flag *)(p+0x2175))->bit==0) {
        idx=(*(u8 **)p)[0x4b]+0x22;
        B_PLIST_DRAW_PlaceActor(*(u8 **)(p+idx*4+0x1ebc),(u32)&d_02211D34[9]);
    } else {
        idx=(*(u8 **)p)[0x4b]+0x1d;
        B_PLIST_DRAW_PlaceActor(*(u8 **)(p+idx*4+0x1ebc),(u32)&d_02211D34[9]);
    }
    B_PLIST_DRAW_PlaceActor(((Flag *)(p+0x2175))->high==0?((u8 **)p)[0x7d6]:((u8 **)p)[0x7d7],(u32)&d_02211D34[5]);
    B_PLIST_DRAW_TransferCharacterToggle((char *)p,0x27,0x16,*(rec+(*(u8 **)p)[0x4b]*8+0x31));
}




/*
 * lever: d_02211D34 is a non-const Pair array (a const one reorders the schedule).
 */
void B_PLIST_DRAW_LayoutMoveListWithNewMovePage(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[7];
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[6]));
    B_PLIST_DRAW_SwapActorPair((char *)p,rec,&d_02211D34[19]);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    B_PLIST_MAIN_SyncMoveActors(p);
}


void B_PLIST_DRAW_LayoutMoveDetailWithNewMovePage(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    unsigned n;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[8];
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[2]));
    B_PLIST_DRAW_SwapActorPair((char *)p,rec,&d_02211D34[23]);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    if(((Fl *)(p+0x2175))->a==0) B_PLIST_DRAW_PlaceActor(*(u8 **)(p+((*(u8 **)p)[0x4b]+0x22)*4+0x1ebc),(u32)&d_02211D34[3]);
    else B_PLIST_DRAW_PlaceActor(*(u8 **)(p+((*(u8 **)p)[0x4b]+0x1d)*4+0x1ebc),(u32)&d_02211D34[3]);
    if(((Fl *)(p+0x2175))->b==0) B_PLIST_DRAW_PlaceActor(*(u8 **)(p+0x1F58),(u32)&d_02211D34[10]);
    else B_PLIST_DRAW_PlaceActor(*(u8 **)(p+0x1F5C),(u32)&d_02211D34[10]);
    n=(*(u8 **)p)[0x4b];
    if(n<4) B_PLIST_DRAW_TransferCharacterToggle((char *)p,0x27,0x16,(rec+n*8)[0x31]);
    else B_PLIST_DRAW_TransferCharacterToggle((char *)p,0x27,0x16,WAZA_TOOL_GetParam(*(u16 *)(*(u8 **)p+0x26),2));
}

void B_PLIST_DRAW_LayoutMoveListForItemPage(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[7];
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[6]));
    B_PLIST_DRAW_SwapActorPair((char *)p,rec,&d_02211D34[19]);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    B_PLIST_MAIN_SyncMoveActors(p);
}
