/*
 * file:     time_icon.c
 * unit:     yes
 * function: COMM_PLAYER_SUPPORT_Create, func_0202E794, COMM_PLAYER_SUPPORT_Init, COMM_PLAYER_SUPPORT_SetModeAndCurrent, COMM_PLAYER_SUPPORT_GetCurrent, COMM_PLAYER_SUPPORT_GetMode, COMM_PLAYER_SUPPORT_SavePreviousAndSuspend, COMM_PLAYER_SUPPORT_StashMode, COMM_PLAYER_SUPPORT_HasSavedMode, COMM_PLAYER_SUPPORT_GetActiveRecord, COMM_PLAYER_SUPPORT_GetInfoCode, func_0202E848, func_0202E888, func_0202E8A4, func_0202E8B8, func_0202E8CC, COMM_PLAYER_SUPPORT_FindPeerRecord, COMM_PLAYER_SUPPORT_GetRecordFieldPtr, COMM_PLAYER_SUPPORT_GetRecordField, BLINK_PALANM_Create, BLINK_PALANM_LoadPalettes, func_0202EA20, BLINK_PALANM_Update, BLINK_PALANM_ResetPhase, func_0202EB0C, func_0202EB14, func_0202EB44, func_0202EB4C, func_0202EB60, func_0202EB7C, func_0202EB9C, func_0202EC24, func_0202EC44, func_0202EC7C, func_0202ECB0, func_0202ED00, func_0202ED60, func_0202ED90, func_0202EDE4, func_0202EE0C, TIME_ICON_Create, TIME_ICON_CreateNode, TIME_ICON_Init, TIME_ICON_Alloc, TIME_ICON_Start, TIME_ICON_Delete, TIME_ICON_TaskMain, TIME_ICON_NodeMain, TIME_ICON_Update, sub_0202F114, sub_0202F138, sub_0202F144, sub_0202F170, func_0202F190, func_0202F1B4, func_0202F27C, func_0202F2AC, func_0202F2F4, func_0202F30C, func_0202F358, func_0202F3AC, func_0202F41C, func_0202F464, func_0202F47C, func_0202F488, func_0202F498, func_0202F630, func_0202F640, func_0202F688, func_0202F6D8, func_0202F72C, func_0202F738, func_0202F768, func_0202F774, func_0202F788, func_0202F7C4, func_0202F870, func_0202F940, func_0202F9F4, func_0202F9F8, func_0202FAB0
 * address:  0x0202E770
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Split from time_icon.c at 0x0202E770 (__FILE__ anchor boundary, certain cut).
 * time_icon.c.  The unlabelled four-byte leaf after func_0202F9F8's literal
 * pool (`movs r0, #1; bx lr`), which the listing extent of func_0202F9F8
 * swallows.  It saves nothing, so disasm.py never labels it
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); seed
 * 0x0202FAB0 in layout/function_starts.txt.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202FAB0.c \
 *       --func func_0202FAB0 --addr 0x0202FAB0 --cc 1.1p1 --thumb
 *
 * symbols:
 *   func_02030734    0x02030734  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   comm_player_support_File     0x020A77EC  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   MYSTATUS_Init  0x020084A0  thumb
 *   func_02012138  0x02012138  thumb
 *   INTRUDE_COMM_GetAreaSlotFlag  0x02158468  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   GAME_DATA_SetSeason  0x0201298C  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008534  0x02008534  thumb
 *   blink_palanm_File    0x020A7804  data
 *   func_02049F78      0x02049F78  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetParentalControlInfoPtr  0x02087E60  arm
 *   func_02087DC4  0x02087DC4  arm
 *   OS_IsAgreeEULA  0x02087DE0  arm
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   func_0200974C  0x0200974C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_0202EC24  0x0202EC24  thumb
 *   func_02008530   0x02008530  thumb
 *   func_02009750   0x02009750  thumb
 *   func_020095E8   0x020095E8  thumb
 *   _u32_div_f      0x0209C2B0  arm
 *   time_icon_File     0x020A7814  data
 *   func_02030DA8  0x02030DA8  arm
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   func_020056EC   0x020056EC  thumb
 *   BMP_CreateFromArchive   0x0204384C  arm
 *   BMP_WIN_GetBgLayer   0x02045730  arm
 *   BMP_WIN_GetPosX   0x02045758  arm
 *   BMP_WIN_GetWidth   0x02045738  arm
 *   BMP_WIN_GetPosY   0x02045760  arm
 *   BMP_WIN_GetHeight   0x02045740  arm
 *   BMP_WIN_GetPalette   0x02045778  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   func_02041B6C   0x02041B6C  arm
 *   BMP_Delete   0x020437AC  arm
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_WIN_Delete   0x020452E8  arm
 *   func_02030EAC   0x02030EAC  arm
 *   TCBL_DeleteTask   0x02031194  arm
 *   BMP_Blit   0x020439A0  arm
 *   sItemGfxExtraTable      0x020A03C8  data
 *   func_020185F0   0x020185F0  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   POKE_TOOL_IsBoxOwnedByPlayer  0x02018488  thumb
 *   POKE_TOOL_SetBoxValue   0x02017E64  thumb
 *   func_02017E88   0x02017E88  thumb
 *   ZONEDATA_IsRawZoneGroup4CTo69   0x02014034  thumb
 *   POKE_TOOL_IsBoxShiny  0x02017EB4  thumb
 *   func_020212E4  0x020212E4  thumb
 *   func_02007084  0x02007084  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   func_020351A0  0x020351A0  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   func_0207D534    0x0207D534  arm
 *   func_0207D3AC    0x0207D3AC  arm
 *   GX_VBlankIntr    0x0207D3E4  arm
 *   func_020808F4    0x020808F4  arm
 *   func_020809A0    0x020809A0  arm
 *   func_0207FDCC    0x0207FDCC  arm
 *   func_0207D4B0    0x0207D4B0  arm
 *   func_0207E24C    0x0207E24C  arm
 *   func_02082A7C    0x02082A7C  arm
 *   ARC_UTIL_LoadMember    0x0204A1BC  arm
 *   func_02062A4C    0x02062A4C  arm
 *   DWCi_ScreenDC_FlushRange    0x020862F0  arm
 *   MIi_CpuCopy16    0x02082A60  arm
 *   func_02062B30    0x02062B30  arm
 *   func_0207DFB4    0x0207DFB4  arm
 *   func_02062AD4    0x02062AD4  arm
 *   func_02062A98    0x02062A98  arm
 *   MIi_CpuClear16    0x02082A48  arm
 *   BMP_CreateFromVram    0x02043754  arm
 *   GF_FONT_Create    0x0201D7EC  thumb
 *   func_02045B38    0x02045B38  arm
 *   func_02045EC0    0x02045EC0  arm
 *   PRINTSYS_PrintColor    0x0201C7D0  thumb
 *   MSGDATA_Delete    0x02045C04  arm
 *   GF_FONT_Delete    0x0201D83C  thumb
 *   ov088_id       0x00000058  data  a1
 *   ov179_id       0x000000B3  data  a1
 *   d_021BD8E8     0x021BD8E8  data
 *   d_021B68D8     0x021B68D8  data  ov179
 *   d_021BD574     0x021BD574  data
 *   sOverlayLaunchWork     0x02146948  data
 *   sOverlayLaunchWorkArg 0x02146948  data
 *   PROCSYS_PushGlobal  0x020312CC  arm
 */
#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))
#define REG_BG1CNT_A        0x0400000A
#define REG_BG1HOFS_A       0x04000014
#define REG_BLDCNT_A        0x04000050
#define REG_MASTER_BRIGHT_A 0x0400006C
#define REG_MASTER_BRIGHT_B 0x0400106C
struct Tcb;
struct TcbList;
struct TcblNode;
struct TcblList;
struct BmpWin;
struct Bmp;
struct SaveData;
struct Strbuf;
struct MsgBank;
struct GfFont;
struct PlayerInfo;
struct PlayerLookup;
struct HistoryOwner;
struct ResourceFile;
struct ArchiveRecord;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

/* A 0x20-byte player record, read through the accessors func_02008510 etc. */
struct PlayerRecord {
    u32 words[8];
};

/*
 * COMM_PLAYER_SUPPORT state object (0x4c bytes, allocated by
 * COMM_PLAYER_SUPPORT_Create): a mode word, the mode it replaced, a stashed mode, and
 * two player records, the current one and the one saved before a switch.
 */
struct CommPlayerSupport {
    u32 mode;                       /* 0x00 */
    u32 prevMode;                   /* 0x04, set by COMM_PLAYER_SUPPORT_SavePreviousAndSuspend */
    u32 stashedMode;                /* 0x08, set by COMM_PLAYER_SUPPORT_StashMode */
    struct PlayerRecord current;    /* 0x0c */
    struct PlayerRecord previous;   /* 0x2c */
};

/* RTC date as func_0203F4E4 fills it: year, month, day, weekday. */
struct RtcDate {
    s32 year;
    s32 month;
    s32 day;
    s32 weekday;
};

/*
 * A record plus the three 6-byte addresses (MAC addresses of the peers it
 * has met) that follow it at +0x22.
 */
struct PeerBook {
    struct PlayerRecord record;     /* 0x00 */
    u8 reserved20[2];               /* 0x20 */
    u8 macs[3][6];                  /* 0x22 */
};

/*
 * BLINK_PALANM object: cross-fades a run of palette colors between two
 * source rows (srcColors, dstColors) into outColors and uploads the result.
 */
struct BlinkPalAnm {
    u16 *srcColors;     /* 0x00, allocated by BLINK_PALANM_LoadPalettes */
    u16 *dstColors;     /* 0x04, allocated by BLINK_PALANM_LoadPalettes */
    u16 *outColors;     /* 0x08, colorCount entries, allocated at creation */
    u16 firstColor;     /* 0x0c, first palette color to overwrite */
    u16 colorCount;     /* 0x0e */
    u16 phase;          /* 0x10, 0..0xFFFF, advances 0x400 per frame */
    u16 reserved12;     /* 0x12, zeroed at creation, never read */
    u32 targetMask;     /* 0x14, which palettes to upload to (0xe/0x1e/0xf/0x1f) */
    u16 heapId;         /* 0x18 */
};

