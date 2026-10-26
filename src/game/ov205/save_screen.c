/*
 * file:     save_screen.c
 * unit:     yes
 * function: SAVE_SCREEN_Init, SAVE_SCREEN_Main, SAVE_SCREEN_Exit, SAVE_SCREEN_Setup, SAVE_SCREEN_Delete, SAVE_SCREEN_SetupBackground, SAVE_SCREEN_DeleteBackground, SAVE_SCREEN_PrintEntry, SAVE_SCREEN_SnapshotParty, SAVE_SCREEN_SetTrainerDate, SAVE_SCREEN_SetTrainerFlag, SAVE_SCREEN_SaveFieldClock, SAVE_SCREEN_AppendPartyRecord, SAVE_SCREEN_PartSaveMain, SAVE_SCREEN_NoticeInit, SAVE_SCREEN_NoticeMain, SAVE_SCREEN_NoticeExit, SAVE_SCREEN_SetupNoticeBackground, SAVE_SCREEN_DeleteNoticeBackground, SAVE_SCREEN_PrintText
 * address:  0x021B95A0
 * region:   ov205
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
 *   MIi_CpuClear32 0x02082A7C arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SAVE_CONTROL_WouldOverwriteSave 0x020071F0 thumb
 *   sSaveScreenInit 0x021B9E50 data a2
 *   KEY_GetTrg 0x020362DC arm
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   TCBL_Main 0x020310C4 arm
 *   TIME_ICON_Update 0x0202F0B0 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_SetBankForLCDC 0x0208068C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   GX_DisableBankForLCDC 0x02080B98 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   TCBL_Create 0x0203101C arm
 *   STRBUF_Create 0x020457B0 arm
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021B9E90 0x021B9E90 data a4
 *   d_021B9E60 0x021B9E60 data a4
 *   d_021B9E70 0x021B9E70 data a4
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   RTC_GetDate 0x02088864 arm
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAME_DATA_GetSaveBlock42 0x02012F68 thumb
 *   DENDOU_SAVEDATA_SetRecord 0x0200EA3C thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   PLAYTIME_GetHours 0x0200864C thumb
 *   PLAYTIME_GetMinutes 0x02008650 thumb
 *   PLAYTIME_GetSeconds 0x02008654 thumb
 *   RECORD_SetCounterClamped 0x02008D1C thumb
 *   RECORD_AddCounter 0x02008DAC thumb
 *   RECORD_GetCounterClamped 0x02008DFC thumb
 *   FIELD_CLOCK_SaveTimestamp 0x02169120 thumb ov010
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   SAVE_CONTROL_GetExtraSaveRecord 0x020073D8 thumb
 *   DENDOU_SAVEDATA_AppendRecord 0x0200EBD0 thumb
 *   GAME_DATA_PartSaveStart 0x02012E4C thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   SAVE_CONTROL_DeleteExtraSave 0x020072A4 thumb
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   d_021B9EFC 0x021B9EFC data a4
 *   d_021B9ECC 0x021B9ECC data a4
 *   d_021B9EDC 0x021B9EDC data a4
 *   MSGDATA_ReadString 0x02045CAC arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 */

typedef struct SaveScreenWork {
    unsigned short heapId;
    unsigned short arcId;
    void *ctx;
    void *anim;
    void *textBuf;
    void *font;
    void *msgBank;
    void *wordset;
    void *bmpWin;
    void *printStream;
    void *tcbl;
    unsigned char printBlk[8];
    void *timeIcon;
    unsigned int saveResult;
    unsigned int partSaveFlag;
    unsigned int saveDoneFlag;
    unsigned int hasSave;
    unsigned int resumeState;
    int counter;
} SaveScreenWork;

typedef struct SaveScreenNoticeWork {
    unsigned short heapId;
    unsigned char pad2[2];
    unsigned int mode;
    void *textSrc;
    void *msgBank;
    void *wordset;
    void *bmpWin;
    void *font;
} SaveScreenNoticeWork;

typedef struct SaveScreenContext {
    unsigned char pad0[4];
    unsigned int mode;
    void *textSrc;
} SaveScreenContext;

