/*
 * file:     worldtrade_deposit.c
 * unit:     yes
 * function: WORLDTRADE_DEPOSIT_Init, WORLDTRADE_DEPOSIT_Main, WORLDTRADE_DEPOSIT_Exit, WORLDTRADE_DEPOSIT_PrintMessage, WORLDTRADE_DEPOSIT_SetupBgPlanes, WORLDTRADE_DEPOSIT_ExitBgPlanes, WORLDTRADE_DEPOSIT_LoadBgGraphics, WORLDTRADE_DEPOSIT_CreateWindows, WORLDTRADE_DEPOSIT_DeleteWindows, WORLDTRADE_DEPOSIT_CreateActors, WORLDTRADE_DEPOSIT_DeleteActors, WORLDTRADE_DEPOSIT_CreateStrings, WORLDTRADE_DEPOSIT_DeleteStrings, WORLDTRADE_DEPOSIT_WaitWipeIn, WORLDTRADE_DEPOSIT_StateWaitCancel, WORLDTRADE_DEPOSIT_StateOpenCategoryMenu, WORLDTRADE_DEPOSIT_StateCategoryMenuInput, WORLDTRADE_DEPOSIT_StateCreateSpeciesMenu, WORLDTRADE_DEPOSIT_SetGenderFromEvent, WORLDTRADE_DEPOSIT_StateSpeciesMenuInput, WORLDTRADE_DEPOSIT_StatePrintGenderPrompt, WORLDTRADE_DEPOSIT_StateOpenGenderMenu, WORLDTRADE_DEPOSIT_StateGenderMenuInput, WORLDTRADE_DEPOSIT_StatePrintLevelPrompt, WORLDTRADE_DEPOSIT_StateOpenLevelMenu, WORLDTRADE_DEPOSIT_StateLevelMenuInput, WORLDTRADE_DEPOSIT_StatePrintConfirmPrompt, WORLDTRADE_DEPOSIT_StateOpenConfirmYesNo, WORLDTRADE_DEPOSIT_StateConfirmYesNoInput, WORLDTRADE_DEPOSIT_StateStartWipeOut, WORLDTRADE_DEPOSIT_StateWaitMessage, WORLDTRADE_DEPOSIT_GetModeColor, WORLDTRADE_DEPOSIT_PrintName, WORLDTRADE_DEPOSIT_PrintBankString, WORLDTRADE_DEPOSIT_PrintMessageLine, WORLDTRADE_DEPOSIT_GetModeFontColor, WORLDTRADE_DEPOSIT_PrintModeLabelAligned, WORLDTRADE_DEPOSIT_PrintModeLabel, WORLDTRADE_DEPOSIT_PrintLevelRange, WORLDTRADE_DEPOSIT_PrintConditionLabel, WORLDTRADE_DEPOSIT_DrawRequestWindow, WORLDTRADE_DEPOSIT_DrawRequestWindowAlt, WORLDTRADE_DEPOSIT_PrintMonSummary, WORLDTRADE_DEPOSIT_LoadSpeciesList, WORLDTRADE_DEPOSIT_GetSpeciesRange, WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable, WORLDTRADE_DEPOSIT_BuildOffer, WORLDTRADE_DEPOSIT_StoreOfferInWork, WORLDTRADE_DEPOSIT_CreateSpeciesMenu, WORLDTRADE_DEPOSIT_CreateSpeciesMenuList, WORLDTRADE_DEPOSIT_CreateGenderMenu, WORLDTRADE_DEPOSIT_GetLevelBracket, WORLDTRADE_DEPOSIT_FindLevelBracketIndex, WORLDTRADE_DEPOSIT_SetCountryFilter, WORLDTRADE_DEPOSIT_GetListRange, WORLDTRADE_DEPOSIT_CreateListMenu, WORLDTRADE_DEPOSIT_UpdateListMenu, WORLDTRADE_DEPOSIT_ClearListRange, WORLDTRADE_DEPOSIT_SetListRangeEntry
 * address:  0x021F73DC
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
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   GF_PANIC_Fail 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   WORLDTRADE_ADAPTER_IsStreamBusy  0x02202840  thumb  ov135
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WORLDTRADE_INPUT_MenuCreate 0x021F9890 thumb ov135
 *   g_02203BBC  0x02203BBC  data  ov135
 *   WORLDTRADE_INPUT_MenuDelete 0x021F99D0 thumb ov135
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   g_02202F64  0x02202F64  data  ov135
 *   g_02202F84  0x02202F84  data  ov135
 *   g_02202F44  0x02202F44  data  ov135
 *   g_02202FA4  0x02202FA4  data  ov135
 *   ARC_UTIL_UploadBgCharFromArchive 0x02049624 arm
 *   ARC_UTIL_UploadBgPaletteFromArchive 0x0204989C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   tbl_02202EC0 0x02202EC0 data a2
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   WORLDTRADE_DEPOSIT_ClearListRange 0x021F8990 thumb ov135
 *   g_02203C00 0x02203C00 data a4
 *   WORLDTRADE_INPUT_MenuSetMode  0x021F9968  thumb  ov135
 *   WORLDTRADE_DEPOSIT_UpdateListMenu 0x021F8950 thumb ov135
 *   WORLDTRADE_ADAPTER_ClearWindowScreen 0x02202644 thumb ov135
 *   WORLDTRADE_INPUT_MenuUpdate 0x021F99F0 thumb ov135
 *   WORLDTRADE_DEPOSIT_SetListRangeEntry 0x021F89A8 thumb ov135
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb
 *   tbl_02202EB0   0x02202EB0  data
 *   WORLDTRADE_ADAPTER_CreateString  0x02202670  thumb
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   tbl_0220307C   0x0220307C  data
 *   WORLDTRADE_ADAPTER_CopyBoxMon  0x022026A0  thumb
 *   tbl_02203B84 0x02203B84 data a2
 *   d_02202ED8 0x02202ED8 data a4
 *   tbl_0220301C 0x0220301C data a4
 *   tbl_02202FC4 0x02202FC4 data a4
 *   str_02203C18 0x02203C18 data a1
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb  arm9
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb  arm9
 *   POKE_TOOL_ChangeForm  0x02017988  thumb  arm9
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   BMP_MENULIST_Create  0x0201FF30  thumb  arm9
 *   BMP_MENULIST_Delete  0x0202020C  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   ZUKAN_SAVE_IsSeen  0x0200D064  thumb  arm9
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_DEPOSIT_CreateGenderMenu 0x021F87E0 thumb ov135
 *   WORLDTRADE_DEPOSIT_LoadSpeciesList  0x021F8498  thumb
 *   WORLDTRADE_DEPOSIT_GetSpeciesRange  0x021F84BC  thumb
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   WORLDTRADE_DEPOSIT_FindLevelBracketIndex 0x021F886C thumb ov135
 *   WORLDTRADE_DEPOSIT_DrawRequestWindowAlt 0x021F8290 thumb ov135
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORLDTRADE_DEPOSIT_PrintBankString  0x021F7FD4  thumb
 *   WORLDTRADE_DEPOSIT_PrintModeLabel  0x021F8104  thumb
 *   WORLDTRADE_DEPOSIT_PrintConditionLabel  0x021F8178  thumb
 *   WORLDTRADE_DEPOSIT_PrintName  0x021F7F9C  thumb
 *   WORLDTRADE_DEPOSIT_PrintModeLabelAligned  0x021F8098  thumb
 *   WORLDTRADE_DEPOSIT_PrintLevelRange  0x021F8154  thumb
 *   WORLDTRADE_DEPOSIT_PrintMessageLine  0x021F8010  thumb
 *   WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable  0x021F84EC  thumb
 *   WORLDTRADE_DEPOSIT_SetGenderFromEvent 0x021F7B9C thumb ov135
 *   WORLDTRADE_DEPOSIT_GetLevelBracket 0x021F882C thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135
 *   WORLDTRADE_BOX_IsPartyBox 0x021F6B34 thumb ov135
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   WIFI_HISTORY_GetVisitedCountryCount  0x02009584  thumb  arm9
 *   WORDSET_CopyString  0x0201F41C  thumb  arm9
 *   MYSTATUS_GetId  0x02008530  thumb  arm9
 *   MYSTATUS_GetTrainerView  0x02008554  thumb  arm9
 *   MYSTATUS_GetNation  0x0200856C  thumb  arm9
 *   MYSTATUS_GetArea  0x02008570  thumb  arm9
 *   WIFI_HISTORY_GetRatingLevel  0x0200960C  thumb  arm9
 *   WIFI_HISTORY_GetGreetingSet  0x02009628  thumb  arm9
 *   d_022030E8 0x022030E8 data a2
 *   tbl_02202F0C  0x02202F0C  data
 *   tbl_022030E8 0x022030E8 data a2
 *   BMP_MENULIST_Main  0x020200CC  thumb  arm9
 *   WORLDTRADE_DEPOSIT_CreateListMenu 0x021F8908 thumb ov135
 *   WORLDTRADE_DEPOSIT_GetListRange  0x021F88D8  thumb  ov135
 *   WORLDTRADE_DEPOSIT_SetCountryFilter 0x021F88B0 thumb ov135
 *   BMP_MENULIST_GetListIndex  0x020202EC  thumb  arm9
 */