/* Palette resource as func_02049F78 returns it: colors start at +0xC. */
struct PaletteFile {
    u8 header[0xC];
    u8 *colors;
};

/* One slot of the 20-entry history table (0x28 bytes). */
struct HistoryEntry {
    struct PlayerRecord record;     /* 0x00 */
    u8 reserved20[6];               /* 0x20 */
    u8 : 3;                         /* 0x26 */
    u8 isMarked : 1;
    u8 isOccupied : 1;
    u8 : 3;
    u8 reserved27;                  /* 0x27 */
};

/* Hardware capability word (DSi/wireless flags) behind OS_GetParentalControlInfoPtr. */
struct DeviceInfo {
    u32 bit0:1;
    u32 pad:4;
    u32 bit5:1;
};

/* Owner info record behind OS_GetOwnerInfo: only bytes 2 and 3 are read. */
struct OwnerInfo {
    u8 reserved00;
    u8 reserved01;
    u8 favoriteColor;
    u8 birthMonth;
    u8 rest[0x50];
};

/*
 * TIME_ICON object (0x1c bytes): the animated wait icon, a 2x2 tile window
 * in the bottom right corner of a reference window.  Each tick copies the
 * next 16x16 frame of the 8-frame sheet into the window.
 */
struct TimeIcon {
    struct Tcb *task;           /* 0x00, set when created with a task list */
    struct TcblNode *node;      /* 0x04, set when created with a TCBL node */
    struct BmpWin *win;         /* 0x08 */
    struct Bmp *sheet;          /* 0x0c, frame sheet loaded from archive 0xC6 */
    u16 heapId;                 /* 0x10 */
    u8 fillColor;               /* 0x12, window background fill value */
    u8 waitCounter;             /* 0x13, ticks left until the next frame */
    u8 waitInterval;            /* 0x14, ticks per frame */
    u8 frame;                   /* 0x15, current frame, 0..7 */
    u8 reserved16[2];           /* 0x16 */
    u32 isActive;               /* 0x18 */
};

/* Entry of the 46-row item graphics extra table. */
struct ItemGfxExtra {
    u16 itemId;
    u16 value;
};

/* State block of the overlay launcher driven by func_0202F9F8. */
struct OverlayLaunchWork {
    u16 stage;      /* 0x00 */
    u8 enabled;     /* 0x02 */
    u8 aborted;     /* 0x03, set by the launched overlay */
    u32 mode;       /* 0x04 */
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void STRBUF_Delete(struct Strbuf *str);
extern void MI_CpuCopy8(void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *p, u32 value, u32 size);
extern void MYSTATUS_Init(struct PlayerRecord *record);
extern u32 func_02012138(const struct PlayerInfo *info);
extern int INTRUDE_COMM_GetAreaSlotFlag(int value);
extern void func_0203F4E4(struct RtcDate *date);
extern u8 GAME_DATA_SetSeason(s32 handle, u8 value);
extern int func_02012B70(struct PlayerInfo *info);
extern int func_02012984(struct PlayerInfo *info);
extern int func_02009D1C(struct PlayerLookup *lookup, const struct PlayerRecord *record, u32 *out);
extern u16 *func_020084F4(const struct PlayerRecord *record);
extern u16 func_02008534(const struct PlayerRecord *record);
extern struct ResourceFile *func_02049F78(void *archive, u32 fileId, u32 outData, u32 heapId);
extern s32 func_02061CA4(u32 targetMask, u32 firstColor, u32 colors, s32 size);
extern u32 OS_IsRunOnTwl(void);
extern struct DeviceInfo *OS_GetParentalControlInfoPtr(void);
extern void func_02087DC4(void);
extern int OS_IsAgreeEULA(void);
extern void OS_GetOwnerInfo(struct OwnerInfo *info);
extern u8 func_0200856C(const struct PlayerRecord *record);
extern struct HistoryEntry *func_0200974C(struct HistoryOwner *owner);
extern u32 func_02008530(const struct PlayerRecord *record);
extern u32 func_02009750(struct HistoryOwner *owner, u32 key);
extern void func_020095E8(struct HistoryOwner *owner);
extern u32 _u32_div_f(u32 dividend, u32 divisor);
extern struct Tcb *func_02030DA8(struct TcbList *list, void (*callback)(struct Tcb *, void *), void *work, u32 priority);
extern struct TcblNode *TCBL_AddTask(struct TcblList *list, void (*callback)(struct TcblNode *, void *), u32 size, u32 flags);
extern void *TCBL_GetWork(struct TcblNode *node);
extern u32 func_020056EC(u32 range);
extern struct Bmp *BMP_CreateFromArchive(u32 arcId, u32 memberId, u32 compressed, u32 heapId);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern u8 BMP_WIN_GetPosX(struct BmpWin *win);
extern u8 BMP_WIN_GetWidth(struct BmpWin *win);
extern u8 BMP_WIN_GetPosY(struct BmpWin *win);
extern u8 BMP_WIN_GetHeight(struct BmpWin *win);
extern u8 BMP_WIN_GetPalette(struct BmpWin *win);
extern struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u32 width, u32 height, u32 palette, u32 allocDir);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern void func_02041B6C(u32 bgLayer);
extern void BMP_Delete(struct Bmp *bmp);
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bmp *bmp, u8 value);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern void func_02030EAC(struct Tcb *tcb);
extern void TCBL_DeleteTask(struct TcblNode *node);
extern void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 w, u32 h, u32 colorKey);
extern struct SaveData *func_020185F0(void *gameData);
extern u32 func_02017DBC(struct SaveData *save);
extern u32 func_02017DE4(struct SaveData *save, u32 savedFlag);
extern u32 POKE_TOOL_IsBoxOwnedByPlayer(struct SaveData *save, const struct PlayerRecord *record);
extern void POKE_TOOL_SetBoxValue(struct SaveData *save, u32 varId, u32 value);
extern u32 func_02017E88(struct SaveData *save, u32 varId, u32 defaultValue);
extern u32 ZONEDATA_IsRawZoneGroup4CTo69(u32 id);
extern struct Strbuf *func_02008510(const struct PlayerRecord *record, u32 index);
extern u32 func_02008550(const struct PlayerRecord *record);
extern u32 POKE_TOOL_IsBoxShiny(struct SaveData *save);
extern u32 func_020212E4(u16 value);
extern void func_02007084(void);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_ClearExitFlag(void);
extern int GFL_NET_Exit(int enable);
extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern u32 GFL_NET_Main(void);
extern int GFL_NET_IsSessionNull(void);
extern int func_020351A0(u32 stage);
extern void GFL_USE_PollPowerExit(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern long func_0207D3AC(int enable);
extern long GX_VBlankIntr(int enable);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void func_0207FDCC(u32 layerMask);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0Is3d);
extern void *func_0207E24C(void);
extern void func_02082A7C(u32 value, u32 dest, u32 size);
extern int ARC_UTIL_LoadMember(int arcId, int memberId, int compressed, int heapId);
extern s32 func_02062A4C(struct ArchiveRecord *file, void **out);
extern void DWCi_ScreenDC_FlushRange(u32 addr, u32 size);
extern void MIi_CpuCopy16(u32 src, u32 dest, u32 size);
extern int func_02062B30(void *file, void **out);
extern void *func_0207DFB4(void);
extern s32 func_02062AD4(struct ArchiveRecord *file, void **out);
extern s32 func_02062A98(struct ArchiveRecord *file, void **out);
extern void MIi_CpuClear16(u32 value, u32 dest, u32 size);
extern struct Bmp *BMP_CreateFromVram(void *pixels, u32 width, u32 height, u32 depth, u16 heapId);
extern struct GfFont *GF_FONT_Create(int fontId, int spacingX, int spacingY, int colorMode, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Strbuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *text, struct GfFont *font, u16 color);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void PROCSYS_PushGlobal(u32 ovl, u32 proc, u32 arg);
struct CommPlayerSupport *COMM_PLAYER_SUPPORT_Create(u32 heapId);
void COMM_PLAYER_SUPPORT_Delete(void *support);
void COMM_PLAYER_SUPPORT_Init(struct CommPlayerSupport *support);
void COMM_PLAYER_SUPPORT_SetModeAndCurrent(struct CommPlayerSupport *support, u32 mode, const struct PlayerRecord *record);
struct PlayerRecord *COMM_PLAYER_SUPPORT_GetCurrent(struct CommPlayerSupport *support);
u32 COMM_PLAYER_SUPPORT_GetMode(struct CommPlayerSupport *support);
void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(struct CommPlayerSupport *support);
void COMM_PLAYER_SUPPORT_StashMode(struct CommPlayerSupport *support);
int COMM_PLAYER_SUPPORT_HasSavedMode(const struct CommPlayerSupport *support);
struct PlayerRecord *COMM_PLAYER_SUPPORT_GetActiveRecord(struct CommPlayerSupport *support);
int COMM_PLAYER_SUPPORT_GetInfoCode(struct PlayerInfo *info);
int func_0202E848(struct PlayerInfo *info, u16 *outStored, u16 *outCurrent);
u8 sub_0202E888(void);
u8 sub_0202E8A4(u8 season);
u8 sub_0202E8B8(s32 season);
u8 sub_0202E8CC(s32 handle, s32 value);
int COMM_PLAYER_SUPPORT_FindPeerRecord(const struct PeerBook *book, struct PlayerLookup *lookup, const u8 *mac);
u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(const struct PlayerRecord *record);
u16 COMM_PLAYER_SUPPORT_GetRecordField(const struct PlayerRecord *record);
struct BlinkPalAnm *BLINK_PALANM_Create(u16 firstColor, u16 colorCount, u32 mode, u16 heapId);
void BLINK_PALANM_LoadPalettes(struct BlinkPalAnm *anm, void *archive, u32 fileId, u32 srcStart, u32 dstStart);
u32 BLINK_PALANM_Delete(struct BlinkPalAnm *anm);
s32 BLINK_PALANM_Update(struct BlinkPalAnm *anm);
void BLINK_PALANM_ResetPhase(struct BlinkPalAnm *anm);
u32 sub_0202EB0C(void);
int func_0202EB14(void);
void func_0202EB44(void);
u32 sub_0202EB4C(void);
void sub_0202EB60(u8 *outFavoriteColor, u8 *outBirthMonth);
u32 func_0202EB7C(struct HistoryOwner *owner, struct HistoryEntry *entry);
u32 func_0202EB9C(struct HistoryOwner *owner, struct HistoryEntry *entry);
u32 sub_0202EC24(const struct HistoryEntry *table);
u32 func_0202EC44(struct HistoryEntry *table, u32 key);
s32 func_0202EC7C(struct HistoryEntry *table, u32 key);
s32 func_0202ECB0(struct HistoryEntry *table, struct HistoryEntry *entry);
void func_0202ED00(struct HistoryEntry *table, u32 index);
void func_0202ED60(struct HistoryOwner *owner, struct HistoryEntry *entry, u32 mark);
void func_0202ED90(struct HistoryEntry *table, struct HistoryEntry *entry, u32 mark);
u32 func_0202EDE4(u32 maxValue, u32 value, u32 rangeStart, u32 rangeEnd, u32 margin);
u32 func_0202EE0C(u32 total, u32 rate, u32 start, u32 end, u32 margin);
struct TimeIcon *TIME_ICON_Create(struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, volatile u16 heapId);
struct TimeIcon *TIME_ICON_CreateNode(struct TcblList *nodeList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId);
void TIME_ICON_Init(struct TimeIcon *icon, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId);
struct TimeIcon *TIME_ICON_Alloc(u32 heapId);
void TIME_ICON_Start(struct TimeIcon *icon, struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval);
void TIME_ICON_Delete(struct TimeIcon *icon);
void TIME_ICON_TaskMain(struct Tcb *tcb, void *work);
void TIME_ICON_NodeMain(struct TcblNode *node, void *work);
void TIME_ICON_Update(struct TimeIcon *icon);
u32 sub_0202F114(const u8 *bits, u32 index);
u16 sub_0202F138(u32 row);
u32 sub_0202F144(u32 itemId);
u32 sub_0202F170(u16 itemId);
void func_0202F190(void *gameData, u32 mode, const struct PlayerRecord *record, u32 eventId, u16 index);
void func_0202F1B4(struct SaveData *save, u32 mode, const struct PlayerRecord *record, u32 eventId, u32 index);
void func_0202F27C(struct SaveData *save);
void func_0202F2AC(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day);
void func_0202F2F4(struct SaveData *save, u32 variant);
void func_0202F30C(struct SaveData *save, u32 eventId, u32 variant);
void func_0202F358(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day, u32 variant);
void func_0202F3AC(struct SaveData *save, u32 variant);
void func_0202F41C(struct SaveData *save, const struct PlayerRecord *record, u32 index);
void func_0202F464(struct SaveData *save);
void func_0202F47C(struct SaveData *save);
int func_0202F488(void *gameData, int stage);
int func_0202F498(struct SaveData *save, int stage);
void func_0202F630(void *gameData, u32 stage);
void func_0202F640(struct SaveData *save, u32 stage);
unsigned int func_0202F688(unsigned int id);
unsigned int func_0202F6D8(unsigned int id);
u32 func_0202F72C(void *unused, u16 value, u16 unused2);
int func_0202F738(struct SaveData *save, int unused);
void func_0202F768(void);
void func_0202F774(u32 on);
void func_0202F788(u32 mode);
void func_0202F7C4(u32 messageId);
void func_0202F870(void);
void func_0202F940(u32 messageId);
int func_0202F9F4(void);
int func_0202F9F8(void *unused, u32 *state);
int func_0202FAB0(void);
extern const char comm_player_support_File[];
extern const char blink_palanm_File[];
extern const s16 FX_SinCosTable_[];
extern char time_icon_File[];
extern struct ItemGfxExtra sItemGfxExtraTable[];
extern u8 ov088_id[];
extern u8 ov179_id[];
extern u8 d_021BD8E8[];
extern u8 d_021B68D8[];
extern u8 d_021BD574[];
extern struct OverlayLaunchWork sOverlayLaunchWork;
extern u8 sOverlayLaunchWorkArg[];


