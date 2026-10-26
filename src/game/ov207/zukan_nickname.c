/*
 * file:     zukan_nickname.c
 * unit:     yes
 * function: ZUKAN_NICKNAME_Create, ZUKAN_NICKNAME_Delete, ZUKAN_NICKNAME_Main, ZUKAN_NICKNAME_SetupScreen, ZUKAN_NICKNAME_GetResult, ZUKAN_NICKNAME_TransferPalette, ZUKAN_NICKNAME_InitKeyboard, ZUKAN_NICKNAME_DeleteKeyboard, ZUKAN_NICKNAME_UpdateInfoWindow
 * address:  0x0220B55C
 * region:   ov207
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   file_0220BC38 0x0220BC38 data a1
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMonSpeciesName 0x0201EE84 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   UI_GetInputMode 0x020355C4 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   UI_SetInputMode 0x020355D8 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_SetSlotBoxName 0x0201F164 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   overlay94 0x0000005E data
 *   BTLV_INPUT_CreateDefault 0x02202058 thumb ov094
 *   BTLV_INPUT_Delete 0x022021F4 thumb ov094
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb  arm9
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *   BTLV_INPUT_ChangeScreen  0x0220270C  thumb
 *   BTLV_INPUT_ProcessTouchInput  0x02202DC4  thumb
 *   BTLV_INPUT_UpdateInfoWindow  0x02202228  thumb
 *   d_0220BBEC     0x0220BBEC  data  ov207
 *   d_0220BBF8     0x0220BBF8  data  ov207
 */

typedef struct ZukanNicknameWork {
    unsigned short heapId;
    unsigned char pad2[2];
    void *titleStr;
    void *nameStr;
    void *textId;
    unsigned int textParam;
    struct Unit *display;
    struct GfFont *font;
    struct PrintQueue *gfx;
    void *infoWinParam;
    void *bmpWin;
    void *printStream;
    void *strbuf;
    unsigned int lineBuf;
    void *tcbl;
    void *bmpWin2;
    int state;
    int mode;
    int counter;
    void *task;
    int pauseFlag;
    unsigned char soundEnabled;
    unsigned char pad51[3];
    void *input;
    void *palAnm;
} ZukanNicknameWork;

struct WordSet;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct CharBuf;
struct Tcbl;
struct Rec;
struct Node;
struct Rec3;
struct S02031140;
struct Cfg;
struct PaletteFade;
struct PaletteFade;
struct PaletteFade;
struct ClactActor;
#include "../arm9/bmp_menuwork.h"
#include "../types.h"

#include "../arm9/printsys.h"
typedef struct ClactActor Obj;

typedef struct {
    struct Strbuf *primaryText;
    struct Strbuf *secondaryText;
    int enabled;
} S3;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
#include "../arm9/arc_util.h"
#include "../arm9/gf_font.h"
#include "../arm9/wordset.h"
#include "../arm9/msgdata.h"
struct Strbuf;
#include "../arm9/strbuf.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/bg_sys.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "../arm9/msg_speed.h"
#include "../arm9/ui.h"
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
struct TextPrinter;
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/palanm.h"
struct BtlvInput;
#include "../ov094/btlv_input.h"
char *ZUKAN_NICKNAME_Create(u16 heap,void *a,void *b,void *c,u32 d,struct Unit *e,struct GfFont *f,struct PrintQueue *g,void *h);
void ZUKAN_NICKNAME_Delete(ZukanNicknameWork *p);
int ZUKAN_NICKNAME_Main(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_SetupScreen(ZukanNicknameWork *p);
int ZUKAN_NICKNAME_GetResult(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_TransferPalette(struct TcbTask *a, void *pArg);
void ZUKAN_NICKNAME_InitKeyboard(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_DeleteKeyboard(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_UpdateInfoWindow(ZukanNicknameWork *a);
extern char file_0220BC38[];
extern char overlay94[];
extern BtlvInputTouchTable d_0220BBEC;
extern s8 d_0220BBF8[][12];

/*
 * ABI: 0201CCE4 is a void forwarder in its matched source; caller stores live r0, so declare its observed word return.
 */
char *ZUKAN_NICKNAME_Create(u16 heap,void *a,void *b,void *c,u32 d,struct Unit *e,struct GfFont *f,struct PrintQueue *g,void *h)
{
    ZukanNicknameWork *p;
    struct WordSet *ws;
    struct MsgBank *bank;
    void *str;
    u8 enabled;
    p=(ZukanNicknameWork *) GFL_HEAP_Alloc(heap,sizeof(ZukanNicknameWork),0,file_0220BC38,220);
    MI_CpuFill8(p,0,sizeof(ZukanNicknameWork));
    p->heapId=heap;
    p->titleStr=a;
    p->nameStr=b;
    p->textId=c;
    p->textParam=d;
    p->display=e;
    p->font=f;
    p->gfx=g;
    p->infoWinParam=h;
    p->state=0;
    p->mode=2;
    p->counter=0;
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17,5,0,0x120,32,p->heapId);
    ws=WORDSET_CreateDefault(p->heapId);
    WORDSET_SetSlotMonSpeciesName(ws,0,p->titleStr);
    bank=MSGDATA_CreateFromArchive(0,2,0xea,p->heapId);
    str=MSGDATA_AllocString(bank,0xaf);
    p->strbuf=STRBUF_Create(64,p->heapId);
    WORDSET_CopyTaggedText(ws,p->strbuf,str);
    STRBUF_Delete(str);
    MSGDATA_Delete((struct MsgBank *)bank);
    WORDSET_Delete(ws);
    p->bmpWin2=(void *)BMP_WIN_Create(3,0,0,1,1,9,0);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&p->bmpWin2)),0);
    BMP_WIN_TransferChars((struct BmpWin *)(*(struct Descriptor * *)&p->bmpWin2));
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)(*(struct Descriptor * *)&p->bmpWin2)));
    p->tcbl=TCBL_Create(p->heapId,p->heapId,1,0);
    p->bmpWin=(void *)BMP_WIN_Create(3,1,19,30,4,9,1);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&p->bmpWin)),15);
    GF_FONT_SetTextColor(1,2,15);
    p->printStream=PRINTSYS_PrintStream(p->bmpWin,0,0,p->strbuf,p->font,MSG_SPEED_GetWait(),p->tcbl,(u32)2,p->heapId,15);
    p->lineBuf=BMP_MENUWORK_LoadFrameGfx(3,8,0,p->heapId);
    enabled=1;
    if(UI_GetInputMode()!=0) enabled=0;
    p->soundEnabled=enabled;
    ZUKAN_NICKNAME_InitKeyboard(p);
    p->task=GFL_USE_AddMainTask(ZUKAN_NICKNAME_TransferPalette,(void *)((uptr)p),1);
    return (char *)p;
}

