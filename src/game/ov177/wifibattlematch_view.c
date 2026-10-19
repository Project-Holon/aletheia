/*
 * file:     wifibattlematch_view.c
 * unit:     yes
 * function: WIFIBATTLEMATCH_VIEW_Create, WIFIBATTLEMATCH_VIEW_Delete, WIFIBATTLEMATCH_VIEW_LoadBgPalette, WIFIBATTLEMATCH_VIEW_GetFrameIndex, WIFIBATTLEMATCH_VIEW_UpdateAnimation, WIFIBATTLEMATCH_VIEW_BlendColors, WIFIBATTLEMATCH_VIEW_DrawTaggedText, WIFIBATTLEMATCH_VIEW_CreateMainWindow, WIFIBATTLEMATCH_VIEW_DeleteMainWindow, WIFIBATTLEMATCH_VIEW_CreateStatusWindow, WIFIBATTLEMATCH_VIEW_DeleteStatusWindow, WIFIBATTLEMATCH_VIEW_DrawStatusWindow, WIFIBATTLEMATCH_VIEW_CreateDateWindow, WIFIBATTLEMATCH_VIEW_DeleteDateWindow, WIFIBATTLEMATCH_VIEW_DrawDateWindow, WIFIBATTLEMATCH_VIEW_UpdatePokeList, WIFIBATTLEMATCH_VIEW_StepMainWindow, WIFIBATTLEMATCH_VIEW_StepMainWindowIdle, WIFIBATTLEMATCH_VIEW_SetupMainWindow, WIFIBATTLEMATCH_VIEW_SetupDateWindow, WIFIBATTLEMATCH_VIEW_SetupTimeWindow, WIFIBATTLEMATCH_VIEW_UpdateWindow, WIFIBATTLEMATCH_VIEW_DeleteWindow, WIFIBATTLEMATCH_VIEW_CreatePokeActors, WIFIBATTLEMATCH_VIEW_DeletePokeActors, WIFIBATTLEMATCH_VIEW_CreatePokeActor, WIFIBATTLEMATCH_VIEW_DeletePokeActor, WIFIBATTLEMATCH_VIEW_CreateActorFromTable, WIFIBATTLEMATCH_VIEW_DeleteActorFromTable, WIFIBATTLEMATCH_VIEW_CreateActorFromInfo, WIFIBATTLEMATCH_VIEW_DeleteActorFromInfo, WIFIBATTLEMATCH_VIEW_CreateRecordWindow, WIFIBATTLEMATCH_VIEW_DeleteRecordWindow, WIFIBATTLEMATCH_VIEW_UpdateRecordWindow, WIFIBATTLEMATCH_VIEW_StepRecordWindow, WIFIBATTLEMATCH_VIEW_SetupRecordWindow, WIFIBATTLEMATCH_VIEW_UpdateRecordWindowInner, WIFIBATTLEMATCH_VIEW_DeleteRecordWin, WIFIBATTLEMATCH_VIEW_CreateRecordActor, WIFIBATTLEMATCH_VIEW_DeleteRecordActor, WIFIBATTLEMATCH_VIEW_CreateRecordActorFromRec, WIFIBATTLEMATCH_VIEW_DeleteRecordActorObj, WIFIBATTLEMATCH_VIEW_GetEntryValue, WIFIBATTLEMATCH_VIEW_CreateActorArray, WIFIBATTLEMATCH_VIEW_DeleteActorArray, WIFIBATTLEMATCH_VIEW_Noop, WIFIBATTLEMATCH_VIEW_SetActorVisible, WIFIBATTLEMATCH_VIEW_CreatePartyWindow, WIFIBATTLEMATCH_VIEW_DeletePartyWindow, WIFIBATTLEMATCH_VIEW_StepPartyWindow, WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt, WIFIBATTLEMATCH_VIEW_UpdatePartyWindow
 * address:  0x021E567C
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wifibattlematch_view.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_021E8DBC 0x021E8DBC data a1
 *   MI_CpuCopy8 0x02082D44 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   FX_SinCosTable_  0x020A1B38  data  a2
 *   NNS_GfdRegisterNewVramTransferTask    0x02061CA4  arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_Clear 0x02043B5C arm
 *   BG_SYS_GetScrollX 0x020407E8 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   d_021E8D36 0x021E8D36 data a1
 *   d_021E8CCE 0x021E8CCE data a1
 *   d_021E8D0E 0x021E8D0E data a1
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   REGULATION_Party_GetValue 0x0200B214 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   d_021E8CBE 0x021E8CBE data a1
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   d_021E8CEE 0x021E8CEE data a1
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 *   PMS_DRAW_IsPrintEnd 0x0202DC98 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   POKE_TOOL_GetIconPalette  0x0201BBE8  thumb  arm9
 *   PMS_DRAW_Create  0x0202DB0C  thumb  arm9
 *   PMS_DRAW_Print  0x0202DC48  thumb  arm9
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb  arm9
 *   PMS_DRAW_SetPrintColor  0x0202DE64  thumb  arm9
 *   PMS_DRAW_SetFollowBgScroll  0x0202DE68  thumb  arm9
 *   STRBUF_SetString  0x02045924  arm  arm9
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm  arm9
 *   CLACT_GetActorSurfacePos  0x0204B454  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   GFL_USE_StopSeSlot  0x020061F8  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb  arm9
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   WORDSET_SetSlotFromKeyedMessage  0x0201F094  thumb  arm9
 *   BG_SYS_GetBuf  0x0204162C  arm  arm9
 *   BG_SYS_ChangeScroll  0x02041EE4  arm  arm9
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb  arm9
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb  arm9
 *   WORDSET_SetSlotMonth  0x0201F230  thumb  arm9
 *   BG_SYS_FreeTiles  0x02040DA8  arm  arm9
 *   BG_SYS_DrawTileEx  0x020410D0  arm  arm9
 *   APP_ICON_GetArchiveId  0x020275E4  thumb  arm9
 *   APP_ICON_GetItemCellFileId  0x02027694  thumb  arm9
 *   APP_ICON_GetItemPaletteFileId  0x02027698  thumb  arm9
 *   APP_ICON_GetItemAnimFileId  0x0202769C  thumb  arm9
 *   APP_ICON_GetItemFrameFileId  0x020276A0  thumb  arm9
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb  arm9
 *   POKE_TOOL_GetIconCellArcId  0x0201BC40  thumb  arm9
 *   POKE_TOOL_GetIconCellEntryId  0x0201BCB4  thumb  arm9
 *   MYSTATUS_NameToStrbuf  0x02008500  thumb  arm9
 *   BATTLE_BOX_CreateParty  0x0200BAF4  thumb  arm9
 *   ARC_UTIL_UploadBgPaletteFromArchive  0x0204989C  arm  arm9
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm  arm9
 *   MYSTATUS_GetName  0x020084F4  thumb  arm9
 *   MYSTATUS_GetTrainerView  0x02008554  thumb  arm9
 *   MYSTATUS_GetNation  0x0200856C  thumb  arm9
 *   MYSTATUS_GetArea  0x02008570  thumb  arm9
 */
#include "wifibattlematch_graphic_shared_types.h"
#include "wifibattlematch_view_shared_types.h"

struct WordSet;

struct Rec;

struct StrObj;

struct Actor;

struct PtS;

struct Strbuf;

struct Rec1E;

struct PmsDraw;

struct MyStatus;

typedef signed short s16;

typedef struct { int a, b, c, d, e, f; } WifiBattleMatchViewRoot;

typedef struct { char pad[0x18]; unsigned short out[16], original[16], target[16], phase; } WifiBattleMatchViewAnimState;

typedef struct {
    u32 kind;            /* 0x00, REC[1] box kind */
    u16 count, pad6;     /* 0x04, BSUBWAY stat count */
    u32 name;            /* 0x08, avatar id (MYSTATUS_GetTrainerView), poke-actor index */
    void *total;         /* 0x0C, score (a + b), first GetEntryValue argument */
    u16 a, b;            /* 0x10 win count, 0x12 loss count */
} WifiBattleMatchViewMainInfo;

typedef enum 
{
  BG2 = 2,
  BG6 = 6
} Layer;

typedef struct { short x, y; } Pt;

typedef struct {
    unsigned count;      /* 0x000 */
    void *wins[30];      /* 0x004 */
    Slot slots[30];      /* 0x07c */
    void *objs[22];      /* 0x16c */
    void *chr[6];        /* 0x1c4 */
    char pad1dc[4];
    void *cell;          /* 0x1e0 */
    void *pal;           /* 0x1e4 */
    u32 actorPal;        /* 0x1e8 */
    u32 actorChr;        /* 0x1ec */
    u32 actorCell;       /* 0x1f0 */
    void *pal2;          /* 0x1f4 */
    void *chr2;          /* 0x1f8 */
    void *cell2;         /* 0x1fc */
    unsigned objCount;   /* 0x200 */
    short baseX[22];     /* 0x204 */
    u8 bg;               /* 0x230 */
    u8 palette;          /* 0x231 */
    u8 palSlot;          /* 0x232 */
    u8 spritePalSlot;
    u32 layer;           /* 0x234 */
    void *record;        /* 0x238 */
    u16 heap;            /* 0x23c */
    u16 pad23e;
    void *owner;         /* 0x240 */
} Work;

typedef struct { u8 a, b, c, d; } WinDef;

typedef struct {
    char pad0[0x94];
    unsigned date1;      /* 0x94 */
    unsigned date2;      /* 0x98 */
    unsigned pad9c;
    u16 statA0;          /* 0xa0 */
    u16 statA2;          /* 0xa2 */
    union { u32 total; struct { u16 a4, a6; } h; } statTotal; /* 0xa4 */
    u16 statA8;          /* 0xa8 */
} WifiBattleMatchViewStatusInfo;

/*
 * The date/time window reads the same 0xAC record as the status window. 0xA4
 * is one word the status view reads as a u32 and the time view as two u16,
 * the union the ov176 digitalcardcheck.c filler spells out
 * (union { u32 total; struct { u16 a4, a6; } h; }).
 */
typedef WifiBattleMatchViewStatusInfo WifiBattleMatchViewTimeInfo;

typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;

typedef struct {
    u32 owner;           /* 0x00 */
    void *win[8];        /* 0x04 */
    Slot ent[7];        /* 0x24 */
    char pad5c[0x64 - 0x5c];
    void *recordActor;          /* 0x64 */
    void *obj[5];        /* 0x68 */
    void *menu;          /* 0x7c */
    u16 recPal;          /* 0x80 */
    u16 recChr;          /* 0x82 */
    u16 recCell;         /* 0x84 */
    char pad86[0x88 - 0x86];
    unsigned count;      /* 0x88 */
    unsigned short base; /* 0x8c */
    unsigned short objBase[5]; /* 0x8e */
    u32 mode;            /* 0x98 */
} WifiBattleMatchViewRecordWork;

typedef struct {
    char pad0[0x28];
    unsigned score;      /* 0x28 */
    u32 losses;          /* 0x2c */
    void *total;           /* 0x30 */
    unsigned count;      /* 0x34 */
    char name[1];        /* 0x38 */
} WifiBattleMatchViewRecord;

typedef struct { unsigned char bg, x, y, w; } WinTemplate;

typedef struct {
    void *pal;
    void *chr[7];
    void *cell;
    void *palB;
    void *chrB;
    void *cellB;
    void *spr[14];
    void *win[6];
    Slot ent[6];
    unsigned count;
    short base[14];
} WifiBattleMatchViewPartyWork;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void MI_CpuFill8(void *, u8, u32);

extern u32 GFL_HEAP_Free(void *p);

extern void MI_CpuCopy8(const void *, void *, u32);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u16 mode);

extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *arc, u32 memberIdx, u32 unpackedOut, u32 flags);

extern void ARC_TOOL_DeleteHandle(void *);

extern void BG_SYS_Init(u32, u32, u32, u32);

extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void BG_SYS_FreeTiles(u32 idx, u32 count, u32 tile);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);

extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct WordSet *WORDSET_CreateDefault(u16 heap);

extern struct U16Vec *STRBUF_Create(u32 capacity, u16 heapId);

extern u8 BMP_WIN_GetWidth(struct Descriptor *p);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern u32 PRINTSYS_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 WORDSET_Delete(struct WordSet *p);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern void G2x_SetBlendAlpha_(void *, int, int, int, int);

