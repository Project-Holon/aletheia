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
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
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
#include "manual_data_shared_types.h"
#include "manual_common_shared_types.h"
#include "manual_touchbar_shared_types.h"

struct CharBuf;

struct Cfg;

struct WordSet;

struct Actor;

struct ManualTouchbar;

struct TouchBar;

/* Touch bar object built by MANUAL_COMMON_CreateTouchbar (0x4C). */
struct ManualTouchbar {
    void *owner;                /* 0x00 */
    void *touchbar;             /* 0x04 TOUCHBAR handle */
    u32 mode;                   /* 0x08 */
    u8 selectX;                 /* 0x0C */
    u8 selectY;                 /* 0x0D */
    u8 pad0E[6];                /* 0x0E */
    void *bmp0;                 /* 0x14 */
    u32 pad18;                  /* 0x18 */
    u32 bmp0Dirty;              /* 0x1C */
    u32 pressState;             /* 0x20 */
    int pressedId;              /* 0x24 */
    int releasedId;             /* 0x28 */
    u32 animPalette;            /* 0x2C */
    u32 animCharacter;          /* 0x30 */
    u32 animCell;               /* 0x34 */
    void *actor0;               /* 0x38 */
    void *actor1;               /* 0x3C */
    u8 focusIndex;              /* 0x40 */
    u8 pad41[3];                /* 0x41 */
    u32 animState;              /* 0x44 */
    void *task;                 /* 0x48 */
};

/* Argument block for TOUCHBAR_Create. */
typedef struct {u8 *bgTable;u32 layer;int clactUnit;u32 cellW,cellH,flags;int reserved18,reserved1C;} ManualTouchbarArgs;

struct ManualBgTable {u32 words[16];};

struct ManualEntryRecord {unsigned word[7];};

struct ManualBmpParams {u8 layer,baseX,baseY,tiles,palette,mode,slot,pad7,pad8;};

struct ManualActorEntry { u32 first; u16 normal,pad6; u8 left,right,top,bottom; u32 active,mask,sound,last; };

extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);

extern u32 GFL_HEAP_Free(void *p);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern void ARC_TOOL_DeleteHandle(void *);

extern void PRINTSYS_QUE_Clear(struct PrintSys *);

extern int GF_OVERLAY_Load(int);

extern void *GFL_USE_AddMainTask(unsigned,unsigned,unsigned);

extern void TCB_DeleteTask(struct Node *n);

extern void TOUCHBAR_Delete(unsigned char *);

extern void GF_OVERLAY_Unload(int);

extern void TOUCHBAR_Update(struct TouchBar *p);

extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *);

extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);

extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);

extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);

extern void MI_CpuFill8(void *,u8,u32);

extern u32 MANUAL_GRAPHIC_GetClactUnit(const u8 *p);

extern struct ManualRes *TOUCHBAR_Create(ManualTouchbarArgs *,int);

extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,u8,u8,u8);

extern void *BMP_WIN_GetBmp(struct Descriptor *);

extern void BMP_Clear(struct CharBuf *,u8);

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void PRINTSYS_QUE_Clear(struct PrintSys *),BMP_WIN_Delete(struct Descriptor *);

extern unsigned PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *);

extern void BMP_WIN_MakeScreen(struct Cfg *);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);

extern void BG_SYS_SetFlagField06(unsigned);

extern void *MSGDATA_AllocString(struct MsgBank *,unsigned);

extern void PRINTSYS_PrintQueColor(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);

extern void STRBUF_Delete(struct U16Vec *);

extern struct WordSet *WORDSET_CreateDefault(u32);

extern struct U16Vec *STRBUF_Create(u32,u32);

extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);

extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32 APP_ICON_GetArchiveId(void);

extern u32 APP_ICON_GetMoveKindPaletteFileId(void);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern u32 APP_ICON_GetMoveKindAnimFileId(void);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern u32 APP_ICON_GetStatusCellFileId(u32);

extern u32 APP_ICON_GetStatusPaletteFileId(u32);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorAutoAnim(struct Obj *,u32);

extern void CLACT_DeleteActor(struct Obj *);

extern void CLACT_ReleaseCellAnim(u32);

extern void CLACT_ReleaseCharacter(u32);

extern void CLACT_ReleasePalette(u32);

extern u32 CLACT_GetActorDrawEnable(struct Obj *);

extern u32 KEY_GetRepeat(void);

extern void UI_SetInputMode(u8);

extern u32 TOUCHPANEL_GetPointTrg(u32 *,u32 *);

extern void CLACT_SetActorAnimSeq(struct Obj *,u16);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern u32 CLACT_IsActorAnimActive(struct Actor *);

void *MANUAL_COMMON_CreateTouchbar(char *owner);

void MANUAL_COMMON_DeleteTouchbar(char *p);

