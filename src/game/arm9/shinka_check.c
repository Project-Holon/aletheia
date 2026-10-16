/*
 * file:     shinka_check.c
 * unit:     yes
 * function: SHINKA_CHECK_CheckEvolution, SHINKA_CHECK_OpenHandle, SHINKA_CHECK_GetRowParam, SHINKA_CHECK_LoadData, SHINKA_CHECK_KnowsMove, NATSUKI_Calc, NATSUKI_CalcUseItem, NATSUKI_CalcWalk, NATSUKI_CalcParty, NATSUKI_Apply, POKE_TOOL_IsPPRestorable, POKE_TOOL_RestorePP, POKE_TOOL_HealFull, POKE_TOOL_HealParty, POKE_TOOL_GetGraphicIndex, POKE_TOOL_CalcGraphicIndex, POKE_TOOL_CalcIconPalette, POKE_TOOL_GetIconPalette, POKE_TOOL_GetIconPaletteArcId, POKE_TOOL_GetIconCellArcId, POKE_TOOL_GetIconCellArcIdSub, POKE_TOOL_GetIconCellEntryId, POKE_TOOL_GetIconCellEntryIdSub, WAZA_TOOL_GetParam, WAZA_TOOL_GetDataParam, WAZA_TOOL_GetFlag, WAZA_TOOL_GetDataFlag, WAZA_TOOL_GetSickCont, WAZA_TOOL_GetRankEffectCount, WAZA_TOOL_GetRankEffect, WAZA_TOOL_GetMaxPP, WAZA_TOOL_GetWeather, WAZA_TOOL_GetCategory, WAZA_TOOL_GetType, WAZA_TOOL_GetPower, WAZA_TOOL_GetDamageType, WAZA_TOOL_IsAlwaysHit, WAZA_TOOL_IsAlwaysCritical, WAZA_TOOL_IsDamaging, WAZA_TOOL_CreateCache, WAZA_TOOL_DeleteCache, WAZA_TOOL_IsCacheCreated, PRINTSYS_Init, PRINTSYS_QUE_Create, PRINTSYS_QUE_CreateEx, PRINTSYS_QUE_Delete, PRINTSYS_QUE_SetForceQueue, PRINTSYS_QUE_SetLimitTick, PRINTSYS_QUE_Main, PRINTSYS_QUE_IsFinished, PRINTSYS_QUE_IsExistTarget, PRINTSYS_QUE_Clear, PRINTSYS_PrintQue, PRINTSYS_PrintQueColor, PRINTSYS_SubmitJob, PRINTSYS_Print, PRINTSYS_PrintColor, PRINTSYS_SetupJob, PRINTSYS_SetJobColor, PRINTSYS_RunJob, PRINTSYS_PrintStep, PRINTSYS_PutGlyph4bpp, PRINTSYS_PutGlyph8bpp, PRINTSYS_ProcGeneralTag, PRINTSYS_ProcColorTag, PRINTSYS_PrintStream, PRINTSYS_PrintStreamCallBack, PRINTSYS_SplitWait, PRINTSYS_PrintStreamStop, PRINTSYS_PrintStreamRun, PRINTSYS_PrintStreamGetState, PRINTSYS_PrintStreamGetWaitKind, PRINTSYS_PrintStreamReleasePause, PRINTSYS_PrintStreamDelete, PRINTSYS_PrintStreamShortWait, PRINTSYS_PrintStreamSetSpeed, PRINTSYS_PrintStreamResetSpeed, PRINTSYS_PrintStreamIsOverrideSpeed
 * address:  0x0201B2B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pokeparty.c by tools/splitfile.py.
 *
 * symbols:
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   GFL_HEAP_Alloc 0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   FILE_UTIL_Get_0FE4   0x02020FE4  thumb
 *   TIMEZONE_IsNight   0x02011410  thumb
 *   shinka_check_File 0x020A7330 data  a1
 *   _IceRockZones      0x020A7320  data  a2
 *   _MossRockZones      0x020A7322  data  a2
 *   _MagneticZones      0x020A7324  data  a2
 *   _ExtraEvolutionZones      0x020A732A  data  a2
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   _NatsukiDeltaTable     0x0209E45C  data
 *   _NatsukiWalkDeltas     0x0209E465  data  a1
 *   _NatsukiPartyDeltas     0x0209E462  data
 *   ZONEDATA_GetPlaceNameId   0x02013E4C  thumb
 *   GPOWER_ApplyFriendshipBonus   0x02011014  thumb
 *   _IconPaletteTable  0x0209E474  data
 *   _pWazaTool   0x02146530  data
 *   _WazaTempData  0x02146534  data
 *   waza_tool_File  0x020A7340  data
 *   _pGlyphBmp         0x02146558  data
 *   printsys_File   0x020A734C  data
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   GF_FONT_IsTextColorDifferent  0x0201DE18  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   OS_GetTick  0x020870D0  arm
 *   GF_FONT_UpdatePrintsy  0x0201D7C4  thumb
 *   _PrintJobWork   0x0214655C  data
 *   STRBUF_GetChars  0x02045A90  arm
 *   func_0201D26C  0x0201D26C  thumb
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   GF_FONT_Task  0x0201CEE0  thumb
 *   POKE_TOOL_GetPersonalParam 0x02019C90 thumb
 *   GF_FONT_ReadGlyph  0x0201DB04  thumb
 *   TCBL_DeleteTask  0x02031194  arm
 *   BMP_GetTileBytes  0x02043994  arm
 *   BMP_BlitPaletteOffset  0x02043AAC  arm
 *   STRBUF_SetEosChar  0x020457A0  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_Blit  0x020439A0  arm
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   MSG_SPEED_GetWaitForSpeed  0x02013080  thumb
 *   GF_FONT_CopyStrbufD6D8  0x0201D6D8  thumb
 *   GF_FONT_GetAllocSize  0x0201D6B8  thumb
 *   GF_FONT_GetQueueLength  0x0201D6C4  thumb
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb arm9
 *   POKEPARTY_GetMember 0x0201AB28 thumb arm9
 *   POKEPARTY_HasSpecies 0x0201AC44 thumb arm9
 */
#include "pokeparty_shared_types.h"

#define REG_DISPCNT      (*(volatile u32 *)0x04000000)

#define REG_DB_DISPCNT   (*(volatile u32 *)0x04001000)

#define OBJ_MAPPING_MASK 0x300010

struct Strbuf;

struct Bmp;

struct BmpWin;

struct GfFont;

struct Tcbl;

struct TcblNode;

typedef signed char    s8;

typedef signed short   s16;

/* One evolution: method, its argument (level, item, move, species ...)
 * and the species it evolves into. */
struct EvolutionRow {
    u16 method;
    u16 param;
    u16 species;
};

/* The 0x2C byte evolution record of one species. */
struct EvolutionData {
    struct EvolutionRow rows[7];
    u16 pad;
};

/* The 0x24 byte move record (waza_tool.c). */
struct WazaData {
    u8  type;
    u8  category;
    u8  damageType;
    u8  power;
    u8  accuracy;
    u8  basePP;
    s8  priority;
    u8  hitMin : 4;
    u8  hitMax : 4;
    u16 sickId;
    u8  sickPercent;
    u8  sickContType;
    u8  sickTurnMin;
    u8  sickTurnMax;
    u8  criticalRank;
    u8  shrinkPercent;
    u16 effectSequence;
    s8  drainRatio;
    s8  healRatio;
    u8  target;
    u8  rankType[3];
    s8  rankValue[3];
    u8  rankPercent[3];
    u8  pad[2];
    u32 flags;
};

/* The move record cache: `count` records and the move id each one holds
 * (0 for an empty slot). */
struct WazaTool {
    struct WazaData **records;
    u16 *moveIds;
    s32 count;
};

/* The packed sick-continuation value WAZA_TOOL_GetSickCont returns. */
union WazaSickCont {
    struct {
        u16 type : 4;
        u16 turnMin : 6;
        u16 turnMax : 6;
    } bits;
    s16 value;
};

/* Pen origin and colour mode, packed in one word of PrintCtx. */
union PrintPos {
    u32 raw;
    struct {
        s32 originX : 10;
        u32 originY : 10;
        s32 colorMode : 4;
        u32 extra : 8;
    } bits;
};

typedef void (*PrintBlitFn)(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo);

/* One print job: the pen, the colours, the font and the target bitmap. */
struct PrintCtx {
    s16 penX;
    s16 penY;
    union PrintPos pos;
    u16 letterSpacing;
    u16 lineSpacing;
    u16 textColor;
    u16 activeColor;
    struct GfFont *font;
    struct Bmp *bmp;
    PrintBlitFn blitGlyph;
};

union PrintTicks {
    u64 value;
    struct {
        u32 low;
        u32 high;
    } half;
};

union PrintQueueState {
    u8 raw;
    struct {
        u8 pending : 4;
        u8 forceQueue : 4;
    } bits;
};

/* The print queue: a byte ring of queued jobs and their strings after the
 * 0x18 byte header. */
struct PrintQueue {
    u16 head;
    u16 tail;
    u16 capacity;
    u8  frameCount;
    union PrintQueueState state;
    union PrintTicks limitTicks;
    struct PrintCtx *job;
    u16 *cursor;
    u8  data[4];
};

typedef u8 (*PrintCallback)(u32 arg);

union TextPrinterFlags {
    u8 raw;
    struct {
        u8 halted : 1;
        u8 scrolling : 1;
        u8 advance : 1;
        u8 useOverrideSpeed : 1;
        u8 clearOverridePending : 1;
        u8 reserved : 3;
    } bits;
};

/* A streamed text print (0x50 byte task work). */
struct TextPrinter {
    u32  state;
    u32  waitKind;
    struct BmpWin *bmpWin;
    struct Bmp *bmp;
    struct TcblNode *task;
    u16 *cursor;
    u8   defaultWait;
    u8   defaultGlyphs;
    u8   waitFrames;
    u8   glyphsPerTick;
    u8   overrideWait;
    u8   overrideGlyphs;
    u8   waitCounter;
    u8   scrollPixels;
    u8   fillColor;
    u8   callbackResult;
    union TextPrinterFlags flags;
    u8   pad23;
    PrintCallback callback;
    u32  initialCallbackArg;
    u32  nextCallbackArg;
    u32  callbackArg;
    struct PrintCtx ctx;
};

extern u32   POKE_TOOL_GetBoxValue(struct BoxPokemon *box, u32 id, u32 arg);

extern void  ARC_TOOL_ReadMember(void *dst, u32 arcId, u32 dataId);

extern u32   POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 id, u32 arg);

extern void  POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 id, u32 value);

extern void *GFL_HEAP_Alloc(u32 heap, u32 size, int fromTail, const char *file, u16 line);

extern u32   GFL_HEAP_Free(void *ptr);

extern struct ArcHandle *ARC_TOOL_CreateHandle(unsigned int arcId, unsigned int heap);

extern u32   GF_STANDARD_Rand(void);

extern u32   FILE_UTIL_Get_0FE4(u32 item, u32 param, u16 heap);

extern u32   TIMEZONE_IsNight(u32 timezone);

extern void  ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 dataId, void *dst);

extern u32   ZONEDATA_GetPlaceNameId(u32 zoneId);

extern int   GPOWER_ApplyFriendshipBonus(int delta);

extern u32   POKE_TOOL_DecodeBoxParam(struct BoxPokemon *box);

extern u32   POKE_TOOL_EncodeBoxParam(struct BoxPokemon *box, u32 wasDecoded);

extern u32   ARC_TOOL_GetMemberSize(u32 arcId, u32 dataId);

extern void  STRBUF_SetEosChar(u16 eosChar);

extern struct Bmp *BMP_Create(u32 widthTiles, u32 heightTiles, u32 tileBytes, u32 heap);

extern void  GF_FONT_GetTextColor(u8 *letter, u8 *shadow, u8 *background);

extern u32   GF_FONT_IsTextColorDifferent(u32 letter, u32 shadow, u32 background);

extern void  GF_FONT_SetTextColor(u32 letter, u32 shadow, u32 background);

extern u64   OS_GetTick(void);

extern struct PrintCtx *GF_FONT_UpdatePrintsy(struct PrintQueue *queue, struct PrintCtx *job);

extern int   GFL_NET_GetNegotiationNum(void);

extern u32   GF_FONT_GetAllocSize(struct Strbuf *str);

extern u32   GF_FONT_GetQueueLength(const struct PrintQueue *queue);

extern void  GF_FONT_CopyStrbufD6D8(struct PrintQueue *queue, struct PrintCtx *job, struct Strbuf *str);

extern u16  *STRBUF_GetChars(struct Strbuf *str);

extern u8    BMP_GetTileBytes(struct Bmp *bmp);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern void  BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 width, u32 height, u32 colorKey);

extern void  GF_FONT_ReadGlyph(struct GfFont *font, u16 code, void *dst, void *metrics);

extern void  BMP_BlitPaletteOffset(struct Bmp *src, u32 dst, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 width, u32 height, u16 colorKey, u16 shift);

extern u32   func_0201D26C(u16 *str, void *font, u32 spacing, u16 **next);

extern u16   BMP_GetWidth(const struct Bmp *bmp);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern struct TcblNode *TCBL_AddTask(struct Tcbl *tcbl, void *func, u32 workSize, u32 priority);

extern void *TCBL_GetWork(struct TcblNode *task);

extern void  GF_FONT_Task(void *task, struct TextPrinter *printer);

extern void  TCBL_DeleteTask(struct TcblNode *task);

extern signed char MSG_SPEED_GetWaitForSpeed(u32 speed);

u32 POKE_TOOL_GetPersonalParam(u16 species, u16 form, u32 field);

u32 POKEPARTY_GetCount(const struct Party *party);

struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);

u32 POKEPARTY_HasSpecies(struct Party *party, u32 species);

u32 SHINKA_CHECK_CheckEvolution(struct Party *party, struct PokemonParam *pp, u32 mode, u32 arg, u8 timezone, u32 *methodOut, u16 heap);

struct ArcHandle *SHINKA_CHECK_OpenHandle(u32 heap);

u32 SHINKA_CHECK_GetRowParam(struct ArcHandle *arc, u32 species, u32 rowIndex, u32 field);

