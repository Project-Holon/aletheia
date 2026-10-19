/*
 * file:     p_sta_ribbon.c
 * unit:     yes
 * function: P_STA_RIBBON_Create, P_STA_RIBBON_Delete, P_STA_RIBBON_Main, P_STA_RIBBON_LoadArcGraphics, P_STA_RIBBON_FreeArcGraphics, P_STA_RIBBON_CreateObjects, P_STA_RIBBON_DeleteObjects, P_STA_RIBBON_UpdateInput, P_STA_RIBBON_UpdateKeys, P_STA_RIBBON_UpdateTouch, P_STA_RIBBON_GetTouchedRow, P_STA_RIBBON_SnapCursorToScroll, P_STA_RIBBON_SelectRow, P_STA_RIBBON_Scroll, P_STA_RIBBON_Init, P_STA_RIBBON_Show, P_STA_RIBBON_Deactivate, P_STA_RIBBON_Hide, P_STA_RIBBON_CollectOwned, P_STA_RIBBON_Noop, P_STA_RIBBON_DrawRow, P_STA_RIBBON_UpdateRows, P_STA_RIBBON_GetOwnedIndex, P_STA_RIBBON_GetRowOwnedIndex, P_STA_RIBBON_GetRowY, P_STA_RIBBON_PrintDetail, P_STA_RIBBON_ShowDetail, P_STA_RIBBON_FreeDetailWindows, P_STA_RIBBON_HideDetail
 * address:  0x021D87E0
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from p_sta_oam.c: 0x021D87E0-0x021D96B0. Cuts at the __FILE__ anchor functions (layout/file_anchors.txt);
 * the functions in this range use PStaRibbonWork (PStatusWork.ribbonWork).
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   STRBUF_Create 0x020457B0 arm
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   P_STA_RIBBON_FileName 0x021DC834 data a1
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   BMP_CreateFromVram 0x02043754 arm
 *   BMP_Delete 0x020437AC arm
 *   P_STA_RIBBON_KindCountInit 0x021DC2B0 data a1
 *   BMP_GetPixels 0x020437D4 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   P_STA_RIBBON_GetRibbonDescMsg 0x021DBF94 thumb ov131
 *   P_STA_RIBBON_InfoTable 0x021DC2F8 data a4
 *   P_STATUS_SetInputEnable 0x021D5A9C thumb ov131
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STA_OAM_CreateManager 0x021DBA90 thumb ov131
 *   P_STA_OAM_DeleteManager 0x021DBAC0 thumb ov131
 *   P_STA_OAM_CreateBitmapActors 0x021DBAD0 thumb ov131
 *   P_STA_OAM_DeleteBitmapActors 0x021DBC3C thumb ov131
 *   P_STA_OAM_SetBitmapActorsEnabled 0x021DBCA4 thumb ov131
 *   P_STA_OAM_TransferBitmap 0x021DBCF4 thumb ov131
 *   P_STA_OAM_SetBitmapActorsPos 0x021DBE2C thumb ov131
 *   P_STA_RIBBON_GetRibbonInfo 0x021DBF2C thumb ov131
 *   _u32_div_f                   0x0209C2B0  arm
 */

#include "p_status_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;

struct Actor;
struct Bmp;
struct BmpWin;
struct MsgBank;
struct Strbuf;
struct WordSet;

enum {
    STA_RIBBON_ROW_COUNT = 10,          /* rows on screen, used as a ring buffer while scrolling */
    STA_RIBBON_ROW_HEIGHT = 24,         /* pixels */
    STA_RIBBON_VISIBLE_ROWS = 6,
    STA_RIBBON_MAX = 80                 /* entries of the ribbon table */
};

/* Keys read by the page (trigger and repeat masks). */
enum {
    STA_RIBBON_KEY_A = 0x01,
    STA_RIBBON_KEY_B = 0x02,
    STA_RIBBON_KEY_UP = 0x40,
    STA_RIBBON_KEY_DOWN = 0x80
};

/* PStatusWork.inputType */
enum {
    STA_RIBBON_INPUT_KEYS,
    STA_RIBBON_INPUT_TOUCH
};

/* Sound effects. */
enum {
    STA_RIBBON_SE_CURSOR = 0x548,
    STA_RIBBON_SE_SELECT = 0x54C,
    STA_RIBBON_SE_CANCEL = 0x551,
    STA_RIBBON_SE_SCROLL = 0x645
};

/* PStatusWork.buttonActor indices used here. */
enum {
    STA_RIBBON_BUTTON_PAGE_TAB = 2,
    STA_RIBBON_BUTTON_B = 7
};

/* PStatusWork.objRes indices used here (the last character data, palette and cell resources are the ribbon ones). */
enum {
    STA_RIBBON_RES_DETAIL_PLTT = 7,
    STA_RIBBON_RES_ROW_PLTT = 8,
    STA_RIBBON_RES_DETAIL_CELL = 36
};

/* Character resource (a different file layout than StaGraphicsFile): pixels start at pixels. */
typedef struct StaRibbonCharData {
    u8 pad_0[0x14];
    u8 *pixels;                         /* 0x14 */
} StaRibbonCharData;

/* One of the ten list rows (0x14 bytes). */
typedef struct StaRibbonRow {
    u16 ownedIdx;                       /* 0x00: index into owned[] shown in this row, 0xFFFF = empty */
    u8 pad_2[6];
    u32 printPending;                   /* 0x08: 1 = a text print is running for the row */
    struct Bmp *bmp;                    /* 0x0C: name text, drawn into OBJ VRAM */
    StaOamBitmapActors *actors;  /* 0x10: actors that show the bitmap */
} StaRibbonRow;

/* One ribbon the Pokemon has (8 bytes). */
typedef struct StaRibbonOwned {
    u32 isOwned;                        /* 0x00 */
    u8 ribbonNo;                        /* 0x04: row of the ribbon table */
    u8 category;                        /* 0x05: ribbon kind, 0..4; gives the kind name message */
    u8 number;                          /* 0x06: how many ribbons of this kind came before, plus the kind start */
    u8 pad_7;
} StaRibbonOwned;