extern void CLACT_AddActorSurfacePos(void *, const Pt *, u16);

extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void BG_SYS_PushTile(u32);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern u32 BG_SYS_GetScrollX(u32 layer);

extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

extern void PRINTSYS_PrintQueColor(struct PrintSys *p, void *a, u32 b, s16 c, struct U16Vec *s, u32 e, u16 f);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern void GFL_USE_PlaySeDefaultVolume(unsigned);


extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);

extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);

extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);

extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);

extern void MYSTATUS_NameToStrbuf(void *, void *);

extern void WORDSET_SetSlotMonth(struct WordSet *p, u32 i, u32 v);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern int POKE_TOOL_GetIconPaletteArcId(void);

extern int POKE_TOOL_GetIconCellArcId(void);

extern int POKE_TOOL_GetIconCellEntryId(void);

extern int CLACT_RegisterPaletteCompressed(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);

extern s32 REGULATION_Party_GetValue(struct Rec1E *p, u32 id, u8 n);

extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

extern u32 APP_ICON_GetArchiveId(void);

extern u32 APP_ICON_GetItemCellFileId(void);

extern u32 APP_ICON_GetItemPaletteFileId(void);

extern u32 APP_ICON_GetItemAnimFileId(u32);

extern u32 APP_ICON_GetItemFrameFileId(u32);

extern unsigned CLACT_RegisterPaletteEx(void *, unsigned, unsigned, unsigned short, unsigned short, unsigned short, unsigned short);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);

extern u32 POKE_TOOL_CalcIconPalette(u32, u32, u32, u32);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern void CLACT_DeleteActor(struct Obj *p);

extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);

extern void PMS_DRAW_SetFollowBgScroll(struct PmsDraw *p, u32 v);

extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);

extern u8 MYSTATUS_GetTrainerView(const struct MyStatus *obj);

extern void ARC_UTIL_UploadBgPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags);

extern u32 BG_SYS_GetBuf(int);

extern void BG_SYS_DrawTileEx(u32, u32, u32, u32, u8, u32, u8, u8, u8, u8);

extern void PMS_DRAW_Delete(struct Obj *p);

extern const void *MYSTATUS_GetName(const void *p);

extern u8 MYSTATUS_GetNation(const struct MyStatus *obj);

extern u8 MYSTATUS_GetArea(const struct MyStatus *obj);

extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);

extern void WORDSET_SetSlotFromKeyedMessage(struct WordSet *p, u32 i, u32 a, u32 n);

extern void PMS_DRAW_SetPrintColor(struct PmsDraw *p, u16 v);

extern void PMS_DRAW_Print(void *, void *, const void *, unsigned);

extern void PMS_DRAW_Main(u8 *p);

extern u32 PMS_DRAW_IsPrintEnd(struct PmsDraw *o);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

extern void GFL_USE_StopSeSlot(int i);

extern void *BATTLE_BOX_CreateParty(int box, int heap);

extern unsigned POKEPARTY_GetCount(void *party);

extern void *POKEPARTY_GetMember(void *p, u32 idx);

extern unsigned POKE_TOOL_GetPartyValue(void *p, unsigned id, unsigned v);

extern void *POKE_TOOL_GetBoxParam(void *);

extern unsigned POKE_TOOL_GetGraphicIndex(void *);

extern int POKE_TOOL_GetIconPalette(void *box);

u32 *WIFIBATTLEMATCH_VIEW_Create(int unused, int mode, int heap);

void WIFIBATTLEMATCH_VIEW_Delete(WifiBattleMatchViewRoot *p);

void WIFIBATTLEMATCH_VIEW_LoadBgPalette(int unused, int mode, unsigned color);

int WIFIBATTLEMATCH_VIEW_GetFrameIndex(int *p, int i);

void WIFIBATTLEMATCH_VIEW_UpdateAnimation(WifiBattleMatchViewAnimState *p);

void WIFIBATTLEMATCH_VIEW_BlendColors(u32 slot, u16 *out, const u16 *phase, u32 unused, u8 a, u8 b, u16 c0, u16 c1);

void WIFIBATTLEMATCH_VIEW_DrawTaggedText(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap);

Work *WIFIBATTLEMATCH_VIEW_CreateMainWindow(const WifiBattleMatchViewMainInfo *info, u32 headerMsgId, void *myStatus, void *owner, void *table, int font, void *printQue, void *msgData, void *wordSet, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeleteMainWindow(void *p);

char *WIFIBATTLEMATCH_VIEW_CreateStatusWindow(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeleteStatusWindow(void *p);

void WIFIBATTLEMATCH_VIEW_DrawStatusWindow(char *p, int mode, void *mgr, void *print, int font, u16 unused);

char *WIFIBATTLEMATCH_VIEW_CreateDateWindow(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeleteDateWindow(void *p);

void WIFIBATTLEMATCH_VIEW_DrawDateWindow(char *p, int mode, void *mgr, void *print, int font, u32 unused);

int WIFIBATTLEMATCH_VIEW_UpdatePokeList(unsigned char *p, void *mgr);

int WIFIBATTLEMATCH_VIEW_StepMainWindow(Work *w);

int WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(Work *w);

void WIFIBATTLEMATCH_VIEW_SetupMainWindow(Work *w, unsigned headerMsgId, const WifiBattleMatchViewMainInfo *info, void *myStatus, u32 font, void *printQue, void *msgData, void *wordSet, int highlight, u16 h);

void WIFIBATTLEMATCH_VIEW_SetupDateWindow(Work *w, unsigned drawTotal, const WifiBattleMatchViewStatusInfo *info, void *myStatus, u32 font, void *printQue, void *msgData, void *wordSet, u16 heap);

void WIFIBATTLEMATCH_VIEW_SetupTimeWindow(Work *w, const WifiBattleMatchViewTimeInfo *info, void *myStatus, int font, void *printQue, void *msgData, void *wordSet, u16 heap);

int WIFIBATTLEMATCH_VIEW_UpdateWindow(unsigned char *p, void *mgr);

void WIFIBATTLEMATCH_VIEW_DeleteWindow(unsigned *p);

void WIFIBATTLEMATCH_VIEW_CreatePokeActors(Work *w, void *owner, void *rec, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeletePokeActors(char *p);

void WIFIBATTLEMATCH_VIEW_CreatePokeActor(unsigned char *p, unsigned idx, void *owner, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeletePokeActor(char *p);

void WIFIBATTLEMATCH_VIEW_CreateActorFromTable(char *p, void *owner, void *table, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeleteActorFromTable(int *p);

void WIFIBATTLEMATCH_VIEW_CreateActorFromInfo(char *p, const WifiBattleMatchViewMainInfo *desc, void *owner, void *table, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeleteActorFromInfo(char *p);

WifiBattleMatchViewRecordWork *WIFIBATTLEMATCH_VIEW_CreateRecordWindow(const WifiBattleMatchViewRecord *rec, void *clunit, void *table, void *font, void *printQue, void *msgData, void *wordSet, u32 mode, u32 owner, int style, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(char *p);

int WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(void *p, void *mgr);

int WIFIBATTLEMATCH_VIEW_StepRecordWindow(WifiBattleMatchViewRecordWork *p);

void WIFIBATTLEMATCH_VIEW_SetupRecordWindow(WifiBattleMatchViewRecordWork *p, const WifiBattleMatchViewRecord *data, unsigned font, void *print, void *msg, void *fmt, int alt, u16 heap);

int WIFIBATTLEMATCH_VIEW_UpdateRecordWindowInner(unsigned char *p, void *mgr);

void WIFIBATTLEMATCH_VIEW_DeleteRecordWin(WifiBattleMatchViewRecordWork *p);

void WIFIBATTLEMATCH_VIEW_CreateRecordActor(char *p, unsigned idx, void *owner, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeleteRecordActor(char *p);

void WIFIBATTLEMATCH_VIEW_CreateRecordActorFromRec(char *p, const WifiBattleMatchViewRecord *q, void *x, void *data, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeleteRecordActorObj(WifiBattleMatchViewRecordWork *p);

unsigned WIFIBATTLEMATCH_VIEW_GetEntryValue(void *total, unsigned wins, unsigned losses);

void **WIFIBATTLEMATCH_VIEW_CreateActorArray(void *owner, void *src, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeleteActorArray(int *p);

void WIFIBATTLEMATCH_VIEW_Noop(int p);

void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **p, int on);

WifiBattleMatchViewPartyWork *WIFIBATTLEMATCH_VIEW_CreatePartyWindow(void *src, void *owner, int unused, unsigned font, void *print, void *msg, u16 heap);

void WIFIBATTLEMATCH_VIEW_DeletePartyWindow(char *p);

int WIFIBATTLEMATCH_VIEW_StepPartyWindow(WifiBattleMatchViewPartyWork *p);

int WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(WifiBattleMatchViewPartyWork *p);

int WIFIBATTLEMATCH_VIEW_UpdatePartyWindow(char *p, void *q);

extern const char d_021E8DBC[];

extern const short FX_SinCosTable_[];

extern const WinDef d_021E8D36[];

extern const WinDef d_021E8CCE[];

extern const WinDef d_021E8D0E[];

extern const unsigned char d_021E8CBE[];

extern const WinTemplate d_021E8CEE[];

/*
 * note 2026-10-05 (wP4 S8): EXACT first compile. Twin shape from ov177 021E58A4 (same heap-id mask) and ov172 021BBA94. 0x85 kept in a local (reused as k + 0x9b), 02030734 heap parameter u32 (no halfword truncate before the call).
 */
u32 *WIFIBATTLEMATCH_VIEW_Create(int unused, int mode, int heap)
{
    u32 *w;
    u32 c;
    u32 k;
    void *h;
    void *hd;
    u32 *out;
    u8 *data;
    u32 l, m;
    w = GFL_HEAP_Alloc(heap, 0x7c, 0, d_021E8DBC, 0x7d);
    MI_CpuFill8(w, 0, 0x7c);
    k = 0x85;
    c = (heap & 0x7fff) | 0x8000;
    h = ARC_TOOL_CreateHandle(k, (u16)c);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0, 0, 0, 0, c);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0, 4, 0, 0, c);
    ARC_UTIL_UploadBgCharFromHandle(h, 2, 3, 0, 0, 0, c);
    ARC_UTIL_UploadBgCharFromHandle(h, 2, 7, 0, 0, 0, c);
    WIFIBATTLEMATCH_VIEW_LoadBgPalette((int)w, mode, heap);
    w[0] = CLACT_RegisterPalette(h, 1, 0, 0, c);
    w[2] = CLACT_RegisterCharacter(h, 3, 0, 0, c);
    w[4] = CLACT_RegisterCellAnim(h, 4, 0xb, c);
    w[1] = CLACT_RegisterPalette(h, 1, 1, 0, c);
    w[3] = CLACT_RegisterCharacter(h, 3, 0, 1, c);
    w[5] = CLACT_RegisterCellAnim(h, 4, 0xb, c);
    hd = ARC_UTIL_LoadPaletteBlockFromHandle(h, 0, (u32)&out, heap);
    data = (u8 *)out[3];
    MI_CpuCopy8(data, (u8 *)w + 0x38, 0x20);
    k += 0x9b;
    MI_CpuCopy8(data + k, (u8 *)w + 0x58, 0x20);
    GFL_HEAP_Free(hd);
    ARC_TOOL_DeleteHandle(h);
    l = 0x17;
    m = 5;
    ARC_UTIL_UploadPaletteFromArchiveWhole(l, m, 0, 0x1e0, 0x20, c);
    ARC_UTIL_UploadPaletteFromArchiveWhole(l, m, 4, 0x1e0, 0x20, c);
    BG_SYS_Init(0, 0, 1, 0);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xd, 0, c);
    BMP_MENUWORK_LoadCharAndPltt(0, 0xa, 0xe, 0, c);
    BG_SYS_ChangeScrollImmediate(2, 0, -256);
    BG_SYS_ChangeScrollImmediate(1, 0, -256);
    BG_SYS_ChangeScrollImmediate(6, 0, -256);
    BG_SYS_ChangeScrollImmediate(m, 0, -256);
    return w;
}

void WIFIBATTLEMATCH_VIEW_Delete(WifiBattleMatchViewRoot *p)
{
    CLACT_ReleasePalette(p->a);
    CLACT_ReleaseCharacter(p->c);
    CLACT_ReleaseCellAnim(p->e);
    CLACT_ReleasePalette(p->b);
    CLACT_ReleaseCharacter(p->d);
    CLACT_ReleaseCellAnim(p->f);
    BG_SYS_FreeTiles(0, 1, 0);
    GFL_HEAP_Free(p);
}

void WIFIBATTLEMATCH_VIEW_LoadBgPalette(int unused, int mode, unsigned color)
{
    int h;
    unsigned c = (color & 0x7fff) | 0x8000;
    h = (int)ARC_TOOL_CreateHandle((int)0x85, (unsigned short)c);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)h, 5, 3, 0, 0, 0, c);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)h, 6, 7, 0, 0, 0, c);
    switch (mode) {
    case 2:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)h, 8, 6, 0, 0, 0, c);
        break;
    case 3:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)h, 10, 2, 0, 0, 0, c);
        break;
    case 0:
    case 1:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)h, 10, 6, 0, 0, 0, c);
        break;
    }
    BG_SYS_ChangeScrollImmediate(2, 0, -256);
    BG_SYS_ChangeScrollImmediate(1, 0, -256);
    BG_SYS_ChangeScrollImmediate(6, 0, -256);
    BG_SYS_ChangeScrollImmediate(5, 0, -256);
    ARC_TOOL_DeleteHandle((void *)h);
}