void SHINKA_CHECK_LoadData(u32 species, struct EvolutionRow *rows);

u32 SHINKA_CHECK_KnowsMove(struct PokemonParam *pp, u32 move);

void NATSUKI_Calc(struct PokemonParam *pp, int type, int zoneId, u16 heap);

void NATSUKI_CalcUseItem(struct PokemonParam *pp, int item, u16 zoneId, u16 heap);

void NATSUKI_CalcWalk(struct PokemonParam *pp, int zoneId, u16 heap);

void NATSUKI_CalcParty(struct Party *party, int zoneId, u16 heap);

void NATSUKI_Apply(struct PokemonParam *pp, const s8 *deltas, int zoneId, u16 heap);

u8 POKE_TOOL_IsPPRestorable(struct PokemonParam *pp, u32 slot);

u32 POKE_TOOL_RestorePP(struct PokemonParam *pp, u32 slot, u32 amount);

void POKE_TOOL_HealFull(struct PokemonParam *pp);

void POKE_TOOL_HealParty(struct Party *party);

u32 POKE_TOOL_GetGraphicIndex(struct BoxPokemon *box);

u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 female, u32 isEgg);

u32 POKE_TOOL_GetIconPalette(struct BoxPokemon *box);

int POKE_TOOL_GetIconPaletteArcId(void);

int POKE_TOOL_GetIconCellArcId(void);

int POKE_TOOL_GetIconCellArcIdSub(void);

int POKE_TOOL_GetIconCellEntryId(void);

int POKE_TOOL_GetIconCellEntryIdSub(void);

u32 WAZA_TOOL_GetParam(u16 move, u32 param);

u32 WAZA_TOOL_GetDataParam(const struct WazaData *data, u32 param);

u32 WAZA_TOOL_GetFlag(u16 move, u32 flag);

u32 WAZA_TOOL_GetDataFlag(const struct WazaData *data, u32 flag);

s16 WAZA_TOOL_GetSickCont(u16 move);

u8 WAZA_TOOL_GetRankEffectCount(u16 move);

u8 WAZA_TOOL_GetRankEffect(u16 move, u32 index, s32 *value);

u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);

u32 WAZA_TOOL_GetWeather(int item);

u32 WAZA_TOOL_GetCategory(u16 move);

u8 WAZA_TOOL_GetType(u16 move);

u16 WAZA_TOOL_GetPower(u16 move);

int WAZA_TOOL_GetDamageType(u16 move);

u32 WAZA_TOOL_IsAlwaysHit(u16 move);

u32 WAZA_TOOL_IsAlwaysCritical(u16 move);

u32 WAZA_TOOL_IsDamaging(u16 move);

void WAZA_TOOL_CreateCache(s32 count, u32 heap);

void WAZA_TOOL_DeleteCache(void);

u32 WAZA_TOOL_IsCacheCreated(void);

void PRINTSYS_Init(u32 heap);

struct PrintQueue *PRINTSYS_QUE_Create(u32 heap);

struct PrintQueue *PRINTSYS_QUE_CreateEx(u16 bufSize, u32 heap);

void PRINTSYS_QUE_Delete(struct PrintQueue *queue);

void PRINTSYS_QUE_SetForceQueue(struct PrintQueue *queue, u32 forceQueue);

void PRINTSYS_QUE_SetLimitTick(struct PrintQueue *queue, u32 tickLow, u32 tickHigh);

u32 PRINTSYS_QUE_Main(struct PrintQueue *queue);

u32 PRINTSYS_QUE_IsFinished(const struct PrintQueue *queue);

u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);

void PRINTSYS_QUE_Clear(struct PrintQueue *queue);

void PRINTSYS_PrintQue(struct PrintQueue *queue, struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font);

void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);

void PRINTSYS_SubmitJob(struct PrintQueue *queue, struct PrintCtx *job, struct Strbuf *str);

void PRINTSYS_Print(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font);

void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);

void PRINTSYS_SetupJob(struct PrintCtx *job, struct GfFont *font, struct Bmp *bmp, u32 x, s16 y);

void PRINTSYS_SetJobColor(struct PrintCtx *job, u16 color);

void PRINTSYS_RunJob(struct PrintCtx *job, struct Strbuf *str);

u16 *PRINTSYS_PrintStep(struct PrintCtx *job, u16 *cursor, u32 stopAtPause);

void PRINTSYS_PutGlyph4bpp(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo);

void PRINTSYS_PutGlyph8bpp(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo);

u16 *PRINTSYS_ProcGeneralTag(struct PrintCtx *job, u16 *cursor);

u16 *PRINTSYS_ProcColorTag(struct PrintCtx *job, u16 *cursor);

void PRINTSYS_PrintStream(struct BmpWin *win, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, s32 wait, struct Tcbl *tcbl, u32 priority, u16 heap, u16 fillColor);

struct TextPrinter *PRINTSYS_PrintStreamCallBack(struct BmpWin *win, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, s32 wait, struct Tcbl *tcbl, u32 priority, u32 heap, u16 fillColor, PrintCallback callback);

void PRINTSYS_SplitWait(int wait, u8 *speed);

void PRINTSYS_PrintStreamStop(struct TextPrinter *printer);

void PRINTSYS_PrintStreamRun(struct TextPrinter *printer);

u32 PRINTSYS_PrintStreamGetState(const struct TextPrinter *printer);

u32 PRINTSYS_PrintStreamGetWaitKind(const struct TextPrinter *printer);

void PRINTSYS_PrintStreamReleasePause(struct TextPrinter *printer);

void PRINTSYS_PrintStreamDelete(struct TextPrinter *printer);

void PRINTSYS_PrintStreamShortWait(struct TextPrinter *printer, s32 wait);

void PRINTSYS_PrintStreamSetSpeed(struct TextPrinter *printer, s32 wait);

void PRINTSYS_PrintStreamResetSpeed(struct TextPrinter *printer);

u32 PRINTSYS_PrintStreamIsOverrideSpeed(const struct TextPrinter *printer);

extern u8 shinka_check_File[];

extern const u16 _IceRockZones[1];

extern const u16 _MossRockZones[1];

extern const u16 _MagneticZones[3];

extern const u16 _ExtraEvolutionZones[3];

extern const s8 _NatsukiDeltaTable[];

extern const s8 _NatsukiWalkDeltas[];

extern const s8 _NatsukiPartyDeltas[];

extern const u8 _IconPaletteTable[];

extern struct WazaTool *_pWazaTool;

extern struct WazaData _WazaTempData;

extern const char waza_tool_File[];

extern struct Bmp *_pGlyphBmp;

extern const char printsys_File[];

extern struct PrintCtx _PrintJobWork;

/*
 * note:     wave 18 (2026-09-24): EXACT* (the listing extent includes the
 *           12-byte unlabelled follower at 0x0201B70C, src/matched/
 *           unit_0201B70C.c).  Closed by the heap id's width: the seventh
 *           parameter is a u16 and FILE_UTIL_Get_0FE4 takes its third argument
 *           as a u16.  With both u32 the gate's `ldr r2, [sp, #0x68]` is
 *           hoisted above the pidHigh store (12 bytes out); u16 on the
 *           parameter alone breaks the size, u16 on both keeps the load
 *           behind the store as in the image.  FILE_UTIL_Get_0FE4 masks the id to
 *           fifteen bits and ORs in 0x8000 (a temporary-heap id), and
 *           src/matched/unit_02007CB0.c already declares that parameter u16.
 *
 * shinka_check.c (the string at 0x020A7330), the evolution checker: the
 * egg/everstone gate, then the 0x2A-byte evolution record (seven six-byte
 * rows, SHINKA_CHECK_LoadData) walked under a switch on the context (0 level up,
 * 1 trade, 2 and 3 item use); the first row that fires gives the target
 * species and its method goes to *methodOut (method 15 writes 15 and gives
 * no species).  docs/notes/SHINKA_CHECK_CheckEvolution.c.txt holds the method map and the
 * history.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SHINKA_CHECK_CheckEvolution.c \
 *       --func SHINKA_CHECK_CheckEvolution --addr 0x0201B2B0 --cc 1.1p1 --thumb
 */
