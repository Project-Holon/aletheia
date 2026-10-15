/*
 * file:     namein_graphic_p02.c
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
 *   func_02061CA4  0x02061CA4  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
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
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   GX_GetBankForLCDC 0x02045A98 arm
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
 *   func_0201D42C 0x0201D42C thumb
 *   NAMEIN_GRAPHIC_GetGridHeight 0x021F4DA0 thumb ov194
 *   NAMEIN_GRAPHIC_GetGridWidth 0x021F4D9C thumb ov194
 *   d_021F5544 0x021F5544 data a4
 *   d_021F5550 0x021F5550 data a4
 */
#include "../../matched/include/Obj10806.h"
#include "../../matched/include/Obj00418.h"
#include "../../matched/include/Obj03896.h"
#include "../../matched/include/Obj02909.h"
#include "../../matched/include/Obj01574.h"
#include "../../matched/include/Obj08342.h"
#include "../../matched/include/Obj10807.h"
#include "../../matched/include/Obj05509.h"
#include "../../matched/include/Obj24901.h"
#include "../../matched/include/Obj03897.h"
#include "../../matched/include/Obj14496.h"
#include "../../matched/include/Obj24902.h"
#include "../../matched/include/Obj24903.h"
#include "../../matched/include/Obj14497.h"
#include "../../matched/include/Obj02530.h"
#include "../../matched/include/Obj10808.h"
#include "../../matched/include/Obj14499.h"
#include "../../matched/include/Obj14500.h"
#include "../../matched/include/Obj14501.h"

struct Actor;
struct Cfg;
struct Descriptor;
struct Obj;
struct U16Vec;
struct Vec2;
struct CharBuf;
struct StrObj;
struct Strbuf;
struct PrintSys;
typedef unsigned char u8;

typedef short s16_021F1D58;

typedef s16_021F1D58 fx16;

typedef unsigned short u16;

typedef unsigned int u32_021F1D58;

typedef signed int     s32;

typedef unsigned int u32_021F1E28;

typedef unsigned int u32_021F1F7C;

typedef unsigned u32_021F1FB4;

typedef unsigned int u32;

typedef struct {u8 removedCount,addedCount;u16 removed[4],added[4];} Changes;

typedef unsigned int u32_021F23B8;

typedef signed char s8;

typedef signed short s16_021F23B8;

typedef struct {u8 count,pad;u16 values[4];} Group;

typedef struct {int x,y;} Pair;

typedef unsigned u32_021F26E0;

typedef struct {int x,y,z,w;} Box;

typedef int (*Conv)(Pair *, Pair *);