#include "../version.h"
#include "worldtrade_types.h"

struct MenuTemplate;


typedef struct {
    u32 id;
    union {
        struct { s16 x; s16 y; };
        struct { s16 key; s16 val; };
    };
} WorldtradeTableRow;

/* WorldtradeMenu-list source descriptor handed to BMP_MENULIST_Create as `struct MenuTemplate`. */
typedef struct { u32 ptrs[4]; u16 count, rows; u32 extra[8]; } MenuSrc;

#include "../arm9/mi_memory.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/wipe.h"


#include "../arm9/gf_panic.h"

#include "../arm9/arc_tool.h"

struct MyStatus;

#include "../arm9/mystatus.h"
struct MsgBank;
struct Strbuf;

#include "../arm9/msgdata.h"

#include "../arm9/strbuf.h"
struct BmpWin;

#include "../arm9/bmp_win.h"


#include "../arm9/bg_sys.h"

#include "worldtrade_title.h"


#include "worldtrade_input.h"


#include "../arm9/clact.h"







#include "../arm9/arc_util.h"

#include "../arm9/bmp_menuwork.h"



struct Actor;






struct Bmp;

typedef short s16_p07;
#include "../arm9/bmp.h"




#include "worldtrade_adapter.h"



#include "../arm9/gfl_use.h"

#include "../arm9/key.h"




struct BoxPokemon;

#include "../arm9/poke_tool.h"


struct WordSet;


#include "../arm9/wordset.h"












void WORLDTRADE_DEPOSIT_ClearListRange(SelTable *p);


int WORLDTRADE_DEPOSIT_UpdateListMenu(void *p, u16 *old);
struct BmpMenuList;

#include "../arm9/bmp_menulist.h"


struct PersonalData;

#include "../arm9/poke_personal.h"



void WORLDTRADE_DEPOSIT_SetListRangeEntry(SelTable *p, int i, u16 a, u16 b);




struct PokemonParam;









struct WifiHistory;

#include "../arm9/wifi_history.h"


struct ZukanSave;

#include "../arm9/zukan_save.h"
struct MenuTemplate;


#include "worldtrade.h"






#include "worldtrade_box.h"

int WORLDTRADE_DEPOSIT_Init(WorldtradeWork *p);

void WORLDTRADE_DEPOSIT_Main(u8 *p);

int WORLDTRADE_DEPOSIT_Exit(WorldtradeWork *p);

void WORLDTRADE_DEPOSIT_PrintMessage(WorldtradeWork *p, u32 b, u32 c, u32 d, u32 e);

void WORLDTRADE_DEPOSIT_SetupBgPlanes(void);

void WORLDTRADE_DEPOSIT_ExitBgPlanes(void);

void WORLDTRADE_DEPOSIT_LoadBgGraphics(WorldtradeWork *p);

void WORLDTRADE_DEPOSIT_CreateWindows(WorldtradeWork *p);

void WORLDTRADE_DEPOSIT_DeleteWindows(WorldtradeWork *p);

void WORLDTRADE_DEPOSIT_CreateActors(WorldtradeWork *p);

void WORLDTRADE_DEPOSIT_DeleteActors(WorldtradeWork *p);

void WORLDTRADE_DEPOSIT_CreateStrings(WorldtradeWork *p);

