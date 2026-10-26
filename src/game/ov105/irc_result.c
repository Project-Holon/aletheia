/*
 * file:     irc_result.c
 * unit:     yes
 * function: IRC_RESULT_Init, IRC_RESULT_Exit, IRC_RESULT_Main, IRC_RESULT_InitScreen, IRC_RESULT_ExitScreen, IRC_RESULT_DrawScreen, IRC_RESULT_GetScreenActor, IRC_RESULT_GetScreenActorUnit, IRC_RESULT_ScreenVBlankTask, IRC_RESULT_InitBackgrounds, IRC_RESULT_ExitBackgrounds, IRC_RESULT_VBlankBackgrounds, IRC_RESULT_InitActorSystem, IRC_RESULT_ExitActorSystem, IRC_RESULT_DrawActorSystem, IRC_RESULT_VBlankActorSystem, IRC_RESULT_GetActor, IRC_RESULT_GetActorUnit, IRC_RESULT_InitTextSystem, IRC_RESULT_ExitTextSystem, IRC_RESULT_RunPrintQueue, IRC_RESULT_GetFont, IRC_RESULT_GetPrintQueue, IRC_RESULT_GetMessages, IRC_RESULT_GetWordSet, IRC_RESULT_InitMessageWindow, IRC_RESULT_InitTextWindow, IRC_RESULT_ExitTextWindow, IRC_RESULT_UpdateTextWindow, IRC_RESULT_PrintMessage, IRC_RESULT_PrintCenteredMessage, IRC_RESULT_PrintMessageWithNumber, IRC_RESULT_PrintMessageWithNames, IRC_RESULT_PrintRewardMessage, IRC_RESULT_SetState, IRC_RESULT_Finish, IRC_RESULT_StateStart, IRC_RESULT_StateShowScore, IRC_RESULT_StateEnd, IRC_RESULT_InitScoreDisplay, IRC_RESULT_ShowDigit, IRC_RESULT_UpdateScoreDisplay, IRC_RESULT_IsDigitShown, IRC_RESULT_SetScoreDigits, IRC_RESULT_InitRankFade, IRC_RESULT_ExitRankFade, IRC_RESULT_UpdateRankFade, IRC_RESULT_StartRankFade, IRC_RESULT_IsRankFadeFinished, IRC_RESULT_BlendPaletteEntry, IRC_RESULT_GetScoreRank, IRC_RESULT_GetRewardQuantity, IRC_RESULT_GiveReward
 * address:  0x021B7560
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BG_SYS_ChangeScale 0x02041F6C arm
 *   BG_SYS_ChangeCenter 0x02041FB0 arm
 *   COMPATIBLE_IRC_SYS_BuildProfile 0x021B658C thumb ov101
 *   IRC_APPBAR_Create 0x021B70DC thumb ov101
 *   IRC_APPBAR_SetEnabled 0x021B728C thumb ov101
 *   IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 *   COMPATIBLE_IRC_SYS_UpdateValueSync 0x021B63D0 thumb ov101
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   sResultVramBankConfig 0x021B89D8 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   sResultDisplayConfig 0x021B8964 data ov105 a4
 *   sResultBackgroundLayers 0x021B89B8 data a4
 *   sResultBackgroundTemplates 0x021B8A08 data ov105 a4
 *   sResultBackgroundTypes 0x021B8998 data ov105 a4
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_SetSlotFromBank 0x0201EF6C thumb
 *   IRC_RESULT_GiveReward 0x021B8860 thumb ov105
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   sResultPowersOfTen 0x021B8974 data a4
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   sResultRankFadeRows 0x021B8984 data a1
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   IRC_RANKING_GetFromSave  0x0200A8A0  thumb  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb  arm9
 *   PRINTSYS_CountLines  0x0201D42C  thumb  arm9
 *   MSGDATA_CreateFromArchive  0x02045B38  arm  arm9
 *   IRC_RANKING_IsEntryNew  0x0200A9A4  thumb  arm9
 *   IRC_RANKING_AddEntry  0x0200AA68  thumb  arm9
 *   MYITEM_SAVEDATA_AddItem  0x02007E50  thumb  arm9
 *   MYITEM_SAVEDATA_GetItemQuantity  0x02007FB8  thumb  arm9
 *   MYSTATUS_GetName  0x020084F4  thumb  arm9
 *   MYSTATUS_GetId  0x02008530  thumb  arm9
 *   MYSTATUS_GetSex  0x02008550  thumb  arm9
 *   RECORD_AddOne  0x02008DF0  thumb  arm9
 *   GAMESYSTEM_GetGameData       0x020120F4  thumb
 *   GAME_DATA_GetMyItem          0x0201292C  thumb
 *   GAME_DATA_GetSaveControl     0x02012EBC  thumb
 */
#include "irc_result_types.h"
#include "../arm9/clact.h"

/*
 * Infrared compatibility check, result screen.  Shows the score of the
 * check as three digits, lights the rank bars, plays the jingle of the rank
 * and prints a comment chosen by the score.  A first-time partner also gives
 * a reward item and is entered in the ranking save data.
 */

/* sound effects and music */
#define IRC_RESULT_SE_DIGITS        0x653
#define IRC_RESULT_SE_RANK_FADE_IN  2000
#define IRC_RESULT_SE_RANK_FADE_OUT 1998
#define IRC_RESULT_BGM_RANK_5       0x527
#define IRC_RESULT_BGM_RANK_4       0x528
#define IRC_RESULT_BGM_OTHER        0x529

/* message numbers of the game's message bank */
#define IRC_RESULT_MSG_NAMES            0
#define IRC_RESULT_MSG_TITLE            1
#define IRC_RESULT_MSG_SCORE_FIRST      2     /* 2 to 12, by score */
#define IRC_RESULT_MSG_SCORE_LAST       12
#define IRC_RESULT_MSG_REWARD           13
#define IRC_RESULT_MSG_REWARD_BONUS     14
#define IRC_RESULT_MSG_BAG_FULL         15

#define IRC_RESULT_REWARD_ITEM          134
#define IRC_RESULT_REWARD_MAX           999
#define IRC_RESULT_TRAINER_RECORD       113

