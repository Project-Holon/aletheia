/*
 * file:     namein_graphic_field.c
 * unit:     yes
 * function: NAMEIN_GRAPHIC_FadeCellColor, NAMEIN_GRAPHIC_InitInputField, NAMEIN_GRAPHIC_DeleteInputField, NAMEIN_GRAPHIC_RefreshInputField, NAMEIN_GRAPHIC_Backspace, NAMEIN_GRAPHIC_AppendChar, NAMEIN_GRAPHIC_AppendCandidate, NAMEIN_GRAPHIC_ApplyConversion, NAMEIN_GRAPHIC_RevertChar, NAMEIN_GRAPHIC_IsFieldDrawDone, NAMEIN_GRAPHIC_CopyToStrbuf, NAMEIN_GRAPHIC_ClearSecondary, NAMEIN_GRAPHIC_CommitSecondary, NAMEIN_GRAPHIC_ClearPrimary, NAMEIN_GRAPHIC_AppendString, NAMEIN_GRAPHIC_IsFieldFull, NAMEIN_GRAPHIC_GetLength, NAMEIN_GRAPHIC_GetSecondaryLength, NAMEIN_GRAPHIC_PickCandidate, NAMEIN_GRAPHIC_HasNonSpace, NAMEIN_GRAPHIC_InitPicker, NAMEIN_GRAPHIC_LoadGrid, NAMEIN_GRAPHIC_ClearPicker, NAMEIN_GRAPHIC_PickerToChar, NAMEIN_GRAPHIC_FindCellAtPoint, NAMEIN_GRAPHIC_PickerMove, NAMEIN_GRAPHIC_DrawCellTips, NAMEIN_GRAPHIC_PickerGetBox, NAMEIN_GRAPHIC_FindCellByValue, NAMEIN_GRAPHIC_ConvertCellMode, NAMEIN_GRAPHIC_KanaGetBox, NAMEIN_GRAPHIC_SymbolGetBox, NAMEIN_GRAPHIC_KanaMove, NAMEIN_GRAPHIC_SymbolMove, NAMEIN_GRAPHIC_GridValue, NAMEIN_GRAPHIC_ComputeGridValue
 * address:  0x021F1D58
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FX_SinCosTable_  0x020A1B38  data
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   STRBUF_Create  0x020457B0  arm
 *   NAMEIN_GRAPHIC_LoadCharMember  0x021F4DBC  thumb  ov194
 *   NAMEIN_GRAPHIC_LoadPairMember  0x021F4F50  thumb  ov194
 *   NAMEIN_GRAPHIC_GetActor  0x021F1998  thumb  ov194
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 *   NAMEIN_GRAPHIC_FreePairMember 0x021F4F60 thumb ov194
 *   NAMEIN_GRAPHIC_FreeHandle 0x021F4DD0 thumb ov194
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   WORDSET_CopyString 0x0201F41C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   NAMEIN_GRAPHIC_FindTableIndex 0x021F4ED8 thumb ov194
 *   NAMEIN_GRAPHIC_PickTable8 0x021F4E18 thumb ov194
 *   NAMEIN_GRAPHIC_CopyTableEntries 0x021F4DDC thumb ov194
 *   NAMEIN_GRAPHIC_NextPairChar 0x021F4F7C thumb ov194
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   NAMEIN_GRAPHIC_PickTableE 0x021F4E58 thumb ov194
 *   NAMEIN_GRAPHIC_PickTable14 0x021F4E98 thumb ov194
 *   NAMEIN_GRAPHIC_GetWord 0x021F4D94 thumb ov194
 *   NAMEIN_GRAPHIC_SymbolGetValue 0x021F2F8C thumb ov194
 *   d_021F555C 0x021F555C data a4
 *   NAMEIN_GRAPHIC_GetGridCell 0x021F4DA4 thumb ov194
 *   NAMEIN_GRAPHIC_IsPointInRect 0x021F4450 thumb ov194
 *   PRINTSYS_CountLines 0x0201D42C thumb
 *   NAMEIN_GRAPHIC_GetGridHeight 0x021F4DA0 thumb ov194
 *   NAMEIN_GRAPHIC_GetGridWidth 0x021F4D9C thumb ov194
 *   d_021F5544 0x021F5544 data a4
 *   d_021F5550 0x021F5550 data a4
 */
/* The DS code passes the heap id as a word (the original prototypes); the definitions take a halfword. The host build uses the header. */
#ifdef __MWERKS__
#define NAMEIN_GRAPHIC_LoadCharMember NAMEIN_GRAPHIC_LoadCharMember_header
#define NAMEIN_GRAPHIC_LoadPairMember NAMEIN_GRAPHIC_LoadPairMember_header
#endif
#include "namein_graphic_shared_types.h"
#include "namein_data.h"
#ifdef __MWERKS__
#undef NAMEIN_GRAPHIC_LoadCharMember
#undef NAMEIN_GRAPHIC_LoadPairMember
extern void *NAMEIN_GRAPHIC_LoadCharMember(int a, int b);
extern void *NAMEIN_GRAPHIC_LoadPairMember(int a);
#endif

struct ClactActor;
struct Cfg;
struct Descriptor;
struct ClactActor;
struct U16Vec;
struct ClactVec2;
struct CharBuf;
struct StrObj;
struct Strbuf;
struct PrintSys;
#include "../types.h"

typedef struct {u8 removedCount,addedCount;u16 removed[4],added[4];} Changes;

typedef struct {u8 count,pad;u16 values[4];} Group;



typedef int (*Conv)(NameinGraphicPair *, NameinGraphicPair *);