/* Hardware registers (main engine, A) used by the shutdown display reset. */
#define REG_DISPCNT_A       0x04000000


struct CommPlayerSupport *COMM_PLAYER_SUPPORT_Create(u32 heapId)
{
    struct CommPlayerSupport *support = func_02030734(heapId, 0x4c, 1, comm_player_support_File, 0x2c);

    COMM_PLAYER_SUPPORT_Init(support);
    return support;
}


/*
 * A pool-word-and-bx tail call into the ARM deallocator
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): eight bytes, no
 * prologue, no label in the listing. The destructor half of the
 * constructor at 0x0202E770, which allocates the same object.
 */
void COMM_PLAYER_SUPPORT_Delete(void *support)
{
    func_020307B0(support);
}


void COMM_PLAYER_SUPPORT_Init(struct CommPlayerSupport *support)
{
    MI_CpuFill8(support, 0, 0x4c);
    support->mode = 0;
    support->prevMode = 0;
    support->stashedMode = 0;
    MYSTATUS_Init(&support->current);
    MYSTATUS_Init(&support->previous);
}


/* Sets the mode word and copies a 32-byte record into the current slot. */
void COMM_PLAYER_SUPPORT_SetModeAndCurrent(struct CommPlayerSupport *support, u32 mode, const struct PlayerRecord *record)
{
    support->mode = mode;
    support->current = *record;
}


/*
 * Returns the current record.  Leaf accessor matched to give overlay call
 * sites a `matched` witness.
 */
struct PlayerRecord *COMM_PLAYER_SUPPORT_GetCurrent(struct CommPlayerSupport *support)
{
    return &support->current;
}


/* Witness leaf for ov093 BTL_SERVER_FLOW_ProcPlayerSupportHeal (tiny arm9 leaf). */
u32 COMM_PLAYER_SUPPORT_GetMode(struct CommPlayerSupport *support) { return support->mode; }


/* Remembers the mode and the current record, then enters mode 3. */
void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(struct CommPlayerSupport *support)
{
    support->prevMode = support->mode;
    support->previous = support->current;
    support->mode = 3;
}


/*
 * Moves the mode into the stashed slot and clears it.  Witness for the call
 * in ov010 EVENT_BATTLE_ProcBattleTask.
 */
void COMM_PLAYER_SUPPORT_StashMode(struct CommPlayerSupport *support)
{
    support->stashedMode = support->mode;
    support->mode = 0;
}


/* Nonzero if either the previous mode or the stashed mode is set. */
int COMM_PLAYER_SUPPORT_HasSavedMode(const struct CommPlayerSupport *support)
{
    if (support->prevMode != 0 || support->stashedMode != 0)
        return 1;
    return 0;
}


/* The saved record when a previous mode is set, else the current record. */
struct PlayerRecord *COMM_PLAYER_SUPPORT_GetActiveRecord(struct CommPlayerSupport *support)
{
    if (support->prevMode != 0)
        return &support->previous;
    return &support->current;
}


int COMM_PLAYER_SUPPORT_GetInfoCode(struct PlayerInfo *info)
{
    return INTRUDE_COMM_GetAreaSlotFlag(func_02012138(info));
}


/*
 * Reads the stored season of the record into *outStored and the season to
 * compare against into *outCurrent; returns 1 when they differ.  A fixed
 * record always reports 0.
 */
int func_0202E848(struct PlayerInfo *info, u16 *outStored, u16 *outCurrent)
{
    int isFixed;
    int stored;
    int current;

    isFixed = func_02012B70(info);
    if ((unsigned int)isFixed != 0) {
        stored = func_02012984(info);
        *outStored = (unsigned short)stored;
        *outCurrent = *outStored;
        return 0;
    } else {
        stored = func_02012984(info);
        *outStored = (unsigned short)stored;
        current = sub_0202E888();
        *outCurrent = (unsigned short)current;
        if (*outStored != *outCurrent) {
            return 1;
        } else {
            return 0;
        }
    }
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Four small season helpers. sub_0202E888 asks the ARM clock getter for a
 * 0x10-byte date and reduces its month to a two-bit season;
 * sub_0202E8A4 and sub_0202E8B8 step that value forwards and backwards
 * around the same four-element cycle.
 *
 * The `lsrs #0x1F` / `lsls #0x1E` / `subs` / `rors #0x1E` quartet in the
 * two steppers is a signed `% 4` and nothing else: `& 3` is a two
 * instruction `movs`/`ands`, which is exactly what sub_0202E888 uses at
 * the top, and `/ 4` carries a different rounding correction. Both
 * spellings appear four instructions apart in the same 80 bytes, so the
 * pair of them pins the signedness of each operand independently.
 *
 * The `lsls #0x18` / `lsrs #0x18` at the end of all three is the `(u8)`
 * return type.
 *
 * sub_0202E8CC is a twelve byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) that narrows its
 * second argument to `u8` on the way through.
 */
u8 sub_0202E888(void)
{
    struct RtcDate date;

    func_0203F4E4(&date);
    return (u8)((date.month - 1) & 3);
}


u8 sub_0202E8A4(u8 season)
{
    return (u8)((season + 1) % 4);
}


u8 sub_0202E8B8(s32 season)
{
    return (u8)((season + 3) % 4);
}


u8 sub_0202E8CC(s32 handle, s32 value)
{
    return GAME_DATA_SetSeason(handle, (u8)value);
}