/* results of IRC_RESULT_GiveReward */
#define IRC_RESULT_REWARD_GIVEN         0
#define IRC_RESULT_REWARD_NONE          1
#define IRC_RESULT_REWARD_BAG_FULL      2

struct Proc;
struct ClactActor;
struct Unit;
struct GfFont;
struct DispConfig;
struct Cfg;
struct Descriptor;
struct CharBuf;
struct U16Vec;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct StrObj;
struct Node;
struct BgTemplate;
struct SaveControl;
struct ItemBag;
struct TrainerRecord;

/* screen offset passed to CLACT_AddActorSurfacePos */



typedef struct IrcPaletteFile {
    u8 header[12];
    u8 *colors;
} IrcPaletteFile;

typedef struct IrcRankFadeRow {
    u8 index[2];
    u8 count;
} IrcRankFadeRow;

#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
struct GameSystem;
struct GameComm;
#include "../arm9/gamesystem.h"
struct BmpWin;
#include "../arm9/bmp_menuwork.h"
#include "../arm9/bg_sys.h"
#include "../ov101/compatible_irc_sys.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/fade.h"
struct DispVram;
struct TcbTask;
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/bmp_win.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
struct DispVramCfg;
struct ClactActor;
#include "../arm9/gf_font.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/msgdata.h"
#include "../arm9/wordset.h"
struct Strbuf;
#include "../arm9/strbuf.h"
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/touchpanel.h"
#include "../arm9/gfl_use.h"
#include "../arm9/nns_gfd_vram_transfer.h"
struct GameData;

#include "../arm9/game_data.h"
struct IrcRankSave;
#include "../arm9/irc_ranking.h"
struct MyStatus;
#include "../arm9/mystatus.h"
struct IrcRankEntry;
struct MyItem;
#include "../arm9/myitem_savedata.h"
#include "../arm9/record.h"

int IRC_RESULT_Init(struct Proc *proc,void *state,IrcResultContext *context);
int IRC_RESULT_Exit(struct Proc *proc,int unused1,int unused2,IrcResult *work);
int IRC_RESULT_Main(void *proc,u32 *state,void *unused,IrcResult *work);
void IRC_RESULT_InitScreen(IrcResultScreen *screen,u16 heapId);
void IRC_RESULT_ExitScreen(IrcResultScreen *screen);
void IRC_RESULT_DrawScreen(IrcResultScreen *screen);
struct ClactActor *IRC_RESULT_GetScreenActor(IrcResultScreen *screen, int index);
struct Unit *IRC_RESULT_GetScreenActorUnit(IrcResultScreen *screen);
void IRC_RESULT_ScreenVBlankTask(struct TcbTask *task, void *screen);
void IRC_RESULT_InitBackgrounds(IrcResultScreen *screen,u16 heapId);
void IRC_RESULT_ExitBackgrounds(u32 *bgCharRegion);
void IRC_RESULT_VBlankBackgrounds(void *unused);
void IRC_RESULT_InitActorSystem(IrcResultActorSystem *sys,const void *config,u16 heapId);
void IRC_RESULT_ExitActorSystem(IrcResultActorSystem *sys);
void IRC_RESULT_DrawActorSystem(void *unused);
void IRC_RESULT_VBlankActorSystem(void *unused);
struct ClactActor *IRC_RESULT_GetActor(IrcResultActorSystem *sys, int index);
struct Unit *IRC_RESULT_GetActorUnit(IrcResultActorSystem *sys);
void IRC_RESULT_InitTextSystem(IrcTextSystem *text, int fontStyle, u16 heapId);
void IRC_RESULT_ExitTextSystem(IrcTextSystem *text);
u32 IRC_RESULT_RunPrintQueue(IrcTextSystem *text);
void *IRC_RESULT_GetFont(IrcTextSystem *text);
void *IRC_RESULT_GetPrintQueue(IrcTextSystem *text);
void *IRC_RESULT_GetMessages(IrcTextSystem *text);
void *IRC_RESULT_GetWordSet(IrcTextSystem *text);
void IRC_RESULT_InitMessageWindow(IrcTextWindow *win, u32 layer, u32 x, u8 y, u8 width, u8 height, u8 paletteNo, u16 heapId);
void IRC_RESULT_InitTextWindow(IrcTextWindow *win,u32 layer,u32 x,u8 y,u8 width,u8 height,u8 paletteNo,u16 clearColor,u8 slot,u16 heapId);
void IRC_RESULT_ExitTextWindow(IrcTextWindow *win);
int IRC_RESULT_UpdateTextWindow(IrcTextWindow *win,IrcTextSystem *text);
void IRC_RESULT_PrintMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId,int x,s16 y);
void IRC_RESULT_PrintCenteredMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId);
void IRC_RESULT_PrintMessageWithNumber(IrcTextWindow *win, IrcTextSystem *text, u8 msgId, u16 number, u16 slot);
void IRC_RESULT_PrintMessageWithNames(IrcTextWindow *win, IrcTextSystem *text, int msgId, IrcCompatibleProfile *own, IrcCompatibleProfile *partner, int unused);
void IRC_RESULT_PrintRewardMessage(IrcTextWindow *win, IrcTextSystem *text, IrcCompatibleProfile *own, unsigned quantity, int msgId);
void IRC_RESULT_SetState(IrcResult *work, IrcResultStateFn fn);
void IRC_RESULT_Finish(IrcResult *work);
void IRC_RESULT_StateStart(IrcResult *work,u16 *step);
void IRC_RESULT_StateShowScore(IrcResult *work,u16 *step);
void IRC_RESULT_StateEnd(IrcResult *work,u16 *step);
void IRC_RESULT_InitScoreDisplay(IrcResultScoreDisplay *display,IrcResultScreen *screen,int score);
void IRC_RESULT_ShowDigit(IrcResultScoreDisplay *display, int i);
int IRC_RESULT_UpdateScoreDisplay(IrcResultScoreDisplay *display);
int IRC_RESULT_IsDigitShown(IrcResultScoreDisplay *display,int i);
void IRC_RESULT_SetScoreDigits(IrcResultScoreDisplay *display, unsigned score);
void IRC_RESULT_InitRankFade(IrcResultRankFade *fade,int id,int score,u16 heapId);
void IRC_RESULT_ExitRankFade(IrcResultRankFade *fade);
void IRC_RESULT_UpdateRankFade(IrcResultRankFade *fade);
void IRC_RESULT_StartRankFade(IrcResultRankFade *fade);
unsigned IRC_RESULT_IsRankFadeFinished(IrcResultRankFade *fade);
void IRC_RESULT_BlendPaletteEntry(u16 *color,int n,u8 div,u8 paletteBank,u8 colorIndex,u16 from,u16 to);
int IRC_RESULT_GetScoreRank(unsigned score, int *nearNextRank);
unsigned int IRC_RESULT_GetRewardQuantity(unsigned int score,int bonusDay);
int IRC_RESULT_GiveReward(IrcResult *work);