void WORLDTRADE_DEPOSIT_DeleteStrings(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_WaitWipeIn(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateWaitCancel(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateOpenCategoryMenu(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateCategoryMenuInput(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateCreateSpeciesMenu(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_SetGenderFromEvent(u8 *p, int event);

int WORLDTRADE_DEPOSIT_StateSpeciesMenuInput(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StatePrintGenderPrompt(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateOpenGenderMenu(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateGenderMenuInput(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StatePrintLevelPrompt(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateOpenLevelMenu(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateLevelMenuInput(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StatePrintConfirmPrompt(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateOpenConfirmYesNo(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateConfirmYesNoInput(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateStartWipeOut(WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_StateWaitMessage(WorldtradeWork *p);

u16 WORLDTRADE_DEPOSIT_GetModeColor(int mode);

void WORLDTRADE_DEPOSIT_PrintName(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintBankString(void *win, void *bank, u32 index, u32 y, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintMessageLine(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g);

u16 WORLDTRADE_DEPOSIT_GetModeFontColor(int mode, u16 color);

void WORLDTRADE_DEPOSIT_PrintModeLabelAligned(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintModeLabel(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintLevelRange(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g);

void WORLDTRADE_DEPOSIT_PrintConditionLabel(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);

void WORLDTRADE_DEPOSIT_DrawRequestWindow(void *bank, void *names, int unused, void **win, u32 index, int mode, int place, void *g);

void WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(void *bank, void *names, void *unused, void **win, u32 index, int mode, int place, void *g);

void WORLDTRADE_DEPOSIT_PrintMonSummary(void *bank, void *ws, void **win, void *mon, MonTag *out, void *g);

u16 *WORLDTRADE_DEPOSIT_LoadSpeciesList(u32 heap, u32 unused, u32 *count);

void WORLDTRADE_DEPOSIT_GetSpeciesRange(u32 i, int *start, int *end);

u8 *WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable(u32 id);

void WORLDTRADE_DEPOSIT_BuildOffer(WorldtradeEntry *dst, WorldtradeWork *p);

void WORLDTRADE_DEPOSIT_StoreOfferInWork(Deposit *dst, WorldtradeWork *p);

int WORLDTRADE_DEPOSIT_CreateSpeciesMenu(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag);

void *WORLDTRADE_DEPOSIT_CreateSpeciesMenuList(WorldtradeWork *p, void **menu, void *win, void *endmsg, void *msg, DepositState *cfg, void *bag);

int WORLDTRADE_DEPOSIT_CreateGenderMenu(void **menu, void *msg, int kind);

void WORLDTRADE_DEPOSIT_GetLevelBracket(u8 *dst, int i, int kind);

int WORLDTRADE_DEPOSIT_FindLevelBracketIndex(int key, int val, int which);

extern void (*g_02203BBC[])(u8 *);

extern struct BgTemplate g_02202F64;

extern struct BgTemplate g_02202F84;

extern struct BgTemplate g_02202F44;

extern struct BgTemplate g_02202FA4;

extern const u16 tbl_02202EC0[][2];

extern const char g_02203C00[];

extern const u32 tbl_02202EB0[];

extern const int tbl_0220307C[];

extern const u16 tbl_02203B84[];

extern const MenuSrc d_02202ED8;

extern const WorldtradeTableRow tbl_0220301C[12];

extern const WorldtradeTableRow tbl_02202FC4[11];

extern const char str_02203C18[];

int WORLDTRADE_DEPOSIT_Init(WorldtradeWork *p)
{
    WorldtradeInputInit init;
    WORLDTRADE_DEPOSIT_CreateStrings(p);
    WORLDTRADE_DEPOSIT_SetupBgPlanes();
    WORLDTRADE_TITLE_ScrollBg(p,0,0);
    WORLDTRADE_DEPOSIT_LoadBgGraphics(p);
    WORLDTRADE_DEPOSIT_CreateWindows((WorldtradeWork *)p);
    WORLDTRADE_DEPOSIT_CreateActors(p);
    WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
    WORLDTRADE_ENTER_RestartNetTimeout((u8 *)p);
    WORLDTRADE_DEPOSIT_DrawRequestWindow(p->bank,p->names,(sptr)(p->words),(void **)((u8 *)p+0xD90),0,3,-1,(u8 *)p+0xFA0);
    WORLDTRADE_DEPOSIT_PrintMonSummary(p->bank,p->words,(void **)((u8 *)p+0xD9C),p->mon,(MonTag *)((u8 *)p+0xB4C),(u8 *)p+0xFA0);
    init.w00=(uptr)((u8 *)p+0xD50);
    init.w04=(uptr)((u8 *)p+0xDD4);
    init.obj=(uptr)p->mark;
    init.w0c=(uptr)p->btn[0];
    init.w10=(uptr)p->btn[1];
    init.w14=0;
    init.w18=(uptr)p->bank;
    init.w1c=(uptr)p->names;
    init.w20=(uptr)p->msg_p;
    init.w24=(uptr)p->ctx->zukanSave;
    init.w28=(uptr)((DepositState *)p->st)->speciesFlags;
    init.arg=(uptr)p->ctx->statusConfig;
    p->menu=WORLDTRADE_INPUT_MenuCreate(&init,2,0);
    p->state=0;
    p->keepBgLayers=0;
    return 1;
}

/*
 * WorldtradeState-table dispatch through the table at 0x02203BBC.
 */
void WORLDTRADE_DEPOSIT_Main(u8 *p)
{
    g_02203BBC[*(u32 *)(p + 0x28)](p);
}

int WORLDTRADE_DEPOSIT_Exit(WorldtradeWork *p)
{
    WORLDTRADE_DEPOSIT_DeleteActors((WorldtradeWork *)(void *)p);
    WORLDTRADE_INPUT_MenuDelete(p->menu);
    WORLDTRADE_DEPOSIT_DeleteStrings((WorldtradeWork *)p);
    WORLDTRADE_DEPOSIT_DeleteWindows((WorldtradeWork *)p);
    WORLDTRADE_DEPOSIT_ExitBgPlanes();
    WORLDTRADE_TITLE_ExitBgPlanes((WorldtradeWork *)p);
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)*(unsigned *)&p->scrollBarObj), 0);
    WORLDTRADE_AdvanceScreenId((WorldtradeWork *)(void *)p);
    return 0;
}

/*
 * Handle walk: 02045EC0 over the 0xb6c field, the 0xb68/0xb88 pair through
 * 0201F250, then the p+0xd40 window through the 02045334/02045374/
 * 02045730/020409B4 group and a 02202858 redraw with the p+0xfa0 block.
 */
void WORLDTRADE_DEPOSIT_PrintMessage(WorldtradeWork *p, u32 msgId, u32 unused1, u32 unused2, u32 unused3)
{
    u32 v = (uptr)MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&p->bank), msgId);
    struct BmpWin *h;

    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&p->words), (void *)((*(unsigned int *)&p->str)), (void *)v);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->frame)), 0xf);
    h = p->frame;
    BMP_WIN_TransferChars(h);
    BMP_WIN_MakeScreen((struct BmpWin *)h);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
    BMP_MENUWORK_DrawWindow((void *)(p->frame), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(p->frame), 0, (void *)((*(unsigned int *)&p->str)), 0, 0, (u8 *)p + 0xfa0);
    STRBUF_Delete((struct Strbuf *)v);
}

/*
 * Four-layer bring-up with no display restore: layer 2 is seeded by the
 * 02041300 tile dump and its 020409B4 redraw before the enable.
 */
void WORLDTRADE_DEPOSIT_SetupBgPlanes(void)
{
    {
        struct BgTemplate t = g_02202F64;
        BG_SYS_InitBgLayer(0, &t, 0);
    }
    BG_SYS_ClearSlot(0);
    BG_SYS_SetPlaneVisible(0, 1);
    {
        struct BgTemplate t = g_02202F84;
        BG_SYS_InitBgLayer(1, &t, 0);
    }
    BG_SYS_SetPlaneVisible(1, 1);
    {
        struct BgTemplate t = g_02202F44;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x18, 0);
    BG_SYS_PushTile(2);
    BG_SYS_SetPlaneVisible(2, 1);
    {
        struct BgTemplate t = g_02202FA4;
        BG_SYS_InitBgLayer(3, &t, 0);
    }
    BG_SYS_ClearSlot(3);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_InitRun(0, 0x20, 0, 0x48);
    BG_SYS_InitRun(3, 0x20, 0, 0x48);
}

/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void WORLDTRADE_DEPOSIT_ExitBgPlanes(void)
{
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(3);
}

void WORLDTRADE_DEPOSIT_LoadBgGraphics(WorldtradeWork *p)
{
    void *h = ARC_TOOL_CreateHandle(0x60, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x60, 0, 0, 0, 0x40, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1A0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 14, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 31, 11, 0, 0x48);
    ARC_UTIL_UploadBgCharFromArchive(0x60, 9, 1, 0, 0, 1, 0x48);
    ARC_UTIL_UploadBgPaletteFromArchive(0x60, 20, 1, 0, 0x600, 1, 0x48);
    ARC_UTIL_UploadBgCharFromHandle(h, 12, 2, 0, 0, 1, 0x48);
    WORLDTRADE_TITLE_LoadSubBgSwap(p);
    ARC_TOOL_DeleteHandle(h);
}

void WORLDTRADE_DEPOSIT_CreateWindows(WorldtradeWork *p)
{
    void *w;
    int i;
    p->d40 = (void *)BMP_WIN_Create(0, (u8)2, (u8)21, (u8)27, 2, 13, (u16)1);
    BMP_Clear(BMP_WIN_GetBmp(p->d40), 0);
    w = p->d40;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
    for (i = 0; i < 6; i++) {
        p->wins[i] = (void *)BMP_WIN_Create(3, (u8)tbl_02202EC0[i][0], (u8)tbl_02202EC0[i][1], (u8)12, 2, 13, (u16)1);
        BMP_Clear(BMP_WIN_GetBmp(p->wins[i]), 0);
        w = p->wins[i];
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
    }
    WORLDTRADE_TITLE_CreateMenuWindow(p, 3);
}

void WORLDTRADE_DEPOSIT_DeleteWindows(WorldtradeWork *p) { int i; WORLDTRADE_ADAPTER_DeletePrintStream((struct WorldtradeObj *)((struct Actor *)((char *)p+0xfa0))); BMP_WIN_Delete((struct BmpWin *)p->msgWin); for(i=0;i<6;i++) BMP_WIN_Delete((struct BmpWin *)(*(void **)((uptr)(char *)p+(u32)i*4+0xd90))); BMP_WIN_Delete((struct BmpWin *)p->d40); }

/*
 * CLACT_CreateActor returns the object consumed by the subsequent calls and stores.
 * Matched ov135 neighbours prove its pointer request in the fifth slot.
 */
void WORLDTRADE_DEPOSIT_CreateActors(WorldtradeWork *p)
{
    WorldtradeObjPos pos;
    MI_CpuFill8(&pos,0,8);
    pos.x=0xA0;
    pos.y=0x20;
    p->mark=CLACT_CreateActor((struct Unit *)p->res,(uptr)p->set2,(uptr)p->set[1],(uptr)p->set3,(const struct ActorInitParam *)&pos,0,0x48);
    CLACT_SetActorAnimSeq(p->mark,12);
    CLACT_SetActorAutoAnim(p->mark,1);
    CLACT_StopActorAnim(p->mark);
    CLACT_SetActorDrawEnable(p->mark,0);
    pos.x=0xE4;
    pos.y=0x75;
    p->btn[0]=CLACT_CreateActor((struct Unit *)p->res,(uptr)p->set[0],(uptr)p->set[1],(uptr)p->set[2],(const struct ActorInitParam *)&pos,0,0x48);
    CLACT_SetActorAnimSeq(p->btn[0],0x26);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->btn[0],0);
    pos.x=0x8C;
    p->btn[1]=CLACT_CreateActor((struct Unit *)p->res,(uptr)p->set[0],(uptr)p->set[1],(uptr)p->set[2],(const struct ActorInitParam *)&pos,0,0x48);
    CLACT_SetActorAnimSeq(p->btn[1],0x27);
    CLACT_SetActorDrawEnable(p->btn[1],0);
}

/*
 * Release the +0xbf8, +0xd2c and +0xd30 handles.
 */
void WORLDTRADE_DEPOSIT_DeleteActors(WorldtradeWork *p)
{
    CLACT_DeleteActor((struct ClactActor *)((struct Actor *)(p->sub.depositMarkObj)));
    CLACT_DeleteActor((struct ClactActor *)((struct Actor *)((*(unsigned int *)&p->btn[0]))));
    CLACT_DeleteActor((struct ClactActor *)((struct Actor *)((*(unsigned int *)&p->btn[1]))));
}

void WORLDTRADE_DEPOSIT_CreateStrings(WorldtradeWork *p)
{
    p->str = STRBUF_Create(0xB4, 0x48);
    (*(void **)&p->st) = GFL_HEAP_Alloc(0x48, 0x30, 0, g_02203C00, 0x2B4);
    MIi_CpuClearFast(0, (void *)p->st, 0x30);
    ((DepositState *)p->st)->speciesList = WORLDTRADE_DEPOSIT_LoadSpeciesList(0x48, 0, &((DepositState *)p->st)->speciesCount);
    ((DepositState *)p->st)->speciesFlags = WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable(0x48);
    WORLDTRADE_DEPOSIT_ClearListRange((SelTable *)((u8 *)p + 0xEEC));
}

void WORLDTRADE_DEPOSIT_DeleteStrings(WorldtradeWork *p) { GFL_HEAP_Free(((DepositState *)p->st)->speciesFlags); GFL_HEAP_Free(((DepositState *)p->st)->speciesList); GFL_HEAP_Free((void *)p->st); STRBUF_Delete(p->str); }

int WORLDTRADE_DEPOSIT_WaitWipeIn(WorldtradeWork *p) { if(WIPE_SYS_EndCheck()){WORLDTRADE_DEPOSIT_PrintMessage(p,9,1,0,0xf0f);WORLDTRADE_SetNextState(p,16,1);}return 2; }

/*
 * Test bit 1 of the callee result; the odd branch re-latches state 2 before state 3.
 */
int WORLDTRADE_DEPOSIT_StateWaitCancel(WorldtradeWork *p)
{
    u32 v = KEY_GetTrg();

    if (v & 2) {
        WORLDTRADE_SetStateAndReturn(p, 5, 5);
        p->state = 2;
    }
    p->state = 3;
    return 2;
}

/*
 * Hand the buffer at +0xde4 to the writer and stamp state 6.
 */
int WORLDTRADE_DEPOSIT_StateOpenCategoryMenu(WorldtradeWork *p)
{
    WORLDTRADE_INPUT_MenuSetMode((WorldtradeMenu *)((u8 *)((*(unsigned int *)&p->menu))), 0);
    p->state = 6;
    return 2;
}

int WORLDTRADE_DEPOSIT_StateCategoryMenuInput(WorldtradeWork *p)
{
    switch ((unsigned)WORLDTRADE_DEPOSIT_UpdateListMenu(p->speciesMenuList, (u16 *)((u8 *)p + 0xBC))) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        BMP_MENULIST_Delete(p->speciesMenuList, &((DepositState *)p->st)->menuScroll, &((DepositState *)p->st)->menuRow);
        BMP_MENUWORK_Delete(p->de8);
        p->state = 5;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        break;
    case (unsigned)-2:
        BMP_MENULIST_Delete(p->speciesMenuList, &((DepositState *)p->st)->menuScroll, &((DepositState *)p->st)->menuRow);
        BMP_MENUWORK_Delete(p->de8);
        WORLDTRADE_ADAPTER_ClearWindowScreen((p->side_p2[0]), 0);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        BMP_WIN_Delete(p->side_p2[0]);
        BMP_WIN_Delete(p->win3);
        WORLDTRADE_SetStateAndReturn(p, 5, 5);
        p->state = 2;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        break;
    case 0:
        break;
    }
    return 2;
}

int WORLDTRADE_DEPOSIT_StateCreateSpeciesMenu(WorldtradeWork *p)
{
    p->speciesMenuList = WORLDTRADE_DEPOSIT_CreateSpeciesMenuList((WorldtradeWork *)p, (void **)((u8 *)p + 0xDE8), p->win3, p->bank, p->names, (DepositState *)((void *)p->st), p->ctx->zukanSave);
    p->menuChoice = 0xFFFF;
    p->state = 6;
    return 2;
}

/*
 * Map the event code to its state byte: 0, 0xfe and 0xff are accepted.
 */
int WORLDTRADE_DEPOSIT_SetGenderFromEvent(u8 *p, int event)
{
    switch (event) {
    case 0:
        p[2] = 1;
        return 1;
    case 0xfe:
        p[2] = 2;
        return 1;
    case 0xff:
        p[2] = 3;
        return 1;
    }
    return 0;
}

/*
 * lever: signed halfword selection store keeps the unsigned argument truncation after it.
 */
int WORLDTRADE_DEPOSIT_StateSpeciesMenuInput(WorldtradeWork *p)
{
    int result=WORLDTRADE_INPUT_MenuUpdate(p->menu);
    u32 v; uptr h;
    int mode;
    DepositState *target;
    switch(result) {
    case (u32)-2:
        BMP_MENUWORK_DrawWindowBorder(p->d40,0);
        WORLDTRADE_SetStateAndReturn(p,5,5);
        p->state=2;
        target=(DepositState *)p->st;
        WORLDTRADE_DEPOSIT_SetListRangeEntry((SelTable *)((u8 *)p+0xEEC),target->menuScroll+target->menuRow,target->restoreScroll,target->restoreRow);
        break;
    case (u32)-1:
        break;
    default:
        p->wantSpecies=result;
        h=(uptr)POKE_PERSONAL_Create((u16)result,0,0x48);
        v=POKE_PERSONAL_GetParam((struct PersonalData *)h,20);
        POKE_PERSONAL_Delete((void *)h);
        ((DepositState *)p->st)->genderEvent=v;
        if(WORLDTRADE_DEPOSIT_SetGenderFromEvent((u8 *)p+0xB50,((DepositState *)p->st)->genderEvent)) {
            p->state=10;
            mode=p->wantGender;
        } else {
            p->state=7;
            mode=3;
        }
        WORLDTRADE_DEPOSIT_DrawRequestWindow(p->bank,p->names,(sptr)(p->words),(void **)((u8 *)p+0xD90),p->wantSpecies,mode,-1,(u8 *)p+0xFA0);
        target=(DepositState *)p->st;
        WORLDTRADE_DEPOSIT_SetListRangeEntry((SelTable *)((u8 *)p+0xEEC),target->menuScroll+target->menuRow,target->restoreScroll,target->restoreRow);
        break;
    }
    return 2;
}

/*
 * Build through WORLDTRADE_DEPOSIT_PrintMessage and publish the 0x10/0x8 pair.
 */
int WORLDTRADE_DEPOSIT_StatePrintGenderPrompt(WorldtradeWork *p)
{
    WORLDTRADE_DEPOSIT_PrintMessage(p, 0xa, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x10, 0x8);
    return 2;
}

/*
 * Publish the 0xffff sentinel at +0xbc and the u32 at +0xde4, then latch state 9.
 */
int WORLDTRADE_DEPOSIT_StateOpenGenderMenu(WorldtradeWork *p)
{
    p->menuChoice = 0xffff;
    WORLDTRADE_INPUT_MenuSetMode((WorldtradeMenu *)((u8 *)((*(unsigned int *)&p->menu))), 1);
    p->state = 9;
    return 2;
}

int WORLDTRADE_DEPOSIT_StateGenderMenuInput(WorldtradeWork *p)
{
    unsigned result = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    switch (result) {
    case (unsigned)-2:
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        p->state = 0;
        break;
    case 0: case 1: case 2:
        p->wantGender = result + 1;
        p->state = 10;
        WORLDTRADE_DEPOSIT_DrawRequestWindow(p->bank, p->names, (sptr)(p->words), (void **)((u8 *)p + 0xD90), p->wantSpecies, p->wantGender, -1, (u8 *)p + 0xFA0);
        break;
    }
    return 2;
}

int WORLDTRADE_DEPOSIT_StatePrintLevelPrompt(WorldtradeWork *p)
{
    WORLDTRADE_DEPOSIT_PrintMessage(p, 0xb, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x10, 0xb);
    return 2;
}

/*
 * Publish the u32 at +0xde4, the 0xffff sentinel at +0xbc and latch state 0xc.
 */
int WORLDTRADE_DEPOSIT_StateOpenLevelMenu(WorldtradeWork *p)
{
    WORLDTRADE_INPUT_MenuSetMode((WorldtradeMenu *)((u8 *)((*(unsigned int *)&p->menu))), 2);
    p->menuChoice = 0xffff;
    p->state = 0xc;
    return 2;
}

int WORLDTRADE_DEPOSIT_StateLevelMenuInput(WorldtradeWork *p)
{
    unsigned result = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    switch (result) {
    case 12: case (unsigned)-2:
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        if (WORLDTRADE_DEPOSIT_SetGenderFromEvent((u8 *)p + 0xB50, ((DepositState *)p->st)->genderEvent)) {
            p->state = 0;
        } else {
            p->state = 7;
        }
        break;
    case (unsigned)-1:
        break;
    default:
        WORLDTRADE_DEPOSIT_GetLevelBracket((u8 *)p + 0xB50, result, 0);
        p->state = 13;
        result = WORLDTRADE_DEPOSIT_FindLevelBracketIndex(p->wantLevelMin, p->wantLevelMax, 0);
        WORLDTRADE_DEPOSIT_DrawRequestWindow(p->bank, p->names, (sptr)(p->words), (void **)((u8 *)p + 0xD90), p->wantSpecies, p->wantGender, result, (u8 *)p + 0xFA0);
        break;
    }
    return 2;
}

int WORLDTRADE_DEPOSIT_StatePrintConfirmPrompt(WorldtradeWork *p)
{
    WORLDTRADE_DEPOSIT_PrintMessage(p, 0x17, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x10, 0xe);
    return 2;
}

/*
 * WorldtradeState setter: build with the fixed 0x14/0x126/0x3/0x0 argument pair and latch state 0xf.
 */
int WORLDTRADE_DEPOSIT_StateOpenConfirmYesNo(WorldtradeWork *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((WorldtradeWork *)((uptr)p), 0x14, 0x126, 0x3, 0x0);
    p->state = 0xf;
    return 2;
}

int WORLDTRADE_DEPOSIT_StateConfirmYesNoInput(WorldtradeWork *p)
{
    int result;
    result = WORLDTRADE_UpdateTaskMenuYesNo(p);
    if (result == 1) {
        WORLDTRADE_CloseTaskMenu(p);
        WORLDTRADE_SetStateAndReturn(p, 7, 7);
        p->state = 2;
        p->eb4 = 1;
        WORLDTRADE_DEPOSIT_StoreOfferInWork((Deposit *)&p->single, p);
    } else if (result == 2) {
        WORLDTRADE_CloseTaskMenu(p);
        WORLDTRADE_SetStateAndReturn(p, 5, 5);
        p->state = 2;
    }
    return 2;
}

int WORLDTRADE_DEPOSIT_StateStartWipeOut(WorldtradeWork *p)
{
    if (p->nextScreenId == 0) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
        p->eb4 = 1;
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 3;
}

/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int WORLDTRADE_DEPOSIT_StateWaitMessage(WorldtradeWork *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy(&p->printCtx) == 0) {
        p->state = p->returnState;
    }
    return 2;
}

/*
 * Mode table: 0 -> 0x14c0, 1 -> 0xc80, anything else 0.
 */
u16 WORLDTRADE_DEPOSIT_GetModeColor(int mode)
{
    switch (mode) {
    case 0:
        return 0x53 << 6;
    case 1:
        return 0x32 << 6;
    default:
        return 0;
    }
}

void WORLDTRADE_DEPOSIT_PrintName(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *printer)
{
    void *str;

    if (index != 0) {
        str = MSGDATA_AllocString(bank, index);
        WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, 0, x, y, color, printer);
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_PrintBankString(void *win, void *bank, u32 index, u32 y, u16 color, void *printer)
{
    void *str;

    if (index != 0) {
        str = MSGDATA_AllocString(bank, index);
        WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, 0, y, 0, color, printer);
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_PrintMessageLine(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *printer)
{
    void *str;

    if (index != 0) {
        str = MSGDATA_AllocString(bank, index);
        WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, 0, x, y, color, printer);
        STRBUF_Delete(str);
    } else {
        str = MSGDATA_AllocString(bank2, 0xBB);
        WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, 0, x, y, color, printer);
        STRBUF_Delete(str);
    }
}

u16 WORLDTRADE_DEPOSIT_GetModeFontColor(int mode, u16 color)
{
    if (mode == 1) {
        return WORLDTRADE_DEPOSIT_GetModeColor(0);
    }
    if (mode == 2) {
        color = WORLDTRADE_DEPOSIT_GetModeColor(1);
    }
    return color;
}

void WORLDTRADE_DEPOSIT_PrintModeLabelAligned(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *printer)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = MSGDATA_AllocString(bank, tbl_02202EB0[mode]);
        if (y > 3) {
            WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, y, x, 0, WORLDTRADE_DEPOSIT_GetModeFontColor(mode, color), printer);
        } else {
            WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, 0, x, y, WORLDTRADE_DEPOSIT_GetModeFontColor(mode, color), printer);
        }
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_PrintModeLabel(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *printer)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = MSGDATA_AllocString(bank, tbl_02202EB0[mode]);
        WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, x, y, 0, WORLDTRADE_DEPOSIT_GetModeFontColor(mode, color), printer);
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_PrintLevelRange(void *win, void *bank, int idx, u32 align, u32 y, u16 color, int alt, void *printer)
{
    WORLDTRADE_DEPOSIT_PrintConditionLabel(win, bank, idx, align, 0, y, color, alt, (uptr)printer);
}

void WORLDTRADE_DEPOSIT_PrintConditionLabel(void *win, void *bank, int idx, u32 align, u32 x, u32 y, u16 color, int alt, u32 printer)
{
    const WorldtradeTableRow *tab;
    void *str;

    if (idx != -1) {
        tab = tbl_0220301C;
        if (alt != 0) {
            tab = tbl_02202FC4;
        }
        str = MSGDATA_AllocString(bank, tab[idx].id);
        WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, x, y, align, color, (void *)printer);
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_DrawRequestWindow(void *bank, void *names, int unused, void **win, u32 index, int mode, int place, void *printer)
{
    int i;
    void *str;
    int show = 1;
    str = MSGDATA_AllocString(bank, 0x6b);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], str, 1, 0, 0, 0x440, printer);
    for (i = 1; i < 3; i++)
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
    WORLDTRADE_DEPOSIT_PrintName(win[1], names, index, 0, 0, 0x440, printer);
    if (index == 29 && mode == 2)
        show = 0;
    else if (index == 32 && mode == 1)
        show = 0;
    if (show) {
        if (mode == 1 || mode == 2)
            WORLDTRADE_DEPOSIT_PrintModeLabelAligned(win[1], bank, mode, 0, 0, 70, 0x440, printer);
    }
    WORLDTRADE_DEPOSIT_PrintLevelRange(win[2], bank, place, 2, 0, 0x440, 0, printer);
    STRBUF_Delete(str);
}

void WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(void *bank, void *names, void *unused, void **win, u32 index, int mode, int place, void *printer)
{
    int i;
    void *str;
    int show = 1;
    str = MSGDATA_AllocString(bank, 0x6b);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], str, 0, 0, 0, 0x440, printer);
    for (i = 1; i < 3; i++)
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
    WORLDTRADE_DEPOSIT_PrintName(win[1], names, index, 0, 0, 0x440, printer);
    if (index == 29 && mode == 2)
        show = 0;
    else if (index == 32 && mode == 1)
        show = 0;
    if (show) {
        if (mode == 1 || mode == 2)
            WORLDTRADE_DEPOSIT_PrintModeLabelAligned(win[1], bank, mode, 0, 0, 70, 0x440, printer);
    }
    WORLDTRADE_DEPOSIT_PrintLevelRange(win[2], bank, place, 0, 0, 0x440, 0, printer);
    STRBUF_Delete(str);
}

void WORLDTRADE_DEPOSIT_PrintMonSummary(void *bank, void *ws, void **win, void *mon, MonTag *out, void *printer)
{
    int i;
    int form;
    void *title;
    void *place;
    void *name;
    void *tmp;
    u32 has;
    u32 level;

    name = STRBUF_Create(0xB, 0x48);
    tmp = STRBUF_Create(0xB, 0x48);
    POKE_TOOL_GetBoxValue(mon, 0x73, (uptr)name);
    form = POKE_TOOL_GetBoxValue(mon, 0x6E, 0) + 1;
    level = POKE_TOOL_CalcBoxLevel(mon);
    has = POKE_TOOL_GetBoxValue(mon, 0xAD, 0);
    title = MSGDATA_AllocString(bank, 0x6E);
    WORDSET_SetSlotNumber(ws, 3, level, 3, 0, 1);
    place = (void *)WORLDTRADE_ADAPTER_CreateString((uptr)ws, (uptr)bank, 0x72, 0x48);
    if (form != 3) {
        MSGDATA_ReadString(bank, tbl_02202EB0[form], tmp);
    }
    for (i = 0; i < 3; i++) {
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
    }
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], title, 1, 0, 0, 0x3C40, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[1], name, 0, 0, 0, 0x3C40, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[2], place, 0, 0, 2, 0x3C40, printer);
    if (form != 3 && has != 0) {
        WORLDTRADE_INPUT_PrintStringAlignedLine(win[1], tmp, 0x46, 0, 0, WORLDTRADE_DEPOSIT_GetModeColor(form - 1), printer);
    }
    out->species = POKE_TOOL_GetBoxValue(mon, 5, 0);
    out->form = form;
    out->level = level;
    STRBUF_Delete(place);
    STRBUF_Delete(tmp);
    STRBUF_Delete(name);
    STRBUF_Delete(title);
}