/*
 * Matches a six-byte address against the three-slot address table of the
 * book (six bytes apart).  Both loop counters are `unsigned char` - the
 * lsls 0x18 / lsrs 0x18 pair after each increment is the narrowing, and the
 * comparisons are `blo`, so signed ints give `blt` instead.
 *
 * Do NOT bind the slot base to a local pointer: writing the inner compare
 * through a hoisted base makes the compiler move `adds r4, book, i*6` ahead
 * of the ok/j initialisers and differs by six bytes.  Indexing the table
 * inside the compare leaves the hoist where the original has it (after
 * `movs r6,#1` and `movs r3,#0`).
 *
 * EXACT*: the compared extent ran long by the follower's padding - the
 * follower at 0x0202E930 is a two-halfword `ldr r3,[pc]; bx r3`
 * long-branch veneer with no label of its own.
 */
int COMM_PLAYER_SUPPORT_FindPeerRecord(const struct PeerBook *book, struct PlayerLookup *lookup, const u8 *mac)
{
    unsigned char slot;
    unsigned char byte;

    if (lookup == 0) {
        return 0;
    }
    for (slot = 0; slot < 3; slot++) {
        int matches = 1;

        for (byte = 0; byte < 6; byte++) {
            if (book->macs[slot][byte] != mac[byte]) {
                matches = 0;
                break;
            }
        }
        if (matches == 1) {
            return func_02009D1C(lookup, &book->record, 0);
        }
    }
    return 0;
}


/*
 * A forwarding leaf after COMM_PLAYER_SUPPORT_FindPeerRecord's pop: a pool-word tail call to
 * func_020084F4 (the u16 pointer accessor), the caller's argument passed
 * through untouched ("ldr r3, [pc]; bx r3").  Called from the overlays only.
 */
u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(const struct PlayerRecord *record)
{
    return func_020084F4(record);
}


/* Forwarding leaf: pool-word tail call to func_02008534 (the u16 getter). */
u16 COMM_PLAYER_SUPPORT_GetRecordField(const struct PlayerRecord *record)
{
    return func_02008534(record);
}


/*
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x3c and 0x3d).
 *
 * The mode chain must write `targetMask` in EVERY arm, not into a local read
 * once at the end: with the local the scheduler hoists `movs r0, #0xf`
 * above the `cmp` and saves the branch, and the tail comes out two bytes
 * short (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
struct BlinkPalAnm *BLINK_PALANM_Create(u16 firstColor, u16 colorCount, u32 mode, u16 heapId)
{
    struct BlinkPalAnm *anm;

    anm = func_02030734(heapId, sizeof(struct BlinkPalAnm), 0, blink_palanm_File, 0x3c);
    anm->outColors = func_02030734(heapId, (u32)colorCount * 2, 0, blink_palanm_File, 0x3d);
    anm->firstColor = firstColor;
    anm->colorCount = colorCount;
    anm->phase = 0;
    anm->reserved12 = 0;
    anm->heapId = heapId;
    if (mode == 0xfffe) {
        anm->targetMask = 0xe;
    } else if (mode == 0xffff) {
        anm->targetMask = 0x1e;
    } else if (mode <= 3) {
        anm->targetMask = 0xf;
    } else {
        anm->targetMask = 0x1f;
    }

    return anm;
}


/*
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x83 and 0x84).
 * Loads the palette file and copies two rows of colorCount colors into the
 * source and target buffers.
 */
void BLINK_PALANM_LoadPalettes(struct BlinkPalAnm *anm, void *archive, u32 fileId, u32 srcStart, u32 dstStart)
{
    struct PaletteFile *file;
    struct ResourceFile *handle;
    u8 *colors;

    anm->srcColors = func_02030734(anm->heapId, (u32)anm->colorCount * 2, 0, blink_palanm_File,
                                   0x83);
    anm->dstColors = func_02030734(anm->heapId, (u32)anm->colorCount * 2, 0, blink_palanm_File,
                                   0x84);
    handle = func_02049F78(archive, fileId, (u32)(&file), anm->heapId);
    colors = file->colors;
    MI_CpuCopy8(colors + srcStart * 2, anm->srcColors, (int)((u32)anm->colorCount * 2));
    MI_CpuCopy8(colors + dstStart * 2, anm->dstColors, (int)((u32)anm->colorCount * 2));
    func_020307B0(handle);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * A four-call destructor: three owned buffers and then the object
 * itself, freed in the order dstColors, srcColors, outColors, self. The order
 * is the source's, because this compiler does not reorder calls.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 */
u32 BLINK_PALANM_Delete(struct BlinkPalAnm *anm)
{
    func_020307B0(anm->dstColors);
    func_020307B0(anm->srcColors);
    func_020307B0(anm->outColors);
    return func_020307B0(anm);
}


/*
 * blink_palanm.c: the per-frame BGR555 cross-fade.  Advances the phase word
 * at +0x10 by 0x400 (wrapping at 0x10000), takes the fade scale as
 * (FX_SinCosTable_[phase >> 4 pair, second entry] + 0x1000) / 2, blends
 * every color of the src row toward the dst row into the output row, then
 * hands the output row to func_02061CA4.
 *
 * Two facts closed it (wave 13).  The colors are u16 locals, not s32: with
 * `s32 b` the dst channel extraction is scheduled differently (46 out).  And
 * the final pack is `(r << 10) | (bl | (g << 5))`: the channel ORed last is
 * the one the compiler evaluates FIRST, so red is blended and held, then
 * blue, then green, exactly the image's order; the left-nested
 * `(r << 10) | (g << 5) | bl` evaluates green before blue.
 *
 * EXACT* because the listing extent runs 8 bytes long: the unlabelled leaf
 * at 0x0202EB04 follows the pool word.
 */
s32 BLINK_PALANM_Update(struct BlinkPalAnm *anm)
{
    s32 scale;
    u32 i;
    u16 from;
    u16 to;
    s32 red;
    s32 green;
    s32 blue;

    if (anm->phase + 0x400 >= 0x10000) {
        anm->phase = anm->phase - 0xFC00;
    } else {
        anm->phase = anm->phase + 0x400;
    }

    scale = (FX_SinCosTable_[((anm->phase >> 4) << 1) + 1] + 0x1000) / 2;

    for (i = 0; i < anm->colorCount; i++) {
        from = anm->srcColors[i];
        to = anm->dstColors[i];
        red = (u8)(((from >> 10) & 0x1f)
                   + (((((to >> 10) & 0x1f) - ((from >> 10) & 0x1f)) * scale) >> 12));
        blue = (u8)((from & 0x1f)
                    + ((((to & 0x1f) - (from & 0x1f)) * scale) >> 12));
        green = (u8)(((from >> 5) & 0x1f)
                     + (((((to >> 5) & 0x1f) - ((from >> 5) & 0x1f)) * scale) >> 12));
        anm->outColors[i] = (u16)((red << 10) | (blue | (green << 5)));
    }

    return func_02061CA4(anm->targetMask, anm->firstColor * 2, (u32)anm->outColors, anm->colorCount * 2);
}


/*
 * blink_palanm.c: resets the fade phase word at +0x10 of the blink object
 * (the word BLINK_PALANM_Update advances by 0x400 per frame).  An unlabelled leaf
 * with no prologue sitting after BLINK_PALANM_Update's pool word at 0x0202EB00, so
 * the listing folds it into BLINK_PALANM_Update's extent (204 against the real
 * 196).
 */
void BLINK_PALANM_ResetPhase(struct BlinkPalAnm *anm)
{
    anm->phase = 0;
}


/*
 * A pool-word-and-bx tail call into an ARM SDK entry point
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), eight bytes with no
 * prologue. Its result is compared against 1 by sub_0202EB4C, which is the
 * only caller.
 */
u32 sub_0202EB0C(void)
{
    return OS_IsRunOnTwl();
}


/* Nonzero when running on a DSi with both capability bits (0 and 5) set. */
int func_0202EB14(void)
{
    if (sub_0202EB0C()) {
        if (OS_GetParentalControlInfoPtr()->bit0 && OS_GetParentalControlInfoPtr()->bit5) {
            return 1;
        }
        return 0;
    }
    return 0;
}


/* Bare tail call into an ARM SDK leaf. */
void func_0202EB44(void)
{
    func_02087DC4();
}


/*
 * Neither call sets an argument register, so both callees are declared
 * with no parameters: the `blx` to the ARM helper follows a `cmp r0, #1`
 * and leaves r0 holding the 1 it was compared against, which is a
 * leftover and not an argument
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * Declaring either callee with a parameter costs an `adds r0, ...` the
 * original does not have.
 */
u32 sub_0202EB4C(void)
{
    if (sub_0202EB0C() == 1) {
        return OS_IsAgreeEULA();
    }
    return 1;
}


/*
 * Fills an 0x54-byte structure on the stack from an ARM SDK getter and
 * copies two of its bytes out through the two pointer parameters. The
 * whole 0x54 bytes are reserved even though only offsets 2 and 3 are
 * read, so the stack object is the SDK's structure and not a pair of
 * bytes; `add r0, sp, #0` is emitted twice, once for the call and once
 * as the base of the two loads, which is what a named local rather than
 * a re-taken address looks like here.
 */
void sub_0202EB60(u8 *outFavoriteColor, u8 *outBirthMonth)
{
    struct OwnerInfo info;

    OS_GetOwnerInfo(&info);
    *outFavoriteColor = info.favoriteColor;
    *outBirthMonth = info.birthMonth;
}


/*
 * Byte-correct, MATCH-capped.
 *
 * All 30 concrete bytes are right; the call to func_0202EB9C is the only open
 * site and it is blocked on `label`: the sole branch to 0x0202EB9C image-wide
 * is the one inside this function, so there is no witness outside the
 * compared range and no cut helps (the range cannot be smaller than the one
 * function holding the call).  It closes when func_0202EB9C itself gets a
 * manifest entry or a second caller appears.
 *
 * The trailing `*` is the unlabelled follower at 0x0202EB9C: the listing's
 * extent runs 32 bytes against 30 compiled because the follower carries no
 * `func_` label in the generated listing.
 */
u32 func_0202EB7C(struct HistoryOwner *owner, struct HistoryEntry *entry)
{
    if (func_0200856C(&entry->record) == 0) {
        return 0;
    }
    return func_0202EB9C(owner, entry);
}


/*
 * The history table dispatcher (look the entry up; remove and notify, or
 * insert by key under the count-capped policy).  Closed in wave 16 under
 * 1.1p1, no pin: the notify call is written in BOTH arms of the count test.
 * 1.1p1 then cross-jumps the two notify tails (the then-arm's `b` at
 * 0x0202EC04, reached by the inner `blo` as a jump to a jump) and no longer
 * merges the two func_0202ED00 calls, and the a/b/v register rotation
 * resolves with it.  `isMarked` is the +0x26 bit-3 field.
 *
 * Returns 1 when an existing entry was replaced and 2 when a new one was
 * inserted.
 */
u32 func_0202EB9C(struct HistoryOwner *owner, struct HistoryEntry *entry)
{
    struct HistoryEntry *table;
    u32 index;
    u32 value;

    table = func_0200974C(owner);
    index = func_0202ECB0(table, entry);

    if (index != 0x14) {
        if (table[index].isMarked)
            value = 1;
        else
            value = 0;
        func_0202ED00(table, index);
        func_0202ED60(owner, entry, value);
        return 1;
    }

    value = func_0200856C(&entry->record);
    if (func_0202EC44(table, value) < 5) {
        if (sub_0202EC24(table) >= 0x14)
            func_0202ED00(table, 0);
        func_0202ED60(owner, entry, 0);
    } else {
        func_0202ED00(table, func_0202EC7C(table, value));
        func_0202ED60(owner, entry, 0);
    }
    return 2;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Counts the leading run of occupied entries in a 20-entry array of
 * 0x28-byte records and returns the index of the first free one, or 20.
 * No prologue at all, because it calls nothing and needs no callee-saved
 * register, so `disasm.py` gives it no label.
 *
 * The occupancy test is `lsls #0x1B` / `lsrs #0x1F` on a byte at offset
 * 0x26, which is a one-bit unsigned bitfield at bit 4 and cannot be
 * written as a mask: `& 0x10` folds to `movs`/`ands` and a shift pair
 * with unequal amounts is a narrowing cast, not a field
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md,
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The record stride arrives as `movs r1, #0x28` / `muls` rather than a
 * scaled index because 0x28 is not a power of two.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 */
u32 sub_0202EC24(const struct HistoryEntry *table)
{
    u32 i;

    for (i = 0; i < 20; i++) {
        if (table[i].isOccupied == 0) {
            break;
        }
    }
    return i;
}


/*
 * Counts the occupied entries whose key matches, capped at five.  Same
 * 0x28-byte record as func_0202EC7C, matched next door.
 */
u32 func_0202EC44(struct HistoryEntry *table, u32 key)
{
    u32 i;
    u32 count = 0;

    for (i = 0; i < 0x14; i++) {
        u32 entryKey;
        if (!table[i].isOccupied)
            break;
        entryKey = func_0200856C(&table[i].record);
        if (entryKey == key)
            count++;
    }

    if (count > 5)
        count = 5;
    return count;
}


/* Index of the first occupied entry with the given key, or 0x14. */
s32 func_0202EC7C(struct HistoryEntry *table, u32 key)
{
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 entryKey;
        if (!table[i].isOccupied) break;
        entryKey = func_0200856C(&table[i].record);
        if (entryKey == key) return i;
    }
    return 0x14;
}


/*
 * Finds the first occupied entry whose two keys both match the reference
 * entry's, or 0x14 when there is none.
 */
s32 func_0202ECB0(struct HistoryEntry *table, struct HistoryEntry *entry)
{
    u32 keyA = func_02008530(&entry->record);
    u32 keyB = func_0200856C(&entry->record);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 candidateA, candidateB;
        if (!table[i].isOccupied)
            break;
        candidateA = func_02008530(&table[i].record);
        if (candidateA == keyA) {
            candidateB = func_0200856C(&table[i].record);
            if (candidateB == keyB)
                return i;
        }
    }
    return 0x14;
}