extern const u8 sResultVramBankConfig[];
extern const u8 sResultDisplayConfig[],sResultBackgroundTemplates[];
extern const int sResultBackgroundLayers[],sResultBackgroundTypes[];
extern const u8 gClActorInitParam[];
extern const unsigned sResultPowersOfTen[];
extern const IrcRankFadeRow sResultRankFadeRows[];

int IRC_RESULT_Init(struct Proc *proc,void *state,IrcResultContext *context)
{
    IrcCompatibleProfile profileForNames,profileForBonus;
    IrcResult *work;
    struct Unit *unit;
    void *font,*printQueue;
    GFL_HEAP_CreateChildHeap(1,60,0x20000);
    work=PROCSYS_AllocProcWork(proc,sizeof(*work),60);
    MI_CpuFill8(work,0,sizeof(*work));
    work->context=context;
    IRC_RESULT_InitScreen(&work->screen,60);
    IRC_RESULT_InitTextSystem(&work->text,0,60);
    if(work->context->gameSystem) GAMESYSTEM_GetGameComm(work->context->gameSystem);
    IRC_RESULT_InitMessageWindow(&work->messageWindow,5,1,18,30,5,5,60);
    BMP_MENUWORK_DrawWindow(work->messageWindow.window,0,(u16)(work->screen.bgCharRegion),6);
    IRC_RESULT_InitTextWindow(&work->captionWindow,7,6,3,20,5,8,1,1,60);
    IRC_RESULT_PrintCenteredMessage(&work->captionWindow,&work->text,IRC_RESULT_MSG_TITLE);
    BG_SYS_ChangeScale(7,3,4096);
    BG_SYS_ChangeScale(7,6,4096);
    BG_SYS_ChangeCenter(7,9,128);
    BG_SYS_ChangeCenter(7,12,40);
    IRC_RESULT_InitScoreDisplay(&work->scoreDisplay,&work->screen,work->context->score);
    if(work->context->gameSystem) {
        COMPATIBLE_IRC_SYS_BuildProfile(work->context->gameSystem,&profileForNames);
        IRC_RESULT_PrintMessageWithNames(&work->messageWindow,&work->text,IRC_RESULT_MSG_NAMES,&profileForNames,work->context->partner,60);
    }
    unit=IRC_RESULT_GetScreenActorUnit(&work->screen);
    font=IRC_RESULT_GetFont(&work->text);
    printQueue=IRC_RESULT_GetPrintQueue(&work->text);
    work->appBar=IRC_APPBAR_Create(2,unit,0,13,13,2,font,printQueue,60);
    IRC_APPBAR_SetEnabled(work->appBar,0);
    IRC_RESULT_InitRankFade(&work->rankFade,3,work->context->score,60);
    if(work->context->gameSystem) {
        COMPATIBLE_IRC_SYS_BuildProfile(work->context->gameSystem,&profileForBonus);
        if(profileForBonus.isDay14 && work->context->partner->isDay14) work->bonusDay=1;
        else work->bonusDay=0;
        work->rewardQuantity=IRC_RESULT_GetRewardQuantity(work->context->score,work->bonusDay);
    }
    IRC_RESULT_SetState(work,IRC_RESULT_StateStart);
    return 1;
}

/*
 * extent: Two zero alignment bytes after return, before 021B7778.
 */
int IRC_RESULT_Exit(struct Proc *proc,int unused1,int unused2,IrcResult *work) {
 IRC_RESULT_ExitRankFade(&work->rankFade); IRC_RESULT_ExitTextWindow(&work->captionWindow);
 IRC_APPBAR_Delete(work->appBar); IRC_RESULT_ExitTextWindow(&work->messageWindow);
 IRC_RESULT_ExitScreen(&work->screen); IRC_RESULT_ExitTextSystem(&work->text);
 PROCSYS_FreeProcWork(proc); GFL_HEAP_DeleteChecked(60); return 1;
}

/*
 * extent: 210-byte code; 021B784A..021B784C is two zero alignment bytes.
 * prototype: 7C94 tail-forwards u32 from own matched 0201C4E4;
 * caller tests r0. The owner's void declaration stays untouched.
 */
int IRC_RESULT_Main(void *proc,u32 *state,void *unused,IrcResult *work)
{
    IrcSys *ircSys;
    switch(*state) {
    case 0: *state=1; break;
    case 1: FADE_Start(3,16,0,0); *state=2; break;
    case 2: if(!FADE_IsActive()) *state=3; break;
    case 3:
        work->stateFn(work,&work->stateStep);
        if(work->finished) *state=4;
        break;
    case 4: FADE_Start(3,0,16,0); *state=5; break;
    case 5: if(!FADE_IsActive()) *state=6; break;
    case 6: return 1;
    }
    if(IRC_RESULT_RunPrintQueue(&work->text)) {
        IRC_RESULT_UpdateTextWindow(&work->messageWindow,&work->text);
        IRC_RESULT_UpdateTextWindow(&work->captionWindow,&work->text);
    }
    IRC_RESULT_DrawScreen(&work->screen);
    IRC_RESULT_UpdateRankFade(&work->rankFade);
    IRC_APPBAR_Update(work->appBar);
    ircSys=work->context->ircSys;
    if(ircSys) COMPATIBLE_IRC_SYS_UpdateValueSync(ircSys);
    return 0;
}

/* ---- screen: backgrounds, sprites and the vblank task ---- */