u32 SHINKA_CHECK_CheckEvolution(struct Party *party, struct PokemonParam *pp, u32 mode, u32 arg,
                 u8 timezone, u32 *methodOut, u16 heap)
{
    u32 unusedMethod;
    u32 attackLess;
    u32 attackEqual;
    u32 attackGreater;
    u32 personality;
    struct EvolutionRow *rows;
    u16 species;
    u16 heldItem;
    u16 friendship;
    u16 personalityHigh;
    u8  level;
    u8  beauty;
    int i;
    u16 result;
    u8  holdEffect;
    struct EvolutionRow *row;
    u32 k;

    result = 0;
    if (POKE_TOOL_GetPartyValue(pp, 0x4C, 0) != 0) {
        return result;
    }
    species = POKE_TOOL_GetPartyValue(pp, 5, 0);
    heldItem = POKE_TOOL_GetPartyValue(pp, 6, 0);
    personality = POKE_TOOL_GetPartyValue(pp, 0, 0);
    beauty = POKE_TOOL_GetPartyValue(pp, 0x14, 0);
    personalityHigh = (personality & 0xFFFF0000) >> 16;
    holdEffect = FILE_UTIL_Get_0FE4(heldItem, 1, heap);
    if (species != 0x40 && holdEffect == 0x40 && mode != 3) {
        return result;
    }
    if (methodOut == 0) {
        methodOut = &unusedMethod;
    }
    i = 0;
    rows = GFL_HEAP_Alloc(heap, 0x2A, 0, (const char *)shinka_check_File, 0x6A);
    SHINKA_CHECK_LoadData(species, rows);

    switch (mode) {
    case 0:
        level = POKE_TOOL_GetPartyValue(pp, 0x9E, i);
        friendship = POKE_TOOL_GetPartyValue(pp, 9, i);
        for (i = 0; i < 7; i++) {
            row = &rows[i];
            switch (row->method) {
            case 1:
                if (friendship >= 220) {
                    result = row->species;
                }
                break;
            case 2:
                if (TIMEZONE_IsNight(timezone) == 0 && friendship >= 220) {
                    result = row->species;
                }
                break;
            case 3:
                if (TIMEZONE_IsNight(timezone) == 1 && friendship >= 220) {
                    result = row->species;
                }
                break;
            case 4:
                if (row->param <= level) {
                    result = row->species;
                }
                break;
            case 9:
                if (row->param <= level) {
                    attackGreater = POKE_TOOL_GetPartyValue(pp, 0xA2, 0);
                    if (attackGreater > POKE_TOOL_GetPartyValue(pp, 0xA3, 0)) {
                        result = row->species;
                    }
                }
                break;
            case 10:
                if (row->param <= level) {
                    attackEqual = POKE_TOOL_GetPartyValue(pp, 0xA2, 0);
                    if (attackEqual == POKE_TOOL_GetPartyValue(pp, 0xA3, 0)) {
                        result = row->species;
                    }
                }
                break;
            case 11:
                if (row->param <= level) {
                    attackLess = POKE_TOOL_GetPartyValue(pp, 0xA2, 0);
                    if (attackLess < POKE_TOOL_GetPartyValue(pp, 0xA3, 0)) {
                        result = row->species;
                    }
                }
                break;
            case 12:
                if (row->param <= level && personalityHigh % 10 < 5) {
                    result = row->species;
                }
                break;
            case 13:
                if (row->param <= level && personalityHigh % 10 >= 5) {
                    result = row->species;
                }
                break;
            case 14:
                if (row->param <= level) {
                    result = row->species;
                }
                break;
            case 15:
                *methodOut = 15;
                break;
            case 16:
                if (row->param <= beauty) {
                    result = row->species;
                }
                break;
            case 19:
                if (TIMEZONE_IsNight(timezone) == 0 && heldItem == row->param) {
                    result = row->species;
                }
                break;
            case 20:
                if (TIMEZONE_IsNight(timezone) == 1 && heldItem == row->param) {
                    result = row->species;
                }
                break;
            case 21:
                if (SHINKA_CHECK_KnowsMove(pp, row->param) == 1) {
                    result = row->species;
                }
                break;
            case 22:
                if (party != 0 && POKEPARTY_HasSpecies(party, row->param) == 1) {
                    result = row->species;
                }
                break;
            case 23:
                if (POKE_TOOL_GetPartyValue(pp, 0x6E, 0) == 0 && row->param <= level) {
                    result = row->species;
                }
                break;
            case 24:
                if (POKE_TOOL_GetPartyValue(pp, 0x6E, 0) == 1 && row->param <= level) {
                    result = row->species;
                }
                break;
            case 25:
                for (k = 0; k < 3; k++) {
                    if (arg == _MagneticZones[k]) {
                        result = row->species;
                        break;
                    }
                }
                break;
            case 26:
                for (k = 0; k < 1; k++) {
                    if (arg == _MossRockZones[k]) {
                        result = row->species;
                        break;
                    }
                }
                break;
            case 27:
                for (k = 0; k < 1; k++) {
                    if (arg == _IceRockZones[k]) {
                        result = row->species;
                        break;
                    }
                }
                break;
            case 28:
                for (k = 0; k < 3; k++) {
                    if (arg == _ExtraEvolutionZones[k]) {
                        result = row->species;
                        break;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 1:
        for (i = 0; i < 7; i++) {
            row = &rows[i];
            switch (row->method) {
            case 5:
                result = row->species;
                break;
            case 6:
                if (heldItem == row->param) {
                    result = row->species;
                }
                break;
            case 7:
                if (FILE_UTIL_Get_0FE4((u16)POKE_TOOL_GetPartyValue((struct PokemonParam *)arg, 6, 0), 1, heap) != 0x40) {
                    if ((POKE_TOOL_GetPartyValue(pp, 0xAB, 0) == 588
                         && POKE_TOOL_GetPartyValue((struct PokemonParam *)arg, 0xAB, 0) == 616)
                     || (POKE_TOOL_GetPartyValue((struct PokemonParam *)arg, 0xAB, 0) == 588
                         && POKE_TOOL_GetPartyValue(pp, 0xAB, 0) == 616)) {
                        result = row->species;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 2:
    case 3:
        for (i = 0; i < 7; i++) {
            row = &rows[i];
            if (row->method == 8 && arg == row->param) {
                result = row->species;
            }
            if (row->method == 0x11 && POKE_TOOL_GetPartyValue(pp, 0x6E, 0) == 0 && arg == row->param) {
                result = row->species;
            }
            if (row->method == 0x12 && POKE_TOOL_GetPartyValue(pp, 0x6E, 0) == 1 && arg == row->param) {
                result = row->species;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    }
    GFL_HEAP_Free(rows);
    return result;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * shinka_check.c's data layer: the four small routines the evolution checker
 * at 0x0201B2B0 reads its per-species evolution table through, plus the "does
 * this Pokemon already know that move" predicate one of its arms needs.
 *
 * All three archive routines name the same narc member kind, 0x13, the way
 * src/matched/unit_0201BD28.c's waza_tool.c names 0x15 and
 * src/matched/unit_0201ADD0.c's poke_personal.c names 0x12.  The record is
 * 0x2C bytes: seven six byte rows and a trailing halfword, and the three
 * halfwords of a row are what SHINKA_CHECK_GetRowParam's three arm switch selects between,
 * which is how the row layout is readable at all.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   0x13   the archive member kind for the evolution table.  A kind rather
 *          than a species id, so it moves only if the archive set is
 *          repacked, but it is content in the sense that nothing in the code
 *          derives it.
 *   7      the number of evolution rows per species, as the 0x2C byte record
 *          size fixes it.  A White build that gave a species an eighth
 *          evolution would change this record size and every one of these
 *          four functions with it.
 *   0x36, 0x3A   SHINKA_CHECK_KnowsMove's move id range: the four move slots of the
 *          party record, in src/matched/POKE_TOOL_GetPartyValueRaw.c's id space.  Structure
 *          rather than content, but listed because the loop bound is written
 *          as the literal 0x3A and not as "0x36 + 4".
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * SHINKA_CHECK_OpenHandle and SHINKA_CHECK_LoadData are tail calls and nothing else, eight bytes
 * of code and a pool word each
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Neither could pass a
 * fourth argument even if it wanted to, because r3 carries the target
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md); SHINKA_CHECK_LoadData
 * passes exactly three and is at the limit.
 *
 * SHINKA_CHECK_GetRowParam's switch is a `cmp`/`beq` chain and not a jump table even
 * though its three labels are dense from zero, which is the count and not the
 * density deciding it
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md records the
 * opposite direction for a seven label switch).  The record's address is held
 * in r6 across the call because it is passed to it, so `case 0` reaches the
 * row with a register offset off r6 while `case 1` and `case 2` rebuild
 * `sp + 2` and `sp + 4`: that is the member offset, not a second pointer.
 *
 * SHINKA_CHECK_KnowsMove keeps its answer in a stack slot carved out by the `r3` of the
 * prologue's `push`, and the third argument's zero is common
 * subexpression eliminated into r7 for the whole loop, which is why the
 * literal has to stay a literal at the call site rather than becoming a named
 * local.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B70C.c \
 *       --addr 0x0201B70C --thumb
 */
struct ArcHandle *SHINKA_CHECK_OpenHandle(u32 heap)
{
    return ARC_TOOL_CreateHandle(0x13, heap);
}

u32 SHINKA_CHECK_GetRowParam(struct ArcHandle *arc, u32 species, u32 rowIndex, u32 field)
{
    struct EvolutionData data;

    ARC_TOOL_ReadHandleMember(arc, species, &data);
    switch (field) {
    case 0:
        return data.rows[rowIndex].method;
    case 1:
        return data.rows[rowIndex].param;
    case 2:
        return data.rows[rowIndex].species;
    }
    return 0;
}

void SHINKA_CHECK_LoadData(u32 species, struct EvolutionRow *rows)
{
    ARC_TOOL_ReadMember(rows, 0x13, species);
}

u32 SHINKA_CHECK_KnowsMove(struct PokemonParam *pp, u32 move)
{
    u32 found;
    s32 i;

    found = 0;
    for (i = 0x36; i < 0x3A; i++) {
        if (move == POKE_TOOL_GetPartyValue(pp, i, 0)) {
            found = 1;
            break;
        }
    }
    return found;
}

/*
 *           at 0x0201B7B0, inside the compared range; every concrete byte is
 *           right.
 *
 * A three-byte-stride table entry is handed to NATSUKI_Apply along with the
 * caller's own third and fourth arguments.  Those two are forwarded
 * unchanged - they are already in r2/r3 - so no instruction moves them, and
 * that is also why the call is a real `bl` rather than a tail call: a Thumb
 * tail call spends r3 on the target address, so a four-argument call cannot
 * be one.  The 3 is lsls #1 plus adds; the table pointer is this function's
 * own pool word at 0x0201B7B0.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NATSUKI_Calc.c \
 *       --func NATSUKI_Calc --addr 0x0201B7A0 --cc 1.1p1 --thumb
 */
void NATSUKI_Calc(struct PokemonParam *pp, int type, int zoneId, u16 heap)
{
    NATSUKI_Apply(pp, &_NatsukiDeltaTable[type * 3], zoneId, heap);
}

/*
 * Three bytes are built one selector at a time - selectors 0x3C, 0x3D, 0x3E
 * - and the three-byte buffer is then handed to NATSUKI_Apply along with
 * the caller's own second and fourth arguments.  No literal pool: the only
 * pointers are the two call targets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NATSUKI_CalcUseItem.c \
 *       --func NATSUKI_CalcUseItem --addr 0x0201B7B4 --cc 1.1p1 --thumb
 */
void NATSUKI_CalcUseItem(struct PokemonParam *pp, int item, u16 zoneId, u16 heap)
{
    u8 deltas[3];
    int i;

    for (i = 0; i < 3; i++) {
        deltas[i] = (u8)FILE_UTIL_Get_0FE4(item, (u16)(i + 0x3C), heap);
    }
    NATSUKI_Apply(pp, (const s8 *)deltas, zoneId, heap);
}

/*
 * shinka_check.c.  The coin-flip sibling of NATSUKI_Calc / NATSUKI_CalcParty:
 * on an even draw below 2, hand the fixed row _NatsukiWalkDeltas to NATSUKI_Apply.
 *
 * The `movs r1,#0 / lsls r1,r1,#1 / lsrs r0,r0,#31 / orrs` run that four
 * waves read as a scheduling tie of two u32 shifts is the high word of a
 * 64-bit product: the draw widened to u64, times 2, shifted right 32 (the
 * random-below-N idiom, docs/idioms/random-below-n-is-a-64-bit-multiply-high.md,
 * with N = 2).  The zero high half is shifted left by one and ORed with the
 * low half's carry-out bit; the compiler emits the two halves in that order,
 * which is the order no u32 spelling could reach.  `% 2 == 0` gives the
 * `tst` against 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NATSUKI_CalcWalk.c \
 *       --func NATSUKI_CalcWalk --addr 0x0201B7EC --cc 1.1p1 --thumb
 */
void NATSUKI_CalcWalk(struct PokemonParam *pp, int zoneId, u16 heap)
{
    if ((u32)((u64)GF_STANDARD_Rand() * 2 >> 32) % 2 == 0) {
        NATSUKI_Apply(pp, _NatsukiWalkDeltas, zoneId, heap);
    }
}

/*
 * was-blocked: 0209E462.  The `literal` class still refuses it -- the only
 *           pool word in the image holding 0x0209E462 is this function's own,
 *           at 0x0201B84C, inside the compared range.  The site resolves as
 *           `sole-ref` instead, so the entry is EXACT and not MATCH.
 *
 * for (i = 0; i < count(a0); i++) NATSUKI_Apply(entry(a0, i), &_NatsukiPartyDeltas,
 * a1, a2); - the entry pointer the loop computes is what feeds the second
 * call's first argument, which is why no `r0 = a0` copy appears in front of
 * it (the returned r0 is already the argument), and the bound is
 * re-evaluated at the bottom of the loop so it stays a call in the
 * condition.  The table pointer is this function's own pool word at
 * 0x0201B84C, behind the C0 46 alignment filler at 0x0201B84A.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NATSUKI_CalcParty.c \
 *       --func NATSUKI_CalcParty --addr 0x0201B818 --cc 1.1p1 --thumb
 */
void NATSUKI_CalcParty(struct Party *party, int zoneId, u16 heap)
{
    int i;

    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        NATSUKI_Apply(POKEPARTY_GetMember(party, i), _NatsukiPartyDeltas, zoneId, heap);
    }
}

/*
 * Applies an EV/stat-like gain to party record id 9, scaled by a per-band
 * table the caller supplies.  The species read (id 0xAB) gates the whole
 * body: species 0 and species 650 both return early.
 *
 * The band index `idx` doubles as the literal zero argument of the three
 * POKE_TOOL_GetPartyValue reads, which is why it is a named u8 initialised before the
 * species call rather than three separate `0` literals; and the two
 * increments must be spelled `idx++` (post-increment), not `idx = idx + 1`,
 * or the compiler proves idx is still 0 at the first band test and folds it
 * to `movs r5, #1`, costing the `adds/lsls/lsrs` triple.
 *
 * The function returns void: an `int` return adds a `movs r0, #0` before the
 * epilogue.
 *
 * VERSION SENSITIVITY: 650 is a species id and 0xAB / 6 / 9 / 0x96 / 0x98 are
 * party-record ids; both are content numbering and should be re-read for a
 * White build.  0x35 is the value FILE_UTIL_Get_0FE4 returns for one particular
 * kind and is content numbering too.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/NATSUKI_Apply.c \
 *       --func NATSUKI_Apply --addr 0x0201B850 --cc 1.1p1 --thumb
 *   python tools/match.py tu --src src/matched/NATSUKI_Apply.c \
 *       --addr 0x0201B850 --thumb
 */
void NATSUKI_Apply(struct PokemonParam *pp, const s8 *deltas, int zoneId, u16 heap)
{
    int placeId;
    u32 species;
    u32 holdEffect;
    int friendship;
    int delta;
    u8 band;

    placeId = ZONEDATA_GetPlaceNameId(zoneId);
    band = 0;
    species = (u16)POKE_TOOL_GetPartyValue(pp, 0xAB, 0);
    if (species == 0 || species == 650) {
        return;
    }
    holdEffect = (u8)FILE_UTIL_Get_0FE4((u16)POKE_TOOL_GetPartyValue(pp, 6, band), 1, heap);
    friendship = POKE_TOOL_GetPartyValue(pp, 9, band);

    if (friendship >= 100) {
        band++;
    }
    if (friendship >= 200) {
        band++;
    }
    delta = deltas[band];
    if (delta > 0) {
        if (POKE_TOOL_GetPartyValue(pp, 0x98, 0) == 11) {
            delta = delta + 1;
        }
    }
    if (placeId != 0 && delta > 0) {
        if (placeId == (int)POKE_TOOL_GetPartyValue(pp, 0x96, 0)) {
            delta = delta + 1;
        }
    }
    if (delta > 0 && holdEffect == 0x35) {
        delta = delta * 150 / 100;
    }
    friendship = friendship + GPOWER_ApplyFriendshipBonus(delta);
    if (friendship < 0) {
        friendship = 0;
    }
    if (friendship > 255) {
        friendship = 255;
    }
    POKE_TOOL_SetPartyValue(pp, 9, friendship);
    return;
}

/*
 * A single function, matched as a byte range because the function after it is
 * a near miss and a committed range has to be EXACT end to end.
 *
 * pokeparty.c's "is this move slot short of PP" predicate: 78 bytes, three
 * reads of the party record and one call into the PP table.
 *
 * The three ids it reads are three parallel runs of the record's id space,
 * one per move slot: 0x36 + slot is the move, 0x3A + slot its current PP and
 * 0x3E + slot its PP ups.  src/matched/unit_0201C158.c turns the last two of
 * those into the slot's maximum, and the answer is whether the current PP is
 * below it.
 *
 * It stands alone rather than inside a unit with its neighbours because
 * POKE_TOOL_RestorePP, which sits immediately after it, is a documented near miss
 * (docs/notes/POKE_TOOL_RestorePP.c.txt) and a range cannot be committed while any
 * part of it is short of EXACT.  Its own single caller, POKE_TOOL_HealFull at
 * 0x0201BA18, is parked in src/pending/unit_0201B9F0.c and resolves this
 * address through the `matched` class off this entry.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x36, 0x3A and 0x3E are party
 * record ids in src/matched/POKE_TOOL_GetPartyValueRaw.c's space, and the three are written
 * out as three separate literals rather than derived from one base, so a
 * version that inserted a field into that id space would move all three
 * independently.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The function has two epilogues and only the second truncates the result.
 * That is what says the early exit returns the result *variable* while it is
 * still provably zero rather than the literal zero: `return 0;` would be a
 * `movs r0, #0` where the original copies r5, and a shared exit would need the
 * two tests to be one conjunction, which they cannot be because the second one
 * depends on the first's call
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * The result variable is therefore wider than the return type: declared `u8`
 * it needs no truncation at the tail and the function is two bytes short.
 *
 * The third id is built by advancing r7 in place (`adds r7, #0x3e` over the
 * register that held the slot), which is the last use of the slot number and
 * not a separate pointer.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_IsPPRestorable.c \
 *       --func POKE_TOOL_IsPPRestorable --addr 0x0201B920 --cc 1.1p1
 */
u8 POKE_TOOL_IsPPRestorable(struct PokemonParam *pp, u32 slot)
{
    u16 move;
    u8 curPP;
    u8 ppUp;
    u32 result;

    result = 0;
    move = (u16)POKE_TOOL_GetPartyValue(pp, slot + 0x36, 0);
    if (move == 0) {
        return result;
    }
    curPP = (u8)POKE_TOOL_GetPartyValue(pp, slot + 0x3A, 0);
    ppUp = (u8)POKE_TOOL_GetPartyValue(pp, slot + 0x3E, 0);
    if (curPP < WAZA_TOOL_GetMaxPP(move, ppUp)) {
        result = 1;
    }
    return result;
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`id = slot;` before `id = slot + 0x3A;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * pokeparty.c.  Restore PP to one move slot: read the move (0x36 + slot),
 * its current PP (0x3A + slot) and its PP ups (0x3E + slot), ask
 * WAZA_TOOL_GetMaxPP for the slot's maximum, and if the slot is short either fill
 * it (amount 0x7F) or add `amount` and clamp at the maximum.
 *
 * The last register copy (`adds r2, r4, #0` ahead of POKE_TOOL_SetPartyValue, the new
 * PP kept in r4 where the old one lived) is the compound assignment
 * `pp += (u8)amount`: the spelled-out `pp = (u8)(pp + (u8)amount)` starts a
 * new value that coalesces straight into the argument register (wave 15;
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-
 * the-cached-load.md is the same lever on a field).  WAZA_TOOL_GetMaxPP returns a
 * u8, so `max` is u8 (wave 14).  The dead store `id = slot` is the image's
 * `str r0, [sp]` before the add.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_RestorePP.c \
 *       --func POKE_TOOL_RestorePP --addr 0x0201B970 --thumb
 */
u32 POKE_TOOL_RestorePP(struct PokemonParam *pp, u32 slot, u32 amount)
{
    u16 move;
    u32 ppId;
    u8  curPP;
    u32 ppUp;
    u8  maxPP;

    move = (u16)POKE_TOOL_GetPartyValue(pp, slot + 0x36, 0);
    if (move == 0) {
        return 0;
    }
    ppId = slot + 0x3A;
    curPP = (u8)POKE_TOOL_GetPartyValue(pp, ppId, 0);
    ppUp = POKE_TOOL_GetPartyValue(pp, slot + 0x3E, 0);
    maxPP = WAZA_TOOL_GetMaxPP(move, (u8)ppUp);
    if (curPP < maxPP) {
        if (amount == 0x7F) {
            curPP = maxPP;
        } else {
            curPP += (u8)amount;
            if (curPP > maxPP) {
                curPP = maxPP;
            }
        }
        POKE_TOOL_SetPartyValue(pp, ppId, curPP);
        return 1;
    }
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * pokeparty.c's healer: POKE_TOOL_HealFull restores one Pokemon (current HP to its
 * maximum, status to zero, and every move slot that is short of PP back to
 * full), and POKE_TOOL_HealParty runs it over every occupied slot of a party.
 * POKE_TOOL_HealParty is the packet's only entry point, reached from 0x02011062.
 *
 * Both of its calls into the neighbouring functions resolve, and the second one
 * is the interesting one.  0x0201B920 is covered by src/matched/
 * unit_0201B920.c, so the `matched` class would carry it on its own;
 * 0x0201B970 is a near miss (docs/notes/POKE_TOOL_RestorePP.c.txt) and has no matched
 * entry at all, and the only `bl` to it inside arm9_main is the one in this
 * file.  What attests it is an overlay: ov118 branches to 0x0201B970 at
 * 0x021BE4D0, and to 0x0201B920 at 0x021BDF2A, and those are real instructions
 * outside the compared range, which is exactly what the `label` class asks for
 * once it reads branches from the whole image rather than from arm9 alone.
 * The two functions here would otherwise have had to be split apart or parked.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  0x7F is the "fill the slot" sentinel
 * POKE_TOOL_RestorePP tests for and has to stay in step with it; 4 is the move slot
 * count written out as the loop bound; 0xA9, 0xA0, 0xA1 and 0x9D are party
 * record ids in src/matched/POKE_TOOL_GetPartyValueRaw.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The id 0xA1 read is used directly as the id 0xA0 write's third argument with
 * nothing bound to a local, so the result reaches r2 straight out of r0; this
 * is the site where the inline spelling is the right one
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * POKE_TOOL_HealFull's `for` runs 0 to 3 with no entry guard, because the compiler
 * can see the bound; the 0x7F is hoisted into r6 in front of the loop and the
 * index's zero is set before the two writes that precede it.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201B9F0.c \
 *       --addr 0x0201B9F0 --thumb
 */
void POKE_TOOL_HealFull(struct PokemonParam *pp)
{
    s32 i;

    POKE_TOOL_SetPartyValue(pp, 0xA0, POKE_TOOL_GetPartyValue(pp, 0xA1, 0));
    POKE_TOOL_SetPartyValue(pp, 0x9D, 0);
    for (i = 0; i < 4; i++) {
        if (POKE_TOOL_IsPPRestorable(pp, i) == 1) {
            POKE_TOOL_RestorePP(pp, i, 0x7F);
        }
    }
}

void POKE_TOOL_HealParty(struct Party *party)
{
    s32 memberCount;
    s32 i;
    struct PokemonParam *member;

    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        member = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(member, 0xA9, 0) != 0) {
            POKE_TOOL_HealFull(member);
        }
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The graphics index of a Pokemon: POKE_TOOL_GetGraphicIndex unpacks the four values that
 * decide it out of the record and POKE_TOOL_CalcGraphicIndex turns them into a member number
 * of archive 7.  The pair that follows them, POKE_TOOL_CalcIconPalette and POKE_TOOL_GetIconPalette, is
 * the same index arithmetic over a different table and is parked in
 * src/pending/unit_0201BB5C.c because that table has no witness; the cut
 * between the two pairs is what lets this half land
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * POKE_TOOL_GetGraphicIndex brackets its four reads with POKE_TOOL_DecodeBoxParam and POKE_TOOL_EncodeBoxParam,
 * which is the pair the region uses around a run of raw field reads; that is
 * why the reads here are POKE_TOOL_GetBoxValue and not the POKE_TOOL_GetPartyValue of
 * src/matched/POKE_TOOL_CalcParam.c.  The fourth read is written inline as the call's
 * fourth argument rather than bound to a local, which is what puts it in r3
 * with the other three already in place.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Four content constants, and the index arithmetic that ties them together is
 * itself a statement about how the sprite archive is packed:
 *
 *   490    the species whose egg has a graphic of its own.  Every other
 *          species shares one egg graphic.
 *   650    the index the ordinary egg occupies, so 651 is that species' egg;
 *          the same 650/651 pair src/matched/unit_0201AFD4.c rejects as
 *          species ids.
 *   7      the first member of archive 7 that belongs to a species, and the
 *          stride is two members per index.
 *   1311   the member the alternate forms start at, which is 652 * 2 + 7, i.e.
 *          immediately after the two egg indices.  A White build with a
 *          different species count would move this number and only this one.
 *   0x1F, 0x20, 0x23   the three personal-record attributes POKE_TOOL_GetPersonalParam
 *          answers: the form block's first index, the form count, and the flag
 *          that says the forms are not drawn separately.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The `case 1` arm binds the archive query to a local before assigning the
 * gender.  Written inline, `gender = 1;` is hoisted in front of the `blx` and
 * six bytes come out in the wrong order; the named local is what pins the
 * order, the same way
 * docs/idioms/cmp-operand-order-names-the-temporary.md pins a comparison.
 *
 * `case 2`'s `gender = 0;` and `case 1`'s failure arm are one block, reached
 * by a `b` whose displacement is zero: the source writes the statement out in
 * both arms and the compiler cross-jumps the two copies
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).  The switch
 * is a `cmp`/`beq` chain rather than a table, because three labels are too few
 * for mwccarm to build one
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md, the other side of
 * the density rule).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BA68.c \
 *       --addr 0x0201BA68 --thumb
 */
u32 POKE_TOOL_GetGraphicIndex(struct BoxPokemon *box)
{
    u32 wasDecoded;
    u32 species;
    u32 form;
    u32 gender;
    u32 index;

    wasDecoded = POKE_TOOL_DecodeBoxParam(box);
    species = POKE_TOOL_GetBoxValue(box, 5, 0);
    form = POKE_TOOL_GetBoxValue(box, 0x6F, 0);
    gender = POKE_TOOL_GetBoxValue(box, 0x6E, 0);
    index = POKE_TOOL_CalcGraphicIndex(species, form, gender, POKE_TOOL_GetBoxValue(box, 0x4C, 0));
    POKE_TOOL_EncodeBoxParam(box, wasDecoded);
    return index;
}

u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg)
{
    u32 firstFormIndex;
    u32 formsShared;
    u32 formCount;
    u32 index;
    u32 hasFemale;

    index = species * 2 + 7;
    if (isEgg != 0) {
        index = (u32)((species == 490 ? 1 : 0) + 650) * 2 + 7;
    } else if (form != 0) {
        firstFormIndex = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x1F);
        formsShared = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x23);
        formCount = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x20);
        if (form >= formCount) {
            form = 0;
        }
        if (formsShared == 0 && form != 0) {
            index = (firstFormIndex + form - 1) * 2 + 1311;
        }
    }
    switch (gender) {
    case 0:
        break;
    case 1:
        hasFemale = ARC_TOOL_GetMemberSize(7, index + 1);
        gender = 1;
        if (hasFemale == 0) {
            gender = 0;
        }
        break;
    case 2:
        gender = 0;
        break;
    }
    return index + gender;
}

/*
 * note:     224 bytes, two functions
 *
 * The nibble-table twin of src/matched/unit_0201BA68.c: the same egg and
 * alternate-form index arithmetic, indexing a packed table of two four bit
 * values per entry instead of an archive.  POKE_TOOL_GetIconPalette unpacks the four
 * inputs out of a Pokemon record, bracketed by the POKE_TOOL_DecodeBoxParam /
 * POKE_TOOL_EncodeBoxParam pair, and hands them over.
 *
 * The index is the same logical number unit_0201BA68.c computes, one step
 * short of it: there the answer is `n * 2 + 7`, a member of archive 7, here it
 * is `n` itself, and the alternate-form case reaches it as `first + form +
 * 651` where the other reaches `(first + form - 1) * 2 + 1311`.  1311 is
 * 652 * 2 + 7, so the two agree.
 *
 * ---------------------------------------------------------------------------
 * WHY IT WAS CAPPED (HISTORY)
 * ---------------------------------------------------------------------------
 * NO LONGER CAPPED (re-verified 2026-09-22).  The pool word at 0x0201BBE4 is
 * still the only word in the image that holds 0x0209E474, so the `literal`
 * class does discard its only witness.  What closed it is the sole-ref
 * widening of 2026-09-21: 0x0209E474 is 4-aligned and starts a recognised
 * data object, so the site now resolves as `sole-ref` and the unit is EXACT.
 * The old "WHY IT IS CAPPED" reading below is kept only as history.
 *
 * The cut between this pair and POKE_TOOL_GetGraphicIndex/POKE_TOOL_CalcGraphicIndex is what let those
 * two land EXACT.  POKE_TOOL_CalcIconPalette is reached only from 0x0201BC34, inside this
 * range, so that call is the `local` class and needs no evidence.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   490    the species whose egg has an entry of its own.
 *   650    the ordinary egg's index, so 651 is that species' egg; 651 again is
 *          the base the alternate-form block is counted from.
 *   0x1F, 0x20, 0x23   the three personal-record attributes POKE_TOOL_GetPersonalParam
 *          answers: the form block's first index, the form count, and the
 *          "not drawn separately" flag.
 *   0x0209E474  the table itself, one packed byte per index.  Its contents are
 *          content and are not reproduced here.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The two returns are unequal shift pairs, not bitfields: `lsls #0x14` /
 * `lsrs #0x18` is `(u8)(x >> 4)`, because 32 - 24 is the width and 20 - 24 is
 * the shift, and the low half's equal pair is a plain `(u8)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The mask has to be written out as well as the cast; `x >> 4` on its own
 * loses the `ands`.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_0201BB5C.c \
 *       --addr 0x0201BB5C --thumb
 */
u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 female, u32 isEgg)
{
    u32 firstFormIndex;
    u32 formsShared;
    u32 formCount;
    u32 index;

    index = species;
    if (isEgg != 0) {
        index = (species == 490 ? 1 : 0) + 650;
    } else if (form != 0) {
        firstFormIndex = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x1F);
        formsShared = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x23);
        formCount = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x20);
        if (form >= formCount) {
            form = 0;
        }
        if (formsShared == 0 && form != 0) {
            index = firstFormIndex + form + 651;
        }
    }
    if (female != 0) {
        return (u8)((_IconPaletteTable[index] & 0xF0) >> 4);
    }
    return (u8)(_IconPaletteTable[index] & 0xF);
}