/*
 * Removes entry `index` by shifting the following entries down, then clears
 * the occupied flag of the tail.
 *
 * EXACT* only for the two bytes of alignment padding at 0x0202ED5E.  Closed
 * in wave 16 (the residue since wave 12 was the ldm/stm base order of the
 * record copy): the copy goes through a named destination and a source
 * derived from it (`dst = &table[index]; src = dst + 1; *dst = *src;`), and
 * the flag test must NOT share the `table + index` subexpression with them,
 * or the front end rematerialises table + index*0x28 and computes the
 * source first.  `(table + 1)[index]` shares only the index*0x28 product,
 * which is what the image keeps in r7.
 */
void func_0202ED00(struct HistoryEntry *table, u32 index)
{
    struct HistoryEntry *dst;
    struct HistoryEntry *src;

    if (index >= 0x14)
        return;

    if (index < 0x13) {
        while (1) {
            dst = &table[index];
            src = dst + 1;
            *dst = *src;
            if (!(table + 1)[index].isOccupied) {
                index++;
                break;
            }
            index++;
            if (index >= 0x13)
                break;
        }
    }

    while (index < 0x14) {
        table[index].isOccupied = 0;
        index++;
    }
}


/*
 * Stores the entry in the owner's table, then asks the owner whether the
 * entry's key now needs its follow-up (func_020095E8).  The key is read out
 * of the entry once into a named local and handed to func_02009750; that
 * call's answer decides whether func_020095E8 runs.
 */
void func_0202ED60(struct HistoryOwner *owner, struct HistoryEntry *entry, u32 mark)
{
    struct HistoryEntry *table = func_0200974C(owner);
    u32 key;

    func_0202ED90(table, entry, mark);

    key = func_0200856C(&entry->record);
    if (func_02009750(owner, key) != 0)
        func_020095E8(owner);
}


/*
 * Stores the entry at the first free index of the table (func_0202EC24),
 * after setting the bit-3 mark from `mark` and the bit-4 occupied flag.
 */
void func_0202ED90(struct HistoryEntry *table, struct HistoryEntry *entry, u32 mark)
{
    u32 index = sub_0202EC24(table);

    if (index >= 0x14)
        return;

    if (mark != 0)
        entry->isMarked = 1;
    else
        entry->isMarked = 0;

    entry->isOccupied = 1;

    table[index] = *entry;
}


/* Maps value into the band [rangeStart+margin/2, rangeEnd-margin/2]: 0 below it and maxValue above it. */
u32 func_0202EDE4(u32 maxValue, u32 value, u32 rangeStart, u32 rangeEnd, u32 margin)
{
    u32 halfMargin  = margin >> 1;
    u32 low = rangeStart + halfMargin;
    u32 high = rangeEnd - halfMargin;
    u32 offset;

    if (value <= low)
        return 0;
    if (value >= high)
        return maxValue;

    offset = value - low;
    return (offset * (maxValue << 8) / (high - low)) >> 8;
}


/*
 * A scaled-span helper: the span (end - start - margin) is raised eight
 * bits, scaled by the rate, divided by the total and shifted back down; the
 * quotient joins start and half of margin.
 *
 * The divide is the UNSIGNED runtime entry at 0x0209C2B0 (which
 * layout/runtime_arm9.txt names `_div_by_zero_check`, but the code there is
 * the unsigned divide entry itself; `signed / signed` emits 0x0209C0A4
 * instead).  Declared here under the front end's own name, `_u32_div_f`.
 *
 * Two spellings are load-bearing:
 *   - the quotient must be bound to its own local.  Written inline, the
 *     quotient stays live in r0 and the re-read of `margin` is scheduled
 *     into r1 BEFORE the shift.
 *   - the sum must associate as `(start + scaled) + (margin >> 1)`.  With
 *     `(scaled + start) + (margin >> 1)` the two `adds` land on the other
 *     operand order.
 * Together they put the quotient's high half in r2 and re-read `margin`
 * into r0, which is exactly the original's tail.
 */
u32 func_0202EE0C(u32 total, u32 rate, u32 start, u32 end, u32 margin)
{
    u32 span = ((end - start) - margin) << 8;
    u32 scaled = _u32_div_f(span * rate, total) >> 8;

    return (start + scaled) + (margin >> 1);
}


/*
 * Allocates and fills the 0x1c-byte time icon.  The heap id is the fifth
 * (stack) argument and is re-read from its slot for the second use (it is
 * also what TIME_ICON_Init's u16 tail parameter receives), so it is spelled
 * `volatile u16`.  When the optional task list is non-null the icon is
 * registered as a task (callback TIME_ICON_TaskMain); otherwise `task` is zeroed.
 *
 * Sibling of TIME_ICON_CreateNode, which builds the same object through the
 * TCBL_AddTask allocator instead.
 */
struct TimeIcon *TIME_ICON_Create(struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, volatile u16 heapId)
{
    struct TimeIcon *icon;

    icon = func_02030734(heapId, sizeof(struct TimeIcon), 0, time_icon_File, 0x49);
    TIME_ICON_Init(icon, refWin, fillColor, waitInterval, heapId);
    if (taskList != 0) {
        icon->task = func_02030DA8(taskList, TIME_ICON_TaskMain, icon, 0);
    } else {
        icon->task = 0;
    }
    icon->node = 0;
    icon->isActive = 1;
    return icon;
}


/*
 * Sibling of TIME_ICON_Create: the same 0x1c-byte TimeIcon, built through the
 * TCBL_AddTask node allocator instead of func_02030734.  The node is
 * stashed at +4 and +0 is zeroed, the mirror image of TIME_ICON_Create, which
 * registers a task into +0 and zeroes +4.  The node callback is
 * TIME_ICON_NodeMain.
 */
struct TimeIcon *TIME_ICON_CreateNode(struct TcblList *nodeList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId)
{
    struct TcblNode *node;
    struct TimeIcon *icon;

