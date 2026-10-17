/*
 * file:     zukan_info.c
 * unit:     yes
 * function: ZUKAN_INFO_CreateFromMon, ZUKAN_INFO_Create, ZUKAN_INFO_Delete, ZUKAN_INFO_Update, ZUKAN_INFO_ClearDisplay, ZUKAN_INFO_ClearActors, ZUKAN_INFO_SetPokemon, ZUKAN_INFO_ShowPage, ZUKAN_INFO_SetPokemonPage, ZUKAN_INFO_Show, ZUKAN_INFO_Hide, ZUKAN_INFO_Task, ZUKAN_INFO_CreateWindows, ZUKAN_INFO_DeleteWindows, ZUKAN_INFO_DrawText, ZUKAN_INFO_DrawMessage, ZUKAN_INFO_DrawMainPage, ZUKAN_INFO_DrawPage, ZUKAN_INFO_ClearSlotWindows, ZUKAN_INFO_FlushSlotWindows, ZUKAN_INFO_CreateBgBmp, ZUKAN_INFO_DeleteMainWindows, ZUKAN_INFO_FlushMainWindow, ZUKAN_INFO_SetActors, ZUKAN_INFO_ReleaseActor, ZUKAN_INFO_RegisterGfx, ZUKAN_INFO_ReleaseGfx, ZUKAN_INFO_CreateActor, ZUKAN_INFO_DeleteActor, ZUKAN_INFO_DisableActors, ZUKAN_INFO_CreateIconActors, ZUKAN_INFO_DeleteIconActors, ZUKAN_INFO_ShowFormPair, ZUKAN_INFO_LayoutFormPair, ZUKAN_INFO_LayoutFormPairEx, ZUKAN_INFO_DeleteRow, ZUKAN_INFO_DisableOtherRows, ZUKAN_INFO_InitFormGfx, ZUKAN_INFO_DeleteFormGfx, ZUKAN_INFO_CreateSpeciesActor, ZUKAN_INFO_DeleteActorPair, ZUKAN_INFO_DisableUnselected, ZUKAN_INFO_RefreshDisplay, ZUKAN_INFO_RefreshPage, ZUKAN_INFO_BlendPalette, ZUKAN_INFO_SetDrawEnable, ZUKAN_INFO_SetSlotDrawEnable, ZUKAN_INFO_LoadResources, ZUKAN_INFO_FreeResources, ZUKAN_INFO_GetTypeArchiveId, ZUKAN_INFO_GetSpeciesCellFileId, ZUKAN_INFO_GetPaletteFileId, ZUKAN_INFO_GetCellAnimFileId, ZUKAN_INFO_GetCellAnimMode, ZUKAN_INFO_GetIconArchiveId, ZUKAN_INFO_GetFormFlag
 * address:  0x021B9DE0
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   POKE_TOOL_IsShiny 0x02017EAC thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021BC220 0x021BC220 data
 *   TCB_DeleteTask 0x02030EAC arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PM_VOICE_Play 0x02006984 thumb
 *   CLACT_GetActorPos 0x0204B53C arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   d_021BC174 0x021BC174 data a1
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   GF_FONT_MeasureWidestLine 0x0201D304 thumb
 *   BMP_GetWidth 0x020437DC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   gSpeciesNameBank 0x020A7370 data
 *   d_021BC110 0x021BC110 data a2
 *   d_021BC11C 0x021BC11C data a2
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   BMP_Delete  0x020437AC  arm
 *   BMP_CreateFromArchive  0x0204384C  arm
 *   BMP_Blit  0x020439A0  arm
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorFlip 0x0204B604 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   d_021BC128 0x021BC128 data a2
 *   d_021BC150 0x021BC150 data a1
 *   FX_SinCosTable_ 0x020A1B38 data
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   tbl_021BC134 0x021BC134 data
 *   tbl_021BC1C4 0x021BC1C4 data
 *   tbl_021BC184 0x021BC184 data
 *   MSGDATA_Delete 0x02045C04 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */

struct ArcFile;
struct NitroFileHeader;
struct Personal;
struct Node;
struct PrintSys;
struct Actor;
struct CharBuf;
struct Descriptor;
struct Bmp;
struct StrObj;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct Cfg;
struct Bmp;
struct Obj;
struct Vec2;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef short s16;

struct Pt { s16 x; s16 y; };

struct Tab16 { u8 b[16]; };

typedef enum { ZERO } Zero;

typedef struct { short x,y,z,w; } ActorCreatePos;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct {
    unsigned short a, b, c;
    unsigned char d, e;
} ActorRect;

typedef struct {
    short x, y;
} ActorSurfacePos;

typedef struct {
    short x, y, z, w;
} ShortRect4;

typedef struct {
    short a, b, c;
    unsigned char d, e;
} Rect;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    unsigned char a, b;
} Tile;

typedef struct {
    char pad[0x14];
    int f14;
} Blob;

typedef enum Flag { FLAG_ZERO=0,FLAG_ONE=1 } Flag;

struct Point {
    s16 x;
    s16 y;
    u16 f4;
    u8 f6;
    u8 f7;
};

typedef signed char s8;

/*
 * The Pokedex info screen work object, allocated at 0x2b4 bytes in
 * ZUKAN_INFO_Create. Every Obj view in this file is a window onto this object.
 * Where two views disagreed on a field type at one offset but not its size the
 * type that the code actually uses is kept (a pointer for the handle slots, an
 * int for the plain counters); the alternate view only cast the value.
 */
struct ZukanInfo {
    u16 heap;                 /* 0x000 */
    u16 pad_02;               /* 0x002 */
    int formTableNeeded;      /* 0x004 */
    int showCurrent;          /* 0x008 */
    u16 species;              /* 0x00C */
    u16 form;                 /* 0x00E */
    u16 gender;               /* 0x010 */
    u16 move;                 /* 0x012 */
    int personalParam;        /* 0x014 */
    int mode;                 /* 0x018 */
    int femaleFlag;           /* 0x01C */
    u8 bgLayerBase;           /* 0x020 */
    u8 pad_21[3];             /* 0x021 */
    unsigned int clactUnit;   /* 0x024 */
    int font;                 /* 0x028 */
    void *printQue;           /* 0x02C */
    u32 charHandle;           /* 0x030 */
    u32 charHandle2;          /* 0x034 */
    u8 tileDirty;             /* 0x038 */
    u8 reloadFlag;            /* 0x039 */
    u8 pad_3A[2];             /* 0x03A */
    u32 cellHandle;           /* 0x03C */
    int gfxSlot;              /* 0x040 */
    int hidden;               /* 0x044 */
    int bgConfig;             /* 0x048 */
    u8 layerMain;             /* 0x04C */
    u8 layerUpper;            /* 0x04D */
    u8 layerLower;            /* 0x04E */
    u8 pad_4F;                /* 0x04F */
    void *task;               /* 0x050 */
    int animState;            /* 0x054 */
    int animParam58;          /* 0x058 */
    int animParam5C;          /* 0x05C */
    int animTimer;            /* 0x060 */
    int blinkTimer;           /* 0x064 */
    int windowBottom;         /* 0x068 */
    int win[4];               /* 0x06C */
    int slotDirty[4];         /* 0x07C */
    void *winMain;            /* 0x08C */
    void *winAlt;             /* 0x090 */
    void *charRes[2];         /* 0x094 */
    void *palRes[2];          /* 0x09C */
    void *cellRes[2];         /* 0x0A4 */
    void *actors[2];          /* 0x0AC */
    int selected;             /* 0x0B4 */
    int charIds[2][2];        /* 0x0B8 */
    u32 paletteHandle;        /* 0x0C8 */
    u32 cellAnimHandle;       /* 0x0CC */
    void *actorSlots[2][2];   /* 0x0D0 */
    int iconEnabled;          /* 0x0E0 */
    int iconVisible;          /* 0x0E4 */
    void *iconChars[17];      /* 0x0E8 */
    void *iconActors[17];     /* 0x12C */
    u8 shownFormA;            /* 0x170 */
    u8 shownFormB;            /* 0x171 */
    u8 pad_172[2];            /* 0x172 */
    u32 formChar[2];          /* 0x174 */
    u32 paletteHandleA;       /* 0x17C */
    u32 cellAnimA;            /* 0x180 */
    u32 cellAnimB;            /* 0x184 */
    void *formActor[2];       /* 0x188 */
    int flag190;              /* 0x190 */
    u16 bgOffset;             /* 0x194 */
    u16 palBuf[5];            /* 0x196 */
    u16 palA[5];              /* 0x1A0 */
    u16 palB[5];              /* 0x1AA */
    int yOffset;              /* 0x1B4 */
    void *g[3];               /* 0x1B8 */
    void *w[7];               /* 0x1C4 */
    void *objs[35];           /* 0x1E0 */
    void *x;                  /* 0x26C */
    union {
        int input[16];        /* 0x270 */
        void *str[16];        /* 0x270 */
    } text;
    void *speciesTable;       /* 0x2B0 */
};

/* Unpacked NCLR payload returned by NNS_G2dGetUnpackedPaletteData. */
struct UnpackedPalette {
    u8 pad_0[12];
    void *palette;
};

