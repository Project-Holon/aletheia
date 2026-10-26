/*
 * file:     manual_touchbar.c
 * unit:     yes
 * function: MANUAL_COMMON_CreateTouchbar, MANUAL_COMMON_DeleteTouchbar, MANUAL_COMMON_UpdateTouchbar, MANUAL_COMMON_SetTouchbarState, MANUAL_COMMON_SetTouchbarSelection, MANUAL_COMMON_GetTouchbarSelected, MANUAL_COMMON_GetTouchbarPressed, MANUAL_COMMON_TouchbarTaskNoop, MANUAL_COMMON_CreateTouchbarWidget, MANUAL_COMMON_TouchbarNoop, MANUAL_COMMON_CreateTouchbarSlots, MANUAL_COMMON_DeleteTouchbarSlots, MANUAL_COMMON_UpdateTouchbarSlots, MANUAL_COMMON_DrawTouchbarIdle, MANUAL_COMMON_DrawTouchbarStart, MANUAL_COMMON_DrawTouchbarEnd, MANUAL_COMMON_DrawTouchbarContinue, MANUAL_COMMON_LoadTouchbarActors, MANUAL_COMMON_DeleteTouchbarActors, MANUAL_COMMON_UpdateTouchbarActors, MANUAL_COMMON_ResetTouchbar
 * address:  0x021B9F24
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from manual_common.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   ov067_id 0x00000043 data a1
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   gManualCommonTouchbarAllocFile 0x021BC014 data a1
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   gManualCommonTouchbarButtonIds 0x021BBF2C data a4
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   gManualCommonTouchbarBgTable 0x021BBF4C data a4
 *   MI_CpuFill8 0x02082BCC arm
 *   MANUAL_GRAPHIC_GetClactUnit 0x021B9A08 thumb ov225
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   gManualCommonSlotRecords 0x021BBF00 data a1
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   gManualCommonActorEntries 0x021BBF14 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   UI_SetInputMode 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   gManualGraphicMainBgLayerTable  0x021BBE4C  data
 */
#include "../types.h"
#include "manual_common_shared_types.h"
#include "manual_touchbar_shared_types.h"
#include "../ov067/touchbar_types.h"

struct CharBuf;

struct Cfg;

struct WordSet;

struct Actor;

struct ManualTouchbar;

/* Touch bar object built by MANUAL_COMMON_CreateTouchbar (0x4C). */
struct ManualTouchbar {
    void *owner;                /* 0x00 */
    TouchBar *touchbar;  /* 0x04 TOUCHBAR handle */
    u32 mode;                   /* 0x08 */
    u8 selectX;                 /* 0x0C */
    u8 selectY;                 /* 0x0D */
    u8 pad0E[2];                /* 0x0E */
    struct BmpWin *bmp[2];      /* 0x10 */
    u32 bmpDirty[2];            /* 0x18 */
    u32 pressState;             /* 0x20 */
    int pressedId;              /* 0x24 */
    int releasedId;             /* 0x28 */
    u32 animPalette;            /* 0x2C */
    u32 animCharacter;          /* 0x30 */
    u32 animCell;               /* 0x34 */
    struct ClactActor *actor[2]; /* 0x38 */
    u8 focusIndex;              /* 0x40 */
    u8 pad41[3];                /* 0x41 */
    u32 animState;              /* 0x44 */
    void *task;                 /* 0x48 */
};


struct ManualBgTable {u32 words[16];};

struct ManualEntryRecord {unsigned word[7];};

struct ManualBmpParams {u8 layer,baseX,baseY,tiles,palette,mode,slot,pad7,pad8;};

struct ManualActorEntry { u32 first; u16 normal,pad6; u8 left,right,top,bottom; u32 active,mask,sound,last; };

#include "../arm9/gfl_heap_wrap.h"


struct TcbTask;
struct ClactActor;
struct Bmp;
struct BmpWin;
struct PrintQueue;
struct Strbuf;
struct MsgBank;
struct GfFont;
#include "../arm9/strbuf_types.h"
#include "../arm9/tcb_list.h"
#include "../ov067/touchbar_types.h"
#include "../ov099/wifi_club_work.h"
#include "../arm9/arc_tool.h"


