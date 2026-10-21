/*
 * file:     br_btn.c
 * unit:     yes
 * function: BR_BTN_Create, BR_BTN_Delete, BR_BTN_UpdatePrint, BR_BTN_GetPlacement, BR_BTN_GetPressed, BR_BTN_GetResultValue, BR_BTN_PushRecord, BR_BTN_Init, BR_BTN_BuildSection, BR_BTN_PushPosPair, BR_BTN_PopPosPair, BR_BTN_SetTailSelection, BR_BTN_SetupInput, BR_BTN_HandleInput, BR_BTN_UpdateSpread, BR_BTN_UpdatePress, BR_BTN_UpdateRestore, BR_BTN_UpdateHide, BR_BTN_UpdateExpand, BR_BTN_UpdateCollapse, BR_BTN_UpdateBack, BR_BTN_UpdateTextInput, BR_BTN_UpdateSlide, BR_BTN_UpdateHide2, BR_BTN_InitRecord, BR_BTN_DeleteRecord, BR_BTN_HitTest, BR_BTN_SetAnimMode, BR_BTN_StepAnim, BR_BTN_SetMode, BR_BTN_CopyRecord, BR_BTN_PlaceIndexed, BR_BTN_GetPos, BR_BTN_SetPosY, BR_BTN_GetRowField, BR_BTN_SetDrawPriority, BR_BTN_SetBgPriority, BR_BTN_SetSelected, BR_BTN_SetPos, BR_BTN_AnimMove, BR_BTN_AnimMoveRow, BR_BTN_AnimFlyOut, BR_BTN_AnimFlyIn, BR_BTN_AnimMove2, BR_BTN_CreateFromMessage, BR_BTN_CreateObject, BR_BTN_DeleteObject, BR_BTN_HitTestWithSound, BR_BTN_TestHitBox, BR_BTN_SetObjectPos, BR_BTN_GetObjectPos, BR_BTN_SetObjectDrawPriority, BR_BTN_GetObjectDrawPriority, BR_BTN_SetObjectBgPriority, BR_BTN_GetObjectBgPriority, BR_BTN_SetObjectPalette
 * address:  0x021F9CB8
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, BR_MEMBER_COUNT_GetU16Count.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   d_02200D18 0x02200D18 data a1
 *   d_02200D1C 0x02200D1C data a1
 *   BR_UTIL_DeleteTask  0x021FD714  thumb  ov186
 *   BR_UTIL_DeleteTextWin  0x021FD15C  thumb  ov186
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   d_02200358 0x02200358 data a4
 *   STRBUF_Clone 0x02045874 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   BMP_Create 0x02043678 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_OAM_SetObjMode 0x0202597C thumb
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   BMP_OAM_SetDrawPriority  0x020259C4  thumb
 *   CLACT_GetActorDrawPriority 0x0204B838 arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   BMP_OAM_SetBgPriority  0x02025A0C  thumb
 *   CLACT_GetActorBgPriority 0x0204B864 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   BMP_OAM_SetPalette 0x02025A54 thumb
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_BTN_DATA_Create 0x021FB5E4 thumb ov186
 *   BR_BTN_DATA_Delete 0x021FB63C thumb ov186
 *   BR_BTN_DATA_GetRow 0x021FB704 thumb ov186
 *   BR_BTN_DATA_GetSectionCount 0x021FB760 thumb ov186
 *   BR_BTN_DATA_GetMaxSectionCount 0x021FB788 thumb ov186
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   BR_BTN_DATA_CreateLabel 0x021FB7D0 thumb ov186
 */
#include "br_types.h"

struct BrPair;
struct Strbuf;

#include "../arm9/strbuf.h"

struct BmpOam;

struct Param;

struct BmpOamSys;

typedef struct Button {
    int active;                 /* 0x00 */
    int enabled;                /* 0x04 */
    char *result;               /* 0x08 */
    void *object;               /* 0x0C */
    int (*update)(struct Button *); /* 0x10 */
    int dest_x;                 /* 0x14 */
    int dest_y;                 /* 0x18 */
    int state;                  /* 0x1C */
    s16 from, to, tick, duration; /* 0x20 */
    unsigned index;             /* 0x28 */
    int *pos;                   /* 0x2C */
    char *owner;                /* 0x30 */
    unsigned short heap, pad;   /* 0x34 */
    unsigned a;                 /* 0x38 */
    void *b;                    /* 0x3C */
    struct U16Vec *work;        /* 0x40 */
} Button;

typedef struct { unsigned short x,y,z; unsigned char flag,pad; } BrBtnCreateConfig;

typedef struct Placement { short x, y; unsigned short animation; unsigned char priority, attr; } Placement;

typedef struct BrBtnSpriteInfo { int words[3]; } BrBtnSpriteInfo;

typedef struct { void *bmp;s16 x,y;u32 spriteZ,flags;u8 objMode,flip;u16 mode;u32 mode2; } Param;

typedef struct BrBtnPtS { s16 x, y; } BrBtnPtS;

struct BrBtnVec2{short x,y;};

#include "../arm9/gf_panic.h"

#include "../arm9/gfl_heap_wrap.h"

extern void MI_CpuFill8(void *, int, int);
struct BmpOamSys;

struct PrintQueue;

#include "../arm9/printsys.h"

#include "br_util.h"










#include "../arm9/touchpanel.h"

#include "../arm9/gfl_use.h"




struct MsgBank;
struct Strbuf;



#include "../arm9/msgdata.h"



typedef short s16_p07;
#include "../arm9/bmp.h"
struct GfFont;
struct Strbuf;


struct BmpOam;

struct BmpOam;










/* Callee's complete leaf reads only r0; legacy r1-r3 are unused, unforwarded. */






struct BrBtn *BR_BTN_Create(int a, int b, int c, int d, int e, int f, u16 heap);

void BR_BTN_Delete(u8 *p);

void BR_BTN_UpdatePrint(char *p);

int BR_BTN_GetPlacement(char *p,int *x,int *y);

int BR_BTN_GetPressed(char *p);

int BR_BTN_GetResultValue(char *p);

void BR_BTN_PushRecord(struct BrBtn *ctx, int source, int mode);

int BR_BTN_Init(struct BrBtn *ctx, Button *out);

void BR_BTN_BuildSection(struct BrBtn *p,int section,const int *pos);

void BR_BTN_PushPosPair(char *p,int x,int y);

void BR_BTN_PopPosPair(char *p);

void BR_BTN_SetTailSelection(struct BrBtn *ctx, int mode);

void BR_BTN_SetupInput(void *p);

void BR_BTN_HandleInput(void *p,int *state,struct BrBtn *ctx);

void BR_BTN_UpdateSpread(void *p, int *state, struct BrBtn *ctx);