u32 POKE_TOOL_GetIconPalette(struct BoxPokemon *box)
{
    u32 wasDecoded;
    u32 species;
    u32 form;
    u32 gender;
    u32 isEgg;

    wasDecoded = POKE_TOOL_DecodeBoxParam(box);
    species = POKE_TOOL_GetBoxValue(box, 5, 0);
    form = POKE_TOOL_GetBoxValue(box, 0x6F, 0);
    gender = POKE_TOOL_GetBoxValue(box, 0x6E, 0);
    isEgg = POKE_TOOL_GetBoxValue(box, 0x4C, 0);
    POKE_TOOL_EncodeBoxParam(box, wasDecoded);
    return POKE_TOOL_CalcIconPalette(species, form, gender, isEgg);
}

/*
 *           POKE_TOOL_GetIconCellEntryIdSub
 *
 * Five leaves after POKE_TOOL_GetIconPalette.  The first returns 0.  The other four read
 * the OBJ character mapping bits of DISPCNT (bit 4, 1D mapping, and bits
 * 20..21, the 1D boundary) for the main engine (0x04000000) or the sub engine
 * (0x04001000) and turn the 32/64/128 KB boundary into a shift: 2/4/6 and
 * 1/3/5, with the unlisted 256 KB case falling into a separate default that
 * repeats the last value.  Seeded from ov208 0x021C5304, 0x021C531E,
 * 0x021C5324 (func_021C52F0) and ov021 0x021CC8EA, 0x021CC906, 0x021CC90C.
 *
 * Addresses are Black-image addresses.
 */
int POKE_TOOL_GetIconPaletteArcId(void)
{
    return 0;
}

int POKE_TOOL_GetIconCellArcId(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}

int POKE_TOOL_GetIconCellArcIdSub(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}

int POKE_TOOL_GetIconCellEntryId(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}

int POKE_TOOL_GetIconCellEntryIdSub(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}