    node = TCBL_AddTask(nodeList, TIME_ICON_NodeMain, 0x1c, 0);
    icon = TCBL_GetWork(node);
    TIME_ICON_Init(icon, refWin, fillColor, waitInterval, heapId);
    icon->node = node;
    icon->task = 0;
    icon->isActive = 1;
    return icon;
}


/*
 * Fills in a freshly allocated icon: the heap id, the fill color, the frame
 * timing and a random start frame, then builds the 2x2 window from the
 * reference window's six accessors (x and y are the sum of position and
 * size, minus two, truncated to a byte).
 */
void TIME_ICON_Init(struct TimeIcon *icon, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId)
{
    u32 bgLayer, posY, height;
    u32 posX, width;
    u32 palette;

    icon->heapId = heapId;
    icon->waitCounter = 0;
    icon->fillColor = fillColor;
    icon->waitInterval = waitInterval;
    icon->frame = func_020056EC(8);
    icon->sheet = BMP_CreateFromArchive(0xC6, 0, 1, icon->heapId);

    bgLayer = BMP_WIN_GetBgLayer(refWin);
    posX = BMP_WIN_GetPosX(refWin);
    width = BMP_WIN_GetWidth(refWin);
    posY = BMP_WIN_GetPosY(refWin);
    height = BMP_WIN_GetHeight(refWin);
    palette = BMP_WIN_GetPalette(refWin);

    BMP_WIN_MakeScreen(icon->win = BMP_WIN_Create(bgLayer, (u8)((posX + width) - 2),
                                   (u8)((posY + height) - 2), 2, 2, palette, 1));
    func_02041B6C(BMP_WIN_GetBgLayer(icon->win));
}


/* Allocates an idle TimeIcon: heap id and frame sheet only; TIME_ICON_Start finishes it. */
struct TimeIcon *TIME_ICON_Alloc(u32 heapId)
{
    struct TimeIcon *icon = func_02030734(heapId, 0x1c, 0, time_icon_File, 0xa6);

    icon->heapId = (u16)heapId;
    icon->sheet = BMP_CreateFromArchive(0xc6, 0, 1, icon->heapId);
    icon->win = 0;
    icon->task = 0;
    icon->node = 0;
    return icon;
}


/*
 * TIME_ICON_Init's twin for an icon from TIME_ICON_Alloc: the window is built
 * the same way, then the icon is registered as a task of the caller's list.
 */
void TIME_ICON_Start(struct TimeIcon *icon, struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval)
{
    u32 bgLayer, posY, height;
    u32 posX, width;
    u32 palette;

    icon->waitCounter = 0;
    icon->fillColor = fillColor;
    icon->waitInterval = waitInterval;
    icon->frame = func_020056EC(8);

    bgLayer = BMP_WIN_GetBgLayer(refWin);
    posX = BMP_WIN_GetPosX(refWin);
    width = BMP_WIN_GetWidth(refWin);
    posY = BMP_WIN_GetPosY(refWin);
    height = BMP_WIN_GetHeight(refWin);
    palette = BMP_WIN_GetPalette(refWin);

    BMP_WIN_MakeScreen(icon->win = BMP_WIN_Create(bgLayer, (u8)((posX + width) - 2),
                                   (u8)((posY + height) - 2), 2, 2, palette, 1));
    func_02041B6C(BMP_WIN_GetBgLayer(icon->win));

    icon->node = 0;
    icon->task = func_02030DA8(taskList, TIME_ICON_TaskMain, icon, 0);
    icon->isActive = 1;
}


/*
 * Deletes the icon.  An icon that never got a window (neither task nor
 * node) only frees its sheet and itself; otherwise it clears the window,
 * frees the sheet and removes whichever of task and node it holds.
 */
void TIME_ICON_Delete(struct TimeIcon *icon)
{
    if (icon->task == 0 && icon->node == 0) {
        BMP_Delete(icon->sheet);
        func_020307B0(icon);
        return;
    }

    icon->isActive = 0;
    BMP_Clear(BMP_WIN_GetBmp(icon->win), icon->fillColor);
    BMP_WIN_TransferChars(icon->win);
    BMP_WIN_Delete(icon->win);
    BMP_Delete(icon->sheet);

    if (icon->task != 0) {
        func_02030EAC(icon->task);
        func_020307B0(icon);
        return;
    }

    if (icon->node != 0)
        TCBL_DeleteTask(icon->node);
}


/* Task callback of an icon created with a task list. */
void TIME_ICON_TaskMain(struct Tcb *tcb, void *work)
{
    TIME_ICON_Update(work);
}


/* Node callback of an icon created with a TCBL node. */
void TIME_ICON_NodeMain(struct TcblNode *node, void *work)
{
    TIME_ICON_Update(work);
}


/*
 * One tick of the icon: while the wait counter runs down it only counts;
 * at zero it fills the window, copies the next 16x16 frame of the sheet
 * into it, commits the window and reloads the counter.  The frame wraps at 8.
 */
void TIME_ICON_Update(struct TimeIcon *icon)
{
    if (icon->isActive == 0)
        return;

    if (icon->waitCounter == 0) {
        BMP_Clear(BMP_WIN_GetBmp(icon->win), icon->fillColor);
        BMP_Blit(icon->sheet, BMP_WIN_GetBmp(icon->win), 0,
                      (u32)icon->frame << 4, 0, 0, 0x10, 0x10, 0);
        BMP_WIN_TransferChars(icon->win);

        icon->waitCounter = icon->waitInterval;
        icon->frame = icon->frame + 1;

        if (icon->frame == 8)
            icon->frame = 0;
    } else {
        icon->waitCounter = icon->waitCounter - 1;
    }
}


/*
 * Bit `index` of a byte array, inverted: 1 when the bit is clear.
 * Unlabelled leaf in the 0x0202F114..0x0202F190 gap.
 *
 * The byte index and the bit number are both `u8` locals: the original
 * truncates each with its own `lsls #0x18`/`lsrs #0x18` pair, and `i >> 3`
 * or `i & 7` folded into the shift expression loses them (the front end
 * knows both are already in range and drops the conversions).
 */
u32 sub_0202F114(const u8 *bits, u32 index)
{
    u8 byteIndex = (u8)(index >> 3);
    u8 bitIndex = (u8)(index & 7);

    if ((bits[byteIndex] & (1 << bitIndex)) != 0)
        return 0;
    return 1;
}


/*
 * First field (item id) of row `row` of the 0x2E-row item graphics extra
 * table; the sibling lookups sub_0202F144 (second field) and sub_0202F170
 * (row index) share it.  All three are unlabelled leaf functions in the
 * 0x0202F114..0x0202F190 gap.
 */
u16 sub_0202F138(u32 row)
{
    return sItemGfxExtraTable[row].itemId;
}


/*
 * Second field of the row whose item id matches, 0 when there is none.
 */
u32 sub_0202F144(u32 itemId)
{
    s32 i;

    for (i = 0; i < 0x2E; i++) {
        if (sItemGfxExtraTable[i].itemId == itemId)
            return sItemGfxExtraTable[i].value;
    }
    return 0;
}


/*
 * Row index of the entry whose item id matches, 0 when there is none.
 * Unsigned loop here, signed in sub_0202F144.
 */
u32 sub_0202F170(u16 itemId)
{
    u32 i;

    for (i = 0; i < 0x2E; i++) {
        if (sItemGfxExtraTable[i].itemId == itemId)
            return i;
    }
    return 0;
}


void func_0202F190(void *gameData, u32 mode, const struct PlayerRecord *record, u32 eventId, u16 index)
{
    func_0202F1B4(func_020185F0(gameData), mode, record, eventId, index);
}


/*
 * Seven-way mode switch around a func_02017DBC / func_02017DE4 bracket.
 * Closed in wave 16: the 129-byte residue was NOT an allocator tie but the
 * source's gotos.  Every case is written out in full (no shared labels) and
 * case 2's guard carries the call run in BOTH arms; 1.1p1's own
 * cross-jumping then produces the image's `b` into case 0's
 * func_0202F464/func_0202F47C tail, the kept `bne; b` pair in case 2, and
 * the head that spills the selector and holds the fifth parameter in r7.
 * The call at +0x58 is attested by func_0202F47C (same shard).  0x7532 is
 * a plain constant.
 */
void func_0202F1B4(struct SaveData *save, u32 mode, const struct PlayerRecord *record, u32 eventId, u32 index)
{
    u32 savedFlag = func_02017DBC(save);

    switch (mode) {
    case 0:
        func_0202F2F4(save, 0);
        func_0202F30C(save, eventId, 1);
        func_0202F41C(save, record, index);
        func_0202F464(save);
        func_0202F47C(save);
        break;
    case 1:
        func_0202F30C(save, 0x7532, 1);
        func_0202F464(save);
        func_0202F47C(save);
        break;
    case 2:
        if (POKE_TOOL_IsBoxOwnedByPlayer(save, record) == 1) {
            func_0202F30C(save, eventId, 1);
            func_0202F41C(save, record, index);
        } else {
            func_0202F3AC(save, 1);
            func_0202F30C(save, eventId, 1);
            func_0202F41C(save, record, index);
        }
        func_0202F47C(save);
        break;
    case 3:
    case 4:
        break;
    case 5:
        func_0202F30C(save, eventId, 0);
        func_0202F41C(save, record, index);
        func_0202F47C(save);
        break;
    case 6:
        func_0202F30C(save, eventId, 1);
        break;
    }
    func_02017DE4(save, savedFlag);
}


/* Stores today's RTC date into save variables 0x92 to 0x94. */
void func_0202F27C(struct SaveData *save)
{
    struct RtcDate date;

    func_0203F4E4(&date);

    POKE_TOOL_SetBoxValue(save, 0x92, date.year);
    POKE_TOOL_SetBoxValue(save, 0x93, date.month);
    POKE_TOOL_SetBoxValue(save, 0x94, date.day);
}