void BR_BTN_UpdatePress(void *p,int *state,struct BrBtn *ctx);

void BR_BTN_UpdateRestore(void *p, int *state, struct BrBtn *ctx);

void BR_BTN_UpdateHide(void *p, int *state, struct BrBtn *ctx);

void BR_BTN_UpdateExpand(void *p,int *state,struct BrBtn *ctx);

void BR_BTN_UpdateCollapse(int *task,int *state,struct BrBtn *ctx);

void BR_BTN_UpdateBack(void *p, int *state, struct BrBtn *ctx);

void BR_BTN_UpdateTextInput(void *p, int *state, struct BrBtn *ctx);

void BR_BTN_UpdateSlide(void *p, int *state, struct BrBtn *ctx);

void BR_BTN_UpdateHide2(void *p, int *state, struct BrBtn *ctx);

void BR_BTN_InitRecord(Button *ctx, void *object, unsigned a, void *b, char *owner, const void *arg, unsigned index, unsigned short heap);

void BR_BTN_DeleteRecord(Button *p);

int BR_BTN_HitTest(Button *p, int x, int y);

void BR_BTN_SetAnimMode(Button *ctx, int mode, const int *target);

int BR_BTN_StepAnim(Button *ctx);

void BR_BTN_SetMode(Button *ctx, int mode);

void BR_BTN_CopyRecord(void *ctx, Button *dest, const Button *source, int mode);

void BR_BTN_PlaceIndexed(Button *p, unsigned index);

void BR_BTN_GetPos(Button *p, int *out);

void BR_BTN_SetPosY(Button *p, int y);

int BR_BTN_GetRowField(Button *ctx, int kind);

void BR_BTN_SetDrawPriority(Button *p, int b);

void BR_BTN_SetBgPriority(Button *p, int b);

void BR_BTN_SetSelected(Button *p, unsigned value);

void BR_BTN_SetPos(Button *p, unsigned value);

int BR_BTN_AnimMove(Button *ctx);

int BR_BTN_AnimMoveRow(Button *ctx);

int BR_BTN_AnimFlyOut(Button *p);

int BR_BTN_AnimFlyIn(Button *p);

int BR_BTN_AnimMove2(Button *ctx);

void *BR_BTN_CreateFromMessage(void *ctx, u16 file, unsigned short a, int b, void *c, void *d, void *e, struct MsgBank *archive, void *config, unsigned short heap);

struct BrButton *BR_BTN_CreateObject(const BrBtnPlacement *pt,void *data,u16 a,u32 b,void *c,void *owner,void *font,const BrBtnSpriteIds *triple,u16 heap);

void BR_BTN_DeleteObject(char *p);

int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);

int BR_BTN_TestHitBox(u32 *p, int x, int y);

void BR_BTN_SetObjectPos(char *p, short x, int y);

void BR_BTN_GetObjectPos(char *p,short *x,short *y);

void BR_BTN_SetObjectDrawPriority(int *p, unsigned char b);

int BR_BTN_GetObjectDrawPriority(char *p);

void BR_BTN_SetObjectBgPriority(int *p, int b);

unsigned BR_BTN_GetObjectBgPriority(char *p);

void BR_BTN_SetObjectPalette(char *p,int n);

#include "br_btn_data.h"

struct BrBtnTable;





struct BrRes;

#include "br_res.h"





#include "../arm9/bmp_oam.h"
#include "../arm9/clact.h"
extern char d_02200D18[];

extern char d_02200D1C[];

extern const int d_02200358[];

struct BrBtn *BR_BTN_Create(int a, int b, int c, int d, int e, int f, u16 heap)
{
    struct BrBtn *p;
    int tmp;
    int size;
    int i;
    sptr arch;
    u8 buf[0x44];
    if (a >= 12) GF_PANIC_Fail(d_02200D18, 0, d_02200D18);
    p = GFL_HEAP_Alloc(heap, 0x60, 0, d_02200D1C, 0x13F);
    MI_CpuFill8(p, 0, 0x60);
    p->resBase = c;
    p->oamData = b;
    p->heap = heap;
    p->resultSet = (struct BrBtnResultSet *)e;
    p->oamSys = BMP_OAM_CreateSys(heap, (void *)b);
    p->printQue = (uptr)PRINTSYS_QUE_Create((unsigned int)heap);
    p->effect = f;
    p->pressed = 1;
    MI_CpuFill8(&tmp, 0, 4);
    tmp = d;
    p->dataTable = BR_BTN_DATA_Create(&tmp, heap);
    if (a >= 10) p->spriteIndex = 2;
    else p->spriteIndex = 0;
    BR_RES_LoadSprite((struct BrRes *)p->resBase, p->spriteIndex, heap);
    BR_RES_LoadSprite((struct BrRes *)p->resBase, p->spriteIndex + 1, heap);
    p->rowCount = BR_BTN_DATA_GetMaxSectionCount(p->dataTable);
    size = p->rowCount * 0x44;
    p->rowRecords = GFL_HEAP_Alloc(heap, size, 0, d_02200D1C, 0x167);
    MI_CpuFill8(p->rowRecords, 0, size);
    p->maxRows = 6;
    p->tailRecords = GFL_HEAP_Alloc(heap, 0x198, 0, d_02200D1C, 0x171);
    MI_CpuFill8(p->tailRecords, 0, 0x198);
    p->task = BR_UTIL_CreateTask((sptr)p, (sptr)BR_BTN_SetupInput, heap);
    if (p->resultSet->count != 0) {
        arch = BR_RES_GetMsgData((struct BrRes *)c);
        for (i = 0; i < p->resultSet->count; i++) {
            void *q = BR_BTN_DATA_GetRow(p->dataTable, p->resultSet->rec[i].a, (unsigned short)p->resultSet->rec[i].b);
            void *rec = BR_BTN_DATA_CreateLabel(p->dataTable, q, (struct MsgBank *)arch, (heap & 0x7FFF) | 0x8000);
            MI_CpuFill8(buf, 0, 0x44);
            BR_BTN_InitRecord((Button *)buf, q, b, p->oamSys, (char *)c, rec, p->spriteIndex, heap);
            BR_BTN_PushRecord(p, (sptr)buf, 0);
            STRBUF_Delete(rec);
        }
        for (i = 0; i < p->recordCount; i++)
            BR_BTN_PlaceIndexed((Button *)(p->tailRecords + (p->recordCount - i - 1) * 0x44), (unsigned short)i);
        BR_UTIL_SetTaskStep(p->task, (sptr)BR_BTN_UpdateCollapse);
        p->resultKind = 2;
    } else {
        arch = BR_RES_GetMsgData((struct BrRes *)c);
        p->sectionCount = BR_BTN_DATA_GetSectionCount(p->dataTable, a);
        for (i = 0; i < p->sectionCount; i++) {
            void *q = BR_BTN_DATA_GetRow(p->dataTable, a, (unsigned short)i);
            void *rec = BR_BTN_DATA_CreateLabel(p->dataTable, q, (struct MsgBank *)arch, (heap & 0x7FFF) | 0x8000);
            BR_BTN_InitRecord((Button *)(p->rowRecords + i * 0x44), q, b, p->oamSys, (char *)c, rec, p->spriteIndex, heap);
            STRBUF_Delete(rec);
        }
        for (i = 0; i < p->sectionCount; i++)
            BR_BTN_SetPosY((Button *)(p->rowRecords + i * 0x44), 0xe0);
        BR_UTIL_SetTaskStep(p->task, (sptr)BR_BTN_UpdateSlide);
    }
    return p;
}