/* The name-entry input field (the 0x94 block at work+0x68). */
typedef struct NameinGraphicInputField {
    unsigned short primary[11];    /* 0x00 primary text, up to maxLength code units */
    unsigned short secondary[3];   /* 0x16 candidate text */
    unsigned char pad_1C[2];
    unsigned short primaryLength;  /* 0x1E */
    unsigned short secondaryLength;/* 0x20 */
    unsigned short maxLength;      /* 0x22 */
    unsigned char pad_24[4];
    int needsRefresh;              /* 0x28 */
    void *win;                     /* 0x2C window handle */
    unsigned char drawDone;        /* 0x30 */
    unsigned char pad_31[3];
    unsigned int textColor;        /* 0x34 */
    void *printSys;                /* 0x38 */
    void *strbuf;                  /* 0x3C scratch string buffer */
    void *bmpWin;                  /* 0x40 bmp window */
    void *actors[16];              /* 0x44 character actor handles */
    void *charMember[3];           /* 0x84 character tables used as conversion tables */
    void *pairMember;              /* 0x90 pair table */
} NameinGraphicInputField;

/* The kana/symbol picker embedded at the start of the grid. */
typedef struct NameinGraphicPicker {
    void *table;                   /* 0x00 grid table */
    unsigned char map[13];         /* 0x04 mode map copied from d_021F555C */
    unsigned char pad_11[3];
    void *getBox;                  /* 0x14 int (*)(Pair *, Box *) */
    void *move;                    /* 0x18 void (*)(int, int, char *) */
    void *getValue;                /* 0x1C unsigned (*)(int *, int *) */
    unsigned short width;          /* 0x20 */
    unsigned short height;         /* 0x22 */
} NameinGraphicPicker;

/* The grid cell-tip window and its dirty flag (grid+0xEC). */
typedef struct NameinGraphicTipTarget {
    void *bmp;                     /* 0x00 */
    signed char dirty;             /* 0x04 */
} NameinGraphicTipTarget;

#include "../arm9/nns_gfd_vram_transfer.h"
#include "../arm9/mi_memory.h"
struct BmpWin;
struct ClactActor;
#include "../arm9/bmp_win.h"
#include "../arm9/bg_sys.h"
#include "../arm9/strbuf.h"
#include "namein_graphic_main.h"
#include "../arm9/clact.h"
struct ClactVec2;
#include "../arm9/wordset.h"
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
struct GfFont;
#include "../arm9/printsys.h"
struct PrintQueue;
extern int NAMEIN_GRAPHIC_SymbolGetValue(NameinGraphicPair *,NameinGraphicPair *);
#include "namein_graphic.h"
int NAMEIN_GRAPHIC_FadeCellColor(u16 *out, u16 *phase, u32 step, u32 row, u8 idx, u16 a, u16 b);
void NAMEIN_GRAPHIC_InitInputField(u8 *p, int a, u16 b, u16 c, int d, u8 *e, int f);
void NAMEIN_GRAPHIC_DeleteInputField(u8 *p);
int NAMEIN_GRAPHIC_RefreshInputField(u8 *p);
int NAMEIN_GRAPHIC_Backspace(unsigned char *p);
int NAMEIN_GRAPHIC_AppendChar(char *p, unsigned short v);
int NAMEIN_GRAPHIC_AppendCandidate(unsigned char *p, unsigned short a, u32 b);
int NAMEIN_GRAPHIC_ApplyConversion(u8 *a,int b);
int NAMEIN_GRAPHIC_RevertChar(char *p);
int NAMEIN_GRAPHIC_IsFieldDrawDone(unsigned char *p);
void NAMEIN_GRAPHIC_CopyToStrbuf(char *self, struct Strbuf *dst);
void NAMEIN_GRAPHIC_ClearSecondary(char *p);
void NAMEIN_GRAPHIC_CommitSecondary(char *p);
void NAMEIN_GRAPHIC_ClearPrimary(u8 *p);
void NAMEIN_GRAPHIC_AppendString(char *p,const u16 *q);
int NAMEIN_GRAPHIC_IsFieldFull(char *p);
u32 NAMEIN_GRAPHIC_GetLength(const u8 *p);
u32 NAMEIN_GRAPHIC_GetSecondaryLength(const u8 *p);
int NAMEIN_GRAPHIC_PickCandidate(u8 *p,int direction);
int NAMEIN_GRAPHIC_HasNonSpace(u8 *p);
void NAMEIN_GRAPHIC_InitPicker(char *p, unsigned mode, int index, void *table, u32 unused);
void NAMEIN_GRAPHIC_LoadGrid(int *a, int b, void *c);
void NAMEIN_GRAPHIC_ClearPicker(void *p);
unsigned NAMEIN_GRAPHIC_PickerToChar(char *p,int *input,unsigned short *out);
int NAMEIN_GRAPHIC_FindCellAtPoint(const char *p,int *point,NameinGraphicPair *out);
void NAMEIN_GRAPHIC_PickerMove(char *a, int b, int c);
void NAMEIN_GRAPHIC_DrawCellTips(char *p,char *target,void *window,void *font,u16 heap);
int NAMEIN_GRAPHIC_PickerGetBox(char *a, NameinGraphicPair *b, NameinGraphicBox *c);
int NAMEIN_GRAPHIC_FindCellByValue(const char *p,int target,NameinGraphicPair *out);
void NAMEIN_GRAPHIC_ConvertCellMode(NameinGraphicPair *p, int oldmode, int newmode);
int NAMEIN_GRAPHIC_KanaGetBox(const int *p,int *out);
int NAMEIN_GRAPHIC_SymbolGetBox(NameinGraphicPair *p,NameinGraphicBox *out);
void NAMEIN_GRAPHIC_KanaMove(int *p,int *delta,u8 *saved);
void NAMEIN_GRAPHIC_SymbolMove(int *p,int *delta,unsigned char *s);
int NAMEIN_GRAPHIC_GridValue(const int *p,int *out);
int NAMEIN_GRAPHIC_ComputeGridValue(const int *p,int *out);
extern fx16 FX_SinCosTable_[];
extern const unsigned char d_021F555C[];
extern const int d_021F5544[];
extern const int d_021F5550[];