void func_0202F2AC(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day)
{
    if (func_02017E88(save, 0xAA, 0) == 1)
        func_0202F358(save, eventId, year, month, day, 0);
    else
        func_0202F358(save, eventId, year, month, day, 1);
    func_0202F464(save);
    POKE_TOOL_SetBoxValue(save, 0x6D, 1);
}


void func_0202F2F4(struct SaveData *save, u32 variant)
{
    func_0202F358(save, 0, 0, 0, 0, variant);
}


/* Stores the event id with today's date into the given variant. */
void func_0202F30C(struct SaveData *save, u32 eventId, u32 variant)
{
    struct RtcDate date;

    func_0203F4E4(&date);

    if (ZONEDATA_IsRawZoneGroup4CTo69((u16)eventId) == 1)
        func_0202F358(save, 0x753E, date.year, date.month, date.day, variant);
    else
        func_0202F358(save, eventId, date.year, date.month, date.day, variant);
}


/*
 * Installs the four save variables of one variant (event id, year, month,
 * day).  The base index is the variant flag plus 0x95 for the event id,
 * then that same flag times three plus 0x8f/0x90/0x91 for the date.
 */
void func_0202F358(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day, u32 variant)
{
    u8 base = (variant == 1);

    POKE_TOOL_SetBoxValue(save, base + 0x95, eventId);
    base = (u8)(base * 3);
    POKE_TOOL_SetBoxValue(save, base + 0x8F, year);
    POKE_TOOL_SetBoxValue(save, base + 0x90, month);
    POKE_TOOL_SetBoxValue(save, base + 0x91, day);
}


/*
 * Reads the four save variables of one variant and hands them, with the
 * opposite variant, to func_0202F358 (copies a variant to the other one).
 */
void func_0202F3AC(struct SaveData *save, u32 variant)
{
    u8 base = (variant == 1);
    u32 eventId, year, month, otherVariant, day;

    eventId = func_02017E88(save, base + 0x95, 0);
    base = (u8)(base * 3);
    year = func_02017E88(save, base + 0x8F, 0);
    month = func_02017E88(save, base + 0x90, 0);
    day = func_02017E88(save, base + 0x91, 0);

    otherVariant = (variant == 0);
    func_0202F358(save, eventId, year, month, day, otherVariant);
}


/*
 * Stores the record's name (variable 0x8d), key (0x9a) and kind (7) and
 * frees the name string.
 */
void func_0202F41C(struct SaveData *save, const struct PlayerRecord *record, u32 index)
{
    struct Strbuf *name = (struct Strbuf *)func_02008510(record, index);
    u32 kind = func_02008530(record);
    u32 key = func_02008550(record);

    POKE_TOOL_SetBoxValue(save, 0x8d, (u32)name);
    POKE_TOOL_SetBoxValue(save, 0x9a, key);
    POKE_TOOL_SetBoxValue(save, 7, kind);
    STRBUF_Delete(name);
}


/* Copies save variable 0x9e into 0x99. */
void func_0202F464(struct SaveData *save)
{
    u32 value = func_02017E88(save, 0x9e, 0);

    POKE_TOOL_SetBoxValue(save, 0x99, value);
}


/*
 * Unlabelled 12-byte Thumb leaf (a tail call through a pool word to
 * POKE_TOOL_SetBoxValue with id 0x77, value 0x15) after func_0202F464; filed as the
 * witness for func_0202F1B4's call at +0x58, the only branch to it
 * image-wide.
 */
void func_0202F47C(struct SaveData *save)
{
    POKE_TOOL_SetBoxValue(save, 0x77, 0x15);
}


int func_0202F488(void *gameData, int stage)
{
    return func_0202F498(func_020185F0(gameData), stage);
}


/*
 * Nonzero when the save variables match the expected state of the given
 * stage (0 to 7): variable 5, the event id (0x96), the done flag (0x6d),
 * the count from POKE_TOOL_IsBoxShiny and whether any of the date variables is set.
 */
int func_0202F498(struct SaveData *save, int stage)
{
    u32 savedFlag = func_02017DBC(save);
    int variable5 = func_02017E88(save, 5, 0);
    int eventId = func_02017E88(save, 0x96, 0);
    int done = func_02017E88(save, 0x6d, 0);
    int count = POKE_TOOL_IsBoxShiny(save);
    int anyDate = 0;

    if (func_02017E88(save, 0x8f, anyDate) != 0
        || func_02017E88(save, 0x90, anyDate) != 0
        || func_02017E88(save, 0x91, anyDate) != 0
        || func_02017E88(save, 0x95, anyDate) != 0) {
        anyDate = 1;
    }
    func_02017DE4(save, savedFlag);

    switch (stage) {
    case 0:
        if (variable5 == 0xfb && eventId == 0x753a && done == 1 && anyDate == 0 && count == 0) {
            return 1;
        }
        break;
    case 1:
        if (variable5 == 0xfb && eventId == 0x753b && done == 1 && anyDate == 0 && count == 0) {
            return 1;
        }
        break;
    case 2:
        if ((unsigned)(variable5 - 0xf3) <= 2 && eventId == 0x753c && count == 1 && done == 1
            && anyDate == 0) {
            return 1;
        }
        break;
    case 3:
        if ((unsigned)(variable5 - 0xf3) <= 2 && eventId == 0x753d && count == 1 && done == 1
            && anyDate == 0) {
            return 1;
        }
        /* fall through */
    case 4:
        if (variable5 == 0x287 && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    case 5:
        if (variable5 == 0x288 && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    case 6:
        if (variable5 == 0x289 && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    case 7:
        if (variable5 == 0x1ec && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    }
    return 0;
}


/*
 * Promoted out of src/pending: the callee func_0202F640 became a manifest
 * entry this pass, so the second call site resolves on `matched`.
 */
void func_0202F630(void *gameData, u32 stage)
{
    func_0202F640(func_020185F0(gameData), stage);
}


/*
 * The two trailing pool words (0x753B / 0x753D, bare literals with no
 * relocation) are part of the compiled body, so the compared output is 72
 * bytes against the worklist's 62 code bytes; the listing extent runs to the
 * end of the packet.  All four call sites resolve on `label`.
 */
void func_0202F640(struct SaveData *save, u32 stage)
{
    u32 savedFlag = func_02017DBC(save);

    if (func_0202F498(save, stage) == 1) {
        switch (stage) {
        case 0:
            POKE_TOOL_SetBoxValue(save, 0x96, 0x753B);
            break;
        case 2:
            POKE_TOOL_SetBoxValue(save, 0x96, 0x753D);
            break;
        }
    }
    func_02017DE4(save, savedFlag);
}


/*
 * Unlabelled Thumb leaf (no entry in layout/function_starts.txt; the listing
 * shows the range as ARM). Compiled body is 80 bytes including its literal
 * pool. Witness for ov131 func_021D8784 (bl from 0x021D878C / 0x021D8794).
 * Maps an id range to a bank number (0x0202F688) and to an index inside
 * that bank (0x0202F6D8).
 */
unsigned int func_0202F688(unsigned int id) {
  if(id<0x7531) return 89;
  if(id<0x9c41) { if(id-0x7531>=14) return 89; return 92; }
  if(id<0xea61) { if(id-0x9c41>=109) return 89; return 90; }
  if(id<=65535) return 91;
  return 89;
}


/* The in-bank index half of the pair above (see func_0202F688); 84 bytes with its pool. */
unsigned int func_0202F6D8(unsigned int id) {
  if(id<0x7531) { if(id>=117) return 2; }
  else if(id<0x9c41) { id-=0x7531; if(id>=14) return 2; }
  else if(id<0xea61) { id-=0x9c41; if(id>=109) return 2; }
  else { if(id<=65535) { id-=0xea61; if(id>=3) return 0; } else return 2; }
  return id;
}


/*
 * Twelve-byte tail forwarder (pool word and bx) to func_020212E4 with the
 * second argument; witness for ov131 P_STA_SKILL_HandleTouchForget (bl at +0x13A), whose
 * call supplies a pointer, a halfword and a second halfword.
 */
u32 func_0202F72C(void *unused, u16 value, u16 unused2)
{
    return func_020212E4(value);
}


/* 1 when none of the four save variables 0x36 to 0x39 passes func_020212E4. */
int func_0202F738(struct SaveData *save, int unused)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (func_020212E4((u16)func_02017E88(save, i + 0x36, 0)) != 0) {
            return 0;
        }
    }
    return 1;
}


/*
 * An unlabelled tail-call leaf (it saves nothing, so disasm.py prints it as
 * .word data): func_0202F788(0).  With func_0202F774 it is the callback pair
 * GFL_USE_InitSystem (gfl_use.c boot) hands to BACKUP_SYSTEM_Init(7, ...).  Filed apart
 * from func_0202F774 on purpose: the only pool words naming 0x0202F789 that
 * are outside a two-function range are each other's, so as one unit neither
 * site has a witness
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 */
void func_0202F768(void)
{
    func_0202F788(0);
}


/*
 * The second unlabelled tail-call leaf of the callback pair GFL_USE_InitSystem
 * hands to BACKUP_SYSTEM_Init: a flag mapped to mode 2 (clear) or 1 (set) for
 * func_0202F788.  Filed apart from func_0202F768 so each pool word
 * witnesses the other.
 */
void func_0202F774(u32 on)
{
    u32 mode;

    if (on == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    func_0202F788(mode);
}


/*
 * The power callback reached from func_0202F768 as func_0202F788(0) (and
 * registered through the pool word 0x0202F789 at 0x0202F784).  It never
 * returns: after the shutdown work it spins on GFL_USE_PollPowerExit.
 */
void func_0202F788(u32 mode)
{
    func_02007084();
    func_0202F7C4(mode);
    if (GFL_NET_GetRunState()) {
        GFL_NET_ClearExitFlag();
        GFL_NET_Exit(0);
        GFL_NET_IRC_WIRELESS_Exit();
        do {
            GFL_NET_Main();
        } while (!GFL_NET_IsSessionNull());
    }
    func_020351A0(2);
    for (;;)
        GFL_USE_PollPowerExit();
}


/*
 * The two calls to this packet's own followers (0x0202F870 at +0x7A and
 * 0x0202F940 at +0x80) are the only sites that need the `matched` class:
 * their compared range was their only `label` witness until those two files
 * existed.  Everything else is `label`.
 *
 * A display reset for the shutdown screen: two func_0207D534 writes of
 * 0xFFFFFFF0 to the master brightness registers of both engines, the engine
 * setup calls, then three read-modify-write pairs on the hardware registers
 * (DISPCNT: clear bits 8-12, set bit 9, then clear 0xE000; BG1CNT: clear all
 * but 0x43, set 4, then clear bit 6; BG1HOFS and BLDCNT zeroed), the two
 * packet-local sub-inits, and the brightness registers set again.
 *
 * Note the compiler derives BG1CNT and BG1HOFS from the pooled
 * master-brightness address with `subs r0, #0x62` / `#0x58`, and reuses the
 * value 4 in r6 as `lsls r0, r6, #0x18` for the DISPCNT base; both fall out
 * of writing the plain literals, so no symbol for the registers is needed.
 */
void func_0202F7C4(u32 messageId)
{
    func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_A, 0xFFFFFFF0);
    func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_B, 0xFFFFFFF0);
    func_0207D3AC(0);
    GX_VBlankIntr(0);
    func_020808F4();
    func_020809A0();
    func_0207FDCC(4);
    func_0207D4B0(1, 0, 0);
    REG32(REG_DISPCNT_A) = (REG32(REG_DISPCNT_A) & 0xFFFFE0FF) | 0x200;
    REG32(REG_DISPCNT_A) = REG32(REG_DISPCNT_A) & 0xFFFF1FFF;
    REG16(REG_BG1CNT_A) = (REG16(REG_BG1CNT_A) & 0x43) | 4;
    REG16(REG_BG1CNT_A) = REG16(REG_BG1CNT_A) & 0xFFBF;
    REG32(REG_BG1HOFS_A) = 0;
    REG16(REG_BLDCNT_A) = 0;
    func_0202F870();
    func_0202F940(messageId);
    func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_A, 0);
    func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_B, 0x10);
}