void MANUAL_COMMON_UpdateTouchbar(char *p);

void MANUAL_COMMON_SetTouchbarState(char *p,unsigned state);

void MANUAL_COMMON_SetTouchbarSelection(char *p,unsigned b,unsigned c);

unsigned MANUAL_COMMON_GetTouchbarSelected(char *p);

unsigned MANUAL_COMMON_GetTouchbarPressed(char *p);

void MANUAL_COMMON_TouchbarTaskNoop(void *task,void *data);

void MANUAL_COMMON_CreateTouchbarWidget(char *p);

void MANUAL_COMMON_TouchbarNoop(void *a0);

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
    GF_OVERLAY_Load((int)ov067_id);
    touchbar=GFL_HEAP_Alloc(((struct ManualData *)owner)->heap,0x4c,1,gManualCommonTouchbarAllocFile,235);
    ((struct ManualTouchbar *)touchbar)->owner=owner;MANUAL_COMMON_CreateTouchbarWidget(touchbar);MANUAL_COMMON_TouchbarNoop(touchbar);MANUAL_COMMON_CreateTouchbarSlots(touchbar);MANUAL_COMMON_LoadTouchbarActors(touchbar);
    ((struct ManualTouchbar *)touchbar)->mode=4;touchbar[0xc]=0;touchbar[0xd]=0;MANUAL_COMMON_SetTouchbarState(touchbar,0);MANUAL_COMMON_ResetTouchbar(touchbar);
    ((struct ManualTouchbar *)touchbar)->task=GFL_USE_AddMainTask((unsigned)MANUAL_COMMON_TouchbarTaskNoop,(unsigned)touchbar,1);
    return touchbar;
}

void MANUAL_COMMON_DeleteTouchbar(char *touchbar){TCB_DeleteTask(((struct ManualTouchbar *)touchbar)->task);MANUAL_COMMON_DeleteTouchbarActors(touchbar);MANUAL_COMMON_DeleteTouchbarSlots(touchbar);TOUCHBAR_Delete(*(unsigned char * *)&((struct ManualTouchbar *)touchbar)->touchbar);GFL_HEAP_Free(touchbar);GF_OVERLAY_Unload((int)ov067_id);}

void MANUAL_COMMON_UpdateTouchbar(char *touchbar)
{
    ((struct ManualTouchbar *)touchbar)->pressedId=-1;((struct ManualTouchbar *)touchbar)->releasedId=-1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
    if(((struct ManualTouchbar *)touchbar)->pressState==1) {((struct ManualTouchbar *)touchbar)->pressState=0;return;}
    if(((struct ManualTouchbar *)touchbar)->pressState==0 || ((struct ManualTouchbar *)touchbar)->pressState==2) {
        TOUCHBAR_Update(*(struct TouchBar * *)&((struct ManualTouchbar *)touchbar)->touchbar);
        if(((struct ManualTouchbar *)touchbar)->pressState==0) {
            int result=TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((struct ManualTouchbar *)touchbar)->touchbar);
            if(result!=-1) {((struct ManualTouchbar *)touchbar)->pressState=2;((struct ManualTouchbar *)touchbar)->pressedId=result;}
        } else {
            int result=TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct ManualTouchbar *)touchbar)->touchbar);
            if(result!=-1) {((struct ManualTouchbar *)touchbar)->pressState=1;((struct ManualTouchbar *)touchbar)->releasedId=result;}
        }
    }
    if(((struct ManualTouchbar *)touchbar)->pressState==0 || ((struct ManualTouchbar *)touchbar)->pressState==3) {
        MANUAL_COMMON_UpdateTouchbarActors(touchbar);
        if(((struct ManualTouchbar *)touchbar)->pressState==0) {
            if(((struct ManualTouchbar *)touchbar)->animState==1) {((struct ManualTouchbar *)touchbar)->pressState=3;*(unsigned *)&((struct ManualTouchbar *)touchbar)->pressedId=gManualCommonTouchbarButtonIds[*(u8 *)(touchbar+0x40)].word[0];}
        } else {
            if(((struct ManualTouchbar *)touchbar)->animState==3) {((struct ManualTouchbar *)touchbar)->pressState=1;*(unsigned *)&((struct ManualTouchbar *)touchbar)->releasedId=gManualCommonTouchbarButtonIds[*(u8 *)(touchbar+0x40)].word[0];}
        }
    }
}