#include "../arm9/printsys.h"

#include "../arm9/gf_overlay.h"

#include "../arm9/gfl_use.h"
struct TcbTask;









#include "../arm9/mi_memory.h"

#include "manual_graphic.h"

/* The DS code passes the heap id as a word (the original prototype); the header takes a halfword. The host build uses the header. */
#ifdef __MWERKS__
#define TOUCHBAR_Create TOUCHBAR_Create_header
#endif
#include "../ov067/touchbar.h"
#ifdef __MWERKS__
#undef TOUCHBAR_Create
extern TouchBar *TOUCHBAR_Create(TouchBarParams *params, int heapId);
#endif
struct BmpWin;

extern struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir);
struct Bmp;

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

#include "../arm9/bmp.h"

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern void PRINTSYS_QUE_Clear(struct PrintQueue *),BMP_WIN_Delete(struct Descriptor *);
struct Bmp;
struct PrintQueue;


extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

#include "../arm9/bg_sys.h"
struct MsgBank;
struct Strbuf;

#include "../arm9/msgdata.h"
struct GfFont;


#include "../arm9/strbuf.h"

#include "../arm9/gf_font.h"
struct Strbuf;


#include "../arm9/wordset.h"



#include "../arm9/app_icon.h"







#include "../arm9/clact.h"
struct Unit;








#include "../arm9/key.h"

#include "../arm9/ui.h"

#include "../arm9/touchpanel.h"




void *MANUAL_COMMON_CreateTouchbar(char *owner);

void MANUAL_COMMON_DeleteTouchbar(char *p);

void MANUAL_COMMON_UpdateTouchbar(char *p);

void MANUAL_COMMON_SetTouchbarState(char *p,unsigned state);

void MANUAL_COMMON_SetTouchbarSelection(char *p,unsigned b,unsigned c);

unsigned MANUAL_COMMON_GetTouchbarSelected(char *p);

unsigned MANUAL_COMMON_GetTouchbarPressed(char *p);

void MANUAL_COMMON_TouchbarTaskNoop(struct TcbTask *task, void *data);

void MANUAL_COMMON_CreateTouchbarWidget(char *p);

void MANUAL_COMMON_TouchbarNoop(void *unused);

void MANUAL_COMMON_CreateTouchbarSlots(char *p);

void MANUAL_COMMON_DeleteTouchbarSlots(char *p);

void MANUAL_COMMON_UpdateTouchbarSlots(char *p);

void MANUAL_COMMON_DrawTouchbarIdle(char *p);

void MANUAL_COMMON_DrawTouchbarStart(char *p);

void MANUAL_COMMON_DrawTouchbarEnd(char *p);

void MANUAL_COMMON_DrawTouchbarContinue(char *p);

void MANUAL_COMMON_LoadTouchbarActors(char *p);

void MANUAL_COMMON_DeleteTouchbarActors(char *p);

void MANUAL_COMMON_UpdateTouchbarActors(char *p);

void MANUAL_COMMON_ResetTouchbar(char *p);

extern const char ov067_id[];

extern const char gManualCommonTouchbarAllocFile[];

extern const struct ManualEntryRecord gManualCommonTouchbarButtonIds[];

extern const struct ManualBgTable gManualCommonTouchbarBgTable;

extern const struct ManualBmpParams gManualCommonSlotRecords[];

extern const struct ManualActorEntry gManualCommonActorEntries[];

void *MANUAL_COMMON_CreateTouchbar(char *owner)
{
    char *touchbar;
    GF_OVERLAY_Load((sptr)ov067_id);
    touchbar=GFL_HEAP_Alloc(((struct ManualData *)owner)->heap,sizeof(struct ManualTouchbar),1,gManualCommonTouchbarAllocFile,235);
    ((struct ManualTouchbar *)touchbar)->owner=owner;MANUAL_COMMON_CreateTouchbarWidget(touchbar);MANUAL_COMMON_TouchbarNoop(touchbar);MANUAL_COMMON_CreateTouchbarSlots(touchbar);MANUAL_COMMON_LoadTouchbarActors(touchbar);
    ((struct ManualTouchbar *)touchbar)->mode=4;((struct ManualTouchbar *)touchbar)->selectX=0;((struct ManualTouchbar *)touchbar)->selectY=0;MANUAL_COMMON_SetTouchbarState(touchbar,0);MANUAL_COMMON_ResetTouchbar(touchbar);
    ((struct ManualTouchbar *)touchbar)->task=GFL_USE_AddMainTask(MANUAL_COMMON_TouchbarTaskNoop,(void *)(touchbar),1);
    return touchbar;
}