static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1) + 1]; }

/*
 * note 2026-10-05 (wD9r lane18): closed by the NitroSDK FX_CosIdx inline for the table read
 *   (earlier drafts wrote the raw tbl[(*phase >> 4) * 2 + 1] expression) and the ov105 021B8734
 *   lerp body (u8 r, g, blue; int dr, dg, db) with g before the cosine and an s16 t.
 */
int NAMEIN_GRAPHIC_FadeCellColor(u16 *out, u16 *phase, u32 step, u32 row, u8 idx, u16 a, u16 b)
{
    u8 r, g, blue; int dr, dg, db; s16 t;
    int ph = *phase + step;
    if (ph >= 0x10000) *phase = ph - 0x10000;
    else *phase = ph;
    g = (a & 0x3E0) >> 5;
    t = (FX_CosIdx(*phase) + 0x1000) / 2;
    r = a & 31;
    blue = (a & 0x7C00) >> 10;
    db = ((u8)((b & 0x7C00) >> 10) - blue) * t >> 12;
    dr = ((u8)(b & 31) - r) * t >> 12;
    dg = ((u8)((b & 0x3E0) >> 5) - g) * t >> 12;
    *out = (u8)(r + dr) | ((u8)(g + dg) << 5) | ((u8)(blue + db) << 10);
    NNS_GfdRegisterNewVramTransferTask((void *)0xF, row * 32 + idx * 2, (u32)out, 2);
    return *out == b;
}

/*
 * note 2026-10-05 (wD7 lane05): the entry spill order (b before a) follows the type of the
 *   fourth parameter: c as u16 closes it (as int the compiler spills a, b, c).
 *   c is really the font pointer (stored at +0x34, textColor in the struct, used as a GfFont *);
 *   a host compiler must read it as a full pointer. Tried with c as u32/struct GfFont *: b/a spill
 *   stores swap (4 bytes), no source lever found. See docs/DEBT.tsv narrow-type.
 * note 2026-10-19 (wave 19): mwccdbg shows why. A word spill of a u16 variable is in the
 *   unknown-memory set G, so the b and c spills alias and b gets a store-store edge to c
 *   (release count 2); with a pointer c only b is in G, a and b tie and a goes first.
 */
void NAMEIN_GRAPHIC_InitInputField(u8 *p, int a, u16 b, u16 c, int d, u8 *e, int f)
{
    u16 pos[2];
    int i;
    int h;
    int base;
    MI_CpuFill8(p, 0, 0x94);
    i = 0;
    *(int *)(p + 0x34) = c;
    *(u16 *)(p + 0x22) = b;
    *(int *)(p + 0x38) = d;
    h = (int)BMP_WIN_Create(0, 8, 2, 0x18, 2, 15, 1);
    *(int *)(p + 0x40) = h;
    BMP_WIN_TransferChars((struct BmpWin *)h);
    BMP_WIN_MakeScreen((struct BmpWin *)h);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
    *(int *)(p + 0x2c) = *(int *)(p + 0x40);
    *(u8 *)(p + 0x30) = i;
    *(int *)(p + 0x3c) = (int)STRBUF_Create(0xe, f);
    for (i = 0; i < 3; i++) {
        *(int *)(p + i * 4 + 0x84) = (int)NAMEIN_GRAPHIC_LoadCharMember(i, f);
    }
    *(int *)(p + 0x90) = (int)NAMEIN_GRAPHIC_LoadPairMember(f);
    for (i = 0; i < 16; i++) {
        *(int *)(p + i * 4 + 0x44) = (int)NAMEIN_GRAPHIC_GetActor(e, i);
    }
    if (STRBUF_GetLength((struct Strbuf *)a) == 0) {
        *(u16 *)p = STRBUF_GetEosChar();
    } else {
        STRBUF_ToChars((struct Strbuf *)a, (u16 *)p, b + 1);
        *(u16 *)(p + 0x1e) = STRBUF_GetLength((struct Strbuf *)a);
    }
    pos[1] = 0x25;
    base = 0x40 - (*(u16 *)(p + 0x22) * 14) / 2;
    if (base < 0) {
        base = 0;
    }
    base += 0x40;
    for (i = 0; i < 16; i++) {
        pos[0] = base + i * 14;
        CLACT_SetActorAnimSeq((struct ClactActor *)(*(int *)(p + i * 4 + 0x44)), 1);
        CLACT_SetActorAutoAnim((struct ClactActor *)(*(int *)(p + i * 4 + 0x44)), 1);
        CLACT_AddActorSurfacePos((struct ClactActor *)(*(int *)(p + i * 4 + 0x44)), (struct ClactVec2 *)pos, 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(int *)(p + i * 4 + 0x44)), 1);
    }
    for (i = *(u16 *)(p + 0x22); i < 16; i++) {
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(int *)(p + i * 4 + 0x44)), 0);
    }
    CLACT_StartActorAnim((struct ClactActor *)(*(int *)(p + *(u16 *)(p + 0x1e) * 4 + 0x44)));
    *(int *)(p + 0x28) = 1;
    NAMEIN_GRAPHIC_RefreshInputField(p);
}

