/*
 * file:     worldtrade_input.c
 * unit:     yes
 * function: WORLDTRADE_INPUT_PrintStringTop, WORLDTRADE_INPUT_PrintStringPlain, WORLDTRADE_INPUT_PrintBankString, WORLDTRADE_INPUT_PrintStringAligned, WORLDTRADE_INPUT_PrintStringAlignedLine, WORLDTRADE_INPUT_PrintStringAlignedWrapped, WORLDTRADE_INPUT_PrintCentered, WORLDTRADE_ENTER_RestartNetTimeout, WORLDTRADE_INPUT_CreateModeWindows, WORLDTRADE_INPUT_MenuFinish, WORLDTRADE_INPUT_MenuCreate, WORLDTRADE_INPUT_MenuSetMode, WORLDTRADE_INPUT_MenuDelete, WORLDTRADE_INPUT_MenuUpdate, WORLDTRADE_INPUT_CheckTouch, WORLDTRADE_INPUT_UpdateCategoryGrid, WORLDTRADE_INPUT_ClampPageChoice, WORLDTRADE_INPUT_UpdateButtonRow, WORLDTRADE_INPUT_GetPageCount, WORLDTRADE_INPUT_HandlePagedKey4, WORLDTRADE_INPUT_ScrollPage4, WORLDTRADE_INPUT_UpdatePagedList4, WORLDTRADE_INPUT_UpdateThreeOptionMenu, WORLDTRADE_INPUT_ScrollPage4Alt, WORLDTRADE_INPUT_HandlePagedKey4Alt, WORLDTRADE_INPUT_UpdatePagedList4Alt, WORLDTRADE_INPUT_MapModeToLabel, WORLDTRADE_INPUT_UpdateCategoryGridAlt, WORLDTRADE_INPUT_HandlePagedKey5, WORLDTRADE_INPUT_ScrollPage5, WORLDTRADE_INPUT_UpdatePagedList5, WORLDTRADE_INPUT_DrawFrame, WORLDTRADE_INPUT_DrawThreeOptionScreen, WORLDTRADE_INPUT_DrawGenderListScreen, WORLDTRADE_INPUT_PutBmpWinString, WORLDTRADE_INPUT_StateNone, WORLDTRADE_INPUT_StateWaitFrameIn, WORLDTRADE_INPUT_StateWaitFrameMove, WORLDTRADE_INPUT_StateStartFrameOutSlow, WORLDTRADE_INPUT_StateWaitFrameHide, WORLDTRADE_INPUT_StateStartFrameOut, WORLDTRADE_INPUT_StateStartCategoryScreen, WORLDTRADE_INPUT_StateCategoryInput, WORLDTRADE_INPUT_StateCategorySelected, WORLDTRADE_INPUT_DrawCategoryScreen, WORLDTRADE_INPUT_DrawSubCategoryScreen, WORLDTRADE_INPUT_StateSubCategoryInput, WORLDTRADE_INPUT_StateSubCategorySelected, WORLDTRADE_INPUT_StateRestoreCursor, WORLDTRADE_INPUT_CountSeenSpecies, WORLDTRADE_INPUT_CreateSpeciesMenu, WORLDTRADE_INPUT_PrintPageNumberA, WORLDTRADE_INPUT_PrintPageNumberB, WORLDTRADE_INPUT_DrawSpeciesListScreen, WORLDTRADE_INPUT_StateSpeciesListInput, WORLDTRADE_INPUT_StateSpeciesListSelected, WORLDTRADE_INPUT_StateSpeciesListClose, WORLDTRADE_INPUT_StateStartCategoryScreenAlt, WORLDTRADE_INPUT_StateCategoryInputAlt, WORLDTRADE_INPUT_StateCategorySelectedAlt, WORLDTRADE_INPUT_StateReturnToCategoryAlt, WORLDTRADE_INPUT_DrawSubCategoryScreenAlt, WORLDTRADE_INPUT_StateSubCategoryInputAlt, WORLDTRADE_INPUT_StateSubCategorySelectedAlt, WORLDTRADE_INPUT_StateRestoreCursorAlt, WORLDTRADE_INPUT_DrawConditionListScreen, WORLDTRADE_INPUT_StateConditionListInput, WORLDTRADE_INPUT_StateConditionListSelected, WORLDTRADE_INPUT_StateConditionListClose, WORLDTRADE_INPUT_StateStartThreeOptionScreen, WORLDTRADE_INPUT_StateThreeOptionInput, WORLDTRADE_INPUT_StateThreeOptionClose, WORLDTRADE_INPUT_StateStartGenderListScreen, WORLDTRADE_INPUT_StateGenderListInput, WORLDTRADE_INPUT_StateGenderListClose, WORLDTRADE_INPUT_PrintFrameString, WORLDTRADE_INPUT_PrintFrameStringAlt, WORLDTRADE_INPUT_PrintPageLabel, WORLDTRADE_INPUT_CountSpeciesInList, WORLDTRADE_INPUT_CategoryHasSpecies, WORLDTRADE_INPUT_GetListRangeCount, WORLDTRADE_INPUT_CategoryHasListEntries
 * address:  0x021F9088
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_deposit.c, worldtrade_enter.c, worldtrade_input.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   WORLDTRADE_INPUT_MenuCreate 0x021F9890 thumb ov135
 *   WORLDTRADE_INPUT_MenuDelete 0x021F99D0 thumb ov135
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   WORLDTRADE_INPUT_MenuSetMode  0x021F9968  thumb  ov135
 *   WORLDTRADE_INPUT_MenuUpdate 0x021F99F0 thumb ov135
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   ZUKAN_SAVE_IsSeen  0x0200D064  thumb  arm9
 *   WORLDTRADE_DEPOSIT_CreateGenderMenu 0x021F87E0 thumb ov135
 *   WORLDTRADE_DEPOSIT_LoadSpeciesList  0x021F8498  thumb
 *   WORLDTRADE_DEPOSIT_GetSpeciesRange  0x021F84BC  thumb
 *   WORLDTRADE_ADAPTER_StartPrintStream 0x02202878 thumb ov135
 *   WORLDTRADE_ADAPTER_StrObjThunk 0x022026C4 thumb ov135
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   tbl_022031EC   0x022031EC  data
 *   BG_SYS_Init  0x02040C14  arm
 *   data_02203200  0x02203200  data
 *   data_02203206  0x02203206  data
 *   data_0220322A  0x0220322A  data
 *   data_02203242  0x02203242  data
 *   data_022032AE  0x022032AE  data
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *   WORLDTRADE_DEPOSIT_CreateListMenu 0x021F8908 thumb ov135
 *   WORLDTRADE_DEPOSIT_GetListRange  0x021F88D8  thumb  ov135
 *   WORLDTRADE_INPUT_PrintStringAlignedWrapped  0x021F91DC  thumb
 *   WORLDTRADE_INPUT_PrintCentered  0x021F9218  thumb
 *   WORLDTRADE_INPUT_PrintStringPlain  0x021F90A0  thumb
 *   WORLDTRADE_INPUT_PrintStringTop  0x021F9088  thumb  ov135
 *   WORLDTRADE_ADAPTER_InitPrinter  0x022026D8  thumb
 *   WORLDTRADE_ADAPTER_UpdatePrinter 0x02202770 thumb ov135
 *   WORLDTRADE_ADAPTER_ExitPrinter 0x02202744 thumb ov135
 *   UI_GetInputMode  0x020355C4  arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   BGWINFRM_GetPos  0x0202CF98  thumb
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 *   BGWINFRM_Create  0x0202C9B4  thumb
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   WORLDTRADE_ADAPTER_InitMessageSystem  0x02202974  thumb
 *   g_02203CD8     0x02203CD8  data  ov135
 *   WORLDTRADE_ADAPTER_ExitMessageSystem  0x022029D4  thumb  ov135
 *   tbl_02203C48  0x02203C48  data  a4
 *   WORLDTRADE_ADAPTER_UpdateMessageSystem  0x022029F8  thumb
 *   tbl_02203370   0x02203370  data  a1
 *   tbl_022033C8   0x022033C8  data  a1
 *   tbl_022032DE   0x022032DE  data  a1
 *   tbl_02203270   0x02203270  data  a1
 *   tbl_022032FE   0x022032FE  data  a1
 *   tbl_02203284   0x02203284  data  a1
 *   UI_SetInputMode  0x020355D8  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   tbl_02203348   0x02203348  data  a1
 *   tbl_022032C6   0x022032C6  data  a1
 *   tbl_022033FC   0x022033FC  data  a4
 *   tbl_02203260   0x02203260  data  a1
 *   tbl_02203324   0x02203324  data  a4
 *   tbl_02203220   0x02203220  data  a1
 *   tbl_0220320E  0x0220320E  data
 *   tbl_02203250  0x02203250  data  a4
 *   tbl_02203216   0x02203216  data  a1
 *   tbl_0220339C   0x0220339C  data  a1
 *   tbl_02203298   0x02203298  data  a1
 *   tbl_02203236   0x02203236  data  a1
 *   BGWINFRM_SetFrameDataArc 0x0202CAE4 thumb
 *   BGWINFRM_GetFrameBuffer 0x0202CF84 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   tbl_022033F8   0x022033F8  data
 *   tbl_02203440   0x02203440  data
 *   g_022033FC  0x022033FC  data  ov135
 *   BGWINFRM_Delete  0x0202CA0C  thumb  arm9
 *   BGWINFRM_HideFrame  0x0202CC70  thumb  arm9
 *   BGWINFRM_UpdateMoves  0x0202CD94  thumb  arm9
 *   WORLDTRADE_ADAPTER_QueueMessagePrint  0x02202B20  thumb
 *   WORLDTRADE_INPUT_CreateModeWindows 0x021F9260 thumb ov135
 *   g_0220320E  0x0220320E  data  ov135
 *   g_0220320F  0x0220320F  data  ov135
 *   g_02203216  0x02203216  data  ov135
 *   g_02203217  0x02203217  data  ov135
 *   WORLDTRADE_ADAPTER_PrintNumber 0x02202A50 thumb ov135
 */
#include "worldtrade_types.h"

#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/gf_panic.h"
struct MsgBank;
struct Strbuf;

#include "../arm9/msgdata.h"

#include "../arm9/strbuf.h"
struct Actor;

#include "../arm9/clact.h"

#include "../arm9/bg_sys.h"

struct BmpWin;

#include "../arm9/bmp_win.h"
struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"



#include "../arm9/key.h"

#include "../arm9/bmp_menuwork.h"

struct WordSet;

#include "../arm9/wordset.h"

#include "worldtrade_adapter.h"
struct ZukanSave;

#include "../arm9/zukan_save.h"


#include "../arm9/gfl_use.h"

#include "../arm9/mi_memory.h"






#include "../arm9/net.h"


void WORLDTRADE_INPUT_PrintStringTop(u32 a, u32 b, u32 c, u32 d, u16 e);

void WORLDTRADE_INPUT_PrintStringPlain(u32 a, u32 b, u32 c, u32 d, u16 e);