extern unsigned POKE_TOOL_GetPartyValue(void *,unsigned,unsigned);
extern u8 POKE_TOOL_GetGender(void *);
extern unsigned POKE_TOOL_IsShiny(void *);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, int v, int n);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
extern u32 GFL_HEAP_Free(void *p);
extern void *GFL_USE_AddMainTask(void (*cb)(int, char *), void *arg, int pri);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void BG_SYS_PushTile(u32 layer);
extern void TCB_DeleteTask(struct Node *n);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 PM_VOICE_Play(u32, u32, u32, u32, u32, u32, u32, u32);
extern void CLACT_GetActorPos(const struct Actor *actor, struct Pt *out);
extern void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *POKE_PERSONAL_Create(u32 a, int b, u32 c);
extern void POKE_PERSONAL_Delete(void *p);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u32 c, u32 d, u32 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern unsigned int PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_SetFlagField06(u32 bit);
extern struct Bmp *BMP_CreateFromArchive(u32 arc, u32 member, u32 heap2, u32 heap);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void BMP_Delete(struct Bmp *p);
extern int POKEGRA_RegisterCgr(int,int,int,int,int,int,int,int,int,unsigned short);
extern int POKEGRA_RegisterPalette(int,int,int,int,int,int,int,int,unsigned short,unsigned short);
extern int POKEGRA_RegisterCellAnim(int,int,int,int,int,int,int,int,unsigned short);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorFlip(struct Actor *actor, u32 which, u32 set);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u32 APP_ICON_GetTouchBarFileId(void);
extern u8 APP_ICON_GetTypePaletteOffset(int i);
extern u32 APP_ICON_GetTypeCellFileId(u32 a);
extern u32 APP_ICON_GetTypePaletteFileId(u32 a);
extern u32 APP_ICON_GetTypeAnimFileId(u32 a);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_AddActorSurfacePos(void *, ActorSurfacePos *, unsigned short);
extern void *ARC_UTIL_LoadBgCharDataFromHandle(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned short a4);
extern void CLACT_TransferCharacterPart(int a, void *b, unsigned int c, int d, int e);
extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);
extern u32 APP_ICON_GetArchiveId(void);
extern int POKEGRA_OpenHandle(int a0);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void ARC_TOOL_DeleteHandle(void *);
void *ZUKAN_INFO_CreateFromMon(u16 heap,void *mon,unsigned a2,unsigned a3,unsigned a4,unsigned a5,u8 a6,unsigned a7,unsigned a8,unsigned a9,unsigned a10,unsigned a11,unsigned a12);
void *ZUKAN_INFO_Create(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16);
void ZUKAN_INFO_Delete(char *p);
void ZUKAN_INFO_Update(char *p);
void ZUKAN_INFO_ClearDisplay(char *p);
void ZUKAN_INFO_ClearActors(char *p);
void ZUKAN_INFO_NotifyMoveDone(char *p);
void ZUKAN_INFO_NotifyFadeDone(char *p);
int ZUKAN_INFO_IsMoving(char *p);
int ZUKAN_INFO_IsDone(char *p);
void ZUKAN_INFO_Start(char *p);
void ZUKAN_INFO_SetPokemon(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6);
void ZUKAN_INFO_ShowPage(char *p,int mode);
void ZUKAN_INFO_SetPokemonPage(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);
void ZUKAN_INFO_Show(struct ZukanInfo *p);
void ZUKAN_INFO_Hide(struct ZukanInfo *p);
void ZUKAN_INFO_Task(int unused, char *p);
void ZUKAN_INFO_CreateWindows(char *p);
void ZUKAN_INFO_DeleteWindows(char *p);
void ZUKAN_INFO_DrawText(int heap,int window,void *printer,int font,int input,unsigned short right,unsigned short y,unsigned short color,int alignment,int expansion);
void ZUKAN_INFO_DrawMessage(int heap,int window,struct MsgBank *bank,void *printer,int font,int message,unsigned short x,unsigned short y,unsigned short color,int alignment,int expansion);
void ZUKAN_INFO_DrawMainPage(char *p);
void ZUKAN_INFO_DrawPage(char *p, int idx);
void ZUKAN_INFO_ClearSlotWindows(char *p);
void ZUKAN_INFO_FlushSlotWindows(char *p);
void ZUKAN_INFO_CreateBgBmp(struct ZukanInfo *e);
void ZUKAN_INFO_DeleteMainWindows(char *p);
void ZUKAN_INFO_FlushMainWindow(void *obj);
void ZUKAN_INFO_SetActors(void *a0, void *a1, void *a2, void *a3);
void ZUKAN_INFO_ReleaseActor(char *p, int i);
void ZUKAN_INFO_RegisterGfx(char *p,int index);
void ZUKAN_INFO_ReleaseGfx(char *p, int i);
void ZUKAN_INFO_CreateActor(char *p,int x,int y,int index);
void ZUKAN_INFO_DeleteActor(char *p, int i);
void ZUKAN_INFO_DisableActors(char *p);
void ZUKAN_INFO_CreateIconActors(struct ZukanInfo *p);
void ZUKAN_INFO_DeleteIconActors(char *p);
void ZUKAN_INFO_ShowFormPair(char *p,int mode,int which);
void ZUKAN_INFO_LayoutFormPair(struct ZukanInfo *p, unsigned x, unsigned y, int row);
void ZUKAN_INFO_LayoutFormPairEx(struct ZukanInfo *p, unsigned x, unsigned y, int z, int row);
void ZUKAN_INFO_DeleteRow(char *p, int index);
void ZUKAN_INFO_DisableOtherRows(struct ZukanInfo *p);
void ZUKAN_INFO_InitFormGfx(struct ZukanInfo *p);
void ZUKAN_INFO_DeleteFormGfx(char *p);
void ZUKAN_INFO_CreateSpeciesActor(struct ZukanInfo *p, u32 a, u32 b, u32 idx);
void ZUKAN_INFO_DeleteActorPair(struct ZukanInfo *p, int i);
void ZUKAN_INFO_DisableUnselected(struct ZukanInfo *p);
void ZUKAN_INFO_RefreshDisplay(struct ZukanInfo *p);
void ZUKAN_INFO_RefreshPage(struct ZukanInfo *p, int v);
s32 ZUKAN_INFO_BlendPalette(struct ZukanInfo *p);
void ZUKAN_INFO_SetDrawEnable(struct ZukanInfo *p, int v);
void ZUKAN_INFO_SetSlotDrawEnable(struct ZukanInfo *p, int v);
void ZUKAN_INFO_LoadResources(struct ZukanInfo *p);
void ZUKAN_INFO_FreeResources(struct ZukanInfo *p);
u32 ZUKAN_INFO_GetTypeArchiveId(void);
int ZUKAN_INFO_GetSpeciesCellFileId(int v);
int ZUKAN_INFO_GetPaletteFileId(int a0);
int ZUKAN_INFO_GetCellAnimFileId(int v);
int ZUKAN_INFO_GetCellAnimMode(int v);
u32 ZUKAN_INFO_GetIconArchiveId(void);
u32 ZUKAN_INFO_GetFormFlag(u32 a, u32 b);
extern const char d_021BC220[];
extern const struct Tab16 d_021BC174;
extern void *gSpeciesNameBank;
extern const unsigned short d_021BC110[];
extern const unsigned short d_021BC11C[];
extern const unsigned short d_021BC128[];
extern const Tile d_021BC150[];
extern s16 FX_SinCosTable_[];
extern u32 tbl_021BC134[];
extern u16 tbl_021BC1C4[];
extern u32 tbl_021BC184[];




void *ZUKAN_INFO_CreateFromMon(u16 heap,void *mon,unsigned a2,unsigned a3,unsigned a4,unsigned a5,u8 a6,unsigned a7,unsigned a8,unsigned a9,unsigned a10,unsigned a11,unsigned a12)
{
    u16 species,form,move;
    u8 gender;
    species=(u16)POKE_TOOL_GetPartyValue(mon,5,0);
    form=(u16)POKE_TOOL_GetPartyValue(mon,111,0);
    gender=POKE_TOOL_GetGender(mon);
    move=(u16)POKE_TOOL_IsShiny(mon);
    return ZUKAN_INFO_Create(heap,species,form,gender,move,POKE_TOOL_GetPartyValue(mon,0,0),a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12);
}







static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000040 = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    *(volatile u16 *)0x04000044 = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}







static inline void G2_SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x04000048 & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x04000048 = (u16)tmp;
}







static inline void G2_SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}







/*
 * note: a3 is u16 here (u16 field, strh); the matched caller ZUKAN_INFO_CreateFromMon declares it unsigned.
 */