extern s32 func_02061CA4(void *p, u32_021F1D58 a, u32_021F1D58 b, s32 size);
extern void MI_CpuFill8(void *,unsigned,unsigned);
extern u32_021F1E28 BMP_WIN_Create(u32_021F1E28 layer, u32_021F1E28 a, u32_021F1E28 b, u32_021F1E28 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32_021F1E28 index);
extern struct U16Vec *STRBUF_Create(u32_021F1E28 capacity, u32_021F1E28 heapId);
extern int NAMEIN_GRAPHIC_LoadCharMember(int a, int b);
extern int NAMEIN_GRAPHIC_LoadPairMember(int a);
extern void *NAMEIN_GRAPHIC_GetActor(u8 *p, u32_021F1E28 i);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32_021F1E28 n);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32_021F1E28 v);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32_021F1E28 which);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32_021F1E28 v);
extern void CLACT_StartActorAnim(struct Actor *a);
extern void NAMEIN_GRAPHIC_FreePairMember(void *);
extern void NAMEIN_GRAPHIC_FreeHandle(void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32_021F1F7C BMP_WIN_Delete(struct Descriptor *d);
extern void WORDSET_CopyString(const u16 *,u16 *,u32_021F1FB4);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32_021F1FB4 len);
extern u32_021F1FB4 func_0201D304(struct StrObj *s, u32_021F1FB4 a, u32_021F1FB4 b);
extern void PRINTSYS_PrintQueColor(void *owner, u32_021F1FB4 a, u32_021F1FB4 b, u32_021F1FB4 c, u32_021F1FB4 d, u32_021F1FB4 e, u16 f);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32_021F1FB4 a, u32_021F1FB4 b, u32_021F1FB4 c, void *s, u32_021F1FB4 e);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32_021F1FB4 value);
extern unsigned int GX_GetBankForLCDC(void);
extern u16 NAMEIN_GRAPHIC_FindTableIndex(const char *p, const u16 *b);
extern int NAMEIN_GRAPHIC_PickTable8(int,int,u16 *,int,u8 *);
extern void NAMEIN_GRAPHIC_CopyTableEntries(const char *p, int i, u16 *dst, u32 n, u8 *count);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern int NAMEIN_GRAPHIC_PickTableE(int,int,u16 *,int,u8 *);
extern int NAMEIN_GRAPHIC_PickTable14(char *,int,u16 *,unsigned,u8 *);
extern u32_021F23B8 NAMEIN_GRAPHIC_GetWord(const unsigned char *p, u32_021F23B8 i);
extern int NAMEIN_GRAPHIC_SymbolGetValue(Pair *,Pair *);
extern unsigned NAMEIN_GRAPHIC_GetGridCell(unsigned char *,unsigned short,unsigned short);
extern int NAMEIN_GRAPHIC_IsPointInRect(int *,int *);
extern u32_021F26E0 func_0201D42C(struct StrObj *s, void *font);
extern u16 NAMEIN_GRAPHIC_GetGridHeight(const u16 *p);
extern u16 NAMEIN_GRAPHIC_GetGridWidth(const u16 *p);
int NAMEIN_GRAPHIC_FadeCellColor(u16 *out, u16 *phase, u32_021F1D58 step, u32_021F1D58 row, u8 idx, u16 a, u16 b);
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
u32_021F23B8 NAMEIN_GRAPHIC_GetLength(const u8 *p);
u32_021F23B8 NAMEIN_GRAPHIC_GetSecondaryLength(const u8 *p);
int NAMEIN_GRAPHIC_PickCandidate(u8 *p,int direction);
int NAMEIN_GRAPHIC_HasNonSpace(u8 *p);
void NAMEIN_GRAPHIC_InitPicker(char *p, unsigned mode, int index, void *table, u32_021F23B8 a4);
void NAMEIN_GRAPHIC_LoadGrid(int *a, int b, int c);
void NAMEIN_GRAPHIC_ClearPicker(void *p);
unsigned NAMEIN_GRAPHIC_PickerToChar(char *p,int *input,unsigned short *out);
int NAMEIN_GRAPHIC_FindCellAtPoint(const char *p,int *point,Pair *out);
void NAMEIN_GRAPHIC_PickerMove(char *a, int b, int c);
void NAMEIN_GRAPHIC_DrawCellTips(char *p,char *target,void *window,void *font,u16 heap);
int NAMEIN_GRAPHIC_PickerGetBox(char *a, Pair *b, Box *c);
int NAMEIN_GRAPHIC_FindCellByValue(const char *p,int target,Pair *out);
void NAMEIN_GRAPHIC_ConvertCellMode(Pair *p, int oldmode, int newmode);
int NAMEIN_GRAPHIC_KanaGetBox(const int *p,int *out);
int NAMEIN_GRAPHIC_SymbolGetBox(Pair *p,Box *out);
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
 *   lerp body (u8 r, g, blue; int dr, dg, db) with g before the cosine and an s16_021F1D58 t.
 */
int NAMEIN_GRAPHIC_FadeCellColor(u16 *out, u16 *phase, u32_021F1D58 step, u32_021F1D58 row, u8 idx, u16 a, u16 b)
{
    u8 r, g, blue; int dr, dg, db; s16_021F1D58 t;
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
    func_02061CA4((void *)0xF, row * 32 + idx * 2, (u32_021F1D58)out, 2);
    return *out == b;
}