void WORLDTRADE_INPUT_PrintBankString(WorldtradeWork *p, void *bank, u32 index, int unused1, int unused2, int slow);

int WORLDTRADE_INPUT_PrintStringAligned(void *win, void *str, int x, int align, int unused, int font, void *ctx);

void WORLDTRADE_INPUT_PrintStringAlignedLine(void *p, struct Strbuf *b, u32 c, u32 d, u32 e, u16 f, Printer *g);

void WORLDTRADE_INPUT_PrintStringAlignedWrapped(void *p, struct Strbuf *b, u32 c, u32 d, u32 e, u16 f, Printer *g);

void WORLDTRADE_INPUT_PrintCentered(void *win, void *bank, int idx, void *g);

void WORLDTRADE_ENTER_RestartNetTimeout(u8 *p);

void WORLDTRADE_INPUT_CreateModeWindows(WorldtradeMenu *p, u32 mode);

extern const u32 tbl_022031EC[];

extern const u8 data_02203200[3][2];

extern const u8 data_02203206[4][2];

extern const u8 data_0220322A[4][3];

extern const u8 data_02203242[5][2];

extern const u8 data_022032AE[9][2];

/*
 * Forward the u16 stack argument to WORLDTRADE_INPUT_PrintBankString with mode 1.
 */
void WORLDTRADE_INPUT_PrintStringTop(u32 work, u32 bank, u32 msgId, u32 unused1, u16 unused2)
{
    WORLDTRADE_INPUT_PrintBankString((WorldtradeWork *)work, (void *)bank, msgId, unused1, unused2, 1);
}

/*
 * Forward the u16 stack argument to WORLDTRADE_INPUT_PrintBankString with mode 0.
 */
void WORLDTRADE_INPUT_PrintStringPlain(u32 work, u32 bank, u32 msgId, u32 unused1, u16 unused2)
{
    WORLDTRADE_INPUT_PrintBankString((WorldtradeWork *)work, (void *)bank, msgId, unused1, unused2, 0);
}

void WORLDTRADE_INPUT_PrintBankString(WorldtradeWork *p, void *bank, u32 index, int unused1, int unused2, int slow)
{
    void *str;
    str = MSGDATA_AllocString(bank, index);
    WORDSET_CopyTaggedText(p->words, p->str, str);
    STRBUF_Delete(str);
    BMP_Clear(BMP_WIN_GetBmp(p->d40), 15);
    BMP_WIN_TransferChars(p->d40);
    BMP_MENUWORK_DrawWindow(p->d40, 0, 1, 14);
    if (slow)
        WORLDTRADE_ADAPTER_StartPrintStream(p->d40, 0, p->str, 0, 0, &p->printCtx);
    else
        WORLDTRADE_ADAPTER_QueuePrintDefaultColor(p->d40, 0, p->str, 0, 0, &p->printCtx);
    p->cnt = 0;
}

/*
 * lever: unused fifth argument leaves font and context in stack slots +4/+8.
 */
int WORLDTRADE_INPUT_PrintStringAligned(void *win, void *str, int x, int align, int unused, int font, void *ctx)
{
    int width;
    switch (align) {
    case 1:
        width = WORLDTRADE_ADAPTER_StrObjThunk(ctx, (u8)font, str, (int)0);
        x = (BMP_WIN_GetWidth(win) * 8 - width) / 2;
        break;
    case 2:
        width = WORLDTRADE_ADAPTER_StrObjThunk(ctx, (u8)font, str, (int)0);
        x = BMP_WIN_GetWidth(win) * 8 - width;
        break;
    }
    return x;
}

/*
 * Seven-argument wrapper: forwards the object, three words, the 0 and the u16/g pair to the two helpers.
 */
void WORLDTRADE_INPUT_PrintStringAlignedLine(void *win, struct Strbuf *str, u32 x, u32 y, u32 align, u16 color, Printer *printer)
{
    u32 r = WORLDTRADE_INPUT_PrintStringAligned(win, (void *)str, x, align, color, 0, (void *)printer);

    WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, r, y, 0, color, printer);
}

void WORLDTRADE_INPUT_PrintStringAlignedWrapped(void *win, struct Strbuf *str, u32 x, u32 y, u32 align, u16 color, Printer *printer)
{
    u32 r = WORLDTRADE_INPUT_PrintStringAligned(win, (void *)str, x, align, color, 0, (void *)printer);

    WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, r, y, 0, color, printer);
}

void WORLDTRADE_INPUT_PrintCentered(void *win, void *bank, int idx, void *printer)
{
    void *str;

    str = MSGDATA_AllocString(bank, tbl_022031EC[idx]);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, 0, 0, 0, 0x440, printer);
    STRBUF_Delete(str);
}

/*
 * Tail call into GFL_NET_RefreshWmIconAtTopRight with the fixed 0/0x48 pair.
 */
void WORLDTRADE_ENTER_RestartNetTimeout(u8 *p)
{
    GFL_NET_RefreshWmIconAtTopRight(0, 0x48);
}

void WORLDTRADE_INPUT_CreateModeWindows(WorldtradeMenu *p, u32 mode)
{
    int i;

    BG_SYS_Init(p->layer, 0, 1, 0);
    switch (mode) {
    case 4:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[14])), 10);
        for (i = 0; i < 9; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[i])), 10);
        }
        break;
    case 5:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[14])), 10);
        p->wins[0] = (void *)BMP_WIN_Create((u8)p->layer, 2, 2, 3, 2, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[0])), 7);
        for (i = 1; i < 4; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_022032AE[i - 1][0], data_022032AE[i - 1][1], 2, 2, 1, 1);
            BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[i])), 10);
        }
        break;
    case 0:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[14])), 10);
        for (i = 0; i < 4; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_0220322A[i][0], data_0220322A[i][1], 8, 2, 1, 1);
            BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[i])), 10);
        }
        p->wins[4] = (void *)BMP_WIN_Create((u8)p->layer, 5, 14, 5, 1, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[4])), 8);
        break;
    case 6:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[14])), 10);
        for (i = 0; i < 9; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[i])), 10);
        }
        p->wins[15] = (void *)BMP_WIN_Create((u8)p->layer, 1, 2, 9, 2, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[15])), 10);
        break;
    case 3:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 24, 17, 6, 2, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[14])), 10);
        for (i = 0; i < 5; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_02203242[i][0], data_02203242[i][1], 23, 2, 1, 1);
            BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[i])), 10);
        }
        p->wins[5] = (void *)BMP_WIN_Create((u8)p->layer, 14, 16, 5, 1, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[5])), 10);
        break;
    case 1:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[14])), 10);
        for (i = 0; i < 3; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_02203200[i][0], data_02203200[i][1], 9, 2, 1, 1);
            BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[i])), 10);
        }
        break;
    case 2:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[14])), 10);
        for (i = 0; i < 4; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_02203206[i][0], data_02203206[i][1], 11, 2, 1, 1);
            BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[i])), 10);
        }
        p->wins[4] = (void *)BMP_WIN_Create((u8)p->layer, 5, 14, 5, 1, 1, 1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->wins[4])), 8);
        break;
    }
}



typedef struct {
    u8 up;
    u8 down;
    u8 left;
    u8 right;
} Link;

typedef struct {
    int count;
    int reserved04;
} Layout;



#include "../arm9/ui.h"


struct BgWinFrmWork;

#include "../arm9/bgwinfrm.h"


struct BgWinFrmWork;



#include "worldtrade.h"








#include "../arm9/touchpanel.h"








#include "worldtrade_deposit.h"











void WORLDTRADE_INPUT_MenuFinish(WorldtradeMenu *p, int mode);

InputMenu *WORLDTRADE_INPUT_MenuCreate(WorldtradeInputInit *init, u32 a, u32 b);

void WORLDTRADE_INPUT_MenuSetMode(WorldtradeMenu *p, int mode);

void WORLDTRADE_INPUT_MenuDelete(WorldtradeMenu *p);

int WORLDTRADE_INPUT_MenuUpdate(WorldtradeMenu *p);

int WORLDTRADE_INPUT_CheckTouch(WorldtradeMenu *p, int mode);

int WORLDTRADE_INPUT_UpdateCategoryGrid(WorldtradeMenu *p, u8 *enable);

int WORLDTRADE_INPUT_ClampPageChoice(WorldtradeMenu *p, int v);

int WORLDTRADE_INPUT_UpdateButtonRow(WorldtradeMenu *p, int base);

int WORLDTRADE_INPUT_GetPageCount(int total, int perPage);

int WORLDTRADE_INPUT_HandlePagedKey4(WorldtradeMenu *m, int key);

void WORLDTRADE_INPUT_ScrollPage4(WorldtradeMenu *m, int dir);

int WORLDTRADE_INPUT_UpdatePagedList4(WorldtradeMenu *m);

int WORLDTRADE_INPUT_UpdateThreeOptionMenu(WorldtradeMenu *p);

void WORLDTRADE_INPUT_ScrollPage4Alt(WorldtradeMenu *m, int dir);

int WORLDTRADE_INPUT_HandlePagedKey4Alt(WorldtradeMenu *m, int key);

int WORLDTRADE_INPUT_UpdatePagedList4Alt(WorldtradeMenu *m);

int WORLDTRADE_INPUT_MapModeToLabel(int unused, int mode);

int WORLDTRADE_INPUT_UpdateCategoryGridAlt(WorldtradeMenu *p, u8 *enable);

int WORLDTRADE_INPUT_HandlePagedKey5(WorldtradeMenu *m, int key);

void WORLDTRADE_INPUT_ScrollPage5(WorldtradeMenu *m, int dir);

int WORLDTRADE_INPUT_UpdatePagedList5(WorldtradeMenu *m);

void WORLDTRADE_INPUT_DrawFrame(WorldtradeMenu *p, int mode, int pos);

void WORLDTRADE_INPUT_DrawThreeOptionScreen(WorldtradeMenu *p);

void WORLDTRADE_INPUT_DrawGenderListScreen(WorldtradeMenu *p);

void WORLDTRADE_INPUT_PutBmpWinString(void *mgr, void *win, void *str, u32 x, u16 color, void *g);

int WORLDTRADE_INPUT_StateNone(void);