struct ProcOwner;
struct Big;
struct Ctx;
struct Sub020071E4Ctrl;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Tcbl;
struct Blk;
struct Proc;
struct GfFont;
struct MsgBank;
struct WordSet;
struct U16Vec;
struct Rec;
struct S02031140;
struct BigObj;
struct Date;
struct PlayTime;
struct Sub02008C20Obj;
#include "../arm9/printsys.h"
#include "../sdk_ioreg.h"
#include "../sdk_rtc.h"

struct Ctrl;
struct Obj;
struct Sub020073D8Ctrl;
struct Sub020072A4Ctrl;
#include "../types.h"

#include "../arm9/bg_sys.h"

typedef struct {u16 value;} SaveScreenInit;

#include "save_screen.h"

#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
struct GameSystem;
struct GameData;
#include "../arm9/gamesystem.h"
struct MyStatus;
#include "../arm9/game_data.h"
struct SaveControl;
#include "../arm9/save_control.h"
#include "../arm9/key.h"
#include "../arm9/gpower.h"
#include "../arm9/gx_load2d.h"
#include "../arm9/fade.h"
#include "../arm9/gfl_use.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
struct TcblList;
struct TimeIcon;
#include "../arm9/time_icon.h"
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
struct TextPrinter;
struct PrintStreamCtrl;
#include "../arm9/app_keycursor.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gx_vramcnt_types.h"
#include "../arm9/gx_vramcnt.h"
#include "../arm9/gf_font.h"
#include "../arm9/arc_util.h"
#include "../arm9/msgdata.h"
#include "../arm9/bmp_menuwork.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
#include "../arm9/msg_speed.h"
#include "../arm9/strbuf_types.h"
#include "../ov099/wifi_club_work.h"
#include "../arm9/external.h"
#include "../arm9/dendou_savedata.h"
#include "../arm9/playtime.h"
#include "../arm9/record.h"
#include "../ov010/field_clock.h"
struct PartyRingSave;
#include "../arm9/net.h"
int SAVE_SCREEN_Init(void *owner,int unused,void **args);
int SAVE_SCREEN_Main(void *unused,SaveScreenState *state,SaveScreenContext *context,SaveScreenWork *p);
int SAVE_SCREEN_Exit(void *p);
void SAVE_SCREEN_Setup(SaveScreenWork *p, SaveScreenContext *context);
void SAVE_SCREEN_Delete(SaveScreenWork *p);
void SAVE_SCREEN_SetupBackground(u16 heap);
void SAVE_SCREEN_DeleteBackground(void);
void SAVE_SCREEN_PrintEntry(SaveScreenWork *p, unsigned entry, s16 index, s16 kind);
void SAVE_SCREEN_SnapshotParty(SaveScreenWork *p);
void SAVE_SCREEN_SetTrainerDate(SaveScreenWork *p);
void SAVE_SCREEN_SetTrainerFlag(SaveScreenWork *p);
void SAVE_SCREEN_SaveFieldClock(SaveScreenWork *p);
void SAVE_SCREEN_AppendPartyRecord(SaveScreenWork *p);
void SAVE_SCREEN_PartSaveMain(SaveScreenWork *p);
int SAVE_SCREEN_NoticeInit(struct ProcOwner *obj,u32 unused,SaveScreenContext *ctx);
int SAVE_SCREEN_NoticeMain(void *input,u32 *state,u32 unused,SaveScreenNoticeWork *p);
int SAVE_SCREEN_NoticeExit(void *p);
void SAVE_SCREEN_SetupNoticeBackground(u16 heap);
void SAVE_SCREEN_DeleteNoticeBackground(void);
void SAVE_SCREEN_PrintText(SaveScreenNoticeWork *p,u32 index,s16 x,s16 y);
extern const SaveScreenInit sSaveScreenInit;
extern const unsigned d_021B9E90[],d_021B9E60[],d_021B9E70[];
extern const unsigned d_021B9EFC[],d_021B9ECC[],d_021B9EDC[];