/*
 * waza_tool.c: the cached single-field read of a move record, and the 32 case
 * getter it ends in.
 *
 * WAZA_TOOL_GetParam finds the move's record in the cache the constructor in
 * src/matched/unit_0201C328.c builds, loading it through ARC_TOOL_ReadMember if the
 * slot it picks is empty or is holding a different move, and falls back to
 * the single record buffer at 0x02146534 when the cache has not been built.
 * The slot search, the "cache full, reuse the last slot" fixup and the load
 * are the same three blocks WAZA_TOOL_IsAlwaysHit and WAZA_TOOL_GetRankEffectCount repeat for their
 * own records.
 *
 * WAZA_TOOL_GetDataParam has to stay in this file.  The `bl` at 0x0201BDA6 is the only
 * branch to it anywhere in the image, so split off it would have no witness
 * at all; kept here the site is the `local` class and needs none
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, read the
 * other way round).
 *
 * The getter is an ordinary dense switch: `cmp #0x1F` / `bhi` and a table of
 * 32 signed halfword displacements
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  Two things
 * the table says that the C has to repeat exactly:
 *
 *   * entry 29 points at the default body, so id 29 has no case label at all.
 *     It is a gap in the middle of the range and not an empty arm, which is
 *     the distinction docs/idioms/empty-switch-arms-are-what-make-the-table.md
 *     draws;
 *   * the arms are emitted in source order, and that order is not the numeric
 *     order: id 28 is written between 15 and 16, and the three three-way
 *     groups (16, 19, 22), (17, 20, 23) and (18, 21, 24) share one body each.
 *
 * The three grouped bodies index byte arrays at +0x15, +0x18 and +0x1B with a
 * run-time index, so the middle one costs a `movs`/`ldrsb` register-offset
 * pair rather than an immediate load, which is the only thing that says that
 * field is signed (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Ids 4 and 7 answer a substitute value for one particular stored value,
 * 0x64 for 0x65 and 0 for 6; both reach the function's shared `bx lr` with
 * the loaded value still in r0, which is what says the source returns the
 * value in the ordinary path rather than assigning a result variable.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BD28.c \
 *       --addr 0x0201BD28 --thumb
 */
u32 WAZA_TOOL_GetParam(u16 move, u32 param)
{
    struct WazaData *data;
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    return WAZA_TOOL_GetDataParam(data, param);
}

u32 WAZA_TOOL_GetDataParam(const struct WazaData *data, u32 param)
{
    u32 value;

    switch (param) {
    case 0:  return data->type;
    case 1:  return data->category;
    case 2:  return data->damageType;
    case 3:  return data->power;
    case 4:
        value = data->accuracy;
        if (value == 0x65) {
            return 0x64;
        }
        return value;
    case 5:  return data->basePP;
    case 6:  return data->priority;
    case 7:
        value = data->criticalRank;
        if (value == 6) {
            return 0;
        }
        return value;
    case 8:  return data->hitMax;
    case 9:  return data->hitMin;
    case 10: return data->shrinkPercent;
    case 11: return data->sickId;
    case 12: return data->sickPercent;
    case 13: return data->sickContType;
    case 14: return data->sickTurnMin;
    case 15: return data->sickTurnMax;
    case 28: return data->effectSequence;
    case 16: case 19: case 22:
        return data->rankType[param - 16];
    case 17: case 20: case 23:
        return data->rankValue[param - 17];
    case 18: case 21: case 24:
        return data->rankPercent[param - 18];
    case 25:
        if (data->drainRatio > 0) {
            return data->drainRatio;
        }
        return 0;
    case 30:
        if (data->drainRatio < 0) {
            return -data->drainRatio;
        }
        return 0;
    case 26:
        if (data->healRatio > 0) {
            return data->healRatio;
        }
        return 0;
    case 31:
        if (data->healRatio < 0) {
            return -data->healRatio;
        }
        return 0;
    case 27: return data->target;
    }
    return 0;
}

u32 WAZA_TOOL_GetFlag(u16 move, u32 flag)
{
    struct WazaData *data;
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    return WAZA_TOOL_GetDataFlag(data, flag);
}

u32 WAZA_TOOL_GetDataFlag(const struct WazaData *data, u32 flag)
{
    u32 result = 1;

    if ((data->flags & (1 << flag)) != 0) {
        return result;
    }
    result = 0;
    return result;
}

s16 WAZA_TOOL_GetSickCont(u16 move)
{
    struct WazaData *data;
    s32 i;
    union WazaSickCont cont;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    if (data->sickContType != 0) {
        cont.bits.type = data->sickContType;
        cont.bits.turnMin = data->sickTurnMin;
        cont.bits.turnMax = data->sickTurnMax;
    }
    return cont.value;
}

/*
 * waza_tool.c: two more readers over a move record, each with its own copy of
 * the cache lookup src/matched/unit_0201BD28.c and
 * src/matched/unit_0201C1F4.c also carry.  WAZA_TOOL_GetRankEffectCount counts how many of
 * the three bytes at +0x15 are set; WAZA_TOOL_GetRankEffect hands one of the three
 * signed bytes at +0x18 back through an out-parameter, or zero when the
 * matching +0x15 byte is clear.
 *
 * The +0x18 read is a `movs`/`ldrsb` register-offset pair because the index
 * is a run-time value and Thumb has no immediate-offset `ldrsb`, which is
 * also the only evidence that the field is signed where its +0x15 neighbour
 * is not (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C020.c  *       --addr 0x0201C020 --thumb
 */
u8 WAZA_TOOL_GetRankEffectCount(u16 move)
{
    struct WazaData *data;
    s32 i;
    u32 k;
    u32 rankCount;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    rankCount = 0;
    for (k = 0; k < 3; k++) {
        if (data->rankType[k] != 0) {
            rankCount++;
        }
    }
    return (u8)rankCount;
}

u8 WAZA_TOOL_GetRankEffect(u16 move, u32 index, s32 *value)
{
    struct WazaData *data;
    s32 i;
    u8 rankType;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    rankType = data->rankType[index];
    if (rankType != 0) {
        *value = data->rankValue[index];
    } else {
        *value = 0;
    }
    return rankType;
}

/*
 * waza_tool.c: the effective PP calculation, a four-entry id translation and
 * one more named field read.
 *
 * WAZA_TOOL_GetMaxPP is the function src/pending/POKE_TOOL_GetBoxValueRaw.c's field map calls
 * for ids 0x42 to 0x45: base PP (field 5 of the move record, through
 * src/matched/unit_0201BD28.c) plus base * 20 * ppUp / 100, with ppUp clamped
 * to 3 and every intermediate truncated to u8.  The two `muls` are one
 * expression and their order is the source's: the clamped count multiplies
 * the already-scaled base, not the other way round
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * The clamp compares unsigned (`bls`) while the division calls _s32_div_f,
 * so the count is an unsigned parameter and the product is cast to `int`
 * before the divide; written unsigned throughout, every concrete byte is
 * still right and the call goes to _u32_div_f instead, which is a different
 * address and a DIFF.
 *
 * WAZA_TOOL_GetWeather is a sparse four-case switch, which this front end lowers as a
 * binary search rather than a table: `> 0xF1`, then `< 0xF0`, then the two
 * equality tests.  The bodies are still emitted in source order, so the arms
 * are written 0xF0, 0xF1, 0xC9, 0x102 even though the comparisons are in
 * value order, and the value is signed: the two range tests are `bgt`/`blt`,
 * so the parameter is `int` and not `u32`.  0x102 arrives from a pool word because it is past the 255 a
 * `movs` immediate reaches.
 *
 * VERSION SENSITIVITY: 0xF0, 0xF1, 0xC9 and 0x102 are content ids (moves or
 * items), not offsets.  They are expected to be the same in Pokemon White,
 * which shares Black's numbering, but they are the constants to re-read first
 * if a White build diverges here.
 *
 * WAZA_TOOL_GetCategory is an unlabelled tail call, three instructions and two pool
 * words (docs/idioms/tail-call-is-a-pool-word-and-bx.md), reading field 1.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C158.c \
 *       --addr 0x0201C158 --thumb
 */
u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp)
{
    u8 basePP;

    if (ppUp > 3) {
        ppUp = 3;
    }
    basePP = (u8)WAZA_TOOL_GetParam(move, 5);
    return (u8)(basePP + (u8)((int)(ppUp * (basePP * 20)) / 100));
}

u32 WAZA_TOOL_GetWeather(int item)
{
    switch (item) {
    case 0xF0:  return 2;
    case 0xF1:  return 1;
    case 0xC9:  return 4;
    case 0x102: return 3;
    }
    return 0;
}

u32 WAZA_TOOL_GetCategory(u16 move)
{
    return WAZA_TOOL_GetParam(move, 1);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Two truncating wrappers around WAZA_TOOL_GetParam (0x0201BD28, still open, a
 * getter dispatched by a small id constant), one narrowing the result to a
 * byte for id 0, the other to a halfword for id 3.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C1C8.c \
 *       --addr 0x0201C1C8 --thumb
 */
u8 WAZA_TOOL_GetType(u16 move)
{
    return (u8)WAZA_TOOL_GetParam(move, 0);
}

u16 WAZA_TOOL_GetPower(u16 move)
{
    return (u16)WAZA_TOOL_GetParam(move, 3);
}

/*
 * Tail call with argument 2. Filed as the witness for ov094 BTLV_EFFECT_StartDamageTintTask.
 */
int WAZA_TOOL_GetDamageType(u16 move)
{
    return WAZA_TOOL_GetParam(move, 2);
}

/*
 * waza_tool.c: two predicates over a move record, "is field 4 equal to 0x65"
 * and "is field 0x0E equal to 6", which are the same two special values
 * src/matched/unit_0201BD28.c's getter substitutes for at ids 4 and 7.
 *
 * Both carry their own copy of that file's cache lookup rather than calling
 * it: the slot search, the "cache full, reuse the last slot" fixup, the
 * ARC_TOOL_ReadMember load and the not-yet-built fallback to 0x02146534 are written
 * out again in each.  The duplication is in the source, not an inlining
 * decision: WAZA_TOOL_GetParam is a real function with eight callers, and the
 * bodies here reach the record directly instead of going through its
 * 32 case getter.
 *
 * VERSION SENSITIVITY: 0x65 and 6 are content ids of the move table, not
 * offsets.  They are expected to be identical in Pokemon White but are the
 * constants to re-read first if a White build diverges.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C1F4.c \
 *       --addr 0x0201C1F4 --thumb
 */
u32 WAZA_TOOL_IsAlwaysHit(u16 move)
{
    struct WazaData *data;
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    if (data->accuracy == 0x65) {
        return 1;
    }
    return 0;
}

u32 WAZA_TOOL_IsAlwaysCritical(u16 move)
{
    struct WazaData *data;
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    if (data->criticalRank == 6) {
        return 1;
    }
    return 0;
}

/*
 * A boolean wrapper around WAZA_TOOL_GetParam (see src/matched/unit_0201C1C8.c),
 * id 3 again, this time reduced to 0/1 rather than truncated to a halfword.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C314.c \
 *       --addr 0x0201C314 --thumb
 */
u32 WAZA_TOOL_IsDamaging(u16 move)
{
    if (WAZA_TOOL_GetParam(move, 3) == 0) {
        return 0;
    }
    return 1;
}

/*
 * waza_tool.c: the module's constructor, its destructor, its "is it up"
 * predicate, and (folded back in this run) PRINTSYS_Init, which resets
 * something with 0xFFFF and hands BMP_Create's result to the static at
 * 0x02146558.  PRINTSYS_Init used to be cut out into src/pending/PRINTSYS_Init.c
 * because its one call, to STRBUF_SetEosChar, had no witness anywhere in the
 * image; STRBUF_SetEosChar is now EXACT in src/matched/STRBUF_SetEosChar.c, giving the
 * `matched` class a witness, so the range folds back into one unit.  The file
 * name is the image's own, 0x020A7340 spelling "waza_tool.c" between
 * "shinka_check.c" and "printsys.c".
 *
 * The module object at 0x02146530 is three words: an array of `n` pointers to
 * 0x24 byte records, an array of `n` halfwords, and `n` itself.  Each of the
 * four allocations passes a different __LINE__, and the four values 577, 578,
 * 579 and 584 are visible in the bytes as one pool word holding 577 and three
 * `adds r0, r0, #k` off it, which is what fixes both the line numbers and the
 * order of the statements.  577 is too large for a `movs` immediate, so the
 * first one is a pool word rather than a relocation
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md is the
 * case where it is the other way round).
 *
 * WAZA_TOOL_IsCacheCreated is an unlabelled follower: eight halfwords with no prologue
 * sitting between two literal pools, which the listing prints as `.word` data
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Its `!= 0`
 * arm is the fall-through, so the source returns 1 first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C328.c \
 *       --addr 0x0201C328 --thumb
 */
void WAZA_TOOL_CreateCache(s32 count, u32 heap)
{
    s32 i;

    if (_pWazaTool != 0) {
        return;
    }
    _pWazaTool = (struct WazaTool *)GFL_HEAP_Alloc(heap, sizeof(struct WazaTool), 0,
                                                waza_tool_File, 577);
    _pWazaTool->records = (struct WazaData **)GFL_HEAP_Alloc(heap, count * sizeof(void *), 0,
                                             waza_tool_File, 578);
    _pWazaTool->moveIds = (u16 *)GFL_HEAP_Alloc(heap, count * sizeof(u16), 0,
                                           waza_tool_File, 579);
    _pWazaTool->count = count;
    for (i = 0; i < count; i++) {
        _pWazaTool->records[i] = GFL_HEAP_Alloc(heap, 0x24, 0, waza_tool_File, 584);
        _pWazaTool->moveIds[i] = 0;
    }
}

void WAZA_TOOL_DeleteCache(void)
{
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            GFL_HEAP_Free(_pWazaTool->records[i]);
        }
        GFL_HEAP_Free(_pWazaTool->moveIds);
        GFL_HEAP_Free(_pWazaTool->records);
        GFL_HEAP_Free(_pWazaTool);
        _pWazaTool = 0;
    }
}

u32 WAZA_TOOL_IsCacheCreated(void)
{
    if (_pWazaTool != 0) {
        return 1;
    }
    return 0;
}

void PRINTSYS_Init(u32 heap)
{
    STRBUF_SetEosChar(0xFFFF);
    _pGlyphBmp = BMP_Create(2, 2, 0x20, heap);
}