/*
 * note 2026-10-05 (wD7 lane05): the entry spill order (b before a) follows the type of the
 *   fourth parameter: c as u16 closes it (as int the compiler spills a, b, c).
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
    h = BMP_WIN_Create(0, 8, 2, 0x18, 2, 15, 1);
    *(int *)(p + 0x40) = h;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    *(int *)(p + 0x2c) = *(int *)(p + 0x40);
    *(u8 *)(p + 0x30) = i;
    *(int *)(p + 0x3c) = (int)STRBUF_Create(0xe, f);
    for (i = 0; i < 3; i++) {
        *(int *)(p + i * 4 + 0x84) = NAMEIN_GRAPHIC_LoadCharMember(i, f);
    }
    *(int *)(p + 0x90) = NAMEIN_GRAPHIC_LoadPairMember(f);
    for (i = 0; i < 16; i++) {
        *(int *)(p + i * 4 + 0x44) = (int)NAMEIN_GRAPHIC_GetActor(e, i);
    }
    if (STRBUF_GetLength((struct U16Vec *)a) == 0) {
        *(u16 *)p = STRBUF_GetEosChar();
    } else {
        STRBUF_ToChars((struct U16Vec *)a, (u16 *)p, b + 1);
        *(u16 *)(p + 0x1e) = STRBUF_GetLength((struct U16Vec *)a);
    }
    pos[1] = 0x25;
    base = 0x40 - (*(u16 *)(p + 0x22) * 14) / 2;
    if (base < 0) {
        base = 0;
    }
    base += 0x40;
    for (i = 0; i < 16; i++) {
        pos[0] = base + i * 14;
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 1);
        CLACT_SetActorAutoAnim((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 1);
        CLACT_AddActorSurfacePos((struct Obj *)(*(int *)(p + i * 4 + 0x44)), (const struct Vec2 *)pos, 0);
        CLACT_SetActorDrawEnable((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 1);
    }
    for (i = *(u16 *)(p + 0x22); i < 16; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 0);
    }
    CLACT_StartActorAnim((struct Actor *)(*(int *)(p + *(u16 *)(p + 0x1e) * 4 + 0x44)));
    *(int *)(p + 0x28) = 1;
    NAMEIN_GRAPHIC_RefreshInputField(p);
}




void NAMEIN_GRAPHIC_DeleteInputField(u8 *p) { int i;NAMEIN_GRAPHIC_FreePairMember(((struct Obj10806 *)p)->f90);for(i=0;i<3;i++)NAMEIN_GRAPHIC_FreeHandle(*(void **)((u32_021F1F7C)p+(u32_021F1F7C)i*4+132));STRBUF_Delete(((struct Obj10806 *)p)->f3C);BMP_WIN_Delete((struct Descriptor *)(((struct Obj10806 *)p)->f40));MI_CpuFill8(p,0,148); }




/*
 * lever: load window in each print arm; p+i*4+0x44 preserves per-element bases and constant registers.
 */
int NAMEIN_GRAPHIC_RefreshInputField(u8 *p)
{
 u16 table[14];
 u16 pair[2];
 int i,x;
 void *window;
 if(((struct Obj00418 *)p)->f28){
  if(((struct Obj00418 *)p)->f1E)WORDSET_CopyString((u16 *)p,table,((struct Obj00418 *)p)->f1E+1);
  if(((struct Obj00418 *)p)->f20)WORDSET_CopyString((u16 *)(p+0x16),table+((struct Obj00418 *)p)->f1E,((struct Obj00418 *)p)->f20+1);
  if(((struct Obj00418 *)p)->f1E+((struct Obj00418 *)p)->f20>0){
   BMP_Clear(BMP_WIN_GetBmp(((struct Obj00418 *)p)->f40),0);
   for(i=0;i<((struct Obj00418 *)p)->f1E+((struct Obj00418 *)p)->f20;i++){
    pair[0]=table[i];pair[1]=STRBUF_GetEosChar();
    STRBUF_SetStringN(((struct Obj00418 *)p)->f3C,pair,2);
    x=64-(((struct Obj00418 *)p)->f22*14)/2;if(x<0)x=0;
    x+=i*14+7;
    x-=func_0201D304(((struct Obj00418 *)p)->f3C,((struct Obj00418 *)p)->f34,0)/2;
    if(i>=((struct Obj00418 *)p)->f1E){window=((struct Obj00418 *)p)->f38;PRINTSYS_PrintQueColor(window,(u32_021F1FB4)BMP_WIN_GetBmp(((struct Obj00418 *)p)->f2C),(short)x,0,(u32_021F1FB4)(((struct Obj00418 *)p)->f3C),((struct Obj00418 *)p)->f34,0xc80);}
    else {window=((struct Obj00418 *)p)->f38;PRINTSYS_PrintQue(window,(u32_021F1FB4)BMP_WIN_GetBmp(((struct Obj00418 *)p)->f2C),(short)x,0,((struct Obj00418 *)p)->f3C,((struct Obj00418 *)p)->f34);}
    p[0x30]=1;
   }
  }else{
   BMP_Clear(BMP_WIN_GetBmp(((struct Obj00418 *)p)->f40),0);
   BMP_WIN_TransferChars(((struct Obj00418 *)p)->f40);
  }
  for(i=0;i<((struct Obj00418 *)p)->f22;i++){
   CLACT_SetActorAnimFrame(*(void **)(p+i*4+0x44),0);
   CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x44),1);
   CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x44),1);
  }
  for(;i<16;i++){
   CLACT_SetActorAnimFrame(*(void **)(p+i*4+0x44),0);
   CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x44),1);
   CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x44),0);
  }
  for(i=0;i<=((struct Obj00418 *)p)->f1E && i<((struct Obj00418 *)p)->f22;i++)CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x44),1);
  CLACT_SetActorAnimSeq(*(void **)(p+0x44+((struct Obj00418 *)p)->f1E*4),0);
  ((struct Obj00418 *)p)->f28=0;
 }
 return NAMEIN_GRAPHIC_IsFieldDrawDone(p);
}