void MANUAL_COMMON_DeleteTouchbar(char *touchbar){TCB_DeleteTask(((struct ManualTouchbar *)touchbar)->task);MANUAL_COMMON_DeleteTouchbarActors(touchbar);MANUAL_COMMON_DeleteTouchbarSlots(touchbar);TOUCHBAR_Delete((TouchBar *)(*(unsigned char * *)&((struct ManualTouchbar *)touchbar)->touchbar));GFL_HEAP_Free(touchbar);GF_OVERLAY_Unload((sptr)ov067_id);}

void MANUAL_COMMON_UpdateTouchbar(char *touchbar)
{
    ((struct ManualTouchbar *)touchbar)->pressedId=-1;((struct ManualTouchbar *)touchbar)->releasedId=-1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
    if(((struct ManualTouchbar *)touchbar)->pressState==1) {((struct ManualTouchbar *)touchbar)->pressState=0;return;}
    if(((struct ManualTouchbar *)touchbar)->pressState==0 || ((struct ManualTouchbar *)touchbar)->pressState==2) {
        TOUCHBAR_Update(((struct ManualTouchbar *)touchbar)->touchbar);
        if(((struct ManualTouchbar *)touchbar)->pressState==0) {
            int result=TOUCHBAR_GetPressedButtonIdIfPressing(((struct ManualTouchbar *)touchbar)->touchbar);
            if(result!=-1) {((struct ManualTouchbar *)touchbar)->pressState=2;((struct ManualTouchbar *)touchbar)->pressedId=result;}
        } else {
            int result=TOUCHBAR_GetPressedButtonIdIfDone(((struct ManualTouchbar *)touchbar)->touchbar);
            if(result!=-1) {((struct ManualTouchbar *)touchbar)->pressState=1;((struct ManualTouchbar *)touchbar)->releasedId=result;}
        }
    }
    if(((struct ManualTouchbar *)touchbar)->pressState==0 || ((struct ManualTouchbar *)touchbar)->pressState==3) {
        MANUAL_COMMON_UpdateTouchbarActors(touchbar);
        if(((struct ManualTouchbar *)touchbar)->pressState==0) {
            if(((struct ManualTouchbar *)touchbar)->animState==1) {((struct ManualTouchbar *)touchbar)->pressState=3;*(unsigned *)&((struct ManualTouchbar *)touchbar)->pressedId=gManualCommonTouchbarButtonIds[((struct ManualTouchbar *)touchbar)->focusIndex].word[0];}
        } else {
            if(((struct ManualTouchbar *)touchbar)->animState==3) {((struct ManualTouchbar *)touchbar)->pressState=1;*(unsigned *)&((struct ManualTouchbar *)touchbar)->releasedId=gManualCommonTouchbarButtonIds[((struct ManualTouchbar *)touchbar)->focusIndex].word[0];}
        }
    }
}

void MANUAL_COMMON_SetTouchbarState(char *touchbar,unsigned state)
{
    if(((struct ManualTouchbar *)touchbar)->mode==state)return;
    switch(((struct ManualTouchbar *)touchbar)->mode) {
    case 0:TOUCHBAR_SetButtonVisible(((struct ManualTouchbar *)touchbar)->touchbar,0,0);break;
    case 3:CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[0])),0);CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[1])),0);break;
    case 1:case 2:case 4:break;
    }
    ((struct ManualTouchbar *)touchbar)->mode=state;MANUAL_COMMON_ResetTouchbar(touchbar);
    switch(((struct ManualTouchbar *)touchbar)->mode) {
    case 0:TOUCHBAR_SetButtonVisible(((struct ManualTouchbar *)touchbar)->touchbar,0,1);MANUAL_COMMON_DrawTouchbarIdle(touchbar);break;
    case 1:MANUAL_COMMON_DrawTouchbarStart(touchbar);break;
    case 2:MANUAL_COMMON_DrawTouchbarEnd(touchbar);break;
    case 3:case 4:break;
    }
}