u16 *WORLDTRADE_DEPOSIT_LoadSpeciesList(u32 heap, u32 unused, u32 *count)
{
    u32 size;
    u16 *list;

    list = (u16 *)ARC_UTIL_LoadMemberWithSize(0x62, 5, 0, (u16)heap, &size);
    *count = size / 2;
    return list;
}

void WORLDTRADE_DEPOSIT_GetSpeciesRange(u32 kind, int *start, int *end)
{
    if (kind >= 0x1B) {
        GF_PANIC_Fail((void *)0x02203C18, 0, (void *)0x02203C18);
    }
    *start = tbl_0220307C[kind];
    *end = tbl_0220307C[kind + 1];
}

u8 *WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable(u32 id)
{
    u32 size;
    u32 i;
    u8 *buf;
    u16 *tbl;
    u32 n;

    buf = GFL_HEAP_Alloc(0x48, 0x28A, 0, (const char *)g_02203C00, 0x796);
    MIi_CpuClearFast(0, buf, 0x28A);
    tbl = (u16 *)ARC_UTIL_LoadMemberWithSize(0x62, 4, 0, (u16)id, &size);
    n = size / 2;
    for (i = 0; i < n; i++) {
        if (tbl[i] < 0x28A) {
            buf[tbl[i]] = 1;
        }
    }
    GFL_HEAP_Free(tbl);
    return buf;
}