void *ZUKAN_INFO_Create(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9,
                    u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16)
{
    char *p;
    void *h;
    void *buf;
    void *res;
    char *data;
    u8 i;
    u8 k;
    int x;
    int y;
    u32 hh;

    p = GFL_HEAP_Alloc(heap, 0x2b4, 0, d_021BC220, 0x42f);
    MI_CpuFill8(p, 0, 0x2b4);
    ((struct ZukanInfo *)p)->heap = heap;
    ((struct ZukanInfo *)p)->species = a1;
    ((struct ZukanInfo *)p)->form = a2;
    ((struct ZukanInfo *)p)->gender = a3;
    ((struct ZukanInfo *)p)->move = a4;
    ((struct ZukanInfo *)p)->personalParam = a5;
    ((struct ZukanInfo *)p)->formTableNeeded = a6;
    ((struct ZukanInfo *)p)->showCurrent = a7;
    ((struct ZukanInfo *)p)->mode = a8;
    ((struct ZukanInfo *)p)->femaleFlag = a9;
    ((struct ZukanInfo *)p)->bgLayerBase = a10;
    ((struct ZukanInfo *)p)->clactUnit = a11;
    ((struct ZukanInfo *)p)->font = a12;
    ((struct ZukanInfo *)p)->printQue = (void *)PRINTSYS_QUE_Create((void *)(((struct ZukanInfo *)p)->heap));
    *(u32 *)&((struct ZukanInfo *)p)->g[0] = a14;
    *(u32 *)&((struct ZukanInfo *)p)->g[1] = a15;
    *(u32 *)&((struct ZukanInfo *)p)->g[2] = a16;
    if (((struct ZukanInfo *)p)->femaleFlag == 0) {
        ((struct ZukanInfo *)p)->bgConfig = 0;
        ((struct ZukanInfo *)p)->layerMain = 3;
        ((struct ZukanInfo *)p)->layerUpper = 2;
        ((struct ZukanInfo *)p)->layerLower = 0;
    } else {
        ((struct ZukanInfo *)p)->bgConfig = 4;
        ((struct ZukanInfo *)p)->layerMain = 7;
        ((struct ZukanInfo *)p)->layerUpper = 6;
        ((struct ZukanInfo *)p)->layerLower = 4;
    }
    BG_SYS_SetVisibleLayer(((struct ZukanInfo *)p)->layerMain, ((struct ZukanInfo *)p)->bgLayerBase);
    BG_SYS_SetVisibleLayer(((struct ZukanInfo *)p)->layerUpper, (u8)(((struct ZukanInfo *)p)->bgLayerBase + 1));
    BG_SYS_SetVisibleLayer(((struct ZukanInfo *)p)->layerLower, (u8)(((struct ZukanInfo *)p)->bgLayerBase + 2));
    ((struct ZukanInfo *)p)->tileDirty = 0;
    ((struct ZukanInfo *)p)->reloadFlag = 0;
    switch (((struct ZukanInfo *)p)->mode) {
    case 0:
        ((struct ZukanInfo *)p)->animState = 0;
        break;
    case 1:
        ((struct ZukanInfo *)p)->animState = 5;
        break;
    case 2:
        ((struct ZukanInfo *)p)->animState = 7;
        break;
    }
    ((struct ZukanInfo *)p)->animParam58 = 0;
    ((struct ZukanInfo *)p)->animParam5C = 0;
    ((struct ZukanInfo *)p)->animTimer = 0;
    ((struct ZukanInfo *)p)->blinkTimer = 0;
    ((struct ZukanInfo *)p)->bgOffset = 0;
    if (((struct ZukanInfo *)p)->mode == 2 && ((struct ZukanInfo *)p)->femaleFlag == 0) {
        ((struct ZukanInfo *)p)->yOffset = -0x18;
    } else {
        ((struct ZukanInfo *)p)->yOffset = 0;
    }
    ZUKAN_INFO_LoadResources((struct ZukanInfo *)p);
    hh = (u16)POKE_PERSONAL_GetParam(((struct ZukanInfo *)p)->x, 0x20);
    if (((struct ZukanInfo *)p)->form >= hh) ((struct ZukanInfo *)p)->form = 0;
    h = ((struct ZukanInfo *)p)->w[0];
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 9, ((struct ZukanInfo *)p)->bgConfig, 0, 0x60, ((struct ZukanInfo *)p)->heap);
    ((struct ZukanInfo *)p)->charHandle = ARC_UTIL_RegisterObjCharFromHandle(h, 0x19, ((struct ZukanInfo *)p)->layerUpper, 0x1000, 0, ((struct ZukanInfo *)p)->heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x28, ((struct ZukanInfo *)p)->layerUpper, (u16)((struct ZukanInfo *)p)->charHandle, 0x800, 0, ((struct ZukanInfo *)p)->heap);
    ((struct ZukanInfo *)p)->charHandle2 = ARC_UTIL_RegisterObjCharFromHandle(h, 0x19, ((struct ZukanInfo *)p)->layerLower, 0x1000, 0, ((struct ZukanInfo *)p)->heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x1f, ((struct ZukanInfo *)p)->layerLower, (u16)((struct ZukanInfo *)p)->charHandle2, 0x800, 0, ((struct ZukanInfo *)p)->heap);
    ((struct ZukanInfo *)p)->gfxSlot = 0;
    ((struct ZukanInfo *)p)->hidden = 0;
    if (((struct ZukanInfo *)p)->mode == 2 && ((struct ZukanInfo *)p)->femaleFlag == 1) {
        BG_SYS_SetTileEntry(((struct ZukanInfo *)p)->layerUpper, 0, 0, 0, 0x20, 3, 0x11);
        h = ((struct ZukanInfo *)p)->w[0];
        ARC_UTIL_UploadPaletteFromHandle(h, 2, ((struct ZukanInfo *)p)->bgConfig, 0, 0x80, 0x40, ((struct ZukanInfo *)p)->heap);
        ((struct ZukanInfo *)p)->cellHandle = ARC_UTIL_RegisterObjCharFromHandle(h, 0xc, ((struct ZukanInfo *)p)->layerLower, 0x2000, 0, ((struct ZukanInfo *)p)->heap);
        ((struct ZukanInfo *)p)->gfxSlot = 1;
        ARC_UTIL_UploadBgPaletteAddFromHandle(h, 0x24, ((struct ZukanInfo *)p)->layerLower, 0x400, (u16)((struct ZukanInfo *)p)->cellHandle, 0x800, 0, ((struct ZukanInfo *)p)->heap);
        BG_SYS_FillTileMap(((struct ZukanInfo *)p)->layerLower, 0, 0x20, 0x20, 0x15, 4);
        BG_SYS_FillTileMap(((struct ZukanInfo *)p)->layerLower, 0, 0x35, 0x20, 3, 5);
    }
    h = ((struct ZukanInfo *)p)->w[0];
    buf = GFL_HEAP_Alloc(((struct ZukanInfo *)p)->heap, ARC_TOOL_GetHandleMemberSize(h, 9), 0, d_021BC220, 0x4f7);
    ARC_TOOL_ReadHandleMember(h, 9, buf);
    NNS_G2dGetUnpackedPaletteData(buf, &res);
    data = *(char * *)&((struct UnpackedPalette *)res)->palette;
    for (i = 0; i < 5; i++) {
        ((struct ZukanInfo *)p)->palA[i] = *(u16 *)(data + i * 2 + 0x22);
        ((struct ZukanInfo *)p)->palB[i] = *(u16 *)(data + i * 2 + 0x42);
    }
    GFL_HEAP_Free(buf);
    ZUKAN_INFO_CreateBgBmp((struct ZukanInfo *)p);
    ZUKAN_INFO_FlushMainWindow(p);
    ((struct ZukanInfo *)p)->task = GFL_USE_AddMainTask(ZUKAN_INFO_Task, p, 1);
    ZUKAN_INFO_CreateIconActors((struct ZukanInfo *)p);
    ZUKAN_INFO_InitFormGfx((struct ZukanInfo *)p);
    if (((struct ZukanInfo *)p)->mode == 0 || ((struct ZukanInfo *)p)->mode == 2) {
        ZUKAN_INFO_CreateWindows(p);
        ZUKAN_INFO_RefreshDisplay((struct ZukanInfo *)p);
    }
    for (k = 0; k < 2; k++) {
        ((struct ZukanInfo *)p)->actors[k] = 0;
    }
    ((struct ZukanInfo *)p)->selected = 0;
    switch (((struct ZukanInfo *)p)->mode) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    ZUKAN_INFO_SetActors(p, (void *)x, (void *)((u16)(y + ((struct ZukanInfo *)p)->yOffset)), (void *)(((struct ZukanInfo *)p)->selected));
    if (((struct ZukanInfo *)p)->mode == 0) {
        ((struct ZukanInfo *)p)->windowBottom = 0x88;
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x2000;
        G2_SetWnd0Position(0, 8, 100, ((struct ZukanInfo *)p)->windowBottom);
        G2_SetWnd0InsidePlane(0x1f, 1);
        G2_SetWndOutsidePlane(0x1f, 0);
        G2x_SetBlendBrightness_((u32)((volatile u16 *)0x04000050), 0x10, -0x10);
    }
    BG_SYS_FillScrollArea(((struct ZukanInfo *)p)->layerUpper, 3, -((struct ZukanInfo *)p)->yOffset);
    BG_SYS_FillScrollArea(((struct ZukanInfo *)p)->layerLower, 3, -((struct ZukanInfo *)p)->yOffset);
    BG_SYS_FillScrollArea(((struct ZukanInfo *)p)->layerMain, 3, -((struct ZukanInfo *)p)->yOffset);
    BG_SYS_PushTile(((struct ZukanInfo *)p)->layerUpper);
    BG_SYS_PushTile(((struct ZukanInfo *)p)->layerLower);
    return p;
}







void ZUKAN_INFO_Delete(char *p)
{
    u8 i;
    ZUKAN_INFO_Hide((struct ZukanInfo *)p);
    ((struct ZukanInfo *)p)->hidden=0;
    for(i=0;i<2;i++) ZUKAN_INFO_ReleaseActor(p,i);
    if(((struct ZukanInfo *)p)->mode==2) ZUKAN_INFO_ClearDisplay(p);
    ZUKAN_INFO_DeleteFormGfx(p);
    ZUKAN_INFO_DeleteIconActors(p);
    TCB_DeleteTask(((struct ZukanInfo *)p)->task);
    ZUKAN_INFO_DeleteMainWindows(p);
    if(((struct ZukanInfo *)p)->gfxSlot!=0) {
        BG_SYS_DeleteHalf(((struct ZukanInfo *)p)->layerLower,(u16)((struct ZukanInfo *)p)->cellHandle,(u16)(((struct ZukanInfo *)p)->cellHandle>>16));
        ((struct ZukanInfo *)p)->gfxSlot=0;
    }
    BG_SYS_DeleteHalf(((struct ZukanInfo *)p)->layerLower,(u16)((struct ZukanInfo *)p)->charHandle2,(u16)(((struct ZukanInfo *)p)->charHandle2>>16));
    BG_SYS_DeleteHalf(((struct ZukanInfo *)p)->layerUpper,(u16)((struct ZukanInfo *)p)->charHandle,(u16)(((struct ZukanInfo *)p)->charHandle>>16));
    ZUKAN_INFO_FreeResources((struct ZukanInfo *)p);
    PRINTSYS_QUE_Clear(((struct ZukanInfo *)p)->printQue);
    PRINTSYS_QUE_Delete(((struct ZukanInfo *)p)->printQue);
    GFL_HEAP_Free(p);
}







void ZUKAN_INFO_Update(char *p)
{
    if (((struct ZukanInfo *)p)->mode == 0) ZUKAN_INFO_BlendPalette((struct ZukanInfo *)p);
    ((struct ZukanInfo *)p)->blinkTimer += 1;
    if (((struct ZukanInfo *)p)->blinkTimer == 4) {
        ((struct ZukanInfo *)p)->reloadFlag |= 1;
        ((struct ZukanInfo *)p)->blinkTimer = 0;
    }
    switch (((struct ZukanInfo *)p)->animState) {
    case 0: case 6: case 7: break;
    case 1:
        ((struct ZukanInfo *)p)->animTimer += 1;
        if (((struct ZukanInfo *)p)->animTimer == 15) ((struct ZukanInfo *)p)->animState = 2;
        break;
    case 2: {
        int v = ((struct ZukanInfo *)p)->windowBottom - 1;
        ((struct ZukanInfo *)p)->windowBottom = v;
        *(volatile u16 *)0x04000040 = 100;
        *(volatile u16 *)0x04000044 = (u16)(((8 << 8) & 0xFF00) | (v & 0xFF));
        if (((struct ZukanInfo *)p)->windowBottom == 16) {
            *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
            G2x_SetBlendBrightness_((u32)((volatile u16 *)0x04000050), 0x10, 0);
            PM_VOICE_Play(((struct ZukanInfo *)p)->species, ((struct ZukanInfo *)p)->form, 0x40, 0, 0, 0, 0, 0);
            ((struct ZukanInfo *)p)->animState = 3;
        }
        break;
    }
    case 3:
        if (((struct ZukanInfo *)p)->animParam58 != 0) ((struct ZukanInfo *)p)->animState = 4;
        break;
    case 4: {
        struct Pt pt;
        int fx = 0;
        int fy = 0;
        void *obj = ((struct ZukanInfo *)p)->actors[((struct ZukanInfo *)p)->selected];
        CLACT_GetActorPos(obj, &pt);
        pt.x += 1;
        pt.y += 1;
        if (pt.x > 0x80) { pt.x = 0x80; fx = 1; }
        if (pt.y > 0x48) { pt.y = 0x48; fy = 1; }
        CLACT_SetActorPos(((struct ZukanInfo *)p)->actors[((struct ZukanInfo *)p)->selected], &pt);
        if (fx && fy) ((struct ZukanInfo *)p)->animState = 6;
        break;
    }
    case 5:
        if (((struct ZukanInfo *)p)->animParam5C != 0) {
            PM_VOICE_Play(((struct ZukanInfo *)p)->species, ((struct ZukanInfo *)p)->form, 0x40, 0, 0, 0, 0, 0);
            ((struct ZukanInfo *)p)->animState = 6;
        }
        break;
    }
    if (((struct ZukanInfo *)p)->mode == 0 || ((struct ZukanInfo *)p)->mode == 2) ZUKAN_INFO_FlushSlotWindows(p);
    PRINTSYS_QUE_Main(((struct ZukanInfo *)p)->printQue);
}