int NAMEIN_GRAPHIC_Backspace(unsigned char *p)
{
    if (((struct Obj03896 *)p)->f20 != 0) {
        ((struct Obj03896 *)p)->f20 -= 1;
        *(unsigned short *)(p + 0x16 + ((struct Obj03896 *)p)->f20 * 2) =
            STRBUF_GetEosChar();
        ((struct Obj03896 *)p)->f28 = 1;
        return 1;
    }
    if (((struct Obj03896 *)p)->f1E != 0) {
        ((struct Obj03896 *)p)->f1E -= 1;
        *(unsigned short *)(p + ((struct Obj03896 *)p)->f1E * 2) =
            STRBUF_GetEosChar();
        ((struct Obj03896 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}





int NAMEIN_GRAPHIC_AppendChar(char *p, unsigned short v)
{
    if (((struct Obj02909 *)p)->f1E < ((struct Obj02909 *)p)->f22)
    {
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = v;
        ((struct Obj02909 *)p)->f1E += 1;
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = GX_GetBankForLCDC();
        ((struct Obj02909 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}





int NAMEIN_GRAPHIC_AppendCandidate(unsigned char *p, unsigned short a, u32 b)
{
    if (((struct Obj01574 *)p)->f1E < ((struct Obj01574 *)p)->f22 &&
        ((struct Obj01574 *)p)->f20 < 3) {
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) = a;
        ((struct Obj01574 *)p)->f20 += 1;
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) =
            STRBUF_GetEosChar();
        NAMEIN_GRAPHIC_PickCandidate(p, b);
        ((struct Obj01574 *)p)->f28 = 1;
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
    case 0: p=((struct Obj08342 *)a)->f84; break;
    case 1: p=((struct Obj08342 *)a)->f88; break;
    default:return 0;
    }
    if (((struct Obj08342 *)a)->f1E==0) goto fail;
    v=NAMEIN_GRAPHIC_FindTableIndex(p,(u16 *)(a+(((struct Obj08342 *)a)->f1E-1)*2));
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




int NAMEIN_GRAPHIC_RevertChar(char *p) { u16 v;if(((struct Obj10807 *)p)->f1E!=0 && NAMEIN_GRAPHIC_NextPairChar(*(char * *)&((struct Obj10807 *)p)->f90,(u16 *)((u32)p+(((struct Obj10807 *)p)->f1E-1)*2),&v)) { NAMEIN_GRAPHIC_Backspace((u8 *)p);NAMEIN_GRAPHIC_AppendChar(p,v);return 1; }return 0; }





int NAMEIN_GRAPHIC_IsFieldDrawDone(unsigned char *p)
{
    int c = p[0x30];
    int r4 = ((struct Obj05509 *)p)->f38;

    if (c != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)r4, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05509 *)p)->f2C))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj05509 *)p)->f2C);
            p[0x30] = 0;
        }
    }
    return p[0x30] == 0;
}





void NAMEIN_GRAPHIC_CopyToStrbuf(char *self, struct Strbuf *dst)
{
    STRBUF_SetStringN(dst, (const u16 *)self,
                 ((struct Obj24901 *)self)->f1E + 1);
}





void NAMEIN_GRAPHIC_ClearSecondary(char *p)
{
    if (((struct Obj03897 *)p)->f20 != 0)
    {
        unsigned int v;
        ((struct Obj03897 *)p)->f20 = 0;
        v = GX_GetBankForLCDC();
        *(unsigned short *)(p + 0x16 + (((struct Obj03897 *)p)->f20 << 1)) = v;
        ((struct Obj03897 *)p)->f28 = 1;
    }
}