void NAMEIN_GRAPHIC_DeleteInputField(u8 *p) { int i;NAMEIN_GRAPHIC_FreePairMember(((NameinGraphicInputField *)p)->pairMember);for(i=0;i<3;i++)NAMEIN_GRAPHIC_FreeHandle(*(void **)((u32)p+(u32)i*4+132));STRBUF_Delete(((NameinGraphicInputField *)p)->strbuf);BMP_WIN_Delete((struct BmpWin *)(((NameinGraphicInputField *)p)->bmpWin));MI_CpuFill8(p,0,148); }

/*
 * lever: load window in each print arm; p+i*4+0x44 preserves per-element bases and constant registers.
 */
int NAMEIN_GRAPHIC_RefreshInputField(u8 *p)
{
 u16 table[14];
 u16 pair[2];
 int i,x;
 void *window;
 if(((NameinGraphicInputField *)p)->needsRefresh){
  if(((NameinGraphicInputField *)p)->primaryLength)WORDSET_CopyString((u16 *)p,table,((NameinGraphicInputField *)p)->primaryLength+1);
  if(((NameinGraphicInputField *)p)->secondaryLength)WORDSET_CopyString((u16 *)(p+0x16),table+((NameinGraphicInputField *)p)->primaryLength,((NameinGraphicInputField *)p)->secondaryLength+1);
  if(((NameinGraphicInputField *)p)->primaryLength+((NameinGraphicInputField *)p)->secondaryLength>0){
   BMP_Clear(BMP_WIN_GetBmp(((NameinGraphicInputField *)p)->bmpWin),0);
   for(i=0;i<((NameinGraphicInputField *)p)->primaryLength+((NameinGraphicInputField *)p)->secondaryLength;i++){
    pair[0]=table[i];pair[1]=STRBUF_GetEosChar();
    STRBUF_SetStringN(((NameinGraphicInputField *)p)->strbuf,pair,2);
    x=64-(((NameinGraphicInputField *)p)->maxLength*14)/2;if(x<0)x=0;
    x+=i*14+7;
    x-=PRINTSYS_MeasureWidestLine(((NameinGraphicInputField *)p)->strbuf,(struct GfFont *)(((NameinGraphicInputField *)p)->textColor),0)/2;
    if(i>=((NameinGraphicInputField *)p)->primaryLength){window=((NameinGraphicInputField *)p)->printSys;PRINTSYS_PrintQueColor(window,BMP_WIN_GetBmp(((NameinGraphicInputField *)p)->win),(short)x,0,(((NameinGraphicInputField *)p)->strbuf),(struct GfFont *)(((NameinGraphicInputField *)p)->textColor),0xc80);}
    else {window=((NameinGraphicInputField *)p)->printSys;PRINTSYS_PrintQue(window,BMP_WIN_GetBmp(((NameinGraphicInputField *)p)->win),(short)x,0,((NameinGraphicInputField *)p)->strbuf,(struct GfFont *)(((NameinGraphicInputField *)p)->textColor));}
    p[0x30]=1;
   }
  }else{
   BMP_Clear(BMP_WIN_GetBmp(((NameinGraphicInputField *)p)->bmpWin),0);
   BMP_WIN_TransferChars(((NameinGraphicInputField *)p)->bmpWin);
  }
  for(i=0;i<((NameinGraphicInputField *)p)->maxLength;i++){
   CLACT_SetActorAnimFrame(*(void **)(p+i*4+0x44),0);
   CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x44),1);
   CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x44),1);
  }
  for(;i<16;i++){
   CLACT_SetActorAnimFrame(*(void **)(p+i*4+0x44),0);
   CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x44),1);
   CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x44),0);
  }
  for(i=0;i<=((NameinGraphicInputField *)p)->primaryLength && i<((NameinGraphicInputField *)p)->maxLength;i++)CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x44),1);
  CLACT_SetActorAnimSeq(*(void **)(p+0x44+((NameinGraphicInputField *)p)->primaryLength*4),0);
  ((NameinGraphicInputField *)p)->needsRefresh=0;
 }
 return NAMEIN_GRAPHIC_IsFieldDrawDone(p);
}

int NAMEIN_GRAPHIC_Backspace(unsigned char *p)
{
    if (((NameinGraphicInputField *)p)->secondaryLength != 0) {
        ((NameinGraphicInputField *)p)->secondaryLength -= 1;
        *(unsigned short *)(p + 0x16 + ((NameinGraphicInputField *)p)->secondaryLength * 2) =
            STRBUF_GetEosChar();
        ((NameinGraphicInputField *)p)->needsRefresh = 1;
        return 1;
    }
    if (((NameinGraphicInputField *)p)->primaryLength != 0) {
        ((NameinGraphicInputField *)p)->primaryLength -= 1;
        *(unsigned short *)(p + ((NameinGraphicInputField *)p)->primaryLength * 2) =
            STRBUF_GetEosChar();
        ((NameinGraphicInputField *)p)->needsRefresh = 1;
        return 1;
    }
    return 0;
}

int NAMEIN_GRAPHIC_AppendChar(char *p, unsigned short v)
{
    if (((NameinGraphicInputField *)p)->primaryLength < ((NameinGraphicInputField *)p)->maxLength)
    {
        *(unsigned short *)(p + (((NameinGraphicInputField *)p)->primaryLength << 1)) = v;
        ((NameinGraphicInputField *)p)->primaryLength += 1;
        *(unsigned short *)(p + (((NameinGraphicInputField *)p)->primaryLength << 1)) = STRBUF_GetEosChar();
        ((NameinGraphicInputField *)p)->needsRefresh = 1;
        return 1;
    }
    return 0;
}