void MANUAL_COMMON_SetTouchbarState(char *touchbar,unsigned state)
{
    if(((struct ManualTouchbar *)touchbar)->mode==state)return;
    switch(((struct ManualTouchbar *)touchbar)->mode) {
    case 0:TOUCHBAR_SetButtonVisible(((struct ManualTouchbar *)touchbar)->touchbar,0,0);break;
    case 3:CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,0);break;
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
    touchbar[0xc]=count;touchbar[0xd]=selected;
    if(((struct ManualTouchbar *)touchbar)->mode==3) {
        if(((struct ManualTouchbar *)touchbar)->selectX<=1) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,0);MANUAL_COMMON_DrawTouchbarIdle(touchbar);return;
        }
        if(((struct ManualTouchbar *)touchbar)->selectY==0) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,1);
        } else if(((struct ManualTouchbar *)touchbar)->selectY==count-1) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,1);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,0);
        } else {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,1);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,1);
        }
        MANUAL_COMMON_DrawTouchbarContinue(touchbar);
    }
}

unsigned MANUAL_COMMON_GetTouchbarSelected(char *touchbar){return ((struct ManualTouchbar *)touchbar)->releasedId;}

unsigned MANUAL_COMMON_GetTouchbarPressed(char *touchbar){return ((struct ManualTouchbar *)touchbar)->pressedId;}

void MANUAL_COMMON_TouchbarTaskNoop(void *task,void *data)
{
}

/*
 * lever: args before gManualGraphicMainBgLayerTable declaration puts the 64-byte copy at sp+0.
 */
void MANUAL_COMMON_CreateTouchbarWidget(char *touchbar)
{
    ManualTouchbarArgs args;
    struct ManualBgTable gManualGraphicMainBgLayerTable=gManualCommonTouchbarBgTable;
    MI_CpuFill8(&args,0,sizeof(args));
    args.bgTable=(u8 *)&gManualGraphicMainBgLayerTable;args.layer=2;
    args.clactUnit=(int)MANUAL_GRAPHIC_GetClactUnit(((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->screen);
    args.cellW=6;args.cellH=3;args.flags=1;args.reserved18=0;
    *(struct ManualRes * *)&((struct ManualTouchbar *)touchbar)->touchbar=TOUCHBAR_Create(&args,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    TOUCHBAR_SetButtonVisible(((struct ManualTouchbar *)touchbar)->touchbar,0,0);
}

void MANUAL_COMMON_TouchbarNoop(void *unused){}

void MANUAL_COMMON_CreateTouchbarSlots(char *touchbar)
{
    u8 i;
    for(i=0;i<2;i++) {
        const struct ManualBmpParams *t=&gManualCommonSlotRecords[i];
        *(unsigned *)(touchbar+i*4+0x10)=BMP_WIN_Create(t->layer,t->baseX,t->baseY,t->tiles,t->palette,t->mode,t->slot);
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(touchbar+i*4+0x10)),0);
        BMP_WIN_TransferChars(*(struct Descriptor **)(touchbar+i*4+0x10));
        *(unsigned *)(touchbar+i*4+0x18)=0;
    }
}

void MANUAL_COMMON_DeleteTouchbarSlots(char *touchbar){unsigned char i;PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);for(i=0;i<2;i++){*(unsigned *)((unsigned)touchbar+i*4+24)=0;BMP_WIN_Delete(*(struct Descriptor **)((unsigned)touchbar+i*4+16));}}

void MANUAL_COMMON_UpdateTouchbarSlots(char *touchbar)
{
    u8 i;
    for(i=0;i<2;i++) {
        if(*(unsigned *)(touchbar+i*4+0x18)!=0) {
            if(PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2,BMP_WIN_GetBmp(*(struct Descriptor **)(touchbar+i*4+0x10)))==0) {
                struct Descriptor *d=*(struct Descriptor **)(touchbar+i*4+0x10);
                BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);
                BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(d));
                *(unsigned *)(touchbar+i*4+0x18)=0;
            }
        }
    }
}

void MANUAL_COMMON_DrawTouchbarIdle(char *touchbar){PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0);BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0);((struct ManualTouchbar *)touchbar)->bmp0Dirty=0;}