void WORLDTRADE_DEPOSIT_BuildOffer(WorldtradeEntry *dst, WorldtradeWork *p)
{
    u32 species;

    if (WORLDTRADE_BOX_IsPartyBox(p->box) != 0) {
        species = POKE_TOOL_GetBoxValue(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            POKE_TOOL_ChangeForm(p->mon, 0);
        }
        MIi_CpuCopyFast(p->mon, dst, POKE_TOOL_GetPartyParamSize());
    } else {
        species = POKE_TOOL_GetBoxValue(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            POKE_TOOL_ChangeBoxForm(p->mon, 0);
        }
        WORLDTRADE_ADAPTER_CopyBoxMon(p->mon, (uptr)dst);
    }
    WORDSET_CopyString(MYSTATUS_GetName(p->ctx->myStatus), (u16 *)dst->name, 8);
    dst->trainerId = MYSTATUS_GetId(p->ctx->myStatus);
    dst->nation = MYSTATUS_GetNation(p->ctx->myStatus);
    dst->area = MYSTATUS_GetArea(p->ctx->myStatus);
    dst->trainerView = MYSTATUS_GetTrainerView(p->ctx->myStatus);
    dst->sex = MYSTATUS_GetSex(p->ctx->myStatus);
    dst->romCode = PM_VERSION_ID;
    dst->language = 2;
    dst->greetingSet = WIFI_HISTORY_GetGreetingSet(p->ctx->wifiHistory);
    dst->visitedCountryCount = WIFI_HISTORY_GetVisitedCountryCount(p->ctx->wifiHistory);
    dst->ratingLevel = WIFI_HISTORY_GetRatingLevel(p->ctx->wifiHistory);
}