int WORLDTRADE_INPUT_StateWaitFrameIn(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateWaitFrameMove(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateStartFrameOutSlow(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateWaitFrameHide(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateStartFrameOut(WorldtradeMenu *p);

void WORLDTRADE_INPUT_StateStartCategoryScreen(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateCategoryInput(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateCategorySelected(WorldtradeMenu *p);

int WORLDTRADE_INPUT_DrawCategoryScreen(WorldtradeMenu *p);

int WORLDTRADE_INPUT_DrawSubCategoryScreen(WorldtradeMenu *m);

int WORLDTRADE_INPUT_StateSubCategoryInput(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateSubCategorySelected(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateRestoreCursor(WorldtradeMenu *p);

int WORLDTRADE_INPUT_CountSeenSpecies(u32 unused, u32 item, u32 c, u16 *list, int start, int end);

int WORLDTRADE_INPUT_CreateSpeciesMenu(BmpMenuWork **menu, void *msg, void *bank, u32 x, u32 kind, void *bag);

void WORLDTRADE_INPUT_PrintPageNumberA(WorldtradeMenu *m, int page, int total);

void WORLDTRADE_INPUT_PrintPageNumberB(WorldtradeMenu *m, int page, int total);

int WORLDTRADE_INPUT_DrawSpeciesListScreen(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateSpeciesListInput(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateSpeciesListSelected(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateSpeciesListClose(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateStartCategoryScreenAlt(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateCategoryInputAlt(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateCategorySelectedAlt(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateReturnToCategoryAlt(WorldtradeMenu *p);

int WORLDTRADE_INPUT_DrawSubCategoryScreenAlt(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateSubCategoryInputAlt(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateSubCategorySelectedAlt(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateRestoreCursorAlt(WorldtradeMenu *p);

int WORLDTRADE_INPUT_DrawConditionListScreen(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateConditionListInput(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateConditionListSelected(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateConditionListClose(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateStartThreeOptionScreen(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateThreeOptionInput(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateThreeOptionClose(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateStartGenderListScreen(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateGenderListInput(WorldtradeMenu *p);

int WORLDTRADE_INPUT_StateGenderListClose(WorldtradeMenu *p);

void WORLDTRADE_INPUT_PrintFrameString(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);

void WORLDTRADE_INPUT_PrintFrameStringAlt(void *mgr, void *bank, void *win, u32 index, void *g);

void WORLDTRADE_INPUT_PrintPageLabel(void *mgr, void *ctx, void *win, int page, u32 pages);

int WORLDTRADE_INPUT_CountSpeciesInList(WorldtradeMenu *m, u32 idx);

int WORLDTRADE_INPUT_CategoryHasSpecies(void *p, int idx);

int WORLDTRADE_INPUT_GetListRangeCount(void *p, u32 a);

int WORLDTRADE_INPUT_CategoryHasListEntries(void *p, int idx);

extern u8 g_02203CD8[];

extern u8 tbl_02203370[];

extern u8 tbl_022033C8[];

extern u8 tbl_022032DE[];

extern u8 tbl_02203270[];

extern u8 tbl_022032FE[];

extern u8 tbl_02203284[];

extern const Link tbl_02203348[];

extern const WorldtradeCell tbl_022032C6[];

extern const Layout tbl_022033FC[];

extern const Link tbl_02203260[];

extern u8 *const tbl_02203324[];

extern const CurPos tbl_02203220[];

extern const WorldtradeCell tbl_0220320E[];

extern const int tbl_02203250[];

extern const CurPos tbl_02203216[];

extern const Link tbl_0220339C[];

extern const WorldtradeCell tbl_02203298[];

extern const CurPos tbl_02203236[];

extern const Range tbl_022033F8[];

extern const u32 tbl_02203440[];

extern u8 g_022033FC[];

extern u8 g_0220320E[];

extern u8 g_0220320F[];

extern u8 g_02203216[];

extern u8 g_02203217[];

/*
 * Redraw the text windows of layout `mode` (0..6): clear and refresh the
 * first n windows of the window table, and when the second brightness
 * byte read by BGWINFRM_GetPos is 0x10 reset the two BG2 screen blocks
 * (BG_SYS_SetTileEntry) and commit them; then refresh window 14 (and 15 for
 * layout 6) and schedule the +0x50 screen.
 */
void WORLDTRADE_INPUT_MenuFinish(WorldtradeMenu *p, int mode)
{
    s8 bright[2];
    int i = 0;

    BGWINFRM_GetPos(p->mgr, 0, &bright[1], &bright[0]);
    switch (mode) {
    case 4:
        for (i = 0; i < 9; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->wins[i]), 10);
            BMP_WIN_TransferChars(p->wins[i]);
            BMP_WIN_Delete(p->wins[i]);
        }
        if (bright[1] == 0x10) {
            BG_SYS_SetTileEntry(2, 5, 0x10, 1, 1, 0xF, 0x10);
            BG_SYS_SetTileEntry(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            BG_SYS_PushTile(2);
        }
        BMP_WIN_Delete(p->wins[14]);
        break;
    case 5:
        for (i = 0; i < 4; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->wins[i]), 10);
            BMP_WIN_TransferChars(p->wins[i]);
            BMP_WIN_Delete(p->wins[i]);
        }
        if (bright[1] == 0x10) {
            BG_SYS_SetTileEntry(2, 5, 0x10, 1, 1, 0xF, 0x10);
            BG_SYS_SetTileEntry(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            BG_SYS_PushTile(2);
        }
        BMP_WIN_Delete(p->wins[14]);
        break;
    case 0:
        for (i = 0; i < 5; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->wins[i]), 10);
            BMP_WIN_TransferChars(p->wins[i]);
            BMP_WIN_Delete(p->wins[i]);
        }
        if (bright[1] == 0x10) {
            BG_SYS_SetTileEntry(2, 5, 0x10, 1, 1, 0xF, 0x10);
            BG_SYS_SetTileEntry(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            BG_SYS_PushTile(2);
        }
        BMP_WIN_Delete(p->wins[14]);
        break;
    case 6:
        for (i = 0; i < 9; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->wins[i]), 10);
            BMP_WIN_TransferChars(p->wins[i]);
            BMP_WIN_Delete(p->wins[i]);
        }
        if (bright[1] == 0x10) {
            BG_SYS_SetTileEntry(2, 5, 0x10, 1, 1, 0xF, 0x10);
            BG_SYS_SetTileEntry(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            BG_SYS_PushTile(2);
        }
        BMP_WIN_Delete(p->wins[14]);
        BMP_WIN_Delete(p->wins[15]);
        break;
    case 3:
        for (i = 0; i < 6; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->wins[i]), 10);
            BMP_WIN_TransferChars(p->wins[i]);
            BMP_WIN_Delete(p->wins[i]);
        }
        BMP_WIN_Delete(p->wins[14]);
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            BMP_WIN_Delete(p->wins[i]);
        }
        BMP_WIN_Delete(p->wins[14]);
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            BMP_WIN_Delete(p->wins[i]);
        }
        BMP_WIN_Delete(p->wins[14]);
        break;
    }
    BG_SYS_FreeTiles(p->layer, 1, 0);
}

InputMenu *WORLDTRADE_INPUT_MenuCreate(WorldtradeInputInit *init, u32 layer, u32 listKind)
{
    InputMenu *m;

    m = GFL_HEAP_Alloc(0x48, 0x1b8, 0, (const char *)g_02203CD8, 0x336);
    m->w00 = init->w00;
    m->w04 = init->w04;
    m->obj = init->obj;
    m->w0c = init->w0c;
    m->w10 = init->w10;
    m->w14 = init->w14;
    m->w18 = init->w18;
    m->w1c = init->w1c;
    m->w20 = init->w20;
    m->w24 = init->w24;
    m->w28 = init->w28;
    m->a = layer;
    m->b = listKind;
    m->h38 = 0;
    m->h3a = 0;
    m->h3c = 0;
    m->h3e = 0;
    m->b40 = 0;
    m->b41 = 0;
    m->w44 = 0;
    m->b7a = 0;
    m->w48 = 0;
    m->frm = BGWINFRM_Create(2, 1, 0x48);
    BGWINFRM_AddFrame(m->frm, 0, 2, 0x20, 0x14);
    WORLDTRADE_SetActorPos(m->obj, 0x90, 0x28);
    CLACT_SetActorAnimSeq((struct ClactActor *)m->obj, 4);
    CLACT_SetActorAutoAnim((struct ClactActor *)m->obj, 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)m->obj, 0);
    m->ctx = WORLDTRADE_ADAPTER_InitMessageSystem(0xf, 0xe, 2, 0x48);
    WORLDTRADE_ADAPTER_InitPrinter((Printer *)m->sub, init->arg);
    return m;
}

/*
 * trailing: two-byte zero alignment padding at 0x021F99CE.
 */
void WORLDTRADE_INPUT_MenuSetMode(WorldtradeMenu *p, int mode)
{
    p->mode = mode;
    switch (mode) {
    case 0:
        ((u8 *)p)[122] = 0;
        p->pos = 0;
        p->layout = 0;
        p->start = 0;
        p->state = 6;
        return;
    case 3:
        ((u8 *)p)[122] = 0;
        p->pos = 0;
        p->layout = 0;
        p->start = 0;
        p->state = 18;
        return;
    case 1:
        ((u8 *)p)[122] = 0;
        p->pos = 0;
        p->state = 30;
        return;
    case 2:
        ((u8 *)p)[122] = 0;
        p->pos = 0;
        p->state = 33;
        break;
    }
}

/*
 * Tear the object down: sub-object at +0x7c, buffer at +0x34, then the object.
 */
void WORLDTRADE_INPUT_MenuDelete(WorldtradeMenu *p)
{
    WORLDTRADE_ADAPTER_ExitPrinter((Printer *)((u8 *)p + 0x7c));
    WORLDTRADE_ADAPTER_ExitMessageSystem(p->num);
    BGWINFRM_Delete((struct BgWinFrmWork *)(*(struct WinMgr * *)&p->mgr));
    GFL_HEAP_Free((void *)((uptr)p));
}

extern int (*const tbl_02203C48[])(WorldtradeMenu *p);

int WORLDTRADE_INPUT_MenuUpdate(WorldtradeMenu *p)
{
    int r = tbl_02203C48[p->state](p);

    BGWINFRM_UpdateMoves(p->mgr);
    WORLDTRADE_ADAPTER_UpdatePrinter((Printer *)p->g);
    WORLDTRADE_ADAPTER_UpdateMessageSystem(p->num);
    return r;
}

/*
 * Touch hit test against the rectangle table of screen mode `mode`
 * (0..7; modes 0/2 and 5/7 share a table). Any other mode hands back the
 * first argument, which r0 still holds.
 */
int WORLDTRADE_INPUT_CheckTouch(WorldtradeMenu *p, int mode)
{
    switch (mode) {
    case 4:
        return TOUCHPANEL_HitTrg((const TouchHitTable *)tbl_02203370);
    case 6:
        return TOUCHPANEL_HitTrg((const TouchHitTable *)tbl_022033C8);
    case 0:
    case 2:
        return TOUCHPANEL_HitTrg((const TouchHitTable *)tbl_022032DE);
    case 1:
        return TOUCHPANEL_HitTrg((const TouchHitTable *)tbl_02203270);
    case 3:
        return TOUCHPANEL_HitTrg((const TouchHitTable *)tbl_022032FE);
    case 5:
    case 7:
        return TOUCHPANEL_HitTrg((const TouchHitTable *)tbl_02203284);
    }
    return (sptr)p;
}

/*
 * Cursor input for the ten-entry mode-4 menu: the mode-6 grid of nine
 * entries with one button (9). Returns the entry, -2 for cancel (B or
 * the button), -1 for nothing or an entry `enable` marks off. A grid
 * position past 9 under A reports through GF_PANIC_Fail (raw address
 * 0x02203CEC, a plain constant as in WORLDTRADE_ADAPTER_QueueMessagePrint).
 */
int WORLDTRADE_INPUT_UpdateCategoryGrid(WorldtradeMenu *p, u8 *enable)
{
    int old = p->pos;
    int r;
    int ret;

    if (old < 9) {
        p->last = old;
    }
    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        p->pos = tbl_02203348[p->pos].up;
    } else if (KEY_GetRepeat() & 0x80) {
        p->pos = tbl_02203348[p->pos].down;
    } else if (KEY_GetRepeat() & 0x20) {
        p->pos = tbl_02203348[p->pos].left;
    } else if (KEY_GetRepeat() & 0x10) {
        p->pos = tbl_02203348[p->pos].right;
    }
    if (old >= 9 && p->pos < 9) {
        if (KEY_GetRepeat() & 0x40) {
            p->pos = p->last;
            while (p->pos + 3 < 9) {
                p->pos += 3;
            }
        } else if (KEY_GetRepeat() & 0x80) {
            p->pos = p->last;
            while (p->pos - 3 >= 0) {
                p->pos -= 3;
            }
        }
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
        if (p->pos == 9) {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 0x12);
        }
    }
    ret = -1;
    r = WORLDTRADE_INPUT_CheckTouch(p, 4);
    if (r != ret) {
        WORLDTRADE_SetActorPos(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
        if (r == 9) {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        } else {
            p->pos = r;
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 0x12);
        }
        if (r == 9) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            ret = -2;
        } else if (enable == 0 || enable[r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            ret = r;
        }
        if (ret == -1 && UI_GetInputMode() == 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 0);
        }
        UI_SetInputMode(1);
        return ret;
    }
    if (KEY_GetTrg() & 1) {
        if (p->pos == 9) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            return -2;
        }
        if (p->pos >= 9) {
            GF_PANIC_Fail((void *)0x02203CEC, 0, (void *)0x02203CEC);
        }
        if (enable == 0 || enable[p->pos] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return p->pos;
        }
    } else if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        WORLDTRADE_SetActorPos(p->cursor, 0xC0, 0x88);
        return -2;
    }
    return -1;
}

/*
 * Validate a touched entry index: 3 maps to -2; for layouts 0..8 (+0x38)
 * an index at or past the layout's entry count (first word of its 8-byte
 * row) maps to -1; anything else is returned unchanged.
 */
int WORLDTRADE_INPUT_ClampPageChoice(WorldtradeMenu *p, int choice)
{
    if (choice != 3) {
        if (p->layout <= 8) {
            if (choice >= tbl_022033FC[p->layout].count) {
                choice = -1;
            }
            return choice;
        }
        return choice;
    }
    return -2;
}

/*
 * Cursor input for the five-entry mode-5 menu: the d-pad walks the link
 * table (entry 3 is the fixed bottom button, leaving it restores the last
 * grid entry from +0x7A), a touch (WORLDTRADE_INPUT_CheckTouch) or A selects. Returns
 * the selected entry, -2 for cancel (B or the button), -1 for nothing or
 * for an entry the per-layout enable row marks unavailable at `base`.
 */
int WORLDTRADE_INPUT_UpdateButtonRow(WorldtradeMenu *p, int base)
{
    int old = p->pos;
    int r;

    if (old < 3) {
        p->last = old;
    }
    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        p->pos = tbl_02203260[p->pos].up;
    } else if (KEY_GetRepeat() & 0x80) {
        p->pos = tbl_02203260[p->pos].down;
    } else if (KEY_GetRepeat() & 0x20) {
        p->pos = tbl_02203260[p->pos].left;
    } else if (KEY_GetRepeat() & 0x10) {
        p->pos = tbl_02203260[p->pos].right;
    }
    if (old == 3 && p->pos < 3) {
        p->pos = p->last;
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (p->pos == 3) {
            WORLDTRADE_SetActorPos(p->cursor, 0xC0, 0x88);
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        } else {
            WORLDTRADE_SetActorPos(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 4);
        }
    }
    r = WORLDTRADE_INPUT_CheckTouch(p, 5);
    if (r != -1) {
        if (r == 3) {
            WORLDTRADE_SetActorPos(p->cursor, 0xC0, 0x88);
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        } else {
            p->pos = r;
            WORLDTRADE_SetActorPos(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 4);
        }
        r = WORLDTRADE_INPUT_ClampPageChoice((WorldtradeMenu *)p, r);
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else if (base == 0 || tbl_02203324[p->layout][base + r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else {
            r = -1;
            if (UI_GetInputMode() == 0) {
                CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 0);
            }
        }
        UI_SetInputMode(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        r = WORLDTRADE_INPUT_ClampPageChoice((WorldtradeMenu *)p, p->pos);
        if (r == -1) {
            return r;
        }
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            return r;
        }
        if (base == 0 || tbl_02203324[p->layout][base + r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return r;
        }
    } else if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        WORLDTRADE_SetActorPos(p->cursor, 0xC0, 0x88);
        return -2;
    }
    return -1;
}

/*
 * Number of pages needed for total entries, at least 1.
 */
int WORLDTRADE_INPUT_GetPageCount(int total, int perPage)
{
    int last;

    if (total == 0) {
        return 1;
    }
    last = perPage - 1;
    return (total + last) / perPage;
}

int WORLDTRADE_INPUT_HandlePagedKey4(WorldtradeMenu *menu, int key)
{
    int idx;

    switch (key) {
    case 4:
        return -2;
    case 5:
        WORLDTRADE_INPUT_ScrollPage4((WorldtradeMenu *)menu, -1);
        return -1;
    case 6:
        WORLDTRADE_INPUT_ScrollPage4((WorldtradeMenu *)menu, 1);
        return -1;
    }
    idx = key + menu->page * 4;
    if (idx < menu->total) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return menu->items[idx].value;
    }
    return -1;
}

void WORLDTRADE_INPUT_ScrollPage4(WorldtradeMenu *menu, int dir)
{
    int last;

    last = WORLDTRADE_INPUT_GetPageCount(menu->total, 4) - 1;
    if (last == 0) {
        return;
    }
    if (dir < 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->down)), 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->down)), 0x27);
        if (menu->page != 0) {
            menu->page = menu->page - 1;
        } else {
            menu->page = last;
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->up)), 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->up)), 0x26);
        if (menu->page < last) {
            menu->page = menu->page + 1;
        } else {
            menu->page = 0;
        }
    }
    WORLDTRADE_INPUT_PrintPageNumberA((WorldtradeMenu *)menu, menu->page, menu->total);
    WORLDTRADE_INPUT_PrintPageLabel(menu->mgr, menu->num, menu->wins[4], menu->page, WORLDTRADE_INPUT_GetPageCount(menu->total, 4));
}

int WORLDTRADE_INPUT_UpdatePagedList4(WorldtradeMenu *menu)
{
    int old;
    int r;

    old = menu->pos;
    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        if (menu->pos != 0) {
            menu->pos = menu->pos - 1;
        } else {
            menu->pos = 4;
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (menu->pos != 4) {
            menu->pos = menu->pos + 1;
        } else {
            menu->pos = 0;
        }
    } else if (KEY_GetRepeat() & 0x20) {
        WORLDTRADE_INPUT_ScrollPage4((WorldtradeMenu *)menu, -1);
    } else if (KEY_GetRepeat() & 0x10) {
        WORLDTRADE_INPUT_ScrollPage4((WorldtradeMenu *)menu, 1);
    }
    if (old != menu->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos(menu->cursor, tbl_02203220[menu->pos].x, tbl_02203220[menu->pos].y);
        if (menu->pos == 4) {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 5);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 6);
        }
    }
    r = WORLDTRADE_INPUT_CheckTouch(menu, 0);
    if (r != -1) {
        if ((u32)r < 5) {
            WORLDTRADE_SetActorPos(menu->cursor, tbl_02203220[r].x, tbl_02203220[r].y);
            if (r == 4) {
                CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 5);
            } else {
                menu->pos = r;
                CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 6);
            }
        }
        r = WORLDTRADE_INPUT_HandlePagedKey4((WorldtradeMenu *)menu, r);
        if (r == -1 && UI_GetInputMode() == 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 0);
        }
        UI_SetInputMode(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        return WORLDTRADE_INPUT_HandlePagedKey4((WorldtradeMenu *)menu, menu->pos);
    }
    if (KEY_GetTrg() & 2) {
        WORLDTRADE_SetActorPos(menu->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    }
    return -1;
}