int NAMEIN_GRAPHIC_AppendCandidate(unsigned char *p, unsigned short a, u32 b)
{
    if (((NameinGraphicInputField *)p)->primaryLength < ((NameinGraphicInputField *)p)->maxLength &&
        ((NameinGraphicInputField *)p)->secondaryLength < 3) {
        *(unsigned short *)(p + 0x16 + ((NameinGraphicInputField *)p)->secondaryLength * 2) = a;
        ((NameinGraphicInputField *)p)->secondaryLength += 1;
        *(unsigned short *)(p + 0x16 + ((NameinGraphicInputField *)p)->secondaryLength * 2) =
            STRBUF_GetEosChar();
        NAMEIN_GRAPHIC_PickCandidate(p, b);
        ((NameinGraphicInputField *)p)->needsRefresh = 1;
        return 1;
    }
    return 0;
}

/*
 * lever: shared failure label retains one exit; byte-offset cast +10 inside the loop
 * materialises the added-array base after the entry guard, unlike change.added.
 */
int NAMEIN_GRAPHIC_ApplyConversion(u8 *a,int b)
{
    void *p;
    u16 v;
    Changes change;
    int i;
    u16 *tab;
    switch(b) {
    case 0: p=((NameinGraphicInputField *)a)->charMember[0]; break;
    case 1: p=((NameinGraphicInputField *)a)->charMember[1]; break;
    default:return 0;
    }
    if (((NameinGraphicInputField *)a)->primaryLength==0) goto fail;
    v=NAMEIN_GRAPHIC_FindTableIndex(p,(u16 *)(a+(((NameinGraphicInputField *)a)->primaryLength-1)*2));
    if(v==65535) goto fail;
    if(!NAMEIN_GRAPHIC_PickTable8((int)p,v,change.added,4,&change.addedCount)) goto fail;
    NAMEIN_GRAPHIC_CopyTableEntries(p,v,change.removed,4,&change.removedCount);
    for(i=0;i<change.removedCount;i++) NAMEIN_GRAPHIC_Backspace(a);
    for(i=0;i<change.addedCount;i++) {
        tab=(u16 *)((u8 *)&change+10);
        NAMEIN_GRAPHIC_AppendChar((char *)a,tab[i]);
    }
    return 1;
fail:
    return 0;
}

int NAMEIN_GRAPHIC_RevertChar(char *p) { u16 v;if(((NameinGraphicInputField *)p)->primaryLength!=0 && NAMEIN_GRAPHIC_NextPairChar(*(char * *)&((NameinGraphicInputField *)p)->pairMember,(u16 *)((u32)p+(((NameinGraphicInputField *)p)->primaryLength-1)*2),&v)) { NAMEIN_GRAPHIC_Backspace((u8 *)p);NAMEIN_GRAPHIC_AppendChar(p,v);return 1; }return 0; }

int NAMEIN_GRAPHIC_IsFieldDrawDone(unsigned char *p)
{
    int c = p[0x30];
    int r4 = (int)((NameinGraphicInputField *)p)->printSys;

    if (c != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)r4, (void *)((int)BMP_WIN_GetBmp((struct BmpWin *)((NameinGraphicInputField *)p)->win))) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)((NameinGraphicInputField *)p)->win);
            p[0x30] = 0;
        }
    }
    return p[0x30] == 0;
}

void NAMEIN_GRAPHIC_CopyToStrbuf(char *self, struct Strbuf *dst)
{
    STRBUF_SetStringN(dst, (const u16 *)self,
                 ((NameinGraphicInputField *)self)->primaryLength + 1);
}

void NAMEIN_GRAPHIC_ClearSecondary(char *p)
{
    if (((NameinGraphicInputField *)p)->secondaryLength != 0)
    {
        unsigned int v;
        ((NameinGraphicInputField *)p)->secondaryLength = 0;
        v = STRBUF_GetEosChar();
        *(unsigned short *)(p + 0x16 + (((NameinGraphicInputField *)p)->secondaryLength << 1)) = v;
        ((NameinGraphicInputField *)p)->needsRefresh = 1;
    }
}

void NAMEIN_GRAPHIC_CommitSecondary(char *p) { int i; for(i=0;i<((NameinGraphicInputField *)p)->secondaryLength;i++)NAMEIN_GRAPHIC_AppendChar(p,*(u16 *)((u32)p+(u32)i*2+22));((NameinGraphicInputField *)p)->secondaryLength=0;*(u16 *)((u32)p+((NameinGraphicInputField *)p)->secondaryLength*2+22)=STRBUF_GetEosChar();((NameinGraphicInputField *)p)->needsRefresh=1; }

void NAMEIN_GRAPHIC_ClearPrimary(u8 *p) {if(((NameinGraphicInputField *)p)->primaryLength) {((NameinGraphicInputField *)p)->primaryLength=0;*(u16 *)(p+((NameinGraphicInputField *)p)->primaryLength*2)=STRBUF_GetEosChar();((NameinGraphicInputField *)p)->needsRefresh=1;}NAMEIN_GRAPHIC_ClearSecondary((char *)p);}

void NAMEIN_GRAPHIC_AppendString(char *p,const u16 *q) {while(*q!=STRBUF_GetEosChar()) {if(!NAMEIN_GRAPHIC_AppendChar(p,*q)) break;q++;}}

int NAMEIN_GRAPHIC_IsFieldFull(char *p)
{
    return ((NameinGraphicInputField *)p)->primaryLength == ((NameinGraphicInputField *)p)->maxLength;
}

u32 NAMEIN_GRAPHIC_GetLength(const u8 *p) {return ((NameinGraphicInputField *)p)->primaryLength;}

u32 NAMEIN_GRAPHIC_GetSecondaryLength(const u8 *p) {return ((NameinGraphicInputField *)p)->secondaryLength;}

/*
 * lever: read Group values through ((u16 *)((char *)&group+2))[i] to hoist its member base.
 */