int WIFIBATTLEMATCH_VIEW_GetFrameIndex(int *p, int i)
{
    return p[i];
}

/*
 * lever: observed three color arrays; cached phase on wrap, compound increment reload on no-wrap.
 */
void WIFIBATTLEMATCH_VIEW_UpdateAnimation(WifiBattleMatchViewAnimState *p)
{
    int i;
    unsigned short phase = p->phase;
    if (phase + 0x200 >= 0x10000)
        p->phase = phase - 0xfe00;
    else
        p->phase += 0x200;
    for (i = 0; i < 16; i++) {
        WIFIBATTLEMATCH_VIEW_BlendColors(15, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        WIFIBATTLEMATCH_VIEW_BlendColors(31, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        WIFIBATTLEMATCH_VIEW_BlendColors(14, &p->out[i], &p->phase, 0, 2, i, p->original[i], p->target[i]);
    }
}

/*
 * note: 2026-10-02 lane07: DIFF, 172 bytes. Channel unpack/blend scheduling differs (orig reads c0 via add r1,sp,#0x18 before table load, builds 0x1f<<10 mask by reusing the 0x1f register, blend order B,R,G). Tried u8 locals, decl orders, shifted-mask forms.
 * note 2026-10-05: orig packs `(g << 5) | r | (b << 10)` (orrs g5,r then b10); tried that order:
 * the compiler then rebuilds 0x1f from a shifted register and the function shrinks to 156 B (orig 172).
 * The original keeps c0 in r6 and c1 in r1 and builds each mask with its own movs/lsls; no source form
 * found that reproduces this. Still DIFF.
 * 2026-10-05 (wave D9 lane10): DIFF, now 172 bytes (same size as the original), 94 bytes differ
 *   (was 157 with a 164-byte body). New form: c1 channels in u8 locals (b1, r1, g1) as separate
 *   statements, blends written back into the c0 locals in order b, r, g, pack "r | (g << 5) | (b << 10)".
 *   This reproduces every u8 truncation, every mask constant (0x3e<<4, 0x1f, 0x1f<<10, no 0x1f held in
 *   a register), the blend order and out in r7. Residue: register colouring only. Ours keeps c0 in r1
 *   and hoists c1's 0x1f<<10 mask into r6 at the top; the original keeps c0 in r6 (loaded before the
 *   table read) and builds that mask in r6 after c0 dies. Also g0/r0 swap r3/r4 and b0 is r1 (orig r2).
 *   Tried: declaration order of the locals (no change, all propagated), c0 extraction before t (worse,
 *   100), u8 casts inline in the blends (CSE of 0x1f into r7 when all six channels are u8 inline),
 *   a static inline u8 Blend helper (120), U-suffixed masks (no change).
 * 2026-10-05 (wave D9r lane06): DIFF, 172 bytes, 77 bytes differ (was 94). New form: copy c0 into an
 *   `int col` local as the first statement, before t. This puts `add r1,sp,#0x18` at +6 as in the image.
 *   Residue: colouring only. The image loads c0 into r6 at +0x12 (before the table ldrsh) and c1 into r1;
 *   ours loads col into r1 after t, c1 into r2, and hoists c1's 0x1f<<10 mask into r6. g0/r0 also swap
 *   r3/r4. Tried without gain: u16 col (94), u32 col (77), short col (176 B), col reused for c1 (77),
 *   a second int col1 for c1 (137), statement order of the six channel locals (all 94, mwcc rebuilds the
 *   trees per use), g0 or g0+r0 extracted before t with and without col (100/106), static inline Blend
 *   (u16 c0, u16 c1, int t / short t / u16 phase) (94/96), short t (96), pack (g<<5)|r|(b<<10) (109).
 * 2026-10-05 (wave D9r lane33): DIFF, code unchanged (77 bytes differ). Listing reading: the image
 *   colours c0 last (r6, the only free register), so c0 is a short, low-degree value in the image and the
 *   post-RA scheduler then lifts its ldrh to +0x12 and builds c1's 0x7c00 mask in r6 only after c0 dies.
 *   Ours colours c0 (or col) first into r1, leaving r6 free, so the scheduler hoists that mask to the top.
 *   Tried: t through a static inline CalcT(phase) helper (77, same code); blends into three new u8 locals
 *   bb/rr/gg instead of writing back (90); int c0 channel locals with (u8) casts at each assignment (81);
 *   mask-first operand order `0x3e0 & c0` with and without col (94/77, no change).
 *
 * 2026-10-05 (wave D9r lane37): EXACT. Closed with the form of the matched twin ov068 BLINK_PALANM_BlendStep
 *   (arm9 twin BLINK_PALANM_Update, blink_palanm.c): f as an s16 local, all six channels as u8 locals extracted
 *   mask-then-shift, the blends as s32 locals with a u8 cast, and the pack (b << 10) | (r | (g << 5)).
 */
void WIFIBATTLEMATCH_VIEW_BlendColors(u32 slot, u16 *out, const u16 *phase, u32 unused, u8 a, u8 b, u16 c0, u16 c1)
{
    s16 f;
    u8 r0, g0, b0, r1, g1, b1;
    s32 r, g, bl;

    f = (FX_SinCosTable_[((*phase >> 4) << 1) + 1] + 0x1000) / 2;
    r0 = c0 & 0x1f;
    g0 = (c0 & 0x3e0) >> 5;
    b0 = (c0 & 0x7c00) >> 10;
    r1 = c1 & 0x1f;
    g1 = (c1 & 0x3e0) >> 5;
    b1 = (c1 & 0x7c00) >> 10;
    bl = (u8)(b0 + (((b1 - b0) * f) >> 12));
    r = (u8)(r0 + (((r1 - r0) * f) >> 12));
    g = (u8)(g0 + (((g1 - g0) * f) >> 12));
    *out = (u16)((bl << 10) | (r | (g << 5)));
    NNS_GfdRegisterNewVramTransferTask((void *)slot, a * 32 + b * 2, (u32)out, 2);
}

/*
 * note 2026-10-05 (final push G6L3): EXACT*. The three running x values are separate locals (x, x1 = x - w, x2 = x1 - w, third draw x2 - w), not one x updated in place; the separate values give each its own live range and the original colours (str r4, p r5, heap-base temp and buf r6, x r7). Earlier notes (all pragmas, declaration orders, inline helpers, u8/u16 widths) did not move the colours.
 */
void WIFIBATTLEMATCH_VIEW_DrawTaggedText(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap)
{
    struct MsgBank *msg;
    struct WordSet *ws;
    struct U16Vec *buf;
    void *e;
    int x, x1, x2;
    u16 w;

    msg = MSGDATA_CreateFromArchive(0, 2, 0xa3, heap);
    ws = WORDSET_CreateDefault(heap);
    buf = STRBUF_Create(0x20, heap);
    x = (u16)(BMP_WIN_GetWidth((void *)p[0]) << 3);

    e = MSGDATA_AllocString(msg, 2);
    WORDSET_SetSlotNumber(ws, 0, c1, 8, 0, 1);
    WORDSET_CopyTaggedText(ws, buf, e);
    w = PRINTSYS_MeasureWidestLine((struct StrObj *)buf, str, 0);
    x1 = x - w;
    PRINTSYS_PrintQue(win, (u32)BMP_WIN_GetBmp((struct Descriptor *)p[0]), (s16)x1, 0, buf, str);
    ((u8 *)p)[4] = 1;
    STRBUF_Delete((struct U16Vec *)e);

    e = MSGDATA_AllocString(msg, 0);
    w = PRINTSYS_MeasureWidestLine(e, str, 0);
    x2 = x1 - w;
    PRINTSYS_PrintQue(win, (u32)BMP_WIN_GetBmp((struct Descriptor *)p[0]), (s16)x2, 0, e, str);
    ((u8 *)p)[4] = 1;
    STRBUF_Delete((struct U16Vec *)e);

    e = MSGDATA_AllocString(msg, 1);
    WORDSET_SetSlotNumber(ws, 0, c2, 8, 0, 1);
    WORDSET_CopyTaggedText(ws, buf, e);
    w = PRINTSYS_MeasureWidestLine((struct StrObj *)buf, str, 0);
    PRINTSYS_PrintQue(win, (u32)BMP_WIN_GetBmp((struct Descriptor *)p[0]), (s16)(x2 - w), 0, buf, str);
    ((u8 *)p)[4] = 1;
    STRBUF_Delete((struct U16Vec *)e);
    STRBUF_Delete(buf);
    WORDSET_Delete(ws);
    MSGDATA_Delete((struct Rec *)msg);
}

/*
 * note 2026-10-05 (recoup R4): EXACT. Lever: heap parameter u16 with u16 heap parameters on every callee (02030734 first, 021E6718 last, 021E72FC fourth, 021E7464 fifth), no heapId local. u8 also gives EXACT; u16 chosen to match the sibling constructors 5D68/6118/7520. The earlier u16-only try changed only this function and gave 264 B.
 */
Work *WIFIBATTLEMATCH_VIEW_CreateMainWindow(const WifiBattleMatchViewMainInfo *info, u32 headerMsgId, void *myStatus, void *owner,
                    void *table, int font, void *printQue, void *msgData, void *wordSet, u16 heap)
{
    Work *w;
    u32 kind;
    u32 size;
    int alt;
    Pt pos;
    size = 0x229 + 0x1b;
    w = GFL_HEAP_Alloc(heap, size, 0, d_021E8DBC, 0x229);
    MI_CpuFill8(w, 0, size);
    w->bg = 5;
    w->palette = 15;
    w->palSlot = 3;
    w->spritePalSlot = 7;
    w->layer = 1;
    alt = 1;
    G2x_SetBlendAlpha_((void *)0x04001050, 4, 8, 15, 3);
    kind = WIFIBATTLEMATCH_VIEW_GetEntryValue(info->total, info->a, info->b);
    if (kind != 5) alt = 0;
    WIFIBATTLEMATCH_VIEW_SetupMainWindow(w, headerMsgId, info, myStatus, font, printQue, msgData, wordSet, alt, heap);
    WIFIBATTLEMATCH_VIEW_CreatePokeActor((u8 *)w, info->name, owner, heap);
    pos.x = 0x120;
    pos.y = 0x44;
    CLACT_AddActorSurfacePos(w->objs[7], &pos, 1);
    WIFIBATTLEMATCH_VIEW_CreateActorFromInfo((char *)w, info, owner, table, heap);
    BG_SYS_FillTileMap(6, 0, 0, 0x20, 6, 1);
    BG_SYS_FillTileMap(6, 0, 6, 0x20, 18, kind + 3);
    BG_SYS_PushTile(6);
    G2x_SetBlendAlpha_((void *)0x04001050, 4, 8, 15, 3);
    return w;
}

void WIFIBATTLEMATCH_VIEW_DeleteMainWindow(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    WIFIBATTLEMATCH_VIEW_DeleteActorFromInfo(p);
    WIFIBATTLEMATCH_VIEW_DeletePokeActor(p);
    WIFIBATTLEMATCH_VIEW_DeleteWindow(p);
    GFL_HEAP_Free(p);
}

char *WIFIBATTLEMATCH_VIEW_CreateStatusWindow(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap)
{
  char *w;
  Layer layer;
  Pt pos;
  WifiBattleMatchViewStatusInfo *tmp;
  w = GFL_HEAP_Alloc(heap, 0x244, 0, d_021E8DBC, 0x27f);
  MI_CpuFill8(w, 0, 0x244);
  *((void **) (w + 0x238)) = record;
  *((u16 *) (w + 0x23c)) = heap;
  *((void **) (w + 0x240)) = owner;
  if (mode)
  {
    layer = 2;
    *((u8 *) (w + 0x230)) = 1;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 5;
    *((u8 *) (w + 0x233)) = 9;
    *((u32 *) (w + 0x234)) = 0;
    G2x_SetBlendAlpha_((void *) 0x04000050, 4, 8, 15, 3);
  }
  else
  {
    *((u8 *) (w + 0x230)) = 5;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 3;
    *((u8 *) (w + 0x233)) = 7;
    *((u32 *) (w + 0x234)) = 1;
    layer = 6;
    G2x_SetBlendAlpha_((void *) 0x04001050, 4, 8, 15, 3);
  }
  tmp = (WifiBattleMatchViewStatusInfo *) info;
  switch (*((u16 *) (info + 0xaa)))
  {
    case 0:
      BG_SYS_FillTileMap(layer, 0, 0, 32, 5, 1);
      BG_SYS_FillTileMap(layer, 0, 5, 32, 18, 3);
      BG_SYS_PushTile((u8) layer);
      break;

    case 1:
      BG_SYS_FillTileMap(layer, 0, 0, 32, 5, 1);
      BG_SYS_FillTileMap(layer, 0, 5, 32, 18, 7);
      BG_SYS_PushTile((u8) layer);
      break;

  }

  WIFIBATTLEMATCH_VIEW_SetupDateWindow((Work *)w, a, tmp, b, c, d, e, f, heap);
  WIFIBATTLEMATCH_VIEW_CreatePokeActors((Work *)w, owner, record, heap);
  info += 0x9c;
  WIFIBATTLEMATCH_VIEW_CreatePokeActor((u8 *) w, *((u32 *) info), owner, heap);
  pos.x = 0x120;
  pos.y = 0x6e;
  CLACT_AddActorSurfacePos(*((void **) (w + 0x188)), &pos, *((u32 *) (w + 0x234)));
  WIFIBATTLEMATCH_VIEW_CreateActorFromTable(w, owner, table, heap);
  return w;
}

void WIFIBATTLEMATCH_VIEW_DeleteStatusWindow(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    WIFIBATTLEMATCH_VIEW_DeleteActorFromTable(p);
    WIFIBATTLEMATCH_VIEW_DeletePokeActor(p);
    WIFIBATTLEMATCH_VIEW_DeletePokeActors(p);
    WIFIBATTLEMATCH_VIEW_DeleteWindow(p);
    GFL_HEAP_Free(p);
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the 3 dead first assignments
 * (`layer1=0x240;` before `layer1=0x234;`; `layer2=0x240;` before
 * `layer2=0x234;` and 1 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void WIFIBATTLEMATCH_VIEW_DrawStatusWindow(char *p, int mode, void *mgr, void *print, int font, u16 unused)
{
    int i;
    void *s;
    int x;
    int base,layer1,secondary,layer2;
    Pt pos;
    BMP_Clear(BMP_WIN_GetBmp(((Work *)p)->wins[7]),0);
    i=0;
    WIFIBATTLEMATCH_VIEW_DeletePokeActors(p);
    base=0x240;
    WIFIBATTLEMATCH_VIEW_CreatePokeActors((Work *)p,*(void **)(p+base),*(void **)(p+base-8),*(u16 *)(p+base-4));
    x=32-BG_SYS_GetScrollX(*(u8 *)(p+base-16));
    layer1=0x234;
    layer2=0x234;
    secondary=0x1a8;
    base=0x16c;
    for(;i<6;i++) {
        void *o;
        char *q;
        pos.y=168;pos.x=x+i*32;
        q=p+i*4;
        o=*(void **)(q+base);
        if(o)CLACT_AddActorSurfacePos(o, &pos, *(unsigned *)(p+layer1));
        o=*(void **)(q+secondary);
        if(o) {
            pos.x+=12;pos.y+=8;
            CLACT_AddActorSurfacePos(o, &pos, *(unsigned *)(p+layer2));
        }
    }
    switch(mode) {
    case 0:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((Work *)q)->objs[15];
            if(o)CLACT_SetActorDrawEnable(o,1);
            o=((Work *)q)->objs[0];
            if(o)CLACT_SetActorDrawEnable(o,1);
        }
        CLACT_SetActorDrawEnable(((Work *)p)->objs[8],1);
        s=MSGDATA_AllocString(mgr,17);
        PRINTSYS_PrintQueColor(print,BMP_WIN_GetBmp(((Work *)p)->slots[7].win),0,0,s,font,0x3c40);
        ((Work *)p)->slots[7].shown=1;
        break;
    case 1:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((Work *)q)->objs[15];
            if(o)CLACT_SetActorDrawEnable(o,1);
            o=((Work *)q)->objs[0];
            if(o)CLACT_SetActorDrawEnable(o,1);
        }
        CLACT_SetActorDrawEnable(((Work *)p)->objs[8],0);
        s=MSGDATA_AllocString(mgr,18);
        PRINTSYS_PrintQueColor(print,BMP_WIN_GetBmp(((Work *)p)->slots[7].win),0,0,s,font,0x3c40);
        ((Work *)p)->slots[7].shown=1;
        break;
    case 2:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((Work *)q)->objs[15];
            if(o)CLACT_SetActorDrawEnable(o,0);
            o=((Work *)q)->objs[0];
            if(o)CLACT_SetActorDrawEnable(o,0);
        }
        CLACT_SetActorDrawEnable(((Work *)p)->objs[8],0);
        s=MSGDATA_AllocString(mgr,19);
        PRINTSYS_PrintQueColor(print,BMP_WIN_GetBmp(((Work *)p)->slots[7].win),0,0,s,font,0x3c40);
        ((Work *)p)->slots[7].shown=1;
        break;
    }
    STRBUF_Delete(s);
}

char *WIFIBATTLEMATCH_VIEW_CreateDateWindow(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap)
{
  char *w;
  Layer layer;
  Pt pos;
  WifiBattleMatchViewTimeInfo *tmp;
  w = GFL_HEAP_Alloc(heap, 0x244, 0, d_021E8DBC, 0x354);
  MI_CpuFill8(w, 0, 0x244);
  *((void **) (w + 0x238)) = record;
  *((u16 *) (w + 0x23c)) = heap;
  *((void **) (w + 0x240)) = owner;
  if (mode)
  {
    layer = 2;
    *((u8 *) (w + 0x230)) = 1;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 5;
    *((u8 *) (w + 0x233)) = 9;
    *((u32 *) (w + 0x234)) = 0;
    G2x_SetBlendAlpha_((void *) 0x04000050, 4, 8, 15, 3);
  }
  else
  {
    *((u8 *) (w + 0x230)) = 5;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 3;
    *((u8 *) (w + 0x233)) = 7;
    *((u32 *) (w + 0x234)) = 1;
    layer = 6;
    G2x_SetBlendAlpha_((void *) 0x04001050, 4, 8, 15, 3);
  }
  tmp = (WifiBattleMatchViewTimeInfo *) info;
  switch (*((u16 *) (info + 0xa8)))
  {
    case 0:
      BG_SYS_FillTileMap(layer, 0, 0, 32, 5, 1);
      BG_SYS_FillTileMap(layer, 0, 5, 32, 18, 3);
      BG_SYS_PushTile((u8) layer);
      break;

    case 1:
      BG_SYS_FillTileMap(layer, 0, 0, 32, 5, 1);
      BG_SYS_FillTileMap(layer, 0, 5, 32, 18, 7);
      BG_SYS_PushTile((u8) layer);
      break;

  }

  WIFIBATTLEMATCH_VIEW_SetupTimeWindow((Work *)w, tmp, a, b, c, d, e, heap);
  WIFIBATTLEMATCH_VIEW_CreatePokeActors((Work *)w, owner, record, heap);
  info += 0x9c;
  WIFIBATTLEMATCH_VIEW_CreatePokeActor((u8 *) w, *((u32 *) info), owner, heap);
  pos.x = 0x120;
  pos.y = 0x6e;
  CLACT_AddActorSurfacePos(*((void **) (w + 0x188)), &pos, *((u32 *) (w + 0x234)));
  WIFIBATTLEMATCH_VIEW_CreateActorFromTable(w, owner, table, heap);
  return w;
}

void WIFIBATTLEMATCH_VIEW_DeleteDateWindow(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    WIFIBATTLEMATCH_VIEW_DeleteActorFromTable(p);
    WIFIBATTLEMATCH_VIEW_DeletePokeActor(p);
    WIFIBATTLEMATCH_VIEW_DeletePokeActors(p);
    WIFIBATTLEMATCH_VIEW_DeleteWindow(p);
    GFL_HEAP_Free(p);
}

void WIFIBATTLEMATCH_VIEW_DrawDateWindow(char *p, int mode, void *mgr, void *print, int font, u32 unused)
{
    int i;
    void *s;
    int x;
    int base,layer1,secondary,layer2;
    Pt pos;
    BMP_Clear(BMP_WIN_GetBmp(((Work *)p)->wins[9]),0);
    i=0;
    WIFIBATTLEMATCH_VIEW_DeletePokeActors(p);
    base=0x240;
    WIFIBATTLEMATCH_VIEW_CreatePokeActors((Work *)p,*(void **)(p+base),*(void **)(p+base-8),*(u16 *)(p+base-4));
    x=32-BG_SYS_GetScrollX(*(u8 *)(p+base-16));
    layer1=0x234;
    layer2=0x234;
    secondary=0x1a8;
    base=0x16c;
    for(;i<6;i++) {
        void *o;
        char *q;
        pos.y=168;pos.x=x+i*32;
        q=p+i*4;
        o=*(void **)(q+base);
        if(o)CLACT_AddActorSurfacePos(o, &pos, *(unsigned *)(p+layer1));
        o=*(void **)(q+secondary);
        if(o) {
            pos.x+=12;pos.y+=8;
            CLACT_AddActorSurfacePos(o, &pos, *(unsigned *)(p+layer2));
        }
    }
    switch(mode) {
    case 0:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((Work *)q)->objs[15];
            if(o)CLACT_SetActorDrawEnable(o,1);
            o=((Work *)q)->objs[0];
            if(o)CLACT_SetActorDrawEnable(o,1);
        }
        CLACT_SetActorDrawEnable(((Work *)p)->objs[8],1);
        s=MSGDATA_AllocString(mgr,17);
        PRINTSYS_PrintQueColor(print,BMP_WIN_GetBmp(((Work *)p)->slots[9].win),0,0,s,font,0x3c40);
        ((Work *)p)->slots[9].shown=1;
        break;
    case 1:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((Work *)q)->objs[15];
            if(o)CLACT_SetActorDrawEnable(o,1);
            o=((Work *)q)->objs[0];
            if(o)CLACT_SetActorDrawEnable(o,1);
        }
        CLACT_SetActorDrawEnable(((Work *)p)->objs[8],0);
        s=MSGDATA_AllocString(mgr,18);
        PRINTSYS_PrintQueColor(print,BMP_WIN_GetBmp(((Work *)p)->slots[9].win),0,0,s,font,0x3c40);
        ((Work *)p)->slots[9].shown=1;
        break;
    case 2:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((Work *)q)->objs[15];
            if(o)CLACT_SetActorDrawEnable(o,0);
            o=((Work *)q)->objs[0];
            if(o)CLACT_SetActorDrawEnable(o,0);
        }
        CLACT_SetActorDrawEnable(((Work *)p)->objs[8],0);
        s=MSGDATA_AllocString(mgr,19);
        PRINTSYS_PrintQueColor(print,BMP_WIN_GetBmp(((Work *)p)->slots[9].win),0,0,s,font,0x3c40);
        ((Work *)p)->slots[9].shown=1;
        break;
    }
    STRBUF_Delete(s);
}