int SAVE_SCREEN_Init(void *owner,int unused,void **args)
{
    void *context;
    SaveScreenWork *p;
    context=*args;
    GFL_HEAP_CreateChildHeap(1,84,1<<18);
    p=(SaveScreenWork *) PROCSYS_AllocProcWork(owner,sizeof(SaveScreenWork),84);
    MIi_CpuClear32(0,p,sizeof(SaveScreenWork));
    p->heapId=84;
    p->arcId=36;
    p->ctx=GAMESYSTEM_GetGameData(context);
    p->anim=GAME_DATA_GetMyStatus(p->ctx);
    if(SAVE_CONTROL_WouldOverwriteSave(GAME_DATA_GetSaveControl(p->ctx))!=0)
        p->hasSave=1;
    return 1;
}

int SAVE_SCREEN_Main(void *unused,SaveScreenState *state,SaveScreenContext *context,SaveScreenWork *p)
{
    SaveScreenInit local;
    void *obj;
    enum { M3=3,M12=12 } mode;
    local=sSaveScreenInit;
    KEY_GetTrg();
    switch(*state){
    case 0:SAVE_SCREEN_Setup(p,context);(*state)++;break;
    case 1:
    {
        enum { Z0,Z1 } zero;
        zero=0;
        *(u16 *)0x04000050=zero;
        *(volatile u32 *)REG_DISPCNT_ADDR=(*(volatile u32 *)REG_DISPCNT_ADDR&0xffffe0ff)|256;
        if(GPOWER_GetSpecialPowerId()==21)mode=3;
        else {GXS_LoadBGPltt(&local,zero,2);mode=12;}
        FADE_Start(mode,16,zero,zero);(*state)++;break;
    }
    case 2:if(!FADE_IsActive())*state=3;break;
    case 3:
        if(p->hasSave!=0){ (*state)++; break; }
        {
            GFL_USE_PlaySeDefaultVolume(0x54c);SAVE_SCREEN_PrintEntry(p,3,0,0);
            obj=p->bmpWin;BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);BG_SYS_PushTile(BMP_WIN_GetBgLayer(obj));
            p->resumeState=4;*state=13;GAME_DATA_SaveStart(*(struct GameData **)&p->ctx);
        }
        break;
    case 4:
        if(p->hasSave==0){
            if(context->mode==0){SAVE_SCREEN_SnapshotParty(p);SAVE_SCREEN_SetTrainerDate(p);}
            else {SAVE_SCREEN_SaveFieldClock(p);SAVE_SCREEN_SetTrainerFlag(p);SAVE_SCREEN_AppendPartyRecord(p);}
        }
        p->timeIcon=TIME_ICON_CreateNode(*(struct TcblList **)&p->tcbl,p->bmpWin,15,16,p->heapId);
        (*state)++;break;
    case 5:
        if(p->hasSave==0 && p->partSaveFlag!=0){
            SAVE_SCREEN_PartSaveMain(p);
            if(p->saveDoneFlag!=0)(*state)++;
        }else (*state)++;
        break;
    case 6:
        if(p->hasSave==0){
            switch(GAME_DATA_SaveMain(p->ctx)){
            case 0:case 1:break;
            case 2:p->saveResult=1;(*state)++;break;
            case 3:p->saveResult=0;(*state)++;break;
            }
        }else (*state)++;
        break;
    case 7:
        TIME_ICON_Delete(p->timeIcon);
        if(p->hasSave==0 && p->saveResult!=0){
            SAVE_SCREEN_PrintEntry(p,4,0,0);
            obj=p->bmpWin;BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);BG_SYS_PushTile(BMP_WIN_GetBgLayer(obj));
            p->resumeState=8;*state=13;GFL_USE_PlaySeDefaultVolume(0x558);
        }else{
            SAVE_SCREEN_PrintEntry(p,5,0,0);
            obj=p->bmpWin;BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);BG_SYS_PushTile(BMP_WIN_GetBgLayer(obj));
            p->resumeState=8;*state=13;
        }
        break;
    case 8:
        if(p->counter>120)(*state)++;
        (p->counter)++;break;
    case 9:
        if(GPOWER_GetSpecialPowerId()==21){ FADE_Start(3,0,16,0); }
        else { FADE_Start(12,0,16,0); }
        (*state)++;break;
    case 10:
        if(!FADE_IsActive()){BMP_Clear(BMP_WIN_GetBmp(p->bmpWin),15);(*state)++;}
        break;
    case 11:SAVE_SCREEN_Delete(p);(*state)++;break;
    case 12:return 1;
    case 13:
        if(PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)p->printBlk,p->printStream))*state=p->resumeState;
        break;
    }
    if(p->tcbl)TCBL_Main(p->tcbl);
    if(p->timeIcon)TIME_ICON_Update(p->timeIcon);
    return 0;
}