/* Ribbon page work (page 2, PStatusWork.ribbonWork, 0x3B8 bytes). */
struct PStaRibbonWork {
    int isActive;                       /* 0x000: list reacts to input */
    int isDetailShown;                  /* 0x004: ribbon detail objects exist */
    int isTextPending;                  /* 0x008: waiting for the detail text print to end */
    u32 redrawReq;                      /* 0x00C: 1 = refresh the rows */
    u8 ownedCount;                      /* 0x010 */
    u8 pad_11[3];
    u32 scrollPos;                      /* 0x014: pixels */
    u32 detailChrRes;                   /* 0x018: character resource of the picked ribbon */
    struct Actor *detailObj;            /* 0x01C: big picture of the picked ribbon */
    struct BmpWin *titleWin;            /* 0x020: ribbon name */
    struct BmpWin *descWin;             /* 0x024: ribbon description */
    StaGraphicsFile *listScrn;        /* 0x028 */
    void *listScrnMem;                  /* 0x02C */
    StaGraphicsFile *listPal;          /* 0x030: palette of the list */
    void *listPalMem;                   /* 0x034 */
    StaGraphicsFile *detailPal;        /* 0x038: palette while a detail is shown */
    void *detailPalMem;                 /* 0x03C */
    StaGraphicsFile *titleScrn;       /* 0x040: map of the title bar */
    void *titleScrnMem;                 /* 0x044 */
    StaRibbonCharData *iconChr;         /* 0x048: row picture tiles */
    void *iconChrMem;                   /* 0x04C */
    struct MsgBank *msgBank;            /* 0x050 */
    struct Actor *cursorObj;            /* 0x054 */
    u8 selectedRow;                     /* 0x058: row of the cursor, 255 = none */
    u8 selectedOwned;                   /* 0x059: owned[] index of the cursor, 255 = none */
    u8 prevSelectedRow;                 /* 0x05A */
    u8 pad_5B;
    int scrollSpeed;                    /* 0x05C: kinetic scroll after a touch drag */
    u8 seCooldown;                      /* 0x060: frames before the scroll sound may play again */
    u8 pad_61[3];
    u32 isDragging;                     /* 0x064 */
    u32 selectionChanged;               /* 0x068 */
    StaOamManager *oamMgr;       /* 0x06C */
    StaRibbonRow rows[STA_RIBBON_ROW_COUNT];    /* 0x070 */
    StaRibbonOwned owned[STA_RIBBON_MAX];       /* 0x138 */
};

/* stand-in: a row reached from the start of the work (offset 0x70 + 0x14 * row); the compiler only keeps the original
 * code shape when the row fields are read at their offsets from the work pointer, not through the rows array. */
typedef struct StaRibbonRowAt {
    u8 pad_0[0x70];
    u16 ownedIdx;                       /* 0x70 */
    u8 pad_72[6];
    u32 printPending;                   /* 0x78 */
    struct Bmp *bmp;                    /* 0x7C */
    StaOamBitmapActors *actors;  /* 0x80 */
} StaRibbonRowAt;

#define STA_RIBBON_ROW_AT(work, i) ((StaRibbonRowAt *)((u8 *)(work) + (i) * 20))

/* Touch hit rectangles; a row of 0xFF at top ends the table. */

/* Ribbons found so far per kind. */
typedef struct StaRibbonKindCount {
    u8 count[5];
} StaRibbonKindCount;

/* Parts of the OBJ VRAM address of the row bitmaps, kept in enum variables so the shift is not folded. */
enum StaRibbonVramPart {
    STA_RIBBON_VRAM_ZERO
};