void ZUKAN_INFO_ClearDisplay(char *p)
{
    ZUKAN_INFO_ClearSlotWindows(p);
    ZUKAN_INFO_DeleteWindows(p);
    ZUKAN_INFO_DeleteActorPair((struct ZukanInfo *)p, ((struct ZukanInfo *)p)->flag190);
    ZUKAN_INFO_DeleteRow(p,((struct ZukanInfo *)p)->iconEnabled);
}







void ZUKAN_INFO_ClearActors(char *p)
{
    ZUKAN_INFO_ClearSlotWindows(p);
    ZUKAN_INFO_DeleteActorPair((struct ZukanInfo *)p, ((struct ZukanInfo *)p)->flag190);
    ZUKAN_INFO_DeleteRow(p,((struct ZukanInfo *)p)->iconEnabled);
}







void ZUKAN_INFO_NotifyMoveDone(char *p)
{
    ((struct ZukanInfo *)p)->animParam58=1;
}







void ZUKAN_INFO_NotifyFadeDone(char *p)
{
    ((struct ZukanInfo *)p)->animParam5C=1;
}







int ZUKAN_INFO_IsMoving(char *p)
{
    int result=0;
    if(((struct ZukanInfo *)p)->animState==4) result=1;
    return result;
}







int ZUKAN_INFO_IsDone(char *p)
{
    int result=0;
    if(((struct ZukanInfo *)p)->animState==6) result=1;
    return result;
}







void ZUKAN_INFO_Start(char *p)
{
    if(((struct ZukanInfo *)p)->animState==0) ((struct ZukanInfo *)p)->animState=1;
}






void ZUKAN_INFO_SetPokemon(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6)
{
    int x;
    u32 h;
    int y;
    if (((struct ZukanInfo *)p)->x != 0) POKE_PERSONAL_Delete(((struct ZukanInfo *)p)->x);
    ((struct ZukanInfo *)p)->x = POKE_PERSONAL_Create(a1, a2, ((struct ZukanInfo *)p)->heap);
    if (((struct ZukanInfo *)p)->selected != 0) ((struct ZukanInfo *)p)->selected = 0; else ((struct ZukanInfo *)p)->selected = 1;
    if (((struct ZukanInfo *)p)->iconEnabled != 0) ((struct ZukanInfo *)p)->iconEnabled = 0; else ((struct ZukanInfo *)p)->iconEnabled = 1;
    if (((struct ZukanInfo *)p)->flag190 != 0) ((struct ZukanInfo *)p)->flag190 = 0; else ((struct ZukanInfo *)p)->flag190 = 1;
    ZUKAN_INFO_ReleaseActor(p, ((struct ZukanInfo *)p)->selected);
    ZUKAN_INFO_ClearActors(p);
    ((struct ZukanInfo *)p)->species = a1;
    ((struct ZukanInfo *)p)->form = a2;
    ((struct ZukanInfo *)p)->gender = a3;
    ((struct ZukanInfo *)p)->move = a4;
    ((struct ZukanInfo *)p)->personalParam = a5;
    ((struct ZukanInfo *)p)->showCurrent = a6;
    h = (u16)POKE_PERSONAL_GetParam(((struct ZukanInfo *)p)->x, 0x20);
    if (((struct ZukanInfo *)p)->form >= h) ((struct ZukanInfo *)p)->form = 0;
    ZUKAN_INFO_FlushMainWindow(p);
    ZUKAN_INFO_RefreshDisplay((struct ZukanInfo *)p);
    switch (((struct ZukanInfo *)p)->mode) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    ZUKAN_INFO_SetActors(p, (void *)x, (void *)((u16)(y + ((struct ZukanInfo *)p)->yOffset)), (void *)(((struct ZukanInfo *)p)->selected));
    ZUKAN_INFO_SetSlotDrawEnable((struct ZukanInfo *)p, (((struct ZukanInfo *)p)->hidden != 0) ? 0 : 1);
}






void ZUKAN_INFO_ShowPage(char *p,int mode)
{
    if (((struct ZukanInfo *)p)->iconEnabled) ((struct ZukanInfo *)p)->iconEnabled=0;
    else ((struct ZukanInfo *)p)->iconEnabled=1;
    ZUKAN_INFO_ClearSlotWindows(p);
    ZUKAN_INFO_DeleteRow(p,((struct ZukanInfo *)p)->iconEnabled);
    ZUKAN_INFO_ShowFormPair(p,mode,((struct ZukanInfo *)p)->iconEnabled);
    ZUKAN_INFO_SetDrawEnable((struct ZukanInfo *)p,((struct ZukanInfo *)p)->showCurrent);
    if(mode==6 || ((struct ZukanInfo *)p)->species>493) ZUKAN_INFO_DrawMainPage(p);
    else ZUKAN_INFO_DrawPage(p,mode);
}






void ZUKAN_INFO_SetPokemonPage(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7)
{
    int x;
    u32 h;
    int y;
    if (((struct ZukanInfo *)p)->x != 0) POKE_PERSONAL_Delete(((struct ZukanInfo *)p)->x);
    ((struct ZukanInfo *)p)->x = POKE_PERSONAL_Create(a1, a2, ((struct ZukanInfo *)p)->heap);
    if (((struct ZukanInfo *)p)->selected != 0) ((struct ZukanInfo *)p)->selected = 0; else ((struct ZukanInfo *)p)->selected = 1;
    if (((struct ZukanInfo *)p)->iconEnabled != 0) ((struct ZukanInfo *)p)->iconEnabled = 0; else ((struct ZukanInfo *)p)->iconEnabled = 1;
    if (((struct ZukanInfo *)p)->flag190 != 0) ((struct ZukanInfo *)p)->flag190 = 0; else ((struct ZukanInfo *)p)->flag190 = 1;
    ZUKAN_INFO_ReleaseActor(p, ((struct ZukanInfo *)p)->selected);
    ZUKAN_INFO_ClearActors(p);
    ((struct ZukanInfo *)p)->species = a1;
    ((struct ZukanInfo *)p)->form = a2;
    ((struct ZukanInfo *)p)->gender = a3;
    ((struct ZukanInfo *)p)->move = a4;
    ((struct ZukanInfo *)p)->personalParam = a5;
    ((struct ZukanInfo *)p)->showCurrent = a6;
    h = (u16)POKE_PERSONAL_GetParam(((struct ZukanInfo *)p)->x, 0x20);
    if (((struct ZukanInfo *)p)->form >= h) ((struct ZukanInfo *)p)->form = 0;
    ZUKAN_INFO_FlushMainWindow(p);
    if (a7 == 6 || ((struct ZukanInfo *)p)->species > 0x1ed) ZUKAN_INFO_RefreshDisplay((struct ZukanInfo *)p);
    else ZUKAN_INFO_RefreshPage((struct ZukanInfo *)p, a7);
    switch (((struct ZukanInfo *)p)->mode) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    ZUKAN_INFO_SetActors(p, (void *)x, (void *)((u16)(y + ((struct ZukanInfo *)p)->yOffset)), (void *)(((struct ZukanInfo *)p)->selected));
    ZUKAN_INFO_SetSlotDrawEnable((struct ZukanInfo *)p, (((struct ZukanInfo *)p)->hidden != 0) ? 0 : 1);
}






void ZUKAN_INFO_Show(struct ZukanInfo *p)
{
    if (!p->hidden) {
        p->hidden = 1;
        BG_SYS_SetPlaneVisible(p->layerMain, 0);
        BG_SYS_SetPlaneVisible(p->layerUpper, 0);
        BG_SYS_ResetSlot(p->layerLower, 3, -256);
        ZUKAN_INFO_SetSlotDrawEnable((struct ZukanInfo *)p, p->hidden == 0);
    }
}






void ZUKAN_INFO_Hide(struct ZukanInfo *p)
{
    if (p->hidden) {
        p->hidden = 0;
        BG_SYS_SetPlaneVisible(p->layerMain, 1);
        BG_SYS_SetPlaneVisible(p->layerUpper, 1);
        BG_SYS_ResetSlot(p->layerLower, 3, -p->yOffset);
        ZUKAN_INFO_SetSlotDrawEnable((struct ZukanInfo *)p, p->hidden == 0);
    }
}







void ZUKAN_INFO_Task(int unused, char *p)
{
    if (((struct ZukanInfo *)p)->reloadFlag & 1)
    {
        BG_SYS_ResetSlot(((struct ZukanInfo *)p)->layerLower, 1, 1);
    }
    ((struct ZukanInfo *)p)->tileDirty = 0;
    ((struct ZukanInfo *)p)->reloadFlag = 0;
}