int SAVE_SCREEN_Exit(void *p)
{
    PROCSYS_FreeProcWork(p);
    GFL_HEAP_DeleteChecked(0x54);
    return 1;
}

void SAVE_SCREEN_Setup(SaveScreenWork *p, SaveScreenContext *context) { BG_SYS_SetLcdSwap(1);GX_SetBankForLCDC(511);MIi_CpuClearFast(0,(void *)(0x6800000),0xa4000);GX_DisableBankForLCDC();SAVE_SCREEN_SetupBackground(*(u16 *)p);p->font=GF_FONT_Create(23,0,0,0,*(u16 *)p);ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,416,32,*(u16 *)p);p->msgBank=MSGDATA_CreateFromArchive(0,2,p->arcId,*(u16 *)p);p->wordset=WORDSET_CreateDefault(*(u16 *)p);BMP_MENUWORK_LoadCharAndPltt(0,1,12,0,*(u16 *)p);p->bmpWin=BMP_WIN_Create((unsigned int)0,(unsigned int)2,(unsigned int)18,27,4,13,1);p->tcbl=TCBL_Create(*(u16 *)p,*(u16 *)p,10,32);p->textBuf=STRBUF_Create(1024,*(u16 *)p); }

void SAVE_SCREEN_Delete(SaveScreenWork *p)
{
    TCBL_DeleteAllTasks(p->tcbl);
    TCBL_Destroy(p->tcbl);
    p->tcbl=0;
    BMP_MENUWORK_DrawWindowBorder(p->bmpWin,0);
    BMP_WIN_Delete(p->bmpWin);
    STRBUF_Delete(p->textBuf);
    WORDSET_Delete(p->wordset);
    MSGDATA_Delete(p->msgBank);
    BG_SYS_FreeLayerBuf(0);
    GF_FONT_Delete(p->font);
    SAVE_SCREEN_DeleteBackground();
}

void SAVE_SCREEN_SetupBackground(u16 heap)
{
    unsigned zero;
    BG_SYS_Create(heap);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9E90);
    BG_SYS_SetGraphicsMode((void *)d_021B9E60);
    zero=0;
    BG_SYS_InitBgLayer(0,(const struct BgTemplate *)d_021B9E70,0);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,7,0,416,32,heap);
    if(GPOWER_GetSpecialPowerId()==20) BG_SYS_LoadPlttEntry(zero,65535);
    else BG_SYS_LoadPlttEntry(zero,zero);
    BMP_WIN_Init(heap);
}

void SAVE_SCREEN_DeleteBackground(void) { BMP_WIN_Exit();BG_SYS_Delete(); }

void SAVE_SCREEN_PrintEntry(SaveScreenWork *p,unsigned entry,s16 index,s16 kind)
{
    struct U16Vec *buffer;
    buffer=(struct U16Vec *)STRBUF_Create(1024,p->heapId);
    BMP_Clear(BMP_WIN_GetBmp(p->bmpWin),15);
    MSGDATA_ReadString((struct MsgBank *)p->msgBank,entry,(struct Strbuf *)buffer);
    WORDSET_SetSlotMyStatus((struct WordSet *)p->wordset,0,(void *)p->anim);
    WORDSET_CopyTaggedText((struct WordSet *)p->wordset,(struct Strbuf *)p->textBuf,(struct Strbuf *)buffer);
    p->printStream=PRINTSYS_PrintStream(p->bmpWin,index,kind,p->textBuf,p->font,MSG_SPEED_GetWait(),p->tcbl,0,p->heapId,3855);
    STRBUF_Delete((struct Strbuf *)buffer);
    BMP_MENUWORK_DrawWindow(p->bmpWin,2,1,12);
}