int NAMEIN_GRAPHIC_PickCandidate(u8 *p,int direction)
{
 Group group;
 int (*pick)(int,int,u16 *,int,u8 *);
 int i,j;
 u16 index;
 pick=direction?NAMEIN_GRAPHIC_PickTableE:NAMEIN_GRAPHIC_PickTable8;
 for(i=0;i<((NameinGraphicInputField *)p)->secondaryLength;i++){
  index=NAMEIN_GRAPHIC_FindTableIndex(((NameinGraphicInputField *)p)->charMember[2],(u16 *)(p+0x16+i*2));
  if(index==0xffff)continue;
  for(j=0;j<i;j++)NAMEIN_GRAPHIC_AppendChar((char *)p,*(u16 *)(p+0x16+j*2));
  for(j=0;j<i;j++)NAMEIN_GRAPHIC_Backspace(p);
  if(pick(*(int *)&((NameinGraphicInputField *)p)->charMember[2],index,group.values,4,&group.count)){
   for(i=0;i<group.count;i++)NAMEIN_GRAPHIC_AppendChar((char *)p,*((u16 *)((char *)&group+2)+i));
   NAMEIN_GRAPHIC_CopyTableEntries(((NameinGraphicInputField *)p)->charMember[2],index,group.values,4,&group.count);
   for(i=0;i<group.count;i++)NAMEIN_GRAPHIC_Backspace(p);
   NAMEIN_GRAPHIC_PickTable14(*(char * *)&((NameinGraphicInputField *)p)->charMember[2],index,group.values,4,&group.count);
   for(i=0;i<group.count;i++){
    *(u16 *)(p+0x16+((NameinGraphicInputField *)p)->secondaryLength*2)=*((u16 *)((char *)&group+2)+i);
    ((NameinGraphicInputField *)p)->secondaryLength+=1;
    *(u16 *)(p+0x16+((NameinGraphicInputField *)p)->secondaryLength*2)=STRBUF_GetEosChar();
   }
   return 1;
  }
 }
 return 0;
}

int NAMEIN_GRAPHIC_HasNonSpace(u8 *p) {int i,spaces,n;n=*(volatile u16 *)&((NameinGraphicInputField *)p)->primaryLength;if(!n) return 0;spaces=0;i=0;while(i<n) {if(*(u16 *)(p+i*2)==32) spaces++;n=*(volatile u16 *)&((NameinGraphicInputField *)p)->primaryLength;i++;}return i!=spaces;}

void NAMEIN_GRAPHIC_InitPicker(char *p, unsigned mode, int index, void *table, u32 unused) {
 int i;
 MI_CpuFill8(p,0,36);((NameinGraphicPicker *)p)->table=(void *)NAMEIN_GRAPHIC_GetWord(table,index);
 switch(mode) {
 case 3:
 ((NameinGraphicPicker *)p)->width=11;((NameinGraphicPicker *)p)->height=4;
 ((NameinGraphicPicker *)p)->getBox=NAMEIN_GRAPHIC_SymbolGetBox;((NameinGraphicPicker *)p)->move=NAMEIN_GRAPHIC_SymbolMove;((NameinGraphicPicker *)p)->getValue=NAMEIN_GRAPHIC_SymbolGetValue;break;
 case 0:case 1:case 2:
 ((NameinGraphicPicker *)p)->width=13;((NameinGraphicPicker *)p)->height=6;
 ((NameinGraphicPicker *)p)->getBox=NAMEIN_GRAPHIC_KanaGetBox;((NameinGraphicPicker *)p)->move=NAMEIN_GRAPHIC_KanaMove;((NameinGraphicPicker *)p)->getValue=NAMEIN_GRAPHIC_ComputeGridValue;break;
 }
 for(i=0;i<13;i++)*(unsigned char *)(p+4+i)=d_021F555C[i];
}

void NAMEIN_GRAPHIC_LoadGrid(int *a, int b, void *c)
{
    *a = NAMEIN_GRAPHIC_GetWord((const u8 *)c, b);
}

void NAMEIN_GRAPHIC_ClearPicker(void *p) {MI_CpuFill8(p,0,36);}

unsigned NAMEIN_GRAPHIC_PickerToChar(char *p,int *input,unsigned short *out) {
 int xy[2]; unsigned result;
 result=((unsigned (*)(int *,int *))*(void **)(p+0x1C))(input,xy);
 if(result==1 || result==10 || result==11) {
  if(out) *out=NAMEIN_GRAPHIC_GetGridCell(*(unsigned char * *)&((NameinGraphicPicker *)p)->table,xy[0],xy[1]);
 } else if(result==9) {if(out) *out=32;}
 return result;
}

int NAMEIN_GRAPHIC_FindCellAtPoint(const char *p,int *point,NameinGraphicPair *out) {
 NameinGraphicPair xy; int rect[4];
 for(xy.y=0;xy.y<*(const unsigned short *)&((NameinGraphicPicker *)p)->height;xy.y++) {
 for(xy.x=0;xy.x<*(const unsigned short *)&((NameinGraphicPicker *)p)->width;xy.x++) {
 if(NAMEIN_GRAPHIC_PickerGetBox((char *)p,(NameinGraphicPair *)&xy.x,(NameinGraphicBox *)rect)) {
 rect[0]*=8;rect[1]*=8;rect[2]*=8;rect[3]*=8;
 if(NAMEIN_GRAPHIC_IsPointInRect(rect,point)) {*out=xy;return 1;}
 }
 }} return 0;
}

void NAMEIN_GRAPHIC_PickerMove(char *a, int b, int c)
{
    ((void (*)(int, int, char *))(*(void **)(a + 0x18)))(b, c, a + 4);
}