/*
 * Three copies of one block: register a handle with ARC_UTIL_LoadMember(0x16, i, 0, 7),
 * probe it (func_02062A4C / 02062B30 / 02062A98 with a stack out-pointer), and
 * on success clear 0x20 bytes of the record's buffer through DWCi_ScreenDC_FlushRange and
 * fill it back through MIi_CpuCopy16 with the current frame-tick from the
 * getter (func_0207E24C / func_0207DFB4).  The handle is released with
 * func_020307B0 after each block.
 *
 * The idiom that makes this EXACT: the word each block reads twice (size of
 * the character data, size of the screen data) is written as an ASSIGNMENT
 * INSIDE the third argument of the second call --
 * `MIi_CpuCopy16(chars[5], getter(), charSize = chars[4])`.  mwcc evaluates
 * the arguments of a call right-to-left, so the assignment's load lands
 * before the getter call, and the value it produces is live across that
 * call, which is what puts it in r5 and forces the original's
 * `push {r3, r4, r5, lr}` frame.  Spelling the same value as a statement
 * before the call puts the load one statement early; spelling it inline in
 * both calls leaves the load where it is scheduled and loses r5 (6 bytes
 * short).  See docs/idioms/
 * an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register.md
 *
 * Archive 0x16 members 1, 2 and 0 are the character data, screen data and
 * palette of the shutdown screen.
 */
void func_0202F870(void)
{
    u32 *chars;
    u32 *screen;
    u32 *palette;
    u32 *paletteHeader;
    u32 res;
    u32 charSize;
    u32 screenSize;

    func_02082A7C(0, (u32)func_0207E24C(), 0x4000);
    res = ARC_UTIL_LoadMember(0x16, 1, 0, 7);
    if (func_02062A4C((struct ArchiveRecord *)res, (void **)(&chars)) != 0) {
        DWCi_ScreenDC_FlushRange(chars[5], chars[4]);
        MIi_CpuCopy16(chars[5], (u32)func_0207E24C(), charSize = chars[4]);
    }
    func_020307B0((void *)res);
    res = ARC_UTIL_LoadMember(0x16, 2, 0, 7);
    if (func_02062B30((void *)res, (void **)(&screen)) != 0) {
        DWCi_ScreenDC_FlushRange((u32)screen + 0xc, screen[2]);
        MIi_CpuCopy16((u32)screen + 0xc, (u32)func_0207DFB4(), screenSize = screen[2]);
    }
    func_020307B0((void *)res);
    res = ARC_UTIL_LoadMember(0x16, 0, 0, 7);
    func_02062AD4((struct ArchiveRecord *)res, (void **)(&paletteHeader));
    if (func_02062A98((struct ArchiveRecord *)res, (void **)(&palette)) != 0) {
        DWCi_ScreenDC_FlushRange(palette[3], 0x20);
        MIi_CpuCopy16(palette[3], 0x05000000, 0x20);
    }
    func_020307B0((void *)res);
}


/*
 * EXACT* -- the inferred extent (184 bytes) runs 4 bytes past this
 * function's own 180, over the unlabelled 4-byte leaf at 0x0202F9F4
 * (`movs r0, #1; bx lr`, i.e. `return 1;`), which saves no lr and so gets no
 * label from disasm.py -- docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md.  That leaf is worth seeding
 * into layout/function_starts.txt by the integrator; it is not ours to edit.
 * The follower is also not covered by the manifest entry below, and no `tu`
 * range may span it.
 *
 * Fills the tilemap of the shutdown screen with consecutive tile numbers,
 * then draws message `messageId` of message bank 2 into a 30x16 tile bitmap.
 */
void func_0202F940(u32 messageId)
{
    u16 *tilemap;
    s32 column;
    s32 row;
    u16 tile;
    struct Bmp *bmp;
    struct GfFont *font;
    struct MsgBank *msgBank;
    struct Strbuf *message;

    tilemap = (u16 *)func_0207DFB4();
    tile = 0x20;
    for (row = 4; row < 0x14; row++) {
        for (column = 1; column < 0x1f; column++) {
            tilemap[(row << 5) + column] = tile;
            tile = tile + 1;
        }
    }
    MIi_CpuClear16(0x7777, (u32)func_0207E24C() + 0x400, 0x3C00);
    bmp = BMP_CreateFromVram((void *)((u32)func_0207E24C() + 0x400), 0x1e, 0x10, 0x20, 7);
    font = GF_FONT_Create(0x17, 0, 0, 0, 7);
    msgBank = func_02045B38(0, 2, 2, 7);
    message = func_02045EC0(msgBank, messageId);
    PRINTSYS_PrintColor(bmp, 0, 0, message, font, 0x1167);
    STRBUF_Delete(message);
    MSGDATA_Delete(msgBank);
    GF_FONT_Delete(font);
    BMP_Delete(bmp);
}


int func_0202F9F4(void)
{
    return 1;
}


/*
 * wave 17 (overlay_id class): EXACT. The pooled overlay-id sites ov088_id
 * (88) and ov179_id (179) resolve as `overlay_id` (a layout overlay index,
 * loaded by a pc-relative load of this function, reaching the id register
 * of a known overlay loader), which was the last blocker.
 *
 * A five-state proc driver, the net_save.c shape of
 * src/pending/func_02010AC4.c: state 0 starts overlay 0x58's proc on
 * &sOverlayLaunchWork.mode, states 1 to 3 (re)start overlay 0xB3's proc on
 * the work block, with state 2 bailing to 4 when `aborted` is set, and
 * state 4 starts overlay 0x58's second proc and resets to 0.
 *
 * Two pool words both name 0x02146948 (0x0202FA9C, the base of the field
 * stores, and 0x0202FAA8, the third call argument).  mwcc merges pool words
 * per symbol and CSEs the loaded address, so one symbol gives one word and
 * reuses r2 as the store base (184 -> 172 bytes, 98 out).  Two symbols at
 * the same address reproduce both words; sOverlayLaunchWorkArg is that
 * second name.  The state-2 test is written with the work in the `if` and
 * the bail-out after it (fall-through arm is the source order), so its
 * `*state = 4` block is the one state 3 branches back into.
 */
int func_0202F9F8(void *unused, u32 *state)
{
    switch (*state) {
    case 0:
        PROCSYS_PushGlobal((u32)ov088_id, (u32)d_021BD8E8, (u32)&sOverlayLaunchWork.mode);
        *state = 1;
        break;
    case 1:
        sOverlayLaunchWork.mode = 1;
        sOverlayLaunchWork.stage = 0;
        sOverlayLaunchWork.enabled = 1;
        sOverlayLaunchWork.aborted = 0;
        PROCSYS_PushGlobal((u32)ov179_id, (u32)d_021B68D8, (u32)sOverlayLaunchWorkArg);
        *state = 2;
        break;
    case 2:
        if (sOverlayLaunchWork.aborted == 0) {
            sOverlayLaunchWork.stage = 1;
            sOverlayLaunchWork.aborted = 0;
            PROCSYS_PushGlobal((u32)ov179_id, (u32)d_021B68D8, (u32)sOverlayLaunchWorkArg);
            *state = 3;
            break;
        }
        *state = 4;
        break;
    case 3:
        sOverlayLaunchWork.stage = 2;
        sOverlayLaunchWork.aborted = 0;
        PROCSYS_PushGlobal((u32)ov179_id, (u32)d_021B68D8, (u32)sOverlayLaunchWorkArg);
        *state = 4;
        break;
    case 4:
        PROCSYS_PushGlobal((u32)ov088_id, (u32)d_021BD574, 0);
        *state = 0;
        break;
    }
    return 0;
}

int func_0202FAB0(void)
{
    return 1;
}