/*
 * Unlabelled ov177 thunk hidden in a word run: forwards to WIFIBATTLEMATCH_VIEW_UpdateWindow.
 * Matched to supply the `matched` witness for the pending ov176 caller
 * DIGITALCARDCHECK_DeleteAlt.
 */
int WIFIBATTLEMATCH_VIEW_UpdatePokeList(unsigned char *p, void *mgr)
{
    return WIFIBATTLEMATCH_VIEW_UpdateWindow(p, mgr);
}

int WIFIBATTLEMATCH_VIEW_StepMainWindow(Work *w)
{
    int ret;
    int level;
    int i;
    Pt cur, pos;
    if (BG_SYS_GetScrollX(w->bg) == 0)
        return 1;
    ret = 0;
    if (w->objCount == 0) {
        for (i = 0; i < 22; i++) {
            if (w->objs[i] != 0) {
                CLACT_GetActorSurfacePos(w->objs[i], (struct PtS *)&cur, (unsigned short)w->layer);
                w->baseX[i] = cur.x;
            }
        }
        GFL_USE_PlaySeDefaultVolume(0x63b);
    }
    level = (w->objCount << 8) / 20 - 0x100;
    for (i = 0; i < 22; i++) {
        if (w->objs[i] != 0) {
            CLACT_GetActorSurfacePos(w->objs[i], (struct PtS *)&pos, (unsigned short)w->layer);
            pos.x = w->baseX[i] - (w->objCount << 8) / 20;
            CLACT_AddActorSurfacePos(w->objs[i], &pos, w->layer);
        }
    }
    if (w->objCount++ >= 20) {
        level = 0;
        w->objCount = 0;
        ret = 1;
    }
    BG_SYS_ChangeScroll((unsigned char)(w->bg + 1), (int)0, (int)level);
    BG_SYS_ChangeScroll((unsigned char)w->bg, (int)0, (int)level);
    return ret;
}

int WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(Work *w)
{
    int ret = 0;
    int level;
    int i;
    Pt cur, pos;
    if (w->objCount == 0) {
        for (i = 0; i < 22; i++) {
            if (w->objs[i] != 0) {
                CLACT_GetActorSurfacePos(w->objs[i], (struct PtS *)&cur, (unsigned short)w->layer);
                w->baseX[i] = cur.x;
            }
        }
        GFL_USE_PlaySeDefaultVolume(0x63b);
    }
    level = (w->objCount << 8) / 20;
    for (i = 0; i < 22; i++) {
        if (w->objs[i] != 0) {
            CLACT_GetActorSurfacePos(w->objs[i], (struct PtS *)&pos, (unsigned short)w->layer);
            pos.x = w->baseX[i] - (w->objCount << 8) / 20;
            CLACT_AddActorSurfacePos(w->objs[i], &pos, w->layer);
        }
    }
    if (w->objCount++ >= 20) {
        level = 0x100;
        w->objCount = 0;
        ret = 1;
    }
    BG_SYS_ChangeScroll((unsigned char)(w->bg + 1), (int)0, (int)level);
    BG_SYS_ChangeScroll((unsigned char)w->bg, (int)0, (int)level);
    return ret;
}

void WIFIBATTLEMATCH_VIEW_SetupMainWindow(Work *w, unsigned headerMsgId, const WifiBattleMatchViewMainInfo *info, void *myStatus, u32 font, void *printQue, void *msgData, void *wordSet, int highlight, u16 h)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 11;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = (void *)BMP_WIN_Create(5, d_021E8D36[i].a, d_021E8D36[i].b, d_021E8D36[i].c, d_021E8D36[i].d, 0xf, 1);
        BMP_Clear(BMP_WIN_GetBmp(w->wins[i]), 0);
        win = w->wins[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
        if (w->wins[i] != 0) {
            w->slots[i].win = w->wins[i];
            w->slots[i].shown = 0;
        }
    }
    s1 = STRBUF_Create(0x80, h);
    s2 = STRBUF_Create(0x80, h);
    for (j = 0; j < 11; j++) {
        color = (highlight == 1) ? 0x3c40 : 0x440;
        draw = 1;
        switch (j) {
        case 0:
            MSGDATA_ReadString(msgData, headerMsgId, s2);
            color = 0x3c40;
            break;
        case 1:
            MSGDATA_ReadString(msgData, info->kind + 2, s2);
            color = 0x3c40;
            break;
        case 2:
            MSGDATA_ReadString(msgData, 7, s1);
            WORDSET_SetSlotMyStatus(wordSet, 0, myStatus);
            WORDSET_CopyTaggedText(wordSet, s2, s1);
            color = 0x3c40;
            break;
        case 3:
            if (headerMsgId)
                MSGDATA_ReadString(msgData, 8, s2);
            else
                draw = 0;
            break;
        case 4:
            if (headerMsgId) {
                MSGDATA_ReadString(msgData, 9, s1);
                WORDSET_SetSlotNumber(wordSet, 0, info->count, 4, 1, 1);
                WORDSET_CopyTaggedText(wordSet, s2, s1);
            } else {
                draw = 0;
            }
            break;
        case 5:
            MSGDATA_ReadString(msgData, 10, s2);
            break;
        case 6:
            MSGDATA_ReadString(msgData, 11, s1);
            WORDSET_SetSlotNumber(wordSet, 0, (u32)info->total, 6, 1, 1);
            WORDSET_CopyTaggedText(wordSet, s2, s1);
            break;
        case 7:
            MSGDATA_ReadString(msgData, 12, s2);
            break;
        case 8:
            MSGDATA_ReadString(msgData, 13, s1);
            WORDSET_SetSlotNumber(wordSet, 0, info->a, 5, 1, 1);
            WORDSET_CopyTaggedText(wordSet, s2, s1);
            break;
        case 9:
            MSGDATA_ReadString(msgData, 14, s2);
            break;
        case 10:
            MSGDATA_ReadString(msgData, 15, s1);
            WORDSET_SetSlotNumber(wordSet, 0, info->b, 5, 1, 1);
            WORDSET_CopyTaggedText(wordSet, s2, s1);
            break;
        }
        if (draw) {
            PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(w->slots[j].win), 0, 0, s2, font, color);
            w->slots[j].shown = 1;
        }
    }
    STRBUF_Delete(s1);
    STRBUF_Delete(s2);
}

void WIFIBATTLEMATCH_VIEW_SetupDateWindow(Work *w, unsigned drawTotal, const WifiBattleMatchViewStatusInfo *info, void *myStatus, u32 font, void *printQue, void *msgData, void *wordSet, u16 heap)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 8;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = (void *)BMP_WIN_Create(w->bg, d_021E8CCE[i].a, d_021E8CCE[i].b, d_021E8CCE[i].c, d_021E8CCE[i].d, w->palette, 1);
        BMP_Clear(BMP_WIN_GetBmp(w->wins[i]), 0);
        win = w->wins[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
        if (w->wins[i] != 0) {
            w->slots[i].win = w->wins[i];
            w->slots[i].shown = 0;
        }
    }
    s1 = STRBUF_Create(0x80, heap);
    s2 = STRBUF_Create(0x80, heap);
    for (j = 0; j < 8; j++) {
        unsigned d1, d2;
        draw = 1;
        color = 0x440;
        switch (j) {
        case 0:
            STRBUF_SetString(s2, (const u16 *)info);
            color = 0x3c40;
            break;
        case 1:
            d1 = info->date1;
            d2 = info->date2;
            MSGDATA_ReadString(msgData, 0x10, s1);
            WORDSET_SetSlotNumber(wordSet, 0, (u16)((u8)(d1 >> 24) + 2000), 4, 0, 1);
            WORDSET_SetSlotMonth(wordSet, 1, (u8)(d1 >> 16));
            WORDSET_SetSlotNumber(wordSet, 2, (u8)(d1 >> 8), 2, 0, 1);
            WORDSET_SetSlotNumber(wordSet, 3, (u16)((u8)(d2 >> 24) + 2000), 4, 0, 1);
            WORDSET_SetSlotMonth(wordSet, 4, (u8)(d2 >> 16));
            WORDSET_SetSlotNumber(wordSet, 5, (u8)(d2 >> 8), 2, 0, 1);
            WORDSET_CopyTaggedText(wordSet, s2, s1);
            color = 0x3c40;
            break;
        case 2:
            MYSTATUS_NameToStrbuf(myStatus, s2);
            color = 0x3c40;
            break;
        case 3:
            MSGDATA_ReadString(msgData, 8, s2);
            break;
        case 4:
            MSGDATA_ReadString(msgData, 9, s1);
            WORDSET_SetSlotNumber(wordSet, 0, info->statA0, 4, 1, 1);
            WORDSET_CopyTaggedText(wordSet, s2, s1);
            break;
        case 5:
            MSGDATA_ReadString(msgData, 10, s2);
            break;
        case 6:
            if (drawTotal) {
                WIFIBATTLEMATCH_VIEW_DrawTaggedText((u32 *)(&w->slots[j]), printQue, font, info->statTotal.total, info->statA8, heap);
                draw = 0;
            } else {
                MSGDATA_ReadString(msgData, 11, s1);
                WORDSET_SetSlotNumber(wordSet, 0, info->statTotal.total, 6, 1, 1);
                WORDSET_CopyTaggedText(wordSet, s2, s1);
            }
            break;
        case 7:
            MSGDATA_ReadString(msgData, 0x11, s2);
            color = 0x3c40;
            break;
        }
        if (draw) {
            PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(w->slots[j].win), 0, 0, s2, font, color);
            w->slots[j].shown = 1;
        }
    }
    STRBUF_Delete(s1);
    STRBUF_Delete(s2);
}

void WIFIBATTLEMATCH_VIEW_SetupTimeWindow(Work *w, const WifiBattleMatchViewTimeInfo *info, void *myStatus, int font, void *printQue, void *msgData, void *wordSet, u16 heap)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 10;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = (void *)BMP_WIN_Create(w->bg, d_021E8D0E[i].a, d_021E8D0E[i].b, d_021E8D0E[i].c, d_021E8D0E[i].d, w->palette, 1);
        BMP_Clear(BMP_WIN_GetBmp(w->wins[i]), 0);
        win = w->wins[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
        if (w->wins[i] != 0) {
            w->slots[i].win = w->wins[i];
            w->slots[i].shown = 0;
        }
    }
    s1 = STRBUF_Create(0x80, heap);
    s2 = STRBUF_Create(0x80, heap);
    for (j = 0; j < 10; j++) {
        unsigned d1, d2;
        draw = 1;
        color = 0x440;
        switch (j) {
        case 0:
            STRBUF_SetString(s2, (const u16 *)info);
            color = 0x3c40;
            break;
        case 1:
            d1 = info->date1;
            d2 = info->date2;
            MSGDATA_ReadString(msgData, 0x10, s1);
            WORDSET_SetSlotNumber(wordSet, 0, (u16)((u8)(d1 >> 24) + 2000), 4, 0, 1);
            WORDSET_SetSlotMonth(wordSet, 1, (u8)(d1 >> 16));
            WORDSET_SetSlotNumber(wordSet, 2, (u8)(d1 >> 8), 2, 0, 1);
            WORDSET_SetSlotNumber(wordSet, 3, (u16)((u8)(d2 >> 24) + 2000), 4, 0, 1);
            WORDSET_SetSlotMonth(wordSet, 4, (u8)(d2 >> 16));
            WORDSET_SetSlotNumber(wordSet, 5, (u8)(d2 >> 8), 2, 0, 1);
            WORDSET_CopyTaggedText(wordSet, s2, s1);
            color = 0x3c40;
            break;
        case 2:
            MYSTATUS_NameToStrbuf(myStatus, s2);
            color = 0x3c40;
            break;
        case 3:
            MSGDATA_ReadString(msgData, 12, s2);
            break;
        case 4:
            MSGDATA_ReadString(msgData, 13, s1);
            WORDSET_SetSlotNumber(wordSet, 0, info->statA0, 5, 1, 1);
            WORDSET_CopyTaggedText(wordSet, s2, s1);
            break;
        case 5:
            MSGDATA_ReadString(msgData, 14, s2);
            break;
        case 6:
            MSGDATA_ReadString(msgData, 15, s1);
            WORDSET_SetSlotNumber(wordSet, 0, info->statA2, 5, 1, 1);
            WORDSET_CopyTaggedText(wordSet, s2, s1);
            break;
        case 7:
            MSGDATA_ReadString(msgData, 10, s2);
            break;
        case 8:
            WIFIBATTLEMATCH_VIEW_DrawTaggedText((u32 *)(&w->slots[j]), printQue, font, info->statTotal.h.a4, info->statTotal.h.a6, heap);
            draw = 0;
            break;
        case 9:
            MSGDATA_ReadString(msgData, 0x11, s2);
            color = 0x3c40;
            break;
        }
        if (draw) {
            PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(w->slots[j].win), 0, 0, s2, font, color);
            w->slots[j].shown = 1;
        }
    }
    STRBUF_Delete(s1);
    STRBUF_Delete(s2);
}