/*
 * tail: two zero alignment bytes at 0x0220B72A before 0x0220B72C.
 */
void ZUKAN_NICKNAME_Delete(ZukanNicknameWork *p)
{
    ZUKAN_NICKNAME_DeleteKeyboard((ZukanNicknameWork *)p);
    TCB_DeleteTask((struct TcbTask *)p->task);
    PRINTSYS_PrintStreamDelete(p->printStream);
    BG_SYS_FreeTileRun(3, (u16)p->lineBuf, (u16)(p->lineBuf >> 16));
    BMP_WIN_Delete((struct BmpWin *)p->bmpWin);
    STRBUF_Delete((struct Strbuf *)p->strbuf);
    TCBL_Destroy((struct TcblSystem *)p->tcbl);
    BMP_WIN_Delete((struct BmpWin *)p->bmpWin2);
    GFL_HEAP_Free(p);
}

/*
 * ABI: 02035C60/0201CCE4 matched void forwarders leave r0 live; this caller tests/stores it.
 */
int ZUKAN_NICKNAME_Main(ZukanNicknameWork *p)
{
    int done=0,flag;
    u32 value;
    struct WordSet *ws;
    switch(p->state) {
    case 0: break;
    case 1:
        TCBL_Main((struct TcblSystem *)(*(struct Tcbl * *)&p->tcbl));
        value=PRINTSYS_PrintStreamGetState(p->printStream);
        if(value==2) {p->state=2;p->pauseFlag=1;break;}
        switch(value) {
        case 0:
            flag=0;
            if(KEY_GetCont()&3) {UI_SetInputMode(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {UI_SetInputMode(1);flag=1;}
            if(flag!=0) PRINTSYS_PrintStreamShortWait(p->printStream,0);
            break;
        case 1:
            flag=0;
            if(KEY_GetTrg()&3) {UI_SetInputMode(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {UI_SetInputMode(1);flag=1;}
            if(flag!=0) {PRINTSYS_PrintStreamReleasePause(p->printStream);GFL_USE_PlaySeDefaultVolume(0x547);}
            break;
        }
        break;
    case 2:
        if(p->mode==2) break;
        if(p->mode==0) {
            if(p->nameStr==0) {p->state=5;break;}
            BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&p->bmpWin)),15);
            PRINTSYS_PrintStreamDelete(p->printStream);
            STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&p->strbuf));
            ws=WORDSET_CreateDefault(p->heapId);
            WORDSET_SetSlotMonNickname(ws,0,p->titleStr);
            WORDSET_SetSlotBoxName(ws,1,p->textId,p->textParam);
            p->strbuf=STRBUF_Create(64,p->heapId);
            WORDSET_CopyTaggedText(ws,p->strbuf,p->nameStr);
            WORDSET_Delete(ws);
            p->printStream=PRINTSYS_PrintStream(p->bmpWin,0,0,p->strbuf,p->font,MSG_SPEED_GetWait(),p->tcbl,(u32)2,p->heapId,15);
            p->state=3;
        } else p->state=5;
        break;
    case 3:
        TCBL_Main((struct TcblSystem *)(*(struct Tcbl * *)&p->tcbl));
        value=PRINTSYS_PrintStreamGetState(p->printStream);
        if(value==2) {p->state=4;break;}
        switch(value) {
        case 0:
            flag=0;
            if(KEY_GetCont()&3) {UI_SetInputMode(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {UI_SetInputMode(1);flag=1;}
            if(flag!=0) PRINTSYS_PrintStreamShortWait(p->printStream,0);
            break;
        case 1:
            flag=0;
            if(KEY_GetTrg()&3) {UI_SetInputMode(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {UI_SetInputMode(1);flag=1;}
            if(flag!=0) {PRINTSYS_PrintStreamReleasePause(p->printStream);GFL_USE_PlaySeDefaultVolume(0x547);}
            break;
        }
        break;
    case 4:
        ++p->counter;
        if(p->counter==60) p->state=5;
        break;
    case 5: done=1; break;
    }
    ZUKAN_NICKNAME_UpdateInfoWindow(p);
    return done;
}

void ZUKAN_NICKNAME_SetupScreen(ZukanNicknameWork *p){if(!p->state){struct Descriptor *d;unsigned flag=1;BMP_MENUWORK_DrawWindow((struct BmpWin *)p->bmpWin,1,(sptr)p->lineBuf,8);d=*(struct Descriptor * *)&p->bmpWin;BMP_WIN_TransferChars((struct BmpWin *)d);BMP_WIN_MakeScreen((struct BmpWin *)d);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));p->state=flag;}}

/*
 * Extra: ARM9-free blocker getter for assigned 0220B0A4; ownership and SDK checks clear.
 */
int ZUKAN_NICKNAME_GetResult(ZukanNicknameWork *p)
{
    return p->mode;
}

void ZUKAN_NICKNAME_TransferPalette(struct TcbTask *a, void *pArg){
    ZukanNicknameWork *p = pArg;if(p->palAnm)PALANM_TransferPalettes(p->palAnm);}

void ZUKAN_NICKNAME_InitKeyboard(ZukanNicknameWork *p)
{
    GF_OVERLAY_Load((sptr)overlay94);
    p->palAnm=PALANM_Create(p->heapId);
    PALANM_SetAutoTransfer(p->palAnm,1);
    PALANM_AllocSlotBuffers(p->palAnm,1,480,p->heapId);
    PALANM_AllocSlotBuffers(p->palAnm,3,480,p->heapId);
    p->input=BTLV_INPUT_CreateDefault(p->infoWinParam,0,p->palAnm,p->font,&p->soundEnabled,p->heapId);
    p->pauseFlag=0;
}

/*
 * lever: pooled FS overlay ID is the overlay94 linker symbol address, as in matched ov207 0220B048; literal 94 compiles as movs.
 */
void ZUKAN_NICKNAME_DeleteKeyboard(ZukanNicknameWork *p){BTLV_INPUT_Delete((struct BtlvInput *)(*(Obj * *)&p->input));PALANM_FreeSlotBuffers(p->palAnm,1);PALANM_FreeSlotBuffers(p->palAnm,3);PALANM_Delete(p->palAnm);p->palAnm=0;GF_OVERLAY_Unload((sptr)overlay94);}

void ZUKAN_NICKNAME_UpdateInfoWindow(ZukanNicknameWork *a)
{
    S3 s;

    switch (a->pauseFlag) {
    case 0:
    case 3:
        break;
    case 1:
        a->soundEnabled = (UI_GetInputMode() == 0) ? 1 : 0;
        {
            struct MsgBank *r5 = MSGDATA_CreateFromArchive(0, 2, 0xe9, ((ZukanNicknameWork *)a)->heapId);
            s.primaryText = MSGDATA_AllocString((struct MsgBank *)r5, 0);
            s.secondaryText = MSGDATA_AllocString((struct MsgBank *)r5, 1);
            s.enabled = 1;
            BTLV_INPUT_ChangeScreen((struct BtlvInput *)a->input, 4, &s);
            STRBUF_Delete(s.primaryText);
            STRBUF_Delete(s.secondaryText);
            MSGDATA_Delete((struct MsgBank *)r5);
            a->pauseFlag = 2;
        }
        break;
    case 2:
        {
            int r5 = BTLV_INPUT_ProcessTouchInput((struct BtlvInput *)a->input, &d_0220BBEC, d_0220BBF8);
            if (r5 == -1)
                break;
            BTLV_INPUT_ChangeScreen((struct BtlvInput *)a->input, 0, 0);
            a->pauseFlag = 3;
            if (r5 == 0)
                a->mode = 1;
            else
                a->mode = 0;
            UI_SetInputMode(a->soundEnabled ? 0 : 1);
        }
        break;
    }
    BTLV_INPUT_UpdateInfoWindow((struct BtlvInput *)a->input);
}