void BR_BTN_Delete(u8 *p)
{
    int i;

    BR_UTIL_DeleteTask((void *)(((struct BrBtn *)p)->task));
    if (((struct BrBtn *)p)->textWin != 0) {
        BR_UTIL_DeleteTextWin((void *)(((struct BrBtn *)p)->textWin), ((struct BrBtn *)p)->resBase);
        ((struct BrBtn *)p)->textWin = 0;
    }
    for (i = 0; i < ((struct BrBtn *)p)->recordCount; i++)
        BR_BTN_DeleteRecord((Button *)(((struct BrBtn *)p)->tailRecords + i * 0x44));
    GFL_HEAP_Free((void *)((struct BrBtn *)p)->tailRecords);
    for (i = 0; i < ((struct BrBtn *)p)->sectionCount; i++)
        BR_BTN_DeleteRecord((Button *)(((struct BrBtn *)p)->rowRecords + i * 0x44));
    GFL_HEAP_Free((void *)((struct BrBtn *)p)->rowRecords);
    BR_RES_ReleaseSprite((struct BrRes *)(((struct BrBtn *)p)->resBase), ((struct BrBtn *)p)->spriteIndex);
    BR_RES_ReleaseSprite((struct BrRes *)(((struct BrBtn *)p)->resBase), ((struct BrBtn *)p)->spriteIndex + 1);
    BR_BTN_DATA_Delete((void *)(((struct BrBtn *)p)->dataTable));
    BMP_OAM_DeleteSys((void *)(((struct BrBtn *)p)->oamSys));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((struct BrBtn *)p)->printQue));
    GFL_HEAP_Free(p);
}

void BR_BTN_UpdatePrint(char *p) { BR_UTIL_RunTask((u8 *)(((struct BrBtn *)p)->task));PRINTSYS_QUE_Main((struct PrintQueue *)(*(struct PrintSys * *)&((struct BrBtn *)p)->printQue));if(*(char * *)&((struct BrBtn *)p)->textWin)BR_UTIL_FlushWindow(*(char * *)&((struct BrBtn *)p)->textWin); }

/*
 * blocker-leaf: ov183 021DB770; source/unit/shard ownership checked, parent cleared.
 */
int BR_BTN_GetPlacement(char *p,int *x,int *y){if(x)*x=((struct BrBtn *)p)->section;if(y)*y=((struct BrBtn *)p)->offsetY;return ((struct BrBtn *)p)->placement;}

int BR_BTN_GetPressed(char *p){return ((struct BrBtn *)p)->pressed;}

int BR_BTN_GetResultValue(char *p){return ((struct BrBtn *)p)->resultValue;}

void BR_BTN_PushRecord(struct BrBtn *ctx, int source, int mode)
{
    int i;

    if (ctx->recordCount >= ctx->maxRows)
        GF_PANIC_Fail((const char *)d_02200D18, 0, (const char *)d_02200D18);
    BR_BTN_CopyRecord(ctx, (Button *)(*(u8 * *)&ctx->tailRecords + ctx->recordCount * 0x44), (const Button *)source, mode);
    ctx->recordCount++;
    for (i = 0; i < ctx->recordCount; i++) {
        BR_BTN_SetDrawPriority((Button *)(*(u8 * *)&ctx->tailRecords + i * 0x44), (u16)((ctx->recordCount - i) * 2 + 1));
        BR_BTN_SetBgPriority((Button *)(*(u8 * *)&ctx->tailRecords + i * 0x44), 1);
    }
}

int BR_BTN_Init(struct BrBtn *ctx, Button *out)
{
    if (ctx->recordCount) {
        ctx->recordCount--;
        *out = (*(Button **)((u8 *)ctx + 0x3c))[ctx->recordCount];
        MI_CpuFill8(&(*(Button **)((u8 *)ctx + 0x3c))[ctx->recordCount], 0, 0x44);
        return 1;
    }
    return 0;
}

void BR_BTN_BuildSection(struct BrBtn *p,int section,const int *pos)
{
 int i; sptr bank;
 void *rec,*text;
 for(i=0;i<p->rowCount;i++)BR_BTN_DeleteRecord((Button *)(*(u8 * *)&p->rowRecords+i*0x44));
 bank=BR_RES_GetMsgData((struct BrRes *)(*(char * *)&p->resBase));
 p->sectionCount=BR_BTN_DATA_GetSectionCount(p->dataTable,section);
 for(i=0;i<p->sectionCount;i++){
  rec=BR_BTN_DATA_GetRow((struct BrBtnTable *)(*(char * *)&p->dataTable),section,(u16)i);
  text=BR_BTN_DATA_CreateLabel(*(unsigned *const * *)&p->dataTable,rec,(struct MsgBank *)bank,(p->heap&0x7fff)|0x8000);
  BR_BTN_InitRecord((Button *)(*(u8 * *)&p->rowRecords+i*0x44), rec, p->oamData, (void *)(p->oamSys), (char *)(p->resBase), text, p->spriteIndex, p->heap);
  STRBUF_Delete(text);
  BR_BTN_SetDrawPriority((Button *)(*(u8 * *)&p->rowRecords+i*0x44), 3);
  if(pos)BR_BTN_SetObjectPos(*(void **)(*(u8 * *)&p->rowRecords+i*0x44+8),pos[0],(short)pos[1]);
 }
}

void BR_BTN_PushPosPair(char *p,int x,int y) { if(((struct BrBtnResultSet *)p)->count>=6)GF_PANIC_Fail(d_02200D18,0,d_02200D18);*(unsigned short *)((uptr)p+((struct BrBtnResultSet *)p)->count*4)=x;*(unsigned short *)((uptr)p+((struct BrBtnResultSet *)p)->count*4+2)=y;(((struct BrBtnResultSet *)p)->count)++; }

void BR_BTN_PopPosPair(char *p) { if (((struct BrBtnResultSet *)p)->count!=0) (((struct BrBtnResultSet *)p)->count)--; }