int WORLDTRADE_INPUT_UpdateThreeOptionMenu(WorldtradeMenu *p)
{
    int old = p->pos;
    int r;

    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        if (p->pos != 0) {
            p->pos = p->pos - 1;
        } else {
            p->pos = 3;
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (p->pos != 3) {
            p->pos = p->pos + 1;
        } else {
            p->pos = 0;
        }
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos(p->cursor, tbl_0220320E[p->pos].x, tbl_0220320E[p->pos].y);
        if (p->pos == 3) {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 6);
        }
    }
    r = WORLDTRADE_INPUT_CheckTouch(p, 1);
    if (r != -1) {
        UI_SetInputMode(1);
        WORLDTRADE_SetActorPos(p->cursor, tbl_0220320E[r].x, tbl_0220320E[r].y);
        if (r == 3) {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 6);
        }
        r = tbl_02203250[r];
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        }
        return r;
    }
    if (KEY_GetTrg() & 1) {
        if (tbl_02203250[p->pos] == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        }
        return tbl_02203250[p->pos];
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        WORLDTRADE_SetActorPos(p->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        return -2;
    }
    return -1;
}

void WORLDTRADE_INPUT_ScrollPage4Alt(WorldtradeMenu *menu, int dir)
{
    if (dir < 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->down)), 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->down)), 0x27);
        if (menu->page != 0) {
            menu->page = menu->page - 1;
        } else {
            menu->page = 2;
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->up)), 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->up)), 0x26);
        if (menu->page < 2) {
            menu->page = menu->page + 1;
        } else {
            menu->page = 0;
        }
    }
    WORLDTRADE_INPUT_PrintPageNumberA((WorldtradeMenu *)menu, menu->page, menu->total);
    WORLDTRADE_INPUT_PrintPageLabel(menu->mgr, menu->num, menu->wins[4], menu->page, WORLDTRADE_INPUT_GetPageCount(menu->total, 4));
}

int WORLDTRADE_INPUT_HandlePagedKey4Alt(WorldtradeMenu *menu, int key)
{
    int idx;

    switch (key) {
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    case 5:
        WORLDTRADE_INPUT_ScrollPage4Alt((WorldtradeMenu *)menu, -1);
        return -1;
    case 6:
        WORLDTRADE_INPUT_ScrollPage4Alt((WorldtradeMenu *)menu, 1);
        return -1;
    }
    idx = key + menu->page * 4;
    if (idx < menu->total) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return menu->items[key].value;
    }
    return -1;
}

