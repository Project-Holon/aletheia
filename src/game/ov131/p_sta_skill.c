/*
 * file:     p_sta_skill.c
 * unit:     yes
 * function: P_STA_SKILL_Create, P_STA_SKILL_Delete, P_STA_SKILL_Main, P_STA_SKILL_LoadArcGraphics, P_STA_SKILL_Exit, P_STA_SKILL_CreateObjects, P_STA_SKILL_DeleteObjects, P_STA_SKILL_InitStatsPage, P_STA_SKILL_ShowStatsPage, P_STA_SKILL_FreeStatsPage, P_STA_SKILL_HideStatsPage, P_STA_SKILL_PrintStatsPage, P_STA_SKILL_ApplyStatsScreen, P_STA_SKILL_RefreshMoveDetail, P_STA_SKILL_ApplyMovesScreen, P_STA_SKILL_PrintStats, P_STA_SKILL_DrawHpBar, P_STA_SKILL_PrintMoveDetail, P_STA_SKILL_InitMovesPage, P_STA_SKILL_ShowMovesPage, P_STA_SKILL_FreeMovesPage, P_STA_SKILL_HideMovesPage, P_STA_SKILL_UpdateInput, P_STA_SKILL_HandleKeys, P_STA_SKILL_HandleTouch, P_STA_SKILL_HandleKeysForget, P_STA_SKILL_HandleTouchForget, P_STA_SKILL_StepCursor, P_STA_SKILL_SetCursor, P_STA_SKILL_SwapMoves, P_STA_SKILL_SetNewMoveHeld, P_STA_SKILL_ShowCantForgetMsg, P_STA_SKILL_GetNatureStatColor, P_STA_SKILL_CreateSlotObjects, P_STA_SKILL_DeleteSlotObjects, P_STA_SKILL_UpdateSlot, P_STA_SKILL_InitSlotText, P_STA_SKILL_ShowSlot, P_STA_SKILL_FreeSlot, P_STA_SKILL_HideSlot, P_STA_SKILL_GetSlotTouchRect, P_STA_SKILL_GetSlotPos, P_STA_SKILL_SetSlotAnim
 * address:  0x021D96B0
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from p_sta_oam.c: 0x021D96B0-0x021DBA90. Cuts at the __FILE__ anchor functions (layout/file_anchors.txt);
 * the functions in this range use PStaSkillWork (PStatusWork.skillWork).
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   POKE_TOOL_SetBoxValue 0x02017E64 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   BMP_FillRect 0x02043AF4 arm
 *   BMP_Delete 0x020437AC arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   P_STA_SKILL_FileName 0x021DC844 data a1
 *   P_STA_SKILL_WindowTemplates 0x021DC2C2 data a1
 *   BMP_WIN_SetPalette 0x02045798 arm
 *   BG_SYS_PushTileSource 0x020409E0 arm
 *   BGWINFRM_GetScaleRank 0x0202D034 thumb
 *   BGWINFRM_ScaleRatio 0x0202D01C thumb
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   APP_ICON_GetMoveKindPaletteOffset 0x02027604 thumb
 *   BMP_Clear 0x02043B5C arm
 *   BMP_Create 0x02043678 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   EVENT_ID_Check 0x0202F72C thumb
 *   POKE_TOOL_SetBoxMoveSlot 0x020181FC thumb
 *   POKE_TOOL_GetNatureModifier 0x02019B44 thumb
 *   P_STA_SKILL_SlotTilePos 0x021DC2B8 data a1
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   WAZA_TOOL_GetType 0x0201C1C8 thumb
 *   P_STATUS_SetInputEnable 0x021D5A9C thumb ov131
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STATUS_GetPokeParaSource 0x021D60A4 thumb ov131
 *   P_STATUS_SetFastMode 0x021D60D4 thumb ov131
 *   P_STATUS_PrintMsg 0x021D614C thumb ov131
 *   P_STATUS_PrintMsgToWin 0x021D618C thumb ov131
 *   P_STATUS_PrintWordSetMsg 0x021D61B8 thumb ov131
 *   P_STATUS_PrintWordSetMsgToWin 0x021D6214 thumb ov131
 *   P_STATUS_PrintWordSetMsgRight 0x021D6244 thumb ov131
 *   P_STATUS_PrintWordSetMsgRightToWin 0x021D62B4 thumb ov131
 *   P_STA_OAM_CreateManager 0x021DBA90 thumb ov131
 *   P_STA_OAM_DeleteManager 0x021DBAC0 thumb ov131
 *   P_STA_OAM_CreateBitmapActors 0x021DBAD0 thumb ov131
 *   P_STA_OAM_DeleteBitmapActors 0x021DBC3C thumb ov131
 *   P_STA_OAM_SetBitmapActorsEnabled 0x021DBCA4 thumb ov131
 *   P_STA_OAM_TransferBitmap 0x021DBCF4 thumb ov131
 *   P_STA_OAM_SwapInts 0x021DBE98 thumb ov131
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb  arm9
 *   WAZA_TOOL_IsAlwaysHit  0x0201C1F4  thumb  arm9
 */


#include "p_status_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;

struct Obj;
struct BmpWin;
struct PrintQue;
struct MsgData;
struct Strbuf;
struct WordSet;

/* One move slot of the skill page (0x18 bytes); the fifth slot is the move to learn. */
typedef struct PStaSkillSlot {
    u8 index;                               /* 0x00: slot number, 0xFF once deleted */
    u8 pad_1[3];
    int redrawPending;                      /* 0x04: 1 = show the frame, type icon and name when the text is ready */
    struct Obj *frameObj;                   /* 0x08: slot frame */
    struct Obj *typeObj;                    /* 0x0C: move type icon */
    struct Bmp *nameBmp;                    /* 0x10: bitmap with the move name, PP and PP label */
    StaOamBitmapActors *nameActors;  /* 0x14: actors that show nameBmp */
} PStaSkillSlot;

#define STA_SKILL_SLOT_MAX 5
#define STA_SKILL_WIN_MAX 13
#define STA_SKILL_SLOT_NONE 5          /* heldSlot value: no move is picked up */
#define STA_SKILL_NO_CURSOR 255        /* cursorSlot value: no slot has the cursor */

/* Indices of PStaSkillWork.win.  0 to 7 belong to the stats page, 8 to 11 to the moves page. */
enum {
    STA_SKILL_WIN_HP_LABEL = 0,
    STA_SKILL_WIN_HP_BAR,
    STA_SKILL_WIN_ATTACK,
    STA_SKILL_WIN_DEFENSE,
    STA_SKILL_WIN_SP_ATTACK,
    STA_SKILL_WIN_SP_DEFENSE,
    STA_SKILL_WIN_SPEED,
    STA_SKILL_WIN_ABILITY,
    STA_SKILL_WIN_MOVE_CATEGORY,
    STA_SKILL_WIN_MOVE_POWER,
    STA_SKILL_WIN_MOVE_ACCURACY,
    STA_SKILL_WIN_MOVE_DESC,
    STA_SKILL_WIN_MESSAGE
};

/* Skill page work (pages 1 and 3, PStatusWork.skillWork, 0x128 bytes).  The stats page shows
 * the stats, the HP bar and the ability; the moves page shows the move list and the details
 * of the selected move.  The moves page is also used to choose a move to forget. */
struct PStaSkillWork {
    u32 isOpen;                     /* 0x00: 1 while the page is built */
    u32 statsPrintPending;          /* 0x04: 1 = stats windows wait for the print queue */
    u32 movePrintPending;           /* 0x08: 1 = move detail windows wait for the print queue */
    int msgPrintPending;            /* 0x0C: 1 = message window waits for the print queue */
    u32 swapPending;                /* 0x10: 1 = a move swap waits for the print queue */
    int isMoveHeld;                 /* 0x14: a move is picked up to be swapped */
    int isPickingForget;            /* 0x18: the new move is picked, choose the move to replace */
    int isTouching;                 /* 0x1C: the stylus is down on a slot */
    int isConfirmed;                /* 0x20: 1 = a choice was made, blink the slot and leave */
    u32 blinkSlotFrame;             /* 0x24: 1 = blink the slot frame, 0 = blink the slot animation */
    u8 blinkCount;                  /* 0x28 */
    u8 cursorSlot;                  /* 0x29: slot under the cursor, 0xFF = none */
    u8 heldSlot;                    /* 0x2A: slot that is picked up, 5 = none */
    u8 slotCount;                   /* 0x2B: 4 moves, 5 when a move is to be learned */
    u32 touchStartX;                /* 0x2C */
    u32 touchStartY;                /* 0x30 */
    void *bgScrnData;               /* 0x34: data of bgScrnFile */
    void *bgScrnFile;               /* 0x38: graphics file 72 (background screen) */
    void *statsPlttData;            /* 0x3C */
    void *statsPlttFile;            /* 0x40: graphics file 73 (stats page palette) */
    void *movesPlttData;            /* 0x44 */
    void *movesPlttFile;            /* 0x48: graphics file 74 (moves page palette) */
    void *statsScrnData;            /* 0x4C */
    void *statsScrnFile;            /* 0x50: graphics file 75 (stats page screen) */
    void *movesScrnData;            /* 0x54 */
    void *movesScrnFile;            /* 0x58: graphics file 76 (moves page screen) */
    struct BmpWin *win[STA_SKILL_WIN_MAX]; /* 0x5C: STA_SKILL_WIN_* */
    struct Obj *statsObj;           /* 0x90: decoration shown on the stats page only */
    struct Obj *moveTypeObj;        /* 0x94: type icon of the selected move, moves page only */
    struct Obj *cursorObj;          /* 0x98 */
    struct Obj *heldObj;            /* 0x9C: frame that follows the picked up move */
    struct Obj *touchObj;           /* 0xA0: frame shown while the stylus is down */
    StaOamManager *oamManager;        /* 0xA4 */
    struct Bmp *giveUpBmp;          /* 0xA8: "give up learning" text, 5 slot case only */
    StaOamBitmapActors *giveUpActors; /* 0xAC */
    PStaSkillSlot slot[STA_SKILL_SLOT_MAX];  /* 0xB0 */
};