void BR_BTN_SetTailSelection(struct BrBtn *ctx, int mode)
{
    int i, selected;
    for (i = 0; i < ctx->recordCount; i++) {
        switch (mode) {
        case 0: selected = (i == ctx->recordCount - 1); break;
        case 1: selected = (i >= ctx->recordCount - 2); break;
        }
        if (selected)
            BR_BTN_SetSelected((Button *)(*(char * *)&ctx->tailRecords + i * 0x44), 0);
        else
            BR_BTN_SetSelected((Button *)(*(char * *)&ctx->tailRecords + i * 0x44), 1);
    }
}

void BR_BTN_SetupInput(void *p)
{
    BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_HandleInput);
}

void BR_BTN_HandleInput(void *p,int *state,struct BrBtn *ctx)
{
 int found,i,x,y,kind;
 found=0;ctx->placement=0;ctx->pressed=0;
 if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
  for(i=0;i<ctx->rowCount;i++){
   if(BR_BTN_HitTest((Button *)(int *)(*(char * *)&ctx->rowRecords+i*0x44), x, y)){
    if(BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords+i*0x44), 3)){
     if(ctx->textWin){
      BR_UTIL_DeleteTextWin((void *)(ctx->textWin),ctx->resBase);
      ctx->textWin=0;
     }
     GFL_USE_PlaySeDefaultVolume(0x703);
     ctx->selected=i;
     found=1;
     ctx->touchX=x;ctx->touchY=y;
     BR_UTIL_StartEffect(*(char * *)&ctx->effect,7,(BrPair *)((u8 *)ctx + 0x30));
     BR_BTN_SetPos((Button *)(*(char * *)&ctx->rowRecords+ctx->selected*0x44), (uptr)((BrPair *)((u8 *)ctx + 0x30)));
     ctx->resultValue=0;
    }else{
     kind=BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords+i*0x44), 5);
     BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords+i*0x44), 6);
     GFL_USE_PlaySeDefaultVolume(0x704);
     if(kind==1){ctx->selected=i;BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateTextInput);}
    }
    break;
   }
  }
 }
 if(found){
  ctx->pressed=1;
  *(int *)&ctx->resultKind=BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords+ctx->selected*0x44), 0);
  ctx->kind3=BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords+ctx->selected*0x44), 3);
  ctx->section=BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords+ctx->selected*0x44), 1);
  ctx->offsetY=BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords+ctx->selected*0x44), 2);
  for(i=0;i<ctx->sectionCount;i++){
   if(i==ctx->selected)BR_BTN_SetDrawPriority((Button *)(*(char * *)&ctx->rowRecords+i*0x44), 1);
   else BR_BTN_SetDrawPriority((Button *)(*(char * *)&ctx->rowRecords+i*0x44), 3);
  }
  switch(ctx->resultKind){
  case 2:BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateHide);break;
  case 0:case 1:case 4:BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateSpread);break;
  case 3:BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateHide2);break;
  default:BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateBack);break;
  }
 }
}

void BR_BTN_UpdateSpread(void *p, int *state, struct BrBtn *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx->sectionCount; i++) {
            if (ctx->selected != i) {
                BR_BTN_GetPos((Button *)(*(char * *)&ctx->rowRecords + ctx->selected * 0x44), values);
                BR_BTN_SetAnimMode((Button *)(*(char * *)&ctx->rowRecords + i * 0x44), 0, values);
            }
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx->sectionCount; i++)
            ready &= BR_BTN_StepAnim((Button *)(*(char * *)&ctx->rowRecords + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2:
        if (ctx->resultKind == 4) {
            BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_UpdatePress);
            return;
        } else {
            BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_UpdatePress);
        }
        break;
    }
}

/*
 * lever: unsigned mode <= 1 range guard retains the original compare chain; switch(0,1,2) differs.
 */
void BR_BTN_UpdatePress(void *p,int *state,struct BrBtn *ctx)
{
 int section,index,value,i,y;
 int pos[2],other[2];
 Button record;
 if(ctx->resultKind<=1){
  section=ctx->section;
  BR_BTN_GetPos((Button *)(*(char * *)&ctx->rowRecords+ctx->selected*0x44), pos);
  BR_BTN_PushRecord(ctx,(sptr)(*(char * *)&ctx->rowRecords+ctx->selected*0x44),1);
  index=ctx->selected;
  value=BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords+index*0x44), 4);
  BR_BTN_PushPosPair((char *)ctx->resultSet,(u16)value,(u16)index);
  MI_CpuFill8(*(char * *)&ctx->rowRecords+ctx->selected*0x44,0,0x44);
  pos[1]=-32;
  BR_BTN_BuildSection(ctx,section,pos);
  BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateExpand);
 }else if(ctx->resultKind==2){
  BR_BTN_PopPosPair((char *)ctx->resultSet);
  if(BR_BTN_Init(ctx, (Button *)&record)){
   section=BR_BTN_GetRowField((Button *)&record, 4);
   if(!record.active)GF_PANIC_Fail(d_02200D18,0,d_02200D18);
   other[0]=BR_BTN_DATA_GetRowField(record.object,0);
   other[1]=BR_BTN_DATA_GetRowField(record.object,1);
   BR_BTN_BuildSection(ctx,section,other);
   y=BR_BTN_DATA_GetRowField(record.object,1);
   for(i=0;i<ctx->sectionCount;i++){
    if(y==BR_BTN_DATA_GetRowField((void *)(*(int *)(*(char * *)&ctx->rowRecords+i*0x44+0xc)),1))
     BR_BTN_SetDrawPriority((Button *)(*(char * *)&ctx->rowRecords+i*0x44), 1);
   }
   BR_BTN_DeleteRecord((Button *)(&record));
   BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateRestore);
  }
 }else{
  BR_BTN_PushRecord(ctx,(sptr)(*(char * *)&ctx->rowRecords+ctx->selected*0x44),1);
  index=ctx->selected;
  value=BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords+index*0x44), 4);
  BR_BTN_PushPosPair((char *)ctx->resultSet,(u16)value,(u16)index);
  MI_CpuFill8(*(char * *)&ctx->rowRecords+ctx->selected*0x44,0,0x44);
  for(i=0;i<ctx->sectionCount;i++)BR_BTN_DeleteRecord((Button *)(*(char * *)&ctx->rowRecords+i*0x44));
  BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateExpand);
 }
}