extern u32 GFL_HEAP_Free(void *mem);
extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 animSeq);
extern void BG_SYS_PushTile(u32 bgId);
extern void *ARC_TOOL_CreateHandle(unsigned int archiveID, unsigned short heapID);
extern int CLACT_RegisterCharacter(void *arc, u32 fileId, u32 a, u32 screen, u16 heapId);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern void CLACT_ReleaseCharacter(u32 charRes);
extern struct Actor *CLACT_CreateActor(void *unit, unsigned int chrRes, unsigned int plttRes, unsigned int cellRes, const void *pos, u16 space, u16 heapId);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 enable);
extern void CLACT_DeleteActor(struct Actor *actor);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int MSGDATA_Delete(struct MsgBank *bank);
extern int TOUCHPANEL_HitTrg(const void *hitTable);
struct PrintQueue;
extern u32 PRINTSYS_QUE_IsFinished(struct PrintQueue *queue);
extern unsigned int KEY_GetRepeat(void);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
struct BoxPokemon;
extern u32 POKE_TOOL_GetBoxValue(struct BoxPokemon *box, unsigned int paramId, unsigned int arg);
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct Strbuf *str);
struct GfFont;
extern void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, unsigned int x, short y, struct Strbuf *str, struct GfFont *font, unsigned short color);
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern struct BmpWin *BMP_WIN_Create(unsigned int bgLayer, unsigned int posX, unsigned int posY, unsigned char width, unsigned char height, unsigned char palette, unsigned char allocDir);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void BG_SYS_MarkTileDirty(u32 bgId);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern struct WordSet *WORDSET_CreateDefault(unsigned short heapId);
extern u32 WORDSET_Delete(struct WordSet *ws);
extern void WORDSET_SetSlotNumber(struct WordSet *ws, u32 index, u32 number, u32 digits, u32 dispType, u32 zeroPad);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *arc, unsigned int fileId, unsigned int a, void **outData, unsigned short heapId);
extern void BG_SYS_DrawTileEx(unsigned int index, unsigned char dx, unsigned char dy, unsigned char cw, unsigned char ch, void *src, unsigned char sx, unsigned char sy, unsigned char sw, unsigned char sh);
extern void BG_SYS_DecodeTile(u32 palIndex, const void *src, u32 size);
extern void CLACT_SetActorPaletteOffset(struct Actor *actor, u32 animSeq, u32 flag);
extern void CLACT_AddActorSurfacePos(struct Actor *actor, const StaOamPoint *delta, u32 space);
extern void BG_SYS_SetTileEntry(unsigned int layer, unsigned short value, unsigned char x0, unsigned char y0, unsigned char w, unsigned char h, unsigned char mode);
extern void BG_SYS_ClearLayerEx(int bgId, u16 value);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *arc, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);
extern struct Bmp *BMP_CreateFromVram(void *pixels, u32 width, u32 height, u32 depth, u16 heapId);
extern void BMP_Delete(struct Bmp *bmp);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void GF_FONT_SetTextColor(u32 a, u32 b, u32 c);
extern void PRINTSYS_Print(struct Bmp *bmp, short x, short y, struct Strbuf *str, struct GfFont *font);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);
extern void GFL_USE_PlaySeInSlot(u32 seId, int flag);
extern unsigned int P_STA_RIBBON_GetRibbonDescMsg(int ribbonNo);
void P_STATUS_SetInputEnable(PStatusWork *wk, int enable);
void *P_STATUS_GetPokePara(PStatusWork *wk);
void *P_STA_RIBBON_Create(PStatusWork *wk);
void P_STA_RIBBON_Delete(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Main(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_LoadArcGraphics(PStatusWork *wk, PStaRibbonWork *work, void *arc);
void P_STA_RIBBON_FreeArcGraphics(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_CreateObjects(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_DeleteObjects(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_UpdateInput(PStatusWork *wk, PStaRibbonWork *work);
int P_STA_RIBBON_UpdateKeys(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_UpdateTouch(PStatusWork *wk, PStaRibbonWork *work);
int P_STA_RIBBON_GetTouchedRow(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_SnapCursorToScroll(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_SelectRow(PStatusWork *wk, PStaRibbonWork *work, u8 row);
void P_STA_RIBBON_Scroll(PStatusWork *wk, PStaRibbonWork *work, int delta);
void P_STA_RIBBON_Init(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Show(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Deactivate(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Hide(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_CollectOwned(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Noop(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_DrawRow(PStatusWork *wk, PStaRibbonWork *work, StaRibbonRow *row);
void P_STA_RIBBON_UpdateRows(PStatusWork *wk, PStaRibbonWork *work);
u32 P_STA_RIBBON_GetOwnedIndex(PStaRibbonWork *work, u32 target);
unsigned int P_STA_RIBBON_GetRowOwnedIndex(PStaRibbonWork *work, unsigned int target);
s16 P_STA_RIBBON_GetRowY(PStaRibbonWork *work, u32 target);
void P_STA_RIBBON_PrintDetail(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_ShowDetail(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_FreeDetailWindows(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_HideDetail(PStatusWork *wk, PStaRibbonWork *work);
struct StaOamManager;
StaOamManager *P_STA_OAM_CreateManager(u32 heapId, void *clunit);
void P_STA_OAM_DeleteManager(StaOamManager *mgr);
StaOamBitmapActors *P_STA_OAM_CreateBitmapActors(StaOamManager *mgr, const StaOamBitmapDesc *desc);
void P_STA_OAM_DeleteBitmapActors(StaOamBitmapActors *actors);
void P_STA_OAM_SetBitmapActorsEnabled(StaOamBitmapActors *actors, int enable);
void P_STA_OAM_TransferBitmap(StaOamBitmapActors *actors);
void P_STA_OAM_SetBitmapActorsPos(StaOamBitmapActors *actors, s16 x, s16 y);
u32 P_STA_RIBBON_GetRibbonInfo(u32 ribbonNo, u32 field);
extern const char P_STA_RIBBON_FileName[];
extern const StaRibbonKindCount P_STA_RIBBON_KindCountInit;

void *P_STA_RIBBON_Create(PStatusWork *wk) {
 PStaRibbonWork *work = GFL_HEAP_Alloc(wk->heapId, 0x3b8, 0, P_STA_RIBBON_FileName, 0xaf);
 work->isActive = 0;
 work->seCooldown = 0;
 work->msgBank = MSGDATA_CreateFromArchive(0, 2, 0xaa, wk->heapId);
 return work;
}

void P_STA_RIBBON_Delete(PStatusWork *wk, PStaRibbonWork *work)
{
    MSGDATA_Delete(work->msgBank);
    GFL_HEAP_Free(work);
}

void P_STA_RIBBON_Main(PStatusWork *wk, PStaRibbonWork *work)
{
    P_STA_RIBBON_UpdateInput(wk,work);
    if (work->isTextPending == 1) {
        if (PRINTSYS_QUE_IsFinished(wk->printQue) == 1) {
            P_STA_RIBBON_HideDetail(wk,work);
            P_STA_RIBBON_ShowDetail(wk,work);
            work->isTextPending=0;
        }
    } else P_STA_RIBBON_UpdateRows(wk,work);
    if (work->seCooldown) work->seCooldown--;
}

void P_STA_RIBBON_LoadArcGraphics(PStatusWork *wk, PStaRibbonWork *work, void *arc)
{
    work->listScrnMem = ARC_UTIL_LoadPaletteDataFromHandle(arc, 66, 0, (void **)&work->listScrn, wk->heapId);
    work->listPalMem = ARC_UTIL_LoadPaletteDataFromHandle(arc, 67, 0, (void **)&work->listPal, wk->heapId);
    work->detailPalMem = ARC_UTIL_LoadPaletteDataFromHandle(arc, 68, 0, (void **)&work->detailPal, wk->heapId);
    work->titleScrnMem = ARC_UTIL_LoadPaletteDataFromHandle(arc, 69, 0, (void **)&work->titleScrn, wk->heapId);
    work->iconChrMem = ARC_UTIL_LoadScreenDataFromHandle((void *)arc, (unsigned int)12, (unsigned int)0, &work->iconChr, wk->heapId);
    work->oamMgr = P_STA_OAM_CreateManager(wk->heapId, (wk->clunit));
}

void P_STA_RIBBON_FreeArcGraphics(PStatusWork *wk, PStaRibbonWork *work) {
 if (work->isActive == 1) P_STA_RIBBON_Deactivate(wk, work);
 P_STA_OAM_DeleteManager(work->oamMgr);
 GFL_HEAP_Free(work->iconChrMem);
 GFL_HEAP_Free(work->listScrnMem);
 GFL_HEAP_Free(work->listPalMem);
 GFL_HEAP_Free(work->detailPalMem);
 GFL_HEAP_Free(work->titleScrnMem);
}

/*
 * note (2026-10-02): the P_STA_RIBBON_GetRowY call is inside the loop (its arg is i), so &desc/&pos is recomputed
 *   per group; vramHi/vramLo are enum locals so (0x19<<22)+(2<<16) is not folded.
 */
void P_STA_RIBBON_CreateObjects(PStatusWork *wk, PStaRibbonWork *work)
{
    StaOamActorPos pos;
    StaOamBitmapDesc desc;
    enum StaRibbonVramPart vramHi, vramLo;
    u32 vramBase;
    u8 i;
    pos.x=0;pos.y=0;pos.drawPriority=10;pos.bgPriority=0;pos.animSeq=0;
    work->cursorObj=CLACT_CreateActor((void *)(u32)wk->clunit,wk->objRes[PSTATUS_RES_CHR_END],wk->objRes[PSTATUS_RES_PLTT_END],wk->objRes[PSTATUS_RES_CELL_END],&pos,0,wk->heapId);
    CLACT_SetActorDrawEnable(work->cursorObj,0);
    desc.x=8;
    desc.plttRes=(u32)((void *)wk->objRes[STA_RIBBON_RES_ROW_PLTT]);
    desc.animSeq=0;
    desc.drawPriority=0;
    vramHi=0x19;
    vramLo=2;
    desc.bgPriority=vramLo;
    desc.space=0;
    desc.screen=0;
    vramBase=(vramHi<<22)+(vramLo<<16);
    for(i=0;i<STA_RIBBON_ROW_COUNT;i++){
        StaRibbonRowAt *row;
        desc.y=P_STA_RIBBON_GetRowY(work,i);
        row=(StaRibbonRowAt *)((u8 *)work+i*0x14);
        desc.bmp=row->bmp=BMP_CreateFromVram((void *)(vramBase-(i+1)*0x660),0x11,3,0x20,wk->heapId);
        row->actors=P_STA_OAM_CreateBitmapActors(work->oamMgr,&desc);
        P_STA_OAM_SetBitmapActorsEnabled(row->actors,0);
    }
}

void P_STA_RIBBON_DeleteObjects(PStatusWork *wk, PStaRibbonWork *work) {
 unsigned char i;
 CLACT_DeleteActor(work->cursorObj);
 for (i = 0; i < STA_RIBBON_ROW_COUNT; i++) {
  StaRibbonRowAt *row = (StaRibbonRowAt *)((u8 *)work + i * 20);
  P_STA_OAM_DeleteBitmapActors(row->actors);
  BMP_Delete(row->bmp);
 }
}

/*
 * note (2026-10-02): the isDragging store precedes the selectedRow store; with source order the
 *   allocator hoists constant 0 into r7 instead.
 */
void P_STA_RIBBON_UpdateInput(PStatusWork *wk, PStaRibbonWork *work)
{
    int index;
    if((u32)wk->isInputEnabled==1) {
        if(work->ownedCount==0) return;
        index=P_STA_RIBBON_GetTouchedRow(wk,work);
        if(KEY_GetTrg()!=1 && index==-1) return;
        work->scrollSpeed=0;
        P_STATUS_SetInputEnable(wk,0);
        if(KEY_GetTrg()==1) {
            P_STA_RIBBON_SnapCursorToScroll(wk,work);
            wk->inputType=STA_RIBBON_INPUT_KEYS;
        } else {
            work->isDragging=1;
            work->selectedRow=(u8)index;
            work->selectionChanged=1;
            work->selectedOwned=P_STA_RIBBON_GetRowOwnedIndex(work,(u8)index);
            P_STATUS_SetInputEnable(wk,0);
            wk->inputType=STA_RIBBON_INPUT_TOUCH;
        }
        GFL_USE_PlaySeDefaultVolume(STA_RIBBON_SE_SELECT);
        P_STA_RIBBON_FreeDetailWindows(wk,work);
        P_STA_RIBBON_PrintDetail(wk,work);
    } else {
        if((u32)work->isTextPending==0 && P_STA_RIBBON_UpdateKeys(wk,work)==0) P_STA_RIBBON_UpdateTouch(wk,work);
    }
}

int P_STA_RIBBON_UpdateKeys(PStatusWork *wk, PStaRibbonWork *work)
{
    u8 i,index,narrowDelta;
    s16 shortDelta;
    int position;
    if(KEY_GetTrg()==STA_RIBBON_KEY_B) {
        P_STATUS_SetInputEnable(wk,1);
        CLACT_SetActorAnimSeq(wk->buttonActor[STA_RIBBON_BUTTON_B],9);
        CLACT_SetActorDrawEnable(work->cursorObj,0);
        work->selectedRow=255;
        work->selectedOwned=255;
        work->selectionChanged=1;
        P_STA_RIBBON_FreeDetailWindows(wk,work);
        P_STA_RIBBON_HideDetail(wk,work);
        wk->inputType=STA_RIBBON_INPUT_KEYS;
        GFL_USE_PlaySeDefaultVolume(STA_RIBBON_SE_CANCEL);
        return 1;
    }
    if(wk->inputType==STA_RIBBON_INPUT_TOUCH) {
        if(KEY_GetTrg()==STA_RIBBON_KEY_A || KEY_GetTrg()==STA_RIBBON_KEY_DOWN || KEY_GetTrg()==STA_RIBBON_KEY_UP) {
            position=-16;
            work->scrollSpeed=0;
            work->isDragging=0;
            for(i=0;i<STA_RIBBON_ROW_COUNT;i++) {
                if(work->selectedOwned==work->rows[i].ownedIdx) position=P_STA_RIBBON_GetRowY(work,i);
            }
            if(position < -4 || position >144) P_STA_RIBBON_SnapCursorToScroll(wk,work);
            P_STA_RIBBON_FreeDetailWindows(wk,work);
            P_STA_RIBBON_PrintDetail(wk,work);
            GFL_USE_PlaySeDefaultVolume(STA_RIBBON_SE_CURSOR);
            wk->inputType=STA_RIBBON_INPUT_KEYS;
            return 1;
        }
    } else if(KEY_GetRepeat()==STA_RIBBON_KEY_DOWN) {
        index=work->selectedRow+1;
        if(index>=STA_RIBBON_ROW_COUNT) index-=STA_RIBBON_ROW_COUNT;
        if(work->rows[index].ownedIdx!=0xffff) {
            work->selectedRow=index;
            work->selectionChanged=1;
            if(P_STA_RIBBON_GetRowY(work,work->selectedRow)>128) {
                narrowDelta=P_STA_RIBBON_GetRowY(work,work->selectedRow)-128;
                P_STA_RIBBON_Scroll(wk,work,narrowDelta);
            }
            P_STA_RIBBON_SelectRow(wk,work,work->selectedRow);
            P_STA_RIBBON_FreeDetailWindows(wk,work);
            P_STA_RIBBON_PrintDetail(wk,work);
            GFL_USE_PlaySeDefaultVolume(STA_RIBBON_SE_CURSOR);
        }
        return 1;
    } else if(KEY_GetRepeat()==STA_RIBBON_KEY_UP) {
        index=work->selectedRow;
        if(index==0) index=STA_RIBBON_ROW_COUNT-1;
        else index-=1;
        if(work->rows[index].ownedIdx!=0xffff) {
            work->selectedRow=index;
            work->selectionChanged=1;
            if(P_STA_RIBBON_GetRowY(work,work->selectedRow)<8) {
                shortDelta=P_STA_RIBBON_GetRowY(work,work->selectedRow)-8;
                P_STA_RIBBON_Scroll(wk,work,shortDelta);
            }
            P_STA_RIBBON_SelectRow(wk,work,work->selectedRow);
            P_STA_RIBBON_FreeDetailWindows(wk,work);
            P_STA_RIBBON_PrintDetail(wk,work);
            GFL_USE_PlaySeDefaultVolume(STA_RIBBON_SE_CURSOR);
        }
        return 1;
    }
    return 0;
}

/*
 * proof: The delta subtract at 021D8D9C is full-word modulo arithmetic,
 *   then sign-extends its low halfword. Twice that s16 is -65536..65534,
 *   spelled multiply, permitting negative input. Velocity sums wrap as
 *   u32 before conversion to signed int and truncating division by 2.
 *   Negative velocity +1 and positive velocity -1 cannot overflow int;
 *   their halved outgoing values are explicitly narrowed to s16.
 * interface: 02035C60's result is read by the original despite its matched
 *   void forwarding declaration. 021D9428 forwards target in live r1 to
 *   021D93E4; the original explicitly narrows target to u8 before the call.
 */
void P_STA_RIBBON_UpdateTouch(PStatusWork *wk, PStaRibbonWork *work)
{
    int index, delta, velocity;
    if((u32)wk->tpHit==7) {
        P_STATUS_SetInputEnable(wk,1);
        CLACT_SetActorAnimSeq(wk->buttonActor[STA_RIBBON_BUTTON_B],9);
        CLACT_SetActorDrawEnable(work->cursorObj,0);
        work->selectedRow=255;
        work->selectedOwned=255;
        work->selectionChanged=1;
        wk->inputType=STA_RIBBON_INPUT_TOUCH;
        P_STA_RIBBON_FreeDetailWindows(wk,work);
        P_STA_RIBBON_HideDetail(wk,work);
        GFL_USE_PlaySeDefaultVolume(STA_RIBBON_SE_CANCEL);
        return;
    }
    if(TOUCHPANEL_GetTrg()==1 && wk->tpX>8 && wk->tpX<144) {
        index=P_STA_RIBBON_GetTouchedRow(wk,work);
        if(index!=-1) {
            work->selectedRow=(u8)index;
            work->selectionChanged=1;
            work->selectedOwned=P_STA_RIBBON_GetRowOwnedIndex(work,(u8)index);
            work->isDragging=1;
            work->scrollSpeed=0;
            CLACT_SetActorDrawEnable(work->cursorObj,0);
            P_STA_RIBBON_FreeDetailWindows(wk,work);
            P_STA_RIBBON_PrintDetail(wk,work);
        }
        wk->inputType=STA_RIBBON_INPUT_TOUCH;
        return;
    }
    if(TOUCHPANEL_GetCont()==1 && work->isDragging==1 && wk->tpX>8 && wk->tpX<144) {
        delta=(s16)(wk->prevTpY-wk->tpY);
        velocity=delta*2;
        P_STA_RIBBON_Scroll(wk,work,delta);
        if(velocity>=0 && work->scrollSpeed>0 && velocity<work->scrollSpeed) {
            work->scrollSpeed=(int)((u32)work->scrollSpeed+(u32)velocity)/2;
            return;
        }
        if(velocity<=0 && work->scrollSpeed<0 && velocity>work->scrollSpeed) {
            work->scrollSpeed=(int)((u32)work->scrollSpeed+(u32)velocity)/2;
            return;
        }
        work->scrollSpeed=velocity;
        return;
    }
    work->isDragging=0;
    if(work->scrollSpeed<0) {
        work->scrollSpeed+=1;
        P_STA_RIBBON_Scroll(wk,work,(s16)(work->scrollSpeed/2));
    }
    if(work->scrollSpeed>0) {
        work->scrollSpeed-=1;
        P_STA_RIBBON_Scroll(wk,work,(s16)(work->scrollSpeed/2));
    }
}

int P_STA_RIBBON_GetTouchedRow(PStatusWork *wk, PStaRibbonWork *work)
{
    StaTouchRect hitTable[STA_RIBBON_ROW_COUNT + 1];
    u8 i;
    int y;

    for (i = 0; i < STA_RIBBON_ROW_COUNT; i++) {
        y = P_STA_RIBBON_GetRowY(work, i);
        hitTable[i].left = 8;
        hitTable[i].right = 0x90;
        if (y < 0)
            hitTable[i].top = 0;
        else if (y > 0xa8)
            hitTable[i].top = 0xa8;
        else
            hitTable[i].top = y;
        if (y + 0x18 < 0)
            hitTable[i].bottom = 0;
        else if (y + 0x18 > 0xa8)
            hitTable[i].bottom = 0xa8;
        else
            hitTable[i].bottom = y + 0x18;
        if (hitTable[i].top == 0 && hitTable[i].bottom == 0)
            hitTable[i].top = 0xfd;
        if (P_STA_RIBBON_GetRowOwnedIndex(work, i) == 0xffff)
            hitTable[i].top = 0xfd;
    }
    hitTable[STA_RIBBON_ROW_COUNT].top = 0xff;
    return TOUCHPANEL_HitTrg(hitTable);
}

void P_STA_RIBBON_SnapCursorToScroll(PStatusWork *wk, PStaRibbonWork *work)
{
    P_STA_RIBBON_SelectRow(wk,work,(u8)(((work->scrollPos+23)/STA_RIBBON_ROW_HEIGHT)%STA_RIBBON_ROW_COUNT));
}

void P_STA_RIBBON_SelectRow(PStatusWork *wk, PStaRibbonWork *work, u8 row)
{
    StaOamPoint pt;
    pt.x=8;
    pt.y=P_STA_RIBBON_GetRowY(work,row);
    CLACT_AddActorSurfacePos(work->cursorObj,&pt,0);
    work->selectedRow=row;
    work->selectionChanged=1;
    work->selectedOwned=P_STA_RIBBON_GetRowOwnedIndex(work,row);
}

void P_STA_RIBBON_Scroll(PStatusWork *wk, PStaRibbonWork *work, int delta)
{
    int maxScroll = (work->ownedCount - STA_RIBBON_VISIBLE_ROWS) * STA_RIBBON_ROW_HEIGHT;
    unsigned int old;
    if (maxScroll < 0) maxScroll = 0;
    if (delta > 24) delta = 24;
    if (delta < -24) delta = -24;
    old = work->scrollPos;
    if ((short)old + delta < 0) work->scrollPos = 0;
    else if (old + delta > (unsigned int)maxScroll) work->scrollPos = maxScroll;
    else work->scrollPos = old + delta;
    if (delta != 0) work->redrawReq = 1;
}

void P_STA_RIBBON_Init(PStatusWork *wk, PStaRibbonWork *work)
{
    unsigned char i;
    work->selectedRow=255;
    work->selectedOwned=255;
    work->prevSelectedRow=255;
    work->scrollPos=0;
    work->isActive=1;
    work->isDetailShown=0;
    work->isTextPending=0;
    work->redrawReq=1;
    work->titleWin = (void *)0;
    work->descWin = (void *)0;
    for(i=0;i<STA_RIBBON_ROW_COUNT;i++) {
        work->rows[i].ownedIdx=P_STA_RIBBON_GetRowOwnedIndex(work,i);
        P_STA_RIBBON_DrawRow(wk,work,&work->rows[i]);
    }
}

/*
 * lever: The image's 20-byte records are subscripted per field, avoiding
 *   the pointer-arithmetic spelling's cached object-field base and spill.
 * proof: i is initialized u8 and bounded by 10; i*20 fits int.
 *   Loaded address payloads use u32 +12 for full-word modulo arithmetic.
 */
void P_STA_RIBBON_Show(PStatusWork *wk, PStaRibbonWork *work)
{
    u8 i;
    u16 ownedIdx;
    BG_SYS_DrawTileEx(2,0,0,32,24,work->listScrn->data,0,0,32,32);
    BG_SYS_MarkTileDirty(2);
    BG_SYS_DecodeTile(6,work->listPal->data,work->listPal->dataSize);
    BG_SYS_MarkTileDirty(6);
    BG_SYS_DrawTileEx(5,0,0,32,3,work->titleScrn->data,0,0,32,32);
    BG_SYS_MarkTileDirty(5);
    for(i=0;i<STA_RIBBON_ROW_COUNT;i++) {
        ownedIdx=work->rows[i].ownedIdx;
        P_STA_OAM_SetBitmapActorsPos(work->rows[i].actors,8,P_STA_RIBBON_GetRowY(work,i));
        if(ownedIdx!=0xffff) {
            P_STA_OAM_SetBitmapActorsEnabled(work->rows[i].actors,1);
            P_STA_OAM_TransferBitmap(work->rows[i].actors);
        } else P_STA_OAM_SetBitmapActorsEnabled(work->rows[i].actors,0);
    }
    work->scrollPos=0;
    work->selectedRow=255;
    work->selectedOwned=255;
    work->prevSelectedRow=255;
    work->isActive=1;
    work->redrawReq=1;
    CLACT_SetActorAnimSeq(wk->buttonActor[STA_RIBBON_BUTTON_PAGE_TAB],5);
}

void P_STA_RIBBON_Deactivate(PStatusWork *wk, PStaRibbonWork *work)
{
    work->isActive=0;
    if(work->titleWin!=0) {
        BMP_WIN_Delete(work->titleWin);
        work->titleWin=0;
    }
    if(work->descWin!=0) {
        BMP_WIN_Delete(work->descWin);
        work->descWin=0;
    }
}

void P_STA_RIBBON_Hide(PStatusWork *wk, PStaRibbonWork *work)
{
    unsigned char i;
    for(i=0;i<STA_RIBBON_ROW_COUNT;i++) P_STA_OAM_SetBitmapActorsEnabled(work->rows[i].actors,0);
    BG_SYS_SetTileEntry(1,0,0,0,19,21,16);
    BG_SYS_PushTile(1);
    work->isActive=0;
    CLACT_SetActorAnimSeq(wk->buttonActor[STA_RIBBON_BUTTON_PAGE_TAB],2);
}

/*
 * lever: Initialize the count after the clear loop so its zero shares the
 *   clear-store value without a redundant live zero register.
 * proof: Loop indices are initialized u8 values bounded by 80 or 10.
 *   P_STA_RIBBON_GetRibbonInfo field 5 reads byte +12 of immutable P_STA_RIBBON_InfoTable;
 *   all 80 original records have selector 0..4 (B8/table-proof.log).
 *   count begins with five ROM bytes 1,1,1,1,1 and never exceeds 81.
 *   All scaling and count increments fit int; stores preserve u8 narrowing.
 * interface: P_STA_RIBBON_GetRowOwnedIndex forwards live r1 to P_STA_RIBBON_GetOwnedIndex, whose
 *   own matched body consumes target; caller sets r1 despite stale one-arg
 *   declaration in P_STA_RIBBON_GetRowOwnedIndex's source.
 */
void P_STA_RIBBON_CollectOwned(PStatusWork *wk, PStaRibbonWork *work)
{
    StaRibbonKindCount kindCount = P_STA_RIBBON_KindCountInit;
    void *pp;
    u8 i, n, category;
    pp=P_STATUS_GetPokePara(wk);
    for(i=0;i<STA_RIBBON_MAX;i++) work->owned[i].isOwned=0;
    n=0;
    for(i=0;i<STA_RIBBON_MAX;i++) {
        if(POKE_TOOL_GetBoxValue(pp,P_STA_RIBBON_GetRibbonInfo(i,0),0)==1) {
            category=P_STA_RIBBON_GetRibbonInfo(i,5);
            work->owned[n].isOwned=1;
            work->owned[n].ribbonNo=i;
            work->owned[n].category=category;
            work->owned[n].number=kindCount.count[category];
            kindCount.count[category]++;
            n++;
        }
    }
    work->ownedCount=n;
    for(i=0;i<STA_RIBBON_ROW_COUNT;i++) work->rows[i].ownedIdx=P_STA_RIBBON_GetRowOwnedIndex(work,i);
}

void P_STA_RIBBON_Noop(PStatusWork *wk, PStaRibbonWork *work)
{
}

void P_STA_RIBBON_DrawRow(PStatusWork *wk, PStaRibbonWork *work, StaRibbonRow *row)
{
    StaRibbonOwned *owned;
    u8 *pixels;
    void *text;
    void *buffer;
    struct WordSet *wordSet;
    void *source;
    owned=&work->owned[row->ownedIdx];
    if (owned->isOwned!=1) return;
    pixels=work->iconChr->pixels;
    source=BMP_GetPixels(row->bmp);
    if (row->ownedIdx==work->selectedOwned) pixels+=0x660;
    MI_CpuCopy8(pixels,source,0x660);
    text=MSGDATA_AllocString(work->msgBank,owned->category+160);
    buffer=STRBUF_Create(32,wk->heapId);
    wordSet=WORDSET_CreateDefault(wk->heapId);
    WORDSET_SetSlotNumber(wordSet,0,owned->number,2,2,1);
    WORDSET_CopyTaggedText(wordSet,buffer,text);
    GF_FONT_SetTextColor(1,2,0);
    PRINTSYS_Print(row->bmp,10,6,buffer,wk->font);
    GF_FONT_SetDefaultTextColor();
    STRBUF_Delete(text);
    STRBUF_Delete(buffer);
    WORDSET_Delete(wordSet);
    P_STA_OAM_TransferBitmap(row->actors);
}

/*
 * proof: loop i starts at zero and tests i<10 after each byte increment;
 * i*20 <=180. Each other byte index is guarded <10 before *20.
 * prototype: 021D92EA loads r1 for 021D9428 despite its legacy one-input
 * source. Preserve this observed full-word argument in the caller extern.
 */
void P_STA_RIBBON_UpdateRows(PStatusWork *wk, PStaRibbonWork *work)
{
    int changed;
    u8 *entries;
    u8 i;
    u32 ownedIdx;
    StaRibbonRowAt *row;
    s16 y;
    changed=0;
    entries=(u8 *)work;
    entries+=0x70;
    for(i=0;i<STA_RIBBON_ROW_COUNT;i++) {
        if(work->redrawReq==1) {
            y=P_STA_RIBBON_GetRowY(work,i);
            P_STA_OAM_SetBitmapActorsPos(STA_RIBBON_ROW_AT(work,i)->actors,8,y);
            ownedIdx=P_STA_RIBBON_GetRowOwnedIndex(work,i);
            if(ownedIdx==65535) {
                STA_RIBBON_ROW_AT(work,i)->ownedIdx=ownedIdx;
                P_STA_OAM_SetBitmapActorsEnabled(STA_RIBBON_ROW_AT(work,i)->actors,0);
            } else if(ownedIdx!=STA_RIBBON_ROW_AT(work,i)->ownedIdx) {
                changed=1;
                STA_RIBBON_ROW_AT(work,i)->ownedIdx=ownedIdx;
                P_STA_RIBBON_DrawRow(wk,work,(StaRibbonRow *)(entries+i*20));
                P_STA_OAM_SetBitmapActorsEnabled(STA_RIBBON_ROW_AT(work,i)->actors,1);
            }
        }
        row=STA_RIBBON_ROW_AT(work,i);
        if(row->printPending==1 && PRINTSYS_QUE_IsExistTarget(wk->printQue,row->bmp)==0) {
            row->printPending=0;
            P_STA_OAM_TransferBitmap(row->actors);
        }
    }
    if(changed==1 && work->seCooldown==0) {
        GFL_USE_PlaySeInSlot(STA_RIBBON_SE_SCROLL,1);
        work->seCooldown=3;
    }
    if(work->selectionChanged==1) {
        if(work->selectedRow<STA_RIBBON_ROW_COUNT) P_STA_RIBBON_DrawRow(wk,work,(StaRibbonRow *)(entries+work->selectedRow*20));
        if(work->prevSelectedRow<STA_RIBBON_ROW_COUNT) P_STA_RIBBON_DrawRow(wk,work,(StaRibbonRow *)(entries+work->prevSelectedRow*20));
        work->prevSelectedRow=work->selectedRow;
        work->selectionChanged=0;
    }
    work->redrawReq=0;
}

/* Owned index (not range checked) that row slot target shows at the current scroll position. */
u32 P_STA_RIBBON_GetOwnedIndex(PStaRibbonWork *work, u32 target)
{
    u8 topRow;
    s8 delta;
    topRow = work->scrollPos / (u32)STA_RIBBON_ROW_HEIGHT;
    delta = target - (u8)(topRow % STA_RIBBON_ROW_COUNT);
    if (delta < -2) delta += STA_RIBBON_ROW_COUNT;
    if (delta > 8) delta -= STA_RIBBON_ROW_COUNT;
    return (u8)(topRow + delta);
}

unsigned int P_STA_RIBBON_GetRowOwnedIndex(PStaRibbonWork *work, unsigned int target)
{
    unsigned int ownedIdx = P_STA_RIBBON_GetOwnedIndex(work, target);

    if (ownedIdx < work->ownedCount)
        return ownedIdx;
    return 0xffff;
}

s16 P_STA_RIBBON_GetRowY(PStaRibbonWork *work, u32 target)
{
    u32 position;
    u8 topRow, remainder;
    s8 delta;
    position = work->scrollPos;
    topRow = position / (u32)STA_RIBBON_ROW_HEIGHT;
    remainder = position % (u32)STA_RIBBON_ROW_HEIGHT;
    delta = target - (u8)(topRow % STA_RIBBON_ROW_COUNT);
    if (delta < -2) delta += STA_RIBBON_ROW_COUNT;
    if (delta > 8 && topRow > 6) delta -= STA_RIBBON_ROW_COUNT;
    return delta * STA_RIBBON_ROW_HEIGHT + 8 - remainder;
}

/*
 * extent: two zero alignment bytes at 021D9566 follow the 202-byte body.
 * proof: ribbonNo is ldrb at 021D94DA, hence 0..255; index*8+316
 * is at most 2356 and has no signed overflow. No selector bound assumed.
 */
void P_STA_RIBBON_PrintDetail(PStatusWork *wk, PStaRibbonWork *work)
{
    u8 ribbonNo;
    void *text;
    work->titleWin=BMP_WIN_Create(4,5,7,22,2,14,1);
    work->descWin=BMP_WIN_Create(4,1,16,30,4,14,1);
    ribbonNo=work->owned[work->selectedOwned].ribbonNo;
    text=MSGDATA_AllocString(work->msgBank,P_STA_RIBBON_GetRibbonInfo(ribbonNo,3));
    PRINTSYS_PrintQueColor(wk->printQue,BMP_WIN_GetBmp(work->titleWin),1,1,text,wk->font,1088);
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(work->msgBank,P_STA_RIBBON_GetRibbonDescMsg(ribbonNo));
    PRINTSYS_PrintQueColor(wk->printQue,BMP_WIN_GetBmp(work->descWin),1,1,text,wk->font,1088);
    STRBUF_Delete(text);
    work->isTextPending=1;
}

/*
 * extent: two zero alignment bytes at 021D964A follow the 226-byte body.
 * proof: selector is a byte; selector*8+316 <=2356. Position stores
 * initialize every byte of the eight-byte descriptor before passing it.
 * prototype: 0204B294 leaves 0204CFDC's pointer return live at 0204B318;
 * 021D960E stores it. Keep the own body's u32,u32,u32,u32,u32,u16,u16
 * inputs, and expose the observed r0 result despite its legacy void return.
 */
void P_STA_RIBBON_ShowDetail(PStatusWork *wk, PStaRibbonWork *work)
{
    struct BmpWin *win;
    void *archive;
    u8 ribbonNo;
    StaOamActorPos pos;
    ribbonNo=work->owned[work->selectedOwned].ribbonNo;
    win=work->titleWin;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
    win=work->descWin;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
    archive=ARC_TOOL_CreateHandle(78,wk->heapId);
    work->detailChrRes=CLACT_RegisterCharacter(archive,P_STA_RIBBON_GetRibbonInfo(ribbonNo,1),0,1,wk->heapId);
    ARC_TOOL_DeleteHandle(archive);
    pos.x=128;
    pos.y=100;
    pos.drawPriority=10;
    pos.bgPriority=0;
    pos.animSeq=0;
    work->detailObj=CLACT_CreateActor((void *)(u32)wk->clunit,work->detailChrRes,wk->objRes[STA_RIBBON_RES_DETAIL_PLTT],wk->objRes[STA_RIBBON_RES_DETAIL_CELL],&pos,1,wk->heapId);
    CLACT_SetActorPaletteOffset(work->detailObj,(u8)P_STA_RIBBON_GetRibbonInfo(ribbonNo,2),1);
    CLACT_SetActorDrawEnable(work->detailObj,1);
    BG_SYS_DecodeTile(6,work->detailPal->data,work->detailPal->dataSize);
    BG_SYS_MarkTileDirty(6);
    work->isDetailShown=1;
}

void P_STA_RIBBON_FreeDetailWindows(PStatusWork *wk, PStaRibbonWork *work)
{
    if(work->titleWin!=0) {
        BMP_WIN_Delete(work->titleWin);
        work->titleWin=0;
    }
    if(work->descWin!=0) {
        BMP_WIN_Delete(work->descWin);
        work->descWin=0;
    }
}

void P_STA_RIBBON_HideDetail(PStatusWork *wk, PStaRibbonWork *work)
{
    if(work->isDetailShown==1) {
        CLACT_ReleaseCharacter(work->detailChrRes);
        CLACT_DeleteActor(work->detailObj);
        BG_SYS_ClearLayerEx(4,0);
        BG_SYS_MarkTileDirty(4);
        work->isDetailShown=0;
        BG_SYS_DecodeTile(6,work->listPal->data,work->listPal->dataSize);
        BG_SYS_MarkTileDirty(6);
    }
}