/*
 * lever: signed inner index cast keeps cleanup address apart from unsigned polling address.
 */
int WIFIBATTLEMATCH_VIEW_UpdateWindow(unsigned char *p, void *mgr)
{
    unsigned i;
    int result = 1;
    for (i = 0; i < ((Work *)p)->count; i++) {
        if (*(void **)(p + i * 4 + 4)) {
            unsigned char *e = p + i * 8;
            if (e[0x80] != 0) {
                if (PRINTSYS_QUE_IsExistTarget(mgr, BMP_WIN_GetBmp(((Work *)e)->slots[0].win)) == 0) {
                    BMP_WIN_TransferChars(*(void **)((unsigned)p + (int)i * 8 + 0x7c));
                    *(unsigned char *)((unsigned)p + (int)i * 8 + 0x80) = 0;
                }
            }
            result &= e[0x80] == 0;
        }
    }
    return result;
}

void WIFIBATTLEMATCH_VIEW_DeleteWindow(unsigned *p)
{
    unsigned i;
    for (i = 0; i < p[0]; i++) {
        if ((void *)p[i + 1] != 0)
            BMP_WIN_Delete((void *)p[i + 1]);
    }
}

void WIFIBATTLEMATCH_VIEW_CreatePokeActors(Work *w, void *owner, void *rec, u16 heap)
{
    u8 form;
    u8 shown;
    void *h;
    u16 species;
    u8 gender;
    int i;
    Request req, sub;
    h = ARC_TOOL_CreateHandle(7, heap);
    w->pal = (void *)CLACT_RegisterPaletteCompressed(h, POKE_TOOL_GetIconPaletteArcId(), w->layer, (u16)(w->palSlot << 5), (heap & 0x7fff) | 0x8000);
    w->cell = (void *)CLACT_RegisterCellAnim(h, POKE_TOOL_GetIconCellArcId(), POKE_TOOL_GetIconCellEntryId(), heap);
    for (i = 0; i < 6; i++) {
        species = REGULATION_Party_GetValue(rec, 0, i);
        form = REGULATION_Party_GetValue(rec, 1, i);
        gender = REGULATION_Party_GetValue(rec, 3, i);
        w->chr[i] = (void *)CLACT_RegisterCharacter(h, POKE_TOOL_CalcGraphicIndex((u16)(species != 0 ? species : 1), form, gender, 0), 0, w->layer, (heap & 0x7fff) | 0x8000);
    }
    ARC_TOOL_DeleteHandle(h);
    h = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), heap);
    w->pal2 = (void *)CLACT_RegisterPaletteEx(h, APP_ICON_GetItemCellFileId(), w->layer, (u16)((w->palSlot + 3) << 5), (u32)0, (u32)1, (heap & 0x7fff) | 0x8000);
    w->chr2 = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetItemPaletteFileId(), 0, w->layer, (heap & 0x7fff) | 0x8000);
    w->cell2 = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetItemAnimFileId(2), APP_ICON_GetItemFrameFileId(2), heap);
    ARC_TOOL_DeleteHandle(h);
    MI_CpuFill8(&req, 0, 8);
    req.y = 0xa8;
    req.id = 1;
    req.flag = 1;
    req.a = 1;
    for (i = 0; i < 6; i++) {
        species = REGULATION_Party_GetValue(rec, 0, i);
        form = REGULATION_Party_GetValue(rec, 1, i);
        gender = REGULATION_Party_GetValue(rec, 3, i);
        shown = REGULATION_Party_GetValue(rec, 2, i);
        if (species != 0) {
            req.x = (i << 5) + 0x120;
            w->objs[i] = CLACT_CreateActor(owner, (unsigned int)w->chr[i], (unsigned int)w->pal, (unsigned int)w->cell, &req, w->layer, heap);
            CLACT_SetActorPaletteOffset(w->objs[i], POKE_TOOL_CalcIconPalette(species, form, gender, 0), 0);
            if (shown != 0) {
                sub = req;
                sub.x += 12;
                sub.y += 8;
                sub.a = 0;
                sub.id = 0;
                w->objs[i + 15] = CLACT_CreateActor(owner, (unsigned int)w->chr2, (unsigned int)w->pal2, (unsigned int)w->cell2, &sub, w->layer, heap);
            } else {
                w->objs[i + 15] = 0;
            }
        } else {
            w->objs[i] = 0;
            w->objs[i + 15] = 0;
        }
    }
}

void WIFIBATTLEMATCH_VIEW_DeletePokeActors(char *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0x16c)) {
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x16c));
            *(void **)(p + i * 4 + 0x16c) = 0;
        }
        if (*(void **)(p + i * 4 + 0x1a8)) {
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x1a8));
            *(void **)(p + i * 4 + 0x1a8) = 0;
        }
    }
    for (i = 0; i < 6; i++)
        CLACT_ReleaseCharacter(*(unsigned *)(p + i * 4 + 0x1c4));
    CLACT_ReleaseCellAnim(*(unsigned *)&((Work *)p)->cell);
    CLACT_ReleasePalette(*(unsigned *)&((Work *)p)->pal);
    CLACT_ReleaseCharacter(*(unsigned *)&((Work *)p)->chr2);
    CLACT_ReleasePalette(*(unsigned *)&((Work *)p)->pal2);
    CLACT_ReleaseCellAnim(*(unsigned *)&((Work *)p)->cell2);
}

/*
 * lever: full flag byte times 32 narrowed by fourth callee parameter; no three-bit mask.
 */
void WIFIBATTLEMATCH_VIEW_CreatePokeActor(unsigned char *p, unsigned idx, void *owner, u16 heap)
{
    void *handle;
    Request req;
    handle = ARC_TOOL_CreateHandle(0x20, heap);
    ((Work *)p)->actorPal = CLACT_RegisterPaletteEx(handle, 0, ((Work *)p)->layer, p[0x233] * 32, d_021E8CBE[idx], 1, heap);
    ((Work *)p)->actorChr = CLACT_RegisterCharacter(handle, idx + 0x31, 0, ((Work *)p)->layer, heap);
    ((Work *)p)->actorCell = CLACT_RegisterCellAnim(handle, 0x41, 0x42, heap);
    ARC_TOOL_DeleteHandle(handle);
    MI_CpuFill8(&req, 0, 8);
    req.y = 0;
    req.x = 0;
    req.flag = 1;
    ((Work *)p)->objs[7] = CLACT_CreateActor(owner, ((Work *)p)->actorChr, ((Work *)p)->actorPal, ((Work *)p)->actorCell, &req, ((Work *)p)->layer, heap);
    CLACT_SetActorPaletteOffset(((Work *)p)->objs[7], 0, 1);
}

void WIFIBATTLEMATCH_VIEW_DeletePokeActor(char *p)
{
    CLACT_DeleteActor(((Work *)p)->objs[7]);
    CLACT_ReleaseCharacter((u32)(((Work *)p)->actorChr));
    CLACT_ReleaseCellAnim((u32)(((Work *)p)->actorCell));
    CLACT_ReleasePalette((u32)(((Work *)p)->actorPal));
}

void WIFIBATTLEMATCH_VIEW_CreateActorFromTable(char *p, void *owner, void *table, u16 heap)
{
    Request req;
    unsigned v, a, b, c;
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x118;
    req.y = 0x98;
    req.id = 7;
    req.flag = 1;
    v = ((Work *)p)->layer;
    a = WIFIBATTLEMATCH_VIEW_GetFrameIndex(table, v + 2);
    b = WIFIBATTLEMATCH_VIEW_GetFrameIndex(table, ((Work *)p)->layer);
    c = WIFIBATTLEMATCH_VIEW_GetFrameIndex(table, v + 4);
    ((Work *)p)->objs[8] = CLACT_CreateActor(owner, a, b, c, &req, v, heap);
}

void WIFIBATTLEMATCH_VIEW_DeleteActorFromTable(int *p)
{
    CLACT_DeleteActor((struct Obj *)(((Work *)p)->objs[8]));
}

void WIFIBATTLEMATCH_VIEW_CreateActorFromInfo(char *p, const WifiBattleMatchViewMainInfo *desc, void *owner, void *table, u16 heap)
{
    unsigned n, i, a, b, c;
    Request req;
    n = WIFIBATTLEMATCH_VIEW_GetEntryValue(desc->total, desc->a, desc->b);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x100;
    req.y = 0x10;
    for (i = 0; i < n; i++) {
        req.x += 0x10;
        req.id = i + 2;
        a = WIFIBATTLEMATCH_VIEW_GetFrameIndex(table, 3);
        b = WIFIBATTLEMATCH_VIEW_GetFrameIndex(table, 1);
        c = WIFIBATTLEMATCH_VIEW_GetFrameIndex(table, 5);
        *(void **)(p + i * 4 + 0x190) = CLACT_CreateActor(owner, a, b, c, &req, 1, heap);
    }
}

void WIFIBATTLEMATCH_VIEW_DeleteActorFromInfo(char *p)
{
    int i;
    for (i = 9; i < 14; i++) {
        if (*(void **)(p + i * 4 + 0x16c) != 0) {
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x16c));
            *(void **)(p + i * 4 + 0x16c) = 0;
        }
    }
}

WifiBattleMatchViewRecordWork *WIFIBATTLEMATCH_VIEW_CreateRecordWindow(const WifiBattleMatchViewRecord *rec, void *clunit, void *table, void *font, void *printQue, void *msgData, void *wordSet, u32 mode, u32 owner, int style, u16 heap)
{
    WifiBattleMatchViewRecordWork *w;
    u32 kind;
    int alt;
    w = GFL_HEAP_Alloc(heap, 0x9c, 0, d_021E8DBC, 0x952);
    MI_CpuFill8(w, 0, 0x9c);
    w->owner = owner;
    w->mode = mode;
    w->menu = PMS_DRAW_Create((u32)clunit, 0, (u32)printQue, (u32)font, 5, 1, heap);
    PMS_DRAW_SetFollowBgScroll(w->menu, 1);
    PMS_DRAW_SetNullColorPalette(w->menu, 0);
    kind = WIFIBATTLEMATCH_VIEW_GetEntryValue(rec->total, rec->score, rec->losses);
    alt = 0;
    if (mode - 2 <= 1)
        alt = kind == 5;
    WIFIBATTLEMATCH_VIEW_SetupRecordWindow(w, rec, (unsigned)font, printQue, msgData, wordSet, alt, heap);
    WIFIBATTLEMATCH_VIEW_CreateRecordActor((char *)w, MYSTATUS_GetTrainerView((const struct MyStatus *)rec), clunit, heap);
    ARC_UTIL_UploadBgPaletteFromArchive(0x85, 9, 2, 0, 0, 0, (heap & 0x7fff) | 0x8000);
    switch (mode) {
    case 2:
    case 3:
        WIFIBATTLEMATCH_VIEW_CreateRecordActorFromRec((char *)w, rec, clunit, table, heap);
        BG_SYS_FillTileMap(2, 0, 0, 0x20, 2, 1);
        BG_SYS_FillTileMap(2, 0, 3, 0x20, 0x20, kind + 3);
        BG_SYS_FillTileMap(2, 0, 3, 1, 2, 1);
        BG_SYS_FillTileMap(2, 0x1f, 3, 1, 2, 1);
        break;
    case 0:
    case 1:
        BG_SYS_DrawTileEx(2, 0, 0, 0x20, 2, BG_SYS_GetBuf(2), 0, 0x18, 0x20, 0x20);
        switch (style) {
        case 0:
            BG_SYS_FillTileMap(2, 0, 0, 0x20, 2, 1);
            BG_SYS_FillTileMap(2, 0, 3, 0x20, 0x20, 3);
            BG_SYS_FillTileMap(2, 0, 3, 1, 2, 1);
            BG_SYS_FillTileMap(2, 0x1f, 3, 1, 2, 1);
            break;
        case 1:
            BG_SYS_FillTileMap(2, 0, 0, 0x20, 2, 1);
            BG_SYS_FillTileMap(2, 0, 3, 0x20, 0x20, 7);
            BG_SYS_FillTileMap(2, 0, 3, 1, 2, 1);
            BG_SYS_FillTileMap(2, 0x1f, 3, 1, 2, 1);
            break;
        }
        break;
    }
    BG_SYS_PushTile(2);
    BG_SYS_ChangeScrollImmediate(2, 0, ~0xff);
    BG_SYS_ChangeScrollImmediate(1, 0, ~0xff);
    G2x_SetBlendAlpha_((void *)0x04000050, 4, 8, 0xf, 3);
    return w;
}