int WORLDTRADE_INPUT_UpdatePagedList4Alt(WorldtradeMenu *menu)
{
    int old;
    int r;

    old = menu->pos;
    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        if (menu->pos != 0) {
            menu->pos = menu->pos - 1;
        } else {
            menu->pos = 4;
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (menu->pos != 4) {
            menu->pos = menu->pos + 1;
        } else {
            menu->pos = 0;
        }
    } else if (KEY_GetRepeat() & 0x20) {
        WORLDTRADE_INPUT_ScrollPage4Alt((WorldtradeMenu *)menu, -1);
    } else if (KEY_GetRepeat() & 0x10) {
        WORLDTRADE_INPUT_ScrollPage4Alt((WorldtradeMenu *)menu, 1);
    }
    if (old != menu->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos(menu->cursor, tbl_02203216[menu->pos].x, tbl_02203216[menu->pos].y);
        if (menu->pos == 4) {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 5);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 6);
        }
    }
    r = WORLDTRADE_INPUT_CheckTouch(menu, 2);
    if (r != -1) {
        if ((u32)r < 5) {
            WORLDTRADE_SetActorPos(menu->cursor, tbl_02203216[r].x, tbl_02203216[r].y);
            if (r == 4) {
                CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 5);
            } else {
                menu->pos = r;
                CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 6);
            }
        }
        r = WORLDTRADE_INPUT_HandlePagedKey4Alt((WorldtradeMenu *)menu, r);
        if (r == -1 && UI_GetInputMode() == 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 0);
        }
        UI_SetInputMode(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        return WORLDTRADE_INPUT_HandlePagedKey4Alt((WorldtradeMenu *)menu, menu->pos);
    }
    if (KEY_GetTrg() & 2) {
        WORLDTRADE_SetActorPos(menu->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)menu->cursor)), 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    }
    return -1;
}

/*
 * Map a mode value: 9 and 10 have fixed answers, everything else passes through.
 */
int WORLDTRADE_INPUT_MapModeToLabel(int unused, int mode)
{
    switch (mode) {
    case 9:
        return ~1;
    case 10:
        return 10;
    default:
        return mode;
    }
}

/*
 * Cursor input for the eleven-entry mode-6 menu: a 3-column grid of nine
 * entries plus two buttons (9, 10). Leaving a button with up or down
 * returns to the last grid entry (+0x7A) moved to the bottom or top row.
 * A touch (WORLDTRADE_INPUT_CheckTouch) or A selects. Returns the entry, -2 for cancel
 * (B or entry 9), -1 for nothing or a grid entry `enable` marks off.
 */
int WORLDTRADE_INPUT_UpdateCategoryGridAlt(WorldtradeMenu *p, u8 *enable)
{
    int old = p->pos;
    int r;

    if (old < 9) {
        p->last = old;
    }
    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        p->pos = tbl_0220339C[p->pos].up;
    } else if (KEY_GetRepeat() & 0x80) {
        p->pos = tbl_0220339C[p->pos].down;
    } else if (KEY_GetRepeat() & 0x20) {
        p->pos = tbl_0220339C[p->pos].left;
    } else if (KEY_GetRepeat() & 0x10) {
        p->pos = tbl_0220339C[p->pos].right;
    }
    if (old >= 9 && p->pos < 9) {
        if (KEY_GetRepeat() & 0x40) {
            p->pos = p->last;
            while (p->pos + 3 < 9) {
                p->pos += 3;
            }
        } else if (KEY_GetRepeat() & 0x80) {
            p->pos = p->last;
            while (p->pos - 3 >= 0) {
                p->pos -= 3;
            }
        }
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos(p->cursor, (tbl_02203298[p->pos].x + 0x10) * 8, tbl_02203298[p->pos].y * 8);
        switch (p->pos) {
        case 9:
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
            break;
        case 10:
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 6);
            break;
        default:
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 0x12);
            break;
        }
    }
    r = WORLDTRADE_INPUT_CheckTouch(p, 6);
    if (r != -1) {
        WORLDTRADE_SetActorPos(p->cursor, (tbl_02203298[r].x + 0x10) * 8, tbl_02203298[r].y * 8);
        switch (r) {
        case 9:
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
            break;
        case 10:
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 6);
            break;
        default:
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 0x12);
            p->pos = r;
            break;
        }
        r = WORLDTRADE_INPUT_MapModeToLabel((sptr)p, r);
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else if (r == 10 || enable == 0 || enable[r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else {
            r = -1;
        }
        if (r == -1 && UI_GetInputMode() == 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 0);
        }
        UI_SetInputMode(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        r = WORLDTRADE_INPUT_MapModeToLabel((sptr)p, p->pos);
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            return r;
        }
        if (r == 10 || enable == 0 || enable[r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return r;
        }
    } else if (KEY_GetTrg() & 2) {
        WORLDTRADE_SetActorPos(p->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    }
    return -1;
}

int WORLDTRADE_INPUT_HandlePagedKey5(WorldtradeMenu *menu, int key)
{
    int idx;

    switch (key) {
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    case 6:
        WORLDTRADE_INPUT_ScrollPage5(menu, -1);
        return -1;
    case 7:
        WORLDTRADE_INPUT_ScrollPage5(menu, 1);
        return -1;
    }
    idx = key + menu->page * 5;
    if (idx < menu->total) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return menu->items[idx].value;
    }
    return -1;
}

void WORLDTRADE_INPUT_ScrollPage5(WorldtradeMenu *menu, int dir)
{
    int last;

    last = WORLDTRADE_INPUT_GetPageCount(menu->total, 5) - 1;
    if (last == 0) {
        return;
    }
    if (dir < 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct ClactActor *)menu->down, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)menu->down, 0x27);
        if (menu->page != 0) {
            menu->page = menu->page - 1;
        } else {
            menu->page = last;
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct ClactActor *)menu->up, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)menu->up, 0x26);
        if (menu->page < last) {
            menu->page = menu->page + 1;
        } else {
            menu->page = 0;
        }
    }
    WORLDTRADE_INPUT_PrintPageNumberB((WorldtradeMenu *)menu, menu->page, menu->total);
    WORLDTRADE_INPUT_PrintPageLabel(menu->mgr, menu->num, menu->wins[5], menu->page, WORLDTRADE_INPUT_GetPageCount(menu->total, 5));
}

int WORLDTRADE_INPUT_UpdatePagedList5(WorldtradeMenu *menu)
{
    int old;
    int r;

    old = menu->pos;
    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->cursor, 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        if (menu->pos != 0) {
            menu->pos = menu->pos - 1;
        } else {
            menu->pos = 5;
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (menu->pos != 5) {
            menu->pos = menu->pos + 1;
        } else {
            menu->pos = 0;
        }
    } else if (KEY_GetRepeat() & 0x20) {
        WORLDTRADE_INPUT_ScrollPage5((WorldtradeMenu *)menu, -1);
    } else if (KEY_GetRepeat() & 0x10) {
        WORLDTRADE_INPUT_ScrollPage5((WorldtradeMenu *)menu, 1);
    }
    if (old != menu->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos(menu->cursor, tbl_02203236[menu->pos].x, tbl_02203236[menu->pos].y);
        if (menu->pos == 5) {
            CLACT_SetActorAnimSeq((struct ClactActor *)menu->cursor, 5);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)menu->cursor, 7);
        }
    }
    r = WORLDTRADE_INPUT_CheckTouch(menu, 3);
    if (r != -1) {
        if ((u32)r < 6) {
            WORLDTRADE_SetActorPos(menu->cursor, tbl_02203236[r].x, tbl_02203236[r].y);
            if (r == 5) {
                CLACT_SetActorAnimSeq((struct ClactActor *)menu->cursor, 5);
            } else {
                menu->pos = r;
                CLACT_SetActorAnimSeq((struct ClactActor *)menu->cursor, 7);
            }
        }
        r = WORLDTRADE_INPUT_HandlePagedKey5((WorldtradeMenu *)menu, r);
        if (r == -1 && UI_GetInputMode() == 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)menu->cursor, 0);
        }
        UI_SetInputMode(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        return WORLDTRADE_INPUT_HandlePagedKey5((WorldtradeMenu *)menu, menu->pos);
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        WORLDTRADE_SetActorPos(menu->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct ClactActor *)menu->cursor, 5);
        return -2;
    }
    return -1;
}

void WORLDTRADE_INPUT_DrawFrame(WorldtradeMenu *p, int mode, int pos)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    BGWINFRM_SetFrameDataArc(p->mgr, 0, 96, mode == 6 ? 27 : 28, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    WORLDTRADE_INPUT_CreateModeWindows(p, mode);
    WORLDTRADE_INPUT_PrintFrameStringAlt(p->mgr, p->bank, (*(void ***)p)[14], 74, (u8 *)p + 124);
    MI_CpuFill8((u8 *)p + 96, 1, 26);
    g = (u8 *)p;
    g += 124;
    for (i = 0; i < 9; i++) {
        str = MSGDATA_AllocString(p->bank, i + 116);
        if (mode == 4) {
            if (WORLDTRADE_INPUT_CategoryHasSpecies(p, i) == 1) {
                color = 0x3dc2;
                ((u8 *)p)[i + 96] = 1;
            } else {
                color = 0x2122;
                ((u8 *)p)[i + 96] = 0;
            }
        } else {
            if (WORLDTRADE_INPUT_CategoryHasListEntries(p, i) == 1) {
                color = 0x3dc2;
                ((u8 *)p)[i + 96] = 1;
            } else {
                color = 0x2122;
                ((u8 *)p)[i + 96] = 0;
            }
        }
        WORLDTRADE_INPUT_PutBmpWinString(p->mgr, (*(void ***)p)[i], str, 2, color, g);
        STRBUF_Delete(str);
    }
    if (mode == 6) {
        str = MSGDATA_AllocString(p->bank, 188);
        WORLDTRADE_INPUT_PutBmpWinString(p->mgr, (*(void ***)p)[15], str, 2, 0x3dc2, (u8 *)p + 124);
        STRBUF_Delete(str);
    }
    BGWINFRM_PutFrame(p->mgr, 0, pos, 0);
    BGWINFRM_ShowFrame(p->mgr, 0);
}