/* Library functions: parameter names are guesses from the callers. */
extern void GFL_HEAP_Free(void *ptr);
extern void CLACT_SetActorAnimSeq(struct Obj *obj, u16 animSeq);
extern void BG_SYS_PushTile(u32 bgLayer);
extern struct Obj *CLACT_CreateActor(void *clunit, unsigned int charRes, unsigned int plttRes, unsigned int cellRes, const StaOamActorPos *pos, u16 space, u16 heapId);
extern void CLACT_SetActorAutoAnim(struct Obj *obj, u32 value);
extern void CLACT_SetActorDrawEnable(struct Obj *obj, u32 visible);
extern void CLACT_DeleteActor(struct Obj *obj);
extern struct MsgData *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int MSGDATA_Delete(struct MsgData *msgData);
extern int TOUCHPANEL_HitTrg(const void *rectTable);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintQue *queue);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern u32 POKE_TOOL_GetBoxValue(void *pp, int id, void *buf);
extern u32 POKE_TOOL_GetPartyValue(void *pp, u32 id, u32 buf);
extern struct Strbuf *MSGDATA_AllocString(struct MsgData *msgData, u32 msgId);
extern void STRBUF_Delete(struct Strbuf *str);
extern void PRINTSYS_PrintQueColor(struct PrintQue *queue, struct Bmp *bmp, u32 x, u32 y, struct Strbuf *str, void *font, u16 color);
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern void POKE_TOOL_SetBoxValue(void *pp, u32 id, u32 value);
extern struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 charOffset);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void BG_SYS_SetFlagField06(u32 bgLayer);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern struct WordSet *WORDSET_CreateDefault(u32 heapId);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *wordSet);
extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 padMode, u32 flag);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern int TOUCHPANEL_HitCont(const void *rectTable);
extern void *func_02049EF4(void *arc, unsigned int fileId, unsigned int flag, void **outData, unsigned short heapId);
extern void BG_SYS_DrawTileEx(u32 bgLayer, u32 a, u32 b, u32 width, u8 height, u32 src, u8 c, u8 d, u8 e, u8 f);
extern void BG_SYS_DecodeTile(u32 index, const void *src, u32 size);
extern void CLACT_GetCharacterProxy(u32 res, StaSpriteRes *out);
extern void CLACT_SetActorImageProxy(struct Obj *obj, const StaSpriteRes *res);
extern u8 APP_ICON_GetTypePaletteOffset(int typeId);
extern void CLACT_SetActorPaletteOffset(struct Obj *obj, u32 palette, u32 flag);
extern void CLACT_AddActorSurfacePos(struct Obj *obj, const StaOamPoint *pos, u32 mode);
extern void CLACT_SetActorBgPriority(struct Obj *obj, u32 value);
extern void BG_SYS_SetTileEntry(unsigned int bgLayer, int a, int b, int c, unsigned char d, unsigned char e, unsigned char f);
extern void BG_SYS_ClearLayerEx(int bgLayer, u16 value);
extern void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 width, u32 height, u32 color);
extern void BMP_Delete(struct Bmp *bmp);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQue *queue, struct Bmp *bmp);
extern void BMP_WIN_SetPalette(struct BmpWin *win, u8 value);
extern void BG_SYS_PushTileSource(u32 index, const void *src, u32 size, u32 offset);
extern int BGWINFRM_GetScaleRank(u32 curHp, u32 maxHp);
extern u8 BGWINFRM_ScaleRatio(u32 curHp, u32 maxHp, u32 pixels);
extern void BMP_Clear(struct Bmp *bmp, u8 fill);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern u8 APP_ICON_GetMoveKindPaletteOffset(u8 typeId);
extern u32 WAZA_TOOL_GetPower(u16 moveId);
extern u32 WAZA_TOOL_GetParam(u16 moveId, u32 field);
extern u32 WAZA_TOOL_IsAlwaysHit(u16 moveId);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heapId);
extern void CLACT_RestartActorAnim(struct Obj *obj);
extern u32 EVENT_ID_Check(void *config, u16 moveId, u16 heapId);
extern void POKE_TOOL_SetBoxMoveSlot(void *pp, u16 id, u32 value);
extern s8 POKE_TOOL_GetNatureModifier(u32 nature, u32 statIndex);
extern int WAZA_TOOL_GetType(u16 moveId);

/* Status screen functions (p_status.c). */
void P_STATUS_SetInputEnable(PStatusWork *wk, int enable);
void *P_STATUS_GetPokePara(PStatusWork *wk);
int P_STATUS_GetPokeParaSource(PStatusWork *wk);
void P_STATUS_SetFastMode(PStatusWork *wk, int fastMode);
void P_STATUS_PrintMsg(PStatusWork *wk, struct Bmp *bmp, int msgId, int x, unsigned short y, unsigned short color);
void P_STATUS_PrintMsgToWin(PStatusWork *wk, struct BmpWin *win, int msgId, int x, unsigned short y, unsigned short color);
void P_STATUS_PrintWordSetMsg(PStatusWork *wk, struct Bmp *bmp, struct WordSet *wordSet, int msgId, unsigned short x, unsigned short y, unsigned short color);
void P_STATUS_PrintWordSetMsgToWin(PStatusWork *wk, struct BmpWin *win, struct WordSet *wordSet, int msgId, unsigned short x, unsigned short y, unsigned short color);
void P_STATUS_PrintWordSetMsgRight(PStatusWork *wk, struct Bmp *bmp, struct WordSet *wordSet, int msgId, unsigned short x, unsigned short y, unsigned short color);
void P_STATUS_PrintWordSetMsgRightToWin(PStatusWork *wk, struct BmpWin *win, struct WordSet *wordSet, int msgId, unsigned short x, unsigned short y, unsigned short color);

/* Pokemon status screen sub-page in p_sta_oam.c. */
StaOamManager *P_STA_OAM_CreateManager(u32 heapId, void *clunit);
void P_STA_OAM_DeleteManager(StaOamManager *manager);
StaOamBitmapActors *P_STA_OAM_CreateBitmapActors(StaOamManager *manager, const StaOamBitmapDesc *desc);
void P_STA_OAM_DeleteBitmapActors(StaOamBitmapActors *actors);
void P_STA_OAM_SetBitmapActorsEnabled(StaOamBitmapActors *actors, int enable);
void P_STA_OAM_TransferBitmap(StaOamBitmapActors *actors);
void P_STA_OAM_SwapInts(StaOamBitmapActors *a, StaOamBitmapActors *b);