void WORLDTRADE_DEPOSIT_StoreOfferInWork(Deposit *dst, WorldtradeWork *p)
{
    WORLDTRADE_DEPOSIT_BuildOffer((WorldtradeEntry *)dst, (WorldtradeWork *)p);
    dst->have.species = p->haveSpecies;
    *(u16 *)&dst->have.form = p->haveFormGender;
    dst->want.species = (*(unsigned short *)&p->wantSpecies);
    *(u16 *)&dst->want.form = p->wantGenderLevelMin;
    *(u16 *)&dst->want.levelMax = p->wantLevelMaxPair;
}

int WORLDTRADE_DEPOSIT_CreateSpeciesMenu(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag)
{
    int i;
    int size;
    int count;
    int start;
    count = 0;
    start = tbl_02203B84[kind];
    size = tbl_02203B84[kind + 1] - start;
    for (i = 0; i < size; i++) {
        if (ZUKAN_SAVE_IsSeen(bag, list[start + i]) != 0) count++;
    }
    *menu = BMP_MENUWORK_Create(count + 1, 0x48);
    for (i = 0; i < size; i++) {
        if (ZUKAN_SAVE_IsSeen(bag, list[start + i]) != 0) {
            BMP_MENUWORK_AddMsgItem((BmpMenuWork *)*menu, (struct MsgBank *)((uptr)msg), list[start + i], list[start + i], 0x48);
        }
    }
    BMP_MENUWORK_AddMsgItem((BmpMenuWork *)*menu, (struct MsgBank *)((uptr)endmsg), 0x85, -2, 0x48);
    return count + 1;
}