void ZUKAN_INFO_CreateWindows(char *p)
{
    struct Tab16 tab;
    int out;
    int r6;
    int i;
    ((struct ZukanInfo *)p)->speciesTable = ARC_UTIL_LoadHandleMemberWithSize(((struct ZukanInfo *)p)->w[1], 0, 0, ((struct ZukanInfo *)p)->heap, (u32 *)(&out));
    r6 = 0;
    if (*(int *)&((struct ZukanInfo *)p)->femaleFlag != 0) r6 = 4;
    ARC_UTIL_UploadPaletteFromHandleWhole(((struct ZukanInfo *)p)->w[2], 5, r6, 0x60, 0x20, ((struct ZukanInfo *)p)->heap);
    tab = d_021BC174;
    for (i = 0; i < 4; i++) {
        ((struct ZukanInfo *)p)->win[i] = (int)BMP_WIN_Create(((struct ZukanInfo *)p)->layerMain, tab.b[i*4], tab.b[i*4+1], tab.b[i*4+2], tab.b[i*4+3], 3, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct ZukanInfo *)p)->win[i])), 0);
    }
    for (i = 0; i < 4; i++) {
        ((struct ZukanInfo *)p)->slotDirty[i] = 1;
    }
}








void ZUKAN_INFO_DeleteWindows(char *p)
{
    int i;
    PRINTSYS_QUE_Clear(((struct ZukanInfo *)p)->printQue);
    for(i=0;i<4;i++){
        ((struct ZukanInfo *)p)->slotDirty[i]=1;
        BMP_WIN_Delete((struct Descriptor *)((struct ZukanInfo *)p)->win[i]);
    }
    GFL_HEAP_Free(((struct ZukanInfo *)p)->speciesTable);
}








void ZUKAN_INFO_DrawText(int heap,int window,void *printer,int font,int input,unsigned short right,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int buffer=(int)BMP_WIN_GetBmp((struct Descriptor *)window);
    unsigned short x;
    int text;
    if(expansion) {
        text=(int)STRBUF_Create(128,heap);
        WORDSET_CopyTaggedText((struct WordSet *)expansion,(void *)text,(void *)input);
    } else text=input;
    switch(alignment) {
    case 0: x=right; break;
    case 1: {
        unsigned short width=GF_FONT_MeasureWidestLine((struct StrObj *)text,font,0);
        x=right-width;
        break;
    }
    case 2: {
        unsigned short width=GF_FONT_MeasureWidestLine((struct StrObj *)text,font,0);
        x=(BMP_GetWidth((const struct Bmp *)buffer)-width)/2;
        break;
    }
    }
    PRINTSYS_PrintQueColor(printer,(int)buffer,(short)x,(short)y,(int)text,(int)font,color);
    if(expansion) STRBUF_Delete((struct U16Vec *)text);
}








void ZUKAN_INFO_DrawMessage(int heap,int window,struct MsgBank *bank,void *printer,int font,int message,unsigned short x,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int text=(int)MSGDATA_AllocString(bank,message);
    ZUKAN_INFO_DrawText(heap,window,printer,font,text,x,y,color,alignment,expansion);
    STRBUF_Delete((struct U16Vec *)text);
}








/*
 * note: objs[0] is read first into a local, so its offset is the first constant built and the
 *   objs[1..4] and speciesTable accesses derive from it. The last loop stores the constant 0 (a copy of k's 0).
 */
void ZUKAN_INFO_DrawMainPage(char *p)
{
    int l2c = (int)((struct ZukanInfo *)p)->objs[0];
    int l28 = (int)((struct ZukanInfo *)p)->objs[1];
    int l24 = (int)((struct ZukanInfo *)p)->objs[2];
    int l20 = (int)((struct ZukanInfo *)p)->objs[3];
    int l1c = (int)((struct ZukanInfo *)p)->objs[4];
    u16 t = ((struct ZukanInfo *)p)->species;
    u16 i = 0;
    u32 h2;
    u16 r7;
    u16 r6;
    u16 m;
    void *name;
    u8 k;
    if (((struct ZukanInfo *)p)->form != 0) {
        u16 *arr = *(u16 * *)&((struct ZukanInfo *)p)->speciesTable;
        do {
            t = arr[t];
            if (t == 0) break;
            i = (u16)(i + 1);
        } while (i != ((struct ZukanInfo *)p)->form);
    }
    if (t == 0) t = ((struct ZukanInfo *)p)->species;
    if (((struct ZukanInfo *)p)->mode != 2) {
        ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[0], (struct MsgBank *)l2c, (void *)(((struct ZukanInfo *)p)->printQue), ((struct ZukanInfo *)p)->font, 0x90, 0, 5, 0x3c40, 2, 0);
    }
    r7 = ((struct ZukanInfo *)p)->species;
    if (((struct ZukanInfo *)p)->formTableNeeded == 0) {
        u16 *tab = POKE_PERSONAL_LoadFormTable(((struct ZukanInfo *)p)->heap, 0);
        r7 = tab[((struct ZukanInfo *)p)->species];
        GFL_HEAP_Free(tab);
    }
    if (r7 != 0x3e7) {
        h2 = (u32)WORDSET_CreateDefault(((struct ZukanInfo *)p)->heap);
        WORDSET_SetSlotNumber((struct WordSet *)h2, 0, r7, 3, 2, 1);
        ZUKAN_INFO_DrawText(((struct ZukanInfo *)p)->heap, *(int *)&((struct ZukanInfo *)p)->win[1], (void *)(((struct ZukanInfo *)p)->printQue), ((struct ZukanInfo *)p)->font, ((struct ZukanInfo *)p)->text.input[0], 8, 5, 0x3e7 + 0x59, 0, h2);
        WORDSET_DeleteStrbufED04((struct WordSet *)h2);
    } else {
        ZUKAN_INFO_DrawText(((struct ZukanInfo *)p)->heap, *(int *)&((struct ZukanInfo *)p)->win[1], (void *)(((struct ZukanInfo *)p)->printQue), ((struct ZukanInfo *)p)->font, ((struct ZukanInfo *)p)->text.input[1], 8, 5, 0x3e7 + 0x59, 0, 0);
    }
    name = MSGDATA_AllocString(gSpeciesNameBank, ((struct ZukanInfo *)p)->species);
    PRINTSYS_PrintQueColor((void *)(((struct ZukanInfo *)p)->printQue), (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct ZukanInfo *)p)->win[1]), 0x30, 5, (u32)name, ((struct ZukanInfo *)p)->font, 0x440);
    STRBUF_Delete(name);
    m = 0;
    if (((struct ZukanInfo *)p)->showCurrent != 0) m = ((struct ZukanInfo *)p)->species;
    ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, *(int *)&((struct ZukanInfo *)p)->win[1], (struct MsgBank *)l28, (void *)(((struct ZukanInfo *)p)->printQue), ((struct ZukanInfo *)p)->font, m, 0, 0x16, 0x440, 2, 0);
    ZUKAN_INFO_DrawText(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[2], (void *)(((struct ZukanInfo *)p)->printQue), ((struct ZukanInfo *)p)->font, ((struct ZukanInfo *)p)->text.input[2], 0, 4, 0x440, 0, 0);
    ZUKAN_INFO_DrawText(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[2], (void *)(((struct ZukanInfo *)p)->printQue), ((struct ZukanInfo *)p)->font, ((struct ZukanInfo *)p)->text.input[3], 0, 0x14, 0x440, 0, 0);
    r6 = 0;
    if (((struct ZukanInfo *)p)->showCurrent != 0) r6 = t;
    ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[2], (struct MsgBank *)l24, (void *)(((struct ZukanInfo *)p)->printQue), ((struct ZukanInfo *)p)->font, r6, 0x65, 4, 0x440, 1, 0);
    r6 = 0;
    if (((struct ZukanInfo *)p)->showCurrent != 0) r6 = t;
    ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[2], (struct MsgBank *)l20, (void *)(((struct ZukanInfo *)p)->printQue), ((struct ZukanInfo *)p)->font, r6, 0x66, 0x14, 0x440, 1, 0);
    t = 0;
    if (((struct ZukanInfo *)p)->showCurrent != 0) t = ((struct ZukanInfo *)p)->species;
    ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[3], (struct MsgBank *)l1c, (void *)(((struct ZukanInfo *)p)->printQue), ((struct ZukanInfo *)p)->font, t, 4, 5, 0x3c40, 0, 0);
    for (k = 0; k < 4; k++) {
        ((struct ZukanInfo *)p)->slotDirty[k] = 0;
    }
    ZUKAN_INFO_FlushSlotWindows(p);
}









void ZUKAN_INFO_DrawPage(char *p, int idx)
{
    int t0 = (int)((struct ZukanInfo *)p)->objs[0];
    int a30 = (int)((struct ZukanInfo *)p)->objs[idx + 5];
    int a2c = (int)((struct ZukanInfo *)p)->objs[idx + 11];
    int a28 = (int)((struct ZukanInfo *)p)->objs[idx + 17];
    int a24 = (int)((struct ZukanInfo *)p)->objs[idx + 23];
    int a20 = (int)((struct ZukanInfo *)p)->objs[idx + 29];
    unsigned short cur = ((struct ZukanInfo *)p)->species;
    unsigned short c;
    int h;
    int fl;
    unsigned char i;

    if (cur == 0x1e7 && ((struct ZukanInfo *)p)->form != 0) {
        cur = 0x1ee;
    } else if (cur == 0x1ec && ((struct ZukanInfo *)p)->form != 0) {
        cur = 0x1ef;
    }
    if (((struct ZukanInfo *)p)->mode != 2) {
        ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[0], (struct MsgBank *)t0, (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, 0x90, 0, 5, 0x3c40, 2, 0);
    }
    c = ((struct ZukanInfo *)p)->species;
    if (((struct ZukanInfo *)p)->formTableNeeded == 0) {
        unsigned short *tab = POKE_PERSONAL_LoadFormTable(((struct ZukanInfo *)p)->heap, 0);
        c = tab[((struct ZukanInfo *)p)->species];
        GFL_HEAP_Free(tab);
    }
    if (c != 0x3e7) {
        h = (int)WORDSET_CreateDefault(((struct ZukanInfo *)p)->heap);
        if (idx == 0) {
            WORDSET_SetSlotNumber((struct WordSet *)h, 0, c, 3, 2, 0);
        } else {
            WORDSET_SetSlotNumber((struct WordSet *)h, 0, c, 3, 2, 1);
        }
        ZUKAN_INFO_DrawText(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[1], (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, ((struct ZukanInfo *)p)->text.input[0], 8, 5, 0x440, 0, h);
        WORDSET_DeleteStrbufED04((struct WordSet *)h);
    } else {
        ZUKAN_INFO_DrawText(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[1], (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, ((struct ZukanInfo *)p)->text.input[1], 8, 5, 0x440, 0, 0);
    }
    c = 0;
    ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[1], (struct MsgBank *)a20, (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, ((struct ZukanInfo *)p)->species, 0x30, 5, 0x440, 0, 0);
    if (((struct ZukanInfo *)p)->showCurrent != 0) c = ((struct ZukanInfo *)p)->species;
    ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[1], (struct MsgBank *)a30, (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, c, 0, 0x16, 0x440, 2, 0);
    ZUKAN_INFO_DrawText(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[2], (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, ((struct ZukanInfo *)p)->text.input[idx + 4], 0, 4, 0x440, 0, 0);
    ZUKAN_INFO_DrawText(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[2], (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, ((struct ZukanInfo *)p)->text.input[idx + 10], 0, 0x14, 0x440, 0, 0);
    c = 0;
    if (((struct ZukanInfo *)p)->showCurrent != 0) c = cur;
    ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[2], (struct MsgBank *)a2c, (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, c, d_021BC110[idx], 4, 0x440, 1, 0);
    c = 0;
    if (((struct ZukanInfo *)p)->showCurrent != 0) c = cur;
    ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[2], (struct MsgBank *)a28, (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, c, d_021BC11C[idx], 0x14, 0x440, 1, 0);
    c = 0;
    if (((struct ZukanInfo *)p)->showCurrent != 0) c = ((struct ZukanInfo *)p)->species;
    ZUKAN_INFO_DrawMessage(((struct ZukanInfo *)p)->heap, ((struct ZukanInfo *)p)->win[3], (struct MsgBank *)a24, (void *)((struct ZukanInfo *)p)->printQue, ((struct ZukanInfo *)p)->font, c, 4, 5, 0x3c40, 0, 0);
    for (i = 0; i < 4; i++) {
        ((struct ZukanInfo *)p)->slotDirty[i] = 0;
    }
    ZUKAN_INFO_FlushSlotWindows(p);
}








void ZUKAN_INFO_ClearSlotWindows(char *p)
{
    int i;
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct ZukanInfo *)p)->printQue));
    for (i = 0; i < 4; i++) {
        ((struct ZukanInfo *)p)->slotDirty[i] = 1;
        BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct ZukanInfo *)p)->win[i])), 0);
    }
}