void WORLDTRADE_INPUT_DrawThreeOptionScreen(WorldtradeMenu *p)
{
    int i;
    void *str;
    BGWINFRM_SetFrameDataArc(p->mgr, 0, 96, 25, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    WORLDTRADE_INPUT_CreateModeWindows(p, 1);
    for (i = 0; i < 3; i++) {
        str = MSGDATA_AllocString(p->bank, i + 130);
        WORLDTRADE_INPUT_PutBmpWinString(p->mgr, (*(void ***)p)[i], str, 2, 0x3dc2, (u8 *)p + 124);
        STRBUF_Delete(str);
    }
    WORLDTRADE_INPUT_PrintFrameStringAlt(p->mgr, p->bank, (*(void ***)p)[14], 74, (u8 *)p + 124);
    BGWINFRM_PutFrame(p->mgr, 0, 32, 0);
    BGWINFRM_ShowFrame(p->mgr, 0);
    BGWINFRM_StartMove(p->mgr, 0, -4, 0, 4);
}

void WORLDTRADE_INPUT_DrawGenderListScreen(WorldtradeMenu *p)
{
    BGWINFRM_SetFrameDataArc(p->mgr, 0, 96, 29, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    WORLDTRADE_INPUT_CreateModeWindows(p, 2);
    if (p->listKind == 1)
        p->total = WORLDTRADE_DEPOSIT_CreateGenderMenu((void **)((u8 *)p + 48), p->bank, 1);
    else if (p->listKind == 0)
        p->total = WORLDTRADE_DEPOSIT_CreateGenderMenu((void **)((u8 *)p + 48), p->bank, 0);
    WORLDTRADE_INPUT_PrintPageNumberA((WorldtradeMenu *)p, 0, p->total);
    p->page = 0;
    WORLDTRADE_INPUT_PrintPageLabel(p->mgr, p->num, (*(void ***)p)[4], p->page, WORLDTRADE_INPUT_GetPageCount(p->total, 4));
    WORLDTRADE_INPUT_PrintFrameStringAlt(p->mgr, p->bank, (*(void ***)p)[14], 74, (u8 *)p + 124);
    BGWINFRM_PutFrame(p->mgr, 0, 32, 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), 6);
    p->last = 0;
    *(int *)(unsigned int *)&p->pos = 0;
    WORLDTRADE_SetActorPos(p->cursor, tbl_02203220[p->pos].x, tbl_02203220[p->pos].y);
    BGWINFRM_ShowFrame(p->mgr, 0);
    BGWINFRM_StartMove(p->mgr, 0, -4, 0, 4);
    *(int *)(unsigned int *)&p->state = 34;
}

void WORLDTRADE_INPUT_PutBmpWinString(void *mgr, void *win, void *str, u32 x, u16 color, void *printer)
{
    WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, x, 0, 0, color, (Printer *)printer);
    BMP_WIN_TransferChars((struct BmpWin *)win);
    BGWINFRM_PutBmpWin((struct BgWinFrmWork *)mgr, 0, win);
}

int WORLDTRADE_INPUT_StateNone(void)
{
    return -1;
}

/*
 * lever: explicit if/else calls preserve the flag argument's scheduling.
 */
int WORLDTRADE_INPUT_StateWaitFrameIn(WorldtradeMenu *p)
{
    if (!BGWINFRM_IsMoving((struct BgWinFrmWork *)(*(struct WinMgr * *)&p->mgr), 0)) {
        if (UI_GetInputMode() == 1)
            CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 0);
        else
            CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 1);
        if (p->mode == 2) {
            CLACT_SetActorAutoAnim((*(void * *)&p->up), 0);
            CLACT_SetActorAutoAnim((*(void * *)&p->down), 0);
            CLACT_SetActorAnimSeq((*(void * *)&p->up), 38);
            CLACT_SetActorAnimSeq((*(void * *)&p->down), 39);
            WORLDTRADE_SetActorPos(p->up, 228, 120);
            WORLDTRADE_SetActorPos(p->down, 154, 120);
            CLACT_SetActorDrawEnable((*(void * *)&p->up), 1);
            CLACT_SetActorDrawEnable((*(void * *)&p->down), 1);
        }
        p->state = p->nextState;
    }
    return -1;
}

/*
 * Flush the queued value when the probe reports empty, then answer -1.
 */
int WORLDTRADE_INPUT_StateWaitFrameMove(WorldtradeMenu *p)
{
    if (BGWINFRM_IsMoving((struct BgWinFrmWork *)(*(struct WinMgr * *)&p->mgr), 0) == 0) {
        (*(unsigned int *)&p->state) = (*(unsigned int *)&p->nextState);
    }
    return -1;
}

/*
 * trailing: two-byte zero alignment padding at 0x021FAD82.
 */
int WORLDTRADE_INPUT_StateStartFrameOutSlow(WorldtradeMenu *p)
{
    if (CLACT_IsActorAnimActive((*(void * *)&p->cursor))) return -1;
    CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->up), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->down), 0);
    if (p->mode == 3 && p->nextState == 28)
        BGWINFRM_StartMove(p->mgr, 0, 6, 0, 6);
    else
        BGWINFRM_StartMove(p->mgr, 0, 4, 0, 4);
    p->state = 4;
    return -1;
}

/*
 * Drain the queue then flush the shadowed value, always answering -1.
 */
int WORLDTRADE_INPUT_StateWaitFrameHide(WorldtradeMenu *p)
{
    if (BGWINFRM_IsMoving((struct BgWinFrmWork *)(*(struct WinMgr * *)&p->mgr), 0) == 0) {
        BGWINFRM_HideFrame((struct BgWinFrmWork *)(*(struct WinMgr * *)&p->mgr), 0);
        (*(unsigned int *)&p->state) = (*(unsigned int *)&p->nextState);
    }
    return -1;
}

int WORLDTRADE_INPUT_StateStartFrameOut(WorldtradeMenu *p)
{
    if (CLACT_IsActorAnimActive((*(void * *)&p->cursor))) return -1;
    CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->up), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->down), 0);
    BGWINFRM_StartMove(p->mgr, 0, 4, 0, 4);
    p->state = 2;
    return -1;
}

void WORLDTRADE_INPUT_StateStartCategoryScreen(WorldtradeMenu *p) {WORLDTRADE_INPUT_DrawFrame(p,4,32);CLACT_SetActorAnimSeq((*(void * *)&p->cursor),18);WORLDTRADE_SetActorPos(p->cursor,144,40);BGWINFRM_StartMove(p->mgr,0,-4,0,4);(*(unsigned int *)&p->state)=1;(*(unsigned int *)&p->nextState)=7;p->layout=-1;}

int WORLDTRADE_INPUT_StateCategoryInput(WorldtradeMenu *p)
{
    u32 sel = WORLDTRADE_INPUT_UpdateCategoryGrid((WorldtradeMenu *)p, (u8 *)p + 96);
    if (sel != -2) {
        if (sel <= 8) {
            CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 1);
            CLACT_SetActorAnimSeq((*(void * *)&p->cursor), 19);
            p->state = 8;
            p->layout = sel;
        }
    } else {
        CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 1);
        CLACT_SetActorAnimSeq((*(void * *)&p->cursor), CLACT_GetActorAnimSeq((*(void * *)&p->cursor)) + 9);
        p->state = 3;
        p->nextState = 8;
        p->layout = -1;
    }
    return -1;
}

int WORLDTRADE_INPUT_StateCategorySelected(WorldtradeMenu *p)
{
    if (CLACT_IsActorAnimActive((*(void * *)&p->cursor))) return -1;
    WORLDTRADE_INPUT_MenuFinish((WorldtradeMenu *)p, 4);
    CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 0);
    if (p->layout >= 0) {
        if (tbl_022033FC[p->layout].count != 1)
            p->state = 10;
        else {
            p->start = 0;
            p->state = 14;
        }
    } else return -2;
    return -1;
}

int WORLDTRADE_INPUT_DrawCategoryScreen(WorldtradeMenu *p)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    BGWINFRM_SetFrameDataArc(p->mgr, 0, 96, 28, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    WORLDTRADE_INPUT_CreateModeWindows(p, 4);
    WORLDTRADE_INPUT_PrintFrameStringAlt(p->mgr, p->bank, (*(void ***)p)[14], 74, (u8 *)p + 124);
    MI_CpuFill8((u8 *)p + 96, 1, 26);
    g = (u8 *)p + 124;
    for (i = 0; i < 9; i++) {
        str = MSGDATA_AllocString(p->bank, i + 116);
        if (WORLDTRADE_INPUT_CategoryHasSpecies(p, i) == 1) {
            color = 0x3dc2;
            ((u8 *)p)[i + 96] = 1;
        } else {
            color = 0x2122;
            ((u8 *)p)[i + 96] = 0;
        }
        WORLDTRADE_INPUT_PutBmpWinString(p->mgr, (*(void ***)p)[i], str, 2, color, g);
        STRBUF_Delete(str);
    }
    BGWINFRM_PutFrame(p->mgr, 0, 16, 0);
    BGWINFRM_ShowFrame(p->mgr, 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), 18);
    WORLDTRADE_SetActorPos(p->cursor, (tbl_022032C6[p->layout].x + 16) * 8, tbl_022032C6[p->layout].y * 8);
    p->pos = p->layout;
    CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
    p->state = 7;
    if (UI_GetInputMode() == 1)
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 0);
    else
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
    return -1;
}

int WORLDTRADE_INPUT_DrawSubCategoryScreen(WorldtradeMenu *menu)
{
    int i;
    u16 color;

    i = 1;
    BGWINFRM_SetFrameDataArc(menu->mgr, 0, 0x60, 0x1A, 1);
    BGWINFRM_GetFrameBuffer(menu->mgr, 0);
    WORLDTRADE_INPUT_CreateModeWindows(menu, 5);
    MI_CpuFill8(menu->flags, 1, 0x1A);
    WORLDTRADE_INPUT_PrintFrameString(menu->mgr, menu->bank, menu->wins[0], menu->layout + 0x74, 2, 0x3DC2, menu->g);
    for (i = 1; i < tbl_022033F8[menu->layout].count + 1; i++) {
        if (WORLDTRADE_INPUT_CountSpeciesInList(menu, (sptr)tbl_02203324[menu->layout] + i - 1) > 0) {
            color = 0x3DC2;
            menu->flags[(sptr)tbl_02203324[menu->layout] + i - 1] = 1;
        } else {
            color = 0x2122;
            menu->flags[(sptr)tbl_02203324[menu->layout] + i - 1] = 0;
        }
        WORLDTRADE_INPUT_PrintFrameString(menu->mgr, menu->bank, menu->wins[i], tbl_02203440[i + tbl_022033F8[menu->layout].first - 1], 5, color, menu->g);
    }
    WORLDTRADE_INPUT_PrintFrameStringAlt(menu->mgr, menu->bank, menu->wins[14], 0x4A, menu->g);
    BGWINFRM_PutFrame(menu->mgr, 0, 0x10, 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)menu->cursor, 4);
    if (menu->start < 0) {
        menu->pos = 0;
    } else {
        menu->pos = menu->start;
    }
    WORLDTRADE_SetActorPos(menu->cursor, (tbl_022032C6[menu->pos].x + 0x10) * 8, tbl_022032C6[menu->pos].y * 8);
    if (UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->cursor, 0);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->cursor, 1);
    }
    menu->state = 0xB;
    return -1;
}

int WORLDTRADE_INPUT_StateSubCategoryInput(WorldtradeMenu *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdateButtonRow((WorldtradeMenu *)p, (sptr)((u8 *)p + 0x60));
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 12;
        p->start = r;
        break;
    case -2:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 12;
        p->start = -1;
        break;
    }
    return -1;
}

int WORLDTRADE_INPUT_StateSubCategorySelected(WorldtradeMenu *p) { if(CLACT_IsActorAnimActive((*(void * *)&p->cursor)))return -1;CLACT_SetActorDrawEnable((*(void * *)&p->cursor),0);WORLDTRADE_INPUT_MenuFinish((WorldtradeMenu *)p, 5);if(p->start>=0)*(u32 *)&p->state=14;else *(u32 *)&p->state=9;return -1; }