void BR_BTN_UpdateRestore(void *p, int *state, struct BrBtn *ctx)
{
    int i, ready;
    switch (*state) {
    case 0:
        for (i = 0; i < ctx->sectionCount; i++)
            BR_BTN_SetAnimMode((Button *)(*(char * *)&ctx->rowRecords + i * 0x44), 1, 0);
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx->sectionCount; i++)
            ready &= BR_BTN_StepAnim((Button *)(*(char * *)&ctx->rowRecords + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2:
        switch (ctx->resultKind) {
        case 0: case 1: BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_UpdateBack); break;
        case 4: BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_UpdateExpand); break;
        default: BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_UpdateBack); break;
        }
        break;
    }
}

void BR_BTN_UpdateHide(void *p, int *state, struct BrBtn *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx->sectionCount; i++) {
            BR_BTN_GetPos((Button *)(*(char * *)&ctx->rowRecords + i * 0x44), values);
            values[1] = 0xe0;
            BR_BTN_SetAnimMode((Button *)(*(char * *)&ctx->rowRecords + i * 0x44), 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx->sectionCount; i++)
            ready &= BR_BTN_StepAnim((Button *)(*(char * *)&ctx->rowRecords + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2: BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_UpdateCollapse); break;
    }
}

void BR_BTN_UpdateExpand(void *p,int *state,struct BrBtn *ctx)
{
 int i,ready,kind;
 unsigned short value;
 char *entry;
 switch(*state){
 case 0:
  for(i=0;i<ctx->recordCount;i++){
   if(i==ctx->recordCount-1)BR_BTN_SetAnimMode((Button *)(*(char * *)&ctx->tailRecords+i*0x44), 2, d_02200358);
   else BR_BTN_SetAnimMode((Button *)(*(char * *)&ctx->tailRecords+i*0x44), 4, d_02200358+(ctx->recordCount-i-1)*2);
  }
  *state=1;break;
 case 1:
  ready=1;
  for(i=0;i<ctx->recordCount;i++)ready&=BR_BTN_StepAnim((Button *)(*(char * *)&ctx->tailRecords+i*0x44));
  if(ready){BR_BTN_SetTailSelection(ctx,0);*state=2;}break;
 case 2:
  entry=*(char * *)&ctx->tailRecords+(ctx->recordCount-1)*0x44;
  kind=BR_BTN_GetRowField((Button *)entry, 0);
  value=BR_BTN_GetRowField((Button *)entry, 2);
  if(kind==1){
   if(!ctx->textWin)ctx->textWin=BR_UTIL_CreateTextWin((void *)((ctx->resBase)),(void *)(ctx->printQue),ctx->heap);
   BR_UTIL_SetWindowText(ctx->textWin,(char *)ctx->resBase,(void *)value);
  }
  *state=3;break;
 case 3:
  switch(ctx->resultKind){
  case 0:case 1:BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateRestore);break;
  default:BR_UTIL_SetTaskStep(p,(sptr)BR_BTN_UpdateBack);break;
  }
  break;
 }
}

void BR_BTN_UpdateCollapse(int *task,int *state,struct BrBtn *ctx)
{
    int position[2];
    int i;
    int ready;
    switch(*state) {
    case 0:
        for(i=0;i<ctx->recordCount;i++) {
            if(i==ctx->recordCount-1) {
                position[0]=BR_BTN_DATA_GetRowField(*(void **)(*(u8 * *)&ctx->tailRecords+i*0x44+0xC),0);
                position[1]=BR_BTN_DATA_GetRowField(*(void **)(*(u8 * *)&ctx->tailRecords+i*0x44+0xC),1);
                BR_BTN_SetAnimMode((Button *)(*(char * *)&ctx->tailRecords+i*0x44), 3, position);
                BR_BTN_SetDrawPriority((Button *)(*(char * *)&ctx->tailRecords+i*0x44), 1);
            } else BR_BTN_SetAnimMode((Button *)(*(char * *)&ctx->tailRecords+i*0x44), 4, (const int *)((uptr)d_02200358+(ctx->recordCount-i-2)*8));
        }
        for(i=0;i<ctx->sectionCount;i++)BR_BTN_SetDrawPriority((Button *)(*(char * *)&ctx->rowRecords+i*0x44), 3);
        *state=1;
        break;
    case 1:
        ready=1;
        for(i=0;i<ctx->recordCount;i++)ready&=BR_BTN_StepAnim((Button *)(*(char * *)&ctx->tailRecords+i*0x44));
        if(ready){BR_BTN_SetTailSelection(ctx,1);*state=2;}
        break;
    case 2:BR_UTIL_SetTaskStep(task,(sptr)BR_BTN_UpdatePress);break;
    }
}

void BR_BTN_UpdateBack(void *p, int *state, struct BrBtn *ctx)
{
    if (*state == 0) {
        if (ctx->kind3) {
            switch ((int)ctx->resultKind) {
            case 0: case 1: case 2: break;
            case 3: ctx->placement = 2; break;
            case 4: ctx->placement = 1; break;
            }
        }
        BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_HandleInput);
    }
}

void BR_BTN_UpdateTextInput(void *p, int *state, struct BrBtn *ctx)
{
    sptr value;
    switch (*state) {
    case 0:
        value = BR_BTN_GetRowField((Button *)((uptr)ctx->rowRecords + ctx->selected * 0x44), 6);
        if (ctx->textWin == 0)
            ctx->textWin = BR_UTIL_CreateTextWin(((void *)ctx->resBase), (void *)ctx->printQue, ctx->heap);
        BR_UTIL_SetWindowText(ctx->textWin, (void *)ctx->resBase, (void *)value);
        *state = 1;
        break;
    case 1: *state = 2; break;
    case 2: BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_HandleInput); break;
    }
}

void BR_BTN_UpdateSlide(void *p, int *state, struct BrBtn *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx->sectionCount; i++) {
            values[0] = BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords + i * 0x44), 8);
            values[1] = BR_BTN_GetRowField((Button *)(*(char * *)&ctx->rowRecords + i * 0x44), 9);
            BR_BTN_SetAnimMode((Button *)(*(char * *)&ctx->rowRecords + i * 0x44), 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx->sectionCount; i++)
            ready &= BR_BTN_StepAnim((Button *)(*(char * *)&ctx->rowRecords + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2: BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_SetupInput); break;
    }
}