void ZUKAN_INFO_FlushSlotWindows(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (((struct ZukanInfo *)p)->slotDirty[i] == 0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((struct ZukanInfo *)p)->printQue), (void *)BMP_WIN_GetBmp((struct Descriptor *)((struct ZukanInfo *)p)->win[i])) == 0) {
            int window = ((struct ZukanInfo *)p)->win[i];
            BMP_WIN_TransferChars((struct Descriptor *)window);
            BMP_WIN_MakeScreen((struct Cfg *)window);
            BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)window));
            ((struct ZukanInfo *)p)->slotDirty[i] = 1;
        }
    }
}









void ZUKAN_INFO_CreateBgBmp(struct ZukanInfo *e)
{
    Zero z = ZERO;
    int s = (int)BMP_CreateFromArchive(0x9f, 0x19, z, e->heap);
    int q;

    e->winMain = (void *)BMP_WIN_Create(e->layerUpper, 0xc, 4, 4, 3, z, z);
    q = (int)BMP_WIN_GetBmp((struct Descriptor *)e->winMain);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 8, 0, z, z, 0x20, 0x18, z);

    e->winAlt = (void *)BMP_WIN_Create(e->layerUpper, 0xc, 4, 4, 3, z, z);
    q = (int)BMP_WIN_GetBmp((struct Descriptor *)e->winAlt);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0xa8, 8, z, z, 0x20, 8, z);

    q = (int)BMP_WIN_GetBmp((struct Descriptor *)e->winAlt);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0xf8, 8, z, 8, 8, 8, z);

    q = (int)BMP_WIN_GetBmp((struct Descriptor *)e->winAlt);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0x28, 0x10, 8, 8, 0x18, 8, z);

    q = (int)BMP_WIN_GetBmp((struct Descriptor *)e->winAlt);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0x80, z, 0, 0x10, 8, 8, 0);

    q = (int)BMP_WIN_GetBmp((struct Descriptor *)e->winAlt);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)q, 0x58, 0x10, 8, 0x10, 0x18, 8, z);

    BMP_Delete((struct Bmp *)s);
}








void ZUKAN_INFO_DeleteMainWindows(char *p)
{
    BMP_WIN_Delete(((struct ZukanInfo *)p)->winMain);
    BMP_WIN_Delete(((struct ZukanInfo *)p)->winAlt);
}









void ZUKAN_INFO_FlushMainWindow(void *obj)
{
    void *p;

    if (((struct ZukanInfo *)obj)->showCurrent != 0) {
        p = ((struct ZukanInfo *)obj)->winMain;
        BMP_WIN_TransferChars((struct Descriptor *)p);
        BMP_WIN_MakeScreen((struct Cfg *)p);
        BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)p));
        return;
    }
    p = ((struct ZukanInfo *)obj)->winAlt;
    BMP_WIN_TransferChars((struct Descriptor *)p);
    BMP_WIN_MakeScreen((struct Cfg *)p);
    BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)p));
}









void ZUKAN_INFO_SetActors(void *a0, void *a1, void *a2, void *a3)
{
    ZUKAN_INFO_RegisterGfx(a0, (int)a3);
    ZUKAN_INFO_CreateActor(a0, (int)a1, (int)a2, (int)a3);
    ZUKAN_INFO_DisableActors(a0);
}








void ZUKAN_INFO_ReleaseActor(char *p, int i)
{
    void **slot = &((struct ZukanInfo *)p)->actors[i];
    if (*slot != 0) {
        ZUKAN_INFO_DeleteActor(p, i);
        ZUKAN_INFO_ReleaseGfx(p, i);
        *slot = 0;
    }
}








void ZUKAN_INFO_RegisterGfx(char *p,int index)
{
    int flag=0;
    int handle;
    if (((struct ZukanInfo *)p)->femaleFlag) flag=1;
    handle=(int)((struct ZukanInfo *)p)->w[4];
    ((struct ZukanInfo *)p)->charRes[index]=(void *)POKEGRA_RegisterCgr(handle,((struct ZukanInfo *)p)->species,((struct ZukanInfo *)p)->form,((struct ZukanInfo *)p)->gender,((struct ZukanInfo *)p)->move,0,0,((struct ZukanInfo *)p)->personalParam,flag,((struct ZukanInfo *)p)->heap);
    ((struct ZukanInfo *)p)->palRes[index]=(void *)POKEGRA_RegisterPalette(handle,((struct ZukanInfo *)p)->species,((struct ZukanInfo *)p)->form,((struct ZukanInfo *)p)->gender,((struct ZukanInfo *)p)->move,0,0,flag,index<<5,((struct ZukanInfo *)p)->heap);
    ((struct ZukanInfo *)p)->cellRes[index]=(void *)POKEGRA_RegisterCellAnim(((struct ZukanInfo *)p)->species,((struct ZukanInfo *)p)->form,((struct ZukanInfo *)p)->gender,((struct ZukanInfo *)p)->move,0,0,2,flag,((struct ZukanInfo *)p)->heap);
}








void ZUKAN_INFO_ReleaseGfx(char *p, int i)
{
    CLACT_ReleasePalette((u32)((struct ZukanInfo *)p)->palRes[i]);
    CLACT_ReleaseCharacter((u32)((struct ZukanInfo *)p)->charRes[i]);
    CLACT_ReleaseCellAnim((u32)((struct ZukanInfo *)p)->cellRes[i]);
}








void ZUKAN_INFO_CreateActor(char *p,int x,int y,int index)
{
    int flag=0;
    ActorCreatePos pos;
    if (((struct ZukanInfo *)p)->femaleFlag) flag=1;
    MI_CpuFill8(&pos,0,8);
    pos.x=x;
    pos.y=y;
    *(int *)(p+0xac+index*4)=(int)CLACT_CreateActor((void *)((struct ZukanInfo *)p)->clactUnit,(u32)((struct ZukanInfo *)p)->charRes[index],(u32)((struct ZukanInfo *)p)->palRes[index],(u32)((struct ZukanInfo *)p)->cellRes[index],&pos,flag,((struct ZukanInfo *)p)->heap);
    CLACT_SetActorDrawPriority((struct Node *)(*(int *)(p+0xac+index*4)),0);
    if(((struct ZukanInfo *)p)->mode==2) CLACT_SetActorObjMode((struct Actor *)(*(int *)(p+0xac+index*4)),1);
    if(POKE_PERSONAL_GetParam((const struct Personal *)(((struct ZukanInfo *)p)->x),34)==0) CLACT_SetActorFlip((struct Actor *)(*(int *)(p+0xac+index*4)),1,1);
}








void ZUKAN_INFO_DeleteActor(char *p, int i)
{
    CLACT_DeleteActor(((struct ZukanInfo *)p)->actors[i]);
}








void ZUKAN_INFO_DisableActors(char *p)
{
    unsigned char i;
    for (i = 0; i < 2; i++) {
        if (i != ((struct ZukanInfo *)p)->selected && ((struct ZukanInfo *)p)->actors[i] != 0) {
            CLACT_SetActorDrawEnable(((struct ZukanInfo *)p)->actors[i], 0);
        }
    }
}








void ZUKAN_INFO_CreateIconActors(struct ZukanInfo *p)
{
    unsigned char a, b, i;
    int flag;
    int sh;
    void *u;
    void *arc;
    ActorRect r;

    u = (void *)p->femaleFlag;
    flag = (int)u == 0 ? B_FALSE : B_TRUE;
    sh = 0;
    if (u != 0) sh = 1;
    arc = p->w[3];
    for (a = 0; a < 2; a++) {
        for (b = 0; b < 2; b++) {
            p->charIds[a][b] = -1;
        }
    }
    p->iconEnabled = 0;
    p->paletteHandle = (u32)CLACT_RegisterPaletteEx(arc, APP_ICON_GetTouchBarFileId(), flag, 0x40, 0, 3, p->heap);
    p->cellAnimHandle = (u32)CLACT_RegisterCellAnim(arc, APP_ICON_GetTypePaletteFileId(2), APP_ICON_GetTypeAnimFileId(2), p->heap);
    if (p->mode == 2 && p->femaleFlag == 0) {
        r.a = 0; r.b = 0; r.c = 0; r.d = 0; r.e = 0;
        p->iconVisible = 1;
        p->shownFormA = 0x11;
        p->shownFormB = 0x11;
        for (i = 0; i < 0x11; i++) {
            p->iconChars[i] = (void *)CLACT_RegisterCharacter(arc, APP_ICON_GetTypeCellFileId(i), 0, flag, p->heap);
            p->iconActors[i] = CLACT_CreateActor((void *)p->clactUnit, (unsigned int)p->iconChars[i], p->paletteHandle, p->cellAnimHandle, &r, sh, p->heap);
            CLACT_SetActorPaletteOffset(p->iconActors[i], APP_ICON_GetTypePaletteOffset(i), 1);
            CLACT_SetActorDrawPriority(p->iconActors[i], 2);
            CLACT_SetActorObjMode(p->iconActors[i], 1);
            CLACT_SetActorDrawEnable(p->iconActors[i], 0);
        }
    } else {
        p->iconVisible = 0;
    }
}