void NAMEIN_GRAPHIC_CommitSecondary(char *p) { int i; for(i=0;i<((struct Obj02909 *)p)->f20;i++)NAMEIN_GRAPHIC_AppendChar(p,*(u16 *)((u32)p+(u32)i*2+22));((struct Obj02909 *)p)->f20=0;*(u16 *)((u32)p+((struct Obj02909 *)p)->f20*2+22)=STRBUF_GetEosChar();((struct Obj02909 *)p)->f28=1; }




void NAMEIN_GRAPHIC_ClearPrimary(u8 *p) {if(((struct Obj03897 *)p)->f1E) {((struct Obj03897 *)p)->f1E=0;*(u16 *)(p+((struct Obj03897 *)p)->f1E*2)=STRBUF_GetEosChar();((struct Obj03897 *)p)->f28=1;}NAMEIN_GRAPHIC_ClearSecondary((char *)p);}





void NAMEIN_GRAPHIC_AppendString(char *p,const u16 *q) {while(*q!=STRBUF_GetEosChar()) {if(!NAMEIN_GRAPHIC_AppendChar(p,*q)) break;q++;}}






int NAMEIN_GRAPHIC_IsFieldFull(char *p)
{
    return ((struct Obj14496 *)p)->f1E == ((struct Obj14496 *)p)->f22;
}





u32_021F23B8 NAMEIN_GRAPHIC_GetLength(const u8 *p) {return ((struct Obj24902 *)p)->f1E;}