/*
 * volatile: 0x021E7718 writes hardware 0x04000050
 */
void WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(char *p)
{
    *(volatile unsigned short *)0x04000050 = 0;
    switch (((WifiBattleMatchViewRecordWork *)p)->mode) {
    case 0: case 1: break;
    case 2: case 3: WIFIBATTLEMATCH_VIEW_DeleteRecordActorObj((WifiBattleMatchViewRecordWork *)p); break;
    }
    WIFIBATTLEMATCH_VIEW_DeleteRecordActor(p);
    WIFIBATTLEMATCH_VIEW_DeleteRecordWin((WifiBattleMatchViewRecordWork *)p);
    PMS_DRAW_Delete(((WifiBattleMatchViewRecordWork *)p)->menu);
    BG_SYS_ChangeScrollImmediate(2, 0, -256);
    BG_SYS_ChangeScrollImmediate(1, 0, -256);
    GFL_HEAP_Free(p);
}

int WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(void *p, void *mgr)
{
    return WIFIBATTLEMATCH_VIEW_UpdateRecordWindowInner(p, mgr);
}

int WIFIBATTLEMATCH_VIEW_StepRecordWindow(WifiBattleMatchViewRecordWork *p)
{
    int done;
    int shift;
    Pt pos[2];
    int i;
    done = 0;
    if (p->count == 0) {
        if (p->recordActor != 0) {
            CLACT_GetActorSurfacePos(p->recordActor, (struct PtS *)&pos[1], done);
            p->base = pos[1].x;
        }
        for (i = 0; i < 5; i++) {
            if (p->obj[i] != 0) {
                CLACT_GetActorSurfacePos(p->obj[i], (struct PtS *)&pos[1], 0);
                p->objBase[i] = pos[1].x;
            }
        }
        GFL_USE_PlaySeDefaultVolume(0x63B);
    }
    shift = (p->count << 8) / 20 - 0x100;
    if (p->recordActor != 0) {
        CLACT_GetActorSurfacePos(p->recordActor, (struct PtS *)&pos[0], 0);
        pos[0].x = p->base - (p->count << 8) / 20;
        CLACT_AddActorSurfacePos(p->recordActor, &pos[0], 0);
    }
    for (i = 0; i < 5; i++) {
        if (p->obj[i] != 0) {
            CLACT_GetActorSurfacePos(p->obj[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->objBase[i] - (p->count << 8) / 20;
            CLACT_AddActorSurfacePos(p->obj[i], &pos[0], 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0;
        p->count = 0;
        done = 1;
    }
    BG_SYS_ChangeScroll(2, 0, shift);
    BG_SYS_ChangeScroll(1, 0, shift);
    return done;
}

void WIFIBATTLEMATCH_VIEW_SetupRecordWindow(WifiBattleMatchViewRecordWork *p, const WifiBattleMatchViewRecord *data, unsigned font, void *print, void *msg, void *fmt, int alt, u16 heap)
{
    void *str;
    void *buf;
    int j;
    u16 color;
    int draw;
    void *win;
    int i;
    for (i = 0; i < 8; i++) {
        p->win[i] = (void *)BMP_WIN_Create(1, d_021E8CEE[i].bg, d_021E8CEE[i].x, d_021E8CEE[i].y, d_021E8CEE[i].w, 15, 1);
        BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 0);
        win = p->win[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
        if (i != 7) {
            p->ent[i].win = p->win[i];
            p->ent[i].shown = 0;
        }
    }
    buf = STRBUF_Create(0x80, heap);
    str = STRBUF_Create(0x80, heap);
    for (j = 0; j < 8; j++) {
        color = alt == 1 ? 0x3C40 : 0x440;
        draw = 1;
        switch (j) {
        case 0:
            STRBUF_SetString(str, MYSTATUS_GetName(data));
            color = 0x3C40;
            break;
        case 1:
            if (p->mode == 3) {
                MSGDATA_ReadString(msg, 12, str);
                color = 0x3C40;
            } else if (p->owner != 0) {
                MSGDATA_ReadString(msg, 8, str);
                color = 0x3C40;
            } else {
                draw = 0;
            }
            break;
        case 2:
            if (p->mode == 3) {
                MSGDATA_ReadString(msg, 13, buf);
                WORDSET_SetSlotNumber(fmt, 0, data->score, 5, 1, 1);
                WORDSET_CopyTaggedText(fmt, str, buf);
                color = 0x3C40;
            } else if (p->owner != 0) {
                MSGDATA_ReadString(msg, 9, buf);
                WORDSET_SetSlotNumber(fmt, 0, data->count, 4, 1, 1);
                WORDSET_CopyTaggedText(fmt, str, buf);
                color = 0x3C40;
            } else {
                draw = 0;
            }
            break;
        case 3:
            MSGDATA_ReadString(msg, 20, str);
            color = 0x3C40;
            break;
        case 4:
            MSGDATA_ReadString(msg, 22, buf);
            WORDSET_SetSlotFromMsgE7(fmt, 0, MYSTATUS_GetNation((const struct MyStatus *)data));
            WORDSET_CopyTaggedText(fmt, str, buf);
            break;
        case 5:
            MSGDATA_ReadString(msg, 23, buf);
            WORDSET_SetSlotFromKeyedMessage(fmt, 0, MYSTATUS_GetNation((const struct MyStatus *)data), MYSTATUS_GetArea((const struct MyStatus *)data));
            WORDSET_CopyTaggedText(fmt, str, buf);
            break;
        case 6:
            MSGDATA_ReadString(msg, 21, str);
            color = 0x3C40;
            break;
        case 7:
            PMS_DRAW_SetPrintColor(p->menu, color);
            PMS_DRAW_Print(p->menu, p->win[j], data->name, 0);
            draw = 0;
            break;
        }
        if (draw) {
            PRINTSYS_PrintQueColor(print, BMP_WIN_GetBmp(p->ent[j].win), 0, 0, str, font, color);
            p->ent[j].shown = 1;
        }
    }
    STRBUF_Delete(buf);
    STRBUF_Delete(str);
}

static inline int poll_entry(unsigned char *e, void *mgr)
{
    if (e[0x28] != 0) {
        if (PRINTSYS_QUE_IsExistTarget(mgr, BMP_WIN_GetBmp(((WifiBattleMatchViewRecordWork *)e)->ent[0].win)) == 0) {
            BMP_WIN_TransferChars(((WifiBattleMatchViewRecordWork *)e)->ent[0].win);
            e[0x28] = 0;
        }
    }
    return e[0x28] == 0;
}

/*
 * lever: repeat result accumulation in each branch; hoisting through done changes cross-jump and allocation.
 */
int WIFIBATTLEMATCH_VIEW_UpdateRecordWindowInner(unsigned char *p, void *mgr)
{
    int i;
    unsigned result = 1;
    for (i = 0; i < 8; i++) {
        unsigned done;
        if (i != 7) {
            result &= poll_entry(p + i * 8, mgr);
        } else {
            PMS_DRAW_Main(((WifiBattleMatchViewRecordWork *)p)->menu);
            result &= PMS_DRAW_IsPrintEnd(((WifiBattleMatchViewRecordWork *)p)->menu);
        }
    }
    return result;
}

void WIFIBATTLEMATCH_VIEW_DeleteRecordWin(WifiBattleMatchViewRecordWork *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->win[i] != 0) {
            BMP_WIN_ClearScreen(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
    }
}

void WIFIBATTLEMATCH_VIEW_CreateRecordActor(char *p, unsigned idx, void *owner, u16 heap)
{
    void *handle;
    Request req;
    handle = ARC_TOOL_CreateHandle(0x20, heap);
    ((WifiBattleMatchViewRecordWork *)p)->recPal = CLACT_RegisterPaletteEx(handle, 0, 0, 0x140, d_021E8CBE[idx], 1, heap);
    ((WifiBattleMatchViewRecordWork *)p)->recChr = CLACT_RegisterCharacter(handle, idx + 0x31, 0, 0, heap);
    ((WifiBattleMatchViewRecordWork *)p)->recCell = CLACT_RegisterCellAnim(handle, 0x41, 0x42, heap);
    ARC_TOOL_DeleteHandle(handle);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x120;
    req.y = 0x2c;
    ((WifiBattleMatchViewRecordWork *)p)->recordActor = CLACT_CreateActor(owner, ((WifiBattleMatchViewRecordWork *)p)->recChr, ((WifiBattleMatchViewRecordWork *)p)->recPal, ((WifiBattleMatchViewRecordWork *)p)->recCell, &req, 0, heap);
    CLACT_SetActorPaletteOffset(((WifiBattleMatchViewRecordWork *)p)->recordActor, 0, 1);
}

void WIFIBATTLEMATCH_VIEW_DeleteRecordActor(char *p)
{
    CLACT_DeleteActor(((WifiBattleMatchViewRecordWork *)p)->recordActor);
    CLACT_ReleaseCharacter(((WifiBattleMatchViewRecordWork *)p)->recChr);
    CLACT_ReleaseCellAnim(((WifiBattleMatchViewRecordWork *)p)->recCell);
    CLACT_ReleasePalette(((WifiBattleMatchViewRecordWork *)p)->recPal);
}

void WIFIBATTLEMATCH_VIEW_CreateRecordActorFromRec(char *p, const WifiBattleMatchViewRecord *q, void *x, void *data, u16 heap)
{
 unsigned i,n;
 Request b;
 n=WIFIBATTLEMATCH_VIEW_GetEntryValue(q->total, q->score, q->losses);
 MI_CpuFill8(&b,0,8);
 b.x=0x100;b.y=0x10;
 for(i=0;i<n;i++) {
 int a,c,d;
 b.x+=0x10;b.id=i+2;
 a=WIFIBATTLEMATCH_VIEW_GetFrameIndex(data,2);c=WIFIBATTLEMATCH_VIEW_GetFrameIndex(data,0);d=WIFIBATTLEMATCH_VIEW_GetFrameIndex(data,4);
 *(void **)(p+i*4+0x68)=CLACT_CreateActor(x,a,c,d,&b,0,heap);
 }
}

void WIFIBATTLEMATCH_VIEW_DeleteRecordActorObj(WifiBattleMatchViewRecordWork *p)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (p->obj[i] != 0) {
            CLACT_DeleteActor(p->obj[i]);
            p->obj[i] = 0;
        }
    }
}

unsigned WIFIBATTLEMATCH_VIEW_GetEntryValue(void *total, unsigned wins, unsigned losses)
{
    if (wins >= 1000) {
        return 5;
    }
    if (wins >= 500) {
        return 4;
    }
    if (wins >= 200) {
        return 3;
    }
    if (wins >= 100) {
        return 2;
    }
    if (wins >= 50) {
        return 1;
    }
    return 0;
}

void **WIFIBATTLEMATCH_VIEW_CreateActorArray(void *owner, void *src, u16 heap)
{
    void **objs;
    Request req;
    objs = GFL_HEAP_Alloc(heap, 8, 0, d_021E8DBC, 0xBEF);
    MI_CpuFill8(objs, 0, 8);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x80;
    req.y = 0x60;
    req.id = 1;
    req.a = 1;
    req.flag = 1;
    objs[0] = CLACT_CreateActor(owner, WIFIBATTLEMATCH_VIEW_GetFrameIndex(src, 2), WIFIBATTLEMATCH_VIEW_GetFrameIndex(src, 0), WIFIBATTLEMATCH_VIEW_GetFrameIndex(src, 4), (const Request *)&req, 0, heap);
    CLACT_SetActorAutoAnim(objs[0], 1);
    req.id = 0;
    req.a = 0;
    req.flag = 1;
    objs[1] = CLACT_CreateActor(owner, WIFIBATTLEMATCH_VIEW_GetFrameIndex(src, 2), WIFIBATTLEMATCH_VIEW_GetFrameIndex(src, 0), WIFIBATTLEMATCH_VIEW_GetFrameIndex(src, 4), (const Request *)&req, 0, heap);
    CLACT_SetActorAutoAnim(objs[1], 1);
    return objs;
}

void WIFIBATTLEMATCH_VIEW_DeleteActorArray(int *p)
{
    CLACT_DeleteActor((struct Obj *)(*(int *)((char *)p + 4)));
    CLACT_DeleteActor((struct Obj *)(*(int *)p));
    GFL_HEAP_Free(p);
}

/*
 * extent: bx lr followed by two bytes zero alignment and existing labelled 021E7E0C.
 */
void WIFIBATTLEMATCH_VIEW_Noop(int p) {}

void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **p, int on)
{
    if (on == 1) {
        GFL_USE_PlaySeDefaultVolume(0x80D);
    } else {
        GFL_USE_StopSeSlot(2);
    }
    CLACT_SetActorDrawEnable(p[0], on);
    CLACT_SetActorDrawEnable(p[1], on);
}

static inline unsigned HeapTemp(unsigned heap)
{
    heap &= 0x7FFF;
    heap |= 0x8000;
    return heap;
}

/*
 * The temporary heap id is formed twice: once through an inline that
 * rewrites its own parameter (the image copies heap before the and), held
 * in r7 for the first block; then as a plain expression, which the
 * compiler CSEs into a temporary slot below the loop pointers. One shared
 * expression or one shared local CSEs both blocks together.
 */
WifiBattleMatchViewPartyWork *WIFIBATTLEMATCH_VIEW_CreatePartyWindow(void *src, void *owner, int unused, unsigned font, void *print, void *msg, u16 heap)
{
    WifiBattleMatchViewPartyWork *work;
    void *party;
    void *handle;
    void *mon;
    u8 x;
    void *fmt;
    void *buf;
    void *sLevel;
    void *sMale;
    void *sFemale;
    void *win;
    u8 level;
    int i;
    unsigned h;
    Request req;
    Request req2;
    Pt pos;
    work = GFL_HEAP_Alloc(heap, sizeof(WifiBattleMatchViewPartyWork), 0, d_021E8DBC, 0xC8A);
    MI_CpuFill8(work, 0, sizeof(WifiBattleMatchViewPartyWork));
    h = HeapTemp(heap);
    party = BATTLE_BOX_CreateParty((int)src, (u16)h);
    ARC_UTIL_UploadBgPaletteFromArchive((int)0x85, (int)7, (int)2, (int)0, (int)0, (int)0, h);
    handle = ARC_TOOL_CreateHandle(7, (unsigned)heap);
    work->pal = (void *)CLACT_RegisterPaletteCompressed(handle, POKE_TOOL_GetIconPaletteArcId(), 0, 0xA0, h);
    work->cell = (void *)CLACT_RegisterCellAnim(handle, POKE_TOOL_GetIconCellArcId(), POKE_TOOL_GetIconCellEntryId(), (u16)h);
    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        mon = POKEPARTY_GetMember(party, (int)i);
        if (POKE_TOOL_GetPartyValue(mon, 0xA9, 0) != 0) {
            work->chr[i] = (void *)CLACT_RegisterCharacter(handle, POKE_TOOL_GetGraphicIndex(POKE_TOOL_GetBoxParam(mon)), 0, 0, h);
        }
    }
    ARC_TOOL_DeleteHandle(handle);
    handle = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), (unsigned)heap);
    work->palB = (void *)CLACT_RegisterPaletteEx(handle, APP_ICON_GetItemCellFileId(), 0, 0x100, 0, 1, (heap & 0x7FFF) | 0x8000);
    work->cellB = (void *)CLACT_RegisterCellAnim(handle, APP_ICON_GetItemAnimFileId((int)2), APP_ICON_GetItemFrameFileId((int)2), (u16)((heap & 0x7FFF) | 0x8000));
    work->chrB = (void *)CLACT_RegisterCharacter(handle, APP_ICON_GetItemPaletteFileId(), 0, 0, (heap & 0x7FFF) | 0x8000);
    ARC_TOOL_DeleteHandle(handle);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x18;
    req.y = 0x2C;
    req.id = 1;
    req.a = 1;
    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        mon = POKEPARTY_GetMember(party, (int)i);
        if (POKE_TOOL_GetPartyValue(mon, 0xA9, 0) != 0) {
            req.x = i * 0x28 + 0x18;
            work->spr[i] = CLACT_CreateActor(owner, (unsigned)(work->chr[i]), (unsigned)work->pal, (unsigned)work->cell, (const Request *)&req, 0, heap);
            CLACT_SetActorPaletteOffset(work->spr[i], POKE_TOOL_GetIconPalette(POKE_TOOL_GetBoxParam(mon)), 0);
            if (POKE_TOOL_GetPartyValue(mon, 6, 0) != 0) {
                req2 = req;
                req2.x += 12;
                req2.y += 8;
                req2.a = 0;
                req2.id = 0;
                work->spr[i + 7] = CLACT_CreateActor(owner, (unsigned)work->chrB, (unsigned)work->palB, (unsigned)work->cellB, (const Request *)&req2, 0, heap);
            }
        }
    }
    fmt = WORDSET_CreateDefault((u16)((heap & 0x7FFF) | 0x8000));
    buf = STRBUF_Create(0x80, (u16)((heap & 0x7FFF) | 0x8000));
    sLevel = MSGDATA_AllocString(msg, 0x63);
    sMale = MSGDATA_AllocString(msg, 0x64);
    sFemale = MSGDATA_AllocString(msg, 0x65);
    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        mon = POKEPARTY_GetMember(party, (int)i);
        if (POKE_TOOL_GetPartyValue(mon, 0xA9, 0) != 0) {
            work->win[i] = (void *)BMP_WIN_Create((unsigned char)1, (unsigned char)(i * 5 + 1), (unsigned char)4, (unsigned char)5, 6, 15, 1);
            win = work->win[i];
            BMP_WIN_TransferChars(win);
            BMP_WIN_MakeScreen(win);
            BG_SYS_PushTile((int)BMP_WIN_GetBgLayer(win));
            work->ent[i].win = work->win[i];
            work->ent[i].shown = 0;
            if (POKE_TOOL_GetPartyValue(mon, 0x6E, 0) == 0) {
                PRINTSYS_PrintQueColor(print, BMP_WIN_GetBmp(work->ent[i].win), 0x20, 0, sMale, font, 0x14C0);
                work->ent[i].shown = 1;
            } else if (POKE_TOOL_GetPartyValue(mon, 0x6E, 0) == 1) {
                PRINTSYS_PrintQueColor(print, BMP_WIN_GetBmp(work->ent[i].win), 0x20, 0, sFemale, font, 0xC80);
                work->ent[i].shown = 1;
            }
            level = POKE_TOOL_GetPartyValue(mon, 0x9E, 0);
            WORDSET_SetSlotNumber(fmt, 0, level, 3, 1, 1);
            WORDSET_CopyTaggedText(fmt, buf, sLevel);
            x = 20 - PRINTSYS_MeasureWidestLine(buf, font, 0) / 2;
            PRINTSYS_PrintQueColor(print, BMP_WIN_GetBmp(work->ent[i].win), x, 0x24, buf, font, 0x440);
            work->ent[i].shown = 1;
        }
    }
    STRBUF_Delete(sFemale);
    STRBUF_Delete(sMale);
    STRBUF_Delete(sLevel);
    STRBUF_Delete(buf);
    WORDSET_Delete(fmt);
    for (i = 0; i < 14; i++) {
        if (work->spr[i] != 0) {
            CLACT_GetActorSurfacePos(work->spr[i], (struct PtS *)&pos, 0);
            pos.x += 0x100;
            CLACT_AddActorSurfacePos(work->spr[i], &pos, 0);
        }
    }
    BG_SYS_ChangeScrollImmediate((int)2, (int)0, (int)(-0x100));
    BG_SYS_ChangeScrollImmediate((int)1, (int)0, (int)(-0x100));
    GFL_HEAP_Free(party);
    G2x_SetBlendAlpha_((void *)0x04000050, 4, 8, 15, 3);
    return work;
}