/* This file. */
PStaSkillWork *P_STA_SKILL_Create(PStatusWork *wk);
void P_STA_SKILL_Delete(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_Main(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_LoadArcGraphics(PStatusWork *wk, PStaSkillWork *work, void *arc);
void P_STA_SKILL_Exit(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_CreateObjects(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_DeleteObjects(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_InitStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_ShowStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_FreeStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_HideStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_PrintStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_ApplyStatsScreen(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_RefreshMoveDetail(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_ApplyMovesScreen(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_PrintStats(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_DrawHpBar(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_PrintMoveDetail(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_InitMovesPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_ShowMovesPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_FreeMovesPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_HideMovesPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_UpdateInput(PStatusWork *wk, PStaSkillWork *work);
int P_STA_SKILL_HandleKeys(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_HandleTouch(PStatusWork *wk, PStaSkillWork *work);
int P_STA_SKILL_HandleKeysForget(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_HandleTouchForget(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_StepCursor(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_SetCursor(PStatusWork *wk, PStaSkillWork *work, u8 newSlot, int forceRefresh);
void P_STA_SKILL_SwapMoves(PStatusWork *wk, PStaSkillWork *work, u32 slotA, u32 slotB);
void P_STA_SKILL_SetNewMoveHeld(PStatusWork *wk, PStaSkillWork *work, int isNewMoveHeld);
void P_STA_SKILL_ShowCantForgetMsg(PStatusWork *wk, PStaSkillWork *work, int result);
u16 P_STA_SKILL_GetNatureStatColor(PStatusWork *wk, PStaSkillWork *work, unsigned char nature, u32 statIndex);
void P_STA_SKILL_CreateSlotObjects(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot, u8 index);
void P_STA_SKILL_DeleteSlotObjects(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_UpdateSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_InitSlotText(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_ShowSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_FreeSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_HideSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_GetSlotTouchRect(PStaSkillSlot *slot, StaTouchRect *rect);
void P_STA_SKILL_GetSlotPos(PStaSkillSlot *slot, StaOamPoint *out);
void P_STA_SKILL_SetSlotAnim(PStaSkillSlot *slot, int animOffset);
extern const char P_STA_SKILL_FileName[];
extern const u8 P_STA_SKILL_WindowTemplates[];
extern const u8 P_STA_SKILL_SlotTilePos[][2];

PStaSkillWork *P_STA_SKILL_Create(PStatusWork *wk)
{
    PStaSkillWork *work;
    u8 i;
    work=GFL_HEAP_Alloc(wk->heapId,296,0,P_STA_SKILL_FileName,315);
    work->isOpen=0;
    work->statsPrintPending=0;
    work->movePrintPending=0;
    work->swapPending=0;
    work->isMoveHeld=0;
    work->isPickingForget=0;
    work->blinkSlotFrame=0;
    work->heldSlot=STA_SKILL_SLOT_NONE;
    work->cursorSlot=STA_SKILL_NO_CURSOR;
    if (wk->param->mode==2 && wk->param->newMove!=0) work->slotCount=STA_SKILL_SLOT_MAX;
    else work->slotCount=STA_SKILL_SLOT_MAX - 1;
    for(i=0;i<STA_SKILL_SLOT_MAX;i++) {
        work->slot[i].index=255;
        work->slot[i].redrawPending=0;
    }
    return work;
}

void P_STA_SKILL_Delete(PStatusWork *wk, PStaSkillWork *work)
{
    GFL_HEAP_Free(work);
}

/*
 * proof: all scaled indices are ldrb or byte loop counters, hence
 * *24 <=6120 and *4 <=1020. blinkCount+1 <=256 before the byte store;
 * signed %8 uses the reloaded byte 0..255, with no overflow or division
 * failure. No smaller range or successful callee result is assumed.
 */
void P_STA_SKILL_Main(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    int allPrinted;
    void *win;
    if(work->statsPrintPending==0 && work->movePrintPending==0 && work->swapPending==0 && work->isConfirmed==0) P_STA_SKILL_UpdateInput(wk,work);
    if(work->statsPrintPending==1) {
        allPrinted=1;
        for(i=0;i<=7;i++) {
            if(PRINTSYS_QUE_IsExistTarget(wk->printQue,BMP_WIN_GetBmp(work->win[i]))==1) {
                allPrinted=0;
                break;
            }
        }
        if(allPrinted==1) {
            for(i=0;i<=7;i++) {
                win=work->win[i];
                BMP_WIN_TransferChars(win);
                BMP_WIN_MakeScreen(win);
                BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(win));
            }
            P_STA_SKILL_ApplyStatsScreen(wk,work);
            work->statsPrintPending=0;
        }
    }
    if(work->movePrintPending==1) {
        allPrinted=1;
        for(i=8;i<=11;i++) {
            if(PRINTSYS_QUE_IsExistTarget(wk->printQue,BMP_WIN_GetBmp(work->win[i]))==1) {
                allPrinted=0;
                break;
            }
        }
        if(allPrinted==1) {
            for(i=8;i<=11;i++) {
                win=work->win[i];
                BMP_WIN_TransferChars(win);
                BMP_WIN_MakeScreen(win);
                BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(win));
            }
            P_STA_SKILL_ApplyMovesScreen(wk,work);
            work->movePrintPending=0;
        }
    }
    if(work->msgPrintPending==1) {
        if(PRINTSYS_QUE_IsExistTarget(wk->printQue,BMP_WIN_GetBmp(work->win[STA_SKILL_WIN_MESSAGE]))==0) {
            win=work->win[STA_SKILL_WIN_MESSAGE];
            BMP_WIN_TransferChars(win);
            BMP_WIN_MakeScreen(win);
            BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(win));
            work->msgPrintPending=0;
        }
    }
    if(work->swapPending==1 && PRINTSYS_QUE_IsFinished(wk->printQue)==1) {
        work->isMoveHeld=0;
        P_STA_SKILL_SetSlotAnim(&work->slot[work->heldSlot],0);
        work->heldSlot=STA_SKILL_SLOT_NONE;
        P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
        CLACT_SetActorDrawEnable(work->heldObj,0);
        work->swapPending=0;
    }
    for(i=0;i<STA_SKILL_SLOT_MAX;i++) P_STA_SKILL_UpdateSlot(wk,work,&work->slot[i]);
    if(work->isConfirmed==1) {
        work->blinkCount++;
        if(work->blinkCount%8<4) {
            if(work->blinkSlotFrame==1) CLACT_SetActorAnimSeq(work->slot[work->cursorSlot].frameObj,15);
            else P_STA_SKILL_SetSlotAnim(&work->slot[work->cursorSlot],0);
        } else {
            if(work->blinkSlotFrame==1) CLACT_SetActorAnimSeq(work->slot[work->cursorSlot].frameObj,16);
            else P_STA_SKILL_SetSlotAnim(&work->slot[work->cursorSlot],1);
        }
        if(work->blinkCount>16) wk->seq=2;
    }
}

void P_STA_SKILL_LoadArcGraphics(PStatusWork *wk, PStaSkillWork *work, void *arc)
{
    work->bgScrnFile=func_02049EF4(arc,72,0,&work->bgScrnData,wk->heapId);
    work->statsPlttFile=func_02049EF4(arc,73,0,&work->statsPlttData,wk->heapId);
    work->movesPlttFile=func_02049EF4(arc,74,0,&work->movesPlttData,wk->heapId);
    work->statsScrnFile=func_02049EF4(arc,75,0,&work->statsScrnData,wk->heapId);
    work->movesScrnFile=func_02049EF4(arc,76,0,&work->movesScrnData,wk->heapId);
    work->oamManager=P_STA_OAM_CreateManager(wk->heapId,wk->clunit);
}

void P_STA_SKILL_Exit(PStatusWork *wk, PStaSkillWork *work)
{
    if (work->isOpen == 1) {
        if (wk->param->mode == 2) P_STA_SKILL_FreeMovesPage(wk, work);
        else P_STA_SKILL_FreeStatsPage(wk, work);
    }
    P_STA_OAM_DeleteManager(work->oamManager);
    GFL_HEAP_Free(work->bgScrnFile);
    GFL_HEAP_Free(work->statsPlttFile);
    GFL_HEAP_Free(work->movesPlttFile);
    GFL_HEAP_Free(work->statsScrnFile);
    GFL_HEAP_Free(work->movesScrnFile);
}

/*
 * extent: two zero alignment bytes at 021D9BD2 follow the 390-byte body.
 * proof: i is byte-wrapped; i*24 <=6120, every descriptor byte initialized.
 * No bound smaller than the ldrb domain is assumed for slotCount.
 * prototype: 0204B294 leaves 0204CFDC's pointer result live at 0204B318;
 * this caller stores r0 after every call. Keep all seven own-body inputs.
 */
void P_STA_SKILL_CreateObjects(PStatusWork *wk, PStaSkillWork *work)
{
    StaOamActorPos pos;
    u8 i;
    pos.x=159;
    pos.y=52;
    pos.drawPriority=10;
    pos.bgPriority=1;
    i=0;
    pos.animSeq=0;
    work->statsObj=CLACT_CreateActor(wk->clunit,wk->objRes[19],wk->objRes[5],wk->objRes[31],&pos,1,wk->heapId);
    CLACT_SetActorDrawEnable(work->statsObj,0);
    pos.x=172;
    pos.y=56;
    work->moveTypeObj=CLACT_CreateActor(wk->clunit,wk->objRes[16],wk->objRes[4],wk->objRes[29],&pos,1,wk->heapId);
    CLACT_SetActorDrawEnable(work->moveTypeObj,0);
    pos.bgPriority=0;
    work->cursorObj=CLACT_CreateActor(wk->clunit,wk->objRes[21],wk->objRes[11],wk->objRes[33],&pos,0,wk->heapId);
    CLACT_SetActorDrawEnable(work->cursorObj,0);
    pos.animSeq=5;
    pos.drawPriority=8;
    work->heldObj=CLACT_CreateActor(wk->clunit,wk->objRes[21],wk->objRes[11],wk->objRes[33],&pos,0,wk->heapId);
    CLACT_SetActorDrawEnable(work->heldObj,0);
    CLACT_SetActorAutoAnim(work->heldObj,1);
    pos.animSeq=2;
    pos.drawPriority=4;
    pos.bgPriority=0;
    work->touchObj=CLACT_CreateActor(wk->clunit,wk->objRes[21],wk->objRes[11],wk->objRes[33],&pos,0,wk->heapId);
    CLACT_SetActorDrawEnable(work->touchObj,0);
    CLACT_SetActorAutoAnim(work->touchObj,1);
    for(;i<work->slotCount;i++) P_STA_SKILL_CreateSlotObjects(wk,work,&work->slot[i],i);
}

void P_STA_SKILL_DeleteObjects(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    for (i = 0; i < work->slotCount; i++)
        P_STA_SKILL_DeleteSlotObjects(wk, work, &work->slot[i]);
    CLACT_DeleteActor(work->statsObj);
    CLACT_DeleteActor(work->moveTypeObj);
    CLACT_DeleteActor(work->cursorObj);
    CLACT_DeleteActor(work->heldObj);
    CLACT_DeleteActor(work->touchObj);
}

void P_STA_SKILL_InitStatsPage(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    for(i=0;i<STA_SKILL_WIN_MAX;i++) {
        *(struct BmpWin **)((u8 *)work->win+i*4)=BMP_WIN_Create(4,P_STA_SKILL_WindowTemplates[i*4],P_STA_SKILL_WindowTemplates[i*4+1],P_STA_SKILL_WindowTemplates[i*4+2],P_STA_SKILL_WindowTemplates[i*4+3],14,1);
    }
    BMP_WIN_SetPalette(work->win[STA_SKILL_WIN_HP_BAR],13);
    P_STA_SKILL_PrintStatsPage(wk,work);
    for(i=0;i<work->slotCount;i++) P_STA_SKILL_InitSlotText(wk,work,&work->slot[i]);
    work->cursorSlot=STA_SKILL_NO_CURSOR;
    work->isOpen=1;
    work->isConfirmed=0;
    work->blinkCount=0;
}

void P_STA_SKILL_ShowStatsPage(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    BG_SYS_DrawTileEx(2,0,0,32,24,(u32)work->bgScrnData+12,0,0,32,32);
    BG_SYS_SetFlagField06(2);
    P_STA_SKILL_ApplyStatsScreen(wk,work);
    for(i=0;i<work->slotCount;i++) P_STA_SKILL_ShowSlot(wk,work,&work->slot[i]);
    CLACT_SetActorAnimSeq(wk->buttonActor[1],4);
}

void P_STA_SKILL_FreeStatsPage(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    for (i = 0; i < work->slotCount; i++)
        P_STA_SKILL_FreeSlot(wk, work, &work->slot[i]);
    for (i = 0; i < STA_SKILL_WIN_MAX; i++)
        BMP_WIN_Delete(work->win[i]);
    work->isOpen = 0;
}

void P_STA_SKILL_HideStatsPage(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    for(i=0;i<work->slotCount;i++) P_STA_SKILL_HideSlot(wk,work,&work->slot[i]);
    BG_SYS_SetTileEntry(1,0,0,0,19,21,16);
    BG_SYS_PushTile(1);
    BG_SYS_ClearLayerEx(4,0);
    BG_SYS_SetFlagField06(4);
    CLACT_SetActorDrawEnable(work->statsObj,0);
    CLACT_SetActorDrawEnable(work->moveTypeObj,0);
    CLACT_SetActorDrawEnable(wk->typeIconActor[0],0);
    CLACT_SetActorDrawEnable(wk->typeIconActor[1],0);
    CLACT_SetActorAnimSeq(wk->buttonActor[1],1);
}

void P_STA_SKILL_PrintStatsPage(PStatusWork *wk, PStaSkillWork *work)
{
    P_STA_SKILL_PrintStats(wk, work);
    P_STA_SKILL_DrawHpBar(wk, work);
}

void P_STA_SKILL_ApplyStatsScreen(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    void *win;
    i=0;
    BG_SYS_ClearLayerEx(4,0);
    for(;i<=7;i++) {
        win=work->win[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
    }
    BG_SYS_DecodeTile(6,(u8 *)work->statsPlttData+12,((StaGraphicsFile *)work->statsPlttData)->dataSize);
    BG_SYS_SetFlagField06(6);
    BG_SYS_DrawTileEx(5,0,0,32,3,(u32)work->statsScrnData+12,0,0,32,32);
    BG_SYS_SetFlagField06(5);
    CLACT_SetActorDrawEnable(work->statsObj,1);
    CLACT_SetActorDrawEnable(work->moveTypeObj,0);
    CLACT_SetActorDrawEnable(wk->typeIconActor[0],0);
    CLACT_SetActorDrawEnable(wk->typeIconActor[1],0);
}

void P_STA_SKILL_RefreshMoveDetail(PStatusWork *wk, PStaSkillWork *work)
{
    P_STA_SKILL_PrintMoveDetail(wk,work);
}

/*
 * extent: two zero alignment bytes at 021DA0AE follow the 446-byte body.
 * proof: i is a byte, i*24 <=6120. type1/type2 remain full-word u32
 * results; unsigned address multiply/add preserve original modulo-2^32
 * lsl/add without invented selector bounds. 0204AB84 writes all nine words
 * before 0204B784 reads them; both StaOamPoint halfwords are stored before use.
 */
void P_STA_SKILL_ApplyMovesScreen(PStatusWork *wk, PStaSkillWork *work)
{
    StaSpriteRes type1Res,type2Res;
    StaOamPoint pos;
    u8 i;
    void *win;
    void *pp;
    u32 type1,type2;
    BG_SYS_ClearLayerEx(4,0);
    for(i=8;i<=11;i++) {
        win=work->win[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
    }
    i=0;
    BG_SYS_PushTileSource(6,(u8 *)work->movesPlttData+12,((StaGraphicsFile *)work->movesPlttData)->dataSize,0);
    BG_SYS_DecodeTile(6,(u8 *)work->movesPlttData+12,((StaGraphicsFile *)work->movesPlttData)->dataSize);
    BG_SYS_SetFlagField06(6);
    BG_SYS_DrawTileEx(5,0,0,32,3,(u32)((u8 *)work->movesScrnData+12),0,0,32,32);
    BG_SYS_SetFlagField06(5);
    CLACT_SetActorDrawEnable(work->statsObj,0);
    CLACT_SetActorDrawEnable(work->moveTypeObj,1);
    for(;i<work->slotCount;i++) P_STA_SKILL_ShowSlot(wk,work,&work->slot[i]);
    pp=P_STATUS_GetPokePara(wk);
    type1=POKE_TOOL_GetBoxValue(pp,174,0);
    type2=POKE_TOOL_GetBoxValue(pp,175,0);
    CLACT_GetCharacterProxy(wk->typeChrRes[type1],&type1Res);
    CLACT_SetActorImageProxy(wk->typeIconActor[0],&type1Res);
    CLACT_SetActorPaletteOffset(wk->typeIconActor[0],APP_ICON_GetTypePaletteOffset((u8)type1),1);
    pos.x=208;
    pos.y=120;
    CLACT_AddActorSurfacePos(wk->typeIconActor[0],&pos,0);
    CLACT_SetActorDrawEnable(wk->typeIconActor[0],1);
    CLACT_SetActorBgPriority(wk->typeIconActor[0],0);
    if(type1!=type2) {
        CLACT_GetCharacterProxy(wk->typeChrRes[type2],&type2Res);
        CLACT_SetActorImageProxy(wk->typeIconActor[1],&type2Res);
        CLACT_SetActorPaletteOffset(wk->typeIconActor[1],APP_ICON_GetTypePaletteOffset((u8)type2),1);
        pos.x=240;
        pos.y=120;
        CLACT_AddActorSurfacePos(wk->typeIconActor[1],&pos,0);
        CLACT_SetActorDrawEnable(wk->typeIconActor[1],1);
        CLACT_SetActorBgPriority(wk->typeIconActor[1],0);
    } else CLACT_SetActorDrawEnable(wk->typeIconActor[1],0);
}

/*
 * semantics: full-word results retained; only explicit u8 call arguments
 * narrow. No signed arithmetic or caller-domain assumptions.
 * prototype: 618C final stack argument is u16; P_STA_SKILL_GetNatureStatColor is declared to
 * return u16 so its result needs no extra truncation at the call.
 */
void P_STA_SKILL_PrintStats(PStatusWork *wk, PStaSkillWork *work)
{
    void *pp;
    u32 nature;
    int one;
    struct WordSet *words;
    u32 abilityId;
    void *abilityNameBank,*abilityDescBank,*str;
    pp=(void *)P_STATUS_GetPokeParaSource(wk);
    nature=POKE_TOOL_GetPartyValue(pp,112,0);
    one=1;
    P_STATUS_PrintMsgToWin(wk,work->win[STA_SKILL_WIN_HP_LABEL],110,25,one,15424);
    words=WORDSET_CreateDefault(wk->heapId);
    WORDSET_SetSlotNumber(words,0,POKE_TOOL_GetPartyValue(pp,160,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(wk,work->win[STA_SKILL_WIN_HP_LABEL],words,119,89,one,1088);
    WORDSET_DeleteStrbufED04(words);
    P_STATUS_PrintMsgToWin(wk,work->win[STA_SKILL_WIN_HP_LABEL],117,93,one,1088);
    words=WORDSET_CreateDefault(wk->heapId);
    WORDSET_SetSlotNumber(words,0,POKE_TOOL_GetPartyValue(pp,161,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(wk,work->win[STA_SKILL_WIN_HP_LABEL],words,118,121,one,1088);
    WORDSET_DeleteStrbufED04(words);
    P_STATUS_PrintMsgToWin(wk,work->win[STA_SKILL_WIN_ATTACK],111,one,one,P_STA_SKILL_GetNatureStatColor(wk,work,nature,one));
    words=WORDSET_CreateDefault(wk->heapId);
    WORDSET_SetSlotNumber(words,0,POKE_TOOL_GetPartyValue(pp,162,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(wk,work->win[STA_SKILL_WIN_ATTACK],words,120,105,one,1088);
    WORDSET_DeleteStrbufED04(words);
    P_STATUS_PrintMsgToWin(wk,work->win[STA_SKILL_WIN_DEFENSE],112,one,one,P_STA_SKILL_GetNatureStatColor(wk,work,nature,2));
    words=WORDSET_CreateDefault(wk->heapId);
    WORDSET_SetSlotNumber(words,0,POKE_TOOL_GetPartyValue(pp,163,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(wk,work->win[STA_SKILL_WIN_DEFENSE],words,121,105,one,1088);
    WORDSET_DeleteStrbufED04(words);
    P_STATUS_PrintMsgToWin(wk,work->win[STA_SKILL_WIN_SP_ATTACK],113,one,one,P_STA_SKILL_GetNatureStatColor(wk,work,nature,3));
    words=WORDSET_CreateDefault(wk->heapId);
    WORDSET_SetSlotNumber(words,0,POKE_TOOL_GetPartyValue(pp,165,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(wk,work->win[STA_SKILL_WIN_SP_ATTACK],words,122,105,one,1088);
    WORDSET_DeleteStrbufED04(words);
    P_STATUS_PrintMsgToWin(wk,work->win[STA_SKILL_WIN_SP_DEFENSE],114,one,one,P_STA_SKILL_GetNatureStatColor(wk,work,nature,4));
    words=WORDSET_CreateDefault(wk->heapId);
    WORDSET_SetSlotNumber(words,0,POKE_TOOL_GetPartyValue(pp,166,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(wk,work->win[STA_SKILL_WIN_SP_DEFENSE],words,123,105,one,1088);
    WORDSET_DeleteStrbufED04(words);
    P_STATUS_PrintMsgToWin(wk,work->win[STA_SKILL_WIN_SPEED],115,one,one,P_STA_SKILL_GetNatureStatColor(wk,work,nature,5));
    words=WORDSET_CreateDefault(wk->heapId);
    WORDSET_SetSlotNumber(words,0,POKE_TOOL_GetPartyValue(pp,164,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(wk,work->win[STA_SKILL_WIN_SPEED],words,124,105,one,1088);
    WORDSET_DeleteStrbufED04(words);
    P_STATUS_PrintMsgToWin(wk,work->win[STA_SKILL_WIN_ABILITY],116,5,one,15424);
    abilityId=POKE_TOOL_GetPartyValue(pp,10,0);
    abilityNameBank=MSGDATA_CreateFromArchive(0,2,183,wk->heapId);
    str=MSGDATA_AllocString(abilityNameBank,abilityId);
    PRINTSYS_PrintQueColor(wk->printQue,BMP_WIN_GetBmp(work->win[STA_SKILL_WIN_ABILITY]),5,17,str,wk->font,1088);
    STRBUF_Delete(str);
    MSGDATA_Delete(abilityNameBank);
    abilityDescBank=MSGDATA_CreateFromArchive(0,2,182,wk->heapId);
    str=MSGDATA_AllocString(abilityDescBank,abilityId);
    PRINTSYS_PrintQueColor(wk->printQue,BMP_WIN_GetBmp(work->win[STA_SKILL_WIN_ABILITY]),65,one,str,wk->font,1088);
    STRBUF_Delete(str);
    MSGDATA_Delete(abilityDescBank);
    work->statsPrintPending=one;
}

void P_STA_SKILL_DrawHpBar(PStatusWork *wk, PStaSkillWork *work) {
    void *pp,*bmp;
    u16 maxHp,curHp;
    int barColor,barPixels,firstRow,lastRow;
    pp=(void *)P_STATUS_GetPokeParaSource(wk);
    maxHp=POKE_TOOL_GetPartyValue(pp,161,0);
    curHp=POKE_TOOL_GetPartyValue(pp,160,0);
    barColor=BGWINFRM_GetScaleRank(curHp,maxHp);
    barPixels=BGWINFRM_ScaleRatio(curHp,maxHp,48);
    bmp=BMP_WIN_GetBmp(work->win[STA_SKILL_WIN_HP_BAR]);
    if((u8)(barColor+254)<=1) {firstRow=7;lastRow=8;}
    else if(barColor==1) {firstRow=9;lastRow=10;}
    else {firstRow=5;lastRow=6;}
    BMP_FillRect(bmp,0,3,barPixels,1,firstRow);
    BMP_FillRect(bmp,0,4,barPixels,1,lastRow);
}

/*
 * extent: two-byte zero alignment padding at 0x021DA6A2.
 * semantics: C1E8 forwards BD28(a,2); BDB4 case 2 at 0201BE0C
 * returns ldrb, bounding kind to 0..255 and (kind+16)*4 to 1084.
 * AB84 copies all 36 output bytes at 0204AB9C..0204ABB0 before B784
 * reads them. Other scalar arithmetic uses u8 indices or constants.
 */
void P_STA_SKILL_PrintMoveDetail(PStatusWork *wk, PStaSkillWork *work)
{
    void *pp,*powerWords,*accuracyWords,*descBank,*str;
    u8 i;
    int zero,one,moveId,moveType;
    u32 power,accuracy;
    StaSpriteRes typeRes;
    pp=P_STATUS_GetPokePara(wk);
    zero=0;
    for(i=8;i<=11;i++) BMP_Clear(BMP_WIN_GetBmp(work->win[i]),zero);
    if(work->cursorSlot<4) moveId=POKE_TOOL_GetBoxValue(pp,work->cursorSlot+54,(void *)zero);
    else if(work->cursorSlot==STA_SKILL_NO_CURSOR) {
        if(wk->param->mode==2 && work->slotCount==STA_SKILL_SLOT_MAX) moveId=wk->param->newMove;
        else moveId=POKE_TOOL_GetBoxValue(pp,54,0);
    } else moveId=wk->param->newMove;
    one=1;
    P_STATUS_PrintMsgToWin(wk, work->win[STA_SKILL_WIN_MOVE_CATEGORY], 149, 1, one, 15424);
    moveType=WAZA_TOOL_GetDamageType((u16)moveId);
    CLACT_GetCharacterProxy(wk->objRes[moveType+16],&typeRes);
    CLACT_SetActorImageProxy(work->moveTypeObj,&typeRes);
    CLACT_SetActorPaletteOffset(work->moveTypeObj,APP_ICON_GetMoveKindPaletteOffset(moveType),1);
    P_STATUS_PrintMsgToWin(wk, work->win[STA_SKILL_WIN_MOVE_POWER], 147, 1, one, 15424);
    power=WAZA_TOOL_GetPower(moveId);
    if(power<=1) P_STATUS_PrintMsgToWin(wk, work->win[STA_SKILL_WIN_MOVE_POWER], 154, 87, one, 1088);
    else {
        powerWords=WORDSET_CreateDefault(wk->heapId);
        WORDSET_SetSlotNumber(powerWords,0,power,3,one,one);
        P_STATUS_PrintWordSetMsgToWin(wk,work->win[STA_SKILL_WIN_MOVE_POWER],powerWords,150,81,one,1088);
        WORDSET_DeleteStrbufED04(powerWords);
    }
    P_STATUS_PrintMsgToWin(wk, work->win[STA_SKILL_WIN_MOVE_ACCURACY], 148, 1, 1, 15424);
    accuracy=WAZA_TOOL_GetParam(moveId,4);
    if(WAZA_TOOL_IsAlwaysHit(moveId)==1 || accuracy==0) P_STATUS_PrintMsgToWin(wk, work->win[STA_SKILL_WIN_MOVE_ACCURACY], 154, 87, 1, 1088);
    else {
        accuracyWords=WORDSET_CreateDefault(wk->heapId);
        WORDSET_SetSlotNumber(accuracyWords,0,accuracy,3,1,1);
        P_STATUS_PrintWordSetMsgToWin(wk,work->win[STA_SKILL_WIN_MOVE_ACCURACY],accuracyWords,151,81,1,1088);
        WORDSET_DeleteStrbufED04(accuracyWords);
    }
    descBank=MSGDATA_CreateFromArchive(0,2,202,wk->heapId);
    str=MSGDATA_AllocString(descBank,moveId);
    PRINTSYS_PrintQueColor(wk->printQue,BMP_WIN_GetBmp(work->win[STA_SKILL_WIN_MOVE_DESC]),1,1,str,wk->font,1088);
    STRBUF_Delete(str);
    MSGDATA_Delete(descBank);
    work->msgPrintPending=0;
    work->movePrintPending=1;
}

/*
 * semantics: u8 loop indices bound multiplication to 255*24; no signed
 * overflow. Descriptor fields are initialized before the call. BAD0 reads
 * offsets 0,4,6,8,12,16,17,18,20; trailing padding is never read.
 */
void P_STA_SKILL_InitMovesPage(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    StaOamBitmapDesc desc;
    for(i=0;i<STA_SKILL_WIN_MAX;i++) {
        *(struct BmpWin **)((u8 *)work->win+i*4)=BMP_WIN_Create(4,P_STA_SKILL_WindowTemplates[i*4],P_STA_SKILL_WindowTemplates[i*4+1],P_STA_SKILL_WindowTemplates[i*4+2],P_STA_SKILL_WindowTemplates[i*4+3],14,1);
    }
    BMP_WIN_SetPalette(work->win[STA_SKILL_WIN_HP_BAR],13);
    P_STA_SKILL_RefreshMoveDetail(wk,work);
    for(i=0;i<work->slotCount;i++) P_STA_SKILL_InitSlotText(wk,work,&work->slot[i]);
    if(work->slotCount==STA_SKILL_SLOT_MAX) {
        work->giveUpBmp=BMP_Create(11,4,32,wk->heapId);
        P_STATUS_PrintMsg(wk,work->giveUpBmp,193,5,9,1088);
        desc.x=32;
        desc.y=160;
        desc.plttRes=wk->objRes[8];
        desc.animSeq=0;
        desc.drawPriority=0;
        desc.bgPriority=0;
        desc.space=0;
        desc.screen=0;
        desc.bmp=work->giveUpBmp;
        work->giveUpActors=P_STA_OAM_CreateBitmapActors(work->oamManager,&desc);
        P_STA_OAM_SetBitmapActorsEnabled(work->giveUpActors,0);
    }
    work->cursorSlot=STA_SKILL_NO_CURSOR;
    work->isOpen=1;
    work->isConfirmed=0;
    work->blinkCount=0;
}

/*
 * extent: two-byte zero alignment padding at 0x021DA84A.
 */
void P_STA_SKILL_ShowMovesPage(PStatusWork *wk, PStaSkillWork *work) {
    u8 i;
    BG_SYS_DrawTileEx(2,0,0,32,24,(u32)work->bgScrnData+12,0,0,32,32);
    BG_SYS_SetFlagField06(2);
    P_STA_SKILL_ApplyMovesScreen(wk,work);
    for(i=0;i<work->slotCount;i++) P_STA_SKILL_ShowSlot(wk,work,&work->slot[i]);
    CLACT_SetActorAnimSeq(wk->buttonActor[1],4);
    if(work->slotCount==STA_SKILL_SLOT_MAX) work->cursorSlot=4;else work->cursorSlot=0;
    P_STATUS_SetInputEnable(wk,0);
    P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
}

void P_STA_SKILL_FreeMovesPage(PStatusWork *wk, PStaSkillWork *work) {
    u8 i;
    if(work->slotCount==STA_SKILL_SLOT_MAX) {
        BMP_Delete(work->giveUpBmp);
        P_STA_OAM_DeleteBitmapActors(work->giveUpActors);
    }
    for(i=0;i<work->slotCount;i++) P_STA_SKILL_FreeSlot(wk,work,&work->slot[i]);
    for(i=0;i<STA_SKILL_WIN_MAX;i++) BMP_WIN_Delete(work->win[i]);
    work->isOpen=0;
}

void P_STA_SKILL_HideMovesPage(PStatusWork *wk, PStaSkillWork *work) {
    u8 i;
    for(i=0;i<work->slotCount;i++) P_STA_SKILL_HideSlot(wk,work,&work->slot[i]);
    BG_SYS_SetTileEntry(1,0,0,0,19,21,16);
    BG_SYS_PushTile(1);
    BG_SYS_ClearLayerEx(4,0);
    BG_SYS_SetFlagField06(4);
    CLACT_SetActorDrawEnable(work->statsObj,0);
    CLACT_SetActorDrawEnable(work->moveTypeObj,0);
    CLACT_SetActorDrawEnable(wk->typeIconActor[0],0);
    CLACT_SetActorDrawEnable(wk->typeIconActor[1],0);
    CLACT_SetActorAnimSeq(wk->buttonActor[1],1);
}

void P_STA_SKILL_UpdateInput(PStatusWork *wk, PStaSkillWork *work) {
    if (wk->param->mode != 2) {
        if (P_STA_SKILL_HandleKeys(wk,work)==0) P_STA_SKILL_HandleTouch(wk,work);
    } else {
        if (P_STA_SKILL_HandleKeysForget(wk,work)==0) P_STA_SKILL_HandleTouchForget(wk,work);
    }
    if (TOUCHPANEL_GetCont()==0) work->isTouching=0;
}

/*
 * lever: original shared return0 branch is goto out; selected byte local
 *   preserves the loaded value across its neighbouring selector store.
 * semantics: every key poll is independent; selector bytes retain their
 *   full0..255 domain, so promoted selector*24 is at most6120. No menu
 *   bound is assumed. BA54 unconditionally writes both point halfwords
 *   at BA5E/BA6A before4B404 reads them; no default or success assumption.
 * interfaces: own matched callees, else own-region matched callers.
 *   362DC own body returns a full-word pointer payload; this caller uses
 *   full r0 as a scalar comparison, retained as u32. No argument narrowed
 *   beyond original/callee width. All original call/store order retained.
 */
int P_STA_SKILL_HandleKeys(PStatusWork *wk, PStaSkillWork *work)
{
    StaOamPoint pos;
    if (work->isTouching==1) return 0;
    if (wk->isInputEnabled==1) {
        if (KEY_GetTrg()!=1) goto out;
            work->cursorSlot=0;
            wk->inputType=0;
            P_STATUS_SetInputEnable(wk,0);
            P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
            P_STA_SKILL_RefreshMoveDetail(wk,work);
            GFL_USE_PlaySeDefaultVolume(1356);
            return 1;
    } else {
        if (KEY_GetTrg()==2 && work->isMoveHeld==0) {
            P_STATUS_SetInputEnable(wk,1);
            CLACT_SetActorAnimSeq(wk->buttonActor[7],9);
            P_STA_SKILL_SetSlotAnim(&work->slot[work->cursorSlot],0);
            CLACT_SetActorDrawEnable(work->cursorObj,0);
            P_STA_SKILL_PrintStatsPage(wk,work);
            wk->inputType=0;
            GFL_USE_PlaySeDefaultVolume(1361);
            return 1;
        }
        if (wk->inputType==1) {
            if (KEY_GetTrg()==0) goto out;
                wk->inputType=0;
                work->heldSlot=STA_SKILL_SLOT_NONE;
                P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
                GFL_USE_PlaySeDefaultVolume(1352);
                return 1;
        } else {
            if (KEY_GetTrg()==1) {
                if (wk->param->mode==6) goto out;
                if (work->isMoveHeld==0) {
                    u8 selected;
                    work->isMoveHeld=1;
                    selected=work->cursorSlot;
                    work->heldSlot=selected;
                    P_STA_SKILL_SetSlotAnim(&work->slot[selected],2);
                    P_STA_SKILL_GetSlotPos(&work->slot[work->heldSlot],&pos);
                    CLACT_AddActorSurfacePos(work->heldObj,&pos,0);
                    CLACT_SetActorDrawEnable(work->heldObj,1);
                    CLACT_RestartActorAnim(work->heldObj);
                    GFL_USE_PlaySeDefaultVolume(1356);
                } else {
                    if (work->heldSlot!=work->cursorSlot) {
                        P_STA_SKILL_SwapMoves(wk,work,work->heldSlot,work->cursorSlot);
                        GFL_USE_PlaySeDefaultVolume(1357);
                    } else {
                        work->isMoveHeld=0;
                        P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
                        CLACT_SetActorDrawEnable(work->heldObj,0);
                        GFL_USE_PlaySeDefaultVolume(1356);
                    }
                }
                return 1;
            }
            if (KEY_GetTrg()==2 && work->isMoveHeld==1) {
                P_STA_SKILL_SetSlotAnim(&work->slot[work->heldSlot],0);
                P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
                CLACT_SetActorAnimSeq(wk->buttonActor[7],9);
                CLACT_SetActorDrawEnable(work->heldObj,0);
                work->isMoveHeld=0;
                work->heldSlot=STA_SKILL_SLOT_NONE;
                GFL_USE_PlaySeDefaultVolume(1361);
                return 1;
            }
            if (KEY_GetTrg()==64 || KEY_GetTrg()==128) {
                P_STA_SKILL_StepCursor(wk,work);
                return 1;
            }
        }
    }
out:
    return 0;
}

/*
 * lever: initialized bounded descriptor list and explicit controller arms;
 *   unsigned distance wrap preserves the original signed tests at INT_MIN.
 * output: BA14 writes all four bytes for each index0..4; terminal record
 *   first byte255 stops ADC before any remaining terminal bytes are read.
 *   Both C08->BBC and BA4->B58 return -1 or0..4 for this list; predicates
 *   do not write it. BA54 writes both halfwords before their consumers.
 * arithmetic: admitted index0..4 after -1 rejection keeps index+54 and
 *   index*24 representable; byte record selectors retain0..255, *24<=6120.
 *   Full word distance uses u32 subtraction/negation modulo2^32, with
 *   original signed tests; INT_MIN retains its wrapped negative result.
 * interfaces: observed C38/C60 scalar returns retained despite legacy
 *   own void wrappers; every original call argument and independent poll
 *   remains. No owner C, defaults, extra bound, volatile or signed overflow.
 */
void P_STA_SKILL_HandleTouch(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    int touchedSlot;
    u32 dragDistance;
    StaTouchRect touch[6];
    StaOamPoint pos2;
    StaOamPoint pos1;
    if (wk->tpHit==7 && wk->isInputEnabled==0) {
        P_STATUS_SetInputEnable(wk,1);
        CLACT_SetActorAnimSeq(wk->buttonActor[7],9);
        P_STA_SKILL_SetSlotAnim(&work->slot[work->cursorSlot],0);
        CLACT_SetActorDrawEnable(work->cursorObj,0);
        P_STA_SKILL_PrintStatsPage(wk,work);
        if (work->isMoveHeld==1) {
            P_STA_SKILL_SetSlotAnim(&work->slot[work->heldSlot],0);
            CLACT_SetActorDrawEnable(work->heldObj,0);
            work->isMoveHeld=0;
            work->heldSlot=STA_SKILL_SLOT_NONE;
        }
        wk->inputType=1;
        GFL_USE_PlaySeDefaultVolume(1361);
        return;
    }
    for (i=0;i<STA_SKILL_SLOT_MAX;i++) P_STA_SKILL_GetSlotTouchRect(&work->slot[i],&touch[i]);
    touch[5].top=255;
    if (TOUCHPANEL_GetTrg()==1) {
        touchedSlot=TOUCHPANEL_HitTrg(touch);
        if (touchedSlot==-1) goto out;
        if (POKE_TOOL_GetBoxValue(P_STATUS_GetPokePara(wk),touchedSlot+54,0)==0) goto out;
        if (wk->isInputEnabled==1) P_STATUS_SetInputEnable(wk,0);
        if (wk->param->mode!=6) {
            work->isTouching=1;
            if (work->isMoveHeld!=1) {
                work->heldSlot=touchedSlot;
                P_STA_SKILL_GetSlotPos(&work->slot[touchedSlot],&pos1);
                CLACT_AddActorSurfacePos(work->touchObj,&pos1,0);
                CLACT_SetActorDrawEnable(work->touchObj,1);
                if (touchedSlot==0) CLACT_SetActorAnimSeq(work->touchObj,3);
                else if (touchedSlot==3) CLACT_SetActorAnimSeq(work->touchObj,4);
                else CLACT_SetActorAnimSeq(work->touchObj,2);
            }
            work->touchStartX=wk->tpX;
            work->touchStartY=wk->tpY;
            P_STA_SKILL_GetSlotPos(&work->slot[touchedSlot],&pos2);
            CLACT_AddActorSurfacePos(work->heldObj,&pos2,0);
            CLACT_SetActorDrawEnable(work->heldObj,1);
            CLACT_RestartActorAnim(work->heldObj);
        }
        wk->inputType=1;
        P_STA_SKILL_SetCursor(wk,work,touchedSlot,1);
        GFL_USE_PlaySeDefaultVolume(1356);
        return;
    }
    if (TOUCHPANEL_GetCont()==1) {
        if (work->isTouching!=1) goto out;
        touchedSlot=TOUCHPANEL_HitCont(touch);
        if (work->isMoveHeld==0) {
            if (touchedSlot==-1) {
                work->isTouching=0;
                CLACT_SetActorDrawEnable(work->touchObj,0);
                CLACT_SetActorDrawEnable(work->heldObj,0);
            } else {
                dragDistance=work->touchStartY-wk->tpY;
                if ((int)dragDistance<0) dragDistance=0U-dragDistance;
                if ((int)dragDistance>8) {
                    P_STA_SKILL_SetSlotAnim(&work->slot[work->heldSlot],2);
                    work->isMoveHeld=1;
                    CLACT_SetActorDrawEnable(work->touchObj,0);
                }
            }
        }
        if (work->isMoveHeld==1) {
            if (touchedSlot!=-1) {
                if (POKE_TOOL_GetBoxValue(P_STATUS_GetPokePara(wk),touchedSlot+54,0)==0) goto out;
                P_STA_SKILL_SetCursor(wk,work,touchedSlot,0);
                return;
            }
            P_STA_SKILL_SetSlotAnim(&work->slot[work->heldSlot],0);
            CLACT_SetActorDrawEnable(work->touchObj,0);
            CLACT_SetActorDrawEnable(work->heldObj,0);
            work->isMoveHeld=0;
            work->isTouching=0;
            P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
            work->heldSlot=STA_SKILL_SLOT_NONE;
            return;
        }
    } else {
        if (work->isTouching==1) {
            CLACT_SetActorDrawEnable(work->touchObj,0);
            CLACT_SetActorDrawEnable(work->heldObj,0);
            if (work->isMoveHeld==1) {
                if (work->heldSlot!=work->cursorSlot) {
                    P_STA_SKILL_SwapMoves(wk,work,work->heldSlot,work->cursorSlot);
                    GFL_USE_PlaySeDefaultVolume(1357);
                    return;
                }
                work->isMoveHeld=0;
                P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
            }
        }
    }
out:
    return;
}

int P_STA_SKILL_HandleKeysForget(PStatusWork *wk, PStaSkillWork *work)
{
    StaOamPoint pos;
    u32 forgetBlock;
    u8 pickedSlot;
    if(wk->inputType==1 && KEY_GetTrg()!=0) {
        wk->inputType=0;
        if(work->isPickingForget==0) {
            work->heldSlot=STA_SKILL_SLOT_NONE;
            P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
        }
    }
    if(KEY_GetTrg()==2) {
        if(work->isPickingForget==0) {
            wk->inputType=0;
            wk->retCode=1;
            wk->param->retSel=1;
            wk->seq=2;
            CLACT_SetActorAnimSeq(wk->buttonActor[7],9);
            wk->pushedButton=wk->buttonActor[7];
            GFL_USE_PlaySeDefaultVolume(0x551);
            return 1;
        } else {
            wk->inputType=0;
            P_STA_SKILL_SetSlotAnim(&work->slot[work->heldSlot],0);
            P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
            CLACT_SetActorDrawEnable(work->heldObj,0);
            work->cursorSlot=work->heldSlot;
            work->heldSlot=STA_SKILL_SLOT_NONE;
            work->isPickingForget=0;
            P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
            CLACT_SetActorAnimSeq(wk->buttonActor[7],9);
            P_STA_SKILL_SetNewMoveHeld(wk,work,0);
            GFL_USE_PlaySeDefaultVolume(0x551);
        }
    } else if(work->isPickingForget!=0) {
        if(KEY_GetTrg()==1) {
            wk->inputType=0;
            wk->retCode=1;
            wk->param->retMovePos=work->heldSlot;
            wk->param->retSel=0;
            work->isConfirmed=1;
            work->blinkSlotFrame=1;
            wk->pushedButton=0;
            GFL_USE_PlaySeDefaultVolume(0x54c);
        }
    } else if(KEY_GetTrg()==1) {
        wk->inputType=0;
        if(work->cursorSlot<4) {
            forgetBlock=EVENT_ID_Check(wk->param->config,POKE_TOOL_GetBoxValue(P_STATUS_GetPokePara(wk),*(volatile u8 *)&work->cursorSlot+54,0),wk->heapId);
            if(forgetBlock==0 || wk->restoreModeAll==1) {
                if(wk->param->newMove==0) {
                    wk->retCode=1;
                    wk->param->retSel=0;
                    wk->param->retMovePos=work->cursorSlot;
                    work->isConfirmed=1;
                    wk->pushedButton=0;
                } else {
                    work->isPickingForget=1;
                    pickedSlot=work->cursorSlot;
                    work->heldSlot=pickedSlot;
                    P_STA_SKILL_SetSlotAnim(&work->slot[pickedSlot],2);
                    work->cursorSlot=4;
                    P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
                    P_STA_SKILL_GetSlotPos(&work->slot[work->heldSlot],&pos);
                    CLACT_AddActorSurfacePos(work->heldObj,&pos,0);
                    CLACT_SetActorDrawEnable(work->heldObj,1);
                    CLACT_RestartActorAnim(work->heldObj);
                    P_STA_SKILL_SetNewMoveHeld(wk,work,1);
                }
            } else {
                P_STA_SKILL_ShowCantForgetMsg(wk,work,forgetBlock);
                goto done;
            }
        } else {
            wk->retCode=1;
            wk->param->retSel=1;
            work->isConfirmed=1;
            wk->pushedButton=0;
        }
        GFL_USE_PlaySeDefaultVolume(0x54c);
done:
        return 1;
    } else {
        if(KEY_GetTrg()==0x40 || KEY_GetTrg()==0x80) {
            P_STA_SKILL_StepCursor(wk,work);
            return 1;
        }
    }
    return 0;
}

/*
 * note: callee EVENT_ID_Check filed as arm9 witness (pkt_0202F72C).
 * interface: C08 returns -1 or 0..4 for this five-record list (full
 *   C08/BBC/ADC bodies and nonwriting A70/AA4 predicates, retained evidence).
 *   BA14 writes every four-byte record; the sixth first byte is the sentinel.
 *   BA54 stores both output halfwords before returning. Only sentinel byte
 *   touch[5][0] is read; no other bytes of its partial record are consumed.
 * arithmetic: loop i is initialized zero and guarded <5; selected index
 *   admitted after -1 rejection is 0..4, so index+54 and index*24 are safe.
 *   Secondary record selector is an ldrb, 0..255, product <=6120. No menu
 *   domain, default output value, volatile or narrowed full-word result.
 */
void P_STA_SKILL_HandleTouchForget(PStatusWork *wk, PStaSkillWork *work)
{
    u8 i;
    int touchedSlot,forgetBlock;
    StaOamPoint pos;
    StaTouchRect touch[6];
    if (wk->tpHit==7) {
        if (work->isPickingForget==0) {
            wk->retCode=1;
            wk->param->retSel=1;
            wk->seq=2;
            CLACT_SetActorAnimSeq(wk->buttonActor[7],9);
            wk->pushedButton=wk->buttonActor[7];
            GFL_USE_PlaySeDefaultVolume(1361);
            return;
        }
        wk->inputType=1;
        P_STA_SKILL_SetSlotAnim(&work->slot[work->heldSlot],0);
        P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
        CLACT_SetActorDrawEnable(work->heldObj,0);
        work->heldSlot=STA_SKILL_SLOT_NONE;
        work->isPickingForget=0;
        if (work->slotCount==STA_SKILL_SLOT_MAX) {
            P_STA_SKILL_SetCursor(wk,work,4,0);
            P_STA_SKILL_RefreshMoveDetail(wk,work);
        } else {
            work->cursorSlot=STA_SKILL_NO_CURSOR;
            P_STA_SKILL_SetCursor(wk,work,255,0);
        }
        P_STA_SKILL_SetNewMoveHeld(wk,work,0);
        GFL_USE_PlaySeDefaultVolume(1361);
        return;
    }
    for (i=0;i<STA_SKILL_SLOT_MAX;i++) P_STA_SKILL_GetSlotTouchRect(&work->slot[i],&touch[i]);
    touch[5].top=255;
    touchedSlot=TOUCHPANEL_HitTrg(touch);
    if (touchedSlot==-1) return;
    if (work->isPickingForget==0) {
        if (touchedSlot<4) {
            if (POKE_TOOL_GetBoxValue(P_STATUS_GetPokePara(wk),touchedSlot+54,0)==0) return;
            forgetBlock=EVENT_ID_Check(wk->param->config,POKE_TOOL_GetBoxValue(P_STATUS_GetPokePara(wk),touchedSlot+54,0),wk->heapId);
            if (forgetBlock==0 || wk->restoreModeAll==1) {
                if (wk->param->newMove==0) {
                    wk->retCode=1;
                    wk->param->retSel=0;
                    wk->param->retMovePos=touchedSlot;
                    work->isConfirmed=1;
                    wk->pushedButton=0;
                    GFL_USE_PlaySeDefaultVolume(1356);
                    P_STA_SKILL_SetCursor(wk,work,touchedSlot,0);
                    P_STA_SKILL_SetSlotAnim(&work->slot[touchedSlot],2);
                    return;
                }
                wk->inputType=1;
                work->isPickingForget=1;
                P_STA_SKILL_SetCursor(wk,work,touchedSlot,0);
                work->heldSlot=touchedSlot;
                P_STA_SKILL_SetSlotAnim(&work->slot[touchedSlot],2);
                work->cursorSlot=4;
                P_STA_SKILL_SetCursor(wk,work,work->cursorSlot,0);
                P_STA_SKILL_GetSlotPos(&work->slot[work->heldSlot],&pos);
                CLACT_AddActorSurfacePos(work->heldObj,&pos,0);
                CLACT_SetActorDrawEnable(work->heldObj,1);
                CLACT_RestartActorAnim(work->heldObj);
                P_STA_SKILL_SetNewMoveHeld(wk,work,1);
                GFL_USE_PlaySeDefaultVolume(1356);
                return;
            }
            P_STA_SKILL_SetCursor(wk,work,touchedSlot,0);
            work->heldSlot=touchedSlot;
            P_STA_SKILL_SetSlotAnim(&work->slot[touchedSlot],2);
            P_STA_SKILL_ShowCantForgetMsg(wk,work,forgetBlock);
            return;
        }
        P_STA_SKILL_SetCursor(wk,work,touchedSlot,0);
        wk->inputType=1;
        wk->retCode=1;
        wk->param->retSel=1;
        work->isConfirmed=1;
        wk->pushedButton=0;
        GFL_USE_PlaySeDefaultVolume(1356);
        return;
    }
    if (touchedSlot==4) {
        wk->inputType=1;
        wk->retCode=1;
        wk->param->retMovePos=work->heldSlot;
        wk->param->retSel=0;
        work->isConfirmed=1;
        work->blinkSlotFrame=1;
        wk->pushedButton=0;
        GFL_USE_PlaySeDefaultVolume(1356);
    }
}

void P_STA_SKILL_StepCursor(PStatusWork *wk, PStaSkillWork *work) {
    void *pp;
    int slotIndex,step;
    unsigned moveId;
    pp=P_STATUS_GetPokePara(wk);
    slotIndex=work->cursorSlot;
    if(KEY_GetTrg()==64) step=-1;else step=1;
    GFL_USE_PlaySeDefaultVolume(1352);
    do {
        slotIndex+=step;
        if(slotIndex<0) slotIndex=work->slotCount-1;
        else if(slotIndex>work->slotCount-1) slotIndex=0;
        if(slotIndex<4) moveId=(u16)POKE_TOOL_GetBoxValue(pp,slotIndex+54,0);
        else moveId=wk->param->newMove;
    } while(moveId==0);
    P_STA_SKILL_SetCursor(wk,work,slotIndex,0);
}

/*
 * lever: repeat CLACT_SetActorDrawEnable in both arms to retain branch to next.
 */
void P_STA_SKILL_SetCursor(PStatusWork *wk, PStaSkillWork *work, u8 newSlot, int forceRefresh) {
    StaOamPoint pos;
    if(wk->inputType==0) {
        P_STA_SKILL_GetSlotPos(&work->slot[newSlot],&pos);
        CLACT_AddActorSurfacePos(work->cursorObj,&pos,0);
        CLACT_SetActorDrawEnable(work->cursorObj,0);
    } else CLACT_SetActorDrawEnable(work->cursorObj,0);
    if(work->cursorSlot!=work->heldSlot || work->isMoveHeld==0) {
        if(work->cursorSlot!=STA_SKILL_NO_CURSOR) P_STA_SKILL_SetSlotAnim(&work->slot[work->cursorSlot],0);
    } else P_STA_SKILL_SetSlotAnim(&work->slot[work->cursorSlot],2);
    P_STA_SKILL_SetSlotAnim(&work->slot[newSlot],1);
    if(work->cursorSlot!=newSlot || forceRefresh==1) {
        work->cursorSlot=newSlot;
        P_STA_SKILL_RefreshMoveDetail(wk,work);
    }
}

/*
 * extent: the final two bytes at 021DB612 are zero alignment padding.
 * semantic: selectors and slot indices preserve every input word. Selector
 *   additions and index*24/address additions are u32 wrap, with pointer
 *   conversion only after address arithmetic; no asserted slot bound.
 *   Six getter results and four selectors are assigned before use.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`apid=a;` before `apid=a+58U;`; `auid=a;` before `auid=a+62U;` and 2
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void P_STA_SKILL_SwapMoves(PStatusWork *wk, PStaSkillWork *work, u32 slotA, u32 slotB)
{
    void *pp;
    u32 moveA,ppA,ppUpsA,moveB,ppB,ppUpsB;
    u32 ppIdA,ppUpsIdA,ppIdB,ppUpsIdB;
    pp=P_STATUS_GetPokePara(wk);
    P_STATUS_SetFastMode(wk,1);
    moveA=POKE_TOOL_GetBoxValue(pp,slotA+54U,0);
    ppIdA=slotA+58U;
    ppA=POKE_TOOL_GetBoxValue(pp,ppIdA,0);
    ppUpsIdA=slotA+62U;
    ppUpsA=POKE_TOOL_GetBoxValue(pp,ppUpsIdA,0);
    moveB=POKE_TOOL_GetBoxValue(pp,slotB+54U,0);
    ppIdB=slotB+58U;
    ppB=POKE_TOOL_GetBoxValue(pp,ppIdB,0);
    ppUpsIdB=slotB+62U;
    ppUpsB=POKE_TOOL_GetBoxValue(pp,ppUpsIdB,0);
    POKE_TOOL_SetBoxMoveSlot(pp,moveB,slotA);
    POKE_TOOL_SetBoxMoveSlot(pp,moveA,slotB);
    POKE_TOOL_SetBoxValue(pp,ppIdA,ppB);
    POKE_TOOL_SetBoxValue(pp,ppUpsIdA,ppUpsB);
    POKE_TOOL_SetBoxValue(pp,ppIdB,ppA);
    POKE_TOOL_SetBoxValue(pp,ppUpsIdB,ppUpsA);
    P_STATUS_SetFastMode(wk,0);
    P_STA_OAM_SwapInts(work->slot[slotA].nameActors,work->slot[slotB].nameActors);
    work->slot[slotA].redrawPending=1;
    work->slot[slotB].redrawPending=1;
    P_STA_SKILL_RefreshMoveDetail(wk,work);
    work->swapPending=1;
}

void P_STA_SKILL_SetNewMoveHeld(PStatusWork *wk, PStaSkillWork *work, int isNewMoveHeld) {
    PStaSkillSlot *newMoveSlot=&work->slot[4];
    if(isNewMoveHeld==1) {
        CLACT_SetActorAnimSeq(newMoveSlot->frameObj,16);
        P_STA_OAM_SetBitmapActorsEnabled(newMoveSlot->nameActors,0);
        CLACT_SetActorDrawEnable(newMoveSlot->typeObj,0);
        P_STA_OAM_TransferBitmap(work->giveUpActors);
        P_STA_OAM_SetBitmapActorsEnabled(work->giveUpActors,1);
    } else {
        P_STA_OAM_SetBitmapActorsEnabled(work->giveUpActors,0);
        CLACT_SetActorDrawEnable(newMoveSlot->typeObj,1);
        if(work->cursorSlot==4) P_STA_SKILL_SetSlotAnim(newMoveSlot,1); else P_STA_SKILL_SetSlotAnim(newMoveSlot,0);
        P_STA_OAM_SetBitmapActorsEnabled(newMoveSlot->nameActors,1);
    }
}

void P_STA_SKILL_ShowCantForgetMsg(PStatusWork *wk, PStaSkillWork *work, int result) {
    work->msgPrintPending=1;
    BMP_Clear(BMP_WIN_GetBmp(work->win[STA_SKILL_WIN_MESSAGE]),0);
    if(result==1) P_STATUS_PrintMsgToWin(wk,work->win[STA_SKILL_WIN_MESSAGE],156,0,0,15424);
    GFL_USE_PlaySeDefaultVolume(1367);
}

u16 P_STA_SKILL_GetNatureStatColor(PStatusWork *wk, PStaSkillWork *work, unsigned char nature, u32 statIndex) {
 switch (POKE_TOOL_GetNatureModifier(nature, statIndex)) {
 case 1: return 0x3d20;
 case -1: return 0x3d40;
 case 0:
 default: return 0x3c40;
 }
}

/*
 * lever: assign slot->index before pos.x to schedule its store before the stack address.
 */
void P_STA_SKILL_CreateSlotObjects(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot, u8 index) {
    StaOamActorPos pos;
    slot->redrawPending=0;
    slot->index=index;
    pos.x=P_STA_SKILL_SlotTilePos[index][0]*8;
    pos.y=P_STA_SKILL_SlotTilePos[index][1]*8;
    pos.drawPriority=10;
    pos.bgPriority=0;
    pos.animSeq=slot->index;
    slot->frameObj=CLACT_CreateActor(wk->clunit,(wk->objRes[20]),(wk->objRes[6]),(wk->objRes[32]),&pos,0,wk->heapId);
    CLACT_SetActorDrawEnable(slot->frameObj,0);
    pos.x=P_STA_SKILL_SlotTilePos[slot->index][0]*8+26;
    pos.y=P_STA_SKILL_SlotTilePos[slot->index][1]*8+9;
    pos.drawPriority=8;
    pos.bgPriority=0;
    pos.animSeq=0;
    slot->typeObj=CLACT_CreateActor(wk->clunit,wk->typeChrRes[0],wk->objRes[3],(wk->objRes[29]),&pos,0,wk->heapId);
    CLACT_SetActorDrawEnable(slot->typeObj,0);
}

void P_STA_SKILL_DeleteSlotObjects(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot)
{
    CLACT_DeleteActor(slot->frameObj);
    CLACT_DeleteActor(slot->typeObj);
    slot->index = 0xff;
}

void P_STA_SKILL_UpdateSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot) {
}

/*
 * semantic: selector loads are fresh bytes after each getter, additions
 *   <=321 fit int. Every branch initializes id/count/value. Late table
 *   index is the full byte, with no assumed menu bound; address arithmetic
 *   is u32 wrap. Table x+5<=260, times8<=2080; y*8<=2040, fit s16.
 *   All24 descriptor bytes (including its value and screen) are assigned.
 *   Pool B95C/B960 name the same byte-pair object at C2B8 and its +1 byte.
 */
void P_STA_SKILL_InitSlotText(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot)
{
    StaOamBitmapDesc desc;
    void *pp;
    u32 moveId,curPP,maxPP;
    struct MsgData *nameBank;
    void *str;
    struct WordSet *ppWords,*maxPPWords;
    pp=P_STATUS_GetPokePara(wk);
    if(slot->index<4) {
        moveId=POKE_TOOL_GetBoxValue(pp,slot->index+54,0);
        curPP=POKE_TOOL_GetBoxValue(pp,slot->index+58,0);
        maxPP=POKE_TOOL_GetBoxValue(pp,slot->index+66,0);
    } else {
        moveId=wk->param->newMove;
        curPP=WAZA_TOOL_GetParam(moveId,5);
        maxPP=curPP;
    }
    slot->nameBmp=BMP_Create(11,4,32,wk->heapId);
    nameBank=MSGDATA_CreateFromArchive(0,2,203,wk->heapId);
    str=MSGDATA_AllocString(nameBank,moveId);
    PRINTSYS_PrintQueColor(wk->printQue,slot->nameBmp,3,2,str,wk->font,1088);
    STRBUF_Delete(str);
    MSGDATA_Delete(nameBank);
    if(moveId!=0) {
        P_STATUS_PrintMsg(wk,slot->nameBmp,135,13,17,1088);
        ppWords=WORDSET_CreateDefault(wk->heapId);
        WORDSET_SetSlotNumber(ppWords,0,curPP,3,1,1);
        P_STATUS_PrintWordSetMsgRight(wk,slot->nameBmp,ppWords,136,57,17,1088);
        WORDSET_DeleteStrbufED04(ppWords);
        P_STATUS_PrintMsg(wk,slot->nameBmp,117,57,17,1088);
        maxPPWords=WORDSET_CreateDefault(wk->heapId);
        WORDSET_SetSlotNumber(maxPPWords,0,maxPP,3,1,1);
        P_STATUS_PrintWordSetMsg(wk,slot->nameBmp,maxPPWords,141,61,17,1088);
        WORDSET_DeleteStrbufED04(maxPPWords);
    } else {
        P_STATUS_PrintMsg(wk,slot->nameBmp,153,49,17,1088);
    }
    desc.x=(P_STA_SKILL_SlotTilePos[slot->index][0]+5)*8;
    desc.y=P_STA_SKILL_SlotTilePos[slot->index][1]*8;
    desc.plttRes=wk->objRes[8];
    desc.animSeq=0;
    desc.drawPriority=6;
    desc.bgPriority=0;
    desc.space=0;
    desc.screen=0;
    desc.bmp=slot->nameBmp;
    slot->nameActors=P_STA_OAM_CreateBitmapActors(work->oamManager,&desc);
    slot->redrawPending=1;
}

/*
 * extent: two-byte zero alignment padding at 0x021DB9E6.
 */
void P_STA_SKILL_ShowSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot) {
    unsigned moveId;
    int moveType;
    StaSpriteRes typeRes;
    void *pp;
    pp=P_STATUS_GetPokePara(wk);
    if(slot->index<4) moveId=POKE_TOOL_GetBoxValue(pp,slot->index+54,0);
    else moveId=wk->param->newMove;
    if(slot->redrawPending==1) {
        if(moveId!=0) {
            moveType=WAZA_TOOL_GetType(moveId);
            CLACT_GetCharacterProxy(wk->typeChrRes[moveType],&typeRes);
            CLACT_SetActorImageProxy(slot->typeObj,&typeRes);
            CLACT_SetActorPaletteOffset(slot->typeObj,APP_ICON_GetTypePaletteOffset(moveType),1);
            CLACT_SetActorDrawEnable(slot->typeObj,1);
        } else CLACT_SetActorDrawEnable(slot->typeObj,0);
        P_STA_OAM_TransferBitmap(slot->nameActors);
        CLACT_SetActorDrawEnable(slot->frameObj,1);
        slot->redrawPending=0;
    }
}

void P_STA_SKILL_FreeSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot)
{
    BMP_Delete(slot->nameBmp);
    P_STA_OAM_DeleteBitmapActors(slot->nameActors);
}

void P_STA_SKILL_HideSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot)
{
    CLACT_SetActorDrawEnable(slot->frameObj, 0);
    CLACT_SetActorDrawEnable(slot->typeObj, 0);
}

void P_STA_SKILL_GetSlotTouchRect(PStaSkillSlot *slot, StaTouchRect *rect) {
    if (slot->index<5) {
        rect->top=P_STA_SKILL_SlotTilePos[slot->index][1]*8;
        rect->bottom=rect->top+32;
        rect->left=P_STA_SKILL_SlotTilePos[slot->index][0]*8;
        rect->right=rect->left+136;
    } else { rect->top=0;rect->bottom=0;rect->left=0;rect->right=0; }
}

void P_STA_SKILL_GetSlotPos(PStaSkillSlot *slot, StaOamPoint *out) {
 out->x = P_STA_SKILL_SlotTilePos[slot->index][0] << 3;
 out->y = P_STA_SKILL_SlotTilePos[slot->index][1] << 3;
}

void P_STA_SKILL_SetSlotAnim(PStaSkillSlot *slot, int animOffset)
{
    CLACT_SetActorAnimSeq(slot->frameObj, (u16)(slot->index + animOffset * 5));
}