void IRC_RESULT_InitScreen(IrcResultScreen *screen,u16 heapId) {
 MI_CpuFill8(screen,0,sizeof(*screen)); BG_SYS_ClearGraphicsMemory(0); BG_SYS_SetVramBanks((struct DispVram *)sResultVramBankConfig);
 BG_SYS_SetLcdSwap(0); BG_SYS_ResetSubDisplay(); BG_SYS_ClearMainPlanes();
 IRC_RESULT_InitActorSystem(&screen->actorSystem,sResultVramBankConfig,heapId); IRC_RESULT_InitBackgrounds(screen,heapId);
 screen->vblankTask=GFL_USE_AddMainTask(IRC_RESULT_ScreenVBlankTask,screen,0);
}

void IRC_RESULT_ExitScreen(IrcResultScreen *screen) { TCB_DeleteTask(screen->vblankTask); IRC_RESULT_ExitBackgrounds(&screen->bgCharRegion); IRC_RESULT_ExitActorSystem(&screen->actorSystem); }

/*
 * evidence: IRC_RESULT_DrawActorSystem is ov105's own code ("ldr r3, =0x0204A600; bx r3"
 * after the pop at 0x021B7C00), inside ov105's window, so only ov105 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov105's own listing.  The old hint ov021
 * named a different overlay's function mapped over the same address.
 */
void IRC_RESULT_DrawScreen(IrcResultScreen *screen) { IRC_RESULT_DrawActorSystem(&screen->actorSystem); }

/*
 * Unblocked by matching IRC_RESULT_GetActor in ov105 (pkt_ov105_021B7C14).
 */
struct ClactActor *IRC_RESULT_GetScreenActor(IrcResultScreen *screen, int index) { return IRC_RESULT_GetActor(&screen->actorSystem, index); }

struct Unit *IRC_RESULT_GetScreenActorUnit(IrcResultScreen *screen) { return IRC_RESULT_GetActorUnit(&screen->actorSystem); }

void IRC_RESULT_ScreenVBlankTask(struct TcbTask *task, void *arg) { IrcResultScreen *screen=arg; IRC_RESULT_VBlankBackgrounds(screen); IRC_RESULT_VBlankActorSystem(&screen->actorSystem); }