/*
 * trailing: 021BA152..021BA154 zero alignment padding, inspected in full show.
 */
void MANUAL_COMMON_SetTouchbarSelection(char *touchbar,unsigned count,unsigned selected)
{
    ((struct ManualTouchbar *)touchbar)->selectX=count;((struct ManualTouchbar *)touchbar)->selectY=selected;
    if(((struct ManualTouchbar *)touchbar)->mode==3) {
        if(((struct ManualTouchbar *)touchbar)->selectX<=1) {
            CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[0])),0);CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[1])),0);MANUAL_COMMON_DrawTouchbarIdle(touchbar);return;
        }
        if(((struct ManualTouchbar *)touchbar)->selectY==0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[0])),0);CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[1])),1);
        } else if(((struct ManualTouchbar *)touchbar)->selectY==count-1) {
            CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[0])),1);CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[1])),0);
        } else {
            CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[0])),1);CLACT_SetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualTouchbar *)touchbar)->actor[1])),1);
        }
        MANUAL_COMMON_DrawTouchbarContinue(touchbar);
    }
}

unsigned MANUAL_COMMON_GetTouchbarSelected(char *touchbar){return ((struct ManualTouchbar *)touchbar)->releasedId;}

unsigned MANUAL_COMMON_GetTouchbarPressed(char *touchbar){return ((struct ManualTouchbar *)touchbar)->pressedId;}

void MANUAL_COMMON_TouchbarTaskNoop(struct TcbTask *task, void *data)
{
}

/*
 * lever: args before gManualGraphicMainBgLayerTable declaration puts the 64-byte copy at sp+0.
 */
void MANUAL_COMMON_CreateTouchbarWidget(char *touchbar)
{
    TouchBarParams args;
    struct ManualBgTable gManualGraphicMainBgLayerTable=gManualCommonTouchbarBgTable;
    MI_CpuFill8(&args,0,sizeof(args));
    args.defs=(TouchBarButtonDef *)&gManualGraphicMainBgLayerTable;args.count=2;
    args.actorSys=MANUAL_GRAPHIC_GetClactUnit(((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->screen);
    args.bgLayer=6;args.bgPlttSlot=3;args.actorPlttSlot=1;args.iconSet=0;
    ((struct ManualTouchbar *)touchbar)->touchbar=TOUCHBAR_Create(&args,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    TOUCHBAR_SetButtonVisible(((struct ManualTouchbar *)touchbar)->touchbar,0,0);
}

void MANUAL_COMMON_TouchbarNoop(void *unused){}

void MANUAL_COMMON_CreateTouchbarSlots(char *touchbar)
{
    u8 i;
    for(i=0;i<2;i++) {
        const struct ManualBmpParams *t=&gManualCommonSlotRecords[i];
        ((struct ManualTouchbar *)touchbar)->bmp[i]=BMP_WIN_Create(t->layer,t->baseX,t->baseY,t->tiles,t->palette,t->mode,t->slot);
        BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(((struct ManualTouchbar *)touchbar)->bmp[i]))),0);
        BMP_WIN_TransferChars((struct BmpWin *)(((struct ManualTouchbar *)touchbar)->bmp[i]));
        ((struct ManualTouchbar *)touchbar)->bmpDirty[i]=0;
    }
}

void MANUAL_COMMON_DeleteTouchbarSlots(char *touchbar){unsigned char i;PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue[2]);for(i=0;i<2;i++){((struct ManualTouchbar *)touchbar)->bmpDirty[i]=0;BMP_WIN_Delete((void *)((struct ManualTouchbar *)touchbar)->bmp[i]);}}