void MANUAL_COMMON_DrawTouchbarStart(char *touchbar)
{
    void *s;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0);
    s=MSGDATA_AllocString(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->bank0,2);
    PRINTSYS_PrintQueColor((void *)((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2,(unsigned)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0,4,(unsigned)s,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->font,0x3c40);
    STRBUF_Delete(s);((struct ManualTouchbar *)touchbar)->bmp0Dirty=1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
}

void MANUAL_COMMON_DrawTouchbarEnd(char *touchbar)
{
    void *s;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0);
    s=MSGDATA_AllocString(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->bank0,3);
    PRINTSYS_PrintQueColor((void *)((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2,(unsigned)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0,4,(unsigned)s,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->font,0x3c40);
    STRBUF_Delete(s);((struct ManualTouchbar *)touchbar)->bmp0Dirty=1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
}

/*
 * extent: 178 compiled bytes followed by two zero alignment bytes at 021BA41A.
 */
void MANUAL_COMMON_DrawTouchbarContinue(char *touchbar)
{
    struct WordSet *words;
    struct U16Vec *str;
    void *slot;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0);
    words=WORDSET_CreateDefault(((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    slot=MSGDATA_AllocString(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->bank0,4);
    str=STRBUF_Create(16,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    WORDSET_SetSlotNumber(words,0,((struct ManualTouchbar *)touchbar)->selectY+1,1,0,1);
    WORDSET_SetSlotNumber(words,1,((struct ManualTouchbar *)touchbar)->selectX,1,0,1);
    WORDSET_CopyTaggedText(words,str,slot);
    PRINTSYS_PrintQueColor((void *)((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2,(u32)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),32,4,(u32)str,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->font,0x3c40);
    STRBUF_Delete(str);STRBUF_Delete(slot);WORDSET_DeleteStrbufED04(words);
    ((struct ManualTouchbar *)touchbar)->bmp0Dirty=1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
}

void MANUAL_COMMON_LoadTouchbarActors(char *touchbar)
{
    u8 i;
    void *loader;
    u32 first;
    loader=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    *(int *)&((struct ManualTouchbar *)touchbar)->animCharacter=CLACT_RegisterPaletteEx((void *)((u32)loader),APP_ICON_GetMoveKindPaletteFileId(),1,128,0,3,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    *(int *)&((struct ManualTouchbar *)touchbar)->animPalette=CLACT_RegisterCharacter((void *)((u32)loader),APP_ICON_GetMoveKindAnimFileId(),0,1,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    first=APP_ICON_GetStatusCellFileId(0);
    *(int *)&((struct ManualTouchbar *)touchbar)->animCell=CLACT_RegisterCellAnim((void *)((u32)loader),first,APP_ICON_GetStatusPaletteFileId(0),((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    ARC_TOOL_DeleteHandle(loader);
    for(i=0;i<2;i++) {
        char *parent=*(char * *)&((struct ManualTouchbar *)touchbar)->owner;
        char *dest=touchbar+i*4;
        *(struct Obj * *)&((struct ManualTouchbar *)dest)->actor0=CLACT_CreateActor((void *)MANUAL_GRAPHIC_GetClactUnit(((struct ManualData *)parent)->screen),((struct ManualTouchbar *)touchbar)->animPalette,((struct ManualTouchbar *)touchbar)->animCharacter,((struct ManualTouchbar *)touchbar)->animCell,&gManualCommonActorEntries[i],1,((struct ManualData *)parent)->heap);
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)dest)->actor0,0);
        CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct ManualTouchbar *)dest)->actor0,1);
    }
}

void MANUAL_COMMON_DeleteTouchbarActors(char *touchbar) { u8 i; for(i=0;i<2;i++) CLACT_DeleteActor(*(struct Obj **)(touchbar+i*4+0x38)); CLACT_ReleaseCellAnim(((struct ManualTouchbar *)touchbar)->animCell); CLACT_ReleaseCharacter(((struct ManualTouchbar *)touchbar)->animPalette); CLACT_ReleasePalette(((struct ManualTouchbar *)touchbar)->animCharacter); }

void MANUAL_COMMON_UpdateTouchbarActors(char *touchbar)
{
 u8 i;
 u32 found,x,y;
 const struct ManualActorEntry *row;
 switch(((struct ManualTouchbar *)touchbar)->animState) {
 case 0:
  found=0;
  for(i=0;i<2;i++) {
   if(CLACT_GetActorDrawEnable(*(struct Obj **)(touchbar+i*4+0x38))) {
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
   CLACT_SetActorAnimSeq(*(struct Obj **)(touchbar+((struct ManualTouchbar *)touchbar)->focusIndex*4+0x38),gManualCommonActorEntries[*(u8 *)(touchbar+0x40)].active);
   if(gManualCommonActorEntries[*(u8 *)(touchbar+0x40)].sound) GFL_USE_PlaySeDefaultVolume(gManualCommonActorEntries[*(u8 *)(touchbar+0x40)].sound);
   ((struct ManualTouchbar *)touchbar)->animState=1;
  }
  break;
 case 1: ((struct ManualTouchbar *)touchbar)->animState=2; break;
 case 2:
  if(!CLACT_IsActorAnimActive(*(struct Actor **)(touchbar+((struct ManualTouchbar *)touchbar)->focusIndex*4+0x38))) {
   CLACT_SetActorAnimSeq(*(struct Obj **)(touchbar+((struct ManualTouchbar *)touchbar)->focusIndex*4+0x38),gManualCommonActorEntries[*(u8 *)(touchbar+0x40)].normal);
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
    *(int *)(touchbar + 0x20) = z;
    *(int *)(touchbar + 0x24) = m;
    *(int *)(touchbar + 0x28) = m;
    *(u8 *)(touchbar + 0x40) = 0xFF;
    *(int *)(touchbar + 0x44) = z;
}