void IRC_RESULT_InitBackgrounds(IrcResultScreen *screen,u16 heapId)
{
    int i,id;
    void *archive;
    BG_SYS_Create(heapId); BMP_WIN_Init(heapId); BG_SYS_SetGraphicsMode((struct DispConfig *)sResultDisplayConfig);
    for(i=0;i<8;++i) {
        id=sResultBackgroundLayers[i];
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)(sResultBackgroundTemplates+i*32),(u8)sResultBackgroundTypes[i]);
        BG_SYS_FreeSlot((u8)id); BG_SYS_SetPlaneVisible((u8)id,1);
    }
    archive=ARC_TOOL_CreateHandle(IRC_GRAPHICS_ARCHIVE_ID,heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive,16,0,0,0,heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive,16,4,0,0,heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive,0,2,0,0,0,heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive,0,6,0,0,0,heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive,48,4,0,0,0,heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive,13,1,0,0,0,heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(archive,4,2,0,0,0,heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(archive,4,6,0,0,0,heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(archive,46,4,0,0,0,heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(archive,14,1,0,0,0,heapId);
    BG_SYS_Init(5,0,1,0);
    screen->bgCharRegion=(u32)ARC_UTIL_RegisterObjCharFromHandle(archive,49,5,0,0,heapId);
    ARC_TOOL_DeleteHandle(archive);
}

void IRC_RESULT_ExitBackgrounds(u32 *bgCharRegion) {
 int i;
 BG_SYS_FreeTileRun(5,(u16)(*bgCharRegion),(u16)(*bgCharRegion>>16));
 BG_SYS_FreeTiles(5,1,0);
 for(i=0;i<8;i++) BG_SYS_FreeLayerBuf((u8)sResultBackgroundLayers[i]);
 BMP_WIN_Exit(); BG_SYS_Delete();
}

void IRC_RESULT_VBlankBackgrounds(void *unused) { BG_SYS_Update(); }

/* ---- sprite system ---- */

/*
 * lever: later placementB declaration reproduces its lower stack slot.
 */
void IRC_RESULT_InitActorSystem(IrcResultActorSystem *sys,const void *config,u16 heapId)
{
    struct ActorInitParam placementA,placementB;
    void *archive;
    int i;
    MI_CpuFill8(sys,0,sizeof(*sys));
    CLACT_InitSystem((struct ClactSysInit *)gClActorInitParam,(struct DispVramCfg *)config,heapId);
    sys->unit=CLACT_CreateUnit(128,0,heapId);
    CLACT_SetUnitDefaultRenderer(sys->unit);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
    archive=ARC_TOOL_CreateHandle(IRC_GRAPHICS_ARCHIVE_ID,heapId);
    sys->paletteId=CLACT_RegisterPalette(archive,12,0,0,heapId);
    sys->characterId=CLACT_RegisterCharacter(archive,11,0,0,heapId);
    sys->cellAnimId=CLACT_RegisterCellAnim(archive,10,9,heapId);
    ARC_TOOL_DeleteHandle(archive);
    MI_CpuFill8(&placementA,0,8);
    for(i=0;i<3;++i) sys->actors[IRC_RESULT_ACTOR_DIGIT+i]=CLACT_CreateActor(sys->unit,sys->characterId,sys->paletteId,sys->cellAnimId,&placementA,0,heapId);
    MI_CpuFill8(&placementB,0,8);
    placementB.x=128; placementB.y=96;
    sys->actors[IRC_RESULT_ACTOR_EFFECT]=CLACT_CreateActor(sys->unit,sys->characterId,sys->paletteId,sys->cellAnimId,&placementB,0,heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)sys->actors[IRC_RESULT_ACTOR_EFFECT],0); CLACT_SetActorBgPriority((struct ClactActor *)sys->actors[IRC_RESULT_ACTOR_EFFECT],0); CLACT_SetActorDrawPriority((struct ClactActor *)sys->actors[IRC_RESULT_ACTOR_EFFECT],0);
    CLACT_SetActorAutoAnim((struct ClactActor *)sys->actors[IRC_RESULT_ACTOR_EFFECT],1); CLACT_SetActorAnimSeq((struct ClactActor *)sys->actors[IRC_RESULT_ACTOR_EFFECT],11);
    for(i=0;i<3;++i) {
        CLACT_SetActorDrawEnable((struct ClactActor *)(sys->actors[IRC_RESULT_ACTOR_DIGIT+i]),0); CLACT_SetActorBgPriority((struct ClactActor *)(sys->actors[IRC_RESULT_ACTOR_DIGIT+i]),0); CLACT_SetActorDrawPriority((struct ClactActor *)(sys->actors[IRC_RESULT_ACTOR_DIGIT+i]),0);
    }
}

void IRC_RESULT_ExitActorSystem(IrcResultActorSystem *sys) {
 int i;
 for(i=0;i<38;i++) if(sys->actors[i]) CLACT_DeleteActor((struct ClactActor *)sys->actors[i]);
 CLACT_ReleasePalette(sys->paletteId); CLACT_ReleaseCharacter(sys->characterId); CLACT_ReleaseCellAnim(sys->cellAnimId);
 CLACT_DeleteUnit(sys->unit); CLACT_ExitSystem(); MI_CpuFill8(sys,0,sizeof(*sys));
}

void IRC_RESULT_DrawActorSystem(void *unused) { CLACT_DrawSystem(); }

void IRC_RESULT_VBlankActorSystem(void *unused) { CLACT_VBlankSystem(); }

struct ClactActor *IRC_RESULT_GetActor(IrcResultActorSystem *sys, int index)
{
    return sys->actors[index];
}

struct Unit *IRC_RESULT_GetActorUnit(IrcResultActorSystem *sys)
{
    return sys->unit;
}

/* ---- text system and text windows ---- */

void IRC_RESULT_InitTextSystem(IrcTextSystem *text, int fontStyle, u16 heapId) {
 MI_CpuFill8(text, 0, sizeof(*text));
 GF_FONT_InitTextColor();
 if (fontStyle == 0) {
  text->font = GF_FONT_Create(0x17, 0, 0, 0, heapId);
 }
 text->printQueue = PRINTSYS_QUE_Create(heapId);
 text->msgData = MSGDATA_CreateFromArchive(0, 2, 0x33, heapId);
 text->wordSet = WORDSET_CreateDefault(heapId);
}

void IRC_RESULT_ExitTextSystem(IrcTextSystem *text) { WORDSET_Delete(text->wordSet); MSGDATA_Delete(text->msgData); PRINTSYS_QUE_Delete(text->printQueue); GF_FONT_Delete(text->font); MI_CpuFill8(text,0,sizeof(*text)); }

u32 IRC_RESULT_RunPrintQueue(IrcTextSystem *text) { return PRINTSYS_QUE_Main(text->printQueue); }

/*
 * four getters at +0, +8, +4, +c.
 */
void *IRC_RESULT_GetFont(IrcTextSystem *text)
{
    return text->font;
}

void *IRC_RESULT_GetPrintQueue(IrcTextSystem *text)
{
    return text->printQueue;
}

void *IRC_RESULT_GetMessages(IrcTextSystem *text)
{
    return text->msgData;
}

void *IRC_RESULT_GetWordSet(IrcTextSystem *text)
{
    return text->wordSet;
}

void IRC_RESULT_InitMessageWindow(IrcTextWindow *win, u32 layer, u32 x, u8 y, u8 width, u8 height, u8 paletteNo, u16 heapId)
{
    void *window;
    MI_CpuFill8(win, 0, sizeof(*win));
    win->clearColor = 15;
    win->window = BMP_WIN_Create(layer, x, y, width, height, paletteNo, 1);
    win->buffer = STRBUF_Create(255, heapId);
    win->printTarget = win->window;
    win->isPrinting = 0;
    BMP_Clear(BMP_WIN_GetBmp(win->window), win->clearColor);
    window = win->window;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
}

void IRC_RESULT_InitTextWindow(IrcTextWindow *win,u32 layer,u32 x,u8 y,u8 width,u8 height,u8 paletteNo,u16 clearColor,u8 slot,u16 heapId) {
 void *window;
 MI_CpuFill8(win,0,sizeof(*win)); win->clearColor=clearColor;
 win->window=BMP_WIN_Create(layer,x,y,width,height,paletteNo,slot);
 win->buffer=STRBUF_Create(0xff,heapId);
 win->printTarget=win->window; win->isPrinting=0;
 BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor);
 window=win->window; BMP_WIN_TransferChars(window); BMP_WIN_MakeScreen(window); BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
}

void IRC_RESULT_ExitTextWindow(IrcTextWindow *win) { STRBUF_Delete(win->buffer); BMP_WIN_Delete(win->window); MI_CpuFill8(win,0,sizeof(*win)); }

int IRC_RESULT_UpdateTextWindow(IrcTextWindow *win,IrcTextSystem *text) { void *printQueue; printQueue=text->printQueue; if(win->isPrinting) { if(!PRINTSYS_QUE_IsExistTarget(printQueue,BMP_WIN_GetBmp(win->printTarget))) { BMP_WIN_TransferChars(win->printTarget); win->isPrinting=0; } } if(!win->isPrinting) return 1; return 0; }

void IRC_RESULT_PrintMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId,int x,s16 y) {
 void *messages; void *printQueue; void *font;
 messages=IRC_RESULT_GetMessages(text); printQueue=IRC_RESULT_GetPrintQueue(text); font=IRC_RESULT_GetFont(text);
 BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor);
 MSGDATA_ReadString(messages,msgId,win->buffer);
 PRINTSYS_PrintQue(printQueue,BMP_WIN_GetBmp(win->printTarget),(s16)x,y,win->buffer,font); win->isPrinting=1;
}

void IRC_RESULT_PrintCenteredMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId)
{
 void *messages; void *printQueue; void *font; u16 x,y;
 messages=IRC_RESULT_GetMessages(text); printQueue=IRC_RESULT_GetPrintQueue(text); font=IRC_RESULT_GetFont(text);
 BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor);
 MSGDATA_ReadString(messages,msgId,win->buffer);
 x=BMP_WIN_GetWidth(win->window)*4; y=BMP_WIN_GetHeight(win->window)*4;
 x-= (u16)(PRINTSYS_MeasureWidestLine(win->buffer,font,0)/2);
 y-= (u16)(PRINTSYS_CountLines(win->buffer,font)/2);
 PRINTSYS_PrintQueColor(printQueue,BMP_WIN_GetBmp(win->printTarget),(s16)x,(s16)y,win->buffer,font,15812);
 win->isPrinting=1;
}