u32_021F23B8 NAMEIN_GRAPHIC_GetSecondaryLength(const u8 *p) {return ((struct Obj24903 *)p)->f20;}





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
 for(i=0;i<((struct Obj01574 *)p)->f20;i++){
  index=NAMEIN_GRAPHIC_FindTableIndex(((struct Obj01574 *)p)->f8C,(u16 *)(p+0x16+i*2));
  if(index==0xffff)continue;
  for(j=0;j<i;j++)NAMEIN_GRAPHIC_AppendChar((char *)p,*(u16 *)(p+0x16+j*2));
  for(j=0;j<i;j++)NAMEIN_GRAPHIC_Backspace(p);
  if(pick(*(int *)&((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count)){
   for(i=0;i<group.count;i++)NAMEIN_GRAPHIC_AppendChar((char *)p,*((u16 *)((char *)&group+2)+i));
   NAMEIN_GRAPHIC_CopyTableEntries(((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count);
   for(i=0;i<group.count;i++)NAMEIN_GRAPHIC_Backspace(p);
   NAMEIN_GRAPHIC_PickTable14(*(char * *)&((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count);
   for(i=0;i<group.count;i++){
    *(u16 *)(p+0x16+((struct Obj01574 *)p)->f20*2)=*((u16 *)((char *)&group+2)+i);
    ((struct Obj01574 *)p)->f20+=1;
    *(u16 *)(p+0x16+((struct Obj01574 *)p)->f20*2)=STRBUF_GetEosChar();
   }
   return 1;
  }
 }
 return 0;
}





int NAMEIN_GRAPHIC_HasNonSpace(u8 *p) {int i,spaces,n;n=*(volatile u16 *)&((struct Obj14497 *)p)->f1E;if(!n) return 0;spaces=0;i=0;while(i<n) {if(*(u16 *)(p+i*2)==32) spaces++;n=*(volatile u16 *)&((struct Obj14497 *)p)->f1E;i++;}return i!=spaces;}





void NAMEIN_GRAPHIC_InitPicker(char *p, unsigned mode, int index, void *table, u32_021F23B8 a4) {
 int i;
 MI_CpuFill8(p,0,36);((struct Obj02530 *)p)->f0=(void *)NAMEIN_GRAPHIC_GetWord(table,index);
 switch(mode) {
 case 3:
 ((struct Obj02530 *)p)->f20=11;((struct Obj02530 *)p)->f22=4;
 ((struct Obj02530 *)p)->f14=NAMEIN_GRAPHIC_SymbolGetBox;((struct Obj02530 *)p)->f18=NAMEIN_GRAPHIC_SymbolMove;((struct Obj02530 *)p)->f1C=NAMEIN_GRAPHIC_SymbolGetValue;break;
 case 0:case 1:case 2:
 ((struct Obj02530 *)p)->f20=13;((struct Obj02530 *)p)->f22=6;
 ((struct Obj02530 *)p)->f14=NAMEIN_GRAPHIC_KanaGetBox;((struct Obj02530 *)p)->f18=NAMEIN_GRAPHIC_KanaMove;((struct Obj02530 *)p)->f1C=NAMEIN_GRAPHIC_ComputeGridValue;break;
 }
 for(i=0;i<13;i++)*(unsigned char *)(p+4+i)=d_021F555C[i];
}






void NAMEIN_GRAPHIC_LoadGrid(int *a, int b, int c)
{
    *a = NAMEIN_GRAPHIC_GetWord((const u8 *)c, b);
}





void NAMEIN_GRAPHIC_ClearPicker(void *p) {MI_CpuFill8(p,0,36);}





unsigned NAMEIN_GRAPHIC_PickerToChar(char *p,int *input,unsigned short *out) {
 int xy[2]; unsigned result;
 result=((unsigned (*)(int *,int *))*(void **)(p+0x1C))(input,xy);
 if(result==1 || result==10 || result==11) {
  if(out) *out=NAMEIN_GRAPHIC_GetGridCell(*(unsigned char * *)&((struct Obj10808 *)p)->f0,xy[0],xy[1]);
 } else if(result==9) {if(out) *out=32;}
 return result;
}





int NAMEIN_GRAPHIC_FindCellAtPoint(const char *p,int *point,Pair *out) {
 Pair xy; int rect[4];
 for(xy.y=0;xy.y<*(const unsigned short *)&((struct Obj14499 *)p)->f22;xy.y++) {
 for(xy.x=0;xy.x<*(const unsigned short *)&((struct Obj14499 *)p)->f20;xy.x++) {
 if(NAMEIN_GRAPHIC_PickerGetBox((char *)p,(Pair *)&xy.x,(Box *)rect)) {
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
 Box box;
 Pair xy;
 u16 codes[3];
 void *text;
 u16 x,y;
 unsigned kind;
 text=STRBUF_Create(2,heap);
 for(xy.y=0;xy.y<NAMEIN_GRAPHIC_GetGridHeight(((struct Obj10808 *)p)->f0);xy.y++){
  for(xy.x=0;xy.x<NAMEIN_GRAPHIC_GetGridWidth(((struct Obj10808 *)p)->f0);xy.x++){
   if(NAMEIN_GRAPHIC_PickerGetBox((char *)p, (Pair *)&xy, (Box *)&box)){
    kind=NAMEIN_GRAPHIC_PickerToChar(p,(int *)&xy,codes);
    if(kind==1 || kind==10 || kind==11){
     codes[1]=codes[0];codes[2]=STRBUF_GetEosChar();
     STRBUF_SetStringN(text,codes+1,2);
     box.x*=8;box.y*=8;box.z*=8;box.w*=8;
     x=box.x+(box.z-box.x)/2-24;
     y=box.y+(box.w-box.y)/2-40;
     x-=(u16)(func_0201D304(text,(u32_021F26E0)font,0)/2);
     y-=(u16)(func_0201D42C(text,font)/2);
     PRINTSYS_PrintQue(window,(u32_021F26E0)BMP_WIN_GetBmp(((struct Obj14500 *)target)->f0),(short)(x-1),(short)y,text,(u32_021F26E0)font);
     target[4]=1;
    }
   }
  }
 }
 STRBUF_Delete(text);
}



int NAMEIN_GRAPHIC_PickerGetBox(char *a, Pair *b, Box *c)
{
    return ((int (*)(Pair *, Box *))(*(void **)(a + 0x14)))(b, c);
}



int NAMEIN_GRAPHIC_FindCellByValue(const char *p,int target,Pair *out) {
 Pair xy;
 for(xy.y=0;xy.y<=*(const unsigned short *)&((struct Obj14501 *)p)->f22;xy.y++)
 for(xy.x=0;xy.x<=*(const unsigned short *)&((struct Obj14501 *)p)->f20;xy.x++)
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
void NAMEIN_GRAPHIC_ConvertCellMode(Pair *p, int oldmode, int newmode)
{
    Conv from;
    Conv to;
    int width, height, result;
    Pair xy;
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
int NAMEIN_GRAPHIC_SymbolGetBox(Pair *p,Box *out)
{
 Pair xy;
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
 * tail: 320-byte lead including padding, followed by existing matched 920-byte ov194_func_021F2BC8.
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