void NAMEIN_GRAPHIC_DrawCellTips(char *p,char *target,void *window,void *font,u16 heap)
{
 NameinGraphicBox box;
 NameinGraphicPair xy;
 u16 codes[3];
 void *text;
 u16 x,y;
 unsigned kind;
 text=STRBUF_Create(2,heap);
 for(xy.y=0;xy.y<NAMEIN_GRAPHIC_GetGridHeight(((NameinGraphicPicker *)p)->table);xy.y++){
  for(xy.x=0;xy.x<NAMEIN_GRAPHIC_GetGridWidth(((NameinGraphicPicker *)p)->table);xy.x++){
   if(NAMEIN_GRAPHIC_PickerGetBox((char *)p, (NameinGraphicPair *)&xy, (NameinGraphicBox *)&box)){
    kind=NAMEIN_GRAPHIC_PickerToChar(p,(int *)&xy,codes);
    if(kind==1 || kind==10 || kind==11){
     codes[1]=codes[0];codes[2]=STRBUF_GetEosChar();
     STRBUF_SetStringN(text,codes+1,2);
     box.x*=8;box.y*=8;box.z*=8;box.w*=8;
     x=box.x+(box.z-box.x)/2-24;
     y=box.y+(box.w-box.y)/2-40;
     x-=(u16)(PRINTSYS_MeasureWidestLine(text,font,0)/2);
     y-=(u16)(PRINTSYS_CountLines(text,font)/2);
     PRINTSYS_PrintQue(window,BMP_WIN_GetBmp(((NameinGraphicTipTarget *)target)->bmp),(short)(x-1),(short)y,text,font);
     target[4]=1;
    }
   }
  }
 }
 STRBUF_Delete(text);
}

int NAMEIN_GRAPHIC_PickerGetBox(char *a, NameinGraphicPair *b, NameinGraphicBox *c)
{
    return ((int (*)(NameinGraphicPair *, NameinGraphicBox *))(*(void **)(a + 0x14)))(b, c);
}

int NAMEIN_GRAPHIC_FindCellByValue(const char *p,int target,NameinGraphicPair *out) {
 NameinGraphicPair xy;
 for(xy.y=0;xy.y<=*(const unsigned short *)&((NameinGraphicPicker *)p)->height;xy.y++)
 for(xy.x=0;xy.x<=*(const unsigned short *)&((NameinGraphicPicker *)p)->width;xy.x++)
 if(((int (*)(int *,int *))*(void *const *)(p+0x1C))(&xy.x,0)==target) {*out=xy;return 1;}
 return 0;
}

/*
 * note: the original has no else arm: when neither mode is 3 it falls into
 *   the call with r2 (= newmode), r4, r5 and [sp,#4] never assigned
 *   (021F289A bne -> 021F28A6 skips the height store). The C leaves from/to/
 *   width/height unassigned on that path exactly as the image does; the
 *   earlier `else return;` spelling was a guard the original lacks.
 */
void NAMEIN_GRAPHIC_ConvertCellMode(NameinGraphicPair *p, int oldmode, int newmode)
{
    Conv from;
    Conv to;
    int width, height, result;
    NameinGraphicPair xy;
    if (oldmode == 3) {
        from = NAMEIN_GRAPHIC_SymbolGetValue;
        to = (Conv)NAMEIN_GRAPHIC_GridValue;
        width = 13;
        height = 5;
    } else if (newmode == 3) {
        from = (Conv)NAMEIN_GRAPHIC_GridValue;
        to = NAMEIN_GRAPHIC_SymbolGetValue;
        width = 11;
        height = 4;
    }
    result = from(p, 0);
    for (xy.y = 0; xy.y <= height; xy.y++)
        for (xy.x = 0; xy.x <= width; xy.x++)
            if (to(&xy, 0) == result) {
                *p = xy;
                return;
            }
}

int NAMEIN_GRAPHIC_KanaGetBox(const int *p,int *out) {
 int xy[2];enum { X_LEFT=15,X_RIGHT=22 } x;int y;
 switch(NAMEIN_GRAPHIC_GridValue(p,xy)) {
 case 1:case 10:case 11:
 x=xy[0]*2+3;out[0]=x;y=xy[1]*3+5;out[1]=y;out[2]=x+2;out[3]=y+3;break;
 case 2:case 3:case 4:case 5:
 x=(p[0]+1)*3;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+3;out[3]=y+3;break;
 case 6:x=15;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+7;out[3]=y+3;break;
 case 7:x=22;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+7;out[3]=y+3;break;
 case 0:return 0;
 case 8:case 9:break;
 }
 if(p[1]==5 && p[0]>6)return 0;return 1;
}

/*
 * lever: case 0 follows case 9; repeated stores in each case-8 arm preserve backward tail sharing.
 */
int NAMEIN_GRAPHIC_SymbolGetBox(NameinGraphicPair *p,NameinGraphicBox *out)
{
 NameinGraphicPair xy;
 switch((unsigned)NAMEIN_GRAPHIC_SymbolGetValue(p,&xy)) {
 case 1:out->x=d_021F5544[xy.y]+xy.x*2;out->y=d_021F5550[xy.y];out->z=out->x+2;out->w=out->y+3;break;
 case 2:case 3:case 4:case 5:out->x=(p->x+1)*3;out->y=20;out->z=out->x+3;out->w=out->y+3;break;
 case 6:out->x=25;out->y=8;out->z=out->x+4;out->w=out->y+3;break;
 case 7:out->x=24;out->y=12;out->z=out->x+5;out->w=out->y+3;break;
 case 8:if(p->x==0){out->x=3;out->y=16;out->z=out->x+4;out->w=out->y+3;}else {out->x=23;out->y=16;out->z=out->x+4;out->w=out->y+3;}break;
 case 9:out->x=15;out->y=20;out->z=out->x+12;out->w=out->y+3;break;
 case 0:return 0;
 }
 switch(p->y) {
 case 1:if(p->x>9)return 0;break;
 case 2:if(p->x>9)return 0;break;
 case 3:if(p->x>4)return 0;break;
 }
 return 1;
}