void SAVE_SCREEN_SnapshotParty(SaveScreenWork *p) { u32 date[4];void *party,*rec;RTC_GetDate((RTCDate *)date);party=GAME_DATA_GetMyParty((const struct GameData *)((struct GameData *)(*(struct BigObj * *)&p->ctx)));rec=GAME_DATA_GetSaveBlock42((struct GameData *)(*(void ** *)&p->ctx));DENDOU_SAVEDATA_SetRecord((struct DendouRec *)rec,(void *)party,(struct Date *)date,4); }

void SAVE_SCREEN_SetTrainerDate(SaveScreenWork *p)
{
    void *counter,*date;
    unsigned year,month,day;
    counter=GAME_DATA_GetTrainerRecord(p->ctx);
    date=(void *)GAME_DATA_GetPlayTime((p->ctx));
    year=PLAYTIME_GetHours(date);
    month=PLAYTIME_GetMinutes(date);
    day=PLAYTIME_GetSeconds(date);
    RECORD_SetCounterClamped(counter,2,day+(year*10000+month*100));
}

void SAVE_SCREEN_SetTrainerFlag(SaveScreenWork *p) { void *save,*obj;save=GAME_DATA_GetSaveControl((struct GameData *)(*(struct Big * *)&p->ctx));obj=GAME_DATA_GetTrainerRecord((struct GameData *)(*(int * *)&p->ctx));if(SAVE_CONTROL_WouldOverwriteSave(save)==0)RECORD_AddCounter(obj,71,1); }

void SAVE_SCREEN_SaveFieldClock(SaveScreenWork *p) { if(RECORD_GetCounterClamped(GAME_DATA_GetTrainerRecord((struct GameData *)(*(int * *)&p->ctx)),71)==0)FIELD_CLOCK_SaveTimestamp((struct GameData *)(*(char * *)&p->ctx)); }

void SAVE_SCREEN_AppendPartyRecord(SaveScreenWork *p)
{
    unsigned date[4];
    void *save,*object,*record;
    RTC_GetDate((struct RTCDate *)date);
    object=GAME_DATA_GetMyParty(p->ctx);
    save=GAME_DATA_GetSaveControl(p->ctx);
    SAVE_CONTROL_LoadExtraSave(save,8,4);
    record=SAVE_CONTROL_GetExtraSaveRecord(save,8,0);
    if(SAVE_CONTROL_WouldOverwriteSave(save)==0) {
        DENDOU_SAVEDATA_AppendRecord(record,object,date,4);
        GAME_DATA_PartSaveStart(p->ctx,8);
        p->partSaveFlag=1;
    }
}

void SAVE_SCREEN_PartSaveMain(SaveScreenWork *p) { void *save; u32 n;save=GAME_DATA_GetSaveControl((struct GameData *)(*(struct Big * *)&p->ctx));if(SAVE_CONTROL_WouldOverwriteSave(save)==0) { n=GAME_DATA_PartSaveMain((struct GameData *)(*(char * *)&p->ctx),8);if(n-2<=1) { SAVE_CONTROL_DeleteExtraSave(save,8);p->saveDoneFlag=1; } } }

int SAVE_SCREEN_NoticeInit(struct ProcOwner *obj,u32 unused,SaveScreenContext *ctx) { SaveScreenNoticeWork *p;GFL_HEAP_CreateChildHeap(1,84,0x40000);p=(SaveScreenNoticeWork *) PROCSYS_AllocProcWork((struct Proc *)obj,sizeof(SaveScreenNoticeWork),84);MIi_CpuClear32(0,p,sizeof(SaveScreenNoticeWork));p->heapId=84;p->mode=ctx->mode;p->textSrc=ctx->textSrc;return 1; }