/*
 * WorldtradeState select before the notify call.
 */
int WORLDTRADE_INPUT_StateRestoreCursor(WorldtradeMenu *p)
{
    struct ClactActor *v;
    int n;

    if (UI_GetInputMode() == 1) {
        v = p->cursor;
        n = 0;
    } else {
        v = p->cursor;
        n = 1;
    }
    CLACT_SetActorDrawEnable(v, n);
    (*(unsigned int *)&p->state) = 0xa;
    return -1;
}

/*
 * Count the entries of a u16 table that the query accepts.
 */
int WORLDTRADE_INPUT_CountSeenSpecies(u32 unused, u32 item, u32 count, u16 *list, int start, int end)
{
    int i;
    int n = 0;

    for (i = start; i < end; i++) {
        if (ZUKAN_SAVE_IsSeen((struct ZukanSave *)item, list[i]) != 0) {
            n++;
        }
    }
    return n;
}

int WORLDTRADE_INPUT_CreateSpeciesMenu(BmpMenuWork **menu, void *msg, void *bank, u32 speciesFlags, u32 kind, void *bag)
{
    u32 count;
    int start;
    int end;
    int n;
    int i;
    u16 *list;

    list = WORLDTRADE_DEPOSIT_LoadSpeciesList(0x48, 0, &count);
    WORLDTRADE_DEPOSIT_GetSpeciesRange(kind, &start, &end);
    count = end - start;
    n = WORLDTRADE_INPUT_CountSeenSpecies(speciesFlags, (uptr)bag, count, list, start, end);
    *menu = BMP_MENUWORK_Create(n + 1, 0x48);
    for (i = start; i < end; i++) {
        if (ZUKAN_SAVE_IsSeen((struct ZukanSave *)bag, list[i]) != 0) {
            BMP_MENUWORK_AddMsgItem(*menu, (struct MsgBank *)((uptr)msg), list[i], list[i], 0x48);
        }
    }
    GFL_HEAP_Free(list);
    return n;
}

void WORLDTRADE_INPUT_PrintPageNumberA(WorldtradeMenu *menu, int page, int total)
{
    int i;

    for (i = 0; i < 4; i++) {
        BMP_Clear(BMP_WIN_GetBmp(menu->wins[i]), 0xA);
        if (i + page * 4 < total) {
            WORLDTRADE_INPUT_PutBmpWinString(menu->mgr, menu->wins[i], menu->items[page * 4 + i].u.handle, 0, 0x3DC2, menu->g);
        } else {
            BMP_WIN_TransferChars(menu->wins[i]);
            BGWINFRM_PutBmpWin(menu->mgr, 0, menu->wins[i]);
        }
    }
}

void WORLDTRADE_INPUT_PrintPageNumberB(WorldtradeMenu *menu, int page, int total)
{
    int i;

    for (i = 0; i < 5; i++) {
        BMP_Clear(BMP_WIN_GetBmp(menu->wins[i]), 0xA);
        if (i + page * 5 < total) {
            WORLDTRADE_INPUT_PutBmpWinString(menu->mgr, menu->wins[i], menu->items[page * 5 + i].u.handle, 0, 0x3DC2, menu->g);
        } else {
            BMP_WIN_TransferChars(menu->wins[i]);
            BGWINFRM_PutBmpWin(menu->mgr, 0, menu->wins[i]);
        }
    }
}

int WORLDTRADE_INPUT_DrawSpeciesListScreen(WorldtradeMenu *p)
{
    u8 pages;

    BGWINFRM_SetFrameDataArc(p->mgr, 0, 0x60, 0x1D, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    WORLDTRADE_INPUT_CreateModeWindows(p, 0);
    p->total = WORLDTRADE_INPUT_CreateSpeciesMenu(&p->items, p->msg, p->bank, p->speciesFlags, (sptr)tbl_02203324[p->layout] + p->start, p->bag);
    p->page = 0;
    WORLDTRADE_INPUT_PrintPageNumberA((WorldtradeMenu *)p, 0, p->total);
    pages = WORLDTRADE_INPUT_GetPageCount(p->total, 4);
    WORLDTRADE_INPUT_PrintPageLabel(p->mgr, p->num, p->wins[4], p->page, pages);
    WORLDTRADE_INPUT_PrintFrameStringAlt(p->mgr, p->bank, p->wins[14], 0x4A, p->g);
    BGWINFRM_PutFrame(p->mgr, 0, 0x10, 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, 6);
    p->pos = 0;
    WORLDTRADE_SetActorPos(p->cursor, tbl_02203220[p->pos].x, tbl_02203220[p->pos].y);
    WORLDTRADE_SetActorPos(p->up, 0xE4, 0x78);
    WORLDTRADE_SetActorPos(p->down, 0x9A, 0x78);
    if (UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 0);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
    }
    if (pages == 1) {
        CLACT_SetActorAnimSeq((struct ClactActor *)p->up, 0x3D);
        CLACT_SetActorAnimSeq((struct ClactActor *)p->down, 0x3E);
    } else {
        CLACT_SetActorAnimSeq((struct ClactActor *)p->up, 0x26);
        CLACT_SetActorAnimSeq((struct ClactActor *)p->down, 0x27);
    }
    CLACT_SetActorAutoAnim((struct ClactActor *)p->up, 0);
    CLACT_SetActorAutoAnim((struct ClactActor *)p->down, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->up, 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->down, 1);
    p->state = 0xF;
    return -1;
}

int WORLDTRADE_INPUT_StateSpeciesListInput(WorldtradeMenu *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdatePagedList4((WorldtradeMenu *)p);
    switch (r) {
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 16;
        p->speciesResult = -1;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 3;
        p->nextState = 17;
        p->speciesResult = r;
        break;
    }
    return -1;
}

/*
 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0xd/0x9 code from the table.
 */
int WORLDTRADE_INPUT_StateSpeciesListSelected(WorldtradeMenu *p)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)((struct Actor *)(*(u32 *)(void * *)&p->cursor))) != 0) {
        return -1;
    }
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)*(u32 *)(void * *)&p->cursor), 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->up, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->down, 0);
    WORLDTRADE_INPUT_MenuFinish((WorldtradeMenu *)p, 0x0);
    BMP_MENUWORK_Delete((void *)(*(u32 *)(void **)&p->items));
    *(u32 *)&p->state = (*(s32 *)(g_022033FC + p->layout * 8) != 1) ? 0xd : 0x9;
    return -1;
}

int WORLDTRADE_INPUT_StateSpeciesListClose(WorldtradeMenu *p) { if(CLACT_IsActorAnimActive((*(void * *)&p->cursor)))return -1;CLACT_SetActorDrawEnable((*(void * *)&p->cursor),0);WORLDTRADE_INPUT_MenuFinish((WorldtradeMenu *)p, 0);BMP_MENUWORK_Delete((void *)p->items);return p->speciesResult; }

int WORLDTRADE_INPUT_StateStartCategoryScreenAlt(WorldtradeMenu *p)
{
    WORLDTRADE_INPUT_DrawFrame(p, 6, 0x20);
    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), 18);
    BGWINFRM_StartMove(p->mgr, 0, -4, 0, 4);
    p->state = 1;
    p->nextState = 19;
    p->pos = 10;
    p->layout = -1;
    WORLDTRADE_SetActorPos(p->cursor, (tbl_02203298[p->pos].x + 16) * 8, tbl_02203298[p->pos].y * 8);
    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), 6);
    return -1;
}

int WORLDTRADE_INPUT_StateCategoryInputAlt(WorldtradeMenu *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdateCategoryGridAlt((WorldtradeMenu *)p, (u8 *)p + 0x60);
    switch ((u32)r) {
    case -2:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 3;
        p->nextState = 20;
        p->layout = -1;
        break;
    case 10:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 3;
        p->nextState = 20;
        p->layout = -2;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), 19);
        p->layout = r;
        p->state = 20;
        break;
    }
    return -1;
}

int WORLDTRADE_INPUT_StateCategorySelectedAlt(WorldtradeMenu *p)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)((*(void * *)&p->cursor))) != 0) return -1;
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)*(u32 *)(void * *)&p->cursor), 0);
    WORLDTRADE_INPUT_MenuFinish((WorldtradeMenu *)p, 6);
    if (p->layout < 0) {
        if (p->layout == -1) return -2;
        else if (p->layout == -2) return 0;
    } else {
        if (tbl_022033FC[p->layout].count != 1) {
            p->state = 22;
        } else {
            p->start = 0;
            BGWINFRM_StartMove(p->mgr, 0, -4, 0, 3);
            if (p->rowCursor != 0) CLACT_SetActorDrawEnable((struct ClactActor *)p->rowCursor, 0);
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(*(u32 *)(void * *)&p->cursor)), 7);
            p->state = 2;
            BGWINFRM_SetFrameDataArc(p->mgr, 0, 0x60, 0x18, 1);
            p->nextState = 26;
        }
    }
    return -1;
}

int WORLDTRADE_INPUT_StateReturnToCategoryAlt(WorldtradeMenu *p)
{
    WORLDTRADE_INPUT_DrawFrame(p, 6, 0x10);
    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), 18);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
    p->pos = p->layout;
    WORLDTRADE_SetActorPos(p->cursor, (tbl_02203298[p->pos].x + 16) * 8, tbl_02203298[p->pos].y * 8);
    if (UI_GetInputMode() == 1) CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 0);
    else CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
    p->state = 19;
    return -1;
}

int WORLDTRADE_INPUT_DrawSubCategoryScreenAlt(WorldtradeMenu *p)
{
    int i;
    u16 color;

    BGWINFRM_SetFrameDataArc(p->mgr, 0, 0x60, 0x1A, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    WORLDTRADE_INPUT_CreateModeWindows(p, 5);
    MI_CpuFill8(p->flags, 1, 0x1A);
    WORLDTRADE_INPUT_PrintFrameString(p->mgr, p->bank, p->wins[0], p->layout + 0x74, 2, 0x3DC2, p->g);
    for (i = 1; i < 4; i++) {
        if (WORLDTRADE_INPUT_GetListRangeCount(p, (sptr)tbl_02203324[p->layout] + i - 1) > 0) {
            color = 0x3DC2;
            p->flags[(sptr)tbl_02203324[p->layout] + i - 1] = 1;
        } else {
            color = 0x2122;
            p->flags[(sptr)tbl_02203324[p->layout] + i - 1] = 0;
        }
        WORLDTRADE_INPUT_PrintFrameString(p->mgr, p->bank, p->wins[i], tbl_02203440[tbl_022033F8[p->layout].first + i - 1], 5, color, p->g);
    }
    WORLDTRADE_INPUT_PrintFrameStringAlt(p->mgr, p->bank, p->wins[14], 0x4A, p->g);
    BGWINFRM_PutFrame(p->mgr, 0, 0x10, 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, 4);
    if (p->start < 0) {
        p->pos = 0;
    } else {
        p->pos = p->start;
    }
    WORLDTRADE_SetActorPos(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
    if (UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 0);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
    }
    if (p->rowCursor != 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->rowCursor, 1);
    }
    p->state = 0x17;
    return -1;
}