/*
 * A 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), swapping its own
 * parameter into the callee's second argument slot and passing the literal
 * 0x400 as the first: `PRINTSYS_QUE_CreateEx(0x400, p)`.  PRINTSYS_QUE_CreateEx (0x0201C450)
 * is a bigger constructor with an inline division-by-multiplication trick
 * and is left as an unresolved extern; only its address is needed here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C440.c \
 *       --addr 0x0201C440 --thumb
 */
struct PrintQueue *PRINTSYS_QUE_Create(u32 heap)
{
    return PRINTSYS_QUE_CreateEx(0x400, heap);
}

/*
 * The head of printsys.c: the module constructor and three accessors on the
 * object it builds.  The file identity is in the image, the same way
 * src/matched/unit_0201D69C.c recovers gf_font.c: the constructor loads
 * 0x020A734C as the debug allocator's __FILE__ argument and the bytes there
 * spell "printsys.c", with "waza_tool.c" ending at 0x020A734B so the `string`
 * class carries the address.  The __LINE__ argument is 287.
 *
 * The constructor was a documented two-byte near miss and this is what closed
 * it: the field at +8 is one `u64`, not two `u32`.  Written as two words the
 * whole function is right except that the pool constant 0x1130 arrives in r1
 * instead of r2; assigning it to a 64 bit field makes the compiler take the
 * other scratch register, because the high half comes from the register that
 * already holds zero.  See
 * docs/idioms/a-u64-field-store-picks-a-different-scratch-register.md.
 *
 * PRINTSYS_QUE_SetLimitTick writes the two halves of that u64 separately, which is what
 * fixes the field as a union of the 64 bit value and a two-word struct rather
 * than a plain `u64` (docs/idioms/long-long-aligns-to-four.md is why +8 is a
 * legal offset for it at all).
 *
 * The size the constructor allocates is (u16)(n + 0x1C) rounded up to a
 * multiple of four and then + 0x18, and the rounding is a `while (v % 4)` loop
 * over a `u16` local: the signed `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * quartet is `% 4` on the promoted int, exactly as src/matched/sub_0200A6BC.c
 * records for `% 8`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C450.c \
 *       --addr 0x0201C450 --thumb
 */
struct PrintQueue *PRINTSYS_QUE_CreateEx(u16 bufSize, u32 heap)
{
    u16 allocSize = bufSize + 0x1C;
    struct PrintQueue *queue;

    while (allocSize % 4 != 0) {
        allocSize++;
    }
    queue = GFL_HEAP_Alloc(heap, allocSize + 0x18, 0, printsys_File, 287);
    queue->capacity = bufSize;
    queue->limitTicks.value = 0x1130;
    queue->job = 0;
    queue->cursor = 0;
    queue->state.raw = queue->state.raw & ~0xFu;
    queue->state.raw = queue->state.raw & ~0xF0u;
    queue->frameCount = 0;
    queue->head = 0;
    queue->tail = bufSize;
    return queue;
}

void PRINTSYS_QUE_Delete(struct PrintQueue *queue)
{
    GFL_HEAP_Free(queue);
}

void PRINTSYS_QUE_SetForceQueue(struct PrintQueue *queue, u32 forceQueue)
{
    queue->state.raw = (queue->state.raw & ~0xF0u) | (u8)((u8)forceQueue << 4);
}

void PRINTSYS_QUE_SetLimitTick(struct PrintQueue *queue, u32 tickLow, u32 tickHigh)
{
    queue->limitTicks.half.low = tickLow;
    queue->limitTicks.half.high = tickHigh;
}

static inline u16 PrintQueue_WrapOffset(struct PrintQueue *queue, u16 offset)
{
    u16 result = offset;

    if (result >= queue->capacity)
        result = 0;
    return result;
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = (u8 *)ps;` before `base = (u8 *)ps + 0x18;`). Game code has no
 * line table, so these were stand-ins. The plain single assignment gives
 * EXACT in --lang c99 and --lang c: the output bytes do not change. Older
 * text in this header that asks for the double assignment is superseded.
 *
 * printsys.c: the per-frame print pump.  Bumps the frame counter at +6,
 * saves the current text colour, applies the head request's colour when its
 * 4-bit kind is 0 or 2, then runs glyphs through PRINTSYS_PrintStep until the
 * string ends or the tick budget at +8 (OS_GetTick is OS_GetTick) runs
 * out.  On string end it pops the request (GF_FONT_UpdatePrintsy) and moves the
 * glyph cursor to the next record's text in the byte ring at +0x18,
 * wrapping twice at the ring size.  Restores the colour and reports idle.
 *
 * The last five bytes closed on the SHAPE OF THE INLINE WRAP HELPER: it
 * copies its parameter into a named local, conditionally zeroes the local
 * and returns it (`u16 r = o; if (r >= size) r = 0; return r;`).  The
 * early-return spelling (`if (o >= size) return 0; return o;`) truncates
 * `off + 0x1C` in place and hoists the ring-size load between the two
 * shifts; the named-local spelling keeps the image's
 * `lsls r0, r7 / lsrs r1, r0 / ldrh r0, [r5, #4]` order.  History in
 * docs/notes/PRINTSYS_QUE_Main.c.txt.
 */
u32 PRINTSYS_QUE_Main(struct PrintQueue *queue)
{
    
    u8  color[3];
    u32 timedOut;
    u16 savedColor;
    u32 jobLetter;
    u32 jobBackground;
    u8 *ring;
    u32 letter;
    u32 shadow;
    u32 background;
    u32 applyColor;
    u32 jobShadow;
    u32 jobOffset;
    u16 offset;
    u64 startTick;

    timedOut = 0;
    queue->frameCount = (u8)(queue->frameCount + 1);
    if (queue->job == 0) {
        return 1;
    }
    GF_FONT_GetTextColor(&color[2], &color[1], &color[0]);
    savedColor = (u16)(((color[2] & 0x1F) << 10) | ((color[1] & 0x1F) << 5) |
                  (color[0] & 0x1F));
    applyColor = 0;
    if (queue->job->pos.bits.colorMode == 0 || queue->job->pos.bits.colorMode == 2) {
        letter = (u8)((queue->job->activeColor >> 10) & 0x1F);
        shadow = (u8)((queue->job->activeColor >> 5) & 0x1F);
        background = (u8)(queue->job->activeColor & 0x1F);
        applyColor = 1;
    }
    if (applyColor != 0) {
        if (GF_FONT_IsTextColorDifferent(letter, shadow, background) != 0) {
            GF_FONT_SetTextColor(letter, shadow, background);
        }
    }
    startTick = OS_GetTick();
    if (queue->job != 0) {
        ring = queue->data;
        do {
            if (queue->job->pos.bits.colorMode == 1) {
                jobLetter = (u8)((queue->job->activeColor >> 10) & 0x1F);
                jobShadow = (u8)((queue->job->activeColor >> 5) & 0x1F);
                jobBackground = (u8)(queue->job->activeColor & 0x1F);
                if (GF_FONT_IsTextColorDifferent(jobLetter, jobShadow, jobBackground) != 0) {
                    GF_FONT_SetTextColor(jobLetter, jobShadow, jobBackground);
                }
                queue->job->pos.bits.colorMode = 2;
            }
            while (queue->cursor[0] != 0xFFFF) {
                queue->cursor = PRINTSYS_PrintStep(queue->job, queue->cursor, 1);
                if (OS_GetTick() - startTick > queue->limitTicks.value) {
                    timedOut = 1;
                    break;
                }
            }
            if (queue->cursor[0] == 0xFFFF) {
                jobOffset = (u16)((u8 *)queue->job - ring);
                queue->job = GF_FONT_UpdatePrintsy(queue, queue->job);
                if (queue->job != 0) {
                    offset = PrintQueue_WrapOffset(queue, jobOffset + 0x1C);
                    offset = PrintQueue_WrapOffset(queue, offset + 4);
                    queue->cursor = (u16 *)(queue->data + offset);
                }
            }
        } while (timedOut == 0 && queue->job != 0);
    }
    GF_FONT_SetTextColor((u8)((savedColor >> 10) & 0x1F), (u8)((savedColor >> 5) & 0x1F),
                  (u8)(savedColor & 0x1F));
    if (queue->job != 0) {
        queue->tail = (u16)((u8 *)queue->cursor - queue->data);
        return 0;
    }
    queue->head = 0;
    queue->tail = queue->capacity;
    queue->state.bits.pending = 0;
    return 1;
}

u32 PRINTSYS_QUE_IsFinished(const struct PrintQueue *queue)
{
    if (queue->job == 0) {
        return 1;
    }
    return 0;
}

u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp)
{
    struct PrintCtx *job = queue->job;

    if (job != 0) {
        while (job != 0) {
            if (job->bmp == bmp) {
                return 1;
            }
            job = GF_FONT_UpdatePrintsy(queue, job);
        }
    }
    return 0;
}

void PRINTSYS_QUE_Clear(struct PrintQueue *queue)
{
    queue->head = 0;
    queue->tail = queue->capacity;
    queue->cursor = 0;
    queue->job = 0;
}

/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     168 bytes, three functions
 *
 * printsys.c's two public print entry points and the dispatcher they share.
 * PRINTSYS_SubmitJob decides between drawing straight away and queueing the request
 * into the ring: when the module is not busy and the flags nibble in the byte
 * at +7 is clear it calls PRINTSYS_RunJob directly, otherwise it queues with
 * GF_FONT_CopyStrbufD6D8 provided the request fits in the free space GF_FONT_GetQueueLength
 * reports.
 *
 * Why it is capped: the `bl` at 0x0201C79C is the only branch to GF_FONT_CopyStrbufD6D8
 * anywhere in the image, and no pool word holds the address either, so the
 * `label` class has no witness once the compared range holds that call.  No
 * cut helps, because the range cannot be made smaller than PRINTSYS_SubmitJob and
 * the call is inside it.  The `matched` class would carry it, but
 * GF_FONT_CopyStrbufD6D8 is not matched: it is EXACT only in a range that also holds
 * GF_FONT_Copy, and GF_FONT_Copy is four bytes short (the original spills
 * the byte counter and keeps the ring cursor in a callee-saved register; every
 * source shape tried makes the opposite choice).  See the header of
 * src/matched/unit_0201D7C4.c.
 *
 * It closes the day GF_FONT_Copy's register allocation is reproduced, which
 * makes GF_FONT_CopyStrbufD6D8 an EXACT entry and the `matched` class applies.
 *
 * PRINTSYS_SubmitJob's busy test is normalised to 0 or 1 before it is used, which is
 * what a `!= 0` assigned to a local gives; the flags nibble is read as a four
 * bit unsigned bitfield, `((u32)((u8 *)p)[7] << 24) >> 28`, the same spelling
 * src/matched/unit_0201CE5C.c needs for a one bit field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_0201C6FC.c \
 *       --addr 0x0201C6FC --thumb
 */
void PRINTSYS_PrintQue(struct PrintQueue *queue, struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font)
{
    PRINTSYS_SetupJob(&_PrintJobWork, font, bmp, x, y);
    PRINTSYS_SubmitJob(queue, &_PrintJobWork, str);
}

void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font,
                  u16 color)
{
    PRINTSYS_SetupJob(&_PrintJobWork, font, bmp, x, y);
    PRINTSYS_SetJobColor(&_PrintJobWork, color);
    PRINTSYS_SubmitJob(queue, &_PrintJobWork, str);
}

void PRINTSYS_SubmitJob(struct PrintQueue *queue, struct PrintCtx *job, struct Strbuf *str)
{
    u32 busy = GFL_NET_GetNegotiationNum() != 0;
    u32 size;

    if (busy == 0 && queue->state.bits.forceQueue == 0) {
        PRINTSYS_RunJob(job, str);
        return;
    }
    size = GF_FONT_GetAllocSize(str);
    if (size <= GF_FONT_GetQueueLength(queue)) {
        GF_FONT_CopyStrbufD6D8(queue, job, str);
    }
}

/*
 * A printsys entry point: builds the shared print request in the static
 * scratch through PRINTSYS_SetupJob and hands it to PRINTSYS_RunJob with the
 * string object.  The leading STRBUF_GetChars(s) call's result is unused.
 *
 * Withdrawn 2026-09-24 (wave 20, lane 20G): the ../2.0/sp2 pin is retired.
 * The scratch address is held as an integer, a u32 local assigned
 * (u32)&_PrintJobWork and cast back at each site, matching PRINTSYS_PrintColor.c.
 * Spelled this way, dsi/1.1p1 caches the address in a callee-saved
 * register and copies it into r0 at each site, byte-exact under the
 * default compiler.
 */
void PRINTSYS_Print(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font)
{
    u32 jobAddr;

    STRBUF_GetChars(str);
    jobAddr = (u32)&_PrintJobWork;
    PRINTSYS_SetupJob((struct PrintCtx *)jobAddr, font, bmp, x, y);
    PRINTSYS_RunJob((struct PrintCtx *)jobAddr, str);
}

/*
 * A printsys entry point: the PRINTSYS_Print body plus a
 * PRINTSYS_SetJobColor(scratch, v) step between building the shared print request
 * in the static scratch and handing it to PRINTSYS_RunJob.  The leading
 * STRBUF_GetChars(s) call's result is unused.
 *
 * What closed it (wave 20): the scratch address is held as an integer, a
 * u32 local assigned (u32)&_PrintJobWork and cast back at each of the three
 * sites.  Spelled `&_PrintJobWork` at every site, 1.1p1 value-numbers the
 * address once, caches it in r4 and schedules z's outgoing stack store
 * straight after the first call to free that register (37 bytes out).
 * Through the integer local the address is rematerialised from its one pool
 * word at every site, z stays in r4 until its store after r0..r3 as the
 * image does, and the stacked u16 read keeps the 1.1p1 base.  This retires
 * the ../2.0/sp2 near miss (2 out) the notes carried.
 */
void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color)
{
    u32 jobAddr;

    STRBUF_GetChars(str);
    jobAddr = (u32)&_PrintJobWork;
    PRINTSYS_SetupJob((struct PrintCtx *)jobAddr, font, bmp, x, y);
    PRINTSYS_SetJobColor((struct PrintCtx *)jobAddr, color);
    PRINTSYS_RunJob((struct PrintCtx *)jobAddr, str);
}