void BR_BTN_UpdateHide2(void *p, int *state, struct BrBtn *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx->sectionCount; i++) {
            BR_BTN_GetPos((Button *)(*(char * *)&ctx->rowRecords + i * 0x44), values);
            values[1] = 0xe0;
            BR_BTN_SetAnimMode((Button *)(*(char * *)&ctx->rowRecords + i * 0x44), 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx->sectionCount; i++)
            ready &= BR_BTN_StepAnim((Button *)(*(char * *)&ctx->rowRecords + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2: BR_UTIL_SetTaskStep(p, (sptr)BR_BTN_UpdateBack); break;
    }
}

/*
 * lever: 02045874 takes the source and heap, forwarding r1 unchanged to its allocator.
 * evidence: matched arm9/STRBUF_Clone.c; original 021FAC58 loads heap into r1,
 * then loads source into r0 at021FAC5A before storing heap and calling021FAC62.
 */
void BR_BTN_InitRecord(Button *ctx, void *object, unsigned a, void *b, char *owner, const void *arg, unsigned index, unsigned short heap)
{
    unsigned info[3];
    BrBtnCreateConfig config;
    const void *work;
    unsigned short heap_value;
    if (ctx->active) GF_PANIC_Fail(d_02200D18, 0, d_02200D18);
    MI_CpuFill8(ctx, 0, 0x44);
    ctx->active = 1;
    ctx->enabled = 1;
    ctx->object = object;
    ctx->index = index;
    ctx->owner = owner;
    heap_value = heap;
    work = arg;
    ctx->heap = heap_value;
    ctx->a = a;
    ctx->b = b;
    ctx->work = (struct U16Vec *)STRBUF_Clone((struct Strbuf *)work, heap_value);
    MI_CpuFill8(&config, 0, 8);
    config.x = BR_BTN_DATA_GetRowField(ctx->object, 0);
    config.y = BR_BTN_DATA_GetRowField(ctx->object, 1);
    config.z = BR_BTN_DATA_GetRowField(ctx->object, 4);
    config.flag = 1;
    BR_RES_GetSprite((struct BrRes *)owner, ctx->index + 1, info);
    ctx->result = (char *)BR_BTN_CreateObject((const BrBtnPlacement *)&config, ctx->work, 0xa0, ctx->enabled, (void *)a, b, (void *)BR_RES_GetFont((struct BrRes *)owner), (const BrBtnSpriteIds *)info, (unsigned short)((heap & 0x7fff) | 0x8000));
}

void BR_BTN_DeleteRecord(Button *p)
{
    if (p->active != 0) {
        STRBUF_Delete((struct Strbuf *)p->work);
        BR_BTN_DeleteObject(p->result);
        MI_CpuFill8(p, 0, 0x44);
    }
}

/*
 * BR_BTN_TestHitBox reads r0, r1, r2 (obj, x, y); this function forwards its
 * incoming r1 and r2 untouched.  Naming them keeps r1 and r2 live, which is
 * why the original tests p[0] in r3 (the old one-parameter spelling put it
 * in r1 and missed by 2 bytes).
 */
int BR_BTN_HitTest(Button *p, int x, int y)
{
    if (p->active != 0)
        return BR_BTN_TestHitBox((u32 *)p->result, x, y);
    return 0;
}

void BR_BTN_SetAnimMode(Button *ctx, int mode, const int *target)
{
    ctx->state = 0;
    if (target) {
        ctx->dest_x = target[0];
        ctx->dest_y = target[1];
    }
    switch (mode) {
    case 0: ctx->update = BR_BTN_AnimMove; break;
    case 1: ctx->update = BR_BTN_AnimMoveRow; break;
    case 2: ctx->update = BR_BTN_AnimFlyOut; break;
    case 3: ctx->update = BR_BTN_AnimFlyIn; break;
    case 4: ctx->update = BR_BTN_AnimMove2; break;
    }
}

/*
 * tail: 021FADB6..021FADB8 is two zero alignment bytes.
 */
int BR_BTN_StepAnim(Button *ctx)
{
    short x, y;
    int result;
    if (ctx->update != 0) {
        result = ctx->update(ctx);
        if (result != 0) ctx->update = 0;
        if (ctx->pos != 0) {
            BR_BTN_GetObjectPos(ctx->result, &x, &y);
            ctx->pos[0] = x + 80;
            ctx->pos[1] = y;
        }
        return result;
    }
    return 1;
}

void BR_BTN_SetMode(Button *ctx, int mode)
{
    BrBtnSpriteInfo config;
    Placement placement;
    short x, y;
    int priority;
    int attr;
    int shift;
    uptr resource;
    if (ctx->enabled == mode) return;
    ctx->enabled = mode;
    BR_BTN_GetObjectPos(ctx->result, &x, &y);
    priority = BR_BTN_GetObjectDrawPriority(ctx->result);
    attr = BR_BTN_GetObjectBgPriority(ctx->result);
    BR_BTN_DeleteObject(ctx->result);
    ctx->pos = 0;
    shift = mode == 0 ? 512 : -512;
    MI_CpuFill8(&placement, 0, sizeof(placement));
    placement.x = x;
    placement.y = y + shift;
    placement.animation = BR_BTN_DATA_GetRowField(ctx->object, 4);
    placement.priority = priority;
    placement.attr = attr;
    BR_RES_GetSprite((struct BrRes *)ctx->owner, ctx->index + mode, &config);
    resource = BR_RES_GetFont((struct BrRes *)ctx->owner);
    BR_RES_GetMsgData((struct BrRes *)ctx->owner);
    BR_BTN_DATA_GetRowField(ctx->object, 3);
    ctx->result = (char *)BR_BTN_CreateObject((const BrBtnPlacement *)&placement, ctx->work, 160, mode, (void *)ctx->a, ctx->b, (void *)resource, (const BrBtnSpriteIds *)&config, ctx->heap);
}

void BR_BTN_CopyRecord(void *ctx, Button *dest, const Button *source, int mode)
{
    if (dest->active != 0) GF_PANIC_Fail(d_02200D18, 0, d_02200D18);
    if (source->active != 1) GF_PANIC_Fail(d_02200D18, 0, d_02200D18);
    *dest = *source;
    if (source->enabled != mode) BR_BTN_SetMode(dest, mode);
}

void BR_BTN_PlaceIndexed(Button *p, unsigned index) { short x = (short)BR_BTN_DATA_GetRowField(p->object, 0); BR_BTN_SetObjectPos(p->result, x, (short)(169 - (index << 4))); }

void BR_BTN_GetPos(Button *p, int *out) { short x, y; BR_BTN_GetObjectPos(p->result, &x, &y); out[0] = x; out[1] = y; }

void BR_BTN_SetPosY(Button *p, int y)
{
    short r = (short)BR_BTN_DATA_GetRowField(p->object, 0);

    BR_BTN_SetObjectPos(p->result, r, y);
}

int BR_BTN_GetRowField(Button *ctx, int kind)
{
    int result;
    switch (kind) {
    case 0: result = BR_BTN_DATA_GetRowField(ctx->object, 5); break;
    case 1: result = BR_BTN_DATA_GetRowField(ctx->object, 6); break;
    case 2: result = BR_BTN_DATA_GetRowField(ctx->object, 7); break;
    case 5: result = BR_BTN_DATA_GetRowField(ctx->object, 9); break;
    case 6: result = BR_BTN_DATA_GetRowField(ctx->object, 10); break;
    case 3: result = BR_BTN_DATA_GetRowField(ctx->object, 8); break;
    case 4: result = BR_BTN_DATA_GetRowField(ctx->object, 2); break;
    case 7: result = BR_BTN_DATA_GetRowField(ctx->object, 11); break;
    case 8: result = BR_BTN_DATA_GetRowField(ctx->object, 0); break;
    case 9: result = BR_BTN_DATA_GetRowField(ctx->object, 1); break;
    default: result = 0; GF_PANIC_Fail(d_02200D18, 0, d_02200D18); break;
    }
    return result;
}

void BR_BTN_SetDrawPriority(Button *p, int b)
{
    BR_BTN_SetObjectDrawPriority((int *)p->result, (unsigned char)b);
}

void BR_BTN_SetBgPriority(Button *p, int b)
{
    BR_BTN_SetObjectBgPriority((int *)p->result, (unsigned char)b);
}

void BR_BTN_SetSelected(Button *p, unsigned value) { BR_BTN_SetObjectPalette(p->result, value); }

void BR_BTN_SetPos(Button *p, unsigned value) { p->pos = (int *)value; }

/*
 * tail: 021FB056..021FB058 is two zero alignment bytes.
 */
int BR_BTN_AnimMove(Button *ctx)
{
    int position[2];
    short x;
    short value;
    switch (ctx->state) {
    case 0:
        BR_BTN_GetPos(ctx, position);
        ctx->from = position[1];
        ctx->to = ctx->dest_y;
        ctx->tick = 0;
        ctx->duration = 10;
        ctx->state = 1;
        break;
    case 1:
        value = ctx->from + ((ctx->to - ctx->from) * ctx->tick) / ctx->duration;
        BR_BTN_GetObjectPos(ctx->result, &x, 0);
        BR_BTN_SetObjectPos(ctx->result, x, value);
        if (ctx->tick++ >= ctx->duration) ctx->state = 2;
        break;
    case 2: return 1;
    }
    return 0;
}

/*
 * tail: 021FB0E6..021FB0E8 is two zero alignment bytes.
 * lever: load position[1] to a local before the target and step stores.
 */
int BR_BTN_AnimMoveRow(Button *ctx)
{
    int position[2];
    short x;
    short value;
    int target;
    int start;
    switch (ctx->state) {
    case 0:
        BR_BTN_GetPos(ctx, position);
        target = BR_BTN_DATA_GetRowField(ctx->object, 1);
        start = position[1];
        ctx->to = target;
        ctx->tick = 0;
        ctx->from = start;
        ctx->duration = 16;
        ctx->state = 1;
        break;
    case 1:
        value = ctx->from + ((ctx->to - ctx->from) * ctx->tick) / ctx->duration;
        BR_BTN_GetObjectPos(ctx->result, &x, 0);
        BR_BTN_SetObjectPos(ctx->result, x, value);
        if (ctx->tick++ >= ctx->duration) ctx->state = 2;
        break;
    case 2: return 1;
    }
    return 0;
}

int BR_BTN_AnimFlyOut(Button *p)
{
    s16 y,x;
    switch(p->state) {
    case 0: {
        int position[2];
        BR_BTN_GetPos((Button *)p, position);
        p->from=position[1];p->to=-32;p->tick=0;p->duration=14;p->state=1;
        break;
    }
    case 1: {
        s16 value;
        value=p->from;
        value=value+((p->to-value)*p->tick)/p->duration;
        BR_BTN_GetObjectPos(p->result,&y,0);
        BR_BTN_SetObjectPos(p->result,y,value);
        if(p->tick++>=p->duration)p->state=2;
        break;
    }
    case 2:BR_BTN_SetMode(p,0);p->state=3;break;
    case 3: {
        int position[2];
        BR_BTN_GetPos((Button *)p, position);
        p->from=position[1];p->to=p->dest_y;p->tick=0;p->duration=14;p->state=4;
        break;
    }
    case 4: {
        s16 value;
        value=p->from;
        value=value+((p->to-value)*p->tick)/p->duration;
        BR_BTN_GetObjectPos(p->result,&x,0);
        BR_BTN_SetObjectPos(p->result,x,value);
        if(p->tick++>=p->duration)p->state=5;
        break;
    }
    case 5:return 1;
    }
    return 0;
}

/*
 * tail: 021FB2EE..021FB2F0 is two zero alignment bytes.
 * lever: capture from in the s16 value before the named divider, keeping its load live across the helper.
 */
int BR_BTN_AnimFlyIn(Button *p)
{
    s16 y,x;
    switch(p->state) {
    case 0: {
        int position[2];
        BR_BTN_GetPos((Button *)p, position);
        p->from=position[1];p->to=224;p->tick=0;p->duration=14;p->state=1;
        break;
    }
    case 1: {
        s16 value;
        value=p->from;
        value=value+((p->to-value)*p->tick)/p->duration;
        BR_BTN_GetObjectPos(p->result,&y,0);
        BR_BTN_SetObjectPos(p->result,y,value);
        if(p->tick++>=p->duration)p->state=2;
        break;
    }
    case 2:BR_BTN_SetMode(p,1);p->state=3;break;
    case 3: {
        int position[2];
        BR_BTN_GetPos((Button *)p, position);
        p->from=position[1];p->to=p->dest_y;p->tick=0;p->duration=14;p->state=4;
        break;
    }
    case 4: {
        s16 value;
        value=p->from;
        value=value+((p->to-value)*p->tick)/p->duration;
        BR_BTN_GetObjectPos(p->result,&x,0);
        BR_BTN_SetObjectPos(p->result,x,value);
        if(p->tick++>=p->duration)p->state=5;
        break;
    }
    case 5:return 1;
    }
    return 0;
}

int BR_BTN_AnimMove2(Button *ctx)
{
    int position[2];
    short x;
    short value;
    switch (ctx->state) {
    case 0:
        BR_BTN_GetPos(ctx, position);
        ctx->from = position[1];
        ctx->to = ctx->dest_y;
        ctx->tick = 0;
        ctx->duration = 26;
        ctx->state = 1;
        break;
    case 1:
        value = ctx->from + ((ctx->to - ctx->from) * ctx->tick) / ctx->duration;
        BR_BTN_GetObjectPos(ctx->result, &x, 0);
        BR_BTN_SetObjectPos(ctx->result, x, value);
        if (ctx->tick++ >= ctx->duration) ctx->state = 2;
        break;
    case 2: return 1;
    }
    return 0;
}

/*
 * tail: 021FB3BA..021FB3BC is two zero alignment bytes.
 */
void *BR_BTN_CreateFromMessage(void *ctx, u16 file, unsigned short a, int b, void *c, void *d, void *e, struct MsgBank *archive, void *config, unsigned short heap)
{
    void *data;
    void *result;
    data = MSGDATA_AllocString(archive, file);
    result = BR_BTN_CreateObject((const BrBtnPlacement *)ctx, data, a, b, c, d, e, (const BrBtnSpriteIds *)config, heap);
    STRBUF_Delete(data);
    return result;
}

/*
 * lever: parameter a declared u16 (u8 also EXACT); a narrow parameter pins its home store to the front of the prologue, see docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md. 2026-10-05 wave P12 lane A5: the older draft (docs/notes/pkt_ov186_021FB3BC.c.txt) was only wrong here.
 */
struct BrButton *BR_BTN_CreateObject(const BrBtnPlacement *pt,void *data,u16 a,u32 b,void *c,void *owner,void *font,const BrBtnSpriteIds *triple,u16 heap)
{
    Param param;
    const BrBtnSpriteIds *config;
    u32 value;
    struct BrButton *p;
    value=b;config=triple;
    p=GFL_HEAP_Alloc(heap,24,0,d_02200D1C,0xA3B);
    MI_CpuFill8(p,0,24);
    p->paramA=a;p->surface=value;
    p->actor=CLACT_CreateActor(c,config->y,config->z,config->x,(const struct ActorInitParam *)pt,value,heap);
    CLACT_SetActorObjMode(p->actor,1);
    p->bmp=BMP_Create(p->paramA>>3,2,32,heap);
    PRINTSYS_PrintColor(p->bmp,1,0,data,font,0x3DA0);
    MI_CpuFill8(&param,0,24);
    param.bmp=p->bmp;
    param.x=pt->x+32;param.y=pt->y-8;
    param.spriteZ=config->z;param.objMode=pt->flag-1;param.mode=value;
    param.mode2=value;param.flip=pt->attr;param.flags=1;
    p->grid=BMP_OAM_Create(owner,(const struct BmpOamParam *)(const struct Param *)(&param));
    BMP_OAM_UploadChars(p->grid);
    BMP_OAM_SetObjMode(p->grid,1);
    return p;
}

void BR_BTN_DeleteObject(char *p) { BMP_OAM_Delete((struct BmpOam *)(*(struct BmpOam * *)&((struct BrButton *)p)->grid));BMP_Delete(*(struct Bmp * *)&((struct BrButton *)p)->bmp);CLACT_DeleteActor((struct ClactActor *)*(struct Actor * *)&((struct BrButton *)p)->actor);GFL_HEAP_Free(p); }

int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y)
{
    int r = BR_BTN_TestHitBox(obj, x, y);

    if (r != 0)
        GFL_USE_PlaySeDefaultVolume(0x703);
    return r;
}