void ZUKAN_INFO_DeleteIconActors(char *p)
{
    unsigned char i;
    for(i=0;i<2;i++) ZUKAN_INFO_DeleteRow(p,i);
    if(((struct ZukanInfo *)p)->iconVisible) {
        for(i=0;i<17;i++) {
            CLACT_DeleteActor((struct Obj *)((struct ZukanInfo *)p)->iconActors[i]);
            CLACT_ReleaseCharacter((u32)((struct ZukanInfo *)p)->iconChars[i]);
        }
        ((struct ZukanInfo *)p)->iconVisible=0;
    }
    CLACT_ReleaseCellAnim(((struct ZukanInfo *)p)->cellAnimHandle);
    CLACT_ReleasePalette(((struct ZukanInfo *)p)->paletteHandle);
}





void ZUKAN_INFO_ShowFormPair(char *p,int mode,int which)
{
    void *mon=((struct ZukanInfo *)p)->x;
    unsigned char first=POKE_PERSONAL_GetParam((const struct Personal *)mon,6);
    unsigned char second=POKE_PERSONAL_GetParam((const struct Personal *)mon,7);
    if(first==second) second=17;
    if(mode==6) ZUKAN_INFO_LayoutFormPair((struct ZukanInfo *)p, first, second, which);
    else ZUKAN_INFO_LayoutFormPairEx((struct ZukanInfo *)p, first, second, mode, which);
    ZUKAN_INFO_DisableOtherRows((struct ZukanInfo *)p);
}





void ZUKAN_INFO_LayoutFormPair(struct ZukanInfo *p, unsigned x, unsigned y, int row)
{
    ShortRect4 rr[2];
    ActorSurfacePos pos[2];
    unsigned char sel[2];
    int ifv;
    int tern;
    short v;
    int j;
    void *arc;
    short *zp;

    if (p->iconVisible != 0) {
        ifv = 0;
        if (p->femaleFlag != 0) ifv = 1;
        pos[0].x = 0xa8;
        v = p->yOffset + 0x54;
        pos[0].y = v;
        pos[1].x = 0xd0;
        pos[1].y = v;
        if (p->shownFormA != 0x11) {
            if (p->shownFormA != x && p->shownFormA != y) {
                CLACT_SetActorDrawEnable(p->iconActors[p->shownFormA], 0);
                p->shownFormA = 0x11;
            } else {
                if (p->shownFormA == y) {
                    CLACT_AddActorSurfacePos(p->iconActors[p->shownFormA], (ActorSurfacePos *)(&pos[1]), ifv);
                }
                CLACT_SetActorDrawEnable(p->iconActors[p->shownFormA], 1);
            }
        }
        if (p->shownFormB != 0x11) {
            if (p->shownFormB != x && p->shownFormB != y) {
                CLACT_SetActorDrawEnable(p->iconActors[p->shownFormB], 0);
                p->shownFormB = 0x11;
            } else {
                if (p->shownFormB == x) {
                    CLACT_AddActorSurfacePos(p->iconActors[p->shownFormB], (ActorSurfacePos *)(&pos[0]), ifv);
                }
                CLACT_SetActorDrawEnable(p->iconActors[p->shownFormB], 1);
            }
        }
        if (x != 0x11) {
            p->shownFormA = x;
            CLACT_SetActorDrawEnable(p->iconActors[p->shownFormA], 1);
            CLACT_AddActorSurfacePos(p->iconActors[p->shownFormA], (ActorSurfacePos *)(&pos[0]), ifv);
        }
        if (y != 0x11) {
            p->shownFormB = y;
            CLACT_SetActorDrawEnable(p->iconActors[p->shownFormB], 1);
            CLACT_AddActorSurfacePos(p->iconActors[p->shownFormB], (ActorSurfacePos *)(&pos[1]), ifv);
        }
    } else {
        zp = (short *)rr;
        zp[0] = 0;
        zp[1] = 0;
        zp[2] = 0;
        zp[3] = 0;
        zp[4] = 0;
        zp[5] = 0;
        zp[6] = 0;
        zp[7] = 0;
        ifv = 0;
        if (p->femaleFlag != 0) ifv = 1;
        tern = p->femaleFlag == 0 ? B_FALSE : B_TRUE;
        sel[0] = x;
        sel[1] = y;
        rr[0].x = 0xa8;
        v = p->yOffset + 0x54;
        rr[0].y = v;
        rr[1].x = 0xd0;
        rr[1].y = v;
        arc = p->w[3];
        for (j = 0; j < 2; j++) {
            p->charIds[row][j] = -1;
            if (sel[j] != 0x11) {
                p->charIds[row][j] = (int)CLACT_RegisterCharacter(arc, APP_ICON_GetTypeCellFileId(sel[j]), 0, ifv, p->heap);
            }
        }
        for (j = 0; j < 2; j++) {
            if (p->charIds[row][j] != -1) {
                p->actorSlots[row][j] = CLACT_CreateActor((void *)p->clactUnit, p->charIds[row][j], p->paletteHandle, p->cellAnimHandle, &rr[j], (unsigned short)tern, p->heap);
                CLACT_SetActorPaletteOffset(p->actorSlots[row][j], APP_ICON_GetTypePaletteOffset(sel[j]), 1);
                CLACT_SetActorDrawPriority(p->actorSlots[row][j], 2);
                CLACT_SetActorObjMode(p->actorSlots[row][j], 1);
            }
        }
    }
}










void ZUKAN_INFO_LayoutFormPairEx(struct ZukanInfo *p, unsigned x, unsigned y, int z, int row)
{
    ShortRect4 rr[2];
    Pos pos[2];
    unsigned char sel[2];
    void *arc;
    void *handle;
    int data;
    int ta;
    int tb;
    unsigned char id;
    int ifv;
    int tern;
    short v;
    int j;
    short *zp;
    Blob *blob;

    zp = (short *)rr;
    zp[0] = 0;
    zp[1] = 0;
    zp[2] = 0;
    zp[3] = 0;
    zp[4] = 0;
    zp[5] = 0;
    zp[6] = 0;
    zp[7] = 0;
    ifv = 0;
    if (p->femaleFlag != 0) ifv = 1;
    tern = p->femaleFlag == 0 ? B_FALSE : B_TRUE;
    sel[0] = x;
    sel[1] = y;
    rr[0].x = 0xa8;
    v = p->yOffset + 0x54;
    rr[0].y = v;
    rr[1].x = 0xd0;
    rr[1].y = v;
    arc = p->w[3];
    handle = ARC_UTIL_LoadBgCharDataFromHandle(p->w[0], d_021BC128[z], 0, (unsigned int)(&blob), p->heap);
    data = blob->f14;
    for (j = 0; j < 2; j++) {
        p->charIds[row][j] = -1;
        id = sel[j];
        if (id != 0x11) {
            p->charIds[row][j] = (int)CLACT_RegisterCharacter(arc, APP_ICON_GetTypeCellFileId(id), 0, ifv, p->heap);
            ta = d_021BC150[id].b << 7;
            tb = d_021BC150[id].a << 11;
            CLACT_TransferCharacterPart((int)((void *)p->charIds[row][j]), (void *)(data + (tb + ta)), 0x80, 0, ifv);
            CLACT_TransferCharacterPart((int)((void *)p->charIds[row][j]), (void *)(data + ((tb + (1 << 10)) + ta)), 0x80, 0x80, ifv);
        }
    }
    GFL_HEAP_Free(handle);
    for (j = 0; j < 2; j++) {
        if (p->charIds[row][j] != -1) {
            p->actorSlots[row][j] = CLACT_CreateActor((void *)p->clactUnit, (u32)p->charIds[row][j], p->paletteHandle, p->cellAnimHandle, &rr[j], (unsigned short)tern, p->heap);
            CLACT_SetActorPaletteOffset(p->actorSlots[row][j], APP_ICON_GetTypePaletteOffset(sel[j]), 1);
            CLACT_SetActorDrawPriority(p->actorSlots[row][j], 2);
            CLACT_SetActorObjMode(p->actorSlots[row][j], 1);
        }
    }
}









void ZUKAN_INFO_DeleteRow(char *p, int index)
{
    int i;
    if (((struct ZukanInfo *)p)->iconVisible == 0) {
        for (i = 0; i < 2; i++) {
            if (((struct ZukanInfo *)p)->charIds[index][i] != -1)
                CLACT_DeleteActor((struct Obj *)(((struct ZukanInfo *)p)->actorSlots[index][i]));
        }
        for (i = 0; i < 2; i++) {
            if (((struct ZukanInfo *)p)->charIds[index][i] != -1) {
                CLACT_ReleaseCharacter(((struct ZukanInfo *)p)->charIds[index][i]);
                ((struct ZukanInfo *)p)->charIds[index][i] = -1;
            }
        }
    }
}









/*
 * tail: zero alignment halfword at 0x021BB9DE before 0x021BB9E0.
 * lever: two-dimensional arrays as struct fields avoid hoisted raw-offset bases.
 */
void ZUKAN_INFO_DisableOtherRows(struct ZukanInfo *p)
{
    u8 i,j;
    if (p->iconVisible==0) {
        for(i=0;i<2;i++) {
            if(i != p->iconEnabled) {
                for(j=0;j<2;j++) {
                    if(p->charIds[i][j]!=-1)
                        CLACT_SetActorDrawEnable(p->actorSlots[i][j],0);
                }
            }
        }
    }
}