/*
 * tail: 320-byte lead including padding, followed by existing matched 920-byte NAMEIN_GRAPHIC_SymbolMove.
 */
void NAMEIN_GRAPHIC_KanaMove(int *p,int *delta,u8 *saved)
{
 int enter,leave,x,y,index;
 enter=0;leave=0;
 switch(p[1]){
 case 0:
 x=p[0]+=delta[0];if(x<0)x=12;else if(x>12)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 if(y==5)enter=1;
 break;
 case 4:
 x=p[0]+=delta[0];if(x<0)x=12;else if(x>12)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 if(y==5)enter=1;
 break;
 case 5:
 x=p[0]+=delta[0];if(x<0)x=5;else if(x>5)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 if(y!=5)leave=1;
 break;
 default:
 x=p[0]+=delta[0];if(x<0)x=12;else if(x>12)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 break;
 }
 if(enter){
  x=p[0];
  if(x>=6 && x<=9){saved[4]=x;p[0]=4;}
  else if(x>=10 && x<=12){saved[5]=x;p[0]=5;}
  else if(x>=0 && x<=5){index=x*2/3;saved[index]=x;p[0]=index;}
 }
 if(leave){
  x=p[0];
  if(x==4)p[0]=saved[4];
  else if(x==5)p[0]=saved[5];
  else if(x>=0 && x<=3)p[0]=saved[x];
 }
}

/*
 * extent: 920 bytes through return at 021F2F5E; no calls or followers.
 */
void NAMEIN_GRAPHIC_SymbolMove(int *p,int *delta,unsigned char *s) {
 int x,y;
 switch((unsigned)p[1]) {
 case 0:
 x=p[0]+=delta[0];if(x<0)x=10;else if(x>10)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==3) {
 switch((unsigned)p[0]) {
 case 8:case 9:s[8]=p[0];s[12]=p[0];s[11]=8;break;
 case 4:case 5:case 6:case 7:s[12]=p[0];s[11]=p[0];break;
 case 10:s[12]=10;s[11]=9;break;
 case 0:case 1:case 2:case 3:break;
 }
 switch(p[0]) {case 0:p[0]=s[6];break;case 1:case 2:p[0]++;break;default:p[0]=4;break;}
 } else {
 if(y!=1) {default:break;}
 switch((unsigned)p[0]) {
 case 8:case 9:s[8]=p[0];s[12]=p[0];x=p[0];if(x>9)x=9;else if(x<4)x=4;s[11]=x;break;
 case 4:case 5:case 6:case 7:case 10:s[12]=p[0];x=p[0];if(x>9)x=9;else if(x<4)x=4;s[11]=x;break;
 case 0:case 1:case 2:case 3:break;
 }
 switch(p[0]) {case 8:case 9:p[0]=8;break;case 10:p[0]=9;break;}
 }break;
 case 1:
 x=p[0]+=delta[0];if(x<0)x=9;else if(x>9)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==0) {
 switch(p[0]) {case 7:case 8:s[9]=p[0];break;}
 switch(p[0]) {case 8:p[0]=s[8];break;case 9:p[0]=10;break;}
 }else if(y==2) {
 switch(p[0]) {case 7:case 8:s[9]=p[0];break;}
 switch((unsigned)p[0]) {case 0:p[0]=s[7];break;case 7:case 8:p[0]=8;break;case 9:p[0]=9;break;default:p[0]++;break;}
 }break;
 case 2:
 x=p[0]+=delta[0];if(x<0)x=9;else if(x>9)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==1) {
 switch((unsigned)p[0]) {case 0:case 1:s[7]=p[0];break;case 4:case 5:case 6:case 7:case 8:case 9:s[11]=p[0];s[12]=p[0];break;case 2:case 3:break;}
 switch(p[0]) {case 0:case 1:p[0]=0;break;case 8:p[0]=s[9];break;case 9:p[0]=9;break;default:p[0]--;break;}
 }else if(y==3) {
 switch((unsigned)p[0]) {case 0:case 1:s[7]=p[0];break;case 4:case 5:case 6:case 7:case 8:s[11]=p[0];s[12]=p[0];break;case 9:s[11]=9;s[12]=10;break;case 2:case 3:break;}
 switch((unsigned)p[0]) {case 0:p[0]=s[10];break;case 1:case 2:case 3:break;default:p[0]=4;break;}
 }break;
 case 3:
 x=p[0]+=delta[0];if(x<0)x=4;else if(x>4)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==2) {
 switch(p[0]) {case 0:case 1:s[10]=p[0];s[6]=p[0];break;}
 switch((unsigned)p[0]) {case 0:case 1:case 2:case 3:break;case 4:p[0]=s[11];break;}
 }else if(y==0) {
 switch(p[0]) {case 0:case 1:s[10]=p[0];s[6]=p[0];break;}
 switch((unsigned)p[0]) {case 0:case 1:p[0]=0;break;case 2:case 3:p[0]--;break;case 4:p[0]=s[12];break;}
 }break;
 }
}

int NAMEIN_GRAPHIC_GridValue(const int *p,int *out) {return NAMEIN_GRAPHIC_ComputeGridValue(p,out);}

int NAMEIN_GRAPHIC_ComputeGridValue(const int *p,int *out) {
 if(p[1]<5) {if(out) {out[1]=p[1];out[0]=p[0];}return 1;}
 if(p[0]<=5)return p[0]+2;
 return 0;
}