void IRC_RESULT_PrintMessageWithNumber(IrcTextWindow *win, IrcTextSystem *text, u8 msgId, u16 number, u16 slot)
{
 void *wordSet; void *messages; void *string; void *printQueue; void *font;
 BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor);
 wordSet=IRC_RESULT_GetWordSet(text); messages=IRC_RESULT_GetMessages(text);
 WORDSET_SetSlotNumber(wordSet,slot,number,3,0,1);
 string=MSGDATA_AllocString(messages,msgId);
 WORDSET_CopyTaggedText(wordSet,win->buffer,string); STRBUF_Delete(string);
 printQueue=IRC_RESULT_GetPrintQueue(text); font=IRC_RESULT_GetFont(text);
 PRINTSYS_PrintQue(printQueue,BMP_WIN_GetBmp(win->printTarget),0,0,win->buffer,font);
 win->isPrinting=1;
}

void IRC_RESULT_PrintMessageWithNames(IrcTextWindow *win, IrcTextSystem *text, int msgId, IrcCompatibleProfile *own, IrcCompatibleProfile *partner, int unused)
{
 void *wordSet; void *messages; void *string; void *printQueue; void *font;
 BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor);
 wordSet=IRC_RESULT_GetWordSet(text); messages=IRC_RESULT_GetMessages(text);
 WORDSET_SetSlotMyStatus(wordSet,0,partner->myStatus); WORDSET_SetSlotMyStatus(wordSet,1,own->myStatus);
 string=MSGDATA_AllocString(messages,msgId);
 WORDSET_CopyTaggedText(wordSet,win->buffer,string); STRBUF_Delete(string);
 printQueue=IRC_RESULT_GetPrintQueue(text); font=IRC_RESULT_GetFont(text);
 PRINTSYS_PrintQue(printQueue,BMP_WIN_GetBmp(win->printTarget),0,0,win->buffer,font);
 win->isPrinting=1;
}

void IRC_RESULT_PrintRewardMessage(IrcTextWindow *win, IrcTextSystem *text, IrcCompatibleProfile *own, unsigned quantity, int msgId)
{
 void *wordSet; void *messages; void *string; void *printQueue; void *font; int plural;
 u8 *name;
 BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor);
 wordSet=IRC_RESULT_GetWordSet(text);
 messages=IRC_RESULT_GetMessages(text);
 name=own->myStatus; WORDSET_SetSlotMyStatus(wordSet,0,name); plural=0;
 if(quantity>1) plural=1;
 WORDSET_SetSlotFromBank(wordSet,1,IRC_RESULT_REWARD_ITEM,plural,0); WORDSET_SetSlotNumber(wordSet,2,quantity,1,0,1);
 string=MSGDATA_AllocString(messages,msgId);
 WORDSET_CopyTaggedText(wordSet,win->buffer,string); STRBUF_Delete(string);
 printQueue=IRC_RESULT_GetPrintQueue(text); font=IRC_RESULT_GetFont(text);
 PRINTSYS_PrintQue(printQueue,BMP_WIN_GetBmp(win->printTarget),0,0,win->buffer,font);
 win->isPrinting=1;
}

/* ---- state machine ---- */

void IRC_RESULT_SetState(IrcResult *work, IrcResultStateFn fn) { work->stateFn=fn; work->stateStep=0; }

void IRC_RESULT_Finish(IrcResult *work) { work->finished=1; }

void IRC_RESULT_StateStart(IrcResult *work,u16 *step)
{
    IRC_RESULT_SetState(work,IRC_RESULT_StateShowScore);
}

/*
 * lever: unsigned word ratio retains repeated u8 narrowing; duplicate 0 and 1/2/3 sound calls retain the branch-to-branch switch arm.
 * function_starts: 0x021B8340 callback stub included in this unit.
 */
void IRC_RESULT_StateShowScore(IrcResult *work,u16 *step) {
 IrcCompatibleProfile profile; int rewardResult; u32 msgId; u8 score;
 switch(*step) {
 case 0:
  if((work->waitFrames)++>30) {work->waitFrames=0;*step=1;} break;
 case 1:IRC_RESULT_StartRankFade(&work->rankFade);*step=2;break;
 case 2:
  if(IRC_RESULT_IsRankFadeFinished(&work->rankFade)) {
   GFL_USE_PlaySeDefaultVolume(IRC_RESULT_SE_DIGITS);
   IRC_RESULT_ShowDigit(&work->scoreDisplay,0);IRC_RESULT_ShowDigit(&work->scoreDisplay,1);IRC_RESULT_ShowDigit(&work->scoreDisplay,2);*step=3;
  } break;
 case 3:
  if(IRC_RESULT_IsDigitShown(&work->scoreDisplay,0) && IRC_RESULT_IsDigitShown(&work->scoreDisplay,1) && IRC_RESULT_IsDigitShown(&work->scoreDisplay,2)) *step=4;
  break;
 case 4:
  score=work->context->score;msgId=(u8)(score/10+IRC_RESULT_MSG_SCORE_FIRST);
  if(msgId>IRC_RESULT_MSG_SCORE_LAST)msgId=IRC_RESULT_MSG_SCORE_LAST;else if(msgId<IRC_RESULT_MSG_SCORE_FIRST)msgId=IRC_RESULT_MSG_SCORE_FIRST;
  IRC_RESULT_PrintMessageWithNumber(&work->messageWindow,&work->text,msgId,score,2);*step=5;break;
 case 5:
  if((work->waitFrames)++>50) {
   work->waitFrames=0;
   switch(IRC_RESULT_GetScoreRank(work->context->score,0)) {
   case 5:GFL_USE_CancelChangeAndPlayBgm(IRC_RESULT_BGM_RANK_5,65535);break;
   case 4:GFL_USE_CancelChangeAndPlayBgm(IRC_RESULT_BGM_RANK_4,65535);break;
   case 1:case 2:case 3:GFL_USE_CancelChangeAndPlayBgm(IRC_RESULT_BGM_OTHER,65535);break;
   case 0:GFL_USE_CancelChangeAndPlayBgm(IRC_RESULT_BGM_OTHER,65535);break;
   default:break;
   }
   *step=6;
  } break;
 case 6:
  if(!GFL_USE_IsBgmPlaying() && (work->waitFrames)++>30) {work->waitFrames=0;*step=7;}
  break;
 case 7:
  if(TOUCHPANEL_GetTrg()) {
   if(work->context->gameSystem)COMPATIBLE_IRC_SYS_BuildProfile(work->context->gameSystem,&profile);
   rewardResult=IRC_RESULT_GiveReward(work);
   if(rewardResult==IRC_RESULT_REWARD_GIVEN) {
    if(work->bonusDay==0)IRC_RESULT_PrintRewardMessage(&work->messageWindow,&work->text,&profile,(u8)work->rewardQuantity,IRC_RESULT_MSG_REWARD);
    else IRC_RESULT_PrintRewardMessage(&work->messageWindow,&work->text,&profile,(u8)work->rewardQuantity,IRC_RESULT_MSG_REWARD_BONUS);
    *step=8;
   } else if(rewardResult==IRC_RESULT_REWARD_BAG_FULL) {IRC_RESULT_PrintMessage(&work->messageWindow,&work->text,IRC_RESULT_MSG_BAG_FULL,0,0);*step=8;}
   else *step=9;
  } break;
 case 8:
  if((work->waitFrames)++>30) {IRC_APPBAR_SetEnabled(work->appBar,1);work->waitFrames=0;*step=9;}break;
 case 9:IRC_APPBAR_SetEnabled(work->appBar,1);*step=10;break;
 case 10:if(TOUCHPANEL_GetTrg())IRC_RESULT_SetState(work,IRC_RESULT_StateEnd);break;
 }
 if(IRC_APPBAR_GetResult(work->appBar)==1)IRC_RESULT_Finish(work);
 IRC_RESULT_UpdateScoreDisplay(&work->scoreDisplay);
}