/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     156 bytes including five pool words, one function
 *
 * printsys.c's render-context set-up: it records the surface and the string,
 * picks the blitter, packs the pen position into two ten bit fields of the
 * word at +4 and snapshots the current text colour into +0xC and +0xE.
 *
 * The two blitter addresses are the reason this is parked.  0x0201CA2C and
 * 0x0201CA78 are reached only through the two pool words in this function's
 * own literal pool, so `literal` discards both witnesses under the honesty
 * rule and no cut helps.  The `matched` class covers 0x0201CA2C now
 * (src/matched/unit_0201CA2C.c) but not 0x0201CA78, which is parked in
 * src/pending/PRINTSYS_PutGlyph8bpp.c for a reason of its own.  This file graduates
 * with that one.
 *
 * Two details worth keeping.  The three edits of the word at +4 are plain
 * integer mask-and-or arithmetic, the same spelling
 * src/matched/unit_0201C8A4.c uses, and the compiler writes the field only
 * twice for three statements because it keeps the value in a register across
 * the last two.  And the pen coordinates are read back out of the halfwords
 * that were just stored, with `ldrsh` and a register offset, which is the only
 * evidence that +0 and +2 are signed
 * (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/PRINTSYS_SetupJob.c \
 *       --addr 0x0201C808 --thumb
 */
void PRINTSYS_SetupJob(struct PrintCtx *job, struct GfFont *font, struct Bmp *bmp, u32 x, s16 y)
{
    u8 color[3];

    job->bmp = bmp;
    if (BMP_GetTileBytes(bmp) == 0x20) {
        job->blitGlyph = PRINTSYS_PutGlyph4bpp;
    } else {
        job->blitGlyph = PRINTSYS_PutGlyph8bpp;
    }
    job->font = font;
    job->penX = x;
    job->pos.raw = (job->pos.raw & 0xFFFFFC00u) | (job->penX & 0x3FF);
    job->penY = y;
    job->pos.raw = (job->pos.raw & 0xFFF003FFu) | ((job->penY & 0x3FF) << 10);
    job->pos.raw = (job->pos.raw & 0xFF0FFFFFu) | (1u << 20);
    GF_FONT_GetTextColor(&color[2], &color[1], &color[0]);
    job->textColor = (u16)(((color[2] & 0x1F) << 10) | ((color[1] & 0x1F) << 5)
                     | (color[0] & 0x1F));
    job->activeColor = job->textColor;
}

/*
 * Stores a halfword parameter at +0xE, then clears a four-bit field at bits
 * 20-23 of the word at +4 and sets it unconditionally to 1 (the mask/OR
 * pair is plain integer arithmetic, `(x & ~0xF00000) | (1 << 20)`; no
 * bitfield struct is needed since the two shift amounts in the AND/OR would
 * not match docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md's
 * shape anyway).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C8A4.c \
 *       --addr 0x0201C8A4 --thumb
 */
void PRINTSYS_SetJobColor(struct PrintCtx *job, u16 color)
{
    job->activeColor = color;
    job->pos.raw = (job->pos.raw & ~0xF00000u) | (1u << 20);
}

/*
 * printsys.c: if the 4-bit field at bits 20..23 of PrintCtx+0x04 is 1,
 * split the packed 5/5/5 triple at +0x0E and pass it to GF_FONT_IsTextColorDifferent; on a
 * nonzero result fill buf through GF_FONT_GetTextColor, pass the triple to
 * GF_FONT_SetTextColor and set done; then set the field to 2.  Render glyphs
 * through PRINTSYS_PrintStep until 0xFFFF, and if done, pass buf back to
 * GF_FONT_SetTextColor.
 *
 * Two facts the bytes pin (docs/notes/pkt_0201C8BC.c.txt has the history):
 *
 *  1. `done` is a PLAIN u8, not a volatile int.  The image reloads the
 *     zero from [sp,#4] before each of the three byte stores and forms buf's
 *     address as `add r1, sp, #8`: [sp,#4] is the SPILL slot of a register
 *     candidate, and buf is the first addressable local.  A plain int done
 *     has its zero forwarded into the stores (180 bytes); a volatile done
 *     gets a home next to buf in the local area and the stores go off
 *     `add r0, sp, #4` plus 4/5/6 (17 out).  A u8 (or u16, or signed char)
 *     flag is neither forwarded nor addressable
 *     (docs/idioms/a-narrow-flag-local-is-spilled-not-constant-propagated.md).
 *
 *  2. The rewrite mask is 0xFF0FFFFF (clear bits 20..23, the field the
 *     `<< 8 >> 28` test reads), then or 0x200000 (field = 2).  Earlier
 *     notes and docs/families/printsys.h wrote 0xFFFF0FFF.
 *
 * hi and mid are int (the u8 truncation is in the expression), lo is u8:
 * that is what puts hi in r7, mid in r6 and lo in the [sp] spill slot.
 */
void PRINTSYS_RunJob(struct PrintCtx *job, struct Strbuf *str)
{
    u16 *cursor = (u16 *)STRBUF_GetChars(str);
    u8 savedColor[3];
    u8 changed = 0;
    int letter;
    int shadow;
    u8 background;

    savedColor[0] = changed;
    savedColor[1] = changed;
    savedColor[2] = changed;
    if (((int)(job->pos.raw << 8)) >> 28 == 1) {
        int color = job->activeColor;

        letter = (u8)((color >> 10) & 0x1F);
        shadow = (u8)((color >> 5) & 0x1F);
        background = (u8)(color & 0x1F);
        if (GF_FONT_IsTextColorDifferent(letter, shadow, background) != 0) {
            GF_FONT_GetTextColor(&savedColor[2], &savedColor[1], &savedColor[0]);
            GF_FONT_SetTextColor((int)letter, (int)shadow, (int)background);
            changed = 1;
        }
        job->pos.raw = (job->pos.raw & 0xFF0FFFFF) | 0x200000;
    }
    while (*cursor != 0xFFFF) {
        cursor = (u16 *)PRINTSYS_PrintStep(job, cursor, 1);
    }
    if (changed) {
        GF_FONT_SetTextColor((int)savedColor[2], (int)savedColor[1], (int)savedColor[0]);
    }
}

/*
 * printsys.c: the glyph-run interpreter.  Walks the halfword string `p`
 * rendering one glyph per call to the renderer hook at PrintCtx+0x18 and
 * returns the cursor one halfword past the glyph it drew; 0xFFFF (end) and a
 * 0xF000 control block whose code byte is 0xBE with `f == 0` return the
 * cursor unchanged.
 *
 * Three facts the bytes pin, each one worth a whole spelling:
 *
 *  1. PrintCtx+0x04 is a SIGNED 10-BIT BITFIELD, not the `u32` flag word
 *     docs/families/printsys.h had.  The 0xFFFE (line break) arm reads it as
 *     `lsls #0x16 / asrs #0x16`, a 22-bit equal-width pair with a signed right
 *     half, which only `s32 :10` produces
 *     (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  Spelled
 *     `u32` the store is a bare `strh` and the pair is gone.
 *
 *  2. The control-code dispatch is a SWITCH, not an if/else chain.  The
 *     original tests 0xBD, 0xBE, 0xFF with three forward `beq`s and a final
 *     `b default`; an if/else chain of the same three tests emits `bne` skips
 *     instead and costs 86 concrete bytes here.  The switch is sparse (0xBD,
 *     0xBE, 0xFF), so no jump table appears, only the compare chain.
 *
 *  3. The 0xBE arm's guard is spelled `if (f != 0) { ...; break; } return p;`
 *     and NOT `if (f == 0) return p;`.  The original's `cmp r1, #0 / beq` puts
 *     the return out of line as the TAKEN target; the equality form emits
 *     `bne` and mirrors the last seven instructions
 *     (docs/idioms/the-fall-through-arm-is-the-source-order.md).  This was the
 *     last 13 concrete bytes.
 *
 * The block-layout shape also matters: the glyph body is reached by an
 * explicit `goto glyph` to a label AFTER the `while (1)`, which is what places
 * it physically last (at +0x8E) rather than in the middle.  Written as the
 * final `else` arm of the chain the compiler sinks the F000 block instead and
 * the function comes out 180 bytes, four short.
 *
 * The redundant inner `if (v == 0xF000) k = (u8)(p[1] >> 8); else k = 0xFF;`
 * inside the F000 arm is real: the original repeats the same `cmp r0, r7` test
 * (at +0x3C, reusing the flags of the outer one at +0x12) rather than assuming
 * it.  That is an inlined code-fetch helper, and collapsing it to a plain
 * `k = (u8)(p[1] >> 8)` loses the `bne`/`movs #0xff` pair.
 */
u16 *PRINTSYS_PrintStep(struct PrintCtx *job, u16 *cursor, u32 stopAtPause)
{
    u8 glyphInfo[4];
    s16 *penY = &job->penY;

    while (1) {
        u16 code = *cursor;
        if (code != 0xF000) {
            if (code != 0xFFFE) {
                if (code == 0xFFFF) {
                    return cursor;
                }
                goto glyph;
            }
            job->penX = (s16)job->pos.bits.originX;
            cursor = cursor + 1;
            *penY = (s16)(*penY + 0x10);
            continue;
        }
        {
            u32 tag;
            if (code == 0xF000) {
                tag = (u8)(cursor[1] >> 8);
            } else {
                tag = 0xFF;
            }
            switch (tag) {
            case 0xBD:
                cursor = PRINTSYS_ProcGeneralTag(job, cursor);
                break;
            case 0xFF:
                cursor = PRINTSYS_ProcColorTag(job, cursor);
                break;
            case 0xBE:
                if (stopAtPause != 0) {
                    if (code != 0xF000) {
                        continue;
                    }
                    cursor = (u16 *)((u8 *)(cursor + 3) + cursor[2] * 2);
                    break;
                }
                return cursor;
            default:
                if (code != 0xF000) {
                    continue;
                }
                cursor = (u16 *)((u8 *)(cursor + 3) + cursor[2] * 2);
                break;
            }
        }
    }
  glyph:
    {
        u16 code = *cursor;
        job->blitGlyph(job->bmp, job->penX, job->penY, job->font, code, glyphInfo);
        job->penX = (s16)(job->penX + glyphInfo[2]);
        return cursor + 1;
    }
}

/*
 * One of the two printsys.c glyph blitters, both of which forward the caller's
 * pen record to GF_FONT_ReadGlyph and then hand the result to a renderer reached
 * through the module object at 0x02146558.  The pair is cut here rather than
 * matched as one range because GF_FONT_ReadGlyph is reached from exactly two places
 * in the image, 0x0201CA4C and 0x0201CA98, one in each function: matched
 * together neither site has a witness, matched apart each is the other's `label`
 * witness.  That is
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * Its sibling at 0x0201CA78 stays parked (src/pending/PRINTSYS_PutGlyph8bpp.c): it calls
 * 0x02043AAC, and 0x0201CABC is the only branch to that address anywhere in the
 * image, so no cut reaches it.
 *
 * f is a four-byte pen record: f[0] is an x bias added to the caller's x, f[1]
 * and f[3] are passed straight through.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CA2C.c \
 *       --addr 0x0201CA2C --thumb
 */
void PRINTSYS_PutGlyph4bpp(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo)
{
    GF_FONT_ReadGlyph(font, code, BMP_GetPixels(_pGlyphBmp), (void *)glyphInfo);
    BMP_Blit(_pGlyphBmp, bmp, 0, 0, x + glyphInfo[0], y, glyphInfo[1], glyphInfo[3], 0);
}

/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     80 bytes including two pool words, one function
 *
 * printsys.c's second glyph blitter, the twin of PRINTSYS_PutGlyph4bpp in
 * src/matched/unit_0201CA2C.c.  The two differ only in which renderer they
 * call and in the two extra stack arguments this one passes, 0xF and 0.
 *
 * Why it is capped: the `blx` at 0x0201CABC is the only branch to 0x02043AAC
 * anywhere in the image, checked over every Thumb BL/BLX pair and every ARM
 * branch in all 242 regions, and no pool word holds the address either.  The
 * `label` class therefore has no witness once the compared range holds that
 * call, and no cut helps, because the range cannot be smaller than this one
 * function.  Cutting it away from PRINTSYS_PutGlyph4bpp is what let that function come
 * out EXACT, since the two are the only callers of GF_FONT_ReadGlyph and each is
 * now the other's witness
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * It closes the day 0x02043AAC is matched (the `matched` class) or acquires a
 * second caller.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/PRINTSYS_PutGlyph8bpp.c \
 *       --addr 0x0201CA78 --thumb
 */
void PRINTSYS_PutGlyph8bpp(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo)
{
    GF_FONT_ReadGlyph(font, code, BMP_GetPixels(_pGlyphBmp), (void *)glyphInfo);
    BMP_BlitPaletteOffset(_pGlyphBmp, (u32)bmp, 0, 0, x + glyphInfo[0], y, glyphInfo[1], glyphInfo[3], 0xF, 0);
}

/*
 * printsys.c: applies one 0xF000 control block whose code byte is 0xBD -- the
 * "set colour / align line" family -- and steps the cursor past the block.
 * Called from exactly one place image-wide, 0x0201C9D0 inside PRINTSYS_PrintStep,
 * which is why PRINTSYS_PrintStep resolved that call `sole-ref/code` until this
 * file existed; it is `matched` now.
 *
 * The dispatch is a DENSE switch on a 7-entry PC-relative halfword table at
 * +0x30..+0x3D, so cases 0..6 must ALL be written, including `case 6:` which
 * is empty and shares the default's exit
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md and
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  Without the
 * empty case 6 the bound check is `cmp r1, #5` and the table has six entries.
 *
 * Two spellings the bytes pin:
 *
 *  1. The switch selector is `((u32)(u8)p[1] << 16) >> 16`, TWO stacked
 *     narrowings: the original has `lsls #0x18 / lsrs #0x18` (the byte) and
 *     then `lsls #0x10 / lsrs #0x10` (a u16) before the bound check.  Written
 *     as a plain `(u8)p[1]` into a `u16` local the second pair folds away and
 *     the function is four bytes short.  Two nested inlined accessors, one
 *     returning u8 and one u16.
 *
 *  2. The 5/5/5 pack in case 0 is `(b & 0x1F) | (((r << 27) >> 17) |
 *     ((g << 27) >> 22))`, i.e. RED shifts to bit 10 and GREEN to bit 5.  The
 *     reversed grouping is size-exact and eight bytes out; the order of the
 *     two `lsls #0x1b` operands in the image names which byte is which
 *     (docs/idioms/commutative-operand-order-names-the-temporary.md).
 *
 * Also corrected against docs/families/printsys.h as it stood: the measuring
 * arms (cases 2 and 3) hand BMP_GetWidth the handle at PrintCtx+0x14, not
 * +0x18; +0x18 is the renderer hook PRINTSYS_PrintStep calls through.  And
 * PrintCtx+0x04 is a SIGNED 10-BIT BITFIELD (`lsls #0x16 / asrs #0x16`), not
 * a u32 flag word -- the same fact src/matched/PRINTSYS_PrintStep.c records.
 *
 * Case order in the source is 0, 1, 3, 2, 4, 5, 6: the table's displacements
 * put case 3's body (0x0201CB7E) before case 2's (0x0201CBB6), and this
 * compiler emits switch arms in source order.
 */
u16 *PRINTSYS_ProcGeneralTag(struct PrintCtx *job, u16 *cursor)
{
    u32 background;
    u16 code = *cursor;
    u32 tag;

    if (code == 0xF000) {
        tag = ((u32)(u8)cursor[1] << 16) >> 16;
    } else {
        tag = 0xFFFF;
    }

    switch (tag) {
    case 0: {
        u32 letter, shadow, unusedBackground;
        letter = (u8)((code == 0xF000) ? cursor[3] : 0);
        shadow = (u8)((code == 0xF000) ? cursor[4] : 0);
        background = (u8)((code == 0xF000) ? cursor[5] : 0);
        GF_FONT_SetTextColor(letter, shadow, background);
        job->activeColor = (u16)((background & 0x1F) | (((letter << 27) >> 17) | ((shadow << 27) >> 22)));
        break;
    }
    case 1: {
        u16 color = job->textColor;
        GF_FONT_SetTextColor((u8)((color >> 10) & 0x1F), (u8)((color >> 5) & 0x1F), (u8)(color & 0x1F));
        break;
    }
    case 3: {
        s32 width = BMP_GetWidth(job->bmp);
        s32 room = (s32)(width - job->pos.bits.originX);
        u32 strWidth;
        u32 unusedMargin = 0;
        strWidth = (u32)func_0201D26C(cursor, job->font, 0, 0);
        {
            u32 margin = 0;
            if (*cursor == 0xF000) {
                margin = cursor[3];
            }
            job->penX = (s16)(job->pos.bits.originX + (room - (s32)strWidth) - 1 - (s32)margin);
        }
        break;
    }
    case 2: {
        s32 width = BMP_GetWidth(job->bmp);
        s32 room = (s32)(width - job->pos.bits.originX);
        s32 strWidth = func_0201D26C(cursor, job->font, 0, 0);
        if (strWidth < room) {
            job->penX = (s16)(job->pos.bits.originX + (room - strWidth) / 2);
        } else {
            job->penX = (s16)job->pos.bits.originX;
        }
        break;
    }
    case 4: {
        u32 offset = (code == 0xF000) ? cursor[3] : 0;
        job->penX = (s16)(job->penX + (s16)offset);
        break;
    }
    case 5: {
        u32 offset = (code == 0xF000) ? cursor[3] : 0;
        job->penX = (s16)offset;
        break;
    }
    case 6:
        break;
    default:
        break;
    }

    if (*cursor == 0xF000) {
        cursor = (u16 *)((u8 *)(cursor + 3) + cursor[2] * 2);
    }
    return cursor;
}

u16 *PRINTSYS_ProcColorTag(struct PrintCtx *job, u16 *cursor)
{
    u16 tag;
    u8 paletteRow;
    u8 background;
    int base;

    if (cursor[0] == 0xF000) {
        tag = (u16)(cursor[1] & 0xFF);
    } else {
        tag = 0xFFFF;
    }
    if (tag == 0) {
        paletteRow = (u8)((cursor[0] == 0xF000) ? cursor[3] : 0);
        if (paletteRow == 0xFF) {
            GF_FONT_SetTextColor((u8)((job->activeColor >> 10) & 0x1F), (u8)((job->activeColor >> 5) & 0x1F),
                          (u8)(job->activeColor & 0x1F));
        } else {
            int letter;
            int shadow;
            base = paletteRow * 2;
            background = (u8)(job->textColor & 0x1F);
            shadow = base + 2;
            letter = base + 1;
            GF_FONT_SetTextColor((u8)letter, (u8)shadow, background);
            job->activeColor = (u16)((((u8)letter & 0x1F) << 10) | (((u8)shadow & 0x1F) << 5)
                          | (background & 0x1F));
        }
    }
    if (cursor[0] == 0xF000) return (u16 *)((char *)cursor + 6 + cursor[2] * 2);
    return cursor;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_PrintStream.c \
 *       --func PRINTSYS_PrintStream --addr 0x0201CCE4 --cc 1.1p1 --thumb
 */
void PRINTSYS_PrintStream(struct BmpWin *win, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, s32 wait, struct Tcbl *tcbl,
                   u32 priority, u16 heap, u16 fillColor)
{
    PRINTSYS_PrintStreamCallBack(win, x, y, str, font, wait, tcbl, priority, heap, fillColor, 0);
}

/*
 * The printsys text-record constructor: registers GF_FONT_Task as a
 * task with a 0x50-byte work area, builds the PrintCtx at +0x34 through
 * PRINTSYS_SetupJob, splits the signed speed argument into the sign/magnitude
 * pairs at +0x18..+0x1D, and initialises every other field of struct Rec
 * (the same layout src/matched/GF_FONT_Task.c consumes).  Returns the
 * record.
 *
 * The two-load swap the notes carried at +0x28/+0x30 (a4 read before a1)
 * was a declaration fact, not a scheduling one:
 *  - PRINTSYS_SetupJob's real prototype (src/matched/PRINTSYS_SetupJob.c) is
 *    (struct PrintCtx *, void *, void *, s16, s16), so a1 and a2 are s16
 *    parameters here;
 *  - the byte stored to +0x20 is the tenth argument declared `u16 a9`.
 *    Thumb ldrh cannot use sp as a base, which is where the notes'
 *    `*(u16 *)((u8 *)&a4 + 0x14)` came from; taking a4's address to fake
 *    it pinned the a4 load late.  With a9 a real u16 parameter nothing
 *    takes an address and the loads schedule as in the image.
 */
struct TextPrinter *PRINTSYS_PrintStreamCallBack(struct BmpWin *win, s16 x, s16 y, struct Strbuf *str,
                          struct GfFont *font, s32 wait, struct Tcbl *tcbl, u32 priority, u32 heap, u16 fillColor,
                          PrintCallback callback)
{
    struct TextPrinter *printer;
    struct TcblNode *task;
    struct Bmp *bmp;
    u8 speed[2];

    bmp = BMP_WIN_GetBmp(win);
    task = TCBL_AddTask(tcbl, (void *)GF_FONT_Task, 0x50, priority);
    printer = TCBL_GetWork(task);

    printer->task = task;
    PRINTSYS_SetupJob(&printer->ctx, font, bmp, x, y);
    PRINTSYS_SplitWait(wait, speed);
    printer->defaultGlyphs = speed[1];
    {
        u8 waitFrames = speed[0];
        printer->defaultWait = waitFrames;
        printer->overrideWait = waitFrames;
        printer->waitFrames = waitFrames;
    }
    {
        u8 glyphs = printer->defaultGlyphs;
        printer->overrideGlyphs = glyphs;
        printer->glyphsPerTick = glyphs;
    }
    printer->cursor = STRBUF_GetChars(str);
    printer->waitCounter = 0;
    printer->callback = callback;
    printer->initialCallbackArg = 0;
    printer->nextCallbackArg = 0;
    printer->callbackArg = 0;
    printer->bmpWin = win;
    printer->bmp = bmp;
    printer->state = 0;
    printer->fillColor = fillColor;
    printer->waitKind = 1;
    printer->scrollPixels = 0;
    printer->flags.bits.advance = 0;
    printer->flags.bits.halted = 0;
    printer->flags.bits.scrolling = 0;
    printer->callbackResult = 0;
    printer->flags.bits.useOverrideSpeed = 0;
    printer->flags.bits.clearOverridePending = 0;
    return printer;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           PRINTSYS_PrintStreamGetWaitKind, PRINTSYS_PrintStreamReleasePause, PRINTSYS_PrintStreamDelete
 *
 * PRINTSYS_SplitWait splits a signed delta into a sign-magnitude pair of output
 * bytes: byte[1]=1 and byte[0]=the value when it is non-negative, byte[1]=
 * the absolute value and byte[0]=0 when it is negative.  The two branches
 * store to the two bytes in opposite order from each other, which is what
 * the original does and is not an artefact of how it is written.
 *
 * PRINTSYS_PrintStreamStop, PRINTSYS_PrintStreamRun and PRINTSYS_PrintStreamReleasePause are three single-bit
 * operations on a byte at offset 0x22 of an object: set bit 0 (written
 * through a redundant clear-then-set, `(x & ~1) | 1`, rather than a plain
 * `x |= 1`, which is what the bytes show), clear bit 0, and set bit 2 with
 * a plain OR.  All three read and write the field through two separate
 * `((u8 *)p)[0x22]` expressions rather than a named pointer local, which is
 * what keeps the load address and the store address computed independently
 * the way the original does it.
 *
 * PRINTSYS_PrintStreamGetState and PRINTSYS_PrintStreamGetWaitKind are the two four-byte word getters this
 * neighbourhood keeps reusing (the same shape as
 * src/matched/unit_0201AA14.c's pair); disasm.py's prologue sweep does not
 * label either of them, since a two-instruction leaf saves nothing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), so both were
 * read directly out of the `.word` run the listing prints between
 * PRINTSYS_PrintStreamRun and PRINTSYS_PrintStreamReleasePause.
 *
 * PRINTSYS_PrintStreamDelete frees and clears an owned pointer at offset 0x10 if it is
 * non-null.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CDF4.c \
 *       --addr 0x0201CDF4 --thumb
 */
void PRINTSYS_SplitWait(int wait, u8 *speed)
{
    if (wait >= 0) {
        speed[1] = 1;
        speed[0] = (u8)wait;
    } else {
        speed[1] = (u8)(-wait);
        speed[0] = 0;
    }
}

void PRINTSYS_PrintStreamStop(struct TextPrinter *printer)
{
    printer->flags.raw = (printer->flags.raw & ~1u) | 1u;
}

void PRINTSYS_PrintStreamRun(struct TextPrinter *printer)
{
    printer->flags.raw = printer->flags.raw & ~1u;
}

u32 PRINTSYS_PrintStreamGetState(const struct TextPrinter *printer)
{
    return printer->state;
}

u32 PRINTSYS_PrintStreamGetWaitKind(const struct TextPrinter *printer)
{
    return printer->waitKind;
}

void PRINTSYS_PrintStreamReleasePause(struct TextPrinter *printer)
{
    printer->flags.raw = printer->flags.raw | 4u;
}

void PRINTSYS_PrintStreamDelete(struct TextPrinter *printer)
{
    if (printer->task != 0) {
        TCBL_DeleteTask(printer->task);
        printer->task = 0;
    }
}

/*
 * Four more operations on the object src/matched/unit_0201CDF4.c works on,
 * continuing its run of single-bit edits of the flag byte at +0x22: this
 * range sets bit 4 and bit 3, clears bit 3, and reads bit 3 back.
 *
 * PRINTSYS_PrintStreamShortWait lowers a level-like byte at +0x1E and, when the new value is
 * zero, replaces the pair at +0x1C/+0x1D through PRINTSYS_PrintStreamSetSpeed with whatever
 * MSG_SPEED_GetWaitForSpeed(2) returns.  PRINTSYS_PrintStreamResetSpeed is the undo: it clears the bit and
 * restores the pair from the backup at +0x18/+0x19.
 *
 * PRINTSYS_PrintStreamIsOverrideSpeed is an unlabelled follower, eight bytes with no prologue.  It
 * reads bit 3 as a `lsls #0x1C` / `lsrs #0x1F` pair, which is the bitfield
 * extraction shape of
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md rather than
 * the `lsrs #3` / `ands #1` a shift and mask would give.
 *
 * The bit read has to be cast to u32 before the shift pair: on the promoted
 * `int` the right shift is an `asrs` and the one byte is wrong.
 *
 * Every one of the four reaches the flag byte through two independent
 * `((u8 *)p)[0x22]` expressions, the same spelling unit_0201CDF4.c needs, so
 * the load address and the store address are computed separately.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CE5C.c \
 *       --addr 0x0201CE5C --thumb
 */
void PRINTSYS_PrintStreamShortWait(struct TextPrinter *printer, s32 wait)
{
    if (wait < printer->waitCounter) {
        printer->waitCounter = (u8)wait;
        if (wait == 0) {
            PRINTSYS_PrintStreamSetSpeed(printer, MSG_SPEED_GetWaitForSpeed(2));
            printer->flags.raw = 0x10u | printer->flags.raw;
        }
    }
}

void PRINTSYS_PrintStreamSetSpeed(struct TextPrinter *printer, s32 wait)
{
    u8 speed[2];

    PRINTSYS_SplitWait(wait, speed);
    printer->overrideGlyphs = speed[1];
    printer->overrideWait = speed[0];
    printer->flags.raw = 8u | printer->flags.raw;
}

void PRINTSYS_PrintStreamResetSpeed(struct TextPrinter *printer)
{
    printer->flags.raw = printer->flags.raw & ~8u;
    printer->overrideGlyphs = printer->defaultGlyphs;
    printer->overrideWait = printer->defaultWait;
}

u32 PRINTSYS_PrintStreamIsOverrideSpeed(const struct TextPrinter *printer)
{
    return ((u32)printer->flags.raw << 28) >> 31;
}