static inline int in_range(int v, int lo, int hi)
{
    return (u32)(v - lo) <= (u32)(hi - lo);
}

/*
 * Recursive MATCH unblocker: unresolved callee named by the parked
 * BR_BTN_HitTest.  Expands p[0] through the arm9 helper 0x0204B454 into two
 * signed shorts and tests the incoming ranges against p[5] and the +/-16
 * window around tmp[1].  The scratch is a raw 4-byte buffer so the two reads
 * stay register-addressed off sp.
 *
 * 2026-10-05: decoded the original as two unsigned range tests (u32)(v-lo) <= (u32)(hi-lo) with hi,lo unfolded: (a1-x) <= ((x+p5)-x) and (a2-(y-16)) <= ((y+16)-(y-16)), flag r7=0 set before the loads (its zero is reused as the ldrsh index). A static inline in_range(v,lo,hi) with s16 t[2] read at the use gives the unfolded second test but loads t[1] first and puts a2/a1 in the wrong registers; locals x,y fold the second test to cmp #0x20. Not closed.
 *
 * 2026-10-05 (D9 lane 12): EXACT*. The range test is a static inline
 * in_range(v, lo, hi); its parameters keep (hi-lo) unfolded. The first result is a
 * named local, written before the second call: hx = in_range(x); return in_range(y) & hx.
 *
 * Addresses are Black-image addresses.
 */