void IRC_RESULT_StateEnd(IrcResult *work,u16 *step) {IRC_RESULT_Finish(work);}

/* ---- score digits ---- */

void IRC_RESULT_InitScoreDisplay(IrcResultScoreDisplay *display,IrcResultScreen *screen,int score)
{
 int i; struct ClactVec2 pos;
 MI_CpuFill8(display,0,sizeof(*display));
 for(i=0;i<3;i++) {
  display->digitActors[i]=IRC_RESULT_GetScreenActor(screen,i);
  if(score<100) pos.x=74+i*36;
  else if(score>=0 && score<10) pos.x=56+i*36;
  else pos.x=92+i*36;
  pos.y=84;
  CLACT_AddActorSurfacePos(display->digitActors[i],&pos,0);
  CLACT_SetActorDrawEnable((struct ClactActor *)display->digitActors[i],0);
  display->animFrame[i]=0;display->animLength[i]=60;
  display->animStep[i]=4079/display->animLength[i];
 }
 IRC_RESULT_SetScoreDigits(display, score);
}

void IRC_RESULT_ShowDigit(IrcResultScoreDisplay *display, int i)
{
    if (display->digitState[i] == 0) {
        if (i == 0 && display->digits[2 - i] == 0) {
            display->digitState[i] = 1;
            return;
        }
        if (i == 0 && display->digits[2 - i] == 0 && i == 1 && display->digits[2 - i] == 0) {
            display->digitState[i] = 1;
            return;
        }
        display->digitState[i] = 1;
        CLACT_SetActorDrawEnable((struct ClactActor *)display->digitActors[i], 1);
    }
}

int IRC_RESULT_UpdateScoreDisplay(IrcResultScoreDisplay *display) { return 0; }

/*
 * extent: unowned follower at 021B8440 is outside this getter.
 */
int IRC_RESULT_IsDigitShown(IrcResultScoreDisplay *display,int i) {return display->digitState[i];}

void IRC_RESULT_SetScoreDigits(IrcResultScoreDisplay *display, unsigned score)
{
    u8 t;
    int i, j;
    t = score;
    if (t) { for (;;) { if (!t) break; t = t / 10; } }
    for (i = 0; i < 3; i++) CLACT_SetActorAnimSeq((struct ClactActor *)display->digitActors[i],0);
    for (j = 0; j < 3; j++) {
        display->digits[j] = score % sResultPowersOfTen[j+1] / sResultPowersOfTen[j];
        CLACT_SetActorAnimSeq((struct ClactActor *)display->digitActors[2-j],display->digits[j]+1);
    }
}

/* ---- rank bars ---- */