void MANUAL_COMMON_UpdateTouchbarSlots(char *touchbar)
{
    u8 i;
    for(i=0;i<2;i++) {
        if(((struct ManualTouchbar *)touchbar)->bmpDirty[i]!=0) {
            if(PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(*(struct PrintQueue * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue[2]),(struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(((struct ManualTouchbar *)touchbar)->bmp[i]))))==0) {
                struct BmpWin *d=((struct ManualTouchbar *)touchbar)->bmp[i];
                BMP_WIN_TransferChars((struct BmpWin *)d);BMP_WIN_MakeScreen((struct BmpWin *)d);
                BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));
                ((struct ManualTouchbar *)touchbar)->bmpDirty[i]=0;
            }
        }
    }
}

void MANUAL_COMMON_DrawTouchbarIdle(char *touchbar){PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue[2]);BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp[1]))),0);BMP_WIN_TransferChars((struct BmpWin *)(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp[1]));((struct ManualTouchbar *)touchbar)->bmpDirty[1]=0;}

void MANUAL_COMMON_DrawTouchbarStart(char *touchbar)
{
    void *s;
    PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue[2]);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp[1])),0);
    s=MSGDATA_AllocString(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->bank[0],2);
    PRINTSYS_PrintQueColor((void *)((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue[2],BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp[1])),0,4,s,(struct GfFont *)(((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->font),0x3c40);
    STRBUF_Delete(s);((struct ManualTouchbar *)touchbar)->bmpDirty[1]=1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
}

void MANUAL_COMMON_DrawTouchbarEnd(char *touchbar)
{
    void *s;
    PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue[2]);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp[1])),0);
    s=MSGDATA_AllocString(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->bank[0],3);
    PRINTSYS_PrintQueColor((void *)((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue[2],BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp[1])),0,4,s,(struct GfFont *)(((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->font),0x3c40);
    STRBUF_Delete(s);((struct ManualTouchbar *)touchbar)->bmpDirty[1]=1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
}

/*
 * extent: 178 compiled bytes followed by two zero alignment bytes at 021BA41A.
 */
void MANUAL_COMMON_DrawTouchbarContinue(char *touchbar)
{
    struct WordSet *words;
    struct U16Vec *str;
    void *slot;
    PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue[2]);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp[1])),0);
    words=WORDSET_CreateDefault(((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    slot=MSGDATA_AllocString(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->bank[0],4);
    str=(struct U16Vec *)STRBUF_Create(16,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    WORDSET_SetSlotNumber(words,0,((struct ManualTouchbar *)touchbar)->selectY+1,1,0,1);
    WORDSET_SetSlotNumber(words,1,((struct ManualTouchbar *)touchbar)->selectX,1,0,1);
    WORDSET_CopyTaggedText(words,(struct Strbuf *)str,slot);
    PRINTSYS_PrintQueColor((void *)((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue[2],BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp[1])),32,4,(struct Strbuf *)str,(struct GfFont *)(((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->font),0x3c40);
    STRBUF_Delete((struct Strbuf *)str);STRBUF_Delete(slot);WORDSET_Delete(words);
    ((struct ManualTouchbar *)touchbar)->bmpDirty[1]=1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
}

void MANUAL_COMMON_LoadTouchbarActors(char *touchbar)
{
    u8 i;
    void *loader;
    u32 first;
    loader=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    *(int *)&((struct ManualTouchbar *)touchbar)->animCharacter=CLACT_RegisterPaletteEx((void *)((uptr)loader),APP_ICON_GetMoveKindPaletteFileId(),1,128,0,3,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    *(int *)&((struct ManualTouchbar *)touchbar)->animPalette=CLACT_RegisterCharacter((void *)((uptr)loader),APP_ICON_GetMoveKindAnimFileId(),0,1,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    first=APP_ICON_GetStatusCellFileId(0);
    *(int *)&((struct ManualTouchbar *)touchbar)->animCell=CLACT_RegisterCellAnim((void *)((uptr)loader),first,APP_ICON_GetStatusPaletteFileId(0),((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    ARC_TOOL_DeleteHandle(loader);
    for(i=0;i<2;i++) {
        char *parent=*(char * *)&((struct ManualTouchbar *)touchbar)->owner;
        ((struct ManualTouchbar *)touchbar)->actor[i]=CLACT_CreateActor(MANUAL_GRAPHIC_GetClactUnit(((struct ManualData *)parent)->screen),((struct ManualTouchbar *)touchbar)->animPalette,((struct ManualTouchbar *)touchbar)->animCharacter,((struct ManualTouchbar *)touchbar)->animCell,(struct ActorInitParam *)(&gManualCommonActorEntries[i]),1,((struct ManualData *)parent)->heap);
        CLACT_SetActorDrawEnable((struct ClactActor *)((((struct ManualTouchbar *)touchbar)->actor[i])),0);
        CLACT_SetActorAutoAnim((struct ClactActor *)((((struct ManualTouchbar *)touchbar)->actor[i])),1);
    }
}

void MANUAL_COMMON_DeleteTouchbarActors(char *touchbar) { u8 i; for(i=0;i<2;i++) CLACT_DeleteActor((struct ClactActor *)((((struct ManualTouchbar *)touchbar)->actor[i]))); CLACT_ReleaseCellAnim(((struct ManualTouchbar *)touchbar)->animCell); CLACT_ReleaseCharacter(((struct ManualTouchbar *)touchbar)->animPalette); CLACT_ReleasePalette(((struct ManualTouchbar *)touchbar)->animCharacter); }

void MANUAL_COMMON_UpdateTouchbarActors(char *touchbar)
{
 u8 i;
 u32 found,x,y;
 const struct ManualActorEntry *row;
 switch(((struct ManualTouchbar *)touchbar)->animState) {
 case 0:
  found=0;
  for(i=0;i<2;i++) {
   if(CLACT_GetActorDrawEnable((struct ClactActor *)((((struct ManualTouchbar *)touchbar)->actor[i])))) {
    row=&gManualCommonActorEntries[i];
    if(KEY_GetRepeat()&row->mask) {
     ((struct ManualTouchbar *)touchbar)->focusIndex=i;
     UI_SetInputMode(0);
     found=1;
     break;
    }
    if(TOUCHPANEL_GetPointTrg(&x,&y)) {
     if(row->left<=x && x<=row->right && row->top<=y && y<=row->bottom) {
      ((struct ManualTouchbar *)touchbar)->focusIndex=i;
      found=1;
      UI_SetInputMode(1);
      break;
     }
    }
   }
  }
  if(found) {
   CLACT_SetActorAnimSeq((struct ClactActor *)((((struct ManualTouchbar *)touchbar)->actor[((struct ManualTouchbar *)touchbar)->focusIndex])),gManualCommonActorEntries[((struct ManualTouchbar *)touchbar)->focusIndex].active);
   if(gManualCommonActorEntries[((struct ManualTouchbar *)touchbar)->focusIndex].sound) GFL_USE_PlaySeDefaultVolume(gManualCommonActorEntries[((struct ManualTouchbar *)touchbar)->focusIndex].sound);
   ((struct ManualTouchbar *)touchbar)->animState=1;
  }
  break;
 case 1: ((struct ManualTouchbar *)touchbar)->animState=2; break;
 case 2:
  if(!CLACT_IsActorAnimActive((struct ClactActor *)(((struct ManualTouchbar *)touchbar)->actor[((struct ManualTouchbar *)touchbar)->focusIndex]))) {
   CLACT_SetActorAnimSeq((struct ClactActor *)((((struct ManualTouchbar *)touchbar)->actor[((struct ManualTouchbar *)touchbar)->focusIndex])),gManualCommonActorEntries[((struct ManualTouchbar *)touchbar)->focusIndex].normal);
   ((struct ManualTouchbar *)touchbar)->animState=3;
  }
  break;
 case 3: ((struct ManualTouchbar *)touchbar)->animState=0; ((struct ManualTouchbar *)touchbar)->focusIndex=255; break;
 }
}

void MANUAL_COMMON_ResetTouchbar(char *touchbar)
{
    int z = 0;
    int m = z - 1;
    ((struct ManualTouchbar *)touchbar)->pressState = z;
    ((struct ManualTouchbar *)touchbar)->pressedId = m;
    ((struct ManualTouchbar *)touchbar)->releasedId = m;
    ((struct ManualTouchbar *)touchbar)->focusIndex = 0xFF;
    ((struct ManualTouchbar *)touchbar)->animState = z;
}