int SAVE_SCREEN_NoticeMain(void *input,u32 *state,u32 unused,SaveScreenNoticeWork *p)
{
    u32 keys;
    void *obj;
    keys=KEY_GetTrg();
    switch(*state){
    case 0:
        GX_SetBankForLCDC(511);MIi_CpuClearFast(0,(void *)(0x6800000),0xa4000);GX_DisableBankForLCDC();
        SAVE_SCREEN_SetupNoticeBackground(p->heapId);
        p->font=GF_FONT_Create(23,0,0,0,p->heapId);
        p->msgBank=MSGDATA_CreateFromArchive(0,2,37,p->heapId);
        p->wordset=WORDSET_CreateDefault(p->heapId);
        p->bmpWin=(void *)BMP_WIN_Create(0,2,7,27,15,13,1);
        if(p->mode==0)SAVE_SCREEN_PrintText(p,3,6,0);
        else SAVE_SCREEN_PrintText(p,2,6,0);
        obj=p->bmpWin;
        BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);BG_SYS_PushTile(BMP_WIN_GetBgLayer(obj));
        GFL_NET_RefreshWmIconAtTopRight(1,p->heapId);BG_SYS_SetMainPlaneVisible(16,1);
        (*state)++;break;
    case 1:
        FADE_Start(3,16,0,0);*(u16 *)REG_BLDCNT_ADDR=0;
        (*state)++;break;
    case 2:
        if(!FADE_IsActive())(*state)++;
        break;
    case 3:
        if((keys&1)||(keys&2)){FADE_Start(3,0,16,0);(*state)++;}
        break;
    case 4:
        if(!FADE_IsActive()){BMP_Clear(BMP_WIN_GetBmp(p->bmpWin),0);(*state)++;}
        break;
    case 5:
        BMP_MENUWORK_DrawWindowBorder(p->bmpWin,0);BMP_WIN_Delete(p->bmpWin);
        WORDSET_Delete(p->wordset);MSGDATA_Delete(p->msgBank);
        BG_SYS_FreeLayerBuf(0);GF_FONT_Delete(p->font);SAVE_SCREEN_DeleteNoticeBackground();return 1;
    }
    return 0;
}

int SAVE_SCREEN_NoticeExit(void *p)
{
    PROCSYS_FreeProcWork(p);
    GFL_HEAP_DeleteChecked(0x54);
    return 1;
}

void SAVE_SCREEN_SetupNoticeBackground(u16 heap)
{
    BG_SYS_Create(heap);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9EFC);
    BG_SYS_SetGraphicsMode((void *)d_021B9ECC);
    BG_SYS_InitBgLayer(0,(const struct BgTemplate *)d_021B9EDC,0);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,7,0,416,32,heap);
    BG_SYS_LoadPlttEntry(0,0);
    BMP_WIN_Init(heap);
}

void SAVE_SCREEN_DeleteNoticeBackground(void) { BMP_WIN_Exit();BG_SYS_Delete(); }

void SAVE_SCREEN_PrintText(SaveScreenNoticeWork *p,u32 index,s16 x,s16 y)
{
    struct U16Vec *msgBuf,*drawBuf;
    msgBuf=(struct U16Vec *)STRBUF_Create(0x400,*(u16 *)p);
    drawBuf=(struct U16Vec *)STRBUF_Create(0x400,*(u16 *)p);
    BMP_Clear(BMP_WIN_GetBmp(p->bmpWin),0);
    BMP_Clear(BMP_WIN_GetBmp(p->bmpWin),15);
    MSGDATA_ReadString((struct MsgBank *)p->msgBank,index,(struct Strbuf *)msgBuf);
    WORDSET_SetSlotMyStatus((struct WordSet *)p->wordset,1,(void *)p->textSrc);
    WORDSET_CopyTaggedText((struct WordSet *)p->wordset,(struct Strbuf *)drawBuf,(struct Strbuf *)msgBuf);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)p->bmpWin),x,y,(struct Strbuf *)drawBuf,p->font);
    STRBUF_Delete((struct Strbuf *)msgBuf);
    STRBUF_Delete((struct Strbuf *)drawBuf);
    BMP_WIN_TransferChars(p->bmpWin);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(p->bmpWin));
}