/*
 * volatile: hardware write 021E82C4.
 */
void WIFIBATTLEMATCH_VIEW_DeletePartyWindow(char *p)
{
 int i;
 *(volatile unsigned short *)0x04000050 = 0;
 for(i=0;i<6;i++) {if(*(void **)(p+i*4+0x68)!=0){BMP_WIN_ClearScreen(*(void **)(p+i*4+0x68));BMP_WIN_Delete(*(void **)(p+i*4+0x68));}}
 for(i=0;i<14;i++)if(*(void **)(p+i*4+0x30)!=0)CLACT_DeleteActor(*(void **)(p+i*4+0x30));
 CLACT_ReleaseCharacter((u32)(((WifiBattleMatchViewPartyWork *)p)->chrB));CLACT_ReleaseCellAnim((u32)(((WifiBattleMatchViewPartyWork *)p)->cellB));CLACT_ReleasePalette((u32)(((WifiBattleMatchViewPartyWork *)p)->palB));
 for(i=0;i<6;i++)if(*(void **)(p+i*4+0x30)!=0)CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+4)));
 CLACT_ReleaseCellAnim((u32)(((WifiBattleMatchViewPartyWork *)p)->cell));CLACT_ReleasePalette((u32)(((WifiBattleMatchViewPartyWork *)p)->pal));GFL_HEAP_Free(p);
}

int WIFIBATTLEMATCH_VIEW_StepPartyWindow(WifiBattleMatchViewPartyWork *p)
{
    int done;
    int shift;
    Pt pos[2];
    int i;
    if (BG_SYS_GetScrollX(2) == 0) {
        return 1;
    }
    done = 0;
    if (p->count == 0) {
        for (i = done; i < 14; i++) {
            if (p->spr[i] != 0) {
                CLACT_GetActorSurfacePos(p->spr[i], (struct PtS *)&pos[1], 0);
                p->base[i] = pos[1].x;
            }
        }
    }
    shift = (p->count << 8) / 20 - 0x100;
    for (i = 0; i < 14; i++) {
        if (p->spr[i] != 0) {
            CLACT_GetActorSurfacePos(p->spr[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->base[i] - (p->count << 8) / 20;
            CLACT_AddActorSurfacePos(p->spr[i], &pos[0], 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0;
        p->count = 0;
        done = 1;
    }
    BG_SYS_ChangeScroll(2, 0, shift);
    BG_SYS_ChangeScroll(1, 0, shift);
    return done;
}

int WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(WifiBattleMatchViewPartyWork *p)
{
    int done;
    int shift;
    Pt pos[2];
    int i;
    done = 0;
    if (p->count == 0) {
        for (i = done; i < 14; i++) {
            if (p->spr[i] != 0) {
                CLACT_GetActorSurfacePos(p->spr[i], (struct PtS *)&pos[1], 0);
                p->base[i] = pos[1].x;
            }
        }
    }
    shift = (p->count << 8) / 20;
    for (i = 0; i < 14; i++) {
        if (p->spr[i] != 0) {
            CLACT_GetActorSurfacePos(p->spr[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->base[i] - (p->count << 8) / 20;
            CLACT_AddActorSurfacePos(p->spr[i], &pos[0], 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0x100;
        p->count = 0;
        done = 1;
    }
    BG_SYS_ChangeScroll(2, 0, shift);
    BG_SYS_ChangeScroll(1, 0, shift);
    return done;
}

int WIFIBATTLEMATCH_VIEW_UpdatePartyWindow(char *p, void *q)
{
 int result=1;
 unsigned i;
 for(i=0;(int)i<6;i++) {
 if(*(void **)(p+i*4+0x68)!=0) {
 unsigned char *e=(unsigned char *)p+i*8;
 if(e[0x84]!=0) {
 if(PRINTSYS_QUE_IsExistTarget(q,BMP_WIN_GetBmp(((WifiBattleMatchViewPartyWork *)e)->ent[0].win))==0) {
 BMP_WIN_TransferChars(*(void **)((unsigned)p+(int)i*8+0x80));*(unsigned char *)((unsigned)p+(int)i*8+0x84)=0;
 }
 }
 result &= e[0x84]==0;
 }
 }
 return result;
}