int WORLDTRADE_INPUT_StateSubCategoryInputAlt(WorldtradeMenu *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdateButtonRow(p, (sptr)((u8 *)p + 0x60));
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 24;
        p->start = r;
        break;
    case -2:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 24;
        p->start = -1;
        break;
    }
    return -1;
}

/*
 * Tail: two zero bytes of alignment padding after the return.
 */
int WORLDTRADE_INPUT_StateSubCategorySelectedAlt(WorldtradeMenu *p)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)((*(void * *)&p->cursor))) != 0) return -1;
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)*(u32 *)(void * *)&p->cursor), 0);
    WORLDTRADE_INPUT_MenuFinish(p, 5);
    if (p->start < 0) {
        p->state = 21;
    } else {
            BGWINFRM_StartMove(p->mgr, 0, -4, 0, 3);
            if (p->rowCursor != 0) CLACT_SetActorDrawEnable((struct ClactActor *)p->rowCursor, 0);
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(*(u32 *)(void * *)&p->cursor)), 7);
            p->state = 2;
            BGWINFRM_SetFrameDataArc(p->mgr, 0, 0x60, 0x18, 1);
            p->nextState = 26;
    }
    return -1;
}

/*
 * WorldtradeState select before the notify call.
 */
int WORLDTRADE_INPUT_StateRestoreCursorAlt(WorldtradeMenu *p)
{
    struct ClactActor *v;
    int n;

    p->state = 0x16;
    p->pos = p->start;
    if (UI_GetInputMode() == 1) {
        v = p->cursor;
        n = 0;
    } else {
        v = p->cursor;
        n = 1;
    }
    CLACT_SetActorDrawEnable(v, n);
    return -1;
}

int WORLDTRADE_INPUT_DrawConditionListScreen(WorldtradeMenu *p)
{
    u8 pages;
    BGWINFRM_SetFrameDataArc(p->mgr,0,0x60,0x18,1);
    WORLDTRADE_INPUT_CreateModeWindows((WorldtradeMenu *)p, 3);
    p->total=WORLDTRADE_DEPOSIT_CreateListMenu((void **)&p->items,p->listMsg,p->start+(sptr)tbl_02203324[p->layout]);
    WORLDTRADE_INPUT_PrintPageNumberB(p,0,p->total);
    p->page=0;
    pages=WORLDTRADE_INPUT_GetPageCount(p->total,5);
    WORLDTRADE_INPUT_PrintPageLabel(p->mgr,p->num,p->wins[5],p->page,pages);
    WORLDTRADE_INPUT_PrintFrameStringAlt(p->mgr,p->bank,p->wins[14],0x4A,(u8 *)p+0x7C);
    BGWINFRM_PutFrame(p->mgr,0,1,0);
    p->pos=0;
    WORLDTRADE_SetActorPos(p->cursor,tbl_02203236[p->pos].x,tbl_02203236[p->pos].y);
    WORLDTRADE_SetActorPos(p->up,0xB0,0x88);
    WORLDTRADE_SetActorPos(p->down,0x58,0x88);
    if(UI_GetInputMode()==1)
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor,0);
    else
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor,1);
    if(pages==1) {
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->up)),0x3D);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->down)),0x3E);
    } else {
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->up)),0x26);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->down)),0x27);
    }
    CLACT_SetActorAutoAnim((struct ClactActor *)p->up,0);
    CLACT_SetActorAutoAnim((struct ClactActor *)p->down,0);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->up,1);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->down,1);
    p->state=27;
    return -1;
}

int WORLDTRADE_INPUT_StateConditionListInput(WorldtradeMenu *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdatePagedList5(p);
    switch (r) {
    case -2:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        BGWINFRM_SetFrameDataArc(p->mgr, 0, 0x60, 0x18, 1);
        p->state = 5;
        p->nextState = 28;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 3;
        p->nextState = 29;
        p->conditionResult = r;
        break;
    }
    return -1;
}

/*
 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0x19/0x15 code from the table.
 */
int WORLDTRADE_INPUT_StateConditionListSelected(WorldtradeMenu *p)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)((struct Actor *)(*(u32 *)(void * *)&p->cursor))) != 0) {
        return -1;
    }
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)*(u32 *)(void * *)&p->cursor), 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->up, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->down, 0);
    WORLDTRADE_INPUT_MenuFinish(p, 0x3);
    BMP_MENUWORK_Delete((void *)(*(u32 *)&p->items));
    *(u32 *)&p->state = (*(s32 *)(g_022033FC + p->layout * 8) != 1) ? 0x19 : 0x15;
    return -1;
}

int WORLDTRADE_INPUT_StateConditionListClose(WorldtradeMenu *p)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)((*(void * *)&p->cursor))) != 0) return -1;
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)*(u32 *)(void * *)&p->cursor), 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->up, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->down, 0);
    WORLDTRADE_INPUT_MenuFinish(p, 3);
    BMP_MENUWORK_Delete(p->items);
    return p->conditionResult;
}

/*
 * Reset, re-arm the 6 frame, then index the two parallel stride-2 tables from the cursor at +0x44.
 */
int WORLDTRADE_INPUT_StateStartThreeOptionScreen(WorldtradeMenu *p)
{
    u32 i;

    p->pos = 0;
    WORLDTRADE_INPUT_DrawThreeOptionScreen(p);
    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), 6);
    i = p->pos;
    WORLDTRADE_SetActorPos(p->cursor, g_0220320E[i * 2], g_0220320F[i * 2]);
    p->state = 1;
    p->nextState = 0x1f;
    return -1;
}

int WORLDTRADE_INPUT_StateThreeOptionInput(WorldtradeMenu *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdateThreeOptionMenu(p);
    switch (r) {
    case -2:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 3;
        p->nextState = 32;
        p->optionResult = -2;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 3;
        p->nextState = 32;
        p->optionResult = r;
        break;
    }
    return -1;
}

/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int WORLDTRADE_INPUT_StateThreeOptionClose(WorldtradeMenu *p) { if(CLACT_IsActorAnimActive((void *)p->cursor))return -1;CLACT_SetActorDrawEnable((void *)p->cursor,0);WORLDTRADE_INPUT_MenuFinish(p,1);return p->optionResult; }

int WORLDTRADE_INPUT_StateStartGenderListScreen(WorldtradeMenu *p)
{
    u32 i;

    p->pos = 0;
    WORLDTRADE_INPUT_DrawGenderListScreen(p);
    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), 6);
    i = p->pos;
    WORLDTRADE_SetActorPos(p->cursor, g_02203216[i * 2], g_02203217[i * 2]);
    p->state = 1;
    p->nextState = 0x22;
    return -1;
}

int WORLDTRADE_INPUT_StateGenderListInput(WorldtradeMenu *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdatePagedList4Alt(p);
    switch (r) {
    case -2:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 3;
        p->nextState = 35;
        p->genderResult = -2;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor)), CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)(p->cursor))) + 9);
        p->state = 3;
        p->nextState = 35;
        p->genderResult = *(u32 *)(*(u8 * *)&p->items + (r + p->page * 4) * 8 + 4);
        break;
    }
    return -1;
}

int WORLDTRADE_INPUT_StateGenderListClose(WorldtradeMenu *p) { if(CLACT_IsActorAnimActive((*(void * *)&p->cursor)))return -1;CLACT_SetActorDrawEnable((*(void * *)&p->cursor),0);WORLDTRADE_INPUT_MenuFinish(p,2);BMP_MENUWORK_Delete(p->items);return p->genderResult; }

void WORLDTRADE_INPUT_PrintFrameString(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *printer)
{
    void *str = MSGDATA_AllocString(bank, index);

    WORLDTRADE_INPUT_PutBmpWinString(mgr, win, str, x, color, printer);
    STRBUF_Delete(str);
}

void WORLDTRADE_INPUT_PrintFrameStringAlt(void *mgr, void *bank, void *win, u32 index, void *printer)
{
    void *str = MSGDATA_AllocString(bank, index);

    WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, 0, 0, 0, 0x3DC2, (Printer *)printer);
    BMP_WIN_TransferChars(win);
    BGWINFRM_PutBmpWin(mgr, 0, win);
    STRBUF_Delete(str);
}

void WORLDTRADE_INPUT_PrintPageLabel(void *mgr, void *ctx, void *win, int page, u32 pages)
{
    BMP_Clear(BMP_WIN_GetBmp(win), 8);
    WORLDTRADE_ADAPTER_PrintNumber(ctx, page + 1, 2, 1, win, 0, 0);
    WORLDTRADE_ADAPTER_QueueMessagePrint(ctx, 0, win, 0x10, 0);
    WORLDTRADE_ADAPTER_PrintNumber(ctx, pages, 2, 0, win, 0x18, 0);
    BMP_WIN_TransferChars(win);
    BGWINFRM_PutBmpWin(mgr, 0, win);
}

int WORLDTRADE_INPUT_CountSpeciesInList(WorldtradeMenu *menu, u32 idx)
{
    u32 n;
    int start;
    int end;
    u16 *list;
    int r;

    list = WORLDTRADE_DEPOSIT_LoadSpeciesList(0x48, 0, &n);
    WORLDTRADE_DEPOSIT_GetSpeciesRange(idx, &start, &end);
    n = end - start;
    r = WORLDTRADE_INPUT_CountSeenSpecies(menu->speciesFlags, (uptr)menu->bag, n, list, start, end);
    GFL_HEAP_Free(list);
    return r;
}

int WORLDTRADE_INPUT_CategoryHasSpecies(void *p, int idx)
{
    int base;
    int i;
    base = (sptr)tbl_02203324[idx];
    if (tbl_022033F8[idx].count > 0) {
        for (i = 0; i < tbl_022033F8[idx].count; i++) {
            if (WORLDTRADE_INPUT_CountSpeciesInList(p, base + i) > 0) return 1;
        }
    } else {
        if (WORLDTRADE_INPUT_CountSpeciesInList(p, base) > 0) return 1;
    }
    return 0;
}

/*
 * Hand the second argument to WORLDTRADE_DEPOSIT_GetListRange with a scratch word.
 */
int WORLDTRADE_INPUT_GetListRangeCount(void *p, u32 id)
{
    u32 tmp;

    return WORLDTRADE_DEPOSIT_GetListRange(id, &tmp);
}

int WORLDTRADE_INPUT_CategoryHasListEntries(void *p, int idx)
{
    int base;
    int i;
    base = (sptr)tbl_02203324[idx];
    if (tbl_022033F8[idx].count > 0) {
        for (i = 0; i < tbl_022033F8[idx].count; i++) {
            if (WORLDTRADE_INPUT_GetListRangeCount(p, base + i) > 0) return 1;
        }
    } else {
        if (WORLDTRADE_INPUT_GetListRangeCount(p, base) > 0) return 1;
    }
    return 0;
}