int BR_BTN_TestHitBox(u32 *p, int x, int y)
{
    BrBtnPtS pos;
    int hx;
    CLACT_GetActorSurfacePos((struct ClactActor *)(struct Actor *)p[0], (struct ClactVec2 *)&pos, (u16)p[4]);
    hx = in_range(x, pos.x, pos.x + p[5]);
    return in_range(y, pos.y - 16, pos.y + 16) & hx;
}

void BR_BTN_SetObjectPos(char *p, short x, int y) { struct BrBtnVec2 v;v.x=x;v.y=y;CLACT_AddActorSurfacePos((struct ClactActor *)*(struct Actor * *)&((struct BrButton *)p)->actor,(struct ClactVec2 *)(const struct ClactVec2 *)&v,(unsigned short)(((struct BrButton *)p)->surface));BMP_OAM_SetPos((struct BmpOam *)(*(struct BmpOam * *)&((struct BrButton *)p)->grid),v.x+32,v.y-8); }

void BR_BTN_GetObjectPos(char *p,short *x,short *y) { BrBtnPtS v;CLACT_GetActorSurfacePos((struct ClactActor *)*(struct Actor * *)&((struct BrButton *)p)->actor,(struct ClactVec2 *)&v,(unsigned short)((struct BrButton *)p)->surface);if(x)*x=v.x;if(y)*y=v.y; }

void BR_BTN_SetObjectDrawPriority(int *p, unsigned char b)
{
    CLACT_SetActorDrawPriority((struct ClactActor *)(struct Actor *)p[0], b);
    BMP_OAM_SetDrawPriority((struct BmpOam *)p[1], (unsigned char)(b - 1));
}

int BR_BTN_GetObjectDrawPriority(char *p) { return CLACT_GetActorDrawPriority((struct ClactActor *)((struct BrButton *)p)->actor); }

void BR_BTN_SetObjectBgPriority(int *p, int b)
{
    CLACT_SetActorBgPriority((struct ClactActor *)(struct Actor *)p[0], b);
    BMP_OAM_SetBgPriority((struct BmpOam *)p[1], b);
}

unsigned BR_BTN_GetObjectBgPriority(char *p) { return CLACT_GetActorBgPriority((struct ClactActor *)(struct Actor *)(*(unsigned char * *)&((struct BrButton *)p)->actor)); }

void BR_BTN_SetObjectPalette(char *p,int n) { CLACT_SetActorPaletteOffset(((struct BrButton *)p)->actor,(unsigned char)n,0);BMP_OAM_SetPalette((struct BmpOam *)(*(unsigned char * *)&((struct BrButton *)p)->grid),(unsigned char)(n+1)); }