void IRC_RESULT_InitRankFade(IrcResultRankFade *fade,int id,int score,u16 heapId)
{
    void *archive, *data;
    IrcPaletteFile *file;
    u8 *colors;
    int i;
    MI_CpuFill8(fade,0,0x60);
    fade->id=id;
    fade->phaseCount=IRC_RESULT_GetScoreRank(score,&fade->nearNextRank);
    if (fade->nearNextRank) ++fade->phaseCount;
    archive=ARC_TOOL_CreateHandle(IRC_GRAPHICS_ARCHIVE_ID,heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive,15,3,0,0,0,heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(archive,17,3,0,0,0,heapId);
    ARC_TOOL_DeleteHandle(archive);
    data=ARC_UTIL_LoadPaletteBlockFromArchive(IRC_GRAPHICS_ARCHIVE_ID,16,&file,heapId);
    colors=file->colors;
    MI_CpuCopy8(colors,fade->targetColors,32);
    MI_CpuCopy8(colors+0x100,fade->targetColors,32);
    GFL_HEAP_Free(data);
    MI_CpuCopy8(fade->targetColors,fade->workColors,32);
    for(i=0;i<13;++i) fade->workColors[i]=0x7fff;
    for(i=0;i<16;++i) NNS_GfdRegisterNewVramTransferTask(IRC_PALETTE_TARGET,(u32)(0x100+i*2),(&fade->workColors[i]),2);
}

void IRC_RESULT_ExitRankFade(IrcResultRankFade *fade) { MI_CpuFill8(fade, 0, 0x60); }

/*
 * extent: 376-byte lead,20-byte reset871C,4-byte getter8730; no tail data.
 * lever: 3-byte table rows unify index array and count field relocations.
 */
void IRC_RESULT_UpdateRankFade(IrcResultRankFade *fade)
{
    int i;
    if (!fade->running) return;
    switch(fade->step) {
    case 0:
        if(fade->phase>fade->phaseCount) {
            if(fade->nearNextRank) fade->step=1;
            else { fade->finished=1; fade->running=0; }
            return;
        }
        if(!fade->frame) GFL_USE_PlaySeDefaultVolume(IRC_RESULT_SE_RANK_FADE_IN+fade->phase);
        for(i=0;i<sResultRankFadeRows[fade->phase].count;++i) {
            int index=sResultRankFadeRows[fade->phase].index[i];
            IRC_RESULT_BlendPaletteEntry(fade->workColors+index,(u16)fade->frame,40,8,index,0x7fff,fade->targetColors[index]);
        }
        if(fade->frame++>=40) { fade->frame=0; ++fade->phase; }
        break;
    case 1:
        if(fade->frame++>=60) { fade->frame=0; fade->step=2; }
        break;
    case 2:
        if(!fade->frame) GFL_USE_PlaySeDefaultVolume(IRC_RESULT_SE_RANK_FADE_OUT+fade->phase);
        for(i=0;i<sResultRankFadeRows[fade->phase-1].count;++i) {
            int index=sResultRankFadeRows[fade->phase-1].index[i];
            IRC_RESULT_BlendPaletteEntry(fade->workColors+index,(u16)fade->frame,40,8,index,fade->targetColors[index],0x7fff);
        }
        if(fade->frame++>=40) { fade->frame=0; fade->finished=1; fade->running=0; }
        break;
    }
}

void IRC_RESULT_StartRankFade(IrcResultRankFade *fade)
{
    fade->running=1; fade->finished=0; fade->phase=1; fade->step=0; fade->frame=0;
}

unsigned IRC_RESULT_IsRankFadeFinished(IrcResultRankFade *fade)
{
    return fade->finished;
}

/*
 * extent: two-byte zero padding before IRC_RESULT_GetScoreRank
 * lever: u8 div and paletteBank pin their home stores to the prologue
 */
void IRC_RESULT_BlendPaletteEntry(u16 *color,int n,u8 div,u8 paletteBank,u8 colorIndex,u16 from,u16 to)
{
 u8 r,g,blue; int dr,dg,db;
 g=(from&0x3E0)>>5;
 r=from&31;
 blue=(from&0x7C00)>>10;
 db=((u8)((to&0x7C00)>>10)-blue)*n/div;
 dr=((u8)(to&31)-r)*n/div;
 dg=((u8)((to&0x3E0)>>5)-g)*n/div;
 *color=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
 NNS_GfdRegisterNewVramTransferTask(IRC_PALETTE_TARGET,(u32)(paletteBank*32+colorIndex*2),color,2);
}

/* ---- score rank and reward ---- */

int IRC_RESULT_GetScoreRank(unsigned score, int *nearNextRank)
{
    int nextLimit, rank;
    if (score == 100) { nextLimit = 65535; rank = 5; }
    else if (score >= 80) { nextLimit = 100; rank = 4; }
    else if (score >= 60) { nextLimit = 80; rank = 3; }
    else if (score >= 30) { nextLimit = 60; rank = 2; }
    else if (score > 0) { nextLimit = 30; rank = 1; }
    else if (score == 0) { nextLimit = 0; rank = 0; }
    else { nextLimit = 100; rank = 1; }
    if (nearNextRank) *nearNextRank = (int)(score + 3) > nextLimit ? 1 : 0;
    return rank;
}

unsigned int IRC_RESULT_GetRewardQuantity(unsigned int score,int bonusDay) { unsigned int quantity; if(bonusDay) quantity=2; else quantity=1; if(score==100) return quantity*3; if(score>79) quantity*=2; return quantity; }

/*
 * extent: 248-byte function; 021B8958..021B8B20 is overlay rodata.
 * lever: one-case switch retains conditional-plus-unconditional dispatch.
 * abi: 084F4's full empty body preserves the input r0 consumed at8890;
 *   12F2C's full body forwards its live r0 result from071CC/319A4 to08DF0.
 *   The matched071CC tail-call and full319A4 body return that word;
 *   original8944..894A forwards it with r1=113. No callee source changed.
 */
int IRC_RESULT_GiveReward(IrcResult *work)
{
    IrcCompatibleProfile *partner;
    void *record;
    u8 *key;
    struct ItemBag *bag;
    u32 quantity,request;
    void *src;
    int flag;
    int result=IRC_RESULT_REWARD_NONE;
    record=IRC_RANKING_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(work->context->gameSystem)));
    partner=work->context->partner;
    key=partner->myStatus;
    if(!IRC_RANKING_IsEntryNew(record,MYSTATUS_GetId((struct MyStatus *)key)) && work->context->gameSystem) {
        bag=GAME_DATA_GetMyItem(GAMESYSTEM_GetGameData(work->context->gameSystem));
        quantity=MYITEM_SAVEDATA_GetItemQuantity((struct MyItem *)bag,IRC_RESULT_REWARD_ITEM,60);
        switch(quantity) {
        case IRC_RESULT_REWARD_MAX: result=IRC_RESULT_REWARD_BAG_FULL; break;
        default:
            request=work->rewardQuantity;
            if(IRC_RESULT_REWARD_MAX-quantity<request) request=IRC_RESULT_REWARD_MAX-quantity;
            result=MYITEM_SAVEDATA_AddItem((struct MyItem *)bag,IRC_RESULT_REWARD_ITEM,(u16)request,60)?IRC_RESULT_REWARD_GIVEN:IRC_RESULT_REWARD_BAG_FULL;
            break;
        }
    }
    if(work->context->partner) {
        src=(void *)MYSTATUS_GetName((struct MyStatus *)key);
        flag=MYSTATUS_GetSex((struct MyStatus *)key)?0:1;
        IRC_RANKING_AddEntry(record,src,work->context->score,(u8)flag,partner->birthMonth,partner->birthDay,MYSTATUS_GetId((struct MyStatus *)key),partner->leadSpecies,partner->leadType2,partner->leadType1,partner->leadNature);
    }
    if(work->context->gameSystem) RECORD_AddOne(GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData(work->context->gameSystem)),IRC_RESULT_TRAINER_RECORD);
    return result;
}