/*
 * lever: u16 arrays at 0xEF0 and 0xF04 preserve base/index load scheduling; raw offset casts differ by 8 bytes.
 */
void *WORLDTRADE_DEPOSIT_CreateSpeciesMenuList(WorldtradeWork *p, void **menu, void *win, void *endmsg, void *msg, DepositState *cfg, void *bag)
{
    int kind;
    int count;
    MenuSrc src;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    kind = cfg->menuScroll + cfg->menuRow;
    count = WORLDTRADE_DEPOSIT_CreateSpeciesMenu(menu, msg, endmsg, cfg->speciesList, (uptr)cfg->speciesFlags, cfg->speciesCount, kind, bag);
    src = d_02202ED8;
    src.count = count;
    src.ptrs[0] = (uptr)*menu;
    src.ptrs[3] = (uptr)win;
    BMP_MENUWORK_DrawWindow((struct BmpWin *)win, 0, 31, 11);
    return BMP_MENULIST_Create((struct BmpMenuListTemplate *)((struct MenuTemplate *)(&src)), p->a[kind], p->b[kind], 0x48);
}

int WORLDTRADE_DEPOSIT_CreateGenderMenu(void **menu, void *msg, int kind)
{
    const WorldtradeTableRow *table;
    int i;
    int count;
    if (kind == 0) { table = tbl_0220301C; count = 12; }
    else { table = tbl_02202FC4; count = 11; }
    *menu = BMP_MENUWORK_Create(count, 0x48);
    for (i = 0; i < count; i++) {
        BMP_MENUWORK_AddMsgItem((BmpMenuWork *)*menu, (struct MsgBank *)((uptr)msg), table[i].id, i, 0x48);
    }
    return count;
}