void ZUKAN_INFO_InitFormGfx(struct ZukanInfo *p)
{
    u8 i;
    int flag;
    unsigned owner;
    i=0;
    for(;i<2;i++) p->formActor[i]=0;
    p->flag190=0;
    flag=0;
    if(p->femaleFlag) flag=1;
    owner=(unsigned)p->w[5];
    p->paletteHandleA=CLACT_RegisterPaletteEx((void *)owner,ZUKAN_INFO_GetPaletteFileId(p->femaleFlag),flag,160,0,1,p->heap);
    p->cellAnimA=CLACT_RegisterCellAnim((void *)owner,ZUKAN_INFO_GetCellAnimFileId(0),ZUKAN_INFO_GetCellAnimMode(0),p->heap);
    p->cellAnimB=CLACT_RegisterCellAnim((void *)owner,ZUKAN_INFO_GetCellAnimFileId(494),ZUKAN_INFO_GetCellAnimMode(494),p->heap);
}









void ZUKAN_INFO_DeleteFormGfx(char *p)
{
    unsigned char i;
    for (i = 0; i < 2; i++) {
        ZUKAN_INFO_DeleteActorPair((struct ZukanInfo *)p, i);
    }
    CLACT_ReleaseCellAnim((u32)(((struct ZukanInfo *)p)->cellAnimB));
    CLACT_ReleaseCellAnim((u32)(((struct ZukanInfo *)p)->cellAnimA));
    CLACT_ReleasePalette((u32)(((struct ZukanInfo *)p)->paletteHandleA));
}








void ZUKAN_INFO_CreateSpeciesActor(struct ZukanInfo *p, u32 a, u32 b, u32 idx)
{
    u32 flag;
    u32 w;
    u32 v;
    Bool flag2;
    struct Point pt;

    flag = 0;
    if (p->femaleFlag != 0)
        flag = 1;
    flag2 = p->femaleFlag == 0 ? B_FALSE : B_TRUE;
    v = ZUKAN_INFO_GetFormFlag(a, b);
    if (v == 0xFFFF) {
        w = (u32)p->w[5];
        p->formChar[idx] = (u32)CLACT_RegisterCharacter((void *)w, ZUKAN_INFO_GetSpeciesCellFileId(a), 1, flag, p->heap);
    } else {
        p->formChar[idx] = (u32)CLACT_RegisterCharacter((void *)p->w[6], v, 1, flag, p->heap);
    }
    pt.x = 0x78;
    pt.y = p->yOffset + 0x58;
    pt.f4 = 0;
    pt.f6 = 1;
    pt.f7 = 0;
    if (a <= 0x1ED && v != 0xFFFF)
        p->formActor[idx] = CLACT_CreateActor((void *)p->clactUnit, p->formChar[idx], p->paletteHandleA, p->cellAnimA, &pt, flag2, p->heap);
    else
        p->formActor[idx] = CLACT_CreateActor((void *)p->clactUnit, p->formChar[idx], p->paletteHandleA, p->cellAnimB, &pt, flag2, p->heap);
    CLACT_SetActorDrawPriority(p->formActor[idx], 1);
    CLACT_SetActorObjMode(p->formActor[idx], 1);
    ZUKAN_INFO_DisableUnselected(p);
}








void ZUKAN_INFO_DeleteActorPair(struct ZukanInfo *p, int i)
{
    if (p->formActor[i] != 0) {
        CLACT_DeleteActor(p->formActor[i]);
        CLACT_ReleaseCharacter((u32)p->formChar[i]);
        p->formActor[i] = 0;
    }
}






void ZUKAN_INFO_DisableUnselected(struct ZukanInfo *p)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (i != p->flag190 && p->formActor[i] != 0)
            CLACT_SetActorDrawEnable(p->formActor[i], 0);
    }
}






void ZUKAN_INFO_RefreshDisplay(struct ZukanInfo *p)
{
    ZUKAN_INFO_ShowFormPair((char *)p, 6, p->iconEnabled);
    ZUKAN_INFO_CreateSpeciesActor(p, p->species, p->form, p->flag190);
    ZUKAN_INFO_SetDrawEnable(p, p->showCurrent);
    ZUKAN_INFO_DrawMainPage((char *)p);
}






void ZUKAN_INFO_RefreshPage(struct ZukanInfo *p, int v)
{
    ZUKAN_INFO_ShowFormPair((char *)p, v, p->iconEnabled);
    ZUKAN_INFO_CreateSpeciesActor(p, p->species, p->form, p->flag190);
    ZUKAN_INFO_SetDrawEnable(p, p->showCurrent);
    ZUKAN_INFO_DrawPage((char *)p, v);
}





s32 ZUKAN_INFO_BlendPalette(struct ZukanInfo *p)
{
    s16 f;
    u8 i;

    if (p->bgOffset + 0x400 >= 0x10000)
        p->bgOffset = p->bgOffset + 0x400 - 0x10000;
    else
        p->bgOffset += 0x400;
    f = (FX_SinCosTable_[(p->bgOffset >> 4) * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < 5; i++) {
        u16 a = p->palA[i];
        u16 b = p->palB[i];
        u8 a1 = a & 0x1f;
        u8 a2 = (a & 0x3e0) >> 5;
        u8 a3 = (a & 0x7c00) >> 10;
        u8 b1 = b & 0x1f;
        u8 b2 = (b & 0x3e0) >> 5;
        u8 b3 = (b & 0x7c00) >> 10;
        u8 c1 = a1 + (((b1 - a1) * f) >> 12);
        u8 c2 = a2 + (((b2 - a2) * f) >> 12);
        u8 c3 = a3 + (((b3 - a3) * f) >> 12);
        p->palBuf[i] = c1 | (c2 << 5) | (c3 << 10);
    }
    return NNS_GfdRegisterNewVramTransferTask((void *)(p->femaleFlag == 0 ? 0xf : 0x1f), 0x22, (u32)p->palBuf, 0xa);
}





void ZUKAN_INFO_SetDrawEnable(struct ZukanInfo *p, int v)
{
    u8 i;
    CLACT_SetActorDrawEnable(p->formActor[p->flag190],v);
    if(p->iconVisible) {
        if(p->shownFormA!=17) CLACT_SetActorDrawEnable(p->iconActors[p->shownFormA],v);
        if(p->shownFormB!=17) CLACT_SetActorDrawEnable(p->iconActors[p->shownFormB],v);
    } else {
        for(i=0;i<2;i++) {
            if(p->charIds[p->iconEnabled][i]!=-1)
                CLACT_SetActorDrawEnable(p->actorSlots[p->iconEnabled][i],v);
        }
    }
}





void ZUKAN_INFO_SetSlotDrawEnable(struct ZukanInfo *p, int v)
{
    CLACT_SetActorDrawEnable(p->actors[p->selected], v);
    if (p->showCurrent == 0)
        v = 0;
    ZUKAN_INFO_SetDrawEnable(p, v);
}





void ZUKAN_INFO_LoadResources(struct ZukanInfo *p)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        switch (i) {
        case 3:
            p->w[i] = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), p->heap);
            break;
        case 4:
            p->w[i] = (void *)POKEGRA_OpenHandle(p->heap);
            break;
        case 5:
            p->w[i] = ARC_TOOL_CreateHandle(ZUKAN_INFO_GetTypeArchiveId(), p->heap);
            break;
        case 6:
            p->w[i] = ARC_TOOL_CreateHandle(ZUKAN_INFO_GetIconArchiveId(), p->heap);
            break;
        default:
            p->w[i] = ARC_TOOL_CreateHandle(tbl_021BC134[i], p->heap);
            break;
        }
    }
    for (i = 0; i < 35; i++) {
        switch (i) {
        case 1:
            if (p->g[0] != 0)
                p->objs[i] = p->g[0];
            else
                p->objs[i] = MSGDATA_CreateFromArchive(0, 2, tbl_021BC1C4[i], p->heap);
            break;
        case 2:
            if (p->g[1] != 0)
                p->objs[i] = p->g[1];
            else
                p->objs[i] = MSGDATA_CreateFromArchive(0, 2, tbl_021BC1C4[i], p->heap);
            break;
        case 3:
            if (p->g[2] != 0)
                p->objs[i] = p->g[2];
            else
                p->objs[i] = MSGDATA_CreateFromArchive(0, 2, tbl_021BC1C4[i], p->heap);
            break;
        default:
            p->objs[i] = MSGDATA_CreateFromArchive(0, 2, tbl_021BC1C4[i], p->heap);
            break;
        }
    }
    p->x = POKE_PERSONAL_Create(p->species, p->form, p->heap);
    for (i = 0; i < 16; i++)
        p->text.str[i] = MSGDATA_AllocString(p->objs[0], tbl_021BC184[i]);
}




void ZUKAN_INFO_FreeResources(struct ZukanInfo *p)
{
    u8 i;
    for (i = 0; i < 16; i++)
        STRBUF_Delete(p->text.str[i]);
    if (p->x != 0)
        POKE_PERSONAL_Delete(p->x);
    for (i = 0; i < 35; i++) {
        switch (i) {
        case 1:
            if (p->g[0] == 0)
                MSGDATA_Delete(p->objs[i]);
            break;
        case 2:
            if (p->g[1] == 0)
                MSGDATA_Delete(p->objs[i]);
            break;
        case 3:
            if (p->g[2] == 0)
                MSGDATA_Delete(p->objs[i]);
            break;
        default:
            MSGDATA_Delete(p->objs[i]);
            break;
        }
    }
    for (i = 0; i < 7; i++)
        ARC_TOOL_DeleteHandle(p->w[i]);
}




u32 ZUKAN_INFO_GetTypeArchiveId(void)
{
    return 0xa7;
}




int ZUKAN_INFO_GetSpeciesCellFileId(int v)
{
    return v + 5;
}




int ZUKAN_INFO_GetPaletteFileId(int a0)
{
    return 0;
}





int ZUKAN_INFO_GetCellAnimFileId(int v)
{
    if (v <= 0x1ED)
        return 2;
    else
        return 4;
}





int ZUKAN_INFO_GetCellAnimMode(int v)
{
    if (v <= 0x1ED)
        return 1;
    else
        return 3;
}




u32 ZUKAN_INFO_GetIconArchiveId(void)
{
    return 0xe9;
}


u32 ZUKAN_INFO_GetFormFlag(u32 a, u32 b)
{
    if (a == 0x1E7 && b == 1)
        return 0;
    if (a == 0x1EC && b == 1)
        return 1;
    return 0xFFFF;
}