void WORLDTRADE_DEPOSIT_GetLevelBracket(u8 *dst, int index, int kind)
{
    const WorldtradeTableRow *table;
    if (kind == 0) {
        table = tbl_0220301C;
        if (index >= 12) GF_PANIC_Fail(str_02203C18, 0, str_02203C18);
    } else {
        table = tbl_02202FC4;
        if (index >= 11) GF_PANIC_Fail(str_02203C18, 0, str_02203C18);
    }
    dst[3] = table[index].x;
    dst[4] = table[index].y;
}

/*
 * Index of a key/value pair in one of two s16 tables.
 */
int WORLDTRADE_DEPOSIT_FindLevelBracketIndex(int key, int val, int which)
{
    int i;
    int n;
    const WorldtradeTableRow *tab;

    if (which == 0) {
        tab = tbl_0220301C;
        n = 0xc;
    } else {
        tab = tbl_02202FC4;
        n = 0xb;
    }
    for (i = 0; i < n; i++) {
        if (tab[i].key == key && tab[i].val == val) {
            return i;
        }
    }
    return 0;
}

typedef struct {
    u8 start;
    u8 id;
} IdRange;



void WORLDTRADE_DEPOSIT_SetCountryFilter(WorldtradeWork *p,u32 n);

int WORLDTRADE_DEPOSIT_GetListRange(u32 id, u32 *start);

int WORLDTRADE_DEPOSIT_CreateListMenu(void **menu, void *msg, int id);

extern const u16 d_022030E8[];

extern const IdRange tbl_02202F0C[];

extern u16 tbl_022030E8[];

void WORLDTRADE_DEPOSIT_SetCountryFilter(WorldtradeWork *p,u32 index) { if(index==0){p->countryFilter=0;return;}index--;if(index<130)p->countryFilter=d_022030E8[index]; }

int WORLDTRADE_DEPOSIT_GetListRange(u32 id, u32 *start)
{
    int i;

    for (i = 0; i < 28; i++) {
        if (id == tbl_02202F0C[i].id) {
            *start = tbl_02202F0C[i].start;
            return tbl_02202F0C[i + 1].start - tbl_02202F0C[i].start;
        }
    }
    return 0;
}

#pragma opt_common_subs off

/*
 * Builds a message menu: reads the entry range for an id, allocates the table
 * and fills one slot per entry. The slot call takes five arguments (heap id
 * 0x48 on the stack), as in the other matched callers of BMP_MENUWORK_AddMsgItem (the
 * arm9 definition lists four parameters; the fifth is passed but not read).
 * Closed with opt_common_subs off: the original does not share start + i
 * between the table index and the tag. 2026-10-05 (P21): plain form 16 bytes
 * off, only that pragma closes it. Table extern is not const (const gave 18).
 */
int WORLDTRADE_DEPOSIT_CreateListMenu(void **menu, void *msg, int id)
{
    int i;
    int count;
    u32 start;
    count = WORLDTRADE_DEPOSIT_GetListRange(id, &start);
    *menu = BMP_MENUWORK_Create(count, 0x48);
    for (i = 0; (i < count) ? 1 : 0; i++) {
        BMP_MENUWORK_AddMsgItem((BmpMenuWork *)*menu, (struct MsgBank *)((uptr)msg), tbl_022030E8[start + i], start + i + 1, 0x48);
    }
    return count;
}

#pragma opt_common_subs reset

int WORLDTRADE_DEPOSIT_UpdateListMenu(void *p, u16 *old)
{
    u16 current;
    int result;
    result = BMP_MENULIST_Main(p);
    BMP_MENULIST_GetListIndex(p, &current);
    if (*old != current) {
        if (*old != 0xFFFF) GFL_USE_PlaySeDefaultVolume(0x548);
        *old = current;
    }
    return result;
}

/*
 * Clear the two ten-entry u16 tables at +4 and +0x18 and the two header words.
 */
void WORLDTRADE_DEPOSIT_ClearListRange(SelTable *p)
{
    int i;
    u16 zero = 0;

    for (i = 0; i < 10; i++) {
        p->a[i] = zero;
        p->b[i] = zero;
    }
    p->reserved00 = zero;
    p->reserved02 = zero;
}

/*
 * Store a pair of u16 values at +4 and +0x18 of record i.
 */
void WORLDTRADE_DEPOSIT_SetListRangeEntry(SelTable *p, int index, u16 restoreScroll, u16 restoreRow)
{
    p->a[index] = restoreScroll;
    p->b[index] = restoreRow;
}
